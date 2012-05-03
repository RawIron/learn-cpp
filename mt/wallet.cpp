#include <iostream>
#include <queue>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>


class Wallet {
public:
    Wallet() : account(0) {}
    void deposit(int amount) { account += amount; }
    void withdraw(int amount) { account -= amount; }
    int balance() const { return account; }
private:
    int account;
};


class ControlEvent {
public:
    virtual bool isStopped() = 0;
    virtual void shutdown() = 0;
};

class WalletControlEvent : public ControlEvent {
public:
    WalletControlEvent() : stopped(false) {}
    bool isStopped() { return stopped; }
    void shutdown() { stopped = true; }
private:
    bool stopped;
};


class WalletEvent {
public:
    virtual void provide(Wallet*) = 0;
    virtual void execute() = 0;
};

class WalletWithdrawEvent : public WalletEvent {
public:
    WalletWithdrawEvent(int requested): amount(requested), w(new Wallet()) {}
    void provide(Wallet *use) { w = use; }
    void execute() { w->withdraw(amount); }
private:
    int amount;
    Wallet *w;
}; 

class WalletDepositEvent : public WalletEvent {
public:
    WalletDepositEvent(int requested): amount(requested), w(new Wallet()) {}
    void provide(Wallet *use) { w = use; }
    void execute() { w->deposit(amount); }
private:
    int amount;
    Wallet *w;
}; 


class Worker {
public:
    Worker() : w(), active(false), t(0) {}
    void operator()() { work(); }

    void sent(WalletEvent *e) {
        boost::mutex::scoped_lock lock(mx);
        events.push(e);
        condition.notify_one();
    }
    void sent(ControlEvent *c) {
        boost::mutex::scoped_lock lock(mx);
        controls.push(c);
        condition.notify_one();
    }
    int balance() const { return w.balance(); }

    void run() {
        t = new boost::thread(boost::ref(*this));
        active = true;
    }
    void stop() {
        t->join();
    }
    void force() {}
private:
    void work() {
        while(true) {
            boost::mutex::scoped_lock lock(mx);
            while (events.empty() && controls.empty()) {
                condition.wait(lock);
            }
            if (!events.empty()) {
                WalletEvent *e = receiveEvent();
                e->provide(&w);
                e->execute();
            } else if (!controls.empty()) {
                ControlEvent *c = receiveControl();
                if (c->isStopped()) {
                    break;
                }
            }
        }
    }
    WalletEvent* receiveEvent() {
        WalletEvent *e = events.front();
        events.pop();
        return e;
    }
    ControlEvent* receiveControl() {
        ControlEvent *c = controls.front();
        controls.pop();
        return c;
    }

    boost::thread *t;
    boost::mutex mx;
    boost::condition condition;
    Wallet w;
    std::queue<WalletEvent*> events;
    std::queue<ControlEvent*> controls;
    bool active;
};


int main() {
    Worker t;
    WalletWithdrawEvent w1(12), w2(34);
    WalletDepositEvent d1(23), d2(20);
    WalletControlEvent c1;
    c1.shutdown();

    t.run();
    t.sent(&w1);
    t.sent(&w2);
    t.sent(&d1);
    t.sent(&d2);
    t.sent(&c1);
    t.stop();
    std::cout << t.balance();
}


#include "tickerListener.h"
#include "ticker.h"
#include "platterServer.cpp"

#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestSuite.h>
#include <cppunit/Test.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>


class PlatterServerTest : public CppUnit::TestFixture, public TicListener {
    public:
    PlatterServerTest() : ticker(nullptr), server(nullptr), client(nullptr), blocked(false) {}
    void setup();
    void teardown();
    static CppUnit::Test* suite();
    virtual void trigger();
    void block();

    void receivedTrigger();
    void receivedTest();
    void processedTrigger();
    void processedTest();

    private:
    PlatterServer* server;
    PlatterClient* client;
    Ticker* ticker;
    bool blocked;
    void (PlatterServerTest::*triggeredMethod)(void);
};

void PlatterServerTest::setup() {
    ticker = new Ticker();
    this->subscribeAt(ticker);
    client = new PlatterClient();
    client->subscribeAt(ticker);
    server = new PlatterServer();
}
void PlatterServerTest::teardown() {
    delete ticker;
    delete server;
    delete client;
}
CppUnit::Test* PlatterServerTest::suite() {
    CppUnit::TestSuite* suite = new CppUnit::TestSuite("server");
    suite->addTest(new CppUnit::TestCaller<PlatterServerTest>(
                   "receive", &PlatterServerTest::receivedTest));
    suite->addTest(new CppUnit::TestCaller<PlatterServerTest>(
                   "process", &PlatterServerTest::processedTest));
    return suite;
}

void PlatterServerTest::trigger() {
    (this->*triggeredMethod)();
}
void PlatterServerTest::block() {
    blocked = true;
}


void PlatterServerTest::receivedTrigger() {
    if (latestTick() == 1) {
        client->readLba(60);
        block();
        CPPUNIT_ASSERT(client->readQueueSize() == 1);
        CPPUNIT_ASSERT(blocked == true);
    }
    if (latestTick() == 3) {
        CPPUNIT_ASSERT(client->readQueueSize() == 0);
        CPPUNIT_ASSERT(blocked == true);
    }
}
void PlatterServerTest::processedTrigger() {
    if (latestTick() == 1) {
        client->readLba(60);
        block();
        CPPUNIT_ASSERT(client->readQueueSize() == 1);
    }
    if (latestTick() == 3) {
        CPPUNIT_ASSERT(client->readQueueSize() == 0);
        CPPUNIT_ASSERT(blocked == true);
    }
}

void PlatterServerTest::receivedTest() {
    setup();
    triggeredMethod = &PlatterServerTest::receivedTrigger;
    ticker->tick();
    ticker->tick();
    ticker->tick();
    teardown();
}

void PlatterServerTest::processedTest() {
    setup();
    triggeredMethod = &PlatterServerTest::processedTrigger;
    ticker->tick();
    ticker->tick();
    ticker->tick();
    teardown();
}



int main() {
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(PlatterServerTest::suite());
    runner.run();
}


#include "ticker.h"

#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestSuite.h>
#include <cppunit/Test.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>


class TickerTest : public CppUnit::TestFixture, public TicListener {
    public:
    TickerTest() : ticker(nullptr), triggered(false) {}
    void setup();
    void teardown();
    static CppUnit::Test* suite();
    virtual void trigger();

    void registerTest();
    void unregisterTest();
    void updateTest();
    void forwardUpdateTest();
    void triggerTest();

    private:
    Ticker* ticker;
    bool triggered;
};

void TickerTest::setup() {
    ticker = new Ticker();
}
void TickerTest::teardown() {
    delete ticker;
}
CppUnit::Test* TickerTest::suite() {
    CppUnit::TestSuite* suite = new CppUnit::TestSuite("ticker");
    suite->addTest(new CppUnit::TestCaller<TickerTest>(
                   "register", &TickerTest::registerTest));
    suite->addTest(new CppUnit::TestCaller<TickerTest>(
                   "unregister", &TickerTest::unregisterTest));
    suite->addTest(new CppUnit::TestCaller<TickerTest>(
                   "update", &TickerTest::updateTest));
    suite->addTest(new CppUnit::TestCaller<TickerTest>(
                   "forwardUpdate", &TickerTest::forwardUpdateTest));
    suite->addTest(new CppUnit::TestCaller<TickerTest>(
                   "trigger", &TickerTest::triggerTest));
    return suite;
}
void TickerTest::trigger() {
    triggered = true;
}

void TickerTest::registerTest() {
    setup();
    ticker->subscribe(this);
    CPPUNIT_ASSERT(ticker->has(this) == true);
    teardown();
}

void TickerTest::unregisterTest() {
    setup();
    ticker->unsubscribe(this);
    CPPUNIT_ASSERT(ticker->has(this) == false);
    teardown();
}

void TickerTest::updateTest() {
    setup();
    ticker->subscribe(this);
    ticker->tick();
    CPPUNIT_ASSERT(this->latestTick() == ticker->currentTick());
    teardown();
}

void TickerTest::forwardUpdateTest() {
    setup();
    ticker->subscribe(this);
    ticker->tick(4);
    CPPUNIT_ASSERT(this->latestTick() == ticker->currentTick());
    teardown();
}

void TickerTest::triggerTest() {
    setup();
    ticker->subscribe(this);
    ticker->tick();
    CPPUNIT_ASSERT(this->triggered == true);
    teardown();
}



int main() {
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(TickerTest::suite());
    runner.run();
}


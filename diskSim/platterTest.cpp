#include <memory>
#include "platter.cpp"

#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestSuite.h>
#include <cppunit/Test.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>


class PlatterTest : public CppUnit::TestFixture {
    public:
    void setup();
    void teardown();
    static CppUnit::Test* suite();

    void readTest();
    void seekTest();
    void meterTest();

    private:
    std::shared_ptr<Platter> d;
};

void PlatterTest::setup() {
    d = std::shared_ptr<Platter>(new Platter());
    d->randomInit();
}
void PlatterTest::teardown() {
    d.reset();
}
CppUnit::Test* PlatterTest::suite() {
    CppUnit::TestSuite* suite = new CppUnit::TestSuite("platter");
    suite->addTest(new CppUnit::TestCaller<PlatterTest>(
                   "read", &PlatterTest::readTest));
    suite->addTest(new CppUnit::TestCaller<PlatterTest>(
                   "seek", &PlatterTest::seekTest));
    suite->addTest(new CppUnit::TestCaller<PlatterTest>(
                   "meter", &PlatterTest::meterTest));
    return suite;
}

void PlatterTest::readTest() {
    setup();
    CPPUNIT_ASSERT(d->read(12) == d->read(0,3,1));
    teardown();
}

void PlatterTest::seekTest() {
    setup();
    d->on();
    d->read(0,3,1);
    tMove perf = d->moves();
    CPPUNIT_ASSERT(perf.cylinder == 0);
    CPPUNIT_ASSERT(perf.sector == 1);
    d->read(0,2,4);
    perf = d->moves();
    CPPUNIT_ASSERT(perf.cylinder == 0);
    CPPUNIT_ASSERT(perf.sector == 3);
    teardown();
}

void PlatterTest::meterTest() {
    setup();
    d->on();
    d->read(0,3,1);
    CPPUNIT_ASSERT(d->meter() == 2);
    d->read(0,2,4);
    CPPUNIT_ASSERT(d->meter() == 6);
    teardown();
}



int main() {
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(PlatterTest::suite());
    runner.run();
}


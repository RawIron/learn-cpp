#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestSuite.h>
#include <cppunit/Test.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>

class BowlingTest : public CppUnit::TestFixture {
    public:
    void setup();
    void teardown();
    static CppUnit::Test *suite();
}


void BowlingTest::setup() {
}
void BowlingTest::teardown() {
}

CppUnit::Test* BowlingTest::suite() {
    CppUnit::TestSuite* suite = new CppUnit::TestSuite("bowling");
    suite->addTest(new CppUnit::TestCaller<BowlingTest>(
                   "read", &BowlingTest::readTest));
    suite->addTest(new CppUnit::TestCaller<BowlingTest>(
                   "seek", &BowlingTest::seekTest));
    suite->addTest(new CppUnit::TestCaller<BowlingTest>(
                   "meter", &BowlingTest::meterTest));
    return suite;
}



int main() {
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(BowlingTest::suite());
    runner.run();
}


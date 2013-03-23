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
    void test_finishFirstFrame();
    static CppUnit::Test *suite();
};


void BowlingTest::setup() {
}
void BowlingTest::teardown() {
}
void BowlingTest::test_finishFirstFrame() {
    CPPUNIT_ASSERT(true == true);
}

CppUnit::Test* BowlingTest::suite() {
    CppUnit::TestSuite* suite = new CppUnit::TestSuite("bowling");
    suite->addTest(new CppUnit::TestCaller<BowlingTest>(
                   "firstFrame", &BowlingTest::test_finishFirstFrame));
    return suite;
}



int main() {
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(BowlingTest::suite());
    runner.run();
}


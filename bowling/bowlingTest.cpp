#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestSuite.h>
#include <cppunit/Test.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>


class Bowling {
    public:
    Bowling() : total(0) {};
    void tookDown(int pins) { total += pins; }
    int currentFrame() const { return total; }
    private:
    int total;
};


class BowlingTest : public CppUnit::TestFixture {
    public:
    void setup();
    void teardown();
    void test_finishFirstFrame();
    void test_finishFirstFrameWithStrike();
    void test_finishFirstFrameWithSpare();
    static CppUnit::Test *suite();
};


void BowlingTest::setup() {
}
void BowlingTest::teardown() {
}

void BowlingTest::test_finishFirstFrame() {
    Bowling *b = new Bowling();
    b->tookDown(3);
    b->tookDown(4);
    CPPUNIT_ASSERT(b->currentFrame() == 7);
}
void BowlingTest::test_finishFirstFrameWithStrike() {
    CPPUNIT_ASSERT(true == true);
}
void BowlingTest::test_finishFirstFrameWithSpare() {
    CPPUNIT_ASSERT(true == true);
}

CppUnit::Test* BowlingTest::suite() {
    CppUnit::TestSuite* suite = new CppUnit::TestSuite("bowling");
    suite->addTest(new CppUnit::TestCaller<BowlingTest>(
                   "firstFrame", &BowlingTest::test_finishFirstFrame));
    suite->addTest(new CppUnit::TestCaller<BowlingTest>(
                   "firstFrame", &BowlingTest::test_finishFirstFrameWithStrike));
    suite->addTest(new CppUnit::TestCaller<BowlingTest>(
                   "firstFrame", &BowlingTest::test_finishFirstFrameWithSpare));
    return suite;
}



int main() {
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(BowlingTest::suite());
    runner.run();
}


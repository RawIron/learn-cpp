#include "bowling.cpp"

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
    void test_finishFirstFrameWithStrike();
    void test_finishFirstFrameWithSpare();
    void test_finishSecondFrame();
    void test_finishSecondFrameAfterStrike();
    void test_finishSecondFrameAfterSpare();
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
    CPPUNIT_ASSERT(b->currentFrameCount() == 7);
}
void BowlingTest::test_finishFirstFrameWithStrike() {
    Bowling *b = new Bowling();
    b->tookDown(9);
    CPPUNIT_ASSERT(b->currentFrameCount() == b->Strike);
}
void BowlingTest::test_finishFirstFrameWithSpare() {
    Bowling *b = new Bowling();
    b->tookDown(3);
    b->tookDown(6);
    CPPUNIT_ASSERT(b->currentFrameCount() == b->Spare);
}

void BowlingTest::test_finishSecondFrame() {
    Bowling *b = new Bowling();
    b->tookDown(3);
    b->tookDown(4);
    b->tookDown(4);
    b->tookDown(4);
    CPPUNIT_ASSERT(b->previousFrameCount() == 7);
    CPPUNIT_ASSERT(b->currentFrameCount() == 8);
    CPPUNIT_ASSERT(b->totalFrameCount() == 15);
}
void BowlingTest::test_finishSecondFrameAfterStrike() {
    Bowling *b = new Bowling();
    b->tookDown(9);
    b->tookDown(2);
    b->tookDown(4);
    CPPUNIT_ASSERT(b->previousFrameCount() == b->Strike);
    CPPUNIT_ASSERT(b->currentFrameCount() == 6);
    CPPUNIT_ASSERT(b->totalFrameCount() == 22);
}
void BowlingTest::test_finishSecondFrameAfterSpare() {
    Bowling *b = new Bowling();
    b->tookDown(3);
    b->tookDown(6);
    b->tookDown(5);
    b->tookDown(1);
    CPPUNIT_ASSERT(b->previousFrameCount() == b->Spare);
    CPPUNIT_ASSERT(b->currentFrameCount() == 6);
    CPPUNIT_ASSERT(b->totalFrameCount() == 21);
}



CppUnit::Test* BowlingTest::suite() {
    CppUnit::TestSuite* suite = new CppUnit::TestSuite("bowling");
    suite->addTest(new CppUnit::TestCaller<BowlingTest>(
                   "firstFrame", &BowlingTest::test_finishFirstFrame));
    suite->addTest(new CppUnit::TestCaller<BowlingTest>(
                   "firstFrame", &BowlingTest::test_finishFirstFrameWithStrike));
    suite->addTest(new CppUnit::TestCaller<BowlingTest>(
                   "firstFrame", &BowlingTest::test_finishFirstFrameWithSpare));
    suite->addTest(new CppUnit::TestCaller<BowlingTest>(
                   "firstFrame", &BowlingTest::test_finishSecondFrame));
    suite->addTest(new CppUnit::TestCaller<BowlingTest>(
                   "firstFrame", &BowlingTest::test_finishSecondFrameAfterStrike));
    suite->addTest(new CppUnit::TestCaller<BowlingTest>(
                   "firstFrame", &BowlingTest::test_finishSecondFrameAfterSpare));
    return suite;
}


int main() {
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(BowlingTest::suite());
    runner.run();
}


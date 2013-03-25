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
    void test_finishFirstFrameIsStrike();
    void test_finishFirstFrameIsSpare();

    void test_finishSecondFrame();
    void test_finishSecondFrameAfterStrike();
    void test_finishSecondFrameAfterSpare();
    void test_finishSecondFrameAllStrike();
    void test_finishSecondFrameAllSpare();

    void test_finishThirdFrame();
    void test_finishThirdFrameAfterStrike();
    void test_finishThirdFrameAfterSpare();
    void test_finishThirdFrameAllStrike();
    void test_finishThirdFrameAllSpare();

    static CppUnit::Test *suite();
};


void BowlingTest::setup() {
}
void BowlingTest::teardown() {
}

void BowlingTest::test_finishFirstFrame() {
    Bowling *b = new Bowling();
    b->knockedDown(3); b->knockedDown(4);
    CPPUNIT_ASSERT(b->currentFrameCount() == 7);
}
void BowlingTest::test_finishFirstFrameIsStrike() {
    Bowling *b = new Bowling();
    b->knockedDown(10);
    CPPUNIT_ASSERT(b->currentFrameCount() == b->Strike);
}
void BowlingTest::test_finishFirstFrameIsSpare() {
    Bowling *b = new Bowling();
    b->knockedDown(4); b->knockedDown(6);
    CPPUNIT_ASSERT(b->currentFrameCount() == b->Spare);
}


void BowlingTest::test_finishSecondFrame() {
    Bowling *b = new Bowling();
    b->knockedDown(3); b->knockedDown(4);
    b->knockedDown(4); b->knockedDown(4);
    CPPUNIT_ASSERT(b->previousFrameCount() == 7);
    CPPUNIT_ASSERT(b->currentFrameCount() == 8);
    CPPUNIT_ASSERT(b->totalFrameCount() == 15);
}
void BowlingTest::test_finishSecondFrameAfterStrike() {
    Bowling *b = new Bowling();
    b->knockedDown(10);
    b->knockedDown(2); b->knockedDown(4);
    CPPUNIT_ASSERT(b->previousFrameCount() == b->Strike);
    CPPUNIT_ASSERT(b->currentFrameCount() == 6);
    CPPUNIT_ASSERT(b->totalFrameCount() == 22);
}
void BowlingTest::test_finishSecondFrameAfterSpare() {
    Bowling *b = new Bowling();
    b->knockedDown(4); b->knockedDown(6);
    b->knockedDown(5); b->knockedDown(1);
    CPPUNIT_ASSERT(b->previousFrameCount() == b->Spare);
    CPPUNIT_ASSERT(b->currentFrameCount() == 6);
    CPPUNIT_ASSERT(b->totalFrameCount() == 21);
}
void BowlingTest::test_finishSecondFrameAllStrike() {
    Bowling *b = new Bowling();
    b->knockedDown(10);
    b->knockedDown(10);
    CPPUNIT_ASSERT(b->previousFrameCount() == b->Strike);
    CPPUNIT_ASSERT(b->currentFrameCount() == b->Strike);
    CPPUNIT_ASSERT(b->totalFrameCount() == 30);
}
void BowlingTest::test_finishSecondFrameAllSpare() {
    Bowling *b = new Bowling();
    b->knockedDown(4); b->knockedDown(6);
    b->knockedDown(3); b->knockedDown(7);
    CPPUNIT_ASSERT(b->previousFrameCount() == b->Spare);
    CPPUNIT_ASSERT(b->currentFrameCount() == b->Spare);
    CPPUNIT_ASSERT(b->totalFrameCount() == 23);
}


void BowlingTest::test_finishThirdFrame() {
    Bowling *b = new Bowling();
    b->knockedDown(3); b->knockedDown(4);
    b->knockedDown(4); b->knockedDown(4);
    b->knockedDown(1); b->knockedDown(2);
    CPPUNIT_ASSERT(b->previousFrameCount() == 8);
    CPPUNIT_ASSERT(b->currentFrameCount() == 3);
    CPPUNIT_ASSERT(b->totalFrameCount() == 18);
}
void BowlingTest::test_finishThirdFrameAfterStrike() {
    Bowling *b = new Bowling();
    b->knockedDown(10);
    b->knockedDown(2); b->knockedDown(4);
    b->knockedDown(2); b->knockedDown(3);
    CPPUNIT_ASSERT(b->previousFrameCount() == 6);
    CPPUNIT_ASSERT(b->currentFrameCount() == 5);
    CPPUNIT_ASSERT(b->totalFrameCount() == 27);
}
void BowlingTest::test_finishThirdFrameAfterSpare() {
    Bowling *b = new Bowling();
    b->knockedDown(4); b->knockedDown(6);
    b->knockedDown(5); b->knockedDown(1);
    b->knockedDown(1); b->knockedDown(1);
    CPPUNIT_ASSERT(b->previousFrameCount() == 6);
    CPPUNIT_ASSERT(b->currentFrameCount() == 2);
    CPPUNIT_ASSERT(b->totalFrameCount() == 23);
}
void BowlingTest::test_finishThirdFrameAllStrike() {
    Bowling *b = new Bowling();
    b->knockedDown(10);
    b->knockedDown(10);
    b->knockedDown(10);
    CPPUNIT_ASSERT(b->previousFrameCount() == b->Strike);
    CPPUNIT_ASSERT(b->currentFrameCount() == b->Strike);
    CPPUNIT_ASSERT(b->totalFrameCount() == 50);
}
void BowlingTest::test_finishThirdFrameAllSpare() {
    Bowling *b = new Bowling();
    b->knockedDown(4); b->knockedDown(6);
    b->knockedDown(3); b->knockedDown(7);
    b->knockedDown(5); b->knockedDown(5);
    CPPUNIT_ASSERT(b->previousFrameCount() == b->Spare);
    CPPUNIT_ASSERT(b->currentFrameCount() == b->Spare);
    CPPUNIT_ASSERT(b->totalFrameCount() == 38);
}



CppUnit::Test* BowlingTest::suite() {
    CppUnit::TestSuite* suite = new CppUnit::TestSuite("bowling");
    suite->addTest(new CppUnit::TestCaller<BowlingTest>(
                   "", &BowlingTest::test_finishFirstFrame));
    suite->addTest(new CppUnit::TestCaller<BowlingTest>(
                   "", &BowlingTest::test_finishFirstFrameIsStrike));
    suite->addTest(new CppUnit::TestCaller<BowlingTest>(
                   "", &BowlingTest::test_finishFirstFrameIsSpare));

    suite->addTest(new CppUnit::TestCaller<BowlingTest>(
                   "", &BowlingTest::test_finishSecondFrame));
    suite->addTest(new CppUnit::TestCaller<BowlingTest>(
                   "", &BowlingTest::test_finishSecondFrameAfterStrike));
    suite->addTest(new CppUnit::TestCaller<BowlingTest>(
                   "", &BowlingTest::test_finishSecondFrameAfterSpare));
    suite->addTest(new CppUnit::TestCaller<BowlingTest>(
                   "", &BowlingTest::test_finishSecondFrameAllStrike));
    suite->addTest(new CppUnit::TestCaller<BowlingTest>(
                   "", &BowlingTest::test_finishSecondFrameAllSpare));

    suite->addTest(new CppUnit::TestCaller<BowlingTest>(
                   "", &BowlingTest::test_finishThirdFrame));
    suite->addTest(new CppUnit::TestCaller<BowlingTest>(
                   "", &BowlingTest::test_finishThirdFrameAfterStrike));
    suite->addTest(new CppUnit::TestCaller<BowlingTest>(
                   "", &BowlingTest::test_finishThirdFrameAfterSpare));
    suite->addTest(new CppUnit::TestCaller<BowlingTest>(
                   "", &BowlingTest::test_finishThirdFrameAllStrike));
    suite->addTest(new CppUnit::TestCaller<BowlingTest>(
                   "", &BowlingTest::test_finishThirdFrameAllSpare));

    return suite;
}


int main() {
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(BowlingTest::suite());
    runner.run();
}


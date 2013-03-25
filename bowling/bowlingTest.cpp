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

    void test_completeGame1();

    static CppUnit::Test *suite();
};


void BowlingTest::setup() {
}
void BowlingTest::teardown() {
}

void BowlingTest::test_finishFirstFrame() {
    bowling::Game *b = new bowling::Game();
    b->knockedDown(3); b->knockedDown(4);
    CPPUNIT_ASSERT(b->currentFrameCount() == 7);
}
void BowlingTest::test_finishFirstFrameIsStrike() {
    bowling::Game *b = new bowling::Game();
    b->knockedDown(10);
    CPPUNIT_ASSERT(b->currentFrameCount() == b->Strike);
}
void BowlingTest::test_finishFirstFrameIsSpare() {
    bowling::Game *b = new bowling::Game();
    b->knockedDown(4); b->knockedDown(6);
    CPPUNIT_ASSERT(b->currentFrameCount() == b->Spare);
}


void BowlingTest::test_finishSecondFrame() {
    bowling::Game *b = new bowling::Game();
    b->knockedDown(3); b->knockedDown(4);
    b->knockedDown(4); b->knockedDown(4);
    CPPUNIT_ASSERT(b->previousFrameCount() == 7);
    CPPUNIT_ASSERT(b->currentFrameCount() == 8);
    CPPUNIT_ASSERT(b->totalFrameCount() == 15);
}
void BowlingTest::test_finishSecondFrameAfterStrike() {
    bowling::Game *b = new bowling::Game();
    b->knockedDown(10);
    b->knockedDown(2); b->knockedDown(4);
    CPPUNIT_ASSERT(b->previousFrameCount() == b->Strike);
    CPPUNIT_ASSERT(b->currentFrameCount() == 6);
    CPPUNIT_ASSERT(b->totalFrameCount() == 22);
}
void BowlingTest::test_finishSecondFrameAfterSpare() {
    bowling::Game *b = new bowling::Game();
    b->knockedDown(4); b->knockedDown(6);
    b->knockedDown(5); b->knockedDown(1);
    CPPUNIT_ASSERT(b->previousFrameCount() == b->Spare);
    CPPUNIT_ASSERT(b->currentFrameCount() == 6);
    CPPUNIT_ASSERT(b->totalFrameCount() == 21);
}
void BowlingTest::test_finishSecondFrameAllStrike() {
    bowling::Game *b = new bowling::Game();
    b->knockedDown(10);
    b->knockedDown(10);
    CPPUNIT_ASSERT(b->previousFrameCount() == b->Strike);
    CPPUNIT_ASSERT(b->currentFrameCount() == b->Strike);
    CPPUNIT_ASSERT(b->totalFrameCount() == 30);
}
void BowlingTest::test_finishSecondFrameAllSpare() {
    bowling::Game *b = new bowling::Game();
    b->knockedDown(4); b->knockedDown(6);
    b->knockedDown(3); b->knockedDown(7);
    CPPUNIT_ASSERT(b->previousFrameCount() == b->Spare);
    CPPUNIT_ASSERT(b->currentFrameCount() == b->Spare);
    CPPUNIT_ASSERT(b->totalFrameCount() == 23);
}


void BowlingTest::test_finishThirdFrame() {
    bowling::Game *b = new bowling::Game();
    b->knockedDown(3); b->knockedDown(4);
    b->knockedDown(4); b->knockedDown(4);
    b->knockedDown(1); b->knockedDown(2);
    CPPUNIT_ASSERT(b->previousFrameCount() == 8);
    CPPUNIT_ASSERT(b->currentFrameCount() == 3);
    CPPUNIT_ASSERT(b->totalFrameCount() == 18);
}
void BowlingTest::test_finishThirdFrameAfterStrike() {
    bowling::Game *b = new bowling::Game();
    b->knockedDown(10);
    b->knockedDown(2); b->knockedDown(4);
    b->knockedDown(2); b->knockedDown(3);
    CPPUNIT_ASSERT(b->previousFrameCount() == 6);
    CPPUNIT_ASSERT(b->currentFrameCount() == 5);
    CPPUNIT_ASSERT(b->totalFrameCount() == 27);
}
void BowlingTest::test_finishThirdFrameAfterSpare() {
    bowling::Game *b = new bowling::Game();
    b->knockedDown(4); b->knockedDown(6);
    b->knockedDown(5); b->knockedDown(1);
    b->knockedDown(1); b->knockedDown(1);
    CPPUNIT_ASSERT(b->previousFrameCount() == 6);
    CPPUNIT_ASSERT(b->currentFrameCount() == 2);
    CPPUNIT_ASSERT(b->totalFrameCount() == 23);
}
void BowlingTest::test_finishThirdFrameAllStrike() {
    bowling::Game *b = new bowling::Game();
    b->knockedDown(10);
    b->knockedDown(10);
    b->knockedDown(10);
    CPPUNIT_ASSERT(b->previousFrameCount() == b->Strike);
    CPPUNIT_ASSERT(b->currentFrameCount() == b->Strike);
    CPPUNIT_ASSERT(b->totalFrameCount() == 60);
}
void BowlingTest::test_finishThirdFrameAllSpare() {
    bowling::Game *b = new bowling::Game();
    b->knockedDown(4); b->knockedDown(6);
    b->knockedDown(3); b->knockedDown(7);
    b->knockedDown(5); b->knockedDown(5);
    CPPUNIT_ASSERT(b->previousFrameCount() == b->Spare);
    CPPUNIT_ASSERT(b->currentFrameCount() == b->Spare);
    CPPUNIT_ASSERT(b->totalFrameCount() == 38);
}


void BowlingTest::test_completeGame1() {
    bowling::Game *b = new bowling::Game();
    b->knockedDown(10);
    CPPUNIT_ASSERT(b->totalFrameCount() == 10);
    b->knockedDown(3); b->knockedDown(7);
    CPPUNIT_ASSERT(b->totalFrameCount() == 30);
    b->knockedDown(7); b->knockedDown(2);
    CPPUNIT_ASSERT(b->totalFrameCount() == 46);
    b->knockedDown(9); b->knockedDown(1);
    CPPUNIT_ASSERT(b->totalFrameCount() == 56);
    b->knockedDown(10);
    CPPUNIT_ASSERT(b->totalFrameCount() == 76);
    b->knockedDown(10);
    CPPUNIT_ASSERT(b->totalFrameCount() == 96);
    b->knockedDown(10);
    CPPUNIT_ASSERT(b->totalFrameCount() == 126);
    b->knockedDown(2); b->knockedDown(3);
    CPPUNIT_ASSERT(b->totalFrameCount() == 138);
    b->knockedDown(6); b->knockedDown(4);
    CPPUNIT_ASSERT(b->totalFrameCount() == 148);
    b->knockedDown(7); b->knockedDown(3);
    CPPUNIT_ASSERT(b->totalFrameCount() == 165);
    b->knockedDown(3); b->knockedDown(0);
    CPPUNIT_ASSERT(b->previousFrameCount() == b->Spare);
    CPPUNIT_ASSERT(b->currentFrameCount() == 3);
    CPPUNIT_ASSERT(b->totalFrameCount() == 168);
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

    suite->addTest(new CppUnit::TestCaller<BowlingTest>(
                   "", &BowlingTest::test_completeGame1));

    return suite;
}


int main() {
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(BowlingTest::suite());
    runner.run();
}


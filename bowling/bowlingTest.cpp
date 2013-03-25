#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestSuite.h>
#include <cppunit/Test.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>


class BowlingFrame {
    public:
    static const int Strike = -2;
    static const int Spare = -1;
    BowlingFrame() : frameTotal(0), gameTotal(0), balls(0), complete(false) {};
    int score() const;
    int gameScore() const { return gameTotal; }
    void scored(int pins);
    bool completed() const { return complete; }
    void previousScore(int total) { gameTotal += total; }
    void doubleScored(int fromPrevious) { doubles = fromPrevious; }
    void wipe() { frameTotal = 0; gameTotal = 0; balls = 0; complete = false; }

    private:
    void isComplete();
    int frameTotal;
    int gameTotal;
    int balls;
    bool complete;
    int doubles;
};

void BowlingFrame::isComplete() {
    if (score() == Strike) {
        complete = true;
    } else if (score() == Spare) {
        complete = true;
    } else if (balls == 2) {
        complete = true;
    }
}

void BowlingFrame::scored(int pins) {
    ++balls;
    frameTotal += pins;
    isComplete();
    if (doubles > 0) {
        gameTotal += 2*pins;
        --doubles;
    } else {
        gameTotal += pins;
    }
}

int BowlingFrame::score() const {
    if (balls == 1 && frameTotal == 9) {
        return Strike;
    } else if (balls == 2 && frameTotal == 9) {
        return Spare;
    } else {
        return frameTotal;
    }
}


class Bowling {
    public:
    static const int NoFrames = 2;
    static const int Strike = -2;
    static const int Spare = -1;
    Bowling() : currentFrameIs(0), ballsBothFrames(0) { initFrames(); }
    void tookDown(int pins);
    int previousFrameCount() { return frames[previousFrame()]->score(); }
    int currentFrameCount() { return frames[currentFrameIs]->score(); }
    int totalFrameCount() { return frames[currentFrameIs]->gameScore(); }

    private:
    void initFrames();
    int nextFrame() { return (currentFrameIs + 1) & (NoFrames-1); }
    int previousFrame() { return (currentFrameIs - 1) & (NoFrames-1); }
    BowlingFrame *frames[NoFrames];
    int currentFrameIs;
    int ballsBothFrames;
};

void Bowling::initFrames() {
    frames[0] = new BowlingFrame();
    frames[1] = new BowlingFrame();
}
void Bowling::tookDown(int pins) {
    if (frames[currentFrameIs]->completed()) {
        frames[nextFrame()]->wipe();
        if (frames[currentFrameIs]->score() == Strike) {
            frames[nextFrame()]->previousScore(10);
            frames[nextFrame()]->doubleScored(2);
        } else if (frames[currentFrameIs]->score() == Spare) {
            frames[nextFrame()]->previousScore(10);
            frames[nextFrame()]->doubleScored(1);
        } else {
            frames[nextFrame()]->previousScore(frames[currentFrameIs]->score());
            frames[nextFrame()]->doubleScored(0);
        }
        currentFrameIs = nextFrame();
    }
    frames[currentFrameIs]->scored(pins);
}



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


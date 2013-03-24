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
    BowlingFrame() : total(0), balls(0) {};
    int score() const;
    void scored(int pins) { ++balls; total += pins; }
    bool completed() const { return (balls == 2); }
    void wipe() { total = 0; balls = 0; }

    private:
    int total;
    int balls;
};

int BowlingFrame::score() const {
    if (balls == 1 && total == 9) {
        return Strike;
    } else if (balls == 2 && total == 9) {
        return Spare;
    } else {
        return total;
    }
}

class Bowling {
    public:
    static const int Strike = -2;
    static const int Spare = -1;
    Bowling() : currentFrameIs(0) { frames[0] = new BowlingFrame(); frames[1] = new BowlingFrame(); }
    void tookDown(int pins) { frames[currentFrameIs]->scored(pins); }
    int currentFrameCount() { return frames[currentFrameIs]->score(); }

    private:
    BowlingFrame *frames[2];
    int currentFrameIs;
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


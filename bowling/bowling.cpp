#include <iostream>

class BowlingFrame {
    public:
    static const int Strike = -2;
    static const int Spare = -1;
    BowlingFrame() : frameTotal(0), gameTotal(0), balls(0), complete(false), doubles(0) {};
    int score() const;
    int gameScore() const { return gameTotal; }
    void scored(int pins);
    bool completed() const { return complete; }
    void previousScore(int total) { gameTotal += total; }
    void doubleScored(int fromPrevious) { doubles = fromPrevious; }
    void wipe() { frameTotal = 0; gameTotal = 0; balls = 0; complete = false; doubles = 0; }

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
    Bowling() : currentFrameIs(0) { initFrames(); }
    void tookDown(int pins);
    int previousFrameCount() { return frames[previousFrame()]->score(); }
    int currentFrameCount() { return frames[currentFrameIs]->score(); }
    int totalFrameCount() { return frames[currentFrameIs]->gameScore(); }

    private:
    void initFrames();
    int currentFrame() { return currentFrameIs; }
    int nextFrame() { return (currentFrameIs + 1) & (NoFrames-1); }
    int previousFrame() { return (currentFrameIs - 1) & (NoFrames-1); }
    BowlingFrame *frames[NoFrames];
    int currentFrameIs;
};

void Bowling::initFrames() {
    frames[0] = new BowlingFrame();
    frames[1] = new BowlingFrame();
}
void Bowling::tookDown(int pins) {
    if (frames[currentFrame()]->completed()) {
        frames[nextFrame()]->wipe();
        if (frames[currentFrame()]->score() == Strike) {
            frames[nextFrame()]->previousScore(10);
            frames[nextFrame()]->doubleScored(2);
        } else if (frames[currentFrame()]->score() == Spare) {
            frames[nextFrame()]->previousScore(10);
            frames[nextFrame()]->doubleScored(1);
        } else {
            frames[nextFrame()]->previousScore(frames[currentFrame()]->gameScore());
            frames[nextFrame()]->doubleScored(0);
        }
        currentFrameIs = nextFrame();
    }
    frames[currentFrameIs]->scored(pins);
}


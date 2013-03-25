#include <iostream>

namespace bowling {

class RollingFrame {
    public:
    static const int Strike = -2;
    static const int Spare = -1;
    RollingFrame() : frameIndex(0), frameTotal(0), gameTotal(0), balls(0), complete(false), firstStrikeInSeries(false), doubles(0) {};
    int score() const;
    bool completed() const { return complete; }
    int gameScore() const { return gameTotal; }
    int doublesNotUsed() const { return doubles; }
    int myFrameId() const { return frameIndex; }
    void scored(int pins);
    void previousScore(int total) { gameTotal += total; }
    void frameId(int id) { frameIndex = id; }
    void isFirstStrike() { firstStrikeInSeries = true; }
    void doubleNext(int upcomingBalls) { doubles = upcomingBalls; }
    void wipe() { frameIndex = 0; frameTotal = 0; gameTotal = 0; balls = 0; complete = false; firstStrikeInSeries = false; doubles = 0; }

    private:
    void isComplete();
    int frameIndex;
    int frameTotal;
    int gameTotal;
    int balls;
    bool complete;
    bool firstStrikeInSeries;
    int doubles;
};

void RollingFrame::isComplete() {
    if (score() == Strike) {
        complete = true;
    } else if (score() == Spare) {
        complete = true;
    } else if (balls == 2) {
        complete = true;
    }
}

void RollingFrame::scored(int pins) {
    ++balls;
    frameTotal += pins;
    isComplete();

    int multiplicator = 2;
    if (frameIndex == 11) {
        --multiplicator;
    }
    if (doubles > 2) {
        gameTotal += (multiplicator+1)*pins;
        doubles -= 2;
    } else if (firstStrikeInSeries) {
        gameTotal += multiplicator*pins;
        --doubles;
        firstStrikeInSeries = false;
    } else if (doubles > 0) {
        gameTotal += multiplicator*pins;
        --doubles;
    } else {
        gameTotal += pins;
    }
}

int RollingFrame::score() const {
    if (balls == 1 && frameTotal == 10) {
        return Strike;
    } else if (balls == 2 && frameTotal == 10) {
        return Spare;
    } else {
        return frameTotal;
    }
}


class Game {
    public:
    static const int NoFrames = 2;
    static const int Strike = -2;
    static const int Spare = -1;
    Game() : currentFrameIs(0) { initFrames(); }
    void knockedDown(int pins);
    int previousFrameCount() { return frames[previousFrame()]->score(); }
    int currentFrameCount() { return frames[currentFrameIs]->score(); }
    int totalFrameCount() { return frames[currentFrameIs]->gameScore(); }

    private:
    void initFrames();
    int currentFrame() { return currentFrameIs; }
    int nextFrame() { return (currentFrameIs + 1) & (NoFrames-1); }
    int previousFrame() { return (currentFrameIs - 1) & (NoFrames-1); }
    RollingFrame *frames[NoFrames];
    int currentFrameIs;
};

void Game::initFrames() {
    frames[0] = new RollingFrame();
    frames[1] = new RollingFrame();
    frames[currentFrameIs]->frameId(1);
}

void Game::knockedDown(int pins) {
    if (frames[currentFrame()]->completed()) {
        frames[nextFrame()]->wipe();
        frames[nextFrame()]->frameId((frames[currentFrame()]->myFrameId())+1);
        if (frames[currentFrame()]->score() == Strike) {
            if (frames[currentFrame()]->doublesNotUsed() == 0) {
                frames[nextFrame()]->isFirstStrike();
            }
            frames[nextFrame()]->previousScore(frames[currentFrame()]->gameScore());
            frames[nextFrame()]->doubleNext((frames[currentFrame()]->doublesNotUsed())+2);
        } else if (frames[currentFrame()]->score() == Spare) {
            frames[nextFrame()]->previousScore(frames[currentFrame()]->gameScore());
            frames[nextFrame()]->doubleNext((frames[currentFrame()]->doublesNotUsed())+1);
        } else {
            frames[nextFrame()]->previousScore(frames[currentFrame()]->gameScore());
            frames[nextFrame()]->doubleNext((frames[currentFrame()]->doublesNotUsed())+0);
        }
        currentFrameIs = nextFrame();
    }
    frames[currentFrameIs]->scored(pins);
}

}

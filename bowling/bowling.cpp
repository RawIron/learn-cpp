#include <iostream>


namespace bowling {

class RollingFrame {
    public:
    static const int Strike = -2;
    static const int Spare = -1;
    RollingFrame() : frameIndex(0), frameTotal(0),
                    gameTotal(0), balls(0), complete(false),
                    firstStrikeInSeries(false), doublesNotUsed(0) {};
    RollingFrame& RollingFrame(const RollingFrame& rhs);

    int score() const;
    int gameScore() const { return gameTotal; }
    bool completed() const { return complete; }
    void scored(int pins);

    private:
    void isComplete();
    int frameIndex;
    int frameTotal;
    int gameTotal;
    int balls;
    bool complete;
    bool firstStrikeInSeries;
    int doublesNotUsed;
};


RollingFrame& RollingFrame(const RollingFrame& rhs) {
    frameIndex = rhs.frameIndex+1;
    gameTotal = rhs.gameTotal;
    if (rhs.score() == Strike) {
        if (rhs.doublesNotUsed == 0) {
            firstStrikeInSeries = true;
        }
        doublesNotUsed = rhs.doublesNotUsed + 2;
    } else if (rhs.score() == Spare) {
        doublesNotUsed = rhs.doublesNotUsed + 1;
    } else {
        doublesNotUsed = rhs.doublesNotUsed;
    }
}

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
    static const int Strike = -2;
    static const int Spare = -1;
    Game() : previousScore(0) { initFrame(); }
    void knockedDown(int pins);
    int previousFrameCount() { return previousScore; }
    int currentFrameCount() { return frame->score(); }
    int totalFrameCount() { return frame->gameScore(); }

    private:
    void initFrame();
    RollingFrame *frame;
    int previousScore;
};

void Game::initFrame() {
    frame = new RollingFrame();
}

void Game::knockedDown(int pins) {
    if (frame->completed()) {
        previousScore = frame->score();
        RollingFrame *temp = new RollingFrame(frame);
        frame = temp;
    }
    frame->scored(pins);
}

}

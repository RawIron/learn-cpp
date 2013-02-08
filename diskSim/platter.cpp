#include <iostream>
#include <array>
#include <stdexcept>
#include <random>
#include <time.h>
#include <cstdlib>


typedef struct {int cylinder; int sector;} tPosition;
typedef tPosition tMove;


class Platter {
    public:
    Platter() : mtics(0) {};
    virtual ~Platter() {};
    void on();
    void initWithZero();
    void randomInit();
    tMove moves() const;
    int meter() const;
    int read(unsigned int lba) const throw(std::out_of_range);
    int read(unsigned int clylinder, unsigned int head, unsigned int sector);

    static const int CYLINDERS = 2;
    static const int HEADS = 2;
    static const int SPT = 4;
    static const int CAPACITY = HEADS * SPT * CYLINDERS;
    static const int CYLINDER_MTICS = 8;
    static const int SECTOR_MTICS = 2;

    private:
    void moveTo(int clylinder, int sector);
    void logMove(int clylinder, int sector);
    void updatePosition(int clylinder, int sector);

    std::array<int,CAPACITY> platter;
    unsigned int mtics;
    tPosition position;
    tMove moved;
};


int Platter::read(unsigned int lba) const throw(std::out_of_range) {
    if ((lba > CAPACITY) || (lba < 0)) {
        throw std::out_of_range("");
    }
    return platter[lba];
}
int Platter::read(unsigned int cylinder, unsigned int head, unsigned int sector) {
    if ((cylinder > CYLINDERS) || (cylinder < 0)) {
        throw std::out_of_range("");
    }
    if ((head > HEADS) || (head < 0)) {
        throw std::out_of_range("");
    }
    if ((sector > SPT) || (sector < 0)) {
        throw std::out_of_range("");
    }
    int lba = ((cylinder*HEADS)+head) * SPT + sector-1;
    moveTo(cylinder, sector);
    return platter[lba];
}

void Platter::moveTo(int cylinder, int sector) {
    logMove(cylinder, sector);
    updatePosition(cylinder, sector);
}
void Platter::logMove(int cylinder, int sector) {
    moved.cylinder = abs(position.cylinder - cylinder);
    moved.sector = abs(position.sector - sector);
}
void Platter::updatePosition(int cylinder, int sector) {
    position.cylinder = cylinder;
    position.sector = sector;
}
tMove Platter::moves() const {
    return moved;
}
int Platter::meter() const {
    return (moved.cylinder * CYLINDER_MTICS) + (moved.sector * SECTOR_MTICS);
}

void Platter::on() {
    position = {0,0};
    moved = {0,0};
    mtics = 0;
}
void Platter::randomInit() {
    srand(static_cast<unsigned int>(time(nullptr)));
    for (std::array<int,CAPACITY>::iterator i = platter.begin(); i != platter.end(); ++i) {
         *i = std::rand();
    }
}
void Platter::initWithZero() {
    for (std::array<int,CAPACITY>::iterator i = platter.begin(); i != platter.end(); ++i) {
         *i = 0;
    }
}


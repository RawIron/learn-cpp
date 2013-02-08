#include <iostream>
#include <array>
#include <random>
#include <time.h>


class PhysicalDiskDrive {
    public:
    PhysicalDiskDrive() : rpm(DEFAULT_RPM), seek(DEFAULT_SEEK), rotate(MILLIPS/DEFAULT_RPM) {};
    explicit PhysicalDiskDrive(int requested) :
            rpm(requested), seek(DEFAULT_SEEK),
            rotate(MILLIPS/requested) {};
    virtual int read(int lba) const;
    virtual int write(int lba);
    virtual void format();
    virtual void dd(Platter* p);

    private:
    static const int MILLIPS = 60000;
    static const int DEFAULT_RPM = 7200;
    static const int DEFAULT_SEEK = 6;
    int rpm;
    int seek;
    float rotate;
    Platter *p;
};

int PhysicalDiskDrive::read(int lba) const {
    int cylinder = lba / (Platter::SPT * Platter::HPC);
    int head =  (lba / Platter::SPT) % Platter::HPC;
    int sector = (lba % Platter::SPT) +1;
    return p->read(cylinder, head, sector);
}
int PhysicalDiskDrive::write(int lba) {
}

void PhysicalDiskDrive::format() {
}
void PhysicalDiskDrive::dd(Platter *platter) {
    p = platter;
}


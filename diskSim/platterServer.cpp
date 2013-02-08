#include <map>
#include <iostream>

#ifndef __PLATTERSERVER__
#define __PLATTERSERVER__
class PlatterServer {
};
#endif


#ifndef __PLATTERCLIENT__
#define __PLATTERCLIENT__

class PlatterClient : public TicListener {
    public:
    virtual void trigger();
    void readLba(int);
    void writeLba(int);
    int readQueueSize() {return readRequests.size();}
    int writeQueueSize() {return writeRequests.size();}

    private:
    bool isPlatterOn;
    Platter platter;
    std::multimap<int,int> readRequests;
    std::multimap<int,int> writeRequests;
};

#endif


void PlatterClient::trigger() {
    int lba;
    for (std::multimap<int,int>::iterator it=readRequests.begin(); (it != readRequests.end()) && (it->first < latestTick()); ++it) {
        lba = it->second;
        platter.read(lba);
        readRequests.erase(it);
    }
    for (std::multimap<int,int>::iterator it=writeRequests.begin(); it != writeRequests.end() && it->first < latestTick(); ++it) {
        lba = it->second;
        writeRequests.erase(it);
    }
}

void PlatterClient::readLba(int lba) {
    readRequests.insert({latestTick(),lba});
}
void PlatterClient::writeLba(int lba) {
    writeRequests.insert({latestTick(),lba});
}


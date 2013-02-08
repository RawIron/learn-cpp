#ifndef DATA_STORE_DRIVER_H
#define DATA_STORE_DRIVER_H

#include <string>
#include <vector>
#include <map>
using namespace std;

class data_store_driver_interface {
    public:
    virtual map<string,int> findHash(string query) throw(bool) = 0;
};

class data_store_driver : public data_store_driver_interface {
    public:
    explicit data_store_driver();
    virtual map<string,int> findHash(string query) throw(bool);
    private:
    map<string,int> storage;
};

#endif

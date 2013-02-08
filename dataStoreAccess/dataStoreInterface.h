#ifndef DATASTOREINTERFACE_H
#define DATASTOREINTERFACE_H

#include <string>
#include "resultSet.h"

class DataStoreInterface {
    public:
    virtual bool connect() = 0;
    virtual bool disconnect() = 0;
    virtual ResultSet query(std::string) = 0;
    virtual bool execute(std::string) = 0;
};

#endif

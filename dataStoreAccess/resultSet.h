#ifndef RESULTSET_H
#define RESULTSET_H

#include <vector>
#include "resultSetInterface.h"


template <typename TYPE>
class ResultSet : public ResultSetInterface<TYPE> {
    public:
    ResultSet();
    bool hasNext();
    TYPE next();

    private:
    std::vector<TYPE> results;
};


template<typename TYPE>
ResultSet<TYPE>::ResultSet() : results(new std::vector<TYPE>) {
}

template<typename TYPE>
bool ResultSet<TYPE>::hasNext() {
    return true;
}

template<typename TYPE>
TYPE ResultSet<TYPE>::next() {
    return results[0];
}

#endif

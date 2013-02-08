#ifndef RESULTSETINTERFACE_H
#define RESULTSETINTERFACE_H


template <typename ANY>
class ResultSetInterface {
    public:
    virtual bool hasNext() = 0;
    virtual ANY next() = 0;
};

#endif

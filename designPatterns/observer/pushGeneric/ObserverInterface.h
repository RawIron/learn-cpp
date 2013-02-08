#ifndef OBSERVERINTERFACE_H
#define OBSERVERINTERFACE_H

template <typename TYPE>
class ObserverInterface {
    public:
    virtual void deliverNews(TYPE message) = 0;
};

#endif

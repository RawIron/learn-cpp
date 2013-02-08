#include <string>
#include <iostream>
#include "Observer.h"
#include "Observable.h"


int main() {
    Observer<std::string> *quest = new Observer<std::string>();
    Observer<std::string> achievement;
    Observer<std::string> *p = &achievement;
    Observable<std::string> counter;
    std::string event = "level";

    quest->deliverNews("step1");
    quest->deliverNews("step2");
    quest->deliverNews("step3");
    listNews<std::string>(*quest);

    counter.subscribe(quest);
    counter.notify(event);
    listNews<std::string>(*quest);
    counter.unsubscribe(quest);

    counter.subscribe(p);
    counter.notify(event);
    listNews<std::string>(achievement);
    counter.unsubscribe(p);
    p->deliverNews("award1");
    listNews<std::string>(achievement);
}


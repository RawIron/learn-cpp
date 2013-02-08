#include "data_store_driver.h"
#include "assert.h"
#include <string>
#include <vector>

using namespace std;

data_store_driver::data_store_driver() {
    map<string,int>::iterator it;
    it = storage.begin();
    it = storage.insert(it, pair<string,int>("gold",1));
    it = storage.insert(it, pair<string,int>("silver",2));
    it = storage.insert(it, pair<string,int>("platinum",3));
}

map<string,int> data_store_driver::findHash(string query) throw(bool) {
    assert(query.size()>0);
    map<string,int> result;
    result.insert(*(storage.find(query)));
    if(result.size() == 0) {
        throw false;
    }
	return result;
}


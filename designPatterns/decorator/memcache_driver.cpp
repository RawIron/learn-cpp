#include "memcache_driver.h"
#include "assert.h"
#include <string>
#include <vector>

using namespace std;

memcache_driver::memcache_driver() {
    map<string,int>::iterator it;
    it = storage.begin();
    it = storage.insert(it, pair<string,int>("earth",1));
    it = storage.insert(it, pair<string,int>("water",2));
    it = storage.insert(it, pair<string,int>("fire",3));
}

map<string,int> memcache_driver::findHash(string query) throw(bool) {
    assert(query.size()>0);
    map<string,int> result;
    result.insert(*(storage.find(query)));
    if(result.size() == 0) {
        throw false;
    }
	return result;
}


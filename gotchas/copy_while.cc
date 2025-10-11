#include <iostream>
#include <set>
#include <algorithm>
#include <functional>
#include <stdlib.h>

using namespace std;


void copy_while(set<int>::iterator source_it, set<int>::iterator source_end,
                insert_iterator<set<int>> dest_it, function<bool(int)> lambda) {
    while (source_it != source_end && lambda(*source_it)) {
        *dest_it = *source_it;
        ++source_it;
        ++dest_it;
    }
    return;
}


int main(void) {
    set<int> data{2, 3, 4, 6};
    set<int> workset{};
    copy_while( data.begin(), data.end(), inserter(workset, workset.begin()),
                 [](int x) { return x <= 3; } );

    for (auto w: workset) {
        cout << w;
    }
    cout << endl;

    return EXIT_SUCCESS;
}

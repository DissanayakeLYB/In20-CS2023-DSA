#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    multiset<int> min_heap;     // create the min-heap
    int num_queries;
    cin >> num_queries;         // number of queries

    for (int i = 0; i < num_queries; i++) {
        int query_type;
        int value;
        cin >> query_type;
        
        if (query_type == 1) {
            cin >> value;
            min_heap.insert(value);                          // add an element
        }
        else if (query_type == 2) {
            cin >> value;
            auto it = min_heap.find(value);
            if (it != min_heap.end()) {
                min_heap.erase(it);                         // remove an element
            }
        }
        else if (query_type == 3) {
            if (min_heap.empty()) {
                cout << "Heap is empty" << endl;
            }
            else {
                cout << *(min_heap.begin()) << endl;        // print the minimum value
            }
        }
        else {
            cout << "Invalid query type" << endl;
        }
    }

    return 0;
}

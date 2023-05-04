#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> min_heap;        // create the min-heap
    int num_queries;
    cin >> num_queries;                 //number of queries 

    for (int i = 0; i < num_queries; i++) {
        
        int query_type, value;
        cin >> query_type ;            

        if (query_type == 1) {
            cin >> value;
            min_heap.push(value);               //add an element
        }
        else if (query_type == 2) {   
            cin >> value;
            min_heap.pop();                     //remove an element
        }
        else if (query_type == 3) {
            cout << min_heap.top() << endl;     //print the minimum value
        }
    }

    return 0;
}

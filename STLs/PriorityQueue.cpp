/* Priority Queue
- Constant time lookup of the largest element (highest priority).
- 'Compare' can be used to change the ordering.
- Sequence container, supports push from one end and pop from the other end.
- Elements are stored non-contiguously.

Methods : 
size()
=
top()
empty()
push(), pop() */

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> pq; // default is std::less (descneding order)
    vector<int> v = {8, 2, 3, 1, 7, 9, 4};

    for (int x : v) {
        pq.push(x);
    }

    while(!pq.empty()) {

        cout << pq.top() << " ";
        pq.pop();
    }
    
    cout << endl;
    
    // make is ascending order (smallest number has highest priority)
    
    priority_queue<int, vector<int>, greater<int>> p;

    for (int x : v) {
        p.push(x);
    }

    while(!p.empty()) {

        cout << p.top() << " ";
        p.pop();
    }
    
    cout << endl;
    
    // using custom comparator
    
    auto cmp = [](int a, int b) {
        return a < b;
    };
    
    priority_queue<int, vector<int>, decltype(cmp)> p1(cmp);

    for (int x : v) {
        p1.push(x);
    }

    while(!p1.empty()) {

        cout << p1.top() << " ";
        p1.pop();
    }
    

    return 0;
}
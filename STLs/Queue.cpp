/* Queue
- Deque is the underlying container.
- Sequence container, supports push from one end and pop from the other end.
- Elements are stored non-contiguously.

Methods : 
size()
=
front(), back()
empty()
push(), pop() */

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;

    for (int i = 1; i <= 5; i++) {
        q.push(i);
    }

    cout << "Size = " << q.size() << endl;
    cout << "Front = " << q.front() << endl;
    cout << "Back = " << q.back() << endl;

    q.pop();
    q.pop();

    cout << "Size = " << q.size() << endl;
    cout << "Front = " << q.front() << endl;
    cout << "Back = " << q.back() << endl;

    cout << "Empty? " << boolalpha << q.empty() << endl;


    return 0;
}
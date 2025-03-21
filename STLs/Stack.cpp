/* Stack
- Deque is the underlying container.
- Sequence container, supports push and pop from one end.
- Elements are stored non-contiguously.

Methods : 
size()
=
top()
empty()
push(), pop() [equivalent to push_back() and pop_back()] */

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;

    for (int i = 1; i <= 5; i++) {
        s.push(i);
    }

    cout << "Size = " << s.size() << endl;
    cout << "Top = " << s.top() << endl;

    s.pop();

    cout << "Size = " << s.size() << endl;
    cout << "Top = " << s.top() << endl;

    cout << "Empty? " << boolalpha << s.empty() << endl;


    return 0;
}
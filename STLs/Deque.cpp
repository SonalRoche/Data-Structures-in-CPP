/* Deque
- Sequence container, supports push and pop from both ends.
- Elements are stored non-contiguously.
- Supports random access.
- Occupy more space than static arrays as more memory is allocated to 
  handle future growth.

Methods : 
size()
=, []
fromt(), back()
empty()
begin(), end(), rbegin(), rend()
insert(), erase()
push_back(), pop_back(), push_front(), pop_front()
clear() // accessing elements after clear() is undefined behavior */

#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> d = {1,2,3,4,5};
    cout << "Size = " << d.size() << endl;
    
    // accessing elements
    cout << "d[2] = " << d[2] << endl;
    
    cout << "Front = " << d.front() << " Back = " << d.back() << endl;
    
    for(deque<int>::iterator it = d.begin(); it != d.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    
    d.push_back(6);
    d.push_front(0);
    cout << "Front = " << d.front() << " Back = " << d.back() << endl;
    
    d.pop_back();
    d.pop_front();
    cout << "Front = " << d.front() << " Back = " << d.back() << endl;
    
    d.clear();

    return 0;
}
/* Lists
- Sequence containers, optimized for rapid insert and delete.
- Elements are stored non-contiguously.
- Does not support random access.
- Handle bi-directional iterations.

Methods : 
size(), max_size()
=
fromt(), back()
empty()
begin(), end(), rbegin(), rend()
insert(), erase(), remove()
push_back(), push_front(), pop_back(), pop_front()
clear() // accessing elements after clear() is undefined behavior */

#include <iostream>
#include <list>
using namespace std;

void print_list(list<int>& li) {
    
    cout << "Printing list : ";
    
    // for(auto it..) is also ok instead of list<int>::iterator it
    for(list<int>::iterator it = li.begin(); it != li.end(); ++it) {
        cout << *it << "  ";
    }
    cout << endl;
}

int main()
{
    list<int> li = {1,2,3,4,5};
    print_list(li);
    
    cout << "Size = " << li.size() << endl;
    
    cout << "Front = " << li.front() << " Back = " << li.back() << endl;
    cout << "Empty ? " << boolalpha << li.empty() << endl;
    
    cout << "begin = " << *li.begin() << " rbegin = " << *li.rbegin() << endl;
    cout << "end = " << *li.end() << endl; //  *li.rend() cannot be dereferenced
    
    // insert 100 before 3
    auto it = li.begin();
    while(*it != 3 && it != li.end()) {
        it++;
    }
    li.insert(it, 100);
    print_list(li);
    
    // remove the element pointed to by it ie. 3
    li.erase(it); 
    print_list(li);
    
    // remove 4
    li.remove(4);
    print_list(li);
    
    // add elements to back
    li.push_back(8);
    print_list(li);
    // add elements to front
    li.push_front(0);
    print_list(li);
    
    // remove elements from back
    li.pop_back();
    print_list(li);
    // remove elements from front
    li.pop_front();
    print_list(li);
    
    li.clear();
    print_list(li);
    cout << "Empty ? " << boolalpha << li.empty() << endl;
    

    return 0;
}
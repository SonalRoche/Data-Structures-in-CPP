/* Set
- Associative container that contains a sorted set of unique objects.
- 'Compare' can be used to change the ordering.
- Implemented using RB Tress.
- Operation times are logarithmic.

Methods : 
size()
=
clear()
begin(), end()
count(), find()
insert(key), insert(iterator1,iterator2), insert(init_list)
erase(iterator), erase(key), erase(iterator1,iterator2)
upper_bound(key), lower_bound(key)
empty() */

#include<iostream>
#include<set>
using namespace std;

class Student {
public:
    int id;
    string name;
    
    void print_stud() const {
        cout << "Name = " << name << " ID = " << id << endl;
    }
    
    // this needs to be there because 'set' needs to know how to order the
    // student objects.
    bool operator< (const Student& other) const {
        return (this->id < other.id);
    }
};

int main(){
    set<int> s = {4, 5, 7, 8, 4, 1, 8};

    cout << "Size = " << s.size() << endl;
    
    s.insert(1); // not inserted
    s.insert(2);
    
    cout << "Size = " << s.size() << endl;
    
    s.insert({-2, -9, 0, -1});
    
    for(auto it = s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    
    auto it = s.erase(s.find(2));
    cout << *it << endl; // iterator points to next element
    
    int num_erased = s.erase(5); // returns number of elements erased
    cout << "Num erased = " << num_erased << endl;
    
    auto ub = s.upper_bound(7);
    cout << "ub = " << *ub << endl;
    
    // ------------------------------ //
    
    // set of student objects
    set<Student> st = {{50, "Snl"}, {12, "Alia"}, {22,"Ben"}};
    
    for(auto& stt : st) {
        stt.print_stud();
    }
    

    return 0;
}
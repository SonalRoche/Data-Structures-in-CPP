/* Map
- Associative container that contains key-value pairs with unique keys.
- 'Compare' can be used to change the ordering.
- Implemented using RB Tress.
- Operation times are logarithmic.

Methods : 
size()
=
[], at()
clear()
begin(), end()
count(), find()
insert(key), insert(iterator1,iterator2), insert(init_list)
erase(iterator), erase(key), erase(iterator1,iterator2)
upper_bound(key), lower_bound(key)
empty() */

#include<iostream>
#include<map>
using namespace std;


int main(){
    map<int,string> map = {{1,"Snl"}, {2,"Ben"}, {3, "Sam"}};
    cout << "Size = " << map.size() << endl;
    
    map.insert({6,"Den"});
    
    for(auto& ele : map) {
        cout << "{" << ele.first << "," << ele.second << "}";
    }
    cout << endl;
    
    auto it = map.erase(map.find(2));
    cout << "Iterator now at: " << it->first << endl;
    
    int num_erased = map.erase(3);
    cout << "Number of erased elements = " << num_erased << endl;
    
    auto ub = map.upper_bound(1);
    cout << "UB = " << ub->first << endl;
    
    return 0;
}
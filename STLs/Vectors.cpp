/* Vectors
- Elements are stored contiguously.
- Storage is handled automatically.
- Occupy more space than static arrays as more memory is allocated to 
  handle future growth.

Methods : 
size(), capacity(), max_size()
=, [], at()
fromt(), back()
shrink_to_fit() // returns extra allocated space such that capacity = size
empty()
begin(), end(), rbegin(), rend()
insert(), erase()
push_back(), pop_back()
clear() // accessing elements after clear() is undefined behavior
sort() */

  #include <iostream>
  #include <vector>
  #include <algorithm>
  using namespace std;
  
  int main()
  {
      vector<int> v = {1,2,3,4,5};
      cout << "Size = " << v.size() << " Capacity = " << v.capacity() << endl; 
      cout << "Max Size = " << v.max_size() << endl;
      
      // insert element at end
      v.push_back(6);
      cout << "Size = " << v.size() << " Capacity = " << v.capacity() << endl;
      // insert in the middle at position 2
      v.insert(v.begin() + 2, -100);
      
      // accessing elements
      cout << "v[2] = " << v[2] << endl; // no bound check
      cout << "v.at(2) = " << v.at(2) << endl; // checks bounds
      
      //front & back
      cout << "Front = " << v.front() << " Back = " << v.back() << endl;
      
      //deleting
      v.pop_back();
      cout << "Front = " << v.front() << " Back = " << v.back() << endl;

      //sorting
      sort(v.begin(), v.end());
      cout << "Front = " << v.front() << " Back = " << v.back() << endl;

      v.clear();
      cout << "Size = " << v.size() << " Capacity = " << v.capacity() << endl;
  
      return 0;
  }
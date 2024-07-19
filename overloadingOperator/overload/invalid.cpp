//iterator invalidation
//container changes in a way no longer correctly reference intended elements
//causes: 1. reallocation 2. insert/delete 
//example: 1. for std::vector push_back() may cause reallocation if capacity is exceeded
// insert() or erase() invalidates ay or after the point of insertion/erasure

//2. for std::list, erase() invalidates only the iterators pointing to the erased element
//3.for std:map and std::set, erase() invalidates only iterators to the erased elements
// which means erase an unrelated element from a std::set has no effect on iter

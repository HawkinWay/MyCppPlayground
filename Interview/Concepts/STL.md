# Standard Template library

- Containers
- Algorithms
- Iterators
- Adapters
- Allocators
- Functors



## Containers

### Sequence Containers

|Name|Data Structure|Memory Layout|Important Interface|Iterator Invalidation|Remarks|
|--|--|--|--|--|--|
|vector|A dynamic array|Contiguous single block of memory|`emplace_back()`: since C++17, the sole advantage of this interface is *passing multiple constructor parameters and handle explicit constructor* (because of `Guaranteed Copy Elision`)|insert(), erase(), reserve()|vector bool is **not** a standard container, underlying storage is bit-packed (1-bit per boolean). `auto& ref = vb[0];` **fails to compile**, vb[0] is a temporary proxy, not `bool&`|
|deque|A double-end queue|central map (pointer array) + chunks (buffers)|push_back(), push_front()|--| Iterators hold a pointer into the map. When the map itself grows, the map’s address changes, thus all iterators are invalidated. =|
|list|A double-linked list|--|push_back(), push_front(), pop_back(), pop_front()|erase()|--|
|array|A fixed-length array|Contiguous storage|--|--|--|
|forward_list|A singly-linked list|--|--|--|--|

### Assosiative Containers

|Name|Low Level Implement|Remarks|
|--|--|--|
|set|Red-black tree|dafult ascending order(set<int>); Ascending order(set<int, less<int>>), Descending order(set<int, greater<int>>) 
|multiset|
|map|Red-black tree|
|multimap|

### Unordered Assosiative Containers

|Name|
|--|
|unordered_set|
|unordered_multiset|
|unordered_map|
|unordered_multimap|



## Container Adapters

|Name|Important Interface|
|--|--|
|stack|push(), pop(), top()|
|queue|push(), pop(), front()|
|priority_queue|push(), pop(), front()|


## Algorithms

find(), count(), for_each()

sort(), reverse(), replace(), swap()

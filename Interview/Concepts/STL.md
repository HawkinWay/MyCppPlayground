# Standard Template library

- Containers
- Iterators
- Algorithms
- Adapters
- Allocators
- Functors

---

## 1. Containers

### 1.1 Sequence Containers

|Name|Data Structure|Memory Layout|Important Interface|Iterator Invalidation|Remarks|
|--|--|--|--|--|--|
|vector|A dynamic array|Contiguous single block of memory|`emplace_back()`: since C++17, the sole advantage of this interface is *passing multiple constructor parameters and handle explicit constructor* (because of `Guaranteed Copy Elision`)|insert(), erase(), reserve()|vector bool is **not** a standard container, underlying storage is bit-packed (1-bit per boolean). `auto& ref = vb[0];` **fails to compile**, vb[0] is a temporary proxy, not `bool&`|
|deque|A double-end queue|central map (pointer array) + chunks (buffers)|push_back(), push_front()|--| Iterators hold a pointer into the map. When the map itself grows, the map’s address changes, thus all iterators are invalidated. =|
|list|A double-linked list|--|push_back(), push_front(), pop_back(), pop_front()|erase()|--|
|string|
|array|A fixed-length array|Contiguous storage|--|--|--|
|forward_list|A singly-linked list|--|--|--|--|

### 1.2 Assosiative Containers

|Name|Low Level Implement|Key Find|Remarks|
|--|--|--|--|
|set|Red-black tree|O(logN)|dafult ascending order(set<int>); Ascending order(set<int, less<int>>), Descending order(set<int, greater<int>>) 
|multiset||O(logN)
|map|Red-black tree|O(logN)
|multimap||O(logN)

### 1.3 Unordered Assosiative Containers

|Name|Low Level Implement|Key Find|
|--|--|--|
|unordered_set|Hashmap|O(1)|
|unordered_multiset|Hashmap|O(1)|
|unordered_map|Hashmap|O(1)|
|unordered_multimap|Hashmap|O(1)|

---


## 2. Iterators

An itrator is an object that behaves like a pointer that traverse and access elements of a container.

---

## 3. Algorithms

Algorithms don't work with containers themselves but rather with iterators. Therefore, the same algorithm can be used by most if not all of the C++ Standard Library containers.

find(), count(), for_each()

sort(), reverse(), replace(), swap()

### reserve() vs resize()

> These two functions only work on vector and string, list/map doesn't have these interfaces.

|Dimension|reserve(n)|resize(n)|
|--|--|--|
|Modify what|capacity|size(valid elements)|
|Change size?|no|yes|
|Create objects?|**NO**, only get raw memory|Yes, construct and destruct. If n>size, call default/copy constructor to create new elements in the end;if n<size, destruct superfluous elements in the end｜
|Reduce behaviour|No, reserve can only expand|If n<size, destruct elemetns in the end, capacity usually doesn't change|
|Boundary|reserve(100), v[50] = 1 is **illegal**|resize(100), v[50] is legal|
|Iterator failure|Only n>capacity, all iterators failure|If expand memory, all iterators failure; if not, in push_back/pop_back case, only the end() iterator failure|

---

## 4. Container Adapters

|Name|Important Interface|
|--|--|
|stack|push(), pop(), top()|
|queue|push(), pop(), front()|
|priority_queue|push(), pop(), front()|

---

## 5. Allocators

Decouple memory expansion and object construction. The allocator only responsible for getting raw memory (void* or char*) and not for calling constructor.

std::allocator encapsulates ::operator new and ::operator delete. ::operator new encapsulates malloc(), ::operator delete encapsulates free().

### Two-Level Structure(from SGI STL)

- **First-level allocator(__malloc_alloc)**: [Request > 128Bytes] Directly calls  standard malloc() and free(), handling large memory requests and utilizing a custom out-of-memory handler if allocation fails.

- **Second-level allocator(__default_alloc_alloc)**: [Request <= 128 Bytes] Uses a memory pool and 16 free lists, drastically reducing memory fragmentation and system call overhead.

    - 16 free lists for chunk sizes aligned to 8-byte mutiples(8, 16, 24, ..., 128bytes)
    - Allocates memory in larger pools from the heap when a specific free list is empty, carving it up into individual blocks.

---

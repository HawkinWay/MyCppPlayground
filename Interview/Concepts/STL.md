# Standard Template library

- `Containers`: store data
- `Iterators`: connect data and algorithm
- `Algorithms`: operate data
- `Adapters`: converse interface
- `Allocators`: manage memory allocation and release
- `Functors`: pass to the algorithm as a strategy

---

## 1. Containers

### 1.1 Sequence Containers

|Name|Data Structure|Memory Layout|Important Interface|Iterator Invalidation|Remarks|
|--|--|--|--|--|--|
|vector|A dynamic array|Contiguous single block of memory(**means high `cache hit rate`**)|`emplace_back()`: since C++17, the sole advantage of this interface is *passing multiple constructor parameters and handle explicit constructor* (because of `Guaranteed Copy Elision`)|insert(), erase(), reserve()|vector bool is **not** a standard container, underlying storage is bit-packed (1-bit per boolean). `auto& ref = vb[0];` **fails to compile**, vb[0] is a temporary proxy, not `bool&`|
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

*concept: [Red-black tree](../Concepts/Tree.md)*

### 1.3 Unordered Assosiative Containers

|Name|Low Level Implement|Key Find|
|--|--|--|
|unordered_set|Hashmap|O(1), worst-case O(n)|
|unordered_multiset|Hashmap|O(1), worst-case O(n)|
|unordered_map|Hashmap|O(1), worst-case O(n)|
|unordered_multimap|Hashmap|O(1), worst-case O(n)|

*When all keys have conflict with a same bucker, the linked list length become n. This leads to a whole traversion of the linked list.*

#### unordered_map

`bucket`: each slot of the hash array

`load_factor`: the number of elements / the number of buckets. the smaller load_factor is, the shorter linked list is, so the faster find does.

`rehash`: when `load_factor()` > `max_load_factor()`(usually 1.0), reallocate bucket arrays, redistribute all elements into new buckets.

---


## 2. Iterators

An itrator is an object that behaves like a pointer that traverse and access elements of a container.

- `Input iterator`: read-only, `istream_iterator`
- `output iterator`: read-only, `ostream_iterator`
- `Forward iterator`: read and write, ++, `forward_list`
- `Bidirectional iterator`: ++, --`list`, `set`, `map`
- `Random access iterator`: +n, -n, [], `vector`, `deque`, `array`


`sort()` need Random access iterator  
`reverse()` need Bidirectional iterator  
`find()` need istream
`copy` need ostream  

*container list can't use `std::sort()`, use member function `.sort()`insteadly*


---

## 3. Algorithms

Algorithms don't work with containers themselves but rather with iterators. Therefore, the same algorithm can be used by most if not all of the C++ Standard Library containers.

find(), count(), for_each()

sort(), reverse(), replace(), swap()

### sort() vs stable_sort()

`sort`: Unstable sorting (IntroSort), the relative order of equal elements is not guaranteed.

`stable_sort`: Stable sorting (merge sort approach), guarantees the relative order of equal elements, but requires additional memory.

Use case: Sorting by multiple keys (first sort by name, then by department, maintaining name order).

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

## 6. Functors

A struct/class overloads `operator()`.

- std::greater<>
- std::less<>
- std::plus<>

|Dimension|Functor|Lambda|std::function|std::bind|
|--|--|--|--|--|
|Essence|Hand-writing class|Compiler-generated anonymous functor class|Generic callable object wrapper|Binding parameters to generate callable objects|
|Remarks||[], [=], [&], [x] [&x], [this]|
---

## Remarks

### Vector expansion

Before C++11, there're no move semantics. So when a vector expanse, it needs a new larger memory block and copy elements from old memory to new memory one by one(call copy constructor). Then destruct old elements and release old memory block. This made **deep copy** and have a huge overhead.

After C++11, with noexcept move constructor, vector can handle expansion faster. Because this only need copy some opinters(start, finish, end_of_storage).

### SSO(short string optimization)

If a string's length is less than 16B, it's a small string. std::string reserved a small cache block in stack and storage that. 

In the event of SSO, the move semantics of std::string degenerate into copying. Therefore, performing std::move on small strings does not result in a performance improvement.

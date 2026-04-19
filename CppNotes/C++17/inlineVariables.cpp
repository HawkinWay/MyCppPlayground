
// An inline variable can be defined in multiple translation units, the linker selects one definition and discards the rest.

//inline variables are useful for defining constants or static data members in header files
inline constexpr double pi = 3.141592653;

struct MyClass{
	static inline int instanceCount = 0;	// Can be defined in header
};

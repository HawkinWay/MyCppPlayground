// Unions conserve memory by enabling membes of different types to occupy the same memory location. But they aren't type-safe and are prone to programming errors.
// To solve this issue, C++17 introduces std::variant class.
// The std::visit function can be used to access the members of a variant type in a type-safe manner.

#include<variant>


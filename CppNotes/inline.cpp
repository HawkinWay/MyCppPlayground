
// Using inline functions can make your program faster because they eliminate the overhead associated with function calls
// Calling a function requires pushing the return address on the stack, pushing arguments onto the stack, jumping to the function body, and then executing a return instruction when the function finishes

// One Definition Rule(ODR) 单一定义原则
// Normally, a function can only be defined oce across all translation units
// When a function is marked inline, it can be defined in multiple translation units(typically via a header file) if all the definitions are identical.
// The linker then selects one definition and discards the duplicates rather than reporting an error

// The ODR aspect is a practical necessity where the same header(containing an inline function definition) may be included in multiple source files

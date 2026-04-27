// a specifier, a suffix to a function declaration
// Every function(include constructor and destructor) can be postfixed with 'noexcept', compiler will ensure this function won't throw excrption
// This means no exceptions can escape from their scope of function.
// If a 'noexcept' function throw out an exception, there are two situations: 1.The exception was caught within the function scope， then it cannot be rethrown.  2. The exception was not caught within the function scope, Cpp program calls 'std::terminate()' and end the program.


// WHEN TO USE?
// 1. Move Constructor
// 2. Move Assignment
// 3. Destructor
// 4. Swap

void doThat(int argument) noexcept{
try{
	//code for  the function
}
catch(...){
	// handles all exceptions and does now rethrow
}
}

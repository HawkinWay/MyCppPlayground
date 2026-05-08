// a template function, placeholder
// to represents a result that does not exist now but will appear in the future.
// this avoid the hassle of manually creating nd managing threads


// future is move semantic（move-only), once you call '.get()'，then this future is invalid
#include<iostream>
#include<future>

int func(){
	int i = 0;
	for(i = 0; i < 1000; i++){
		i++;
	}
	return i;
}

int main(){
	std::future<int> future_result = std::async(std::launch::async, func);		// this creates a child thread in the background to run, and returns the result to future_result
	std::cout << "func(): " << func() << std::endl;
	std::cout << "future_result.get(): " << future_result.get() << std::endl;		// Retrieves the result that is stored in the associated asynchronous state.
}

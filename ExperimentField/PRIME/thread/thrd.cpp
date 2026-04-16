#include "thrd.h"

namespace Genshen{
void Foo::print(){
	using namespace std::literals::chrono_literals;
	
	std::cout << "HUMAN...\n";
	std::this_thread::sleep_for(2.0s);
	std::cout << "...\n";
	std::this_thread::sleep_for(3.0s);
	std::cout << "AFTER\n";
	std::this_thread::sleep_for(0.5s);
	std::cout << "ALL\n";
	std::this_thread::sleep_for(3.0s);

	std::cout << "\nTHE\n";
	std::this_thread::sleep_for(0.2s);
	std::cout << "PRIME\n";
	std::this_thread::sleep_for(0.5s);
	std::cout << "TIME\n";
	std::this_thread::sleep_for(0.5s);
	std::cout << "OF YOUR\n";
	std::this_thread::sleep_for(0.5s);
	std::cout << "LIVE\n";
	std::this_thread::sleep_for(1.0s);

}
}

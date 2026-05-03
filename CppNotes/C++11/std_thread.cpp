#include<iostream>
#include<thread>

static bool Play = false;

void DoWork(){
	using namespace std::literals::chrono_literals;
	
	std::cout << "started thread id=" << std::this_thread::get_id() << std::endl;
	std::cout << "BPM:120" << std::endl;

	while(!Play){
		std::cout << "KICK\n";
		std::this_thread::sleep_for(0.5s);
		std::cout << "SNARE\n";
		std::this_thread::sleep_for(0.5s);
	}

}

int main(){
	std::thread drums(DoWork);

	std::cin.get();
	Play = true;

	drums.join();	// This main thread will only continue after the child thread (DoWork()) finishes. 
	std::cout << "Paused." << std::endl;
	std::cout << "started thread id=" << std::this_thread::get_id() << std::endl;
	#if 0
	drums.detach();	// detach the main thread and the child thread. Although main thread has finished , the child thread continues to run in the bacground.
	drums.joinable();	// return a bool value, judge wheather the thread can be joined
	#endif
	std::cin.get();
}

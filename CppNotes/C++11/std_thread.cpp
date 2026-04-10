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

	drums.join();	// waiting for thread 'drums' to end
	std::cout << "Paused." << std::endl;
	std::cout << "started thread id=" << std::this_thread::get_id() << std::endl;

	
	std::cin.get();
}

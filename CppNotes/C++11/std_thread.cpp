#include<iostream>
#include<thread>

static bool Play = false;

void DoWork(){
	using namespace std::literals::chrono_literals;
	
	std::cout << "BPM:128" << std::endl;

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

	drums.join();
	std::cout << "paused\n";
	
	std::cin.get();
}

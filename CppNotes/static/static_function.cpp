#include<iostream>

class Entity{
public:
	// static member-function can't add 'const', because static stuff has no 'this' pointer
	static int getSampleRate() /*error const*/{
		return sampleRate;	// can only call static member
	}

	void process(){
		// non-static function can all static members(static member-fucntions or static member-variables)
		int sr = getSampleRate();
		int test = sampleRate;
	}
private:
	static int sampleRate;

};

int Entity::sampleRate = 44100;	// static member-variables MUST defined outside the class

int main(){
	sr = Entity::getSampleRate();
	std::cout << sr << std::endl;
}

#include<iostream>
#include<string>

class LOG{
private:
	LOG(){};		// prevent 'new' outside
	LOG(const LOG& log) = delete;
	LOG& operator=(const LOG& log) = delete;
public:
	static LOG& getInstanceLazy(){
		static LOG log{};
		return log;
	}

	static LOG& getINstanceHungry(){
		static LOG* log = nullptr;
		if(!log)
			log = new LOG{};
		return *log;
	}

	void printLog(std::string msg){
		std::cout << __TIME__ << " " << msg << std::endl;
	}
};

int main(){
	LOG::getInstanceLazy().printLog("This is a test.");
	LOG::getINstanceHungry().printLog("This is also a test.");
}
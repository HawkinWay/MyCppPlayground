#include<iostream>
#include<string>

class LOG{
private:
	LOG(){};		// prevent 'new' outside
	LOG(const LOG& log) = delete;	// delete copy constructor. if we copy all the data, it's not a singleton
	LOG& operator=(const LOG& log) = delete;

// optimize: private printLog, this make the singleton be called simpler
	void I_print(std::string msg){
		std::cout << __TIME__ << " " << msg << std::endl;
	}
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
	
	/* optimize: private printLog, this make the singleton be called simpler
	
	void printLog(std::string msg){
		std::cout << __TIME__ << " " << msg << std::endl;
	}

	*/

	static void printLogLazy(std::string msg){
		getInstanceLazy().I_print(msg);
	}

	static void printLogHungry(std::string msg){
		getINstanceHungry().I_print(msg);
	}
};

int main(){
	/*
	LOG::getInstanceLazy().printLog("This is a test.");
	LOG::getINstanceHungry().printLog("This is also a test.");
	*/
// optimize: private printLog, this make the singleton be called simpler 
	LOG::printLogLazy("This a test.");
	LOG::printLogHungry("This also a test.");
}
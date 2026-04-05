#include<iostream>
#include<string>

class A{
	// friend fucntion is not a member fucntion,
	// have no 'this' pointer.
	// call friend function  directly by its fucntion name,
	// just like calling a regular global fucntion.
	friend long func(A s){
		if(s.x < 4){
			return 1;
		}
		return s.x + func(A(s.x - 1));
	}
public:
	A(long a){
		x = a--;
	}
private:
	long x;
};

int main(){
	int sum = 0;
	for(auto i = 0; i < 5; i++){
		sum += func(A(i));
	}
	std::cout << sum << std::endl;

}

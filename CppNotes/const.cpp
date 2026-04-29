#include<iostream>
#include<string>

// 不会修改对象的值的成员函数可以声明为const
// const对象无法调用它的非const成员函数
// West const: const int& val = vec.at(0); —— 你不能执行 val = 10
// East const: at(size_t index) const{}	这说明该函数是一个常成员函数。它承诺不会修改容器本身的任何成员变量

//  const int :它是原变量的一个只读副本,不能修改,开销有拷贝开销
//  int& :它是原变量的一个可写别名,可以修改,你在函数里改了这个引用，外部的原变量会跟着变,开销极小
//  const int& :它是原变量的一个只读别名,不能修改,开销极小。它不拷贝原对象，只是传递一个地址（在底层类似于指针）。

class Entity{
private:
	int X, Y;
	int var;
	const int varC = 0;
	mutable int varM;	// mutable means it's able to be change
	int *p, *q;			// p is pointer, q is pointer
	int *m, n;			// m is pointer, n is int
public:
	void setX(int x) const{
	    // X = x; 	    error
		// 在 const 成员函数内部，编译器会将所有的非 mutable 成员变量视为“常量”。
    	// 此时 this 指针的类型从 Entity* 变成了 const Entity*。
    	// 既然 this 指向的是常量对象，你就不能修改该对象的任何普通成员变量（如 X 和 Y）。
	}
	
	int GetX(){
		var = 2;
		//varC = 2;	    error, 无论是在普通成员函数还是 const 成员函数里，const 变量的值在初始化后都永远不能被修改。
		varM = 2;
		return X;
	}

	int GetXconst() const{
		//var = 2;		error, 在 const 函数中修改普通成员变量
		//varC = 2;	    error, 无论是在普通成员函数还是 const 成员函数里，const 变量的值在初始化后都永远不能被修改。
		varM = 2;
		return X;
	}

};

void printEntity(const Entity& e){
	
	std::cout << "e.GetXconst(): " << e.GetXconst() << std::endl;
}

class Rectangle{
private:
	int width, height;
public:
	Rectangle(int width, int height) : width(width), height(height){}

	void setWidth(/* Rectangle *this */int w){
		width = w;
	}

	int GetArea(/* const Rectangle *this */) const{
		return /*this->*/width * /*this->*/height;
	}

	int GetWidth(/* const Rectangle *this */) const{
		// this = rec;			this的作用相当于此
		// this->width = 0; 	error
		// this->setWidth();	error, const对象无法调用它的非const成员函数
		return width;
	}

	int GetHeight() const{
		return height;
	}
};

void printRectangle(const Rectangle& rec){
	std::cout << "rec.GetWidth(): " << rec.GetWidth() << std::endl;
}

int main(){
	Entity entity;
	printEntity(entity);
	

	Rectangle rec(10, 20);
	printRectangle(rec);

	std::cin.get();
}

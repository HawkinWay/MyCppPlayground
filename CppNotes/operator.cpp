// return reference(Point& operator), lvalue: needs to modify itself and return to itself, or needs chaining of assignments,  	
//		+ += -= *= /= ++(prefix) --(prefix) [] *

// return value(Point operator), rlavue: needs to create new object  	
//		+ - * / ++(postfix) --(postfix)

// return bool(bool operator): needs to judge	
//		== != > >= < <=

// return pointer(T* operator->()): ->
#include<iostream>

struct Complex{
	Complex(double r, double i) : re(r), im(i){}
	Complex operator+(Complex &other);
	void Display(){ std::cout << re << "," << im << std::endl;}
private:
	double re, im;

};

Complex Complex::operator+(Complex &other){
	return Complex(re + other.re, im + other.im);
}

class Point{
private:
	int _x, _y;
public:
	Point& operator++();	// prefix
	Point operator++(int);	// 'int' is dummy parameter, has no other use than distinguishing between prefix and postfix
};

Point& Point::operator++(){
	_x++;
	_y++;
	return *this;	// dereference 'this', 'this' points to the member variables(_x, _y)
}

Point Point::operator++(int){
	Point temp = *this;
	++*this;
	return temp;
}

class IntVector{
private:
	int _size;
	int *_arr;
public:
	IntVector(int n) : _size(n), _arr(new int[n]){ }
	~IntVector(){ delete[]_arr; }
	int& operator[](int idx);
};

int& IntVector::operator[](int idx){	// _arr[idx] is lvalue, return reference
	static int Err = -1;
	if(idx >=0 && idx < _size){
		return _arr[idx];
	}else{
		std::clog << "Array bounds violation" << std::endl;
		return Err;
	}
}

int main(){
	Complex a = Complex(1.2, 3.4);
	Complex b = Complex(7.8, 5.6);
	Complex c(0.0, 0.0);
	c = a + b;
	c.Display();

	Complex d = c.operator+(a);		// Complex d = c + a;
	d.Display();

	std::cout << "\n";

	IntVector v(10);
	int i;
	for(i = 0; i <= 10; ++i){
		v[i] = i;
	}

	v[3] = v[9];

	for(i = 0; i <= 10; ++i)
		std::cout << "Element: [" << i << "] =" << v.operator[](i) << std::endl;
}


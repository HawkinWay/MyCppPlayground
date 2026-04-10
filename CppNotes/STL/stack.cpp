#include<iostream>
#include<stack>
using namespace std;

int main() {
	//默认构造
	stack<int> stk;
	stk.push(1);
	stk.push(2);
	stk.push(3);
	stk.push(4);
	stk.push(5);
	stk.pop();   //删除栈顶元素，无返回值（相当于void）

	//stack容器没有迭代器（因为栈不允许遍历）
	/*for (int i = 0; i < stk.size(); i++) {
		cout << stk[i] << " ";
	}
	cout << endl;*/

	cout << stk.top() << endl;   //top函数只返回栈顶元素

	cout << "\nstk:" << endl;
	while (!stk.empty()) {       //当栈不为空时
		cout << stk.top() << endl;
		stk.pop();
	}


	//赋值
	//拷贝构造
	stk.push(1);
	stk.push(2);
	stk.push(3);
	stk.push(4);
	stk.push(5);
	//1
	stack<int> stk2(stk);
	cout << "\nstk2:" << endl;
	while (!stk2.empty()) {
		cout << stk2.top() << endl;
		stk2.pop();
	}
	//2
	stack<int> stk3 = stk;    //调用拷贝构造函数
	stk3 = stk;               //调用=号的重载 
	cout << "\nstk3:" << endl;
	while (!stk3.empty()) {
		cout << stk3.top() << endl;
		stk3.pop();
	}


	return 0;
}
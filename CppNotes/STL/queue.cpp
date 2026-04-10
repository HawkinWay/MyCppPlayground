#include<iostream>
#include<queue>
using namespace std;

int main() {
	queue<int> q;
	q.push(1);    //队尾添加元素
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	
	//queue容器没有迭代器（因为栈不允许遍历）
	/*for (int i = 0; i < stk.size(); i++) {
		cout << q[i] << " ";
	}
	cout << endl;*/
	
	cout << "queue head element: " << q.front() << endl;
	cout << "queue tail element: " << q.back() << endl;

	q.pop();     //队首出队元素
	
	cout << "\nafter pop, queue head element: " << q.front() << endl;
	cout << "after pop, queue tail element: " << q.back() << endl;

	cout << "\ntraverse queue: " << endl;
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;

	
	//拷贝构造
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	queue<int> q1(q);
	queue<int> q2;
	q2 = q;


	//获得队列中元素个数
	cout << "\nq1 size: " << q1.size() << "\nq2 size: " << q2.size() << endl;

	
	//数据的存取  .front()和.back()可以作为表达式的左值
	q1.front() = 10;
	cout << "\nafter modify head, traverse q1: ";
	while (!q1.empty()) {
		cout << q1.front() << " ";
		q1.pop();
	}
	cout << endl;

	q2.back() = 50;
	cout << "\nafter modify tail, traverse q2: ";
	while (!q2.empty()) {
		cout << q2.front() << " ";
		q2.pop();
	}
	cout << endl;



	return 0;
}
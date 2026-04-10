#include<iostream>
#include<set>

using namespace std;

int main() {
	set<int> st1;
	st1.insert(1);
	st1.insert(5);
	st1.insert(3);
	st1.insert(9);
	st1.insert(7);

	set<int>::iterator it;
	for (it = st1.begin(); it != st1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	set<int>::reverse_iterator rit;
	for (rit = st1.rbegin(); rit != st1.rend(); rit++) {
		cout << *rit << " ";
	}
	cout << endl;

	//拷贝构造
	set<int> st2(st1);
	set<int> st3;
	st3 = st2;
	//交换
	st3.swap(st2);

	//***set容器不支持用反向迭代器对元素进行删除

	//erase函数删除的元素如果在set中，返回TRUE，否则返回FALSE
	cout << st1.erase(100) << endl;


	//降序排序                        //升序排序为set<int,less<int>>或set<int>
	set<int,greater<int>> st4;
	st4.insert(1);
	st4.insert(5);
	st4.insert(3);
	st4.insert(9);
	st4.insert(7);

	set<int>::iterator it4;
	for (it4 = st4.begin(); it4 != st4.end(); it4++) {
		cout << *it4 << " ";
	}
	cout << endl;
	//9 7 5 3 1

	//find函数（返回迭代器）
	it4 = st4.find(5);        
	cout << *it4 << endl;
	it4 = st4.find(6);		//如果找不到指定元素，返回end()
	it4--;
	cout << *it4 << endl;
	
	//count函数				//找到返回1，找不到返回0
	cout << st4.count(1) << endl;
	cout << st4.count(6) << endl;


	//1 3 5 7 9
	//查找≥的第一个迭代器
	it = st1.lower_bound(5);
	cout << "\n≥5：" << *it << endl;
	//查找＞的第一个迭代器
	it = st1.upper_bound(5);
	cout << "\n>5：" << *it << endl;
	cout << endl;


	//equal_range()函数，返回迭代器
	pair<set<int>::iterator, set<int>::iterator> p = st1.equal_range(5);
	cout << *p.first << endl;   //pair对组中第一个元素
	cout << *p.second << endl;  //pair对组中第二个元素


	return 0;
} 
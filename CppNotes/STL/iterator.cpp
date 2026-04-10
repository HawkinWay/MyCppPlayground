#include<iostream>
#include<vector>
using namespace std;

int main() {
	int arr[] = { 1,2,3,4,5 };
	vector<int> vec;
	vec.assign(arr, arr + 5);
	

	vector<int>::iterator it;
	it = vec.begin();
	//cout << *it << endl;

	//遍历
	for (it = vec.begin(); it != vec.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//迭代器的失效(在插入和删除的时候)
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	vector<int>::iterator it1 = v.begin() + 3;
	v.insert(it1, 8);
	//cout << *it1 << endl;   
	//此时直接访问会报错，因为插入后，容器清空，容器寻找了个新空间重新存放元素，而it仍指向旧容器，此时为野指针
	
	//正确应该将  v.insert(it1, 8);  改为   it1 = v.insert(it1, 8);
	//cout << *it1 << endl;
	for (it1 = v.begin(); it1 != v.end(); it1++) {
		cout << *it1 << " ";
	}
	cout << endl;

	int arr2[] = { 1,2,3,3,3,4,3,3,5 };
	vector<int> vec2(arr2, arr2 + 9);
	vector<int>::iterator it2 = vec2.begin();
	/*for (it2 = vec2.begin(); it2 != vec2.end(); it2++) {
		cout << *it2 << " ";
	}
	cout << endl;*/

	for (it2 = vec2.begin(); it2 != vec2.end();) {
		if (*it2 == 3) {
			it2 = vec2.erase(it2);
		}
		else {
			it2++;
		}
	}
	for (it2 = vec2.begin(); it2 != vec2.end(); it2++) {
		cout << *it2 << " ";
	}
	cout << endl;

	cout << endl;
	system("pause");
	return 0;
}
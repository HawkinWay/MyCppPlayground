#include<iostream>
#include<vector>
#include<list>
using namespace std;

int main() {
	list<int> lst;
	lst.push_back(20);
	lst.push_back(21);
	lst.push_front(19);
	lst.push_front(18);
	lst.pop_front();
	lst.pop_back();
	list<int>::iterator it;
	for (it = lst.begin(); it != lst.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	lst.push_back(21);
	lst.push_front(18);
	int x = lst.front();
	int y = lst.back();
	cout << "x = " << x << ", y =" << y << endl;

	lst.front() = 100;
	lst.back() = 200;
	int m = lst.front();
	int n = lst.back();
	cout << "m = " << m << ", n =" << n << endl;

	//反向迭代器
	list<int>::reverse_iterator rit;
	for (rit = lst.rbegin(); rit != lst.rend(); rit++) {
		cout << *rit << " ";
	}
	cout << endl;



	//list的带参构造
	//3个5
	list<int> lst1(3, 5);
	list<int>::iterator it1;
	cout << "\nlst1: ";
	for (it1 = lst1.begin(); it1 != lst1.end(); it1++) {
		cout << *it1 << " ";
	}
	cout << endl;
	//[begin,end)
	list<int> lst2(lst.begin(), lst.end());
	  //list<int> lst2(lst.begin()+1, lst.end()+2);   错误原因：list容器只能自增自减，不能加减（类似链表）
	list<int>::iterator it2;
	cout << "lst2: ";
	for (it2 = lst2.begin(); it2 != lst2.end(); it2++) {
		cout << *it2 << " ";
	}
	cout << endl;
	//拷贝构造
	list<int> lst3(lst2);
	list<int>::iterator it3;
	cout << "lst3: ";
	for (it3 = lst3.begin(); it3 != lst3.end(); it3++) {
		cout << *it3 << " ";
	}
	cout << endl;



	//list赋值
	list<int> lstA, lstB, lstC, lstD;
	//[begin,end)
	list<int>::iterator beg = lst.begin();
	beg++;

	lstA.assign(beg, lst.end());
	list<int>::iterator itA;
	cout << "\nlstA: ";
	for (itA = lstA.begin(); itA != lstA.end(); itA++) {
		cout << *itA << " ";
	}
	cout << endl;
	//9个9
	lstB.assign(9, 9);
	list<int>::iterator itB;
	cout << "lstB: ";
	for (itB = lstB.begin(); itB != lstB.end(); itB++) {
		cout << *itB << " ";
	}
	cout << endl;
	//拷贝，此处略
	//swap交换
	lstC.assign(lstA.begin(), lstA.end());
	lstD.assign(lstB.begin(), lstB.end());
	lstD.swap(lstC);

	list<int>::iterator itC, itD;
	cout << "lstC: ";
	for (itC = lstC.begin(); itC != lstC.end(); itC++) {
		cout << *itC << " ";
	}
	cout << endl;
	cout << "lstD: ";
	for (itD = lstD.begin(); itD != lstD.end(); itD++) {
		cout << *itD << " ";
	}
	cout << endl;



	//长度
	cout << "\nlstB size: " << lstB.size() << endl;
	//判断空
	cout << "is lstB empty? " << lstB.empty() << endl;
	//该变容器大小
	cout << "Change the size of lstB, resize to 3. " << endl;
	cout << "lstB: ";
	lstB.resize(3);
	for (itB = lstB.begin(); itB != lstB.end(); itB++) {
		cout << *itB << " ";
	}
	cout << endl;
	cout << "Change the size of lstB, resize to 12 and use 90 to fill. " << endl;
	cout << "lstB: ";
	lstB.resize(12,90);
	for (itB = lstB.begin(); itB != lstB.end(); itB++) {
		cout << *itB << " ";
	}
	cout << endl;



	//插入
	list<int> lstE;
	lstE.assign(lstD.begin(), lstD.end());
	list<int>::iterator itE;
	cout << "\nlstE:";
	for (itE = lstE.begin(); itE != lstE.end(); itE++) {
		cout << *itE << " ";
	}
	cout << endl;
	//lstE.insert(2, 21);  错误，list要插入只能通过迭代器，无法用下标
	for (itE = lstE.begin(); itE != lstE.end(); itE++) {
		if (*itE == 200) {
			break;
		}
	}
	if (itE != lstE.end()) {
		lstE.insert(itE, 21);  //此处不写 itE = lstE.insert(itE, 21); 迭代器也不会失效
	  //lstE.insert(itE, 3, 21);   在itE的位置插入3个21
      //lstE.insert(itE, lst.begin(), lst.end())  在itE的位置插入lst容器的[begin,end)
		cout << "*itE: " << *itE << endl;
	}
	cout << "After insert, lstE:";
	for (itE = lstE.begin(); itE != lstE.end(); itE++) {
		cout << *itE << " ";
	}
	cout << endl;



	//删除
	lstB.remove(90);
	cout << "\nAfter remove 90, lstB: ";
	for (itB = lstB.begin(); itB != lstB.end(); itB++) {
		cout << *itB << " ";
	}
	cout << endl;
	//清空
	lstB.clear();
	cout << "After clear, lstB: " << (lstB.empty() ? "空" : "非空") << endl;


	//反转
	//lstD.reverse();
	
	
	
	//迭代器的失效(只有删除的时候)
	//使用erase后，返回删除节点的下一个结点的迭代器
	//用迭代器删除list中某个元素的所有，正确写法应为
	/*for (it2 = vec2.begin(); it2 != vec2.end();) {
		if (*it2 == 3) {
			it2 = vec2.erase(it2);
		}
		else {
			it2++;
		}
	}*/

	cout << endl;
	system("pause");
	return 0;
}
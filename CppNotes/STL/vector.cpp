#include<iostream>
#include<vector>
using namespace std;

int main() {
	int arr[] = { 1,2,3,4,5 };
	vector<int> vec1(arr, arr + 5);  //存[1,6)

	vector<int> vec2(3, 10); //存3个10
	for (int i = 0; i < 5; i++) {
		cout << vec1[i] << " ";
	}
	cout << endl;
	//拷贝构造
	vector<int> vec3(vec1);
	vector<int> vec4 = vec2;

	//vector赋值
	vector<int> vecA, vecB, vecC, vecD;
	//将数组arr中的所有元素赋值给vecA容器
	vecA.assign(arr, arr + 5);  //assign赋值会清空原来的值
	cout << "\nvecA:\n";
	for (int i = 0; i < vecA.size(); i++) {
		cout << vecA[i] << " ";
	}
	cout << endl;
	//将vecA中所有的元素赋值给vecB
	cout << "vecB:\n";
	vecB.assign(vecA.begin() + 1, vecA.end() - 2);  //**end指向最后一个元素的下一个元素
	for (int i = 0; i < vecB.size(); i++) {
		cout << vecB[i] << " ";
	}
	cout << endl;
	//4个10
	cout << "vecC:\n";
	vecC.assign(4, 10);
	for (int i = 0; i < vecC.size(); i++) {
		cout << vecC[i] << " ";
	}
	cout << endl;
	//将C与B中元素互换
	cout << "\nswap B and C:\n";
	vecB.swap(vecC);
	cout << "vecB:";
	for (int i = 0; i < vecB.size(); i++) {
		cout << vecB[i] << " ";
	}
	cout << "\nvecC:";
	for (int i = 0; i < vecC.size(); i++) {
		cout << vecC[i] << " ";
	}
	cout << endl;
	//=符号重载
	cout << "\nvecD:";
	vecD = vecC;
	for (int i = 0; i < vecD.size(); i++) {
		cout << vecD[i] << " ";
	}
	cout << endl;

	//判断容器是否空,为空则输出1
	vector<int> vecE;
	if (vecE.empty()) {
		cout << "\nvecE is empty." << endl;
	}
	else {
		cout << "\nvecE is not empty." << endl;
	}

	vecE.assign(arr, arr + 5);
	if (vecE.empty()) {
		cout << "\nvecE is empty." << endl;
	}
	else {
		cout << "\nvecE is not empty." << endl;
	}

	//更改长度
	cout << "\nvecE, before resize longer:";
	for (int i = 0; i < vecE.size(); i++) {
		cout << vecE[i] << " ";
	}
	vecE.resize(10);
	cout << "\nvecE, after resize longer:";
	for (int i = 0; i < vecE.size(); i++) {
		cout << vecE[i] << " ";
	}
	cout << endl;

	cout << "\nvecE, before resize shorter:";
	for (int i = 0; i < vecE.size(); i++) {
		cout << vecE[i] << " ";
	}
	vecE.resize(3);
	cout << "\nvecE, after resize shorter:";
	for (int i = 0; i < vecE.size(); i++) {
		cout << vecE[i] << " ";
	}
	cout << endl;

	cout << "\nvecE, before resize longer and use 258 to fill:";
	for (int i = 0; i < vecE.size(); i++) {
		cout << vecE[i] << " ";
	}
	vecE.resize(10, 258);
	cout << "\nvecE, after resize longer and use 258 to fill:";
	for (int i = 0; i < vecE.size(); i++) {
		cout << vecE[i] << " ";
	}
	cout << endl;

	//访问下标     *用.at()遇到异常会说明
	vecE[6] = 100;
	vecE.at(8) = 369;
	cout << "\nvecE, change vecE[6] to 100, vecE[8] to 369:";
	for (int i = 0; i < vecE.size(); i++) {
		cout << vecE[i] << " ";
	}
	cout << endl;

	//插入与删除
	//队尾
	vecE.push_back(44);
	cout << "\nvecE, insert 44 at the end:";
	for (int i = 0; i < vecE.size(); i++) {
		cout << vecE[i] << " ";
	}
	vecE.pop_back();
	cout << "\nvecE, delete the end element:";
	for (int i = 0; i < vecE.size(); i++) {
		cout << vecE[i] << " ";
	}
	cout << endl;
	//队中
	vecE.insert(vecE.begin()+3, 48);
	cout << "\nvecE, insert 44 at the index of 3:\n";
	for (int i = 0; i < vecE.size(); i++) {
		cout << vecE[i] << " ";
	}
	vecE.insert(vecE.begin() + 3, 3, 2077);
	cout << "\nvecE, insert  three 2077 at the index of 3:\n";
	for (int i = 0; i < vecE.size(); i++) {
		cout << vecE[i] << " ";
	}
	vecA.insert(vecA.begin() + 5, vecE.begin() + 5, vecE.end() - 6);
	cout << "\nvecA, insert vecE[5] to vec[7] at the index of 5:\n";
	for (int i = 0; i < vecA.size(); i++) {
		cout << vecA[i] << " ";
	}




	cout << endl;
	system("pause");
	return 0;
}
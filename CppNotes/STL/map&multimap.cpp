#include<iostream>
#include<map>
#include<string>
using namespace std;

class Student {
public:
	int id;
	string name;

	Student() {

	}
	Student(int id, string name) {
		this->id = id;
		this->name = name;
	}

};

int main() {
	Student s1(1, "WuYi");
	Student s2(2, "SunEr");
	//map容器的插入, map容器的键不可以冲突
	map<int, Student> stus;
	//1.insert()——直接构造pair
	stus.insert(pair<int, Student>(s1.id,s1));
	//2.insert()——value_type
	stus.insert(map<int, Student>::value_type(s2.id, s2));


	map<int, string> mapS;
	mapS.insert(pair<int, string>(3, "ZhangSan"));  //3是键，“小张”是值
	mapS.insert(pair<int, string>(4, "LiSi"));
	
	mapS.insert(map<int, string>::value_type(5, "WangWu"));
	map<int, string>::value_type v(6, "ZhaoLiu");
	mapS.insert(v);
	//3.直接赋值
	mapS[7] = "MaQi";   //用这种插入方法需要注意冲突问题，冲突不报错 并用新的值覆盖旧的值



	
	//map容器的迭代
	map<int, string>::iterator itS;
	cout << "traverse mapS: " << endl;
	for (itS = mapS.begin(); itS != mapS.end(); itS++) {
		pair<int, string> p = *itS;
		int keyS = p.first;
		string valueS = p.second;

		cout << keyS << ": " << valueS << endl;
	}
	cout << endl;

	map<int, Student>::iterator itstus;
	cout << "traverse stus: " << endl;
	for (itstus = stus.begin(); itstus != stus.end(); itstus++) {
		pair<int, Student> p = *itstus;
		int keystus = p.first;
		Student stu = p.second;

		cout << keystus << ": " << stu.name << endl;
	}


	//获取键对应的值	
	string stu_name = mapS[10];			//若键10对应的值不存在，则自动创建一个键为10、默认值为""的键值对
	cout << "\nmapS[10] stu_name is: " << stu_name << endl;

	map<int, string>::iterator it = mapS.find(3);
	cout << "use iterator, 3: " << (*it).second << endl;

	cout << "use .at: " << mapS.at(3) << endl;

	return 0;
}
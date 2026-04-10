#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

int main() {
	unordered_map<int, int> umap;
	//插入
	//1.直接赋值
	umap[1] = 10;            //用这种插入方法依旧需要注意冲突问题，冲突不报错 并用新的值覆盖旧的值
	
	//2.insert()——直接构造pair
	umap.insert(pair<int, int>(2, 20));
	
	//3.insert()——value_type
	umap.insert(unordered_map<int, int>::value_type(3, 30));

	//4.insert()——{}初始化
	umap.insert({ 4,40 });



	//迭代器
	auto it = umap.begin();		//等效于unordered_map<int, int>::iterator it = umap.begin();
	cout << "umap.begin(): " << it->first << " " << it->second << endl;   //(*it).first和(*it).second也行
	//原错误：cout << "umap.begin(): " << *it << endl;
	//unordered_map<int, int> 的迭代器解引用得到的是 pair<const int, int> 类型

	cout << "\ntraverse umap with iterator: " << endl;
	for (it = umap.begin(); it != umap.end(); it++) {
		pair<int, int> p = *it;
		int fst = p.first;
		int scd = p.second;
		cout << fst << ": " << scd << endl;
	}



	//次数统计
	vector<int> vec = { 1,3,3,3,6,6,9,9,9,9 };
	unordered_map<int, int> cnt;
	for (int num : vec) {
		cnt[num]++;
	}
	cout << "\n对于{1,3,3,3,6,6,9,9,9,9}" << endl;
	for (const auto &pair : cnt) {
		cout << pair.first << "出现 " << pair.second << " 次" << endl;
	}



	//判断元素是否存在
	if (umap.find(1) != umap.end())			//使用if(umap[key])判断是否存在有风险！——会插入为0的值，可能会污染数据
		cout << "\n存在" << endl;
	else
		cout << "不存在" << endl;


	//遍历
	cout << "\ntraverse umap without iterator: " << endl;    //遍历顺序随机
	for (auto& p : umap) {
		cout << p.first << ": " << p.second << endl;
	}


	//判断是否为空
	if (umap.empty())
		cout << "umap is empty." << endl;
	else
		cout << "umap is not empty." << endl;

	return 0;
}
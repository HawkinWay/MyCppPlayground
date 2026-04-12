#include<iostream>
#include<stack>
#include<list>
#include<unordered_map>
#include<algorithm>
#include<cmath>


//思路严重错误，std::list<std::unordered_map<int, int>>完全不对。这个意思是双向链表中的每个节点都存储一个哈希表，而一个哈希表存在好几个键值对！
// 本来的意思应该是用双向链表存储键值对的，所以应该是std::list<pair<int, int>>
//class LRUCache {
//private:
//	std::list<std::unordered_map<int, int>> lst;
//	std::unordered_map<int, int> mp;
//	int n;
//	std::list<std::unordered_map<int, int>>::iterator olddest = lst.begin();
//public:
//	LRUCache(int capacity) {
//		//lst.resize(capacity);
//		n = capacity;
//	}
//
//	int get(int key) {
//		if (mp.find(key) != mp.end()) {
//			return mp[key];
//		}
//		return -1;
//	}
//
//	// 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。
//	// 如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
//	void put(int key, int value) {
//		if (mp.find(key) != mp.end()) {
//			mp[key] = value;
//		}
//		else {
//			if (lst.size() == n) {
//				
//			}
//			else {
//				lst.push_back({ key,value });
//			}
//		}
//	}
//};


class LRUCache {
private:
	int capacity;
	std::list<std::pair<int, int>> lst;
	std::unordered_map<int, std::list<std::pair<int, int>>::iterator> mp;
public:
	LRUCache(int capacity) {
		this->capacity = capacity;
	}

	int get(int key) {
		auto mpit = mp.find(key);
		if (mpit != mp.end()) {
			auto lstit = mpit->second;
			lst.splice(lst.begin(), lst, lstit);
			return lstit->second;
		}
		return -1;
	}

	// 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。
	// 如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
	void put(int key, int value) {
		auto mpit = mp.find(key);
		if (mpit != mp.end()) {
			mpit->second->second = value;
			auto lstit = mpit->second;
			lst.splice(lst.begin(), lst, lstit);
		}
		else {
			if (lst.size() == capacity) {
				auto lstback = lst.back();
				lst.pop_back();
				mp.erase(lstback.first);
			}
			lst.push_front({ key,value });
			mp[key] = lst.begin();
		}
	}
};
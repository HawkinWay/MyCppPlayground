#include<iostream>
#include<deque>
using namespace std;

int main() {
	deque<int> deq = { 1,2,3,4,5 };
	deq.push_front(100);
	deque<int>::iterator it;
	it = deq.erase(deq.begin());
	
	for (it = deq.begin(); it != deq.end(); it++) {
		cout << *it << " ";
	}

	cout << endl;


	return 0;
}
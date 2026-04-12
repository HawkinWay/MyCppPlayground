#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int head = 0, tail = numbers.size() - 1;
        while (numbers[head] + numbers[tail] != target) {
            if (numbers[head] + numbers[tail] < target) {
                head++;
            }
            if (numbers[head] + numbers[tail] > target) {
                tail--;
            }
        }
        vector<int> result;
        result.push_back(head + 1);
        result.push_back(tail + 1);
        return result;

    }
};

int main() {
    vector<int> arr = { 1,2,3,4,4,9,56,90 };

    Solution sl;
    vector<int> result = sl.twoSum(arr, 8);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;


    return 0;
}
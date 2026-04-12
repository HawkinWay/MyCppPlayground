#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        int minPrice = prices.at(0);
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            int maxProfit = prices.at(i) - minPrice;
            
            if (prices.at(i) < minPrice) {
                minPrice = prices.at(i);
            }
            if (maxProfit > profit) {
                profit = maxProfit;
            }
        }
        return profit;
    }
};

int main() {
    Solution sl;
    vector<int> prices = { 7,6,4,3,1 };
    cout << "最大利润为：" << sl.maxProfit(prices);


    return 0;
}
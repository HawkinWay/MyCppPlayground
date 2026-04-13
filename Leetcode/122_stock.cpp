#include<iostream>
#include<vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
       int profit = 0, mn = 999999, total = 0;
        for(auto i = 0; i < prices.size(); i++){
            profit = std::max(profit, prices[i] - mn);
            if(profit > 0){
                total += profit;
                profit = 0;
                mn = 999999;
            }
            mn = std::min(mn, prices[i]);
        }
        return total;
    }
};

int main(){
    std::vector<int> prices1 = {7,1,5,3,6,4};
    std::vector<int> prices2 = {1,2,3,4,5};
    Solution sl;
    std::cout << "max profit1: " << sl.maxProfit(prices1);
    std::cout << "\nmax profit2: " << sl.maxProfit(prices2);

    std::cin.get();
}
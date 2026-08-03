#include <vector>
using namespace std;

class Solution {
public:
    // bool isAnagram(const string &p, int (&count)[128]){
    //     for(const auto &i : p){
    //         if(count[i] != 0)
    //             return false;
    //     }
    //     return true;
    // }

    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int count[128] = {0};
        for(auto &i : p){
            count[i]++;
        }
        int head = 0, need = p.size();
        for(int tail = 0; tail < s.size(); tail++){
            if(count[s[tail]] > 0)  need--;
            count[s[tail]]--;
            if(tail - head + 1 == p.size()){
                if(need == 0)   ans.push_back(head);
                if(count[s[head]] >= 0)  need++;
                count[s[head]]++;
                head++;
            }
        }

        return ans;
    }
};

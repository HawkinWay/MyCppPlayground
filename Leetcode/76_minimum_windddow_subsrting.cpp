#include <string>
using namespace std;

#if 0
class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        if(m < n)   return "";

        int count[128] = {0};
        for(auto &i : t){
            count[i]++;
        }

        string ans = s;
        int head = 0, need = t.size();
        for(int tail = 0; tail < s.size(); tail++){
            if(count[s[tail]] > 0)     need--;
            count[s[tail]]--;

            while(need == 0){
                string temp = s.substr(head, tail - head + 1);
                if(temp.size() < ans.size()){
                    ans = temp;
                }
                if(count[s[head]] >= 0)     need++;
                count[s[head]]++;
                head++;
            }
        }
        
        return ans;
    }
};

// Error case: s = "a", t = "b"
#endif

// Optimize substr method, only store start position and length
class Solution {
public:
    string minWindow(string s, string t) {
        int count[128] = {0};
        for(auto &i : t){
            count[i]++;
        }

	int startPosition = 0, len = INT_MAX;
        int head = 0, need = t.size();
        for(int tail = 0; tail < s.size(); tail++){
            if(count[s[tail]] > 0)     need--;
            count[s[tail]]--;

            while(need == 0){
		if(tail - head + 1 < len){
			startPosition = head;
			len = right - left + 1;
		}
		    
                if(count[s[head]] >= 0)     need++;
                count[s[head]]++;
                head++;
            }
        }
        
        return (len == INT_MAX) ? "" : s.substr(startPosition, len);
    }
};

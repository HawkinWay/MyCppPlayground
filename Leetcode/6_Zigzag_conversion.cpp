#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int idx = 0, n = s.size();
        if(numRows == 1 || n == 1)    return s;
        string ans;
        int intervalNums = (numRows - 1) + (numRows - 2) + 1;   // 2 * numRows - 2
        for(int i = 0; i < numRows; i++){
            idx = i;
            if(idx == 0 || idx == numRows - 1){
                while(idx <= n - 1){        // notice <=
                    ans += s[idx];
                    idx += intervalNums;
                }
            }else{
                bool jump = true;   // use jump to switch between intervalNum and intervalNumN
                while(idx <= n - 1){        // notice <=
                    int intervalNumsN = 2 * numRows - 2 * i - 2;
                    if(jump == true){
                        ans += s[idx];
                        idx += intervalNumsN;
                    }
                    else{
                        ans += s[idx];
                        idx += intervalNums - intervalNumsN;
                    }
                    jump = !jump;   
                }
            }
        }
        return ans;
    }
};


int main(){
    string s = "PAYPALISHIRING";
    string s2 = "AB";
    string s3 = "A";
    Solution sl;
    cout << sl.convert(s, 4) << '\n' << sl.convert(s2, 2) << '\n' << sl.convert(s3, 2);
}
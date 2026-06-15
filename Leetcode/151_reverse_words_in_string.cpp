#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        if(n == 1)  return s;
        int slow = 0, fast = 0;
        while(fast < n){    // this cycle aims to retrim ' ' : " a good   example " =>  "a good example    "
            if(s[fast] != ' '){
                if(slow != 0){
                    s[slow++] =' ';
                }
                while(fast < n && s[fast] != ' '){
                    s[slow++] = s[fast++];
                }
            }
            fast++;
        }
        s.resize(slow);     // notice the size of s has changed, we need renew the value of n
        
        reverse(s.begin(), s.end());
        n = s.size();


        int head = 0, tail = 0;
        while(tail <= n){   // only when <=, the tail can reach the value of s.size() 
            if(tail == s.size() || s[tail] == ' '){    
                reverse(s.begin() + head, s.begin() + tail);
                head = tail + 1;
            }
            tail++;
        }
        return s;
    }
};

int main(){
    string s1 = "a good   example";
    string s2 = "the sky is blue";
    string s3 = "  hello world  ";

    Solution sl;
    string out1 = sl.reverseWords(s1);
    string out2 = sl.reverseWords(s2);
    string out3 = sl.reverseWords(s3);

    cout << out1 << '\n' << out2 << '\n' << out3;
}
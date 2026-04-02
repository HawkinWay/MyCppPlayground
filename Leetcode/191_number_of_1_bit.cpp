#include<iostream>

class Solution{
public:
    int hammingWeight(int n){
        int sum = 2;
        int count = 0;
        while(sum < n){
            sum *= sum;
            count++;
        }
        int remainder = n - sum / 2;
        count--;
        hammingWeight(remainder);
    }
};

int binary(int n){
    int sum = 2;
    int count = 1;
    while(sum < 11){
        sum *= sum;
        count++;
    }
    int remainder = 11 - sum / 2;
    return binary(remainder);

}

int main(){
    
    // std::cout << "sum: " << sum << 
    //         "\nremainder: " << remainder << 
    //         "\ncount: " << count << std::endl;
}
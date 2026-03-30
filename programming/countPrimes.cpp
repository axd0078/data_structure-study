#include<vector>
#include<iostream>
#include<cmath>
using namespace std;

class Solution{
public:
    int countPrimes(int n){
        vector<bool> isprime(n,true);
        for(int i=2;i * i<n;i++){
            if(isprime[i]){
                for(int j=i*i;j<n;j+=i){
                    isprime[j] = false;
                }
            }
        }
        int count = 0;
        for(int i=2;i<n;i++){
            if(isprime[i])
                count++;
        }
        return count;
    }//时间复杂度O(N*loglogN)
};

int main(){
    int n;
    cin >> n;
    Solution s;
    cout << s.countPrimes(n) <<endl;
    return 0;
    
}
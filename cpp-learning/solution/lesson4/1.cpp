#include <bits/stdc++.h>
using namespace std;

void swapByRef(int& a,int& b){
    int temp = a;
    a = b;
    b = temp;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b;
    cin >> a >> b;
    swapByRef(a,b);
    cout << a << " " << b <<endl;
}
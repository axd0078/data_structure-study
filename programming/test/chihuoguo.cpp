#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin,s);//整行读取
    int num = 0;
    int ans = 0;
    int begin = 0;
    while(s!="."){
        num++;
        if(s.find("chi1 huo3 guo1")!=string::npos){ //没找到返回string::npos 
            //fgets(s, sizeof(s), stdin); c的 但是最后会有一个"\n"
            if(begin==0) begin = num;
            ans++;
        }
        getline(cin,s);
    }
    cout << num <<endl;
    if(ans == 0){
        cout << "-_-#" <<endl;
    }
    else{
        cout << begin << " "<< ans ;
    }
    return 0;
}
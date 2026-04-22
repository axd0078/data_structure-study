#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> list;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        list.push_back(a);
    }
    vector<vector<int>> s;
    vector<int> xorS;
    for(int i=0;i<m;i++){
        int size;
        int xorSi = 0;
        cin >> size;
        vector<int> si;
        for(int j=0;j<size;j++){
            int index;
            cin >> index;
            si.push_back(index);
            xorSi ^= list[index-1];
        }
        s.push_back(si);
        xorS.push_back(xorSi);
    }
    vector<int> t;
    for(int i=0;i<m;i++){
        int size;
        int xorT = 0;
        cin >> size;
        for(int j=0;j<size;j++){
            int index;
            cin >> index;
            t.push_back(index);
            xorT ^= list[index-1];
        }
        if((s[i]==t)==(xorT==xorS[i]))
            cout << "correct" << endl;
        else
            cout << "wrong" << endl;
        t.clear();
    }
    return 0;
}
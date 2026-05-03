#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    cin.ignore();
    set<string> a,b;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        transform(s.begin(),s.end(),s.begin(),::tolower);
        a.insert(s);
    }
    for(int i=0;i<m;i++){
        string s;
        cin >> s;
        transform(s.begin(),s.end(),s.begin(),::tolower);
        b.insert(s);
    }
    set<string> result;
    set_intersection(a.begin(),a.end(),b.begin(),b.end(),inserter(result, result.begin()));
    cout << result.size() << endl;
    result.clear();
    set_union(a.begin(),a.end(),b.begin(),b.end(),inserter(result, result.begin()));
    cout << result.size() << endl;
    return 0;
}


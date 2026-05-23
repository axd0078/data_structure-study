#include <bits/stdc++.h>
using namespace std;

struct stu{
    string name;
    float grade;
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    stu max;
    cin >> max.name >> max.grade;
    for(int i=1;i<n;i++){
        stu s;
        cin >> s.name >> s.grade;
        if(s.grade > max.grade)
            max = s;
    }

    cout << max.name << " " << max.grade;
}
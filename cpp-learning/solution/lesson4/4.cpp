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

    vector<stu> info;
    for(int i=0;i<n;i++){
        stu s;
        cin >> s.name >> s.grade;
        info.push_back(s);
    }

    sort(info.begin(),info.end(),[](const stu& a,const stu& b){
        if(a.grade==b.grade)
            return a.name < b.name;
        return a.grade > b.grade;
    });


    for(int i=0;i<n;i++){
        cout << info[i].name << " " << info[i].grade << endl;
    }
    return 0;
}
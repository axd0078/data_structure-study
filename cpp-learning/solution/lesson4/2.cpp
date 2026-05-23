#include <bits/stdc++.h>
using namespace std;

float getAve(const vector<float>& grade){
    float sum = 0.0;
    int size = grade.size();
    for(int i=0;i<size;i++){
        sum += grade[i];
    }
    return sum /= size;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<float> grade;
    for(int i=0;i<n;i++){
        float x;
        cin >> x;
        grade.push_back(x);
    }
    cout << fixed << setprecision(2) << getAve(grade) << endl;
    return 0;
}
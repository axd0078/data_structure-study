#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m,q;
    cin >> n >> m >> q;
    long long safe = 1LL* n*m;
    vector<vector<int>> attack(q,vector<int>(2));
    for(int i=0;i<q;i++){
        cin >> attack[i][0] >> attack[i][1];
    }
    vector<bool> attackRow(n,false);
    vector<bool> attackCol(m,false);
    int row = 0,col = 0;
    for(int i=0;i<q;i++){
        if(attack[i][0] == 0){
            if(!attackRow[attack[i][1]-1]){
                attackRow[attack[i][1]-1] = true;
                row++;
            }
        }
        else{
            if(!attackCol[attack[i][1]-1]){
                attackCol[attack[i][1]-1] = true;
                col++;
            }
        }
    }
    safe -= row * m + col * n - col*row;
    cout << safe;
    return 0;
}

/*
给定一个 n×m 的网格，一开始所有格子都是安全的。
接下来有 q 次操作，每次操作有两种类型：
当输入为 0 x 时，表示第 x 行被攻击，该行的所有格子都变为不安全。
当输入为 1 x 时，表示第 x 列被攻击，该列的所有格子都变为不安全。
需要注意：同一行或同一列可能被多次攻击，但只会产生一次影响。
请你计算，在所有操作结束后，网格中仍然安全的格子数量。
*/
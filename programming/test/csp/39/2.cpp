#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,L;
    cin >> n >> L;
    vector<vector<int>> a(n,vector<int>(n));

    vector<string> pattern = {
        "111111111",
        "100100101",
        "100111110",
        "100001100",
        "111111100"
    };

    vector<int> diff(L+1,0);//差分数组,记录从当前位置开始，数值发生了什么变化
    //用一个数组 diff 记录原数组相邻元素之间的变化量。
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin >> a[i][j];
    }

    for(int i=0;i+4<n;i++){
        for(int j=0;j+8<n;j++){
            int minWhite = L;
            int maxBlack = -1;
            for(int x=0;x<5;x++){
                for(int y=0;y<9;y++){
                    int num = a[i+x][y+j];
                    if(pattern[x][y]=='1')
                        minWhite = min(num,minWhite);
                    else
                        maxBlack = max(num,maxBlack);
                }
            }
            int left = maxBlack + 1;    //k要大于黑色的最大值 所以是+1
            int right = minWhite;
            if(right >= left){  //等于就是标记一个
                diff[left]++;
                if(right + 1 < L)
                    diff[right+1]--;//从 right + 1 开始，当前合法区间的覆盖效果结束
            }//表示[left,right] 是合法区间 如果遍历去++ 就会导致时间复杂度极高
        }
    }
    int cur = 0;
    for(int k=0;k<L;k++){
        cur += diff[k];
        if(cur>0)
            cout << k << endl;
    }//这里相当于还原原数组  cur记录的就是当前值
    return 0;
}


/*
白色格：要求 A[i][j] >= k
黑色格：要求 A[i][j] < k

k需要小于等于白色的最小值
大于黑色的最大值
*/
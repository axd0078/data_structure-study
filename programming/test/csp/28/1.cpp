#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double i;
    scanf("%d %lf",&n,&i);
    double ans = 0;
    for(int j=0;j<=n;j++){
        int x;
        scanf("%d",&x);
        ans += pow(1+i,-j)*x;
    }
    printf("%lf\n",ans);
    return 0;
}

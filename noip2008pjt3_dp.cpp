#include <bits/stdc++.h>
using namespace std;
int n,m,f[35][35];
int main(){
    scanf("%d%d",&n,&m);
    f[0][0]=1;
    for(int j=1;j<=m;j++){
        f[0][j]=f[n-1][j-1]+f[1][j-1];
        f[n-1][j]=f[0][j-1]+f[n-2][j-1];
        for(int i=1;i<n-1;i++)
            f[i][j]=f[i-1][j-1]+f[i+1][j-1];
    }
    printf("%d\n",f[0][m]);
    return 0;
}

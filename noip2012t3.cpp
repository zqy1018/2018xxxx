#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
using namespace std;
int n,m,a[105],dp[105][105]={0},p=1000007;
int main(){
    int i,j,k;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<=a[0];i++)
        dp[1][i]=1;
    for(i=2;i<=n;i++)
        for(j=0;j<=m;j++)
            for(k=0;k<=a[i-1];k++)
                if(j-k>=0)dp[i][j]+=dp[i-1][j-k],dp[i][j]%=p;
                else break;
    printf("%d\n",dp[n][m]);
    return 0;
}

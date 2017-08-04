#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define dis(a,b,c,d) score[1+a+(b<<1)+(d<<2)+(c<<2)-c]
#define fep(a,b) for(a=0;a<=cnt[b];a++)
using namespace std;
int dp[41][41][41][41]={0},n,m,cnt[4]={0},score[353];
int main(){
    scanf("%d%d",&n,&m);
    int i,j,u,v,d;
    for(i=1;i<=n;i++)
        scanf("%d",&score[i]);
    for(i=0;i<m;i++)
        scanf("%d",&j),cnt[j-1]++;
    dp[0][0][0][0]=score[1];
    fep(i,0)fep(j,1)fep(u,2)fep(v,3){
        d=dis(i,j,u,v);
        if(i)dp[i][j][u][v]=max(dp[i-1][j][u][v]+d,dp[i][j][u][v]);
        if(j)dp[i][j][u][v]=max(dp[i][j-1][u][v]+d,dp[i][j][u][v]);
        if(u)dp[i][j][u][v]=max(dp[i][j][u-1][v]+d,dp[i][j][u][v]);
        if(v)dp[i][j][u][v]=max(dp[i][j][u][v-1]+d,dp[i][j][u][v]);
    }
    printf("%d\n",dp[cnt[0]][cnt[1]][cnt[2]][cnt[3]]);
    return 0;
}

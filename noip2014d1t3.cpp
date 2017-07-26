#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#define INF 2000000000
using namespace std;
int dp[2][1005][2],n,m,k,up[10005],down[10005],rec[10005][2];
void input(){
    scanf("%d%d%d",&n,&m,&k);
    int i,j;
    for(i=0;i<n;i++)
        scanf("%d%d",&up[i],&down[i]),
        rec[i][0]=-1,rec[i][1]=m+3;
    rec[n][0]=-1,rec[n][1]=m+3;
    for(i=0;i<k;i++)
        scanf("%d",&j),
        scanf("%d%d",&rec[j][0],&rec[j][1]);
}
void solve(){
    int res,ans,i,j,t,u,v,o,l,p,q;
    for(i=0;i<=m;i++)
        dp[0][i][0]=dp[0][i][1]=0;
    for(i=1;i<=n;i++){
        for(o=0,j=1;j<=m;j++){
            dp[i&1][j][0]=dp[i&1][j][1]=INF;
            if(j+down[i-1]<=m)
                p=(j+down[i-1]<rec[i-1][1])&&(j+down[i-1]>rec[i-1][0]),
                q=(j<rec[i][1])&&(j>rec[i][0]),
                u=(p)?dp[1^(i&1)][j+down[i-1]][0]:INF,
                v=(p)?dp[1^(i&1)][j+down[i-1]][1]:INF,
                dp[i&1][j][0]=(q)?min(u,v):INF;
            if(j-up[i-1]>0)
                for(l=(j==m)?0:up[i-1];l<=up[i-1];l++)
                    p=(j-l<rec[i-1][1])&&(j-l>rec[i-1][0]),
                    t=dp[i&1][j-l][1],
                    u=(p)?dp[1^(i&1)][j-l][0]:INF,
                    v=(p)?dp[1^(i&1)][j-l][1]:INF,
                    t=min(min(u,v),t),
                    dp[i&1][j][1]=min(dp[i&1][j][1],t+1);
            if(j<rec[i][1]&&j>rec[i][0]&&(dp[i&1][j][0]<INF||
            dp[i&1][j][1]<INF))o=1;
        }
        if(!o){res=0;break;}
    }
    if(i==n+1)res=1;
    printf("%d\n",res);
    if(res)
        for(ans=INF,j=n,i=1;i<=m;i++)
            ans=min(ans,min(dp[j&1][i][0],dp[j&1][i][1]));
    else
        for(ans=0,j=0;j<i;j++)
            if(rec[j][0]!=-1)ans++;
    printf("%d\n",ans);
}
int main(){
    input();
    solve();
    return 0;
}

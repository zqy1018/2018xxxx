#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int T,k,C[2005][2005],sum[2005][2005]={0},maxn=0,maxm=0,n[10005],m[10005];
void init(){
    int i,j,v;
    for(i=0;i<=maxn;i++)
        C[i][0]=1;
    for(i=1;i<=maxn;i++)
        for(j=1;j<=i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%k;
    for(i=1;i<=maxn;i++)
        for(j=1;j<=maxm;j++){
            if(j<=i&&C[i][j]==0)v=1;else v=0;
            sum[i][j]=sum[i-1][j]+v;
        }
    for(i=1;i<=maxn;i++)
        for(j=1;j<=maxm;j++)
            sum[i][j]+=sum[i][j-1];
}
int main(){
    scanf("%d%d",&T,&k);
    for(int i=1;i<=T;i++)
        scanf("%d%d",&n[i],&m[i]),maxn=max(maxn,n[i]),maxm=max(maxm,m[i]);
    init();
    for(int i=1;i<=T;i++)
        printf("%d\n",sum[n[i]][m[i]]);
    return 0;
}

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cctype>
using namespace std;
typedef long long ll;
int n,m,V,E,INF=1000000000;
int d[305][305];
int p1[2005],p2[2005];
double f[2005][2005][2],p[2005],inf=1e9;
void floyd(){
    for(int k=0;k<V;k++)
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
void init(){
    scanf("%d%d%d%d",&n,&m,&V,&E);
    int i,j,u,v,c;
    for(i=0;i<n;i++)
        scanf("%d",&p1[i]),p1[i]--;
    for(i=0;i<n;i++)
        scanf("%d",&p2[i]),p2[i]--;
    for(i=0;i<n;i++)
        scanf("%lf",&p[i]);
    for(i=0;i<V;i++)
        for(j=0;j<V;j++)
            d[i][j]=(i==j)?0:INF;
    for(i=0;i<E;i++){
        scanf("%d%d%d",&u,&v,&c);
        if(d[u-1][v-1]>c)
            d[u-1][v-1]=d[v-1][u-1]=c;
    }
    floyd();
}
void solve(){
    int i,j,A,B,C,D;
    double choice,ans=inf;
    for(i=0;i<n;i++)
        for(j=0;j<=m;j++)
            f[i][j][0]=f[i][j][1]=inf;
    f[0][0][0]=f[0][1][1]=0;
    for(i=1;i<n;i++){
        A=d[p1[i-1]][p1[i]],
        B=d[p1[i-1]][p2[i]],
        C=d[p2[i-1]][p1[i]],
        D=d[p2[i-1]][p2[i]];
        f[i][0][0]=f[i-1][0][0]+A;
        for(j=1;j<=m;j++){
            choice=min(f[i-1][j][0]+A,
            f[i-1][j][1]+p[i-1]*C+(1-p[i-1])*A);
            f[i][j][0]=min(f[i][j][0],choice);
    
            choice=min(f[i-1][j-1][0]+p[i]*B+
            (1-p[i])*A,
            f[i-1][j-1][1]+p[i-1]*p[i]*D+
            (1-p[i-1])*p[i]*B+
            p[i-1]*(1-p[i])*C+
            (1-p[i-1])*(1-p[i])*A);
            f[i][j][1]=min(f[i][j][1],choice);
        }
    }
    for(i=0;i<=m;i++)
        ans=min(ans,min(f[n-1][i][0],f[n-1][i][1]));
    printf("%.2lf\n",ans);
}
int main(){
    init();
    solve();
    return 0;
}

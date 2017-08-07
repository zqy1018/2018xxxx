#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cctype>
using namespace std;
typedef long long ll;
int n,m,cnt[1005]={0},to[1005][1005],lis[1005];
int vis[1005],d[1005]={0},que[1005],f,r,du[1005]={0};
bool mat[1005][1005]={0};
void init(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        memset(vis,0,sizeof(vis));
        int u,v,k,fi,en;
        scanf("%d",&k);
        for(int j=0;j<k;j++)
            scanf("%d",&lis[j]),vis[lis[j]]=1;
        fi=lis[0],en=lis[k-1];
        //有无人向我连边？ 
        for(int j=fi+1;j<en;j++){
            if(vis[j])continue;
            for(u=0;u<k;u++)
                if(!mat[j][lis[u]])
                    mat[j][lis[u]]=1,
                    to[j][cnt[j]++]=lis[u],
                    du[lis[u]]++;
        }
    }
}
void solve(){
    int i,j,lst,at,ans=0;
    memset(vis,0,sizeof(vis));
    fill(d+1,d+n+1,-1);
    f=r=0;
    for(i=1;i<=n;i++)
        if(!du[i])
            d[i]=0,que[r++]=i;
    while(r-f){
        int h=que[f++],v;
        for(int i=0;i<cnt[h];i++){
            v=to[h][i];
            d[v]=max(d[v],d[h]+1);
            du[v]--;
            if(!du[v])que[r++]=v;
        }
        ans=max(ans,d[h]);
    }
    printf("%d\n",ans+1);
}
int main(){
    init();
    solve();
    return 0;
}

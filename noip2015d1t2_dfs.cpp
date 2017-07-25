#include <cstdio>        
#include <cstdlib>
#include <algorithm>
#define INF 1000000000
using namespace std;
int n,to[200005],vis[200005]={0},ans=INF;
void dfs(int cur,int st){
    if(vis[cur]==-1)return ;
    if(vis[cur]){
        ans=min(ans,st-vis[cur]);
        vis[cur]=-1;
        return ;
    }
    vis[cur]=st;
    dfs(to[cur],st+1),vis[cur]=-1;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&to[i]);
    for(int i=1;i<=n;i++)
        dfs(to[i],1);
    printf("%d\n",ans);
    return 0;    
}   

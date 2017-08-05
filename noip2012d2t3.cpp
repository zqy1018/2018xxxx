#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cctype>
#define INF 10000000000000ll
#define LOG 17
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int read(){
    int f=1,x=0;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return f*x; 
}
P left[50005],city[50005];
int to[100005],nex[100005],at[50005],cnt=0;
int n,m,p[100005],par[50005][20],secfa[50005];
int cost[100005],depth[50005],maxd=0,dis[50005][20];
int tot=0,totc=0;
bool vis[50005];

int query(int u,int t){
    if(depth[u]<=t)return 1;
    for(int i=LOG;i>=0;i--)
        if(par[u][i]&&dis[u][i]<=t)
            t-=dis[u][i],u=par[u][i];
    return u;
}
void dfs2(int cur,int fa){
    if(vis[cur])return ;
    bool flag=1,isleaf=1;
    for(int i=at[cur];i;i=nex[i]){
        if(to[i]==fa)continue ;
        dfs2(to[i],cur),flag&=vis[to[i]];
        isleaf=0;
    }
    if(!isleaf)vis[cur]=flag;
}
bool C(int x){
    tot=totc=0;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=m;i++){
        int goal=query(p[i],x);
        if(goal==1)left[++tot].first=x-depth[p[i]],left[tot].second=p[i];
        else vis[goal]=1;
        //打标记
    }
    dfs2(1,0);
    if(vis[1])return 1;//根节点的子树全部被覆盖了 
    for(int i=at[1];i;i=nex[i])
        if(!vis[to[i]])city[++totc].second=to[i],city[totc].first=cost[i];
    sort(left+1,left+tot+1);
    sort(city+1,city+totc+1);
    int r=1,fr;
	for(int i=1;r<=totc&&i<=tot;i++){
        fr=left[i].second;
        if(left[i].first<city[r].first){
        	vis[secfa[fr]]=1;
		}else{
            vis[city[r].second]=1,r++;
        }
		while(vis[city[r].second]&&r<=totc)r++;
    }
    if(r==totc+1)return 1;
    return 0;
}
void addedge(int _u,int _v,int _c){
    to[++cnt]=_v,cost[cnt]=_c,nex[cnt]=at[_u],at[_u]=cnt;
}
void dfs(int cur,int fa){
    par[cur][0]=fa,maxd=max(maxd,depth[cur]);
    for(int j=1;j<=LOG;j++)
        if(par[cur][j-1])
            par[cur][j]=par[par[cur][j-1]][j-1],
            dis[cur][j]=dis[cur][j-1]+dis[par[cur][j-1]][j-1];
    for(int i=at[cur];i;i=nex[i]){
        if(to[i]==fa)continue ;
        int _v=to[i],_c=cost[i];
        depth[_v]=depth[cur]+_c,
        dis[_v][0]=_c;
        if(cur==1)secfa[_v]=_v;
        else secfa[_v]=secfa[cur]; 
        dfs(_v,cur);
    }
}
void init(){
    n=read();
    int u,v,c; 
    for(int i=1;i<n;i++)
        u=read(),v=read(),c=read(),
        addedge(u,v,c),addedge(v,u,c);
    m=read();
    for(int i=1;i<=m;i++)p[i]=read(); 
    dfs(1,0);
}
void solve(){
    int son=0;
    for(int i=at[1];i;i=nex[i])son++;
    if(son>m){
        printf("-1\n");
        return ;
    }
    int L=0,R=2*maxd,M;
    while(R>L){
        M=(L+R)>>1;
        if(C(M))R=M;
        else L=M+1;
    }
    printf("%d\n",L);
}
int main(){
    init();
    solve();
    return 0;
}

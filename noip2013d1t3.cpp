#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
struct Edge{
    int u,v,cost,nex;
};
Edge edge[110005];
int cmp(const void *a,const void *b){
    int *c=(int*)a,*d=(int*)b;
    return edge[*c].cost-edge[*d].cost;
}
int n,m,q,par[10005],at[10005],cnt=0,_par[10005][15];
int son[10005],bro[10005],depth[10005],que[10005],f,r;
int id[100005],dis[10005][15];
char vis[100005]={0},_vis[10005]={0};
//1.dfs出每个点所在集合并用id表示
//2.求出每一个集合的最小生成树
//3.大力lca，求最短容量 
void addedge(int _u,int _v,int _c){
    edge[cnt].u=_u,
    edge[cnt].v=_v,
    edge[cnt].cost=_c,
    edge[cnt].nex=at[_u],
    at[_u]=cnt++; 
}
void _init(int S){
    int i,j,h,u,v,c;
    f=r=0;
    que[r++]=S,_vis[S]=1;
    depth[S]=1;
    while(r-f){
        h=que[f++];
        for(i=at[h];i!=-1;i=edge[i].nex){
            v=edge[i].v,c=edge[i].cost;
            if(vis[i]&&!_vis[v]){//这条边和这个点都访问过 
                _par[v][0]=h,dis[v][0]=c,
                bro[v]=son[h],son[h]=v,
                depth[v]=depth[h]+1,
                _vis[v]=1,que[r++]=v;
            }
        }
        for(i=1;i<=14;i++)
            if(_par[h][i-1]>=0)
                _par[h][i]=_par[_par[h][i-1]][i-1],
                dis[h][i]=max(dis[h][i-1],dis[_par[h][i-1]][i-1]);
            else break;
    }
}
int query(int u,int v){
    int i,j,d,ans=-999999;
    if(depth[u]<depth[v])
        swap(u,v);
    for(d=depth[u]-depth[v],i=0;(1<<i)<=d;i++);
    for(i--;i>=0&&depth[u]!=depth[v];i--)
        if(depth[u]-(1<<i)>=depth[v])
            ans=max(ans,dis[u][i]),
            u=_par[u][i];
    if(u==v)return -ans;
    for(i=14;i>=0;i--)
        if(_par[u][i]>=0&&_par[u][i]!=_par[v][i])
            ans=max(ans,max(dis[u][i],dis[v][i])),
            u=_par[u][i],v=_par[v][i];
    ans=max(ans,max(dis[u][0],dis[v][0]));
    return -ans;
}
void init(){
    for(int i=1;i<=n;i++)
        par[i]=i;
}
int Find(int x){
    if(par[x]==x)return x;
    return (par[x]=Find(par[x]));
}
void unite(int x,int y){
    par[Find(x)]=Find(y);
}
void kruskal(){
    qsort(id,cnt,sizeof(id[0]),cmp);
    int Cnt=n,cur=0,_u,_v,i;
    while(cur<cnt){
        _u=edge[id[cur]].u,_v=edge[id[cur]].v;
        if(Find(_u)!=Find(_v)){
            unite(_v,_u),Cnt--;
            if(id[cur]&1)
                vis[id[cur]]=vis[id[cur]-1]=1;
            else 
                vis[id[cur]]=vis[id[cur]+1]=1;
        }
        cur++;
    }
    //在这里建树，求出_par
    for(i=1;i<=n;i++)
        if(!_vis[Find(i)])
            _init(par[i]);
}
void read(){
    scanf("%d%d",&n,&m);
    int i,x,y,z;
    memset(at,-1,sizeof(at));
    for(i=0;i<m;i++)
        scanf("%d%d%d",&x,&y,&z),
        addedge(x,y,-z),
        addedge(y,x,-z);
    for(i=0;i<cnt;i++)
        id[i]=i;
}
void solve(){
    init();
    memset(son,-1,sizeof(son));
    memset(bro,-1,sizeof(bro));
    memset(_par,-1,sizeof(_par));
    kruskal();
}
void answer(){
    scanf("%d",&q);
    int u,v,ans;
    while(q--){
        scanf("%d%d",&u,&v);
        if(Find(u)==Find(v))
            printf("%d\n",query(u,v));
        else printf("-1\n");
    }
}
int main(){
    read();
    solve();
    answer();
    return 0;
}

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 300005
using namespace std;
typedef struct{
    int v,cost,_next; 
}Edge; 
Edge edge[MAXN*2];
int n,m,par[MAXN][20]={0},dis[MAXN]={0},cnt=0,at[MAXN];
int son[MAXN]={0},bro[MAXN]={0},depth[MAXN];
int bus[MAXN][4],_dis[MAXN];// 0 路径长 1 _dis 到父亲的路径长 
int dec[MAXN]={0},que[MAXN],f,r,sum[MAXN];
int cmp(const void *a,const void *b){
    return *(int*)b-*(int*)a;//从大到小 
}
void addedge(int _u,int _v,int _cost){
    edge[cnt].v=_v,
    edge[cnt].cost=_cost,
    edge[cnt]._next=at[_u],
    at[_u]=cnt++;
} 
int read(){
    int x=0;char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x; 
}
int bs(int lth){
    int s=0,len=m,md,pos;
    while(len){
        md=s+(len>>1);
        if(lth<bus[md][0])
            s=md+1,len=len-(len>>1)-1;
        else len>>=1;
    }
    return s;
}
void _init(){
    int i,j,h,u,v,c;
    f=r=0;
    que[r++]=1,depth[1]=1;
    while(r-f){
        h=que[f++];
        for(i=at[h];i!=-1;i=edge[i]._next){
            v=edge[i].v;
            if(v==par[h][0])continue;
            que[r++]=v,
            depth[v]=depth[h]+1,
            par[v][0]=h,
            bro[v]=son[h],son[h]=v,
            _dis[v]=edge[i].cost,
            dis[v]=dis[h]+_dis[v];
        }
        for(i=1;i<=19;i++)
            if(par[h][i-1])
                par[h][i]=par[par[h][i-1]][i-1];
            else break;
    }//准备LCA
}
int query(int u,int v){
    int i,j;
    if(depth[u]<depth[v])
        swap(u,v);
    for(i=0;(1<<i)<=depth[u]-depth[v];i++);
    for(i--;i>=0&&depth[u]!=depth[v];i--)
        if(depth[u]-(1<<i)>=depth[v])
            u=par[u][i];
    if(u==v)return u;
    for(i=19;i>=0;i--)
        if(par[u][i]>0&&par[u][i]!=par[v][i])
            u=par[u][i],v=par[v][i];
    return par[u][0];
}
int C(int tot){
    int i,j,h,maxi=0,_max=0;
    for(i=r-1;i>=0;i--){//模拟DFS过程
        h=que[i];
        for(sum[h]=dec[h],j=son[h];j;j=bro[j])
            sum[h]+=sum[j];
        if(sum[h]>maxi)
            maxi=sum[h],_max=_dis[h];
        else if(sum[h]==maxi)
            _max=max(_max,_dis[h]);
    }
    return maxi==tot?_max:0; 
}
void prepare(){
    n=read(),m=read();
    int i,j,u,v,c;
    memset(at,-1,sizeof(at));
    for(i=0;i<n-1;i++)
        u=read(),v=read(),c=read(),
        addedge(u,v,c),
        addedge(v,u,c);
    _init();
    for(i=0;i<m;i++)
        u=read(),v=read(),
        bus[i][1]=u,bus[i][2]=v,
        bus[i][3]=query(u,v),
        bus[i][0]=dis[u]+dis[v]-2*dis[bus[i][3]];//记录运输信息
}
void solve(){
    qsort(bus,m,sizeof(bus[0]),cmp);
    int s=max(0,bus[m-1][0]-1001),t=bus[0][0],md,i,w;
    while(t-s){
        md=(t+s)/2;
        memset(dec,0,sizeof(dec));
        for(i=0;i<m&&bus[i][0]>md;i++)
            dec[bus[i][1]]++,
            dec[bus[i][2]]++,
            dec[bus[i][3]]-=2;//差分操作
        w=C(i);
        if(bus[0][0]-w<=md)t=md;
        else s=md+1;
    }
    printf("%d\n",s);
}
int main(){
    prepare();
    solve();
    return 0;
}

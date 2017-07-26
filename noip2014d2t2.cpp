#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef struct{
    int v,_nex;
}Edge;
Edge edge[400005];
char vis[10005]={0};
int n,m,que[20005],f,r,at[10005],cnt=0,S,T,d[10005];
int at_[10005];
void bfs1(){
    f=r=0;
    que[r++]=T,vis[T]=1;
    int h,i,j,v;
    while(r-f){
        h=que[f++];
        for(i=at[h];i;i=edge[i]._nex){
            v=edge[i].v;
            if(!vis[v])
                vis[v]=1,que[r++]=v;
        }
    }
}
bool judge(int u){
	for(int i=at_[u];i;i=edge[i]._nex)
		if(!vis[edge[i].v])return 0;
	return 1;
}
void bfs2(){
	if(!judge(S))return ;
    d[S]=0,f=r=0;
    que[r++]=S;
    int i,j,h,v,st;
    while(r-f){
        h=que[f++];
        for(i=at_[h];i;i=edge[i]._nex){
            v=edge[i].v;
            if(!judge(v))continue;
            if(d[v]>d[h]+1)
                d[v]=d[h]+1,que[r++]=v;
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    int i,j,u,v;
    for(i=0;i<m;i++)
        scanf("%d%d",&u,&v),
        edge[++cnt].v=u,edge[cnt]._nex=at[v],at[v]=cnt;
    scanf("%d%d",&S,&T);
    fill(d+1,d+n+1,INF);
    bfs1();
    for(i=1;i<=n;i++)
    	for(j=at[i];j;j=edge[j]._nex)
    		edge[++cnt].v=i,edge[cnt]._nex=at_[edge[j].v],at_[edge[j].v]=cnt;
	bfs2();
    if(d[T]==INF)printf("-1\n");
    else printf("%d\n",d[T]);
    return 0;
}

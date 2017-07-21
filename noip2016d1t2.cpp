#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cctype>
#define INF 2000000000
#define MAXN 300005
#define MAXL 21
using namespace std;
typedef long long ll;
int read(){
	int f=1,x=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return f*x; 
}
int n,to[MAXN*2],_next[MAXN*2],at[MAXN]={0},Cnt=0;
//树部分 
int que[MAXN],depth[MAXN],par[MAXN][MAXL]={0},LOG;
//LCA部分 
int at2[MAXN]={0},to2[MAXN],_next2[MAXN],Cnt2=0;
//存T的信息 
int ats[MAXN]={0},tos[MAXN],_nexts[MAXN],Cnts=0;
//自己是LCA时存S的深度 
int att[MAXN]={0},tot[MAXN],_nextt[MAXN],Cntt=0;
//自己是LCA时存T的深度 
int m,ans[MAXN],w[MAXN],c[MAXN]={0};
//ans答案 w出现时间 cS人数 
int down[MAXN],up[MAXN*2]={0};
//up S->LCA down LCA->T（可能有负数） 
void addedge(int _u,int _v){
	to[++Cnt]=_v,_next[Cnt]=at[_u],at[_u]=Cnt;
}
void bfs(){
	int f=0,r=0;
	que[r++]=1,depth[1]=1;
	while(r-f){
		int h=que[f++];
		for(int i=at[h];i;i=_next[i]){
			int _v=to[i];
			if(_v==par[h][0])continue;
			que[r++]=_v,depth[_v]=depth[h]+1,par[_v][0]=h;
		}
		for(int i=1;i<=LOG;i++)
			if(par[h][i-1])par[h][i]=par[par[h][i-1]][i-1];
			else break;
	}
}
int query(int u,int v){
	int i,j,d;
	if(depth[u]<depth[v])
		swap(u,v);
	for(d=depth[u]-depth[v],i=0;(1<<i)<=d;i++);
	for(i--;i>=0&&depth[u]!=depth[v];i--)
		if(depth[u]-(1<<i)>=depth[v])
			u=par[u][i];
	if(u==v)return u;
	for(i=LOG;i>=0;i--)
		if(par[u][i]>0&&par[u][i]!=par[v][i])
			u=par[u][i],v=par[v][i];
	return par[u][0];
}
void dfs(int cur){
	//主要求解过程 
	int up_ans=up[depth[cur]+w[cur]],
	down_ans=down[depth[cur]-w[cur]+MAXN];
	//旧的答案
	up[depth[cur]]+=c[cur];
	for(int i=at2[cur];i;i=_next2[i])
		down[to2[i]+MAXN]++;
	//添加自己的S,T 
	for(int i=at[cur];i;i=_next[i])
		if(to[i]!=par[cur][0])dfs(to[i]);
	//搜索子树
	ans[cur]=up[depth[cur]+w[cur]]+down[depth[cur]-w[cur]+MAXN]
	-up_ans-down_ans;
	//利用DFS性质计算自己的答案 
	for(int i=ats[cur];i;i=_nexts[i]){
		up[tos[i]]--;
		if(tos[i]==depth[cur]+w[cur])ans[cur]--;
		//链状 
	}
	for(int i=att[cur];i;i=_nextt[i])
		down[tot[i]+MAXN]--;
}
void init(){
	n=read(),m=read();
	for(LOG=1;(1<<LOG)<n;LOG++); 
	int u,v;
	for(int i=1;i<n;i++){
		u=read(),v=read();
		addedge(u,v),addedge(v,u);
	}
	bfs();
	for(int i=1;i<=n;i++)w[i]=read();
	for(int i=1;i<=m;i++){
		u=read(),v=read();
		int lca=query(u,v),len=depth[u]+depth[v]-2*depth[lca];
		c[u]++;
		tos[++Cnts]=depth[u],_nexts[Cnts]=ats[lca],ats[lca]=Cnts;
		tot[++Cntt]=depth[v]-len,_nextt[Cntt]=att[lca],att[lca]=Cntt;
		to2[++Cnt2]=depth[v]-len,_next2[Cnt2]=at2[v],at2[v]=Cnt2;
	}
}
void solve(){
	dfs(1);
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
}
int main(){
	init();
	solve();
	return 0;
} 

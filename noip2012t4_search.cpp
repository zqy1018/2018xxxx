#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
int read(){
	int f=1,x=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return f*x; 
}
int to[20005],at[105],nex[20005],cnt=0;
int V,E,K,S,T,mat[105][105],c[105],dis[105][105];
int que[10005],f,r,dist[105],in[105];
int vis[105],ans=1000000000;
void spfa(){
	fill(dist+1,dist+V+1,INF);
	f=r=0,que[r++]=S,in[S]=1,dist[S]=0;
	int h,v;
	while(r>f){
		h=que[f++],in[h]=0;
		for(int i=at[h];i;i=nex[i]){
			v=to[i];
			if(dist[v]>dist[h]+dis[h][v]){
				dist[v]=dist[h]+dis[h][v];
				if(!in[v])
					in[v]=1,que[r++]=v;
			}
		}
	}
}
void dfs(int cur,int d){
	if(cur==S){
		ans=min(ans,d);
		return ;
	}
	if(d+dist[cur]>=ans)return ;
	vis[c[cur]]=1;
	for(int i=at[cur];i;i=nex[i]){
		int v=to[i],flag=0;
		if(vis[c[v]])continue;
		for(int j=1;j<=K;j++)
			if(vis[j]&&mat[c[v]][j]){
				flag=1;
				break;
			}	
		if(flag)continue;
		dfs(v,d+dis[cur][v]);
	}
	vis[c[cur]]=0;
} 
void init(){
	V=read(),K=read(),E=read(),S=read(),T=read();
	for(int i=1;i<=V;i++)c[i]=read();
	for(int i=1;i<=K;i++)
		for(int j=1;j<=K;j++)
			mat[i][j]=read();
	for(int i=1;i<=V;i++)
		for(int j=1;j<=V;j++)
			dis[i][j]=INF;
	for(int i=1;i<=E;i++){
		int u=read(),v=read(),co=read();
		if(dis[u][v]<co)continue;
		dis[u][v]=dis[v][u]=co;
		to[++cnt]=v,nex[cnt]=at[u],at[u]=cnt;
		to[++cnt]=u,nex[cnt]=at[v],at[v]=cnt;
	}
	spfa();
}
void solve(){
	dfs(T,0);
	printf("%d\n",ans==INF?-1:ans);
}
int main(){
	init();
	solve();
	return 0;
}

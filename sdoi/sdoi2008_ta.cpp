#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cctype>
#define INF 2000000000
using namespace std;
typedef long long ll;
int read(){
	int f=1,x=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return f*x; 
}
int n,m,fa[200005]={0},ch[200005][2],rev[200005]={0};
int cmp(int k){
	return ch[fa[k]][1]==k;
}
int isroot(int k){
	return ch[fa[k]][0]!=k&&ch[fa[k]][1]!=k;
}
void Rev(int k){
	swap(ch[k][0],ch[k][1]);
	rev[k]^=1;
}
void maintain(int k){
	
}
void pushdown(int k){ 
	if(k&&rev[k]){
		rev[k]=0;
		if(ch[k][0])Rev(ch[k][0]);
		if(ch[k][1])Rev(ch[k][1]);
	}
}
void pushup(int k){
	if(!k)return ;
	if(!isroot(k))pushup(fa[k]);
	pushdown(k);
} 
void Rotate(int k){
	int Fa=fa[k],Gfa=fa[Fa],d=cmp(k);
	ch[Fa][d]=ch[k][d^1],fa[ch[k][d^1]]=Fa;
	ch[k][d^1]=Fa,fa[Fa]=k;
	fa[k]=Gfa;
	if(!isroot(Fa)){
		if(Fa==ch[Gfa][0])ch[Gfa][0]=k;
		else if(Fa==ch[Gfa][1])ch[Gfa][1]=k;
	}
	maintain(Fa); 
}
void splay(int k){
	pushup(k);
	for(int Fa=fa[k];!isroot(k);Rotate(k),Fa=fa[k])
		if(fa[Fa]&&!isroot(Fa))Rotate(cmp(k)==cmp(Fa)?Fa:k);
	maintain(k);
} 
void access(int k){
	for(int t=0;k;t=k,k=fa[k])splay(k),ch[k][1]=t,maintain(k);
} 
void makeroot(int k){
	access(k),splay(k),Rev(k);
}
int findroot(int k){
	while(fa[k])k=fa[k];return k;
}
void Split(int u,int v){
	makeroot(u),access(v),splay(v);
}
void cut(int u,int v){
	Split(u,v);
	ch[v][0]=fa[u]=0;
	maintain(v);
}
void link(int u,int v){
	makeroot(u),fa[u]=v;
}
void init(){
	n=read(),m=read();
}
void solve(){
	int x,y;
	char ord[11]; 
	while(m--){
		scanf("%s%d%d",ord,&x,&y);
		if(ord[0]=='C')link(x,y); 
		if(ord[0]=='D')cut(x,y);
		if(ord[0]=='Q')printf("%s\n",(findroot(x)==findroot(y))?"Yes":"No");
	}
}
int main(){
	init();
	solve();
	return 0;
}

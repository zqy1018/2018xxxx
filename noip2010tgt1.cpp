#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
int read(){
	int f=1,x=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return f*x; 
}
bool vis[1005];
int w,m,n,que[100005],f=0,r=0;
void init(){
	m=read(),n=read();
}
void solve(){
	int ans=0;
	while(n--){
		w=read();
		if(!vis[w]){
			vis[w]=1,que[r++]=w,ans++;
			if(r-f==m+1)vis[que[f++]]=0;
		}
	}
	printf("%d\n",ans);
}
int main(){
	init();
	solve();
	return 0;
}

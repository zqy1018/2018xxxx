#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int read(){
	int f=1,x=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return f*x; 
}
P p[100005];
int n,ans=0;
void init(){
	n=read();
	for(int i=1;i<=n;i++)p[i].second=read(),p[i].first=read();
	sort(p+1,p+1+n);
}
void solve(){
	int po=n;
	for(int i=1;i<=n;i++){
		while(po>i&&p[i].second>=p[po].second){
			if(p[po].second)
				p[i].second-=p[po].second,ans=max(ans,p[i].first+p[po].first);
			po--;
		}
		if(po==i)break;
		p[po].second-=p[i].second;
	}
	printf("%d\n",ans);
}
int main(){
	init();
	solve();
	return 0;
}

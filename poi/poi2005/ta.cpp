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
int n,m,f[10005][15],ff[15],_next[10006],ans;
char step[10005];
void init(){
	n=read();
	for(int i=0;i<=9999;i++)
		_next[i]=i+1;
	_next[9999]=-1,_next[10000]=0,ans=10000;
}
void solve(){
	int A,B,C,D,t,flag=0;
	for(int T=1;T<=n;T++){
		m=read();
		memset(ff,0,sizeof(ff));
		scanf("%s",step+1);
		for(int i=1;i<=m;i++){
			t=step[i]-'0';
			ff[t]=i;
			for(int j=0;j<=9;j++)
				f[i][j]=ff[j];				
		}
		for(int i=10000;_next[i]>=0;){
			flag=0;
			t=_next[i],D=t%10,t/=10,C=t%10,t/=10;
			B=t%10,t/=10,A=t%10,t/=10;
			if(ff[D]&&f[ff[D]][C]){
				t=f[ff[D]][C];
				if(f[t][B]){
					t=f[t][B];
					if(f[t][A])flag=1;
				}
			}
			if(!flag)_next[i]=_next[_next[i]],ans--;
			else i=_next[i];
		}
	}
	printf("%d\n",ans);
}
int main(){
	init();
	solve();
	return 0;
}

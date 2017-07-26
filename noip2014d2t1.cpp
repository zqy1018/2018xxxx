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
int d,R,n,sum[1000][1000],cnt=0,ans=0;
void init(){
	d=read(),n=read(),R=(d<<1|1);
	for(int i=1;i<=n;i++)
		sum[read()+R][read()+R]=read();
	for(int i=R;i<=128+R+d;i++)
		for(int j=R;j<=128+R+d;j++)
			sum[i][j]+=sum[i][j-1];
	for(int i=R;i<=128+R+d;i++)
		for(int j=R;j<=128+R+d;j++)
			sum[i][j]+=sum[i-1][j];
}
void solve(){
	for(int i=R+d;i<=128+R+d;i++)
		for(int j=R+d;j<=128+R+d;j++){
			int val=sum[i][j]-sum[i-R][j]-sum[i][j-R]+sum[i-R][j-R];
			if(val>ans)ans=val,cnt=1;
			else if(val==ans)cnt++;
		}
	printf("%d %d\n",cnt,ans);
}
int main(){
	init();
	solve();
	return 0;
}

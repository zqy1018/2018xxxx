#include <bits/stdc++.h>
#define INF 2000000000
#define M 10007
using namespace std;
typedef long long ll;
int read(){
	int f=1,x=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return f*x; 
}
int n,m,num[100005],col[100005],ans=0;
int s1[100005][2],s2[100005][2],s3[100005][2],s4[100005][2];
void init(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)num[i]=read()%M;
	for(int i=1;i<=n;i++)col[i]=read();
}
void solve(){
	for(int i=1;i<=n;i++){
		int c=col[i],B=i&1;
		s1[c][B]+=i*num[i],s1[c][B]%=M;
		s2[c][B]+=i,s2[c][B]%=M;
		s3[c][B]+=num[i],s3[c][B]%=M;
		s4[c][B]++;
	}
	for(int i=1;i<=m;i++)
		for(int j=0;j<2;j++)
			ans+=(s4[i][j]-2)*s1[i][j]%M,
			ans+=s2[i][j]*s3[i][j]%M,
			ans%=M;
	printf("%d\n",ans);
}
int main(){
	init();
	solve();
	return 0;
}

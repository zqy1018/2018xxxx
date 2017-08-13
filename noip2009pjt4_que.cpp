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
int n,m,p,coin[2005][1005],sum[1005][1005],cost[2005];
int Deque[1005][1005][2],f[1005],r[1005],maxi[1005];
int dp[1005][1005];
void init(){
	n=read(),m=read(),p=read();
	for(int i=0;i<n;i++)
		for(int j=1;j<=m;j++)
			coin[i][j]=coin[i+n][j]=read();
	for(int i=0;i<n;i++)cost[i]=cost[i+n]=read();
}
void inque(int x,int val,int k){
	while(r[x]>f[x]&&val>Deque[x][r[x]-1][0])r[x]--;
	Deque[x][r[x]][0]=val,Deque[x][r[x]++][1]=k;
}
int outque(int x,int k){
	while(r[x]>f[x]&&k-Deque[x][f[x]][1]>p)f[x]++;
	return Deque[x][f[x]][0];
}
void solve(){
	for(int i=0;i<n;i++)inque(i,-cost[i],0);
	int R=1000*n; //R：当前单调队列的偏移量 
	for(int j=1;j<=m;j++){
		R--;
		sum[n-1][j]=sum[n-2][j-1]+coin[n-1][j];
		sum[0][j]=sum[n-1][j-1]+coin[0][j];
		dp[0][j]=outque(R%n,j)+sum[n-1][j];
		maxi[j]=dp[0][j];
		for(int i=1;i<n;i++){
			sum[i][j]=sum[i-1][j-1]+coin[i][j];
			dp[i][j]=outque((i+R)%n,j)+sum[i-1][j];
			maxi[j]=max(maxi[j],dp[i][j]);
		}
		inque(R%n,maxi[j]-cost[0]-sum[n-1][j],j);
		for(int i=1;i<n;i++)
			inque((i+R)%n,maxi[j]-cost[i]-sum[i-1][j],j);
	}
	//以上把0单独处理了 
	printf("%d\n",maxi[m]);
}
int main(){
	init();
	solve();
	return 0;
}

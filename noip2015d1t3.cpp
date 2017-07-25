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
//剪枝:出牌数递减，（牌大小递增） 
//贪心：5个直接搞 
int n,cnt[20],ans;
int f[7][9][13][24],pat[5];
void dp(){//与顺子无关的dp 
	memset(f,0x3f,sizeof(f));
	f[0][0][0][0]=0;
	int xa=n/4,xb=n/3,xc=n/2;
	for(int i=0;i<=xa;i++)
		for(int j=0;j<=xb;j++)
			for(int k=0;k<=xc;k++)
				for(int l=0;l<=n;l++){
					int &t=f[i][j][k][l];
					if(i){
						t=min(t,f[i-1][j][k][l]+1);
						if(l>=2)t=min(t,f[i-1][j][k][l-2]+1);
						if(k>=2)t=min(t,f[i-1][j][k-2][l]+1);	
					}
					if(j){
						t=min(t,f[i][j-1][k][l]+1);
						if(l)t=min(t,f[i][j-1][k][l-1]+1);
						if(k)t=min(t,f[i][j-1][k-1][l]+1);	
					}
					if(k)t=min(t,f[i][j][k-1][l]+1); 
					if(l)t=min(t,f[i][j][k][l-1]+1);
				}
}
int small_solve(){
	for(int i=0;i<=4;i++)pat[i]=0;
	for(int i=0;i<=13;i++)pat[cnt[i]]++;
	return f[pat[4]][pat[3]][pat[2]][pat[1]];
}
void dfs(int cd,int st){
	if(st+1>=ans&&cd!=0)return ;
	if(cd==0){
		ans=min(ans,st);
		return ;
	}
	int flag=0;
	//只搜索顺子 
	for(int k=1;k<=12;k++){
		if(cnt[k]>=3){
			if(k<=11){
				for(int i=k+1;i<=12&&cnt[i]>=3;i++){
					flag=1;
					for(int j=k;j<=i;j++)cnt[j]-=3;
					dfs(cd-(i-k+1)*3,st+1);
					for(int j=k;j<=i;j++)cnt[j]+=3;
				}
			}	
		}
		if(cnt[k]>=2){
			if(k<=10&&cnt[k+1]>=2){
				for(int i=k+2;i<=12&&cnt[i]>=2;i++){
					flag=1;
					for(int j=k;j<=i;j++)cnt[j]-=2;
					dfs(cd-(i-k+1)*2,st+1);
					for(int j=k;j<=i;j++)cnt[j]+=2;
				}	
			}
		}
		if(cnt[k]){
			if(k<=8&&cnt[k+1]&&cnt[k+2]&&cnt[k+3]){
				for(int i=k+4;i<=12&&cnt[i];i++){
					flag=1;
					for(int j=k;j<=i;j++)cnt[j]--;
					dfs(cd-(i-k+1),st+1);
					for(int j=k;j<=i;j++)cnt[j]++;
				}
			}
		}
	}
	ans=min(ans,st+small_solve());
}
void init(){
	ans=n;
	memset(cnt,0,sizeof(cnt));
	int u;
	for(int i=1;i<=n;i++){
		u=read();
		if(!u)cnt[u]++;
		else if(u<=2)cnt[u+11]++;
		else cnt[u-2]++;
		read();
	}
}
void solve(){
	dfs(n,0);
	printf("%d\n",ans);
}
int main(){
	int T=read();
	n=read();
	dp();
	while(T--){
		init();
		solve();
	}
	return 0;
}

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
int tab[5][5]={//A打B 
	{0,0,1,1,0},
	{1,0,0,1,0},
	{0,1,0,0,1},
	{0,0,1,0,1},
	{1,1,0,0,0}};
int n,na,nb,a[205],b[205],ans1=0,ans2=0;
void init(){
	n=read(),na=read(),nb=read();
	for(int i=0;i<na;i++)a[i]=read();
	for(int i=0;i<nb;i++)b[i]=read();
}
void solve(){
	int ra,rb;
	for(int i=0;i<n;i++)
		ra=i%na,rb=i%nb,
		ans1+=tab[a[ra]][b[rb]],ans2+=tab[b[rb]][a[ra]];
	printf("%d %d\n",ans1,ans2);
}
int main(){
	init();
	solve();
	return 0;
}

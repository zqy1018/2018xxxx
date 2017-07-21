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
int in_or_out[100005],n,m;//in 0,out 1
char job[100005][20];
void init(){
	n=read(),m=read();
	for(int i=0;i<n;i++)
		scanf("%d%s",&in_or_out[i],job[i]);
}
void solve(){
	int opr,s,lst=0;
	while(m--){
		opr=read(),s=read();
		int res=opr^in_or_out[lst];
        if(!res)lst=(lst-s+n)%n;
        else lst=(lst+s)%n;
	}
	printf("%s\n",job[lst]);
}
int main(){
	freopen("a.in","r",stdin);
	init();
	solve();
	return 0;
}

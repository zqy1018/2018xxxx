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
int a,b,c;
void init(){
	a=read(),b=read(),c=read();
}
void solve(){
	printf("%d\n",a/5+b*3/10+c/2);
}
int main(){
	freopen("a.in","r",stdin);
	init();
	solve();
	return 0;
}

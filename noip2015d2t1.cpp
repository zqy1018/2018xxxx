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
int L,n,m,at[50005];
bool C(int x){
    int left=m,lst=0;
    for(int i=2;i<=n+2;i++){
        if(at[i]-lst<x)left--;
        else lst=at[i];
        if(left<0)return 0;
    }
    return 1;
}
void init(){
	L=read(),n=read(),m=read();
	at[1]=0,at[n+2]=L;
	for(int i=2;i<=n+1;i++)
	    at[i]=read();
	sort(at+2,at+n+2);
}
void solve(){
	int l=0,r=L,mid;
	while(r>l){
	    mid=(l+r+1)>>1;
	    if(C(mid))l=mid;
	    else r=mid-1;
	}
	printf("%d\n",l);
}
int main(){
	init();
	solve();
	return 0;
}

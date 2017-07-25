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
int n,m,a[40005],cnt[15005]={0};
int ca[15005],cb[15005],cc[15005],cd[15005];
void init(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)
		a[i]=read(),cnt[a[i]]++;
}
void solve(){
	int hf_max=n/9,len,rp,xa,xb,xc,xd,sum;
	for(int hf=1;hf<=hf_max;hf++){//长度的一半 
		len=hf<<1,sum=0;
		for(xc=4*len+2;xc<=n-hf;xc++){//枚举xc 
			xd=xc+hf,xa=xc-4*len-1,xb=xa+len;
			sum+=cnt[xa]*cnt[xb];
			cc[xc]+=cnt[xd]*sum,cd[xd]+=cnt[xc]*sum;
		}
		sum=0;
		for(xb=n-7*hf-1;xb>=len+1;xb--){//枚举xb 
			xa=xb-len,xd=7*hf+xb+1,xc=xd-hf;
			sum+=cnt[xc]*cnt[xd];
			ca[xa]+=cnt[xb]*sum,cb[xb]+=cnt[xa]*sum; 
		}
	}
	for(int i=1;i<=m;i++)printf("%d %d %d %d\n",ca[a[i]],cb[a[i]],cc[a[i]],cd[a[i]]);
}
int main(){
	init();
	solve();
	return 0;
}

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
int n,m,a[40005],ws[15005];
int pre[2005][15005],dc[2005][15005],dd[2005][15005]; 
int ca[15005],cb[15005],cc[15005],cd[15005];
bool calced[15005];
void calc(int at,int len){
	int *cur=pre[len];
	for(int i=at;i+len<=n;i++)
		cur[i]=cur[i-1]+ws[i]*ws[i+len];
	calced[len]=1;
}
void init(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)a[i]=read(),ws[a[i]]++;
}
void solve(){
	int xb,len,cnt,cnt_c,xs,hf;
	int lenmax=n/9,*tc,*td; 
	for(int i=2;i<=n;i++){
		if(!ws[i])continue;
		cnt=0;
		for(int len=2;len<xb;len+=2){
			int rp=7*(len>>1)+i+1;
			if(rp>n)break;
			if(!ws[i-len])continue;
			xs=ws[i-len]*ws[i],hf=(len>>1);
			dc[hf][rp-hf]+=xs,dc[hf][n-hf+1]-=xs;
			dd[hf][rp]+=xs,dd[hf][n+1]-=xs;
			if(!calced[hf])calc(rp-hf,hf);
			cnt_c=pre[hf][n-hf]-pre[hf][rp-hf-1];
			cnt_c*=xs,cnt+=cnt_c,ca[i-len]+=cnt_c;
		}
		cb[i]+=cnt;
	}
	for(int i=1;i<=lenmax;i++){
		tc=dc[i],td=dd[i];
		for(int j=8*i+2;j<=n-i;j++)
			tc[j]+=tc[j-1],td[j+i]+=td[j+i-1], 
			cc[j]+=tc[j]*ws[j+i],cd[j+i]+=td[j+i]*ws[j];
	}
	for(int i=1;i<=m;i++)
		printf("%d %d %d %d\n",ca[a[i]]/ws[a[i]],cb[a[i]]/ws[a[i]],cc[a[i]],cd[a[i]]);
}
int main(){
	init();
	solve();
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
P p[200005],pp[200005];
int read(){
	int f=1,x=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return f*x; 
}
int n,r,q,w[200005],q1[200005],q2[200005],r1,r2;
//q1胜者 q2败者 
void Merge(){
	int tot=0,lb=1,rb=1;
	while(lb<=r1&&rb<=r2){
		int L=q1[lb],R=q2[rb];
		if(p[L]<p[R])pp[++tot]=p[L],lb++;
		else pp[++tot]=p[R],rb++;
	}
	while(lb<=r1)pp[++tot]=p[q1[lb]],lb++;
	while(rb<=r2)pp[++tot]=p[q2[rb]],rb++;
	memcpy(p+1,pp+1,sizeof(P)*n);
}
void init(){
	n=read()<<1,r=read(),q=read();
	for(int i=1;i<=n;i++)
		p[i].first=-read(),p[i].second=i;
	for(int i=1;i<=n;i++)w[i]=read();
	sort(p+1,p+n+1); 
}
void solve(){
	while(r--){
		r1=r2=0;
		for(int i=1;i<=n;i+=2){
			q1[++r1]=i,q2[++r2]=i+1;
			if(w[p[i].second]<w[p[i+1].second])
				swap(q1[r1],q2[r2]),p[i+1].first--;
			else p[i].first--;
		}
		Merge();
	}
	printf("%d\n",p[q].second);
}
int main(){
	init();
	solve();
	return 0;
}

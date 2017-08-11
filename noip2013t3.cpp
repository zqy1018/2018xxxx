#include <cstdio>
#include <algorithm>
#define INF 2100000000000000ll
using namespace std;
typedef long long ll;
ll d,maxspc=-INF,sum=0,ans,maxi=-INF,mini=INF,p,sc,beg; 
int n;
int main(){
	scanf("%d%lld%lld",&n,&p,&d);
	mini=0,sum=d,maxi=d,maxspc=2*d,sc=maxi%p,ans=maxi%p; 
	beg=d;
	for(int i=2;i<=n;i++){
		mini=min(mini,sum), 
		scanf("%lld",&d),sum+=d, 
		maxi=max(maxi,sum-mini);//sp[i] 
		sc=maxspc%p;
		if(maxi>0){
			maxspc=(maxi+sc)%p;
			if(maxspc<0)ans=max(sc,beg);
			else ans=sc;
		}
	}
	printf("%lld\n",ans);
	return 0;
} 

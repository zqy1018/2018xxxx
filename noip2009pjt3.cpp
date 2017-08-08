#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m1,m2,ans=-1,p[1005],k[1005],a;
int n,cnt=0;
int main(){
    scanf("%d%lld%lld",&n,&m1,&m2);
    ll e=m1;
	for(ll i=2;i*i<=m1&&e>1;i++)
        if(e%i==0){
			p[cnt]=i,k[cnt++]=0;
            while(e%i==0)
				k[cnt-1]++,e/=i;
			k[cnt-1]*=m2;
		}
	if(e>1)p[cnt]=e,k[cnt++]=m2;
    for(int i=0;i<n;i++){
		ll tot=0,p_,k_;
		int flag=0;
        scanf("%lld",&a);
		for(int j=0;j<cnt;j++)
			if(a%p[j]==0){
            	p_=0;
				while(a%p[j]==0)
					p_++,a/=p[j];
            	k_=k[j]/p_;
				if(k[j]%p_)k_++;
				tot=max(tot,k_);
        	}else {
        		flag=1;
        		break;
			}
		if(flag)continue;
        ans=(ans<0)?tot:(ans>tot?tot:ans);
    }
	printf("%lld\n",ans);
	return 0;    
}  

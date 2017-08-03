#include <bits/stdc++.h>   
using namespace std;
typedef long long ll;
ll extgcd(ll a,ll b,ll &x,ll &y){  
    ll d=a;
    if(b){  
        d=extgcd(b,a%b,y,x);  
        y-=(a/b)*x;  
    }else x=1,y=0;  
    return d;  
}
int main(){  
    ll a,m,x,y;
    scanf("%lld%lld",&a,&m);  
    extgcd(a,m,x,y);
    x=(x%m+m)%m;
    printf("%lld\n",x);  
    return 0;  
}  

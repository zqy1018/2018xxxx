#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Pow(ll a,ll b,ll c){
    ll res=1;
    while(b){
        if(b&1)res=(res*a)%c;
        a=(a*a)%c,b>>=1;
    }
    return res;
}
ll n,m,k,x;
int main(){
    scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
    printf("%lld\n",((Pow(10%n,k,n))*m+x)%n);
    return 0;
}

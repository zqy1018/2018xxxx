#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
using namespace std;
typedef long long ll;
ll S,tot,v[200005],ans,sum[200005],cnt[200005];
int w[200005],n,m,ev[200005][2];
void solve(int r){
    int i;
    sum[0]=cnt[0]=0;
    for(i=1;i<=n;i++){
        sum[i]=sum[i-1],
        cnt[i]=cnt[i-1];
        if(w[i-1]>=r)sum[i]+=v[i-1],cnt[i]++;
    }
    for(i=0;i<m;i++)
        tot+=(cnt[ev[i][1]]-cnt[ev[i][0]-1])*
        (sum[ev[i][1]]-sum[ev[i][0]-1]);
}
int main(){
    scanf("%d%d%lld",&n,&m,&S);
    int i,j,lb=0,rb=1000000,md;
    ans=S;
    for(i=0;i<n;i++)
        scanf("%d%lld",&w[i],&v[i]);
    for(i=0;i<m;i++)
        scanf("%d%d",&ev[i][0],&ev[i][1]);
    while(rb-lb){
        md=(rb+lb)/2,tot=0;
        solve(md);
        if(tot==S){ans=0;break;}
        else if(tot>S)ans=min(ans,tot-S),lb=md+1;
        else ans=min(ans,S-tot),rb=md;
    }
    printf("%lld\n",ans);
    return 0;
}

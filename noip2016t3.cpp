#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef struct{
    int t,k,st;
}D;
D _q[100005];
int n,cnt[100005]={0},_cnt=0,q[300005],f,r,cur=0;
int main(){
    scanf("%d",&n);
    int t,m,i,j,l;
    f=r=0;
    for(i=0;i<n;i++){
        scanf("%d%d",&t,&m);
        _q[r].t=t,_q[r++].k=m;
        while(r>f&&_q[f].t<=t-86400){
            for(j=_q[f].st,l=0;l<_q[f].k;l++,j++){
                cnt[q[j]]--;
                if(!cnt[q[j]])_cnt--;
            }
            f++;
        }
        _q[r-1].st=cur;
        for(l=0;l<m;l++,cur++){
            scanf("%d",&q[cur]);
            cnt[q[cur]]++;
            if(cnt[q[cur]]==1)_cnt++;
        }
        printf("%d\n",_cnt);
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int dp[1005][1005][2]={0},m[1005][1005],n,t,p,cost[1005];
int deque[4005][2],f=0,r=0,R;
void in(int o,int at){
    while(r>f&&o>deque[r-1][0])
        r--;
    deque[r][0]=o,deque[r++][1]=at;
}
int out(int at){
    if(deque[f][1]==(at+R-p)%n)
        f++;
    return deque[f][0];
}
int main(){
    scanf("%d%d%d",&n,&t,&p);
    int i,j,m2=0,m3=0,k,l,ans=0,sum;
    R=1000*n;
    for(i=0;i<n;i++)
        for(j=0;j<t;j++)
            scanf("%d",&m[i][j]);
    for(i=0;i<n;i++)
        scanf("%d",&cost[i]);
    for(i=1;i<=t;i++){//[f,r]
        for(j=0;j<n;j++){
            dp[i][j][1]=m2;
            if(!j)dp[i][j][1]+=m[n-1][i-1]-cost[n-1];
            else dp[i][j][1]+=m[j-1][i-1]-cost[j-1];
            for(k=(j-1+n)%n,l=1,sum=0;l<p;l++,k=(k-1+n)%n)
                if(i-l>0)
                    sum+=m[k][i-l],
                    dp[i][j][0]=max(dp[i][j][0],dp[i-l][k][1]+sum);
                else break;              
            m3=max(m3,max(dp[i][j][0],dp[i][j][1]));
        }
        m2=m3,m3=0;
    }
    for(i=0;i<n;i++)
        ans=max(ans,max(dp[t][i][0],dp[t][i][1]));
    printf("%d\n",ans);
    return 0;
} 

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,k,dp[2][205][205][2]={0},ans=0,M=1000000007;
char a[1005]={0},b[205]={0};
int main(){
    scanf("%d%d%d%s%s",&n,&m,&k,&a[1],&b[1]);
    int i,j,o,p,t;
    dp[0][0][0][0]=dp[1][0][0][0]=1;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            for(o=1;o<=k;o++){    
                if(a[i]==b[j])
                    dp[i&1][j][o][1]=((
                    dp[1^(i&1)][j-1][o-1][0]+
                    dp[1^(i&1)][j-1][o][1])%M+
                    dp[1^(i&1)][j-1][o-1][1])%M;
                else dp[i&1][j][o][1]=0;
                dp[i&1][j][o][0]=(
                dp[1^(i&1)][j][o][0]+//
                dp[1^(i&1)][j][o][1])%M;
            }
        }
    }
    printf("%d\n",(dp[n&1][m][k][0]+dp[n&1][m][k][1])%M);
    return 0;
}

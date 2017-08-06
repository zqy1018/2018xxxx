#include <cstdio>
#include <algorithm>
using namespace std;
int dp[105][51][51]={0},m,n,mat[51][51];
int main(){
    int i,j,k;
	scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&mat[i][j]);
    for(k=1;k<m+n-1;k++)
        for(j=0;j<n;j++)
            for(i=0;i<=j;i++){
                if(k-i<0||k-i>=m||k-j<0||k-j>=m)continue;
                dp[k][i][j]=max(dp[k-1][i][j],dp[k][i][j]);
                if(i)dp[k][i][j]=max(dp[k-1][i-1][j],dp[k][i][j]);
                if(j)dp[k][i][j]=max(dp[k-1][i][j-1],dp[k][i][j]);
                if(i&&j)dp[k][i][j]=max(dp[k-1][i-1][j-1],dp[k][i][j]);
                dp[k][i][j]+=mat[k-i][i];
                if(i!=j)dp[k][i][j]+=mat[k-j][j];
            }
    printf("%d\n",dp[m+n-2][n-1][n-1]);
    return 0;
}  

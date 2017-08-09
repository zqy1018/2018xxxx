#include <bits/stdc++.h>
#define M 10007
using namespace std;   
int dp[1005]={0},a,b,k,m,n,ans;    
int Pow(int a,int b){ 
    int res=1;    
    while(b){    
        if(b&1)res=(res*a)%M;    
        a=(a*a)%M,b>>=1;    
    }return res;
}
int main(){
	scanf("%d%d%d%d%d",&a,&b,&k,&n,&m); 
	a%=M,b%=M,dp[0]=1;
    for(int i=1;i<=k;i++)
		for(int j=i;j>=1;j--)
			dp[j]+=dp[j-1],dp[j]%=M;
	//计算组合数 
	ans=(dp[n]*Pow(a,n))%M,
	ans=(ans*Pow(b,m))%M;  
    printf("%d\n",ans);  
    return 0;    
}      

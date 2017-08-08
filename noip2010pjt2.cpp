#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
int n,m,at[105],w[10005],f=0,ans=0; 
int main(){
    scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
		scanf("%d",&at[i]);
    for(int i=m;i<n;i++)
		scanf("%d",&w[i-m]);
    for(;;){
        int mini=INF;
		for(int i=0;i<m;i++)
            if(at[i]>0&&at[i]<mini)mini=at[i];
        if(mini==INF)break;
        ans+=mini;
		for(int i=0;i<m;i++)
            if(at[i]>0){
                at[i]-=mini;
                if(!at[i]){
                    if(f!=n-m)at[i]=w[f++];
					else at[i]=-1;
                }
            }
    }
	printf("%d\n",ans);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int h,maxi,n,ans=0;
int main(){     
    scanf("%d%d",&n,&maxi);
    ans+=maxi;
    for(int i=2;i<=n;i++){
        scanf("%d",&h);
        if(h>maxi)ans+=h-maxi;
        maxi=h;
    }
    printf("%d\n",ans);
    return 0;      
}    

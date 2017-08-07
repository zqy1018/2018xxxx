#include <bits/stdc++.h>
using namespace std;
int n,ans=0,x;
int main(){
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++)
        for(int j=i;j;j/=10)
            ans+=(j%10==x);
    printf("%d\n",ans);
    return 0;
}

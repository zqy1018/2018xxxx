#include <bits/stdc++.h>
using namespace std;
int main(){
    int k,ans=0;
    scanf("%d",&k);
    for(int i=1,j=1;i<=k;i++){
        ans+=j;
        if(j*(j+1)/2==i)j++;
    }
    printf("%d\n",ans);
    return 0;
}

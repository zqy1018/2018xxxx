#include <bits/stdc++.h>
using namespace std;
int l,r,ans=0;
int main(){
    scanf("%d%d",&l,&r);
    for(int i=l;i<=r;i++){
        int t=i;
		while(t)ans+=(t%10==2),t/=10;
    }
	printf("%d\n",ans);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int a[104],n,ans=0;
char vis[20004]={0};
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n);
    n=unique(a,a+n)-a;
    for(int i=0;i<n;i++)vis[a[i]]=1;
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(vis[a[i]+a[j]])ans++,vis[a[i]+a[j]]=0;
    printf("%d\n",ans);
    return 0;
}

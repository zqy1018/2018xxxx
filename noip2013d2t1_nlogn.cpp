#include <bits/stdc++.h>
using namespace std;
pair<int,int> high[100005];
int n,ans=0,l=1;
char destroyed[100005]={0};
int main(){     
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&high[i].first),high[i].second=i;
    sort(high+1,high+1+n);
    int low=high[1].first,last=0,loc;
    destroyed[0]=destroyed[n+1]=1;
    for(int i=1;i<=n;i++){
        ans+=(low-last)*l;
        while(i<=n&&high[i].first==low){
            loc=high[i].second,
            destroyed[loc]=1;
            if(destroyed[loc-1]||destroyed[loc+1]){
                if(destroyed[loc-1]&&destroyed[loc+1])l--;
            }else l++;
            i++;
        }
        last=low,low=high[i--].first;
    }
    printf("%d\n",ans);
    return 0;      
}    

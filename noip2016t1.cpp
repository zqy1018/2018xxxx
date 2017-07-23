#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n,c,v,ans=2000000000;
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<3;i++){
        scanf("%d%d",&v,&c);
        j=(n%v==0)?n/v:(n/v+1);
        j*=c,ans=min(ans,j);
    }
    printf("%d\n",ans);
    return 0;
}

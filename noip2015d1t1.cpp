#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;
int n,ans[50][50]={0};
int main(){
    scanf("%d",&n);
    int i,j,x,y;
    for(i=2,x=0,y=n/2,ans[x][y]=1;i<=n*n;i++){
        if(!x){
            if(y==n-1)x++;
            else x=n-1,y++;
        }else{
            if(y==n-1)y=0,x--;
            else {
                if(!ans[x-1][y+1])
                    x--,y++;
                else x++;
            }
        }
        ans[x][y]=i;
    }
    for(i=0;i<n;i++,printf("\n"))
        for(j=0;j<n;j++,(j<n)?printf(" "):0)
            printf("%d",ans[i][j]);
    return 0;
}

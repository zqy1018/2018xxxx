#include <cstdio>
#include <algorithm>
using namespace std;
int d[100005],n,f1[2],f2[2]; 
int main(){
    scanf("%d",&n);
    int i,j,t,ans=1;
    for(i=0;i<n;i++)
        scanf("%d",&d[i]);
    f1[0]=f2[0]=1,f1[1]=f2[1]=d[0];
    for(i=1;i<n;i++){
        if(d[i]>=f1[1]&&d[i]>=f2[1]){
            if(f1[0]>f2[0])f1[1]=max(f1[1],d[i]);
            else f1[1]=d[i],f1[0]=f2[0]+1;
        }else if(d[i]<f1[1]&&d[i]>f2[1]){
            if(f1[0]>=f2[0])f2[1]=d[i],f2[0]=f1[0]+1;
            else f1[1]=d[i],f1[0]=f2[0]+1;
        }else{
            if(f2[0]>f1[0])f2[1]=min(f2[1],d[i]);
            else f2[1]=d[i],f2[0]=f1[0]+1;
        }
    }
    printf("%d\n",max(f1[0],f2[0]));
    return 0;
}

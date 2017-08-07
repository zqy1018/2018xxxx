#include <bits/stdc++.h>
using namespace std;
int n,m,sum=0,p=20123,at[10005][105][2],access[10005]={0},st;
int main(){
    scanf("%d%d",&n,&m);
    int tmp=0,lf;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            scanf("%d%d",&at[i][j][0],&at[i][j][1]);
            if(at[i][j][0])access[i]++;
        }
    scanf("%d",&st);
    for(int i=0;i<n;i++){
        lf=at[i][st][1];
        sum+=lf,lf%=access[i],tmp=st;
        if(!lf)lf=access[i];
        for(;;){
            if(at[i][tmp][0])lf--;
            if(!lf)break;
            tmp=(tmp+1)%m;
        }
        st=tmp,sum%=p;
    }
    printf("%d\n",sum);
    return 0;
}

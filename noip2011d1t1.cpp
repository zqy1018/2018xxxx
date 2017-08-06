#include <bits/stdc++.h>
int x[10002],y[10002],l[10002],w[10002],n,dx,dy;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d%d%d",&x[i],&y[i],&l[i],&w[i]);
    scanf("%d%d",&dx,&dy);
    int at=-1;
    for(int i=0;i<n;i++)
        if((dx<=x[i]+l[i]&&dx>=x[i])&&(dy<=y[i]+w[i]&&dy>=y[i]))
            at=i+1;
    printf("%d\n",at);
    return 0;
} 

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int mp[105][105],c[105]={0},u[105],V,E,d[105]={0};
int que[105],f=0,r=0,vis[105]={0},mat[105][105]={0};
void topo(){
    int du[105]={0},i,j,o=0;
    for(i=1;i<=V;i++){
        for(j=1;j<=V;j++)
            if(mat[j][i])du[i]++,d[j]++;
        if(!du[i])vis[i]=1,que[r++]=i;
    }
    while(r-f){
        i=que[f++];
        if(du[i])c[i]-=u[i];
        if(c[i]>0){
            for(j=1;j<=V;j++)
                if(mat[i][j]){
                    c[j]+=mp[i][j]*c[i];
                    if(!vis[j])
                        vis[j]=1,que[r++]=j;
                }
        }
    }
    for(i=1;i<=V;i++)
        if(!d[i]&&c[i]>0)
            o=1,printf("%d %d\n",i,c[i]);
    if(!o)printf("NULL\n");
}
int main(){
    scanf("%d%d",&V,&E);
    int i,j,_u,v,_c;
    for(i=1;i<=V;i++)
        scanf("%d%d",&c[i],&u[i]);
    for(i=0;i<E;i++)
        scanf("%d%d%d",&_u,&v,&_c),
        mat[_u][v]=1,
        mp[_u][v]=_c;
    if(V==1&&c[1]>0)
        printf("%d %d\n",1,c[1]);
    else topo();
    return 0;
}

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int parent[20005],riv[20005]={0},m,n,re[100005][3];
int cmp(const void *a,const void *b){
    return *(int*)b-*(int*)a;
}
void init(int k){
    for(int i=1;i<=k;i++)parent[i]=i;
}
int Find(int a){
    if(parent[a]==a)return a;
    return (parent[a]=Find(parent[a]));
}
void joint(int x,int y){
    int a=Find(x),b=Find(y);
    if(a==b)return;
    parent[b]=a;
}
int main(){
    scanf("%d%d",&n,&m);
    init(n);int i,k1,k2,t1,t2;
    for(int i=0;i<m;i++)
        scanf("%d%d%d",&re[i][1],&re[i][2],&re[i][0]);
    qsort(re,m,sizeof(re[0]),cmp);
    for(i=0;i<m;i++){
        t1=re[i][1],t2=re[i][2];
        if(Find(t1)==Find(t2))break;
        if(riv[t2]&&!riv[t1])swap(t1,t2);
        if(!riv[t2]){
            if(!riv[t1])riv[t1]=t2,riv[t2]=t1;
            else riv[t2]=t1,joint(t2,riv[t1]);
        }else
            joint(t2,riv[t1]),joint(t1,riv[t2]);
    }
    if(i==m)printf("0\n");
    else printf("%d\n",re[i][0]);
    return 0;
}

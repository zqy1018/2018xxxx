#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
int q1[100005]={0},q2[7000005],q3[7000005],n,m,q,u,v,t;
int f1=0,f2=0,f3=0,r1=0,r2=0,r3=0;
double xs,tmp;
int main(){
    scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t);
    xs=u,xs/=(double)v;
    int i,j,k,maxi,_max,fi,se,ok=0;
    for(i=0;i<n;i++)
        scanf("%d",&q1[i]);
    sort(q1,q1+n);
    r1=n,reverse(q1,q1+n);
    for(i=0;i<m;i++){
        maxi=_max=0x80000001;
        if(r1>f1)maxi=1,_max=q1[f1];
        if(r2>f2&&_max<q2[f2])maxi=2,_max=q2[f2];
        if(r3>f3&&_max<q3[f3])maxi=3,_max=q3[f3];
        if(maxi==1)f1++;
        if(maxi==2)f2++;
        if(maxi==3)f3++;
        _max+=i*q;
        if((i+1)%t==0){
            if(ok)printf(" ");
            ok=1,printf("%d",_max);
        }
        tmp=_max,tmp*=xs;
        fi=(int)floor(tmp),se=_max-fi;
        q2[r2++]=fi-(i+1)*q,
        q3[r3++]=se-(i+1)*q;
    }
    printf("\n");
    for(ok=i=0;i<m+n;i++){
        maxi=_max=0x80000001;
        if(r1>f1)maxi=1,_max=q1[f1];
        if(r2>f2&&_max<q2[f2])maxi=2,_max=q2[f2];
        if(r3>f3&&_max<q3[f3])maxi=3,_max=q3[f3];
        if(maxi==1)f1++;
        if(maxi==2)f2++;
        if(maxi==3)f3++;
        _max+=m*q;
        if((i+1)%t==0){
            if(ok)printf(" ");
            ok=1,printf("%d",_max);
        }
    }
    printf("\n");
    return 0;
} 

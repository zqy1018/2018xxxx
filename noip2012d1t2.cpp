#include <cstdio>      
#include <algorithm>  
#include <cstring>  
#include <cstdlib>  
using namespace std;
typedef long long ll;
struct P{
    int a,b,t;
};
bool operator<(const P &u,const P &v){
    return (u.t<v.t);
}
P p[1005];
int d1[3]={0},d2[5000]={0},d3[5000],ans[5000]={0},n;
void mul(int s1[],int s2[],int to[]){
    to[0]=s1[0]+s2[0];
    for(int i=1;i<=s1[0];i++){
        int x=0;
        for(int j=1;j<=s2[0];j++)
            x=s1[i]*s2[j]+x+to[i+j-1],to[i+j-1]=x%10000,x/=10000;
        to[i+s2[0]]=x;
    }
    for(;to[0]>1&&to[to[0]]==0;)to[0]--;
}
void div(int s1[],int s2,int to[]){
    to[0]=s1[0];
    int x=0;
    for(int i=s1[0];i>=1;i--)
        to[i]=(x*10000+s1[i])/s2,x=x*10000+s1[i]-to[i]*s2;
    for(;to[0]>1&&to[to[0]]==0;)to[0]--;
}
int smaller(int n1[],int n2[]){//<0 ：小于 
    if(n1[0]!=n2[0])return n1[0]-n2[0];
    else{
        for(int i=n1[0];i>=1;i--)
            if(n1[i]!=n2[i])return n1[i]-n2[i];
        return 0;
    }
}
void output(int s[]){
    printf("%d",s[s[0]]);
    for(int i=s[0]-1;i>=1;i--)
        printf("%04d",s[i]);
    printf("\n");
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
        scanf("%d%d",&p[i].a,&p[i].b),p[i].t=p[i].a*p[i].b;
    sort(p+1,p+1+n);
    d1[0]=d2[0]=d2[1]=1;
    for(int i=0;i<n;i++){
        memset(d3,0,sizeof(d3));
        d1[1]=p[i].a,mul(d1,d2,d3),memcpy(d2,d3,sizeof(d3));
        div(d2,p[i+1].b,d3);
        if(smaller(ans,d3)<0)
            memcpy(ans,d3,sizeof(d3));
    }
    output(ans);
    return 0;
}

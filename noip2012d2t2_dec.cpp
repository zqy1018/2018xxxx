#include <bits/stdc++.h>
#define N 1000005
using namespace std;
typedef long long ll;
int read(){
    int f=1,x=0;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return f*x; 
}
int n,m,d[N],q[N],s[N],e[N];
int oold,nnew;
void update(){
    if(nnew>oold){
        for(int i=oold+1;i<=nnew;i++)
            d[s[i]]-=q[i],d[e[i]+1]+=q[i];
    }else{
        for(int i=oold;i>nnew;i--)
            d[s[i]]+=q[i],d[e[i]+1]-=q[i];
    }
}
bool C(){
    int flag=0,sum=0;
    update();
    for(int i=1;i<=n;i++){
        sum+=d[i];
        if(sum<0){
            flag=1;
            break;
        }
    }
    return flag;
}
void init(){
    n=read(),m=read();
    int lst=read();
    d[1]=lst;
    for(int i=2;i<=n;i++)
        d[i]=read(),d[i]-=lst,lst+=d[i];
    d[n+1]=-lst;
    for(int i=1;i<=m;i++)
        q[i]=read(),s[i]=read(),e[i]=read();
}
void solve(){
    int L=1,R=m;
    oold=0;
    while(R>L){
        nnew=(L+R)>>1;
        if(C())R=nnew;
        else L=nnew+1;
        oold=nnew;
    }
    if(L==m)printf("0\n");
    else printf("-1\n%d\n",L);
}
int main(){
    init();
    solve();
    return 0;
}

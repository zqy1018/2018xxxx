#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#define INF 2000000000
using namespace std;
typedef long long ll;
int seg[2200000],tag[2200000]={0};
int n,size,_a,_b,m,rec[3][1000005],_v;
int read(){
    int x=0;char ch=getchar(); 
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x;
}
void pushdown(int id){
    if(tag[id]&&id<size)
        tag[id<<1]+=tag[id],tag[id<<1|1]+=tag[id],
        seg[id<<1]+=tag[id],seg[id<<1|1]+=tag[id],
        tag[id]=0; 
}
void init(){
    int i;
    for(size=1;size<n;size<<=1);
    for(i=size;i-size<n;i++)seg[i]=read();
    for(;i<(size<<1);i++)seg[i]=INF;
    for(i=size-1;i>=1;i--)
        seg[i]=min(seg[i<<1],seg[i<<1|1]);
}
void minus(int id,int l,int r){
    if(l>_b||r<_a)return ;
    if(_a<=l&&r<=_b){ 
        tag[id]+=_v,seg[id]+=_v;
        return ;
    }
    pushdown(id);
    minus(id<<1,l,(l+r)>>1);
    minus(id<<1|1,(l+r+1)>>1,r);
    seg[id]=min(seg[id<<1],seg[id<<1|1]);
}
int solve(){
    for(int i=0;i<m;i++){
        _v=-rec[0][i],_a=rec[1][i],_b=rec[2][i],
        minus(1,1,size);
        if(seg[1]<0)return i+1;
    }
    return -1;
}
int main(){
    n=read(),m=read();
    init();
    for(int i=0;i<m;i++)
        rec[0][i]=read(),rec[1][i]=read(),rec[2][i]=read();
    int ans=solve();
    if(ans<0)printf("0\n");
    else printf("-1\n%d\n",ans); 
    return 0;
} 

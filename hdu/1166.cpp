#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cctype>
#define INF 2000000000
using namespace std;
typedef long long ll;
int read(){
    int f=1,x=0;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return f*x;
}
int n,seg[400005],siz,_a,_b,_v;
void build_seg(){
    int i;
    for(siz=1;siz<n;siz<<=1);
    for(i=siz;i-siz<n;i++)seg[i]=read();
    for(;i<(siz<<1);i++)seg[i]=0;
    for(i=siz-1;i>=1;i--)seg[i]=seg[i<<1]+seg[i<<1|1];
}
void update(){
    int i=_a+siz-1;
    for(seg[i]+=_v,i>>=1;i;i>>=1)
        seg[i]=seg[i<<1]+seg[i<<1|1];
}
int query(int id,int l,int r){
    if(l>=_a&&r<=_b)return seg[id];
    int mid=(l+r)>>1,ans=0;
    if(_a<=mid)ans+=query(id<<1,l,mid);
    if(_b>=mid+1)ans+=query(id<<1|1,mid+1,r);
    return ans;
}
void init(){
    n=read();
    build_seg();
}
void solve(){
    char ord[10];
    for(;;){
        scanf("%s",ord);
        if(ord[0]=='Q')_a=read(),_b=read(),printf("%d\n",query(1,1,siz));
        if(ord[0]=='A')_a=read(),_v=read(),update();
        if(ord[0]=='S')_a=read(),_v=-read(),update();
        if(ord[0]=='E')break;
    }
}
int main(){
    int T=read();
    for(int i=1;i<=T;i++){
        printf("Case %d:\n",i);
        init();
        solve();
    }
    return 0;
}

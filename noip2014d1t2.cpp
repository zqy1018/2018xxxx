#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm> 
using namespace std;
typedef struct{
    int w,par,son,bro;
}Tree;
Tree tr[200005];
int n,q[200005],f=0,r=0,M=10007,ans=0,ans2=0;
void prepare(){
    int i,h,sum,sum2,mx,mx2,e;
    for(i=0;i<n;i++)
        if(tr[i].par<0){q[r++]=i;break;}
    while(r-f){
        h=q[f++],sum=sum2=mx=mx2=0;
        for(i=tr[h].son;i!=-1;i=tr[i].bro){
            e=tr[i].w,
            sum=(sum+e)%M,
            sum2=(sum2+(e*e)%M)%M;
            if(e>mx)mx2=mx,mx=e;
            else if(e>mx2)mx2=e;
            q[r++]=i;
        }
        ans2=max(ans2,max(mx*mx2,mx*tr[tr[h].par].w)),
        ans=(ans+(tr[tr[h].par].w*sum*2)%M)%M,
        ans=(ans+(sum*sum-sum2)%M+M)%M;
    }
}
int main(){
    scanf("%d",&n);
    int i,u,v;
    for(i=0;i<n;i++)
        tr[i].par=tr[i].son=tr[i].bro=-1;
    for(i=0;i<n-1;i++){
        scanf("%d%d",&u,&v),
        u--,v--;
        if(tr[v].par>=0)swap(u,v);
        tr[v].par=u,tr[v].bro=tr[u].son,tr[u].son=v;
    }
    for(i=0;i<n;i++)
        scanf("%d",&tr[i].w);
    prepare();
    printf("%d %d\n",ans2,ans);
    return 0;
}

//upd:2017.7.26
//以上代码会被某些特殊数据卡住
//以下代码没问题

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm> 
#define M 10007
using namespace std;
int to[400005],nex[400005],at[200005],cnt=0;
int n,ans=0,ans2=0,val[200005];
void dfs(int cur,int fa){
	int sum=0,sum2=0,mx=0,mx2=0,v;
    for(int i=at[cur];i;i=nex[i]){
    	if(to[i]==fa)continue;
    	v=val[to[i]],
        sum=(sum+v)%M,
        sum2=(sum2+(v*v)%M)%M;
        if(v>mx)mx2=mx,mx=v;
        else if(v>mx2)mx2=v;
        dfs(to[i],cur);
	}
    ans2=max(ans2,max(mx*mx2,mx*val[fa])),
    ans=(ans+(val[fa]*sum*2)%M)%M,
    ans=(ans+(sum*sum-sum2)%M+M)%M; 
}
int main(){
    scanf("%d",&n);
    int i,u,v;
    for(i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        to[++cnt]=v,nex[cnt]=at[u],at[u]=cnt;
        to[++cnt]=u,nex[cnt]=at[v],at[v]=cnt;
    }
    for(i=1;i<=n;i++)scanf("%d",&val[i]);
    dfs(1,0);
    printf("%d %d\n",ans2,ans);
    return 0;
}

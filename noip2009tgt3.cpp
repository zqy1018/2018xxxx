#include <cstdio>
#include <cstring>
#include <algorithm> 
#include <cstdlib>
#define K 100005
#define KD 1000005
using namespace std;
int V,E,at[2][K],par[K],cnt[2]={0},tail[2][K];
int dfn[K],low[K],D=0,in[K],stack[K],top=0;
int mini[K],maxi[K],que[5*K],f,r; 
typedef struct{
    int v,_next; 
}Edge; 
Edge edge[2][KD];
void addedge(int _u,int _v,int o){
    edge[o][cnt[o]].v=_v,
    edge[o][cnt[o]]._next=at[o][_u];
    if(at[o][_u]==-1)
        tail[o][_u]=cnt[o];
    at[o][_u]=cnt[o]++;
}
void tarjan_scc(int id){
    dfn[id]=low[id]=++D;
    in[id]=true;
    stack[top++]=id;
    int i=at[0][id],vv,t1,t2,_min,_max;
    while(i!=-1){
        vv=edge[0][i].v;
        if(!dfn[vv])tarjan_scc(vv),low[id]=min(low[id],low[vv]);
        else if(in[vv])low[id]=min(low[id],dfn[vv]);
        i=edge[0][i]._next;
    }
    if(dfn[id]==low[id]){
        t1=t2=-1,i=stack[top-1],_min=101,_max=-1;
        do
            vv=stack[--top],
            in[vv]=false,
            par[vv]=i,
            edge[0][tail[0][vv]]._next=t1,
            t1=at[0][vv],
            edge[1][tail[1][vv]]._next=t2,
            t2=at[1][vv],
            _min=min(_min,mini[vv]),
            _max=max(_max,maxi[vv]);
        while(stack[top]!=id);
        at[0][i]=t1,at[1][i]=t2;
        mini[i]=_min,maxi[i]=_max;
    }
}
void init(){
    scanf("%d%d",&V,&E);
    int i,j,u,v,o,c;
    memset(at,-1,sizeof(at));
    for(i=0;i<V;i++)
        scanf("%d",&c),
        mini[i]=maxi[i]=c;
    for(i=0;i<E;i++){
        scanf("%d%d%d",&u,&v,&o),
        addedge(u-1,v-1,0),
        addedge(v-1,u-1,1);
        if(o==2)
            addedge(v-1,u-1,0),
            addedge(u-1,v-1,1); 
    }
    for(i=0;i<V;i++)
        par[i]=i;
    tarjan_scc(0);
}
void solve(){
    int h,vv,i,o,c,ans=0;
    f=r=0,que[r++]=par[0];
    memset(in,0,sizeof(in));
    while(r-f){
        h=que[f++];
        for(i=at[0][h];i!=-1;i=edge[0][i]._next){
            vv=par[edge[0][i].v];
            if(mini[vv]>mini[h])
                mini[vv]=mini[h],
                in[vv]=1,
                que[r++]=vv;
            else if(!in[vv])
                in[vv]=1,
                que[r++]=vv;
        }
    }
    f=r=0,que[r++]=par[V-1];
    memset(dfn,0,sizeof(dfn));
    while(r-f){
        h=que[f++];
        for(i=at[1][h];i!=-1;i=edge[1][i]._next){
            vv=par[edge[1][i].v];
            if(maxi[vv]<maxi[h])
                maxi[vv]=maxi[h],
                dfn[vv]=1,
                que[r++]=vv;
            else if(!dfn[vv])
                dfn[vv]=1,
                que[r++]=vv;
        }
    }
    for(i=0;i<V;i++)
        if(in[par[i]]&&dfn[par[i]])
            ans=max(ans,maxi[par[i]]-mini[par[i]]);
    printf("%d\n",ans);
}
int main(){
    init();
    solve();
    return 0;
}

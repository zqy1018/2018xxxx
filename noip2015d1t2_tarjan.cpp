#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define addedge(_u,_v) edge[cnt].v=_v,edge[cnt].next=at[_u],at[_u]=cnt,cnt++
using namespace std;
typedef struct {
    int v,next;
}Edge;
Edge edge[200105];
int at[200005],VNum,mini,D=0;
int dfn[200005]={0},low[200005],stack[200005],top=0;
bool in[200005];
void init(){
    int i,cnt=0,a,b,t;
    memset(at,-1,sizeof(at));
    for(i=0;i<VNum;i++)
        scanf("%d",&a),addedge(i,a-1);
}
void tarjan_scc(int id){
    dfn[id]=low[id]=++D;
    in[id]=true;stack[top++]=id;
    int i=at[id],vv;while(i!=-1){vv=edge[i].v;
        if(!dfn[vv])tarjan_scc(vv),low[id]=min(low[id],low[vv]);
        else if(in[vv])low[id]=min(low[id],dfn[vv]);
        i=edge[i].next;
    }
    if(dfn[id]==low[id]){
        i=0;
        do
            in[stack[--top]]=false,i++;
        while(stack[top]!=id);
        if(i!=1)mini=min(mini,i); 
    }
}
int main(){
    scanf("%d",&VNum);
    init();
    mini=VNum;
    for(int i=0;i<VNum;i++)if(!dfn[i])tarjan_scc(i);
    printf("%d\n",mini);
    return 0;
}

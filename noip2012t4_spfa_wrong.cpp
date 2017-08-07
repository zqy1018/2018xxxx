#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#define INF 1000000000
using namespace std;
typedef struct{
    int v,cost,_next; 
}Edge; 
Edge edge[20005];
int cnt=0,at[105],n,k,m,s,t;
int que[10005][105],f,r,c[105],mat[105][105],d[105],in[105]={0};
void addedge(int _u,int _v,int _cost){
    edge[cnt].v=_v,
    edge[cnt].cost=_cost,
    edge[cnt]._next=at[_u],
    at[_u]=cnt++;
}
void spfa_bfs(){
    fill(d+1,d+n+1,INF);
    d[s]=0;
    que[r][0]=s,que[r++][c[s]]=1,in[s]=1;
    int i,_u,_v,_co,j,ok,cul;
    while(r-f){
        _u=que[f++][0],in[_u]=0;
        for(i=at[_u];i!=-1;i=edge[i]._next){
            _v=edge[i].v,_co=edge[i].cost,cul=c[_v];
            for(ok=1,j=1;j<=k;j++)
                if(mat[cul][que[f-1][j]]){
                    ok=0;break;
                }
            if(!ok)continue;
            if(d[_u]+_co<d[_v]){
                d[_v]=d[_u]+_co;
                if(!in[_v]){
                    in[_v]=1,que[r][0]=_v;
                    for(j=1;j<=k;j++)
                        que[r][j]=que[f-1][j];
                    r++;
                }
            }
        }
    }
}
int main(){
    scanf("%d%d%d%d%d",&n,&k,&m,&s,&t);
    int i,j,u,v,_c;
    for(i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(i=1;i<=k;i++)
        for(j=1;j<=k;j++)
            scanf("%d",&mat[i][j]);
    memset(at,-1,sizeof(at));
    for(i=0;i<m;i++)
        scanf("%d%d%d",&u,&v,&_c),
        addedge(u,v,_c),
        addedge(v,u,_c);
    spfa_bfs();
    printf("%d\n",d[t]>=INF-100?-1:d[t]); 
    return 0;
}

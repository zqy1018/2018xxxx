#include <cstdio>
#include <cstdlib>
#define M 100005
using namespace std;
int dis[M],cost[M][2],ans[M],tmp[M],front,t,n,last,head;
bool vis[M];
int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&dis[i]);
    ans[n-1]=dis[n-1]*2;
    for(int i=0;i<n;i++)
        scanf("%d",&tmp[i]),
        cost[i][1]=i,cost[i][0]=tmp[i],
        ans[n-1]+=cost[i][0];
    qsort(cost,n,sizeof(cost[0]),cmp);
    last=n-1,front=n-2,head=0;
    vis[last]=true;
    for(int i=n-2;i>=0;i--){
        ans[i]=ans[i+1];
        while(head<n&&(vis[cost[head][1]]))
			head++;
		//找到最小花费 
        t=(dis[last]-dis[front])*2+tmp[last];//最底下那一段 
        if(t<cost[head][0])
            vis[last]=vis[front]=1,ans[i]-=t,last=front;
        else 
            vis[cost[head][1]]=1,ans[i]-=cost[head][0],head++;
        while(vis[front])front--;
    }
    for(int i=0;i<n;i++)
        printf("%d\n",ans[i]);
    return 0;
}

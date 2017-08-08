#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef struct{
    int id,dis;
}Mis;
Mis mis[200005];
bool operator<(Mis a,Mis b){return a.dis<b.dis;}
int p1[2],p2[2],n,at;//p1 x  p2 y
bool vis[100005]={0};
int ask(){//找第二套应该有的工作半径
    while(vis[mis[at].id]&&at<2*n)
        at++;
    if(at==2*n)return 0;
    else return mis[at].dis;
}
int main(){
    scanf("%d%d%d%d%d",&p1[0],&p2[0],&p1[1],&p2[1],&n);
    int i,j,l1,l2,ans=2000000000;
    for(i=0;i<n;i++)
        scanf("%d%d",&l1,&l2),
        mis[i].dis=(p1[0]-l1)*(p1[0]-l1)+
        (p2[0]-l2)*(p2[0]-l2),
        mis[i+n].dis=-(p1[1]-l1)*(p1[1]-l1)-
        (p2[1]-l2)*(p2[1]-l2),
        mis[i].id=mis[i+n].id=i;
    sort(mis,mis+n),
    sort(mis+n,mis+n+n),
    at=n;
    ans=min(ans,-ask());//全部分配给第二套
    for(i=0;i<n;i++)
        vis[mis[i].id]=1,
        ans=min(ans,(mis[i].dis-ask()));
    printf("%d\n",ans);
    return 0;
}

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
struct Pos{
    int x,y,d;//空格在指定棋子周围的位置 0上 1下 2左 3右 
};
Pos que[1000005];
struct Dis{
    int ddis[32][32];
    Dis(){
        memset(ddis,0x3f,sizeof(ddis));
    }
};
Dis D[32][32][4];
int dis[32][32][5],n,m,q,f,r;
int bdis[32][32];
int ex,ey,sx,sy,tx,ty,dx[]={-1,1,0,0},dy[]={0,0,-1,1};
bool mp[32][32],in[32][32][5];
void bfs(int xx,int yy,Dis *dist){
    f=r=0;
    que[r].x=xx,que[r++].y=yy,dist->ddis[xx][yy]=0;
    int cx,cy,px,py,_dis;
    while(r>f){
        
        cx=que[f].x,cy=que[f++].y;
        _dis=dist->ddis[cx][cy];
        //printf("%d %d\n",cx,cy);
        for(int i=0;i<4;i++){
            px=cx+dx[i],py=cy+dy[i];
            if(!mp[px][py]||dist->ddis[px][py]<=_dis+1)continue;
            dist->ddis[px][py]=_dis+1;
            que[r].x=px,que[r++].y=py;
        }
    } 
}
void bfs1(){
    memset(bdis,-1,sizeof(bdis));
    f=r=0;
    que[r].x=ex,que[r++].y=ey,bdis[ex][ey]=0;
    int cx,cy,px,py;
    while(r>f){
        cx=que[f].x,cy=que[f++].y;
        for(int i=0;i<4;i++){
            px=cx+dx[i],py=cy+dy[i];
            if(!mp[px][py])continue;
            if(px==sx&&py==sy)continue;
            if(bdis[px][py]>=0)continue;
            bdis[px][py]=bdis[cx][cy]+1;
            que[r].x=px,que[r++].y=py;
        }
    } 
    f=r=0;
    for(int i=0;i<4;i++){
        px=sx+dx[i],py=sy+dy[i];
        if(!mp[px][py]||bdis[px][py]<0)continue;
        dis[sx][sy][i]=bdis[px][py],
        que[r].x=sx,que[r].y=sy,que[r++].d=i,
        in[sx][sy][i]=1;
    }
}
inline void update(int cx,int cy,int dd,int _dis){
    if(dis[cx][cy][dd]>_dis){
        dis[cx][cy][dd]=_dis;
        if(!in[cx][cy][dd])
            in[cx][cy][dd]=1,
            que[r].x=cx,que[r].y=cy,que[r++].d=dd;
    }
}
void bfs2(){
    int cx,cy,dd,px,py,_dis;
    Dis *dist;
    while(r>f){
        cx=que[f].x,cy=que[f].y,dd=que[f++].d;
        _dis=dis[cx][cy][dd],dist=&D[cx][cy][dd];
        
        in[cx][cy][dd]=0;
        for(int i=0;i<4;i++){
            if(i==dd)continue;
            update(cx,cy,i,_dis+dist->ddis[cx+dx[i]][cy+dy[i]]);
        }
        if(dd==0){
            update(cx-1,cy,1,_dis+1);
        }else if(dd==1){
            update(cx+1,cy,0,_dis+1);
        }else if(dd==2){
            update(cx,cy-1,3,_dis+1);
        }else {
            update(cx,cy+1,2,_dis+1);
        }
    }
}
void init(){
    n=read(),m=read(),q=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            mp[i][j]=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(mp[i][j]){
                mp[i][j]=0;
                for(int k=0;k<4;k++){
                    int px=i+dx[k],py=j+dy[k];
                    if(!mp[px][py])continue;
                    bfs(px,py,&D[i][j][k]);
                }
                mp[i][j]=1;
            }    
}
void solve(){
    ex=read(),ey=read(),sx=read(),sy=read(),
    tx=read(),ty=read();
    if(sx==tx&&sy==ty){
        printf("0\n");
        return ;
    }
    memset(dis,0x3f,sizeof(dis));
    memset(in,0,sizeof(in));
    bfs1();
    bfs2();
    int ans=0x3f3f3f3f;
    for(int i=0;i<4;i++)
        ans=min(ans,dis[tx][ty][i]);
    if(ans==0x3f3f3f3f)printf("-1\n");
    else printf("%d\n",ans);
}
int main(){
    init();
    while(q--)solve();
    return 0;
}

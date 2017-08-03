#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#define INF 2100000000
using namespace std;
typedef long long ll;
int high[100005][2],_h[100005][2],
lf[100005],rt[100005],n,lg,X,S;
ll dis[100005][4],_dis[100005][18][4];
//dis [0] 小A开距离 [1]小A开到 [2]小B开距离  [3]小B开到
//_dis[i][j]过2^j个回合 [0]小a开距离 [1]小b开距离 [2]开到 [3]总路程 
int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
void init(){
    int i,j,lis[4],m1[2],m2[2],d;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&high[i][0]),
        high[i][1]=i;
    memcpy(_h,high,sizeof(high));
    qsort(_h,n,sizeof(_h[0]),cmp);
    lf[_h[0][1]]=-1;
    for(i=1;i<n;i++)
        lf[_h[i][1]]=_h[i-1][1];
    rt[_h[n-1][1]]=-1;
    for(i=0;i<n-1;i++)
        rt[_h[i][1]]=_h[i+1][1];
    for(i=0;i<n;i++){
        lis[0]=lf[i],lis[1]=rt[i];
        lis[2]=(lf[i]<0)?-1:lf[lis[0]];
        lis[3]=(rt[i]<0)?-1:rt[lis[1]];
        m1[0]=m2[0]=INF;
        m1[1]=m2[1]=-1;
        //m1：最小 m2：第二小 [0]距离 [1]位置
        for(j=0;j<4;j++)
            if(lis[j]>=0){
                d=abs(high[lis[j]][0]-high[i][0]);
                if(d<m1[0]||(d==m1[0]&&high[lis[j]][0]<high[m1[1]][0]))//lis[j]的海拔低
                    m2[0]=m1[0],m2[1]=m1[1],
                    m1[0]=d,m1[1]=lis[j];
                else if(d<m2[0]||(d==m2[0]&&high[lis[j]][0]<high[m2[1]][0]))
                    m2[0]=d,m2[1]=lis[j];
            }
        if(m2[0]>=INF)m2[0]=0;
        if(m1[0]>=INF)m1[0]=0;
        dis[i][0]=m2[0],
        dis[i][1]=m2[1],
        dis[i][2]=m1[0],
        dis[i][3]=m1[1];
        if(rt[i]>=0)lf[rt[i]]=lf[i];
        if(lf[i]>=0)rt[lf[i]]=rt[i];//自我删除
    }
    for(i=1,d=0;i<n;i<<=1,d++);
    lg=d;
    for(i=0;i<n;i++){
        _dis[i][0][0]=dis[i][0];
        if(dis[i][1]>=0)
            _dis[i][0][1]=dis[dis[i][1]][2],
            _dis[i][0][2]=dis[dis[i][1]][3];
        else _dis[i][0][1]=0,_dis[i][0][2]=-1;
        _dis[i][0][3]=_dis[i][0][0]+_dis[i][0][1];
    }
    for(j=1;j<=lg;j++)
        for(i=0;i<n;i++){
            _dis[i][j][0]=_dis[i][j-1][0],
            _dis[i][j][1]=_dis[i][j-1][1];
            if(_dis[i][j-1][2]>=0)//目的地存在 
                _dis[i][j][0]+=_dis[_dis[i][j-1][2]][j-1][0],
                _dis[i][j][1]+=_dis[_dis[i][j-1][2]][j-1][1],
                _dis[i][j][2]=_dis[_dis[i][j-1][2]][j-1][2];
            else _dis[i][j][2]=-1;
            _dis[i][j][3]=_dis[i][j][0]+_dis[i][j][1];
        }
}
void ask(int id,int &a,int &b){
    int i;
    for(i=lg;i>=0;i-- )
        if(_dis[id][i][3]+a+b<=X&&_dis[id][i][2]>=0){
            a+=_dis[id][i][0],
            b+=_dis[id][i][1],
            ask(_dis[id][i][2],a,b);
            break;
        }
    if(i<0)
        for(i=0;i<=lg;i++)
            if(_dis[id][i][0]+a+b<=X){
                a+=_dis[id][i][0];
                break;
            }
}
void solve1(){
    int i,_d[2],d_[2],ans;
    double bi=1e12,t1,t2; 
    scanf("%d",&X);
    for(i=0;i<n;i++){
        d_[0]=d_[1]=0;
        ask(i,d_[0],d_[1]);
        t1=d_[0],t2=d_[1];
        if(!t2)t1=1e11;
        else t1/=t2;
        if(bi>t1||(abs(bi-t1)<0.0000001&&high[i][0]>high[ans][0]))
            bi=t1,_d[0]=d_[0],_d[1]=d_[1],ans=i;
    }
    printf("%d\n",ans+1);        
}
void solve2(){
    int m,i,u,v;
    scanf("%d",&m);
    for(i=0;i<m;i++)
        scanf("%d%d",&S,&X),
        u=0,v=0,
        ask(S-1,u,v),
        printf("%d %d\n",u,v);
}
int main(){
    init();
    solve1();
    solve2();
    return 0;
}

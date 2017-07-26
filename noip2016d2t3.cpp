#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int T,n,m,tag,tab[20][500];
int in[20][1<<19];
double pos[20][2],eps=1e-11;//eps的精度太高会挂（判不出直线），太小也会挂（判不出不同的抛物线）
int jfc(double &a,double &b,int i,int j){
    if(pos[i][0]<pos[j][0])swap(i,j);
    if(fabs(pos[i][0]-pos[j][0])<eps)return -1;//x坐标相同 
    a=(pos[i][1]-(pos[j][1]*pos[i][0]/pos[j][0]))/
    (pos[i][0]*pos[i][0]-pos[i][0]*pos[j][0]);
    if(a>0||fabs(a)<eps)return -1;//a必须<0 
    b=(pos[i][1]-a*pos[i][0]*pos[i][0])/pos[i][0];
    return 0;
}//解方程
void init(){
    int i,j,S,p;
    double _a,_b;
    char vis[50];
    for(i=0;i<n;i++){
        memset(vis,0,sizeof(vis));
        for(j=i+1;j<n;j++){
            if(vis[j])continue;
            if(jfc(_a,_b,i,j)<0)continue;
            S=((1<<i)|(1<<j));
            for(p=j+1;p<n;p++)
                if(fabs(pos[p][1]-_b*pos[p][0]-_a*pos[p][0]*pos[p][0])<eps)
                    S|=(1<<p),vis[p]=1;
            tab[i][++tab[i][0]]=S;
        }
        tab[i][++tab[i][0]]=(1<<i);
    }
}
int dfs(int at,int S){
	if(in[at][S]<0x3f3f3f3f)return in[at][S];
    int st=0x3f3f3f3f,i,j,_S;
    for(i=1;i<=tab[at][0];i++){
        _S=S,_S|=tab[at][i];
        for(j=at+1;j<n;j++)
            if((_S&(1<<j))==0)break;
        st=min(st,1+dfs(j,_S));
    }
    return (in[at][S]=st);
}
int main(){
    scanf("%d",&T);
    int i,j,u,v; 
    while(T--){
        scanf("%d%d",&n,&m);
        memset(tab,0,sizeof(tab));
        memset(in,0x3f,sizeof(in));
        tag=(1<<n);
        for(i=0;i<n;i++)
            scanf("%lf%lf",&pos[i][0],&pos[i][1]);
        init();
        in[n][tag-1]=0;
        printf("%d\n",dfs(0,0));
    }
    return 0;
}

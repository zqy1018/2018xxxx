#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
bool dp[505][505],able[505][505]={0};
int n,m,h[505][505],par[505],res,ans,dx[]={-1,0,0,1},dy[]={0,-1,1,0};
int stack[250005][2],top=0;
void dfs(int x,int y){
    int nx,ny,i;
    stack[top][0]=x,stack[top++][1]=y;
    while(top){
        x=stack[--top][0],y=stack[top][1];
        for(i=0;i<4;i++){
            nx=x+dx[i],ny=y+dy[i];
            if(nx>=0&&ny>=0&&nx<n&&ny<m&&
            h[nx][ny]<h[x][y]&&!dp[nx][ny])
                dp[nx][ny]=1,stack[top][0]=nx,stack[top++][1]=ny;
        }
    }
}
void _solve(){
    int i,j,p,k,rec[505][2],tot=0,l,r;
    for(ans=1,i=j=0;j<m;j++){
        while(i<m&&par[i]==par[j])i++;
        p=par[i-1],k=0;
        while(k<m&&!able[p][k])k++;
        rec[tot][0]=k;
        if(tot&&rec[tot-1][0]==k)tot--;
        while(k<m&&able[p][k])k++;
        rec[tot++][1]=k-1;
        if(k-1<rec[tot-1][0])tot--;
        j=i-1;
    }
    for(l=rec[0][0],r=rec[0][1],i=1;i<tot;i++){
        while(i<tot&&rec[i][0]<=r+1)i++;
        if(r==m-1)break;
        i--,r=rec[i][1],ans++;
    }
}
void solve(){
    int i,j,k;
    for(i=j=0;j<m;j++){
        while(i<m&&par[i]==par[j])i++;
        memset(dp,0,sizeof(dp));
        dp[0][par[i-1]]=1,dfs(0,par[i-1]);
        memcpy(able[par[i-1]],dp[n-1],sizeof(bool)*m);
        j=i-1;
    }
    bool cnt[505]={0};
    for(k=i=0;i<m;i++)
        for(j=0;j<m;j++)
            if(able[par[i]][j]&&!cnt[j])cnt[j]=1,k++;
    res=(k==m)?1:0;
    if(res)_solve();
    else ans=m-k;
    printf("%d\n%d\n",res,ans);
}
int main(){
    scanf("%d%d",&n,&m);
    int i,j,maxi,lst;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&h[i][j]);
    for(i=0;i<m;i++){
        while(i<m-1&&h[0][i+1]>h[0][i])i++;
        for(j=i-1;j>=0&&h[0][j]<h[0][j+1];j--)
            par[j]=i;
        par[i]=i;
        for(j=i+1;j<m&&h[0][j]<h[0][j-1];j++)
            par[j]=i;
        while(i<m-1&&h[0][i+1]<h[0][i])i++;
    }
    solve();
    return 0;
}

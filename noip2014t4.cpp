#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cctype>
using namespace std;
typedef long long ll;
int n,m,r,c,mat[20][20],ans=1000000000;
int cur_r[20],cur_c[20],v_c[20]={0},w[20][20],dp[20][20]={0};
void dfs_c(int at,int cur){
    int fm=cur_c[at-1],val,pos;
    cur+=v_c[fm];
    if(cur>=ans)return;
    if(at==c){
        ans=min(ans,cur);return ;
    }
    for(int i=fm+1;i<=m-c+at;i++){
        cur_c[at]=i;
        
        if(cur>=ans)return ;
        else dfs_c(at+1,cur);
        for(int j=0;j<r;j++){
            pos=cur_r[j];
            val=mat[pos][i]-mat[pos][fm];
            if(val<0)val=-val;
            cur-=val;
        }
    }
}
void solve_(){
    int pos;
    memset(v_c,0,sizeof(v_c));
    memset(w,0,sizeof(w));
    memset(dp,0,sizeof(dp));
    for(int i=0;i<m;i++)
        for(int j=1;j<r;j++)
            v_c[i]+=abs(mat[cur_r[j]][i]-mat[cur_r[j-1]][i]);
    for(int i=0;i<m;i++)
        for(int j=i+1;j<m;j++)
            for(int k=0;k<r;k++)
                pos=cur_r[k],
                w[i][j]+=abs(mat[pos][i]-mat[pos][j]);
    for(int i=0;i<m;i++)
        dp[1][i]=v_c[i];
    for(int i=2;i<=c;i++){
        for(int j=0;j<m;j++){
            pos=1000000000;
            for(int k=0;k<j;k++)
                if(dp[i-1][k]+w[k][j]<pos)
                    pos=dp[i-1][k]+w[k][j];
            dp[i][j]=pos+v_c[j];
        }        
    }
    for(int i=c-1;i<m;i++)
        ans=min(ans,dp[c][i]);
}
void dfs_r(int at){
    int fm=cur_r[at-1],val;
    for(int i=fm+1;i<=n-r+at;i++){
        cur_r[at]=i;
        for(int j=0;j<m;j++){
            val=mat[i][j]-mat[fm][j];
            if(val<0)val=-val;
            v_c[j]+=val;
        }
        if(at==r-1)solve_();
        else dfs_r(at+1);
        for(int j=0;j<m;j++){
            val=mat[i][j]-mat[fm][j];
            if(val<0)val=-val;
            v_c[j]-=val;
        }
    }
}
void init(){
    scanf("%d%d%d%d",&n,&m,&r,&c);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&mat[i][j]);
}
void solve(){
    for(int i=0;i<=n-r;i++){
        cur_r[0]=i;
        dfs_r(1);
    }
    printf("%d\n",ans);
}
int main(){
    init();
    solve();
    return 0;
}

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cctype>
using namespace std;
typedef long long ll;
int n,a[1005],mx[1005],mat[1005][1005]={0},col[1005]={0},ok=1;
int s1[1005],t1=0,s2[1005],t2=0;
void init(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    mx[n]=10000000;
    for(int i=n-1;i>=0;i--)
        mx[i]=min(mx[i+1],a[i]);
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n-1;j++)
            if(a[i]<a[j]&&mx[j+1]<a[i])
                mat[i][j]=mat[j][i]=1;
}
void dfs(int cur,int c){
    if(!col[cur])
        col[cur]=c;
    else{
        if(col[cur]!=c)ok=0;
        return ;
    }
    for(int i=0;i<n;i++)
        if(mat[cur][i])
            dfs(i,3-c);
}
void solve(){
    for(int i=0;i<n&&ok;i++)
        if(!col[i])
            dfs(i,1);
    if(!ok){
        printf("0\n");
        return ;
    }
    int val=0;
    for(int i=0;i<n;i++){
        if(col[i]==1)s1[t1++]=a[i],printf("a ");
        else s2[t2++]=a[i],printf("c ");
        for(;;){
            if(t1&&s1[t1-1]==val+1){
                t1--,printf("b ");
                val++;
            }else if(t2&&s2[t2-1]==val+1){
                t2--,printf("d ");
                val++;
            }else break;
        }
		//输出排序过程
    }
}
int main(){
    init();
    solve();
    return 0;
}

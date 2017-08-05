#include <bits/stdc++.h>
using namespace std;
int maxi=-1,vis[3][11][11]={0},sd[10][10]={0};
int lis[81][2],tot=0;
void get(int at){
    int mini=99,p,x,y,o;
    for(int i=at+1;i<tot;i++){
        x=lis[i][0],y=lis[i][1],o=0;
        for(int j=1;j<=9;j++){
            if(vis[0][x][j]||vis[1][y][j]||vis[2][(x/3)*3+y/3][j])continue;
            else o++;
        }
        if(o<mini)mini=o,p=i;
    }
    x=lis[at+1][0],y=lis[at+1][1];
    lis[at+1][0]=lis[p][0],lis[at+1][1]=lis[p][1];
    lis[p][0]=x,lis[p][1]=y;
}
int calc(){
    int sum=0;
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++){
            if(i==4&&j==4)sum+=sd[i][j]*10;
            else if(i>2&&j>2&&i<6&&j<6)sum+=sd[i][j]*9;
            else if(i>1&&j>1&&i<7&&j<7)sum+=sd[i][j]*8;
            else if(i>0&&j>0&&i<8&&j<8)sum+=sd[i][j]*7;
            else sum+=sd[i][j]*6;
        }
    maxi=max(maxi,sum);
}//计算分数
void dfs(int at){
    int x=lis[at][0],y=lis[at][1];
    for(int i=1;i<=9;i++){
        if(vis[0][x][i]||vis[1][y][i]||vis[2][(x/3)*3+y/3][i])continue;
        vis[0][x][i]=vis[1][y][i]=vis[2][(x/3)*3+y/3][i]=1,sd[x][y]=i;
        if(at<tot-1){
            if(at!=tot-2)get(at);
            dfs(at+1);
        }else calc();
        vis[0][x][i]=vis[1][y][i]=vis[2][(x/3)*3+y/3][i]=0,sd[x][y]=0;
    }
}
//0 行 1 列 2 宫 
int main(){
    int tmp;
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++){
            scanf("%d",&tmp);
            if(tmp){
                sd[i][j]=tmp;
                vis[0][i][tmp]=vis[1][j][tmp]=vis[2][(i/3)*3+j/3][tmp]=1;
            }else lis[tot][0]=i,lis[tot++][1]=j;
        }
    dfs(0);
    printf("%d\n",maxi);
    return 0;  
}  

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
int read(){
	int f=1,x=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return f*x; 
}
char mp[1001][350];
int n,m,mp2[55][55],BOT=1000;
void lie(int x,int y){//画顶上一层 
    mp[x][y]=mp[x][y+4]='+',
    mp[x][y+1]=mp[x][y+2]=mp[x][y+3]='-';
}
void build(int x,int y,int z){
    int dx=BOT,dy=0;
    dx-=(z-1)*3+3+2*(m-x+1);
    dy+=(m-x+1)*2+(y-1)*4;
    lie(dx,dy),lie(dx+2,dy-2),lie(dx+5,dy-2);
    mp[dx+3][dy+4]='+',
    mp[dx+1][dy-1]=mp[dx+1][dy+3]=mp[dx+4][dy+3]='/';
    mp[dx+3][dy-2]=mp[dx+3][dy+2]=
    mp[dx+4][dy-2]=mp[dx+4][dy+2]=
    mp[dx+1][dy+4]=mp[dx+2][dy+4]='|',
    mp[dx+1][dy]=mp[dx+1][dy+1]=mp[dx+1][dy+2]=
    mp[dx+2][dy+3]=mp[dx+3][dy+3]=
    mp[dx+3][dy]=mp[dx+3][dy-1]=mp[dx+3][dy+1]=
    mp[dx+4][dy]=mp[dx+4][dy-1]=mp[dx+4][dy+1]=' ';
}
void output(){
    int s1=0,s2=0,i,j,ok;
    for(i=BOT;i>=0;i--){
        for(j=0,ok=0;j<350;j++)
            if(mp[i][j]!='.')ok=1;
        if(!ok)break;
    }
    s1=i+1;
    for(i=349;i>=0;i--){
        for(j=s1,ok=0;j<=BOT;j++)
            if(mp[j][i]!='.')ok=1;
        if(ok)break;
    }
    s2=i;
    //划定范围 
    for(i=s1;i<=BOT;i++){
        for(j=0;j<=s2;j++)
            printf("%c",mp[i][j]);
        printf("\n");
    }
}
int main(){
    memset(mp,'.',sizeof(mp));
    m=read(),n=read();
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            mp2[i][j]=read();
    for(int i=1;i<=100;i++)
        for(int k=0;k<n;k++)
            for(int j=0;j<m;j++)
                if(mp2[j][k]>=i)build(j+1,k+1,i);
    output();
    return 0;
}

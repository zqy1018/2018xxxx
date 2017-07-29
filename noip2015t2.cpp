#include <bits/stdc++.h>
using namespace std;
int n,m,mat[105][105],dx[]={-1,-1,-1,0,0,1,1,1},
dy[]={-1,0,1,-1,1,-1,0,1};
char s[105];
void get(int x,int y){
	int res=0;
	for(int i=0;i<8;i++)
		res+=(mat[x+dx[i]][y+dy[i]]==-1);
	mat[x][y]=res; 
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
			mat[i][j]-=(s[j]=='*');
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			if(!mat[i][j])get(i,j),printf("%d",mat[i][j]);
			else putchar('*');
		putchar('\n');
	}
	return 0;
} 

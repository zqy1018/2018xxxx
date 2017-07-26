#include <cstdio>      
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int read(){
	int f=1,x=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return f*x; 
}
int p[]={9973,10723,10937,11161,13337};
int n,m,a[5][105]={0},fx[5][20000];
char s[100005];
bool ans[1000005];
int read_(int M){;
	int f=1,x=0;
	if(s[0]=='-')f=-f;
	for(char *t=(s[0]=='-'?s+1:s);*t;t++)x=(x*10+*t-'0')%M;
	return f*x;
}
void init(){
	n=read(),m=read();
	for(int i=0;i<=n;i++){
		scanf("%s",s);
		for(int j=0;j<5;j++)a[j][i]=read_(p[j]);
	}
	for(int i=0;i<5;i++)
		for(int j=1;j<=p[i];j++){
			int res=0;
			for(int k=n;k>=0;k--)
				res=(res*j+a[i][k])%p[i];
			fx[i][j]=res;
		}
}
void solve(){
	int cnt=0,flag;
	for(int i=1;i<=m;i++){
		flag=0;
		for(int j=0;j<5;j++)
			if(fx[j][i%p[j]]){
				flag=1;
				break;
			}
		if(!flag)cnt++,ans[i]=1;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=m;i++)
		if(ans[i])printf("%d\n",i);
}
int main(){
    init();
    solve();
    return 0;  
} 

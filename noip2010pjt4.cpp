#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cctype>
using namespace std;
typedef long long ll;
int n,mat[505][505]={0};
void init(){
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			scanf("%d",&mat[i][j]),
			mat[j][i]=mat[i][j];
}
void solve(){
	int max1=0,max2=0,ans=0;
	for(int i=0;i<n;i++){
		max1=max2=0;
		for(int j=0;j<n;j++){
			if(mat[i][j]>max1)max2=max1,max1=mat[i][j];
			else if(mat[i][j]>max2)max2=mat[i][j];
		}
		ans=max(ans,max2);
	}
	printf("1\n%d\n",ans);
}
int main(){
	init();
	solve();
	return 0;
}

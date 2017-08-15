#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
int n,m,ans=0,vis[100],key[256];
char dna[1005][55];
void init(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n+n;i++)scanf("%s",dna[i]);
	key['A']=0,key['C']=1,key['G']=2,key['T']=3;
}
void solve(){
	int code,tot=0,flag=0;
	for(int i=0;i<m;i++)
		for(int j=i+1;j<m;j++)
			for(int k=j+1;k<m;k++){
				tot++,flag=0;
				for(int t=1;t<=n;t++){
					code=(key[dna[t][i]]<<4)+(key[dna[t][j]]<<2)+key[dna[t][k]];
					vis[code]=tot;
				}
				for(int t=n+1;t<=n+n;t++){
					code=(key[dna[t][i]]<<4)+(key[dna[t][j]]<<2)+key[dna[t][k]];
					if(vis[code]==tot){
						flag=1;break;
					}
				}
				if(!flag)ans++;
			}
	printf("%d\n",ans);
}
int main(){
	init();
	solve();
	return 0;
}

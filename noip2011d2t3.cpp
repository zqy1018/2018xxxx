#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cctype>
#define INF 1000000000
using namespace std;
typedef long long ll;
int read(){
	int f=1,x=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return f*x; 
}
int n,m,K,dis[1005],latest[1005],dec[1005],cost[1005],cnt[1005],cnt2[1005];
int belong[1005],mingap[1005],tail[1005],ans=0;
void build_block(int l,int r){
	int bid=l,curt=latest[l];
	for(int i=l+1;i<=r;i++){
		curt+=dis[i-1];
		if(curt>latest[i])belong[i-1]=bid;
		else{
			belong[i-1]=-1,mingap[i-1]=INF;
			int tmp=curt-dis[i-1];
			for(int j=i-2;j>=bid;j--)
				mingap[j]=min(min(tmp-latest[j+1],dis[j]),mingap[j+1]),
				tmp-=dis[j]; 
			curt=latest[i],tail[bid]=i-1,bid=i;
		}
	}
	if(bid!=r){
		int bef=INF;
		for(int j=r-1;j>=bid;j--)
			mingap[j]=min(bef,min(dis[j],curt-latest[j+1])),
			bef=min(bef,mingap[j]),curt-=dis[j];
		tail[bid]=r;
	}
}
void init(){
	n=read(),m=read(),K=read();
	for(int i=1;i<n;i++)dis[i]=read();
	for(int i=1;i<=m;i++){
		int Ti=read(),Ai=read(),Bi=read();
		latest[Ai]=max(latest[Ai],Ti);
		cost[Ai]+=Ti;
		dec[Ai]++,dec[Bi]--,cnt[Ai]++,cnt2[Bi]++;
	}
	for(int i=2;i<=n+1;i++)dec[i]+=dec[i-1];
	int curt=latest[1];
	ans+=cnt[1]*latest[1]-cost[1];
	for(int i=1;i<n;i++){
		if(latest[i+1]>curt+dis[i]){
			ans+=cnt2[i+1]*dis[i]+(dec[i]-cnt2[i+1])*(latest[i+1]-curt);
			ans+=cnt[i+1]*latest[i+1]-cost[i+1]; 
			curt=latest[i+1];
		}else{
			ans+=dec[i]*dis[i],curt+=dis[i];
			ans+=cnt[i+1]*curt-cost[i+1]; 
		}
	}
	//每一段路上坐车人数 
}
void solve(){
	build_block(1,n);
	for(;K;){
		int maxi=0,maxid=-1,curb=0,bid,sum;
		for(int i=1;i<n;i++){
			bid=belong[i];
			if(bid<0){
				if(dis[i]&&cnt2[i+1]>maxi)maxi=cnt2[i+1],maxid=i;
			}else{
				if(curb!=bid){
					curb=bid,sum=0;
					for(int j=tail[bid]+1;j>=i+1;j--)sum+=cnt2[j];
				}
				if(mingap[i]&&sum>maxi)maxi=sum,maxid=i;
				sum-=cnt2[i+1];
			}
		}
		if(maxid<0)break;
		bid=belong[maxid];
		if(bid<0){
			if(K>dis[maxid])
				ans-=maxi*dis[maxid],K-=dis[maxid],dis[maxid]=0;
			else {
				ans-=maxi*K;
				break;
			}
		}else{
			if(K>mingap[maxid]){
				ans-=maxi*mingap[maxid],K-=mingap[maxid],dis[maxid]-=mingap[maxid];
			}else {
				ans-=maxi*K;
				break;
			}
			build_block(bid,tail[bid]); 
		}
	}
	printf("%d\n",ans);
}
int main(){
	init();
	solve();
	return 0;
}

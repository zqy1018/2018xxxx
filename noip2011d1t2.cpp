#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){
	int f=1,x=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return f*x; 
}
int n,k,p,col[200005],cost[200005];
int at[55],id[200005],nex[200005],cnt=0,tot[55];
void init(){
	n=read(),k=read(),p=read();
	for(int i=1;i<=n;i++){
		col[i]=read(),cost[i]=read();
		id[++cnt]=i,nex[cnt]=at[col[i]],at[col[i]]=cnt,tot[col[i]]++;
	}
	//链式前向星 
}
void solve(){
	int ans=0;
	for(int i=0;i<k;i++){
		if(!at[i])continue ;
		int lf=tot[i],cur=id[at[i]]+1;
		//lf 左端 rt 右端 
		for(int j=at[i];j;j=nex[j]){
			if(id[j]>cur)continue;//优化，该客栈被统计过就跳过 
			int rt=0;//一开始cur右边没被统计过的客栈数是0 
			for(cur=id[j];cur&&cost[cur]>p;cur--)//更新cur 
				if(col[cur]==i)rt++,lf--;//遇到一个客栈在cur右边 
			if(!cur)break;//找不到这样的合法客栈 
			if(col[cur]==i&&!rt)rt=1,lf--;//对应右边无客栈被统计的情况 
			ans+=rt*lf;//计算贡献 
		}
	}
	printf("%d\n",ans);
}
int main(){
	init();
	solve();
    return 0;
}

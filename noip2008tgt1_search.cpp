#include <bits/stdc++.h>
using namespace std;
int cnt[]={6,2,5,5,4,5,6,3,7,6},n,ans=0;
int table[2005];
int get(int a){
	int res=0;
	while(a)res+=cnt[a%10],a/=10;
	return res;
}
int main(){
	scanf("%d",&n),n-=4;
	table[0]=6;
	for(int i=1;i<=2000;i++)
		table[i]=get(i); 
	for(int i=0;i<=1000;i++)
		for(int j=0;j<=1000;j++)
			if(table[i]+table[j]+table[i+j]==n)ans++;
	printf("%d\n",ans);
	return 0;
}

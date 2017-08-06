#include <bits/stdc++.h>
using namespace std;
bool judge(int x){
	if(!x||x==1)return 0;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)return 0;
	return 1;
}
char s[1005];
int cnt[27],len;
int main(){
	scanf("%s",s);
	len=strlen(s);
	for(int i=0;i<len;i++)
		cnt[s[i]-'a']++;
	int maxi=0,mini=1000;
	for(int i=0;i<26;i++){
		if(!cnt[i])continue;
		maxi=max(maxi,cnt[i]),mini=min(mini,cnt[i]);
	}
	if(judge(maxi-mini))
		printf("Lucky Word\n%d\n",maxi-mini);
	else printf("No Answer\n0\n");
	return 0;
}

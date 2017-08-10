#include <bits/stdc++.h>
using namespace std;
char w[20],s[1000005];
int ans1=-1,ans2=0,l1,l2;
bool judge(int t){
	for(int i=0;i<l1;i++)
		if(w[i]!=s[t+i])return 0;
	if(t+l1==l2||s[t+l1]==' ')return 1;
	return 0;
}
int main(){
	scanf("%s",w);
	while(getchar()!='\n');
	fgets(s,1000003,stdin);
	l1=strlen(w),l2=strlen(s);
	for(int i=0;i<l1;i++)if(isupper(w[i]))w[i]+='a'-'A';
	for(int i=0;i<l2;i++)if(isupper(s[i]))s[i]+='a'-'A';
	for(int i=0;i<l2;i++)
		if(s[i]!=' '&&(!i||s[i-1]==' ')&&i+l1-1<l2)
			if(judge(i)){
				if(ans1<0)ans1=i;
				ans2++;
			}
	if(ans1<0)printf("%d\n",ans1);
	else printf("%d %d\n",ans2,ans1);
	return 0;
}

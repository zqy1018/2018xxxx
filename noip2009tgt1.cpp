#include <bits/stdc++.h>
using namespace std;
char f[27],sec[105],ori[105],s[105];
int flag=1,vis[27];
int main(){
	scanf("%s%s%s",sec,ori,s);
	int l1=strlen(sec),l2=strlen(s);
	if(l1<26){
	    flag=0;goto end;
	}//不够26个字母 
	for(int i=0;i<l1;i++){
		if(f[sec[i]-'A']&&ori[i]!=f[sec[i]-'A']){
		    flag=0;goto end;
		}//没对上 
		f[sec[i]-'A']=ori[i],vis[sec[i]-'A']=1; 
	}
	for(int i=0;i<26;i++)
		if(!vis[i]||!f[i]){
		    flag=0;goto end;
		}//禁止没有得对 
	for(int i=0;i<26;i++)vis[f[i]-'A']++;
	for(int i=0;i<26;i++)
		if(vis[i]>2){
			flag=0;goto end;
		}//禁止一对多 
	end:
	if(!flag)printf("Failed\n");
	else {
		for(int i=0;i<l2;i++)
			printf("%c",f[s[i]-'A']);
		printf("\n");
	}
	return 0;
}

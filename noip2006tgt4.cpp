#include <bits/stdc++.h>
#define p 10000
using namespace std;
int c[520][25],ans[56]={0},k,w,k1,k2;
void mul(int s1[],int s2,int to[]){
    to[0]=s1[0];
	int x=0;
    for(int i=1;i<=s1[0];i++)
        x+=s1[i]*s2,to[i]=x%p,x/=p;
    for(;x>0;)to[++to[0]]=x%p,x/=p;
    for(;to[0]>1&&to[to[0]]==0;)to[0]--;
}
void add(int s1[],int s2[]){
    s2[0]=max(s1[0],s2[0]);
	int x=0;
    for(int i=1;i<=s2[0];i++)
        x+=s1[i]+s2[i],s2[i]=x%p,x/=p;
	for(;x!=0;)s2[++s2[0]]=x%p,x/=p;
}
void divide(int s1[],int s2){
    int x=0;
	for(int i=s1[0];i>=1;i--){
        x=x*p+s1[i],s1[i]=x/s2,x%=s2;
    }
	for(;s1[0]>1&&s1[s1[0]]==0;)s1[0]--;
}
void C(int m,int n){
    c[0][0]=c[0][1]=1;
	for(int i=1;i<=m;i++)
        mul(c[i-1],n-i+1,c[i]),divide(c[i],i);
}
int output(int big[]){
	printf("%d",big[big[0]]);
    for(int i=big[0]-1;i>=1;i--)
		printf("%04d",big[i]);
	printf("\n");
}
int main(){
    scanf("%d%d",&k,&w);
	k1=1<<k;
	if(w>k*(k1-1))w=k*(k1-1);
    C(w/k,k1-1);
	for(int i=2;i<=w/k;i++)add(c[i],ans);
    k2=1<<(w%k);
	for(int i=1;i<k2;i++)
		C(w/k,k1-1-i),add(c[w/k],ans);
	output(ans);
	return 0;    
}  

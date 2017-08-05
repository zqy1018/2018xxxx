#include <bits/stdc++.h>
using namespace std;  
int read(){
	int f=1,x=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return f*x; 
}
int prime[5005],tot=0,vis[45001];
int lis[50][2],a0,a1,b0,b1,t,rec[50][2],ans;
int f(int &a,int b){
	int res=0;
	while(a%b==0)a/=b,res++;
	return res;
}
void sieve(){
	for(int i=2;i<=45000;i++){
		if(!vis[i])
			prime[tot++]=i;
		for(int j=0;j<tot;j++){
			if(i*prime[j]>45000)break;
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
}
int main(){
	sieve();
	for(int T=read();T;T--){
        a0=read(),a1=read(),b0=read(),b1=read();
        ans=1,t=1,lis[0][0]=lis[0][1]=1;
		int e=b1;
        for(int i=0;i<tot&&e>1;i++)
			if(e%prime[i]==0)lis[t][0]=prime[i],lis[t++][1]=f(e,prime[i]);
        if(e>1)lis[t][0]=e,lis[t++][1]=1;
		//对b1分解，因为他的质数种类最多 
		
        rec[0][0]=rec[0][1]=1; 
        for(int i=1;i<t;i++){
			int k=0,p=lis[i][0];
            k=f(b0,p),rec[i][0]=rec[i][1]=lis[i][1];
            if(k==lis[i][1])rec[i][0]=0;//kb0==kb1 
            k=f(a1,p),rec[i][0]=max(rec[i][0],k);
			if(k<f(a0,p))
				rec[i][1]=min(rec[i][1],k);//ka1<ka0，注意这里可能无解，所以取Min 
        }
        if(a1!=1)printf("0\n");
		else{
			for(int i=0;i<t;i++)
				if(rec[i][1]<rec[i][0]){
					ans=0;break;
				}else ans*=(rec[i][1]-rec[i][0]+1);
        	printf("%d\n",ans);	
		}
	}
	return 0;  
} 

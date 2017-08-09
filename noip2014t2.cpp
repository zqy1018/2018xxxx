#include <bits/stdc++.h>
using namespace std;
int a,b,lim,fz,fm;
double bi,mini=1e9,cur;
int gcd(int a,int b){
	return (!b)?a:gcd(b,a%b);
}
int main(){
    scanf("%d%d%d",&a,&b,&lim);
	bi=(double)a/b,cur=1e9;
    for(int i=1;i<=lim;i++)
        for(int j=1;j<=lim;j++){
            double t=(double)i/j;
            if(t-bi>0&&t-bi<cur)
            	cur=t-bi,fz=i,fm=j;
        }
	int g=gcd(fz,fm);
	fz/=g,fm/=g;
    printf("%d %d\n",fz,fm);
    return 0;
}

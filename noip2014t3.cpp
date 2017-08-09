#include <bits/stdc++.h>
using namespace std;
int n,x,y,tot=0;
int main(){
    scanf("%d%d%d",&n,&x,&y);
    for(;x!=1&&y!=1&&x!=n&&y!=n;)
        tot+=4*n-4,n-=2,x--,y--;
    if(x==1)tot+=y;
	else{
		tot+=n-1;
		if(y==n)tot+=x;
		else{
			tot+=n-1;
			if(x==n)tot+=(n-y+1);
			else{
				tot+=n-1;
				if(y==1)tot+=(n-x+1);
			} 
		} 
	} 
    printf("%d\n",tot);
    return 0;
}

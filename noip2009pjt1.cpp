#include <bits/stdc++.h>
using namespace std;
int n,xs;
int main(){
    scanf("%d",&n);
    for(int i=n;i>=0;i--){
        scanf("%d",&xs);
        if(xs!=0){
            if(i==n){
                if(abs(xs)==1){
                    if(xs==-1)putchar('-');
                }else printf("%d",xs);
            }else if(i==1){
                if(xs==1)printf("+x");
                else if(xs==-1)printf("-x");
                else printf("%+dx",xs);
				continue;
            }else if(i==0){
                printf("%+d",xs);
				break;
            }else {
                if(xs==1)printf("+");
                else if(xs==-1)printf("-");
                else printf("%+d",xs);
            }
            printf("x^%d",i);
        }
    }
	printf("\n"); 
    return 0;
}

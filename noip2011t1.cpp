#include <bits/stdc++.h>
using namespace std;
char num[15];
int main(){
    scanf("%s",num);
    int f=(num[0]=='-'),len=strlen(num),cur=0;
    reverse(num,num+len);
    while(num[cur]=='0')cur++;
    if(f)putchar('-');
    if(!num[cur]||num[cur]=='-')printf("0\n");
    else{
    	while(isdigit(num[cur]))putchar(num[cur]),cur++;
	}
    return 0;
}

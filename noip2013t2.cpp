#include <bits/stdc++.h>
using namespace std;
char k[1200005]={0};
int len,st[2][100005]={0},top[2]={0},pro[255];
void push(int a,int to){
	st[to][top[to]++]=a;
}
int pop(int to){
	top[to]--;
	return st[to][top[to]];
}
void opr(){
    int a1,a2,p;
	a2=pop(1),a1=pop(1),p=pop(0);
    if(p=='+')push((a1+a2)%10000,1);
    if(p=='*')push((a1%10000)*(a2%10000)%10000,1);
}
int main(){
    fgets(&k[1],1200000,stdin);
    k[0]='(',len=strlen(k);
	while(isspace(k[len-1]))
		k[--len]='\0';
    k[len++]=')';
    pro['+']=pro['-']=1;
    pro['*']=pro['/']=2;
    int sum=-1;
    for(int i=0;i<len;i++){
        if(isdigit(k[i])){
            if(sum==-1)sum=k[i]-'0';
			else sum=sum*10+k[i]-'0';
        }else{
            if(sum>-1)
				push(sum,1),sum=-1;
            if(k[i]=='(')
				push('(',0);
            else if(k[i]==')'){
                while(st[0][top[0]-1]!='(')
					opr();
                pop(0);
            }else{
                while(st[0][top[0]-1]!='('&&pro[st[0][top[0]-1]]>=pro[k[i]])
					opr();
                push(k[i],0);
            }
        }
    }
	printf("%d\n",pop(1)%10000);
	return 0;    
}   

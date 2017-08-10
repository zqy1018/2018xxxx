#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
using namespace std;
int s1[100005][2]={0},s2[100005]={0},t1=0,t2=0,pro[300],lim,M=10007;
char _exp[100005];
void opr(){
    int a1,a2,b1,b2,o;
    a1=s1[--t1][0],a2=s1[t1][1],
    b1=s1[--t1][0],b2=s1[t1][1],
    o=s2[--t2];
    if(o=='+')
        s1[t1][0]=(a1*b1)%M,
        s1[t1++][1]=(a1*b2+a2*b1+a2*b2)%M;
    if(o=='*'){
        s1[t1][1]=(a2*b2)%M,
        s1[t1++][0]=(a1*b1+a1*b2+a2*b1)%M;
    }
}
void calc(){
    int i,j;
    for(i=0;i<lim;i++){
        if(_exp[i]=='(')
            s2[t2++]='(';
        else if(_exp[i]==')'){
            while(s2[t2-1]!='(')
                opr();
            t2--;
        }else{
            if(_exp[i-1]!=')')
                s1[t1][0]=1,
                s1[t1++][1]=1;
            while(t2&&s2[t2-1]!='('&&
            pro[s2[t2-1]]>=pro[_exp[i]])
                opr();
            s2[t2++]=_exp[i];
            if(_exp[i+1]==')')
                s1[t1][0]=1,
                s1[t1++][1]=1;
        }
    }
}
void init(){
    pro['+']=1,pro['*']=2;
    scanf("%d%s",&lim,&_exp[1]);
    lim++;
    _exp[0]='(';
    _exp[lim++]=')';
}
void solve(){
    calc();
    printf("%d\n",s1[0][0]);
}
int main(){
    init();
    solve();
    return 0;
}

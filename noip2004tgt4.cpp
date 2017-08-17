#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
int n,to[30],plus[30]={0},com=0,used[30]={0},ans[30];
char a[30],b[30],c[30];//a 上 b 中 c 下
bool build(int d){
    if(com)return true;
    if(!d){if(plus[d])return false;
    com=1;memcpy(ans,to,sizeof(to));return true;}
    int _a,_b,_c,i,j,k;
    for(_a=1;_a<d;_a++){
        i=to[a[_a]-'A'],j=to[b[_a]-'A'],k=to[c[_a]-'A'];
        if(i>=0&&j>=0&&k>=0&&(i+j)%n!=k&&(i+j+1)%n!=k)return false;
    }
    _a=a[d]-'A',_b=b[d]-'A',_c=c[d]-'A';
    i=to[_a],j=to[_b],k=to[_c];
    if(i<0&&j>=0)swap(i,j),swap(a[d],b[d]),swap(_a,_b);
    //k jinwei
    //used to plus
    if(i>=0){
        if(j>=0){
            if(k>=0){
                if((i+j+plus[d])%n==k){
                    if(i+j+plus[d]>=n)plus[d-1]++;
                    build(d-1);
                    if(plus[d-1])plus[d-1]--;
                }else return false;
            }else{
                k=(i+j+plus[d])%n;
                if(used[k])return false;
                if(i+j+plus[d]>=n)plus[d-1]++;
                used[k]=1,to[_c]=k;
                build(d-1);
                to[_c]=-1,used[k]=0;
                if(plus[d-1])plus[d-1]--;
            }
        }else{
            if(k>=0){
                j=k-plus[d]-i;
                if(j<0)j+=n;
                if(used[j])return false;
                if(i+j+plus[d]>=n)plus[d-1]++;
                used[j]=1,to[_b]=j;
                build(d-1);
                to[_b]=-1,used[j]=0;
                if(plus[d-1])plus[d-1]--;
            }else{
                for(j=0;j<n;j++)
                    if(!used[j]){
                        k=(i+j+plus[d])%n;
                        if(!used[k]&&((_c==_b&&k==j)||(_c!=_b&&k!=j))){
                            if(i+j+plus[d]>=n)plus[d-1]++;
                            used[j]=used[k]=1,to[_c]=k,to[_b]=j;
                            build(d-1);
                            used[k]=used[j]=0,to[_c]=to[_b]=-1;
                            if(plus[d-1])plus[d-1]--;
                        }
                    }
            }
        }
    }else if(k>=0){
        for(i=0;i<n;i++)
            if(!used[i]){
                j=(k-plus[d]-i);
                if(j<0)j+=n;
                if(!used[j]&&((_a==_b&&i==j)||(_a!=_b&&i!=j))){
                    if(i+j+plus[d]>=n)plus[d-1]++;
                    used[i]=used[j]=1,to[_a]=i,to[_b]=j;
                    build(d-1);
                    used[i]=used[j]=0,to[_a]=to[_b]=-1;
                    if(plus[d-1])plus[d-1]--;
                }
            }
    }else{
        for(i=0;i<n;i++)
            for(j=0;j<n;j++){
                if((!used[i])&&(!used[j])&&((_a==_b&&i==j)||(_a!=_b&&i!=j))){
                    k=(i+j+plus[d])%n;
                    if(!used[k]&&((_c==_b&&k==j)||(_c!=_b&&k!=j))&&((_c==_a&&k==i)||(_c!=_a&&k!=i))){
                        if(i+j+plus[d]>=n)plus[d-1]++;
                        used[i]=used[j]=used[k]=1;
                        to[_a]=i,to[_b]=j,to[_c]=k;

                        build(d-1);
                        used[i]=used[j]=used[k]=0;
                        to[_a]=to[_b]=to[_c]=-1;
                        if(plus[d-1])plus[d-1]--;
                    }
                }
            }
    }
}
int main(){
    scanf("%d%s%s%s",&n,&a[1],&b[1],&c[1]);
    memset(to,-1,sizeof(to));
    build(n);
    for(int i=0;i<n;i++)
        printf("%d ",ans[i]);
    return 0;
}
/*
暴搜（DFS）
    首先对于这么一个加法算式，我们要考虑进位。
    由于最低位不用进位，所以从最低位开始。

    设到第d位时上面的字母为a，中间的为b，下面的为c，
    设f（n）表示n所代表的数字（初始为-1），
    plus[d]表示d位上要不要进位。
    用used表示一个数字是否使用过。
    我们有公式(f(a)+f(b)+plus[d]) %n（n为进制数）=f(c)。
    然后分类讨论：

        1.f(a)=-1,f(b)=-1,f(c)=-1.
            枚举f(a)、f(b)，可以算出来f(c)。
            枚举时要注意f(a)，f(b)与f(c)是否用过。
        2.f(a)>=0,f(b)>=0,f(c)>=0.
            判断(f(a)+f(b)+plus[d])%n是否为f(c)，不是的话回溯。
            判断完后再确定是否进位。
        3.f(a)>=0,f(b)>=0,f(c)=-1
            算出f(c)，之后同1.
        4.f(a)>=0,f(b)=-1,f(c)>=0
            算出f(b)，小心f(b)可能小于零，要加n。
            之后和1差不多。
        5.f(a)>=0,f(b)=-1,f(c)=-1
            枚举f(b)，然后同上。
        6.f(a)=-1,f(b)>=0,f(c)>=0
            同4.
        7.只有f(c)>=0
            枚举f(a)，然后同上。

    确定完了第d位，那么第d-1位的进位也确定了，直接递归下去。
    d=0时判断f(a)+f(b)+plus[d]是否大于等于n，若是则回溯。
        因为最高位不可能再进位。

    调试时如果挂了，那么有可能掉进了这么一个坑：
        当i=j时,f(i)可以与f(j)相等，反之则不能。
    程序就这样写好了，能拿90.

    可行性剪枝：当搜到第d位时，检查第1到d-1位。
    若在第i（1<=i<d）位时，上中下均已知，i上面的数字加中间的数字
    无论是否算入进位都不等于下面的数字
        （即(f(a_i)+f(b_i))%n != f(c_i) && (f(a_i)+f(b_i)+1)%n != f(c_i) ）
    那么直接回溯。
    这样就过了。
    细节搞搞就是
*/

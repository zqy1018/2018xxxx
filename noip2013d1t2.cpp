#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
//第一行-->名次-->下标
//第二行-->名次-->下标 沿用以上
int a[100005],b[100005],to[100005],n,t[100005],t1[100005];
long long ans=0;
void Merge(int s,int h,int e){
    //printf("%d %d %d\n",s,h,e);
    int lp=s,rp=h,pos=s;
    while(lp<h&&rp<=e)
        if(t1[lp]<=t1[rp])
            t[pos++]=t1[lp++];
        else 
            ans+=h-lp,
            t[pos++]=t1[rp++];
    while(lp<h)t[pos++]=t1[lp++];
    while(rp<=e)t[pos++]=t1[rp++];
    memcpy(t1+s,t+s,sizeof(int)*(e-s+1));
}
void MSort(int l,int r){
    if(l==r)t[l]=t1[l];
    else{
        int m=(l+r)/2;
        MSort(l,m),
        MSort(m+1,r),
        Merge(l,m+1,r);
    }
}
int main(){
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]),
        t[i]=a[i];
    for(i=0;i<n;i++)
        scanf("%d",&b[i]),
        t1[i]=b[i];
    sort(a,a+n),
    sort(b,b+n);
    memset(to,-1,sizeof(to));
    for(i=0;i<n;i++){
        j=lower_bound(a,a+n,t[i])-a;
        while(to[j]>=0)j++;
        to[j]=i;
    }
    for(i=0;i<n;i++)
        j=lower_bound(b,b+n,t1[i])-b,
        t1[i]=to[j];
    MSort(0,n-1);
    printf("%lld\n",ans%99999997); 
    return 0;
}

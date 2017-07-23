#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
char a[10],b[10];
int rs[]={1,3,5,7,8,10,12},ans=0,x1,x2,y1,y2,m1,m2,d1,d2;
bool cmp(int ye,int mo,int da){
    if(ye<y1||ye>y2)return false;
    if(ye==y1){
        if(mo<m1)return false;
        else if(mo==m1){
            if(da<d1)return false;
        }
    }else if(ye==y2){
        if(mo>m2)return false;
        else if(mo==m2){
            if(da>d2)return false;
        }
    }
    return true;
}
int main(){
    scanf("%s%s",a,b);
    x1=atoi(a),x2=atoi(b);
    y1=x1/10000,y2=x2/10000;
    m1=(x1%10000)/100,m2=(x2%10000)/100;
    d1=x1%100,d2=x2%100;
    int i,j,k,l,t,ye,mo,da,ok;
    for(i=0;i<=1;i++)
        for(j=0;j<=9;j++){
            mo=i*10+j;
            if(mo>12)break;
            if(!mo)continue;
            for(k=0;k<=3;k++){
                if(k==3&&mo==2)break;
                for(l=0;l<=9;l++){
                    ye=l*1000+k*100+j*10+i,
                    da=k*10+l;
                    if(da>31)break;
                    if(!da)continue;
                    if(da==31){
                        for(ok=t=0;t<7;t++)
                            if(mo==rs[t])ok=1;
                        if(!ok)break;
                    }
                    if(ye%400==0||(ye%4==0&&ye%100!=0)){
                        if(mo==2&&da>29)break;
                    }else if(mo==2&&da>28)break;
                    if(!cmp(ye,mo,da))continue;
                    ans++;
                }
            }
        }
    printf("%d\n",ans);
    return 0;
}

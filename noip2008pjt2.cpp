#include <bits/stdc++.h>
using namespace std;
struct Seat{
    int id,tot;
};
Seat line[1005],row[1005];
bool cmp(const Seat &sa,const Seat &sb){
    return sa.tot>sb.tot;
}
bool cmp2(const Seat &sa,const Seat &sb){
    return sa.id<sb.id;
}
int n,m,K,L,D;
int main(){
    scanf("%d%d%d%d%d",&n,&m,&K,&L,&D);
    int x1,y1,x2,y2;
    for(int i=1;i<=n;i++)
        line[i].tot=0,line[i].id=i;//该行上面 
    for(int i=1;i<=m;i++)
        row[i].tot=0,row[i].id=i;//该列右边 
    for(int i=1;i<=D;i++){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1==x2)
            row[min(y1,y2)].tot++; //同行记录列 
        else if(y1==y2)
            line[min(x1,x2)].tot++;
    }
    sort(line+1,line+1+n,cmp),sort(line+1,line+K+1,cmp2);
    sort(row+1,row+1+m,cmp),sort(row+1,row+1+L,cmp2);
    for(int i=1;i<K;i++)
        printf("%d ",line[i].id);
    printf("%d\n",line[K].id);
    for(int i=1;i<L;i++)
        printf("%d ",row[i].id);
    printf("%d\n",row[L].id);
    return 0;
}

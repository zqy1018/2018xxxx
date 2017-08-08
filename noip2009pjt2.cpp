#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
P p[10005];
bool cmp(const P &pa,const P &pb){
	return pa.first>pb.first||(pa.first==pb.first&&pa.second<pb.second);
}
int n,m,lim;
int main(){
    scanf("%d%d",&n,&m);  
    lim=m*150/100;  
    for(int i=0;i<n;i++)
		scanf("%d%d",&p[i].second,&p[i].first);  
    sort(p,p+n,cmp);
    int sc=p[lim-1].first,extra=0;  
    for(int i=lim;i<n;i++)
        if(p[i].first==sc)extra++;  
        else break;
    printf("%d %d\n",sc,lim+extra);  
    for(int i=0;i<lim+extra;i++)  
        printf("%d %d\n",p[i].second,p[i].first);  
    return 0;  
} 

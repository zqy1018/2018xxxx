#include <cstdio>
#include <cctype>
using namespace std;
int main() {
    char isbn[20];
    int last,sum=0,count=1;
    scanf("%s",isbn);
    for(int i=0;i<13;i++){
        if(isdigit(isbn[i])&&i!=12){
            sum+=(isbn[i]-'0')*count,count++;
        }else if(isdigit(isbn[i])&&i==12){
            sum%=11;
            last=isbn[i]-'0';
        }else{
            sum%=11,last=10;
        }
    }
    if(last==sum){
        printf("Right\n");
    }else{
        for(int i=0;i<12;i++)
            printf("%c",isbn[i]);
        if(sum!=10)
            printf("%d\n",sum);
        else
            printf("X\n");
    }
    return 0;
}

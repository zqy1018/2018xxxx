#include <bits/stdc++.h>
using namespace std;
char key[1005],tex[1005];
int get(char a,char b){
    return (b-'a'-(a-'a')+26)%26;
}
int main(){
    scanf("%s%s",key,tex);
    int l1=strlen(key),l2=strlen(tex);
    for(int i=0;i<l1;i++)
        key[i]=tolower(key[i]);
    for(int i=0;i<l2;i++){
        if(isupper(tex[i]))
            putchar('A'+get(key[i%l1],tolower(tex[i])));
        else
            putchar('a'+get(key[i%l1],tex[i]));
    }
    return 0;      
}    

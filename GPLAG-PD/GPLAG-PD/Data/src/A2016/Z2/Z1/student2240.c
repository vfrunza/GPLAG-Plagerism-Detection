#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int broj, decimale=1;
    int cifra1, cifra2, neg, rez=0;
    printf("Unesite broj: ");
    scanf("%d",&broj);
    
    if (broj<0) broj*=-1;
    
    while(broj!=0) {
        cifra1=broj%10;
        broj/=10;
        if(broj!=0){
            cifra2=broj%10;
            neg=cifra1-cifra2;
            if(neg<0) neg*=-1;
            rez+=neg*decimale;
            decimale*=10;
        }
    }
    printf("%d", rez);
    return 0; }
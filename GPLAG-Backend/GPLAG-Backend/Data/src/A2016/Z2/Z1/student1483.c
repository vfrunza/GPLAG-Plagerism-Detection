#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    
    int broj;
    printf("Unesite broj: ");
    scanf("%d",&broj);
    broj=abs(broj);
    int novi_broj;
    novi_broj=0;
    int i;
    int stepen;
    stepen=0;
    int cifra1,cifra2;
    int razlikacifara;
    for(i=broj;i>10;i=i/10){
        cifra1=i%10;
        cifra2=i/10%10;
        razlikacifara=abs(cifra1-cifra2);
        novi_broj=novi_broj+razlikacifara*pow(10,stepen);
        stepen++;
    }
    
    printf("%d",novi_broj);
    
    return 0;
}
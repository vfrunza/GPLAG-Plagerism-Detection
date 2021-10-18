#include <stdio.h>
#include <math.h>

int main(){
    printf("Unesite broj: ");
    int broj;
    scanf("%d",&broj);
    if(broj<0)broj=fabs(broj);
    int prva_cifra;
    int druga_cifra,desetka;
    int krajnji_broj,razlika_cifara;
    int a;
    krajnji_broj=0;
    desetka=0;
    for(a=broj;a>10;a=a/10){
        druga_cifra=a/10%10;
        prva_cifra=a%10;
        razlika_cifara=fabs(prva_cifra-druga_cifra);
        krajnji_broj=krajnji_broj+razlika_cifara*pow(10,desetka);
        desetka++;
    }
    
    printf("%d",krajnji_broj);
    
    return 0; 
}
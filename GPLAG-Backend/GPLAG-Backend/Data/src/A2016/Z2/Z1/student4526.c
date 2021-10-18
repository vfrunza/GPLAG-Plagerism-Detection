#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
    
    int a,b,c,d,e,f=0,p,br=0,g=1,l;
    printf("Unesite broj: ");
    scanf("%d", &a);
    if(a>0 && a<10){
        printf("0");
    }else {
    l=abs(a);
    while(l>=10){
        p=l%10; //Prva cifra-ostatak pri dijeljenju
        d=l/10;
        d=d%10;//Druga cifra
        e=abs(p-d);//razlika dvije susjedne cifre-apsolutna vrijednost
        f=f+(e*g);
        g=g*10;
        l=l/10;
        
    }printf("%d",f);
    
}return 0;}
#include <stdio.h>
#include <math.h>
int main(){
    int n,x=0,pro=0,y=0,o=10000,brojac=-1;
    printf("Unesite broj: ");
    scanf("%d",&n);
    if(n>=-9&& n<=9) {printf("0"); return 0;}
    while(n!=0){
    x=n%10;
    n=n/10;
    if(n==0) break;
    y=n%10;
    pro=fabs(x-y);
    brojac++;
    o=o+pow(10,brojac)*pro;
}
o=o-10000;
    printf ("%d",o);
    
    return 0;
}
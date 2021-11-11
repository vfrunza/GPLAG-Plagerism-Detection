#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
int i,n,fraci1,fraci2,broj=0;

printf("Unesite broj: ");
scanf("%d", &n);
if(n<0)
n=abs(n);

    for(i=0; n>10; i++){
        fraci1 = n%10;
        fraci2 = (n/10)%10;
        n/=10;
        
    broj = broj + (abs(fraci1 - fraci2)*pow(10,i));
    }

printf("%d", broj);
return 0;
}







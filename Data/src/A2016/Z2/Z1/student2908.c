#include <stdio.h>
#include <math.h>

int main () {
    int brojcif=0 , nova, zadnja,predz,i;
    int n, broj;
    int k=1;
    printf("Unesite broj: ");
    scanf("%d",&n);
    broj=n;
    while(broj!=0){
        broj/=10;
        brojcif++;
    }
    for(i=brojcif-1; i>0; i--) {
        zadnja=n%10;
        predz=(n/10)%10;
        nova=fabs(zadnja-predz);
        broj=nova*k+broj;
        n=n/10;
        k*=10;
    }

printf("%d",broj);
    return 0;
}
#include <stdio.h>
#include <math.h>

int main () {

long  j=1,n,i,n1,n2,brojac=0,g=0;

printf("Unesite broj: ");
scanf("%ld", &n);

n=fabs(n);

for(i=1;i<=n;i*=10) {
brojac++;
}


for(i=0;i<brojac-1;i++) {
n1=(n/j)%10;
j*=10;
n2=(n/j)%10;
g+=fabs(n2-n1)*pow(10,i);
}

printf("%ld", g);

return 0;

}
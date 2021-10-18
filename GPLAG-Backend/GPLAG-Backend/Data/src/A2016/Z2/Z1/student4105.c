#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int n, z=0, brojac=0, k;
    printf("Unesite broj: ");
    scanf("%d", &n);
   
   
    n=abs(n);
    brojac-=2;
    k=1;
    while (n>9)
    {
        int x, y;
        x=n%10;
        y=(n/10)%10;
        z+=abs(x-y)*k;
        k*=10;
        n/=10;
    }
    
    
    printf("%d", z);
    
    return 0;
}

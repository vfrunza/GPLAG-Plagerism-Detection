#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int okreni(int n)

{
    if(n<0)n*=-1;
    if(n>-9 && n<9) return 0;
    
    int suma,k,cifra,cifra1,z;
     suma=0;
     k=10;
     cifra=n%10;
     cifra1=n%100;
    cifra1/=10;
    suma+=fabs(cifra-cifra1);
    n/=10;
    
    
    while(n>9)
    {
        cifra=n%10;
        cifra1=n%100;
        cifra1/=10;
        
         z=fabs(cifra-cifra1);
        z*=k;
        k*=10;
        suma+=z;
        n/=10;
    }
    return suma;
    
}

int main()
{
    int n;
    printf("Unesite broj: ");
    scanf("%d",&n);
    int b=okreni(n);
    printf("%d",b);
    
    return 0;
}
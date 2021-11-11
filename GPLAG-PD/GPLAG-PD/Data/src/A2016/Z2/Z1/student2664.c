#include <stdio.h>
#include <math.h>

int main() {
	
	
	int cifra=0,cifra1=0,cifra2=0,konacna=1;
	printf("Unesite broj: ");
	scanf("%d",&cifra);
	
/*
    if (n>=0 && n<=9){
    	printf("0");
    } 
        */
    while (cifra!=0)
    {
    	cifra1=cifra%10;
    	cifra=cifra/10;
    	cifra2=cifra%10;
    	konacna= 10*konacna + fabs(cifra1-cifra2);
    	
    }
    
    if ( cifra < 0) 
    cifra = fabs(cifra);
    
    
    cifra = 1;
    while (konacna!=0)
    {
        konacna=konacna%10;
        cifra = 10*konacna + konacna;
        konacna=konacna/10;

    }
	printf ("%d",konacna);
	return 0;
}

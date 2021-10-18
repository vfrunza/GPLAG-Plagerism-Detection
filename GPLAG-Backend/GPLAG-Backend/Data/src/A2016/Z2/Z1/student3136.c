#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n,prva,druga,pom,brojac,suma ;
	printf("Unesite broj: ") ;
	scanf("%d",&n) ;
	
	if(n<0) { n=abs(n) ;}
	
	prva=n%10 ;
	n/=10 ;
	if(n==0) {
	    suma=0 ;
	    printf("%d",suma) ;
	    return 0 ;
	}
		brojac=0 ;
	suma=0 ;
	
	
	
	do{

	druga=n%10 ;
	n/=10 ;
	pom=prva-druga ;
	if(pom<0) { pom=abs( pom) ; }
	suma=pom*pow(10,brojac) + suma ;
	prva=druga ;
	brojac++ ;
	} while(n!=0) ;
	 printf("%d",suma ) ;
	
	return 0;
}

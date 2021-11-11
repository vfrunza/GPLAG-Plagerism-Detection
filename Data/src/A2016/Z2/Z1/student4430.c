#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	
	int c, a, d, broj, brojac1=0, izlaz, pomocni_broj, b, i, brojac=0;
	
	printf("Unesite broj: ");
	scanf("%d", &broj);
	pomocni_broj=broj;
	if(pomocni_broj<0)
	broj=-broj;
	for(i=0; i<100; i++){
	    
	    pomocni_broj=pomocni_broj/10;
	    brojac++;
	    if(pomocni_broj==0) break;
	}
	if(brojac==1) printf("0");
	
	for(i=brojac-1; i>0; i--){
		c=pow(10,i);
		b=broj/c;
		broj=(broj-b*c);
		d=pow(10,i-1);
		a=broj/d;
		
		izlaz=a-b;
		if(izlaz<0) izlaz=-izlaz;
		if(izlaz!=0) brojac1++;
		if(brojac1==0) continue;
		
		printf("%d",  izlaz);
	}
	if(brojac1==0 && brojac!=1) printf("0");
	
	return 0;
}

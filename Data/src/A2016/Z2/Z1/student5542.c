#include <stdio.h>
#include <math.h>

int main() {
	
	int broj;
	int suma=0, brojac=1;
	int a, b, c;
	
	printf("Unesite broj: ");
	
	scanf("%d", &broj);
	
	while(broj!=0) {
		
		a=broj%10;
		broj=broj/10;                                
		if(broj==0) break;
		b=broj%10;         
		c=a-b;                                            
		c=fabs(c);          
		c=c*brojac;                                                                                                
		suma+=c;
		brojac*=10; 
		
	}
	
	printf("%d", suma);  
	
	return 0;
	
}


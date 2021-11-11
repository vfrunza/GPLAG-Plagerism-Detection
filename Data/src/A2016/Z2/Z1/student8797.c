#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int x;
	int a,b;
	int y=0;
	int brojac=0;
	printf("Unesite broj: ");
	scanf("%d", &x);
	x =  abs(x);
	if(x<10) printf("0");
	else {
	
		while(1){
			
			
			a=x%10;
			x=x/10;
			if (x==0) break; 
			b=x%10;
			y=y+(abs(a-b)*pow(10, brojac));
			brojac++;
			
		}
		
	printf("%d", y);	
		
	}return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int k=0,b=0,st=0,nd=0,z=0,suma=0;
	printf("Unesite broj: ");
	scanf("%d", &b);
	b=abs(b);
	if(b<10){
		printf("");
		
	}do{
		st=b%10;
		b/=10;
		if(b!=0){
			nd=b%10;
			suma=abs(nd-st);
			z=z+suma*pow(10,k);
			k++;
		}
		
	}while(b!=0);
	printf("%d", z);
	return 0;
}

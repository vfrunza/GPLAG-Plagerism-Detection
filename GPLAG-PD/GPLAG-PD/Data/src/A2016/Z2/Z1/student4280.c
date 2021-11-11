#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int broj=0,razlika=0,i=0,x=0,y=0,novibroj=0;
	
	printf("Unesite broj: ");
	scanf("%d", &broj);
	
	if (abs(broj)<10) {
		printf("0");
		return 0;
	}
	
	while(broj!=0) {
	x=abs(broj%10);
	broj=abs(broj/10);
	if(broj==0) break;
	y=abs(broj%10);
	razlika=abs(x-y);
	novibroj+=razlika*pow(10,i);
	i++;
	}
	
   printf("%d",novibroj);
	

	
	return 0;
}
	
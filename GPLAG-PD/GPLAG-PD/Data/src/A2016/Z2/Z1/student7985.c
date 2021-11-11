#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int broj, zadnjac, predzadnjac, c, novibr=0, cc=1;
	printf("Unesite broj: ");
	scanf ("%d", &broj);
	broj=abs(broj);
	
	if (broj==0) { 
		printf ("0");
		return 0;
		}
		
	while (broj>10) {
	zadnjac=broj%10; /* od 38279 to je 9*/
	broj=broj/10;	/* 3827*/
	predzadnjac=broj%10; /*7*/
	
	c=abs(predzadnjac-zadnjac); /*c=2*/
	novibr+=c*cc;
	cc=cc*10; /*cc se povećava  10puta */
	
	}
	printf  ("%d", novibr) ;
 
	return 0;
}

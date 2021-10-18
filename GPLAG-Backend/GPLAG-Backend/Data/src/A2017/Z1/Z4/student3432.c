#include <stdio.h>

int main() {
	int red,kol,sir,i,j;
	do{
	printf("Unesite broj redova: ");
	scanf ("%d",&red);}
		while (red>10 || red<=0);
	do{
	
	printf("Unesite broj kolona: ");
	scanf("%d",&kol);}
	while (kol>10 || kol<=0);
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&sir);}
	while (sir>10 || sir<=0);

		for(i=0;i<red*2+1;i++){
			for(j=0;j<(kol*sir+kol+1);j++) {
				if (i%2==0){
					if (j%(sir+1)==0){
						printf("+");
					}
						else 
						printf("-");
					}
					else {
						if (j%(sir+1)==0){
							printf("|");
						}
							else 
							printf(" ");
						}
					} printf("\n");
				}
			
		
		
		
		
	

	return 0;
}

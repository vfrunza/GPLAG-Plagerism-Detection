#include <stdio.h>

int main() {
	int r,k,s,i,j;
	
	do{
	printf("Unesite broj redova: ");
	scanf("%d", &r);
	} while (r<=0 || r>10);
	do{
	printf("Unesite broj kolona: ");
	scanf("%d", &k);
	} while (k<=0 || k>10);
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &s);
		} while (s<=0 || s>10);
	
	
	
	//Ispisuje Kolone
	for (i = 0; i < 2*r+1; i++) {
		if (i%2==0) {
		printf("+");	
		}
		else {
		printf("|");	
		}
		
		//Redovi
		
		for(j=1;j<(k*s+k+1);j++){
			
		//Brisanje za i neparno
		
			if (i%2!=0) {
				 if (j%(s+1)==0) {
			printf("|");
		}
		else
	{
				printf(" ");
	}
			}
			
		//Razdvoji polja
		else if (j%(s+1)==0) {
			printf("+");
		}
		//Dodavanje za i parno
			else
		{
				printf("-");
		}
		
		
		}
		printf("\n");
	}
	return 0;
}

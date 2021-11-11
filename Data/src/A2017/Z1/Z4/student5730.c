#include <stdio.h>

int main() {
/*	printf("Zadaća 1, Zadatak 4");*/
	
	
	int i, j, red, kolona, sirina;
	do {
	printf("Unesite broj redova: ");
	scanf("%d", &red);
	} while(!(red>0 && red<=10));
	do{
	printf("Unesite broj kolona: ");
	scanf("%d", &kolona);
	}while(!(kolona>0 && kolona<=10));
	
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &sirina);
	} while(!(sirina>0 && sirina<=10));
	
	
	
	for (i=0; i<2*red+1; i++)
	{
		for(j=0; j<kolona*sirina + kolona + 1; j++) {  
	
			if((i%2==0) && (j%(sirina+1)==0)) printf("+");
			else if((i%2==0) && (j%(sirina+1)!=0)) printf("-");
			else if((i%2==1) && (j%(sirina+1)==0)) printf("|");
			else printf(" "); 
			}
	
	 	printf("\n");
		
	}
	
	
	return 0;
}

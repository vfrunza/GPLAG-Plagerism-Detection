#include <stdio.h>

int main() {
	int sirina,kolona,red,i,j,k,m,n;
	do{
	printf("Unesite broj redova: ");
	scanf("%d",&red);
	} while (red<1 || red>10);
	
	do{
		printf("Unesite broj kolona: ");
		scanf ("%d",&kolona);
	} while (kolona<1 || kolona>10);
	
	do{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&sirina);
	}while(sirina<1 || sirina>10);
	
	for(k=1; k<=2*red+1; k++) {
		if (k%2!=0)
		{
		for(i=0; i<kolona; i++) {
			printf("+");
	    for(j=0; j<sirina; j++){
	    	printf("-");
	    }
	    }
	   printf("+\n");
	    } 
	    
	 else { 
	 	for(n=0; n<kolona; n++){
	 		printf("|");
	   for(m=0; m<sirina; m++) {
	   	printf(" "); }}
	   	printf("|\n");
	 }}
	return 0;
}
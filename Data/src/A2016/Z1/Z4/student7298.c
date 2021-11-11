#include <stdio.h>

int main() {
	int broj,i,j;
	while(1){
		printf("Unesite broj n: ");
		scanf("%d", &broj);
		if(broj>0 && broj<=50) break;
		else printf("Pogresan unos\n");
	}
	if(broj==1) printf("***");
	else{
	for(i=0;i<broj;i++){
		for(j=0;j<2*broj-1;j++){
			if(i==j || i+j==2*broj-2) printf("*");
			else printf(" ");
		}
		for(j=0;j<2*broj-2;j++){
			if(i==j+1 || i+j==2*broj-3) printf("*");
			else printf(" ");
		}
	    	printf("\n");
	}
	}
	return 0;
}

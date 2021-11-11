#include <stdio.h>

int main() {
	
	int i,j,k,nr=0,nk=0,ns=0;
	
	do{
	printf("Unesite broj redova: ");
	scanf("%d", &nr);
	}while(nr<1 || nr>10);
	
	do{
	printf("Unesite broj kolona: ");
	scanf("%d", &nk);
	}while(nk<1 || nk>10);
	
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &ns);
	}while(ns<1 || ns>10);
	
	for(i=0;i<=nr;i++){
		for(j=0;j<nk;j++){
			printf("+");
		for(k=0;k<ns;k++){
			printf("-");
		}
		}
		printf("+");
		printf("\n");
		if(i==nr){
			break;
		}
		
			for(j=0;j<nk;j++){
			printf("|");
			for(k=0;k<ns;k++){
			printf(" ");
		}
		}
		printf("|");
		printf("\n");
	}
	return 0;
}

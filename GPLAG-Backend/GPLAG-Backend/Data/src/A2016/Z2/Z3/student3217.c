#include <stdio.h>
#define t 10

int main() {
	int i,j,k,bt,X[t],Y[t],a;

	do{
		printf("Unesite broj tacaka: ");
		scanf("%d", &bt);
		if(bt<=0 || bt>10)
		printf("Pogresan unos\n");
	}
	while(bt<=0 || bt>10);
	for(a=0;a<bt;a++) {
		    printf("Unesite %d. tacku: ", a+1);
		    scanf("%d %d", &X[a], &Y[a]);
		    
		if(X[a]<0 || Y[a]<0 || X[a]>19 || Y[a]>19) {
			a--;
			printf("Pogresan unos\n");
		} }
	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			for(k=0;k<bt;k++){
			if(X[k]==j && Y[k]==i) {
							printf("*");
					j++;
					
				}}
			  printf(" ");
			}
			
			printf("\n");
}
	return 0;
}

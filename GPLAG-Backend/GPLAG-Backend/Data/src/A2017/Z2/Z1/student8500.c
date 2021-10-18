#include <stdio.h>

int main() {
	int N,i,j;
	do {
		printf("Unesite broj N: ");
		scanf("%d",&N);
		if(!(N%4==0 && N>=8))
			printf("Neispravno N! \n");
	} while(!(N%4==0 && N>=8));
	
	/* Prvi i drugi kvadrant */
	printf("\n");
	for(i=0;i<N/2;i++){
		for(j=0;j<N;j++){
			
			// Prvi kvadrant - ZNAK X
			if(j<N/2) {
				if(i==j)
					printf("\\");
				else if(i==N/2-j-1)
					printf("/");
				else 
					printf(" ");
			} 
			
			//Drugi kvadrant
			else {
				// Prvi i zadnji red pravougaonika
				if (i==0 || i==N/2-1) {
					if(j==N/2 || j==N-1)
						printf("+");
					else printf("-");
				}
				// Ostatak pravougaonika
				else {
					if(j==N/2 || j==N-1)
						printf("|");
					else 
						printf(" ");
				}
			}
		}
		printf("\n");
	}
	
	/* Treci i cetvrti kvadrant */ 
	
	for(i=0;i<N/2;i++){
		for(j=0;j<N;j++) {
				
				/* Treci kvadrant */
				
				if(j<N/2) {
					// Prvi i zadnji red pravougaonika
					if (i==0 || i==N/2-1) {
						if(j==0 || j==N/2-1)
							printf("+");
						else printf("-");
					}
					// Ostatak pravougaonika
					else {
						if(j==0 || j==N/2-1)
							printf("|");
						else 
							printf(" ");
					}
				}
				
				/* Cetvrti kvadrant */
				else {
					/* Horizontalne linije */
					if(i==N/4-1 || i==N/4){
						if(j==N-N/4-1 || j==(N-N/4))
							printf("+");
						else 
							printf("-");
					}
					/* Uspravne linije */
					else {
						if(j==N-N/4-1 || j==N-N/4)
							printf("|");
						else 
							printf(" ");
					}
				}
		}
		printf("\n");
	}
	
	
	
	
	
	return 0;
}

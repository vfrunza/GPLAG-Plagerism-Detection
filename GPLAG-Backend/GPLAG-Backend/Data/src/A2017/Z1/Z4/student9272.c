#include <stdio.h>

int main() {
	
	int i,j,k,s,r,l;
	
	do 
	{ printf("Unesite broj redova: ");
	    scanf("%d",&r);
	} while(r<=0 || r>10);
	
	do { printf("Unesite broj kolona: ");
	    scanf("%d",&k);
	} while(k<=0 || k>10);
	
	do { printf("Unesite sirinu jedne kolone: ");
	    scanf("%d",&s);
	} while(s<=0 || s>10);
	
	for (i=0; i<=(2*r); i++) {
		if(i%2==0) {
			for (j=0; j<=(k-1); j++) {
				printf("+");
			
			for(l=0; l<s ;l++){
					printf("-");
				
					}
			}
			printf("+\n");
		}
		else if(i%2==1) {
			for (j=0; j<=(k-1); j++){
				printf("|");
				for(l=0; l<s; l++) {
					printf(" ");
				}
			}
			printf("|\n");
		}
	}
	return 0;
}
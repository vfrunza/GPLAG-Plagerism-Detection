#include <stdio.h>

int main() {
	int i, j, r, k, s;
	
	do{
		printf("Unesite broj redova: ");
		scanf("%d", &r);
	} while(r>10 || r<1);
	
	do{
		printf("Unesite broj kolona: ");
		scanf("%d", &k);
	} while(k>10 || k<1);
	
	do{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &s);
	} while(s>10 || s<1);
	
	for(i=0; i<=2*r; i++){
		if(i%2==0){
			for(j=0; j<=k+k*s; j++){
				if(j%(1+s)==0) printf("+");
				else printf("-");
			} printf("\n");
		} else {
			for(j=0; j<=k+k*s; j++){
				if(j%(1+s)==0) printf("|");
				else printf(" ");
			} printf("\n");
		}
	}
	
	return 0;
}

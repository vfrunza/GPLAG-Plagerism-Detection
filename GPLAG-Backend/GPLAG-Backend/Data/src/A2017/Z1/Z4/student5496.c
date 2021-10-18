#include <stdio.h>

int main() {
	int brred,brkol,sirina,i,j;
	//do{
		printf("Unesite broj redova: ");
		scanf("%d", &brred);
		printf("Unesite broj kolona: ");
		scanf("%d", &brkol);
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sirina);
	//} while(brred<0 || brred>=10 || brkol<0 || brred>=10 || sirina<0 || sirina>=10);
	for(j=1; j<=brkol; j++){
		if(j%2==1){
			for(i=0; i<brkol*sirina+(brkol+1); i++){
				if (i%(sirina+1)==0) printf("+");
				else printf("-");
			}
			printf("\n");
		}
		if(j%2==0){
			for(i=0; i<brkol*sirina+(brkol+1); i++){
				if(i%(sirina+1)==0) printf("|");
				else printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}

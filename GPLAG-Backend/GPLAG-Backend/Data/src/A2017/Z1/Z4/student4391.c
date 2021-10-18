#include <stdio.h>

int main() {
	int r,k,jk,i,j;
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
	scanf("%d", &jk);
	}while (jk<=0 || jk>10);
	
	for(i=0;i<(2*r)+1;i++){
		for(j=0;j<k*(jk+1)+1;j++){
			if(i%2==0){
				if(j%(jk+1)==0){
			printf("+");
			}else{
			printf("-");
			}
		} else
			if(j%(jk+1)==0){
			printf("|");
			}else{
			printf(" ");
		}

		}
		printf("\n");
	}
	
	return 0;
}

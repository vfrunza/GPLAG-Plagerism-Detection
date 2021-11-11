#include <stdio.h>

int main() {
	int i, j, brred, brkol, sirkol;
	do{
		printf("Unesite broj redova: ");
		scanf("%d", &brred);
	}while(brred<=0 || brred>10);
	do{
		printf("Unesite broj kolona: ");
		scanf("%d", &brkol);
	}while(brkol<=0 || brkol>10);
	do{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sirkol);
	}while(sirkol<=0 || sirkol>10);
	for(i=0;i<brred*2+1;i++){
		for(j=0;j<=brkol*(sirkol+1);j++){
			if(i%2==0 && j%(sirkol+1)==0) printf("+");
		    else if(i%2==0) printf("-");
			else if(j%(sirkol+1)==0) printf("|");
			else printf(" ");
			}
		
		printf("\n");
	}
	return 0;
}

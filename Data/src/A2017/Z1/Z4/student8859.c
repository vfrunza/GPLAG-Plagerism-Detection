#include <stdio.h>

int main() {
	int red, kol, sir, i, j, brojac=0;
	
	do{
	printf("Unesite broj redova: ");
	scanf("%d", &red);
	}while(red<=0 || red>10);
	
	do{
	printf("Unesite broj kolona: ");
	scanf("%d", &kol);
	}while(kol<=0 || kol>10);
	
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &sir);
	}while(sir<=0 || sir>10);
	
	for(i=1; i<=(2*red+1); i++) {
		brojac=0;
		for(j=1; j<=(sir*kol+kol+1); j++){
			if((i%2)!=0){
				if(j==brojac*(sir+1)+1) {printf("+"); brojac++;}
				else printf("-");
				} 
			else {
				if(j==brojac*(sir+1)+1) {printf("|"); brojac++;}
				else printf(" ");
			}
		}
		printf("\n");
	}
	
	return 0;
}

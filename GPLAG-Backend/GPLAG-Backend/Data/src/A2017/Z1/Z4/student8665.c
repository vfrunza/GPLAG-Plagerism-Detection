#include <stdio.h>

int main() {
	int r, k, s, i, j;
	do{
	printf("Unesite broj redova: ");
	scanf("%d", &r);
	}
	while (r<=0 || r>10);
	do{
	printf("Unesite broj kolona: ");
	scanf("%d", &k);
	}
	while (k<=0 || k>10);
	do{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &s);
	}
	 /*Broj mjesta na kojim ce se ispisati karakteri po i osi je veci za jedan kada je broj redova pomnozenom sa dva, 
	 dok je na j osi veci za jedan od zbira kolona i proizvoda broja kolona i sirine jedne kolone.*/
	while (s<=0 || s>10);
	for(i=0;i<(2*r+1);i++){           
		for(j=0;j<(k+s*k+1);j++){
			if(i%2==0) {
				if (j%(s+1)==0){
				printf("+");}
				else {
				printf("-");}
				}
		 		else{
		 		if(j%(s+1)==0){
		 		printf("|");
			 }
			else {printf(" ");}
		 }
		}
	printf("\n");
}
	return 0;
}

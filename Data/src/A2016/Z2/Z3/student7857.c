#include <stdio.h>

int main() {
	char koord[20][20]={0};
	int i, a, b, j, n;
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	if (n<=0 || n>10){
		do{
			printf("Pogresan unos\n");
			printf("Unesite broj tacaka: ");
			scanf("%d", &n);
		}while(n<=0 || n>10);
	}
	for (i=0; i<n; i++){
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d" "%d", &a, &b);
		if(a<0 || a>19 || b<0 || b>19){
			printf ("Pogresan unos\n");
			i--;
		}
		else{
		koord[b][a]++;}
	}
	
	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			if(koord[i][j]) {koord[i][j]='*';}
			else {koord[i][j]=' ';}
			printf("%c", koord[i][j]);
		}
		printf ("\n");
	}
	return 0;
}

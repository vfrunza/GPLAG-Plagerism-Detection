#include <stdio.h>
#define brEl 20

int main() {
	int a,b, brojTacaka,i,j;
	char matrica[brEl][brEl];
	for(i=0; i<brEl; i++){
		for(j=0; j<brEl; j++)
			matrica[i][j]=' ';
	}
	printf("Unesite broj tacaka: ");
	scanf("%d", &brojTacaka);
	while(brojTacaka>10 || brojTacaka<1){
		printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
		scanf("%d", &brojTacaka);
	}
	for(i=0; i<brojTacaka; i++){
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &a,&b);
		while(a<0 || a>19 || b<0 || b>19){
			printf("Pogresan unos\n");
			printf("Unesite %d. tacku: ", i+1);
			scanf("%d %d", &a, &b);
		}
		matrica[b][a]='*';
	}
	for(i=0; i<brEl; i++){
		for(j=0; j<brEl; j++){
			printf("%c", matrica[i][j]);
		}
		printf("\n");
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
int i=0, j=0, k=0, redova, kolona, sirina;
do{
printf("Unesite broj redova: ");
scanf("%d", &redova);
}while(redova<=0 || redova>10);
do{
printf("Unesite broj kolona: ");
scanf("%d", &kolona);
}while(kolona<=0 || kolona>10);
do{
printf("Unesite sirinu jedne kolone: ");
scanf("%d", &sirina);
}while(sirina<=0 || sirina>10);
for(i=0;i<=2*redova;i++){
	for(j=0;j<=kolona;j++){
		if(i%2==0) printf("+");
		else printf("|");
		for(k=0;k<sirina;k++){
			if(i%2==0 && j!=kolona) printf("-");
			else printf(" ");
		}
	}
	printf("\n");
}
	return 0;
}

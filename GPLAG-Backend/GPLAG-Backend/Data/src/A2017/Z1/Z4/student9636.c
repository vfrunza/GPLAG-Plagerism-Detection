#include <stdio.h>

int main() {
	int broj_r, broj_k, sirina_jk;
	do {
		printf("Unesite broj redova: ");
		scanf("%d", &broj_r);
	}
	while (broj_r<=0 || broj_r>=11);
	do {
		
		printf("Unesite broj kolona: ");
		scanf("%d", &broj_k);
	}
	while (broj_k<=0 || broj_k>=11);
	do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sirina_jk);
	}
	while (sirina_jk<=0 || sirina_jk>=11);
	
	int i=0, j=0, m=0, n=0, p=0, q=0, g=0;

	for(i=0; i<broj_r;i++){
		for(j=0;j<broj_k;j++){
		printf("+");
			for (m=0;m<sirina_jk;m++)
			{printf("-");}
			
	}
	printf("+");
	printf("\n");
	for(n=0;n<broj_k;n++){
		printf("|");
	
	for (p=0;p<sirina_jk;p++){
	printf(" ");}
	}
	printf("|");
	printf("\n");
	}
	for (q=0;q<broj_k;q++){
			printf("+");
			for(g=0;g<sirina_jk;g++)
			{printf("-");}
		}
			printf("+");
	return 0;
}

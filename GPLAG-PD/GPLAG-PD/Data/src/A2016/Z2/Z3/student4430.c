#include <stdio.h>

int main() {
	
	int i, j, k, broj_tacaka, niz_x[10], niz_y[10], brojac=0, brojac1=0;
	A:
	printf("Unesite broj tacaka: ");
	scanf("%d", &broj_tacaka);
	if(broj_tacaka>10 || broj_tacaka<1) {
		printf("Pogresan unos\n");
		goto A;
	}
	for(i=0; i<broj_tacaka; i++){
		B:
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &niz_x[i], &niz_y[i]);
		if(niz_x[i]<0 || niz_x[i]>19 || niz_y[i]<0 || niz_y[i]>19){
			printf("Pogresan unos\n");
			goto B;
		}
		
	}
	
	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			brojac=0;
			brojac1=0;
			for(k=0; k<broj_tacaka; k++){
				if(brojac1>0) continue;
			if(i==niz_y[k]  && j==niz_x[k]){
				printf("*");
				brojac1++;
			}
			else brojac++;
			if(brojac==broj_tacaka) printf(" ");
			
		}
		}
		printf("\n");
	}
	
	return 0;
}

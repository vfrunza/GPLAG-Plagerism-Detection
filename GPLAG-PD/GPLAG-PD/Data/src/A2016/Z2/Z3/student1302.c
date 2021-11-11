#include <stdio.h>

int main() {
	//printf("Zadaća 2, Zadatak 3");
	int i, j, t, tacka=1, x[10], y[10], printao, lj;
	
	
	unos:
	printf("Unesite broj tacaka: ");
	scanf("%d", &t);
	if(t<=0 || t>10) {printf("Pogresan unos\n"); goto unos;}
	
	for (i=0; i<10; i++){
		unos1:
		printf("Unesite %d. tacku: ", tacka);
		scanf("%d %d", &y[i], &x[i]);
		if (x[i]<0 || x[i]>19 || y[i]<0 || y[i]>19) {
			printf("Pogresan unos\n"); 
			goto unos1; 
		}
		tacka++;
		if(tacka>t) break;
	}
			
	
		for(i=0; i<20; i++) {
			for(j=0; j<20; j++) {
				printao=0;
				for(lj=0; lj<t; lj++) {
					if(x[lj]==i && y[lj]==j) {
						printf("*");
						printao=1;
						break;
					}
				}
				if(printao==0) printf(" ");
			}
			printf("\n");
		}
		
	return 0;
}

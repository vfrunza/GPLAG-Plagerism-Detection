#include <stdio.h>

int main() {
	int broj, nizi[10], nizj[10],i,j,k,tacno=1;
	for(i=0;i<10;i++) {
	printf("Unesite broj tacaka: ");
	scanf("%d", &broj);
	if(broj>10 || broj<=0) {
		printf("Pogresan unos\n");
	}
	else break;
	}
	
	for(i=0;i<broj;i++) {
		do {
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &nizj[i], &nizi[i]);
		if(nizi[i]<0 || nizi[i]>19 || nizj[i]<0 || nizj[i]>19) 	printf("Pogresan unos\n");
		} while( nizi[i]<0 || nizi[i]>19 || nizj[i]<0 || nizj[i]>19);
	}
	for(i=0; i<20;i++) {
		for(j=0;j<20;j++) {
			for(k=0;k<broj;k++) {
				tacno=1;
				if(i==nizi[k] && j==nizj[k]) {
					printf("*");				
					tacno=0;
				}
				if(!tacno) break;
			}
			if(tacno) printf(" ");
			}
			printf("\n");
		}
			
				
	return 0;
}

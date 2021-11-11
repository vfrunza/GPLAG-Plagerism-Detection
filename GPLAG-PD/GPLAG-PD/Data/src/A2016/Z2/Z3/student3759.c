#include <stdio.h>

int main() {
	
	int xORD[20], yORD[20], brojTACAKA, i=0, j=0, k=0, tacnost=0, h=0, postoji=0;
	
	printf("Unesite broj tacaka: ");
	scanf("%d", &brojTACAKA);
	
	while(h==0){
		if(h==0 && brojTACAKA<=10 && brojTACAKA>0){
			h=1;
		}
		else{
			printf("Pogresan unos\n");
			printf("Unesite broj tacaka: ");
			scanf("%d", &brojTACAKA);
			h=0;
		}
	}
	for(i=0;i<brojTACAKA;i++){
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &xORD[i], &yORD[i]);
		if(xORD[i]>=20 || xORD[i]<0 || yORD[i]<0 || yORD[i]>=20){
			printf("Pogresan unos\n");
			i--;
		}
	}
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			while(k<brojTACAKA){
				if(xORD[k]==j && yORD[k]==i && postoji==0){
					printf("*");
					postoji++;
				
				}
				k++;
			}
			if( postoji==0){
				printf(" ");
			}
			postoji=0;
			k=0;
			tacnost=0;
		}
		printf("\n");
	}
	return 0;
}

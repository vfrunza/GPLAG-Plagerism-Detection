#include <stdio.h>

int main() {
	int bt,i,kord1[10],kord2[10],j,k,c;
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d",&bt);
		if(bt<1 || bt>10){
			printf("Pogresan unos\n");
		}
	}while(bt<1 || bt>10);
	for(i=0;i<bt;i++){
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d",&kord1[i],&kord2[i]);
		if((kord1[i]<0 || kord1[i]>19) || (kord2[i]<0 || kord2[i]>19)){
		printf("Pogresan unos");
	}
	}
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			for(k=0;k<bt;k++){
				c=0;
				if(kord1[k]==j && kord2[k]==i){
					printf("*");
					c=1;
					break;
				}
			}
			if(c==0){
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}

#include <stdio.h>
int main(){
	int i,j,k,broj,A[10],B[10];
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d", &broj);
		if(broj<=0 || broj>10)
			printf("Pogresan unos \n");
	}
	while (broj<=0 || broj>10);
	for (i=0;i<broj;i++){
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&A[i],&B[i]);
		if (A[i]>19 || A[i]<0 || B[i]>19 || B[i]<0){
			i--;
			printf("Pogresan unos\n");
			continue;
		}
	}
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			for(k=0;k<broj;k++){
				if(A[k]==j && B[k]==i){
					printf("*");
					j++;
				}
			}
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}
#include <stdio.h>

int main() {
	int i=0, j=0, k=0, brojtacaka, A[10], B[10] ;
    do{printf("Unesite broj tacaka: ");
	scanf("%d", &brojtacaka);
		if(brojtacaka>10 || brojtacaka<=0)printf("Pogresan unos\n");}
	while(brojtacaka>10 || brojtacaka<=0);


	for(i=0; i<brojtacaka; i++){
	    printf("Unesite %d. tacku: ", i+1); 
		scanf("%d %d", &A[i], &B[i]);
		if(A[i]>19 || A[i]<0 || B[i]>19 || B[i]<0){
			printf("Pogresan unos\n");
			i--;
			continue;
		}}
	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			for(k=0; k<brojtacaka; k++){
			if(A[k]==j && B[k]==i ){
				printf("*");
				j++;
				}
			}
			printf(" ");
		}
		printf("\n");
	}
		

	return 0;}
	


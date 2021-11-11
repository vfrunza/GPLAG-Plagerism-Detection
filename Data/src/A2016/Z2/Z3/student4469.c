#include <stdio.h>
#include <stdlib.h>
int main() {
	
	int a,i,j,k,b,c,p;
	int nizx[10],nizy[10];
	
	for(i=0;i<10;i++){
		nizx[i]=0;
		nizy[i]=0;
	}
	
	
	
	
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d", &a);
	if (a<=0 || a>10) {
		printf("Pogresan unos\n");
	}
	}while(a<=0 || a>10);
	
	for(i=0;i<a;i++){
		
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &nizx[i],&nizy[i]);
		if((nizx[i]<0) || (nizx[i]>=20) || (nizy[i]<0) || (nizy[i]>=20)) {
			printf("Pogresan unos\n");
			i--;
		}
	}
	
	
	
	for(k=0;k<20;k++){
		for(j=0;j<20;j++) {
			p=1; 
			for(i=0;i<a;i++) {
				if(nizx[i]==j && nizy[i]==k) {
					printf("*");
					p++;
					break;
				}
			}
			if(p==1) {
				printf(" ");
			}
		}
		printf("\n");
	}
	
	

	
	
	return 0;
}

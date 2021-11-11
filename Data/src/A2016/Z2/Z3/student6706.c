#include <stdio.h>

int main() {
	int niz1[10],n,i,niz2[10],j,k,brojac;
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	while (n>10 || n<=0){
		printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
	}
	for(i=0;i<n;i++){
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d%d",&niz1[i],&niz2[i]);
		while(niz1[i]<0 || niz1[i]>19 || niz2[i]<0 || niz2[i]>19 ){
		printf("Pogresan unos\n");
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d%d",&niz1[i],&niz2[i]);	
		}
			}
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
		brojac=1;
				for(k=0;k<n;k++){
			if(i==niz2[k] && j==niz1[k]) { printf("*"); brojac=0; break; }
			}
			if(brojac==1) printf(" ");
			
		}
		printf("\n");
	}
	
	
	
	return 0;
}

#include <stdio.h>

int main() {
	int niz[20], niz1[20], i, j,n,k,pom=5;
	printf("Unesite broj tacaka: ");
	do{
		scanf("%d", &n);
	}while(n<1 || n>20);
	for(i=0; i<n; i++){
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &niz[i], &niz1[i]);
	
		}
	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			pom=5;
			for(k=0; k<n; k++){
				if(i==niz1[k] && j==niz[k]){
				printf("*");
				pom=55;
				break;
				}
			}
				if(pom==5) printf(" ");
		
		}
		printf("\n");
	}

	return 0;

}
#include <stdio.h>

int main() {
	int n,i,j,k;
	int raz=1;
	int mat[20]={0};
	int niz[20]={0};
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
		if(n<=0 || n>10)
			printf("Pogresan unos\n");
	}while(n<=0 || n>10);

	for(i=0;i<n;i++){
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d",&mat[i],&niz[i]);
		if(mat[i]>=20 || mat [i]<0 || niz[i]>=20 || niz[i]<0){
			printf("Pogresan unos\n");
			i--;
		}
	}
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			for(k=0;k<n;k++){
				if(niz[k]==i && mat[k]==j){
					printf("*");
					raz=0;
					break;
				}
			}
			if (raz==1) 
			printf(" ");
			else raz=1;
		}
		printf("\n");
	}
	return 0;
}
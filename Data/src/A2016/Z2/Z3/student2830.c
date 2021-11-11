#include <stdio.h>

int main() {
	int i,j,z,niz1[10],niz2[10],n,c=0,k=0;
	do{
printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if(n<1 || n>10){
			printf("Pogresan unos\n");
		}
	}while(n<1 || n>10);
	for(z=0;z<n;z++){
		printf("Unesite %d. tacku: ", z+1);
	scanf("%d%d", &niz2[z], &niz1[z]);
	if(niz1[z]<0 || niz1[z]>19 || niz2[z]<0 || niz2[z]>19 ){
		printf("Pogresan unos\n");
		z--;
	}
	}
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			for(z=0;z<n;z++){
				 if(i==niz1[z] && j!=niz2[z]){
				} else {
				if(i==niz1[z] && j==niz2[z] ){
				if( (z>0 && niz1[z]==niz1[z-1] && niz2[z]==niz2[z-1] )|| (z>1 && niz1[z]==niz1[z-2] && niz2[z]==niz2[z-2]) ){
					continue;
				}
	if(i==0 && j==n){

		printf(" *");
		continue;
	}
	printf("*");
					k=0;
				}
				else {
					c=1;
				}
				}
			}
			if(k==0){
				c=0;
				k=1;
			}
			if(c==1){
				printf(" ");
				c=0;
			}
		}
		printf("\n");
	}
	return 0;
}

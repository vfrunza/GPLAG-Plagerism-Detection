#include <stdio.h>
#define d 10

int main() {
	int i,j,n,niza[d],nizb[d],c,e;	
		do{
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
		if (n>10 || n<=0) printf("Pogresan unos\n");
		} while (n>10 || n<=0);
	for(c=0;c<n;c++){
		printf("Unesite %d. tacku: ", c+1);
		scanf("%d %d",&niza[c],&nizb[c]);
		if(niza[c]<0 || niza[c]>19 || nizb[c]<0 || nizb[c]>19){
		printf("Pogresan unos\n");
		c--;
		}
	}
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			for(e=0;e<n;e++){
			if(niza[e]==j && nizb[e]==i){
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
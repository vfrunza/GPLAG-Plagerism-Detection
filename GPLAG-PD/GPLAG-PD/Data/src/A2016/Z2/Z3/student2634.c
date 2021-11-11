#include <stdio.h>

int main() {
	int i,n,k,j,max1,max2;
	int niz[20][20]={0};
	max1=0;
	max2=0;
	while(1) {
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
		if(n<=0 || n>10) printf("Pogresan unos\n");
		else break;
	}
	for(i=0;i<n;i++) {
		while(1) {
			printf("Unesite %d. tacku: ",i+1);
			scanf("%d %d",&j,&k);
			if(j<0 || j>19 || k<0 || k>19) printf("Pogresan unos\n");
			else break;
		}
		niz[k][j]=1;
		if(k>max1) max1=k;
		if(j>max2) max2=j;
	}
	for(i=0;i<=max1;i++) {
		for(j=0;j<=max2;j++) {
			if(niz[i][j]==1) printf("*");
			else printf(" ");
		}
		if(i<max1) printf("\n");
	}
	return 0;
}

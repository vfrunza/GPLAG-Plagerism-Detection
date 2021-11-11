#include <stdio.h>
#include <stdlib.h>
int main() {
	int x[20],y[20],i,j,k,n;
	printf("Unesite broj tacaka: ");
	do {
		scanf("%d",&n); 
		if(n>10 || n<0) printf("Pogresan unos\n");
	}
	while(n>10 || n<0);
	for(k=0;k<n;k++) {
		printf("Unesite %d. tacku: ",k+1);
		scanf("%d%d",&x[k],&y[k]);
		if(x[k]>20 || y[k]>20) { 
			printf("Pogresan unos\n");
			k--;
		}
	}
	for(j=0;j<20;j++) {
		for(i=0;i<20;i++) {
			for(k=0;k<n;k++) {
				if (x[k]==i && y[k]==j) printf("*");
				else printf(" ");
				if(k>0) {
					if(x[k]==x[k-1] && y[k]==y[k-1]) printf("\b");
				}
			}
		}
		printf("\n");
	}
	return 0;
}
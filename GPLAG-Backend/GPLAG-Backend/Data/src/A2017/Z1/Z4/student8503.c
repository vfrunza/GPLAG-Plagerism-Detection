#include <stdio.h>

int main() {
	int d,k,r,i,j,h;
	do {
	printf("Unesite broj redova: ");
	scanf("%d",&r);
	} while(r<=0 || r>10);
	do {
	printf("Unesite broj kolona: ");
	scanf("%d",&k);
	} while(k<=0 || k>10);
	do {
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&d);
	} while(d<=0 || d>10);
	
	for(i=0;i<2*r+1;i++) {
		if(i==0 || i%2==0)
		{
			for(j=0;j<(d+1)*k+1;j++) {
				if(j==0 || j%(d+1)==0)
				printf("+");
				else printf("-");
			}
			printf("\n");
		}
		else {
			for(j=0;j<(d+1)*k+1;j++) {
				if(j==0 || j%(d+1)==0) {
					printf("|");
				}
				else printf(" ");
			}
			printf("\n");
		}
	}
return 0;
}
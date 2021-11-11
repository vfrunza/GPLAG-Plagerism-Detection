#include <stdio.h>

int main() {
	int R,K,SK,i,j,a,b;
	do {
	printf("Unesite broj redova: ");
	scanf("%d",&R);}
	while((R>10) || (R<=0));
	do {
	printf("Unesite broj kolona: ");
	scanf("%d",&K);}
	while((K<=0) || (K>10));
	do {
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&SK);}
	while((SK<=0) || (SK>10));
	a=2*R+1;
	b=K+1+K*SK;
		    for(i=0; i<a; i++){
				if(i%2==0){
					for(j=0; j<b; j++){
						if((j==0) || (j%(SK+1)==0)) printf("+");
						else printf("-");
						}
						printf("\n");
				}
				else if(i%2==1){
					for(j=0; j<b; j++){
						if((j==0) || (j%(SK+1)==0)) printf("|");
						else printf(" ");
					}
					printf("\n");
				}
		    }

	return 0;
}

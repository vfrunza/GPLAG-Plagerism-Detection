#include <stdio.h>

int main() {
	int i,j, z;
	int r, k, jk;
	do{
		printf("Unesite broj redova: ");
		scanf("%d", &r);
	}while(r<1 || r>10);
	do{
		printf("Unesite broj kolona: ");
		scanf("%d", &k);
	}while(k<1 || k>10);	
	do{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &jk);
	}while(jk<1 || jk>10);
	
	for(i=0; i<=2*r; i++){
		if(i%2==0)
			for(z=0; z<k; z++){
				printf("+");
				for(j=0; j<jk; j++) printf("-");
				if(z==k-1)	printf("+");
			}
		else
			for(z=0; z<k; z++)	{
				printf("|%*c", jk, ' ');
				if(z==k-1) printf("|");
			}
		printf("\n");	
	}
	
	return 0;
}

#include <stdio.h>
#define VISINA 20
#define SIRINA 20

int main() {
	int i,j,k,l,n,m,mat[VISINA][SIRINA]={{0}};
    do{
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
    if(n>10 || n<1)	printf("Pogresan unos\n");
    }while(n>10 || n<1);

		do{
			for(m=0; m<n; m++){
			printf("Unesite %d. tacku: ", m+1);
			scanf("%d %d", &k, &l);	
			
			if((k<0 || k>19) || (l<0 || l>19)){ printf("Pogresan unos\n"); m--;}
			else mat[l][k]+=1;
				
			}

			}while((k<0 || k>19) || (l<0 || l>19));

	for(i=0; i<VISINA; i++){
		for(j=0; j<SIRINA; j++){
	
	if(mat[i][j]!=0)printf("*");
	else printf(" ");

		}
		printf("\n");
	}
				
				
	return 0;
}

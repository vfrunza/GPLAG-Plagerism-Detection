#include <stdio.h>
#define SIRINA 20

int main() {
	int i,j,n,k,b,a;
	int mat[SIRINA][SIRINA]={{0}};
	for(;;){
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
		if(n>0 && n<=10)break;
		else printf("Pogresan unos\n");
	}
	for(i=0;i<n;i++){
		for(;;){
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&a,&b);
		if(a<0 || a>19 || b<0 || b>19) printf("Pogresan unos\n");
		else break;
			}
			for(j=0;j<=SIRINA-1;j++){
				for(k=0;k<=SIRINA-1;k++){
					if(k==a && j==b)mat[k][j]=1;
				}
			}
		}
	for(j=0;j<=SIRINA-1;j++){
			for(k=0;k<=SIRINA-1;k++){
				if(mat[k][j]) printf("*");
				else printf(" ");
			}
			printf("\n");
	}
	return 0;
}

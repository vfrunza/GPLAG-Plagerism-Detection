#include <stdio.h>
#define VISINA 20
#define SIRINA 20

int main() {
	int matrica[VISINA][SIRINA]={0};
	int n,i,j,k,x,y;
	
	do { 
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	if (n>10 || n<=0) printf("Pogresan unos\n");
	} while (n<=0 || n>10);
	
	for (i=0;i<n;i++) {
		printf("Unesite %d. tacku: ",i+1);
			scanf("%d %d",&x,&y);
			if(x<0 || x>19 || y<0 || y>19){printf("Pogresan unos\n"); i--; continue;}
			matrica[x][y]=1;
				
				
				}
	
	for(i=0;i<SIRINA;i++) {
		for(j=0;j<VISINA;j++) {
		
			if (matrica[j][i]==1) printf("*");
			else printf(" ");
			
				
			
		}
		printf("\n");
	}
	
	
	return 0;
}

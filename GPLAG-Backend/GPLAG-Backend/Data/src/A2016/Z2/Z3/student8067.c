#include <stdio.h>

int main() {
	int n,M[20][20]={{0}},i,j,p,q;
	printf("Unesite broj tacaka: ");
	scanf("%d",&n); 
	while(n<=0 || n>10)
	{
		printf("Pogresan unos\n");
	
	printf("Unesite broj tacaka: ");
	scanf("%d",&n); 
	
	}
	for(i=0;i<n;i++) {
		 do{
		printf("Unesite %d. tacku: ",i+1);
	scanf("%d %d",&p,&q); 
		if(p<0||p>19||q<0||q>19) printf("Pogresan unos\n",i);
		} while(p<0||p>19||q<0||q>19);
	
	

	M[q][p]=1;
	}
	for(i=0;i<20;i++) {
		for(j=0;j<20;j++) {
			if(M[i][j]==0) printf(" ");
			else printf("*");
		}
		printf("\n");
	}
	

	
	return 0;
}

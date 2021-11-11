#include <stdio.h>

int main() {
	
	int n,i,j,a,b;
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	if(n<1 || n>10){printf("Pogresan unos\n");}
	}
	while(n<1 || n>10);
	
	int matrica [20][20];
	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			matrica[i][j]=0;
		}
	}
	
	for(i=0;i<n;i++){
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d", &a,&b);
		if(a<0 || a>19 || b<0 || b>19) {printf("Pogresan unos\n"); i--;}
		else {matrica[a][b]=1;}
		
	}
	
	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			if(matrica[j][i]==1) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	
	
		return 0;
}

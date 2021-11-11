#include <stdio.h>
#define v 20

int main() {
	int mat[v][v]={0},y[v],z[v],i,j,k,n,M1,M2;
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if(n<=0 || n>10)
		printf("Pogresan unos\n");
	}
	while(n<=0 || n>10);
	for(i=0;i<n;i++){
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d", &y[i]);
		scanf("%d", &z[i]);
	if(y[i]<0 || y[i]>=v || z[i]<0 || z[i]>=v){
		printf("Pogresan unos\n");
	i--;
	continue;}}
	M1=y[0];
	M2=z[0];
	for(i=0;i<n;i++){
		if(y[i]>M1)
		M1=y[i];
		if(z[i]>M2)
		M2=z[i];
	}
	for(k=0;k<n;k++){
		for(i=0;i<v;i++){
			for(j=0;j<v;j++){
				if(i==z[k] && j==y[k])
				mat[i][j]=1;
			}
			
		}
		
	}
	for(i=0;i<=M2;i++){
		for(j=0;j<=M1;j++){
			if(mat[i][j]==1)
		printf("*");
		else printf(" ");
	}
	printf("\n");
			
		}
	return 0;
}

#include <stdio.h>

int main() {
	int n=0; int max=0, max1=0;
	while(n>10 || n<=0){
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if(n>10 || n<=0){
			printf("Pogresan unos\n");
		}
	}
	
	char mat[20][20]={" "};
	int i,x[10]={-1},y[10]={-1};
	for(i=0; i<n; i++){
		unos:
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&x[i],&y[i]);
		if(x[i]<0||x[i]>19||y[i]<0||y[i]>19){printf("Pogresan unos\n");
		goto unos;
		}
		if(max<y[i])max=y[i];
		if(max1<x[i])max1=x[i];
		}
		
	
	for(i=0;i<n;i++){
		mat[y[i]][x[i]]='*';
	}
	int j;
	for(i=0;i<max+1;i++){
		for(j=0;j<max1+1;j++){
			if(mat[i][j]=='*')printf("*");
			else printf(" ");
			
		}
		printf("\n");
	}

	return 0;
}

#include <stdio.h>

int main() {
	int i,j,n,a,b,br=0,mat[20][20]={};
	
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	while(n>10 || n<1){
		printf("Pogresan unos\nUnesite broj tacaka: ");
		scanf("%d",&n);
	}
	
	while(br!=n){
		printf("Unesite %d. tacku: ",br+1);
		scanf("%d %d",&a,&b);
		if(a<0 || a>19 || b<0 || b>19){
			printf("Pogresan unos\n");
			continue;
		}
		br++;
		mat[b][a]=1;
	}
	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			if(mat[i][j]==1) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}

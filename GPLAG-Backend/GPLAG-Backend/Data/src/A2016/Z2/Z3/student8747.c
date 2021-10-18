#include <stdio.h>
#define VEL 20

int main(){
	int n,i,j,k,l;
	char mat[VEL][VEL];
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
		if(n>10 || n<=0){
			printf("Pogresan unos\n");
		}
	}while(n>10 || n<=0);
	
	for(i=0;i<VEL;i++){
		for(j=0;j<VEL;j++){
			mat[i][j]=' ';
		}
	}
	
	for(i=0;i<n;i++){
		do{
			printf("Unesite %d. tacku: ",1+i);
			scanf("%d%d",&k,&l);
			if(k>19 || l>19 || k<0 || l<0)
				printf("Pogresan unos\n");
		}while(k>19 || l>19 || k<0 || l<0);
		mat[l][k]='*';
	}
	
	for(i=0;i<VEL;i++){
			for(j=0;j<VEL;j++){
				printf("%c",mat[i][j]);
			}
			printf("\n");
		}
	return 0;
}
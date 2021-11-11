#include <stdio.h>

int main() {
	int mat[20][20]={0},i,x,y,n,k=1,t,u;
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
		if (n>10 || n<1) printf("Pogresan unos\n");
	}while(n>10 || n<1);
			for(i=0;i<n;i++){
				printf("Unesite %d. tacku: ", k);
				scanf("%d %d", &x, &y);
					if(x<0|| y<0 || x>=20 || y>=20){
					printf("Pogresan unos\n");
					i--;
					}else{
					k++;
					mat[x][y]=1;
					}
				}
		for(u=0;u<20;u++){
			for(t=0;t<20;t++){
				if(mat[t][u]==1) printf("*"); else printf(" ");	
			}
			printf("\n");
		}
	return 0;
}

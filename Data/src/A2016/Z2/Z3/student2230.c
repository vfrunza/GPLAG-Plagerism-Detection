#include <stdio.h>
#define VISINA 20
#define SIRINA 20

int main() {
	int n,mat[20][20],i,j;
	int x=0,y=0;

	do{
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	if(n<=0 || n>10) printf("Pogresan unos \n");
	} while(n<=0 || n>10);
	for(i=0;i<VISINA;i++){
		for(j=0;j<SIRINA;j++){
			mat[i][j]=0;
		}
	}
	for(i=0;i<n;i++){
		opet:	
		printf("Unesite %d. tacku: ",i+1);
	
		scanf("%d %d",&x,&y);
		//printf("x %d y %d ",x,y);
		if(x>=20 || x<0 || y>=20 || y<0){printf("Pogresan unos \n"); goto opet;}
    	//if(x<20 && x>=0 && y>=0 && y<20)
    	else mat[y][x]=1;
	}
	
	for(i=0;i<VISINA;i++){
		for(j=0;j<SIRINA;j++){
		if(mat[i][j]==1) printf("*");
		else printf(" ");
		}
		printf("\n");
	}
	return 0;
}

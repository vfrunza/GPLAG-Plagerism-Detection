#include <stdio.h>


int main() {
	int i,j,n,mat[25][25]={{0}},b=0,x,y;
	
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
		if(n>10 || n<=0){printf("Pogresan unos \n");}
		
		
	}while(n>10 || n<=0);
	
	
	for(b;b<n;b++)
	{
		printf("Unesite %d. tacku: ",b+1);
		scanf("%d %d",&x,&y);
		if(x<0 || x>19 || y<0 || y>19){printf("Pogresan unos\n");b--;}
		else{mat[y][x]=1;}
	}
	b=0;
	
	for(i=0;i<20;i++){
		
		for(j=0;j<20;j++){
			if(mat[i][j]==1){printf("*");}
			else{printf(" ");}
			
		}
		printf("\n");
	
	}
		
		


	
	
	return 0;
}

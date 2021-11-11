#include <stdio.h>

int main() {
	int broj, x, y;
	int i, j, k;
	int mat[20][20];
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d", &broj);
		if((broj<=0)||(broj>10)) printf("Pogresan unos\n");
	}while ((broj<=0)||(broj>10));
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			mat[i][j]=0;
		}
	}
	for(k=0;k<broj;k++){
		
		do{
			printf("Unesite %d. tacku: ", k+1);
			scanf("%d %d",&x,&y);
			if(((x<0)||(x>19))||((y<0)||(y>19))) printf("Pogresan unos\n");
		}while(((x<0)||(x>19))||((y<0)||(y>19)));
		
		
		for(i=0;i<20;i++){
			for(j=0;j<20;j++){
				if((i==y)&&(j==x)) mat[i][j]=1;
				
			}
		}
	}
	for(i=0;i<20;i++){
			for(j=0;j<20;j++){
				if(mat[i][j]==1) printf("*");
				else if(mat[i][j]==0) printf(" ");
			}
			printf("\n");
		}

    return 0;
}
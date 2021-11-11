#include <stdio.h>
#define sirina 20
#define duzina 20

int main() {
	int i,j,x,y,b, mat[sirina][duzina]={{0}};
	
	while(1){
	printf("Unesite broj tacaka: ");
	scanf("%d", &b);
	if(b<=10 && b>0)  break;
	
	if(b>10 || b<=0) printf("Pogresan unos\n");
	
	}
	
	for(i=1; i<=b; i++){
	
	printf("Unesite %d. tacku: ", i);
	scanf("%d %d", &x,&y);

	if(x<0 || x>19 || y<0 || y>19) 
	{
		printf("Pogresan unos\n");
		i--;
	}
	else mat[y][x]=1;
	}

	for(i=0; i<sirina; i++){
	for(j=0; j<duzina; j++){
		
	if(mat[i][j]==1) printf("*");
	else printf(" ");
	}
	printf("\n");
	
	}
	
	return 0;
} 

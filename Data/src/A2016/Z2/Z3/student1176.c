#include<stdio.h>

int main(){
	int x, y, i, j, n, br=0;
	char mat[20][20];
	for(i=0;i<20;i++)
		for(j=0;j<20;j++)
			mat[i][j]=' ';
	
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if(n<=0 || n>10)
			printf("Pogresan unos\n");
		
	} while(n<=0 || n>10); 
	for(i=0; i<n; i++){ 
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &x, &y);
		if(x<0 || x>19 || y<0 || y>19){
			printf("Pogresan unos\n");
			i--;
			continue;
		}    
		mat[x][y]='*';
	} 
	for(j=0; j<=19; j++){
		for(i=0;i<=19; i++){ 
			if(mat[i][j]=='*'){printf("%c", mat[i][j]); br++;}
			else printf(" "); 
		}  
	if (br==n) return 0;
	printf("\n");
	}
	return 0;
}
#include <stdio.h>
int main(){
int mat[20][20]={0},x,y,n,j,i;
	int k;
//Unos tacaka
do{
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	if(n<=0 || n>10)
		printf("Pogresan unos\n");

}while(n<=0 || n>10);
//Unos koordinata
for(i=0;i<n;i++){
	printf("Unesite %d. tacku: ", i+1);
	scanf("%d %d", &x, &y);
	if(x<0 || x>19 || y<0 || y>19){
		printf("Pogresan unos\n");
		i--;
		continue;
	}
	mat[y][x]=1;
}
//Iscrtavanje tacaka
for(i=0;i<20;i++){
	for(j=0;j<20;j++){
		if(mat[i][j]==1)
			printf("*");
		else
			printf(" ");
	}
	
	printf("\n");
}

return 0;	
}
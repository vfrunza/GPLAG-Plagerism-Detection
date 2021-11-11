#include <stdio.h>
#define horizontalno 20
#define vertikalno 20
int main() {
	int mat [vertikalno][horizontalno]={0},i,a,b,j,brtacaka;
do{	printf("Unesite broj tacaka: ");
	scanf("%d",&brtacaka);
	if(brtacaka<=0||brtacaka>10) 
	printf("Pogresan unos\n"); } while(brtacaka>10||brtacaka<=0);
	

	
 for(i=0;i<brtacaka;i++){
 
 		printf("Unesite %d. tacku: ",i+1);
 		scanf("%d",&a);
 	scanf("%d",&b);
 	if(a<0||a>19||b<0||b>19){ printf("Pogresan unos\n");
 	i--;
 	continue;
 }
 	mat[a][b]=1;}
 
 for(j=0;j<vertikalno;j++){
 	for(i=0;i<horizontalno;i++){
 		if( mat[i][j]==1) printf("*");
 		else printf(" ");}
 		printf("\n");
 }
 

	return 0;
}

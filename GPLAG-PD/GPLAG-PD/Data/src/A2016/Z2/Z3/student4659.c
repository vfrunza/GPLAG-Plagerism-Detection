#include <stdio.h>

int main() {
	int i,j,matrica[20][20]={{0}},x,y,n;
do{	
	
	printf("Unesite broj tacaka: ");
    scanf("%d",&n);
    if(n>10 || n<=0){printf("Pogresan unos\n");}
    }while(n>10 || n<=0);
	
for(i=0;i<n;i++){
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&x,&y);
		if(x<0 || x>19 || y<0 || y>19){printf("Pogresan unos\n");
		i--;
		continue;}
		matrica[x][y]=1;}
for(i=0;i<20;i++){
    for(j=0;j<20;j++){
      if (matrica[j][i]==1) printf("*");
      else printf(" ");
}		printf("\n");}
		 
	return 0;
}

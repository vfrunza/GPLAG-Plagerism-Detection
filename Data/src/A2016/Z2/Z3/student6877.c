#include <stdio.h>

int main() {
	char matrica[20][20];
	int n,i,j,x,y;
	do
	{
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
		if (n<1 || n>10) printf("Pogresan unos\n");
	}
	while (n<1 || n>10);
	for (i=0;i<20;i++)
	{
	    for(j=0;j<20;j++)
	    {
	    	matrica[i][j]=' ';
	    }
	}   
	for(i=0;i<n;i++)    
	{
	  do
	    {
	    	printf("Unesite %d. tacku: ",i+1);
	    	scanf("%d %d", &x, &y);
	    	if (x<0 || x>19 || y<0 || y>19) printf("Pogresan unos\n");
	    }while(x<0 || x>19 || y<0 || y>19);
	    matrica[y][x]='*';
	}
	for(i=0;i<20;i++)
	   {
	   	for(j=0;j<20;j++)
	   	{
	   		printf("%c",matrica[i][j]);
	   	}
	   	printf("\n");
	   }
	   	
	   	
	   
	return 0;
}

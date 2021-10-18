#include <stdio.h>

int main() {
	int i=0,j=0,a=0,b=0,br_tacaka=0;
	char mat[20][20];
	for(i = 0; i < 20; i++)
	{
	
		for(j = 0; j < 20; j++)
		{
			
			mat[i][j]=' ';
		}
	}
	greskica:
	printf("Unesite broj tacaka: ");
	scanf("%d", &br_tacaka);
	if(br_tacaka<=0 || br_tacaka>10){
		printf("Pogresan unos\n");
		goto greskica;
	}
	
	for(i = 1; i < br_tacaka+1; i++)
	{
		greska: 
		printf("Unesite %d. tacku: ",i);
			scanf("%d %d",&b, &a);
			if(a<0 || a>=20 || b<0 || b>=20)
			{
				printf("Pogresan unos\n");
				goto greska;
				
			}
	    mat[a][b] = '*';
	}
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			   printf("%c",mat[i][j]);
		}
		printf("\n");
	}
	
	
	return 0;
}

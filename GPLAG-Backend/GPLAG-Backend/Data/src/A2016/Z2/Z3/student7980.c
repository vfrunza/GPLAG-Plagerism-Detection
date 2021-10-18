#include <stdio.h>
#define visina 20
#define sirina 20
int main() {
	int i,j,k,br1,br2,t;
	char mat[visina] [sirina];
	
	for(i=0;i<visina;i++)
		{
			for(j=0;j<sirina;j++)
		{
			mat[i][j]=" ";
		}
		}






	LABEL: printf("Unesite broj tacaka: ");
	scanf("%d",&t);
	if(t>10 || t<=0)
	{	printf("Pogresan unos\n");
		goto LABEL;
	}
	for(k=0; k<t; k++)
	{	printf("Unesite %d. tacku: ",k+1);
		scanf("%d %d ",&br1,&br2);
		if(br1<0 || br1>19 || br2<0 || br2>19)
		{
			printf("Pogresan unos\n");
			k--;
			
		}
	else {
	mat[br2] [br1]='*';
	}
}
		
		for(i=0;i<visina;i++)
		{for(j=0;j<sirina;j++)
		if  (mat[i][j]!='*')
		{printf(" ");}
		
		else {
		
		printf("%c",mat[i] [j]);
		}
		printf("\n");
	

		}
		
	
	return 0;
}

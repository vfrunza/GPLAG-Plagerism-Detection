#include <stdio.h>

int main() 
{
	int N=0,i,j;
	/*Ispit uslova*/
	printf("Unesite broj N: ");
	do
	{
		scanf("%d",&N);
		if(N%4==0 && N>=8)
		{
			printf("\n");
			break;
		}
		printf("Neispravno N!\n");
		printf("Unesite broj N: ");
	}while( N%4!=0 || N<8);
	/*Crtanje*/
		for(i=0;i<(N/2);i++)
		{
			/* Crtanje iksa */
			for(j=0;j<(N/2);j++)
			{
				if(i==j) { printf("\\"); }
				else if (i+j==(N/2)-1) { printf("/"); }
				else { printf(" "); }
			}
				
			/*Crtanje prvog kvadrata*/
			for(j=0;j<(N/2);j++)
			{
				if ( (i==0 && j==0) || (i==0 && j==((N/2)-1)) || (i==((N/2)-1) && j==0) || (i==((N/2)-1) && j==((N/2)-1))) { printf("+"); }
				else if (i==0 || i==(N/2)-1) { printf("-"); }
				else if (j==0 || j==(N/2)-1) { printf("|"); }
				else printf(" ");
			}
		printf("\n");
		}
	
		for(i=0;i<(N/2);i++)
		{
			/*Crtanje drugog kvadrata*/
			for(j=0;j<(N/2);j++)
			{
				if ( (i==0 && j==0) || (i==0 && j==((N/2)-1)) || (i==((N/2)-1) && j==0) || (i==((N/2)-1) && j==((N/2)-1))) { printf("+"); }
				else if (i==0 || i==(N/2)-1) { printf("-"); }
				else if (j==0 || j==(N/2)-1) { printf("|"); }
				else printf(" ");
			}
			for(j=0;j<(N/2);j++)
			{
				if ( (j==(N/4)-1 || j==(N/4)) && (i==(N/4)-1 || i==(N/4)) ) { printf("+"); }
				else if ( (j<(N/4)-1 || j>(N/4)) && (i==(N/4)-1 || i==(N/4)) ) { printf("-"); }
				else if ( j==(N/4)-1 || j==(N/4) ) { printf("|"); }
				else printf(" ");
			}
		printf("\n");
		}
	return 0;
}

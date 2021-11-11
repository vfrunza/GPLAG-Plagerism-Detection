#include <stdio.h>
#include <math.h>

int main() 
{
	
int redovi, kolone, sk, i=1, j=1, k=1, l=1, m=0 ;


do	
	{
	printf("Unesite broj redova: ");
	scanf ("%d", &redovi);
	}
while ((redovi<=0)||(redovi>10));

do 
	{
	printf("Unesite broj kolona: ");
	scanf ("%d", &kolone);
	}
while ((kolone<=0)||(kolone>10));

do
	{
	printf("Unesite sirinu jedne kolone: ");
	scanf ("%d", &sk);
	}
while ((sk<=0)||(sk>10));



for (m=0; m<redovi; m++)
{

	printf ("+");
		for (j=1 ; j<=kolone ; j++)
		{
			for (i=1 ; i<=sk ; i++) 
			{
				printf ("-"); 
			}
			printf ("+");
			
		}
		printf ("\n");
		
	printf ("|");
		for (l=1; l<=kolone ; l++)
		{
			for (k=1 ; k<=sk ; k++)
			{
				printf (" ");
			}
			printf ("|");
		}
		printf ("\n");

}
	
	
	printf ("+");
		for (j=1 ; j<=kolone ; j++)
		{
			for (i=1 ; i<=sk ; i++) 
			{
				printf ("-"); 
			}
			{
			printf ("+");
			}}
			
			
return 0;
}
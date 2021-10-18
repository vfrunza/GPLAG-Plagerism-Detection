#include <stdio.h>

int main() {
	
int N, i=1, j=1;
	
	do
	{
		printf ("Unesite broj N: ");
		scanf ("%d", &N);
		if(N%4!=0 || N<8)
		printf("Neispravno N!");
		printf("\n");
	}
	
	while ((N%4!=0)||(N<8));
	
	
for (i=1 ; i<=N ; i++)
{
	for (j=1 ; j<=N ; j++)
	{
		if (i<=(N/2) && j<=(N/2))
		{
			if (i==j)
			printf ("\\");
			if (j==((N/2)+1-i))
			printf ("/");
			if ((i!=j)&&(j!=((N/2)+1-i)))
			printf (" ");
		}
		if (i>(N/2) && j<=(N/2))
		{
			if ((i==((N/2)+1))||(i==N))
			{
				if (j==1 || j==(N/2))
				printf ("+");
				else 
				printf ("-");
			}
			else
			{
				if (j==1 || j==(N/2))
				printf ("|");
				else 
				printf (" ");
			}
			}
		if (i<=(N/2) && j>(N/2))
		{
			if (i==1 || i==(N/2))
			{
				if (j==(N/2)+1|| j==N)
				printf ("+");
				else
				printf ("-");
			}
			else
			{
				if (j==(N/2)+1 || j==N)
				printf ("|");
				else 
				printf (" ");
			}
		}
		if (i>(N/2) && j>(N/2))
		{
			if (i==(N/4)*3 || i==(N/4)*3+1)
			{
				if (j==(N/4)*3 || j==(N/4)*3+1)
				printf ("+");
				else 
				printf ("-");
			}
			else
			{
				if (j==(N/4)*3 || j==(N/4)*3+1)
				printf ("|");
				else 
				printf (" ");
			}
		}
	}
	printf ("\n");
	}
	return 0;
	}
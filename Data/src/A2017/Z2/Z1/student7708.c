#include <stdio.h>
#include <math.h>


int main() {
	int N,i,j,a,b;
	

	printf("Unesite broj N: "); 
	scanf("%d", &N);
		
	if(N%4!=0 || N<8) printf("Neispravno N!\n");
	else printf("\n");
	while (N%4!=0 || N<8)
	{
		printf("Unesite broj N: ");
		scanf("%d", &N);
		if(N%4!=0 || N<8) printf("Neispravno N!\n");
		else printf("\n");
	}
	
	a=N/2;
	b=N/4;
	for (i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			if(i<a)
				{
				if(j<a)
				{
					if(i==j) printf("\\");
					else if (i+j==a-1) printf("/");
					else printf(" ");
				}
			
				else
				{
					if(((i==0 && (j==a || j==N-1)) || (i==a-1 && (j==a || j==N-1)))) printf("+");
					else if ((i==0 || i==(a-1))) printf("-");
					else if (j==a || j==N-1) printf("|");
					else printf(" ");
				}
				}
				else
				{
					if(j<a)
					{
						if((i==a || i==N-1) && (j==0 || j==a-1)) printf("+");
						else if(i==a || i==N-1) printf("-");
						else if (j==0 || j==a-1) printf("|");
						else printf(" ");
					}
					
					else
					{
						if(j==N-b || j==N-b-1)
						{
							if(i==N-b || i==N-b-1) printf("+");
							else printf("|");
						}
						else
						{
							if(i==N-b || i==N-b-1) printf("-");
							else printf(" ");
						}
					}
				}
				
		}
		printf("\n");
	}
	
	return 0;
	
}

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int N=2;
	do
	{
		printf("Unesite broj N:");
		scanf("%d",&N);
		if(N%4!=0 || N<8)
			printf(" Neispravno N!");
		printf("\n");
	}while(N%4!=0 || N<8);
	int i=0,j=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(j<(N/2) && i<(N/2))  
			{
				if(i==j) printf("\\");
				else if ( j==((N/2)-i-1))	printf("/");
				else printf(" ");		
			}
			if(j>=(N/2) && i<(N/2))
			{
				if(((j==(N/2) || j==(N-1)) && i==0) || ((j==(N/2) || j==(N-1)) && i==((N/2)-1))) printf("+");
				else if(i==0 || i==((N/2)-1)) printf("-");
				else if(j==((N/2)) || j==(N-1)) printf("|");
				else(printf(" "));
			}
			if(j<(N/2) && i>=(N/2))
			{
				if(((j==((N/2)-1) || j==0) && i==(N/2)) || ((j==((N/2)-1) || j==(0)) && i==(N-1))) printf("+");
				else if(i==(N/2) || i==(N-1)) printf("-");
				else if(j==((N/2)-1) || j==(0)) printf("|");
				else(printf(" "));
			}
			if(j>=(N/2) && i>=(N/2))
			{
				if((i==(N-(N/4)) || i==(N-(N/4)-1)) && (j==(N-(N/4)) || j==(N-(N/4)-1))) printf("+");
				else if(i==(N-(N/4)) || i==(N-(N/4)-1)) printf("-");
				else if(j==(N-(N/4)) || j==(N-(N/4)-1)) printf("|");
				else(printf(" "));
			}
			
		}
		printf("\n");
	}
	return 0;
}
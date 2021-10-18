#include <stdio.h>

int main() {

int N, i, j;

/*unos broja N*/
do{
	printf("Unesite broj N: ");
	scanf("%d", &N);
	if(N<8 || N%4!=0)
	printf("Neispravno N!\n");
	printf("\n");
}while(N<8 || N%4!=0);

/*prva dva oblika*/
for(i=0; i<N/2; i++)
{
	for(j=0; j<N/2; j++)
	{
		if(i==j) printf("\\"); /*dijagonala */
		
		else if(i>=0 && j==(N/2) -1-i)
		printf("/");
		
		else printf(" ");
	}
	
	for(j=N/2; j<N; j++)
	{
		if((i==0 || i==(N/2)-1) && (j==N/2 || j==N-1)) /*plusevi*/
		printf("+");
		
		else if((i==0 || i==(N/2)-1) && (j>(N/2) || j<(N-1)))/*minusi*/
		printf("-");
		
		else if((i>0 && i<(N/2)-1) && (j==N/2 || j==N-1)) /*linije*/
		printf("|");
		
		else printf(" "); /*ostalo svuda ubaciti razmake*/
	}
	printf("\n");
}

/*donji dio slike*/
for(i=N/2; i<N; i++)
{
	for(j=0; j<N/2; j++)
	{
		if((i==N/2 || i==N-1) && (j==0 || j==N/2-1))/*plusevi*/
		printf("+");
		
		else if((i==N/2 || i==N-1) && (j>0 && j<N/2-1))/*minusi*/
		printf("-");
		
		else if((i>N/2 && i<N-1) && (j==0 || j==N/2-1))/*linije*/
		printf("|");
		
		else printf(" "); /*preostali prazan prostor*/
		
		
	}
	
	for(j=N/2; j<N; j++)
	{
	  if((i==3*N/4-1 || i==3*N/4) && (j==3*N/4-1 || j==3*N/4))/*plusevi u sredini*/
	  printf("+");
	  
	  else if(i==3*N/4-1 || i==3*N/4)
	  printf("-");
	  
	  else if(j==3*N/4-1 || j==3*N/4)
	  printf("|");
	  
	  else printf(" ");
	  
    }
	
	
	
	printf("\n");
}


return 0;
}

#include <stdio.h>

int main() {
	int N, i, j, k;
	
	
	do{
		printf("Unesite broj N: ");
		scanf("%d", &N);
		if(N%4!=0 || N<8) printf("Neispravno N!\n");
	} while(N%4!=0 || N<8);

	k=N/2;
	printf("\n");
	
	for(i=0; i<k; i++)
	{
		for(j=0; j<k; j++)
		{
			if(i==j) printf("\\");
			else if(i==k-j-1) printf("/");
			else printf(" ");
		} 
	
		for(j=0; j<k; j++)
		{
			if((i==0 || i==k-1) && (j==0 || j==k-1)) printf("+");
			else if(i==0 || i==k-1) printf("-");
			else if(j==0 || j==k-1) printf("|");
			else printf(" ");
		} 	
			
		printf("\n");
	}
	
	
	for(i=0; i<k; i++)
	{
		for(j=0; j<k; j++)
		{
			if((i==0 || i==k-1) && (j==0 || j==k-1)) printf("+");
			else if(i==0 || i==k-1) printf("-");			
			else if(j==0 || j==k-1) printf("|");
			else printf(" ");
		} 	
			
		for(j=0; j<k; j++)	
		{
			if((i==k/2 || i==(k/2)-1) && (j==k/2 || j==(k/2)-1)) printf("+");
			else if (i==k/2 || i==(k/2)-1) printf("-");
			else if(j==k/2 || j==(k/2)-1) printf("|");
			else printf(" ");
		}
		
		printf("\n");
	}
	
	
	
	return 0;
}

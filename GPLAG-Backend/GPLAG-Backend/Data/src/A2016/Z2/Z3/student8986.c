#include <stdio.h>

int main() {
	int n, i, j, k;
	int mat[10][2];
	int ima;
	
	do
	{
		printf("Unesite broj tacaka: ");
			scanf("%d", &n);
				if(n<=0 || n>10) 
					printf("Pogresan unos\n");
	} 	while(n<=0 || n>10);
	
	for(i=0; i<n; i++) 
	{
			printf("Unesite %d. tacku: ", i+1);
			scanf("%d%d", &mat[i][0], &mat[i][1]);
			if(mat[i][0] < 0 || mat[i][0] > 19 || mat[i][1] < 0 || mat[i][1] > 19) {
				printf("Pogresan unos\n");
				i--;
			}
	}
	
	for(i=0; i<20; i++)
	{
		for(j=0; j<20; j++)
		{
			ima=0;
			for(k=0; k<n; k++)
			{
				if(i==mat[k][1] && j==mat[k][0])
				{
					printf("*");
					ima=1; break;
				}
					if(ima==1) break;
			}
				if(ima==0) printf(" ");
		}
			printf("\n");
	}
	
	return 0;
}
#include <stdio.h>

int main() {
	
	int br_t, i, j, m, n;
	int mat[20][20];
	do
	{
		printf("Unesite broj tacaka: ");
		scanf("%d", &br_t);
		if(br_t>10 || br_t<=0)
		{
			printf("Pogresan unos\n");
			continue;
		}
		break;
	}while(1==1);
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			mat[i][j] = 0;
		}
	}
	for(i=0;i<br_t;i++)
	{
		do{
		    printf("Unesite %d. tacku: ", i+1);
		    scanf("%d %d", &m, &n);
		    if(m<0 || m>19 || n<0 || n>19)
		    {
			    printf("Pogresan unos\n");
			    continue;
		    }
		    mat[n][m] = 1;
		    break;
		}while(1==1);
	}
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			if(mat[i][j] == 0) printf(" ");
			else printf("*");
		}
		printf("\n");
	}
	return 0;
}

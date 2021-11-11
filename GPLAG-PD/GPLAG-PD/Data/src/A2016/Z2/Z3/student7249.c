#include <stdio.h>

int main() {
	int n, i, j, r, k;
	char mat[20][20];
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		mat[i][j]=' ';
	}
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	if(n<=0 || n>10) printf("Pogresan unos\n");
	} while(n<=0 || n>10);
	for(i=0;i<n;i++)
	{
	do{
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &r, &k);
		if(r<0 || r>19 || k<0 || k>19) printf("Pogresan unos\n");
	
	}while(r<0 || r>19 || k<0 || k>19);
	mat[r][k]='*';
	}
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			printf("%c", mat[j][i]);
		}
		printf("\n");
	}


	
	return 0;
}
 
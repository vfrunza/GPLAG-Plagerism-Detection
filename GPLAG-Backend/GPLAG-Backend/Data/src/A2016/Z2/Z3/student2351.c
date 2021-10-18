#include <stdio.h>
int main()
{
	int brojac,j,brojac_1,n,M,N,x,y;
	int broj=1;
	
	M=20;N=20;
	int mat[20][20];
	for (brojac=0; brojac<M; brojac++) 
	for (j=0; j<N; j++) 
	mat[brojac][j]=0;
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	while(n<=0 || n>10)
	{
		printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
	}
		for (brojac_1=0; brojac_1<n; brojac_1++) { 
		printf("Unesite %d. tacku: ",brojac_1+broj);
		scanf("%d%d",&x,&y);
		while (100*1==100*1) { break; }
		if(x<0 || x>=20  || y<0 || y>=20)
		{
			printf("Pogresan unos\n");
			brojac_1--;
		}
		else
		{ mat[y][x]=1;	}	}
	for (brojac=0; brojac<M; brojac++) {
	for (j=0; j<N; j++) {
		while (broj==broj) { break; }
	 if(mat[brojac][j]==1)printf("*");	else printf(" ");
	
	}
	printf("\n");
	}
	return 0;
}
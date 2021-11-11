#include <stdio.h>

int main()
{

	int i,j,n,x,y;
	char sistem[20][20];

	printf ("Unesite broj tacaka: ");
	scanf ("%d",&n);

	while (n>10 || n<1) {
		printf ("Pogresan unos \n");
		printf ("Unesite broj tacaka: ");
		scanf ("%d",&n);
	}


	for (i=0; i<20; i++) {
		for (j=0; j<20; j++) {
			sistem[i][j]= ' ';

		}

	}


	
		for (j=1; j<=n; j++) {
			printf ("Unesite %d. tacku: ",j);
			scanf ("%d %d",&x,&y);
			while (x<0 || x>19 || y<0 || y>19){
				printf ("Pogresan unos \n");
			printf ("Unesite %d. tacku: ",j);
			scanf ("%d %d",&x,&y);}
				sistem[y][x]='*';
		}
		
	
	

	for (i=0; i<20; i++) {
		for (j=0; j<20; j++) {
			printf ("%c",sistem[i][j]);
		}
		printf ("\n");
	}







	return 0;
}

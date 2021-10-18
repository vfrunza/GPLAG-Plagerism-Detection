#include <stdio.h>


int main () {
	char mat[20][20];
	int i,j,n,x,y;
	for (i=0;i<20;i++) { 
		for (j=0;j<20;j++) {
			mat[i][j] = ' ';
		}
	}
	greska_1:printf ("Unesite broj tacaka: ");
	scanf ("%d",&n);
	if (n<=0 || n>10) { 
		printf ("Pogresan unos\n"); 
		goto greska_1; 
		}
	for (i=1;i<=n;i++) {
		greska_2:printf ("Unesite %d. tacku: ",i);
		scanf ("%d %d",&x,&y);
		if (x<0 || x>=20 || y<0 || y>=20) {
			printf ("Pogresan unos\n"); 
		 goto greska_2;
		}
		mat[y][x]='*'; 
		}
	
	for (i=0;i<20;i++) {
		for (j=0;j<20;j++) {
			printf ("%c",mat[i][j]);
		}
		printf ("\n");
	}
	
	
	return 0;
}
	
	
	
	
	

	
	
			
			
			
			
		

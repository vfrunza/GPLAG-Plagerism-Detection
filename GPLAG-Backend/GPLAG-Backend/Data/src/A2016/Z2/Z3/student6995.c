#include <stdio.h>

int main() {
	int brT, x, y ,i, j ; 
	char niz[20][20]={'  '};
	//printf("Unesite broj tacaka: ");
	ponoviii:
		printf("Unesite broj tacaka: ");
		scanf ("%d",&brT);
		if (brT<=0 || brT>10) {
			printf ("Pogresan unos\n");
			goto ponoviii;
		}
	ponovi:
	for ( i=0; i<brT; i++ ) {
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d",&x);
		scanf("%d", &y);
		if (x<0 || x>20 || y<0 || y>20) {
			printf ("Pogresan unos\n");
			goto ponovi;
		}
		niz[y][x]='*';
		
		
	}
	for(i=0;i<20;i++){
		for (j=0; j<20; j++) {
			//printf("%c",niz [i][j]);
			if (niz[i][j]=='*') printf ("*" );
			else printf (" ");
		}
		printf("\n");
	}
	
	
	;
	return 0;
}

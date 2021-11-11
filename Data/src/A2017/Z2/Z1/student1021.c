#include <stdio.h>

int main() {
	int cio_broj;
	int i,j;
	int brojac=0;
	do {
		brojac++;
		if(brojac>=2) printf(" Neispravno N!\n");
	printf("Unesite broj N:");
	scanf("%d",&cio_broj);
	} while(cio_broj%4!=0 || cio_broj<8);
	printf("\n");
	for( i=0;i<cio_broj;i++){
		for( j=0;j<cio_broj;j++) {
			if( i==j && i<(cio_broj/2) ) printf("\\");
			else if( i+j == (cio_broj/2)-1 ) printf("/");
			else if ( i==0 && j == cio_broj/2 || i==0 && j==cio_broj-1 || i==cio_broj/2 && j==0 || i==cio_broj/2 && j==(cio_broj/2)-1 || i==cio_broj-1 && j==0 || i==(cio_broj/2)-1 && j==cio_broj/2 || i==(cio_broj/2)-1 && j==cio_broj-1 || i==cio_broj-1 && j==(cio_broj/2)-1) printf("+");
			else if( i==0 && j>=cio_broj/2 || i==(cio_broj/2)-1 && j>=cio_broj/2 || i==cio_broj/2 && j<cio_broj/2 || i==cio_broj-1 && j<cio_broj/2) printf("-");
			else if( j==0 && i>=cio_broj/2 || j==(cio_broj/2)-1 && i>=cio_broj/2 || j==cio_broj/2 && i<cio_broj/2 || j==cio_broj-1 && i <cio_broj/2) printf("|");
			else if( i==(((cio_broj/4)*3)-1) && i==j || j==((cio_broj/4)*3) && i==j || i==(((cio_broj/4)*3)-1) &&(j-i==1) || i==((cio_broj/4)*3) &&(i-j==1) ) printf("+");
			else if(i>=cio_broj/2 && (j==((cio_broj/4)*3)-1 || j==((cio_broj/4)*3))) printf("|");
			else if(j>=cio_broj/2 && (i==((cio_broj/4)*3)-1 || i==((cio_broj/4)*3))) printf("-");
			else printf(" ");
		}
		printf("\n");
		
	}
	return 0;
}

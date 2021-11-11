#include <stdio.h>

int main() {
	int i,j,N;
	/*ogranicenje iz teksta zadatka za unos*/
	int temp = 0;
	do{
		printf("Unesite broj N: ");
		scanf("%d",&N);
		if(temp = N<8 || N%4!=0)
			printf("Neispravno N!\n");
	}while(temp);
	 
	 /*velika for petlja po redovima*/
	printf("\n");
	for(i=0; i<N; i++){
		/*jos jedna velika for petlja po kolonama*/
		for(j=0; j<N; j++){
			/*print "X"*/
			if((i<N/2)&&(j<N/2)&&i==j) printf("\\");
			else if((i<N/2)&&(j<N/2)&&i==((N-1)/2 - j)) printf("/"); 
			else if((i<N/2)&&(j<N/2)) printf(" ");
			/* print "kvadar" u gornjem desnom uglu*/
			if((i<N/2)&&(j>=N/2)){
				if((i==0 || i==(N/2 - 1))&& (j==N/2 || j==(N-1)))  printf("+");
				else if((i==0 || (i==N/2 - 1))&& (j>N/2 && j<(N-1))) printf("-");
				else if((i!=0 && i!=(N/2 - 1))&&(j==N/2 || j==(N-1))) printf("|");
				else printf(" ");
			}
			 /* print kvadar u donjem lijevom uglu*/
			if((i>=N/2)&&(j<N/2)){
				if((i==N/2 || i==N-1)&&(j==0 || j==(N/2 -1))) printf("+");
				else if((i==N/2 || i==N-1)&&(j>0 && j<(N/2 -1))) printf("-");
				else if((i>N/2 && i<N-1)&&(j==0 || j==(N/2 -1))) printf("|");
				else printf(" ");
			}
			/* print "+"*/
			if((i>=N/2)&&(j>=N/2)){
				if((i==(3*N/4 -1))&&((j==(3*N/4 -1)||(j==(3*N/4))))|| (i==3*N/4)&&((j==(3*N/4 -1)||(j==(3*N/4))))) printf("+");
				else if((i==(3*N/4 -1))&&((j<(3*N/4 -1))||(j>3*N/4))|| (i==3*N/4)&&((j<(3*N/4 -1))||(j>3*N/4))) printf("-");
				else if((i>=N/2)&&((j==(3*N/4 -1))||(j==3*N/4))|| (i>(N/2+2))&&((j==(3*N/4 -1))||(j==3*N/4))) printf("|");
				else printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}

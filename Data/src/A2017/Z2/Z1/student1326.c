#include <stdio.h>

int main() {
	int N, i, j;
	do {
	printf("Unesite broj N: ");
	scanf("%d", &N);
	if(N%4==0 && N>=8){
		printf("\n");
	}
	else if(N%4!=0 || N<8){
		printf("Neispravno N!\n");}
	} while (N%4!=0 || N<8);
	
	/*Za x*/
	for(i=0; i<N; i++){
	for(j=0; j<N; j++){
	if( i==j && i<N/2 && j<N/2){
				printf("\\");}
	else if(i<N/2 && j==(N/2)-1-i && j<N/2)	{
	printf("/");}
	
	/*za kvadrate(pravougaonike)*/
	else if((i==0 && (j==(N/2)  || j==N-1)) || (i==(N/2) && (j==0 || j==(N/2)-1)) || (i==N-1 && (j==0 || j==(N/2)-1)) || (i==(N/2)-1 && (j==N/2 || j==N-1))){
		printf("+");}
	else if((i==0 && (j>N/2 && j<N-1)) || (i==(N/2)-1 && (j>N/2 && j<N-1)) || (i==N/2 && (j>0 && j<(N/2)-1)) || (i==N-1 && (j>0 && j<(N/2)-1))){
		printf("-");}
	else if(((i>0 && i<((N/2)-1)) && (j==(N/2) || j==(N-1))) || ((i>(N/2) && i<(N-1)) && (j==0 || j==((N/2)-1)))){
		printf("|");}
		
	/*Za zadnji dio*/
	else if((i==(N-(N/4)) || i==(N-(N/4)-1)) && (j==(N-(N/4)) || j==(N-(N/4)-1))){
	printf("+");}
	else if((i==(N-(N/4)) || i==(N-(N/4)-1)) && ((j>=N/2 && j<(N-(N/4)-1)) || (j>(N-(N/4)-1) && j<=(N-1)))){
		printf("-");}
	else if(((i>=N/2 && i<(N-(N/4)-1)) || (i>(N-(N/4)) && i<=(N-1))) && (j==(N-(N/4)) || j==(N-(N/4)-1))){
		printf("|");
	}
		else { printf(" ");
		}
	} printf("\n");
	}
	return 0;
}

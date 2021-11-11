#include <stdio.h>
#define BROJ_REDOVA 20
#define BROJ_KOLONA 20

int main() {
	
	int i,j,k,broj_tacaka,a,b;
	char A[BROJ_REDOVA][BROJ_KOLONA];
	LOOP1:
	printf("Unesite broj tacaka: ");
	scanf("%d",&broj_tacaka);
	if(broj_tacaka<=0 || broj_tacaka>10)
	{
		printf("Pogresan unos\n");
		goto LOOP1;
	}
	
	for(i=0; i<BROJ_REDOVA; i++){
	 for(j=0; j<BROJ_KOLONA; j++){
	 	A[i][j]=' ';
	 }
	 
	}
	for(k=1; k<=broj_tacaka; k++)
	{
		LOOP2:
		printf("Unesite %d. tacku: ",k);
     	scanf("%d %d",&a,&b);
     	if(a<0 || a>19 || b<0 || b>19)
     	{
     		printf("Pogresan unos\n");
     		goto LOOP2;
     	}
     	A[a][b]='*';
	}
	for(i=0;i<BROJ_REDOVA;i++){
		for(j=0;j<BROJ_KOLONA;j++){
			printf("%c",A[j][i]);
		}
		printf("\n");
	}

	return 0;
}

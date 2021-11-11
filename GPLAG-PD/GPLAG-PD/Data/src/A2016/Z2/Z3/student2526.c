#include <stdio.h>

int main() {
	int bt,i,j,tacke;
	char niz[20][20];
	printf ("Unesite broj tacaka: ");
	scanf ("%d",&bt);
	while (bt<1||bt>10){
		printf ("Pogresan unos\n");
	    printf ("Unesite broj tacaka: ");
	    scanf ("%d",&bt);}
	for (i=0;i<20;i++){
		for (j=0;j<20;j++){
		niz[i][j]=' ';
			
		}
	}
	for (tacke=0;tacke<bt;tacke++) {
		printf ("Unesite %d. tacku: ",tacke+1);
		scanf ("%d %d",&i,&j);
		while (i<0||j<0||i>19||j>19){
			printf ("Pogresan unos\n");
			printf ("Unesite %d. tacku: ",tacke+1);
			scanf ("%d %d",&i,&j);
		}
		niz[i][j]='*';
		
	}
	for (i=0;i<20;i++){
		for (j=0;j<20;j++){
			printf ("%c",niz[j][i]);
	}
	printf("\n");
	}
    return 0;
}

#include <stdio.h>

int main()
{
	int r,s,sh,l,i,j,k,m;
	do {
		printf ("Unesite broj redova: ");
		scanf ("%d", &r);
		break;
	} while (r>0 && r<=10);

	do {
		printf ("Unesite broj kolona: ");
		scanf ("%d", &s);
		break;
	} while (s>0 && s<=10);

	do {
		printf ("Unesite sirinu jedne kolone: ");
		scanf ("%d", &sh);
	} while (sh<0 && sh>=10);

	for (k=0; k<r; k++) {
		
		for (i=0; i<s; i++) {
			
			printf ("+");
		
			
			for (j=0; j<sh; j++) {

				printf ("-");
			} 
		}printf ("+");
		printf ("\n");
		
		
		for (l=0; l<s+1; l++) {
			
			printf ("|");
			for (j=0; j<sh; j++) {
				printf (" ");
			}}printf("\n");}
			
		for (i=0; i<s;i++){
			printf ("+");
			for (j=0; j<sh;j++){
				printf("-");
			}
		}printf("+");
			
		
		printf ("\n");
	

	

	return 0;

}
#include <stdio.h>

int main() {
int redovi;
int kolone;
int i;
int j;
int k;
int sirina_kolone;
	do
{printf ("Unesite broj redova: ");
	scanf ("%d", &redovi);}
	while (redovi<=0 || redovi>10);
	do
{printf ("Unesite broj kolona:  ");
	scanf ("%d", &kolone);} 
	while (kolone<=0 || kolone>10);
	do
{printf ("Unesite sirinu kolone: ");
	scanf ("%d", &sirina_kolone);}
	while (sirina_kolone<=0 || sirina_kolone>10);
	
	for (i=0; i<redovi*2+1; i++) 
			printf ("+");
		printf ("\n");
		
		for (i=0; i<redovi; i++)
			printf ("|");
			for (i=0; i<redovi-2; i++) {
				printf ("+");
		
				for (j=0; j<redovi-1; j++) 
					printf ("-", &sirina_kolone);
						printf ("+\n");
	
					
	}
		
	
	for (i=0; i<kolone; i++)
		printf ("+");
	printf ("\n");
		
		
	

	return 0;
	
}



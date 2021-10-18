#include <stdio.h>

int main() {
	int n=0, i=0, j=0;
	do{
	printf("Unesite broj N: ");
	scanf ("%d", &n);
		if (n%4!=0 || n<8){
	 printf ("Neispravno N!\n");
	 }
	}
	while (n%4!=0 || n<8);
	
	 printf ("\n");
	for (i=0; i<n/2; i++) {
		for (j=0; j<n/2; j++) {
			if (j==i)
			{
				printf ("\\");
			}
			else if (j==n/2-i-1)
			{
				printf("/");
			}
			else {
				printf(" ");
			}
			
		}
	
		 
		for (j=0; j<n/2; j++) {
			
			if ((i==0 && j==0) || (i==0 && j==n/2-1) || (i==n/2-1 && j==0) || (i==n/2-1 && j==n/2-1)) {
				printf ("+");
			}
			else if ((i==0 && (j>0 && j<n/2-1)) || (i==n/2-1 && (j>0 && j<n/2-1))) {
				printf ("-");
			}
			else if ((j==0 && (i>0 && i<n/2-1)) || (j==n/2-1 && (i>0 && i<n/2-1))) {
				printf ("|");
			}
			else {
				printf (" ");
			}
			
		}
		printf("\n");
		
	}
	
		for (i=0; i<n/2; i++) {
		for (j=0; j<n/2; j++) {
			
			if ((i==0 && j==0) || (i==0 && j==n/2-1) || (i==n/2-1 && j==0) || (i==n/2-1 && j==n/2-1)) {
				printf ("+");
			}
			else if ((i==0 && (j>0 && j<n/2-1)) || (i==n/2-1 && (j>0 && j<n/2-1))) {
				printf ("-");
			}
			else if ((j==0 && (i>0 && i<n/2-1)) || (j==n/2-1 && (i>0 && i<n/2-1))) {
				printf ("|");
			}
			else {
				printf (" ");
			}
			
		}
		
		for (j=0; j<n/2; j++) {
			if ((j==n/4 || j==n/4-1) && (i==n/4 || i==n/4-1)) {
				printf ("+");
			}
			else if (j==n/4 || j==n/4-1)
			{
				printf ("|");
			}
			else if (i==n/4 || i==n/4-1)
			{
				printf ("-");
			}
			else printf (" ");
		
		}
		 
		 
	
		
		printf("\n");
		}
		

	
	return 0;
}

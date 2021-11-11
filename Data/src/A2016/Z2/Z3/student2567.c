#include <stdio.h> 
#define VISINA 20
#define VISINA1 10

int main() { 
	
	int n, i, j; 
	int mata[VISINA1][2]; 
	int mat[VISINA][VISINA]={5};
	
	for (;;) {
		printf ("Unesite broj tacaka: ");  
		scanf ("%d", &n);                                 
		if (n>10 || n<=0) printf ("Pogresan unos \n"); 
		else break; 
	}
	
	for (i=0; i<n; i++) {    
		for (j=0; j<1; j++) {
			
			printf ("Unesite %d. tacku: ", i+1); 
			scanf ("%d %d", &mata[j][i], &mata[j][i+1]); 
			
			if (mata[j][i]>19 || mata[j][i]<0 || mata[j][i+1]>19 || mata[j][i+1]<0) {
				printf ("Pogresan unos \n"); 
				i--;
			}
			
			else  mat[mata[j][i]][mata[j][i+1]]=2; 
		}
	}
			
	
	for (i=0; i<VISINA; i++) {
		for (j=0; j<VISINA; j++) {                                                          
			if (mat[j][i]==2) printf ("*"); 
			else printf (" "); 
		}
		printf ("\n"); 
	}
	return 0;
}
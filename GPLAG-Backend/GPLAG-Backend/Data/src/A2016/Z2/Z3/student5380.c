#include <stdio.h>

int main() {
	int n,i,j,x,y;
	int m[20][20]={0};
	
	printf ("Unesite broj tacaka: ");
	scanf ("%d", &n);
   
 
	while ((n<=0) || (n>10)) {
	    printf ("Pogresan unos\n"); 
	    
	printf ("Unesite broj tacaka: ");
	scanf ("%d", &n); }
	
   for (i=0; i<n; i++) {

   printf ("Unesite %d. tacku: ", i+1 );
   scanf("%d %d", &x, &y);
   
   
   while ((x>19) || (y>19) || (x<0) || (y<0)) {
   	printf ("Pogresan unos\n"); 
   	
   printf ("Unesite %d. tacku: ", i+1 );
   scanf("%d %d", &x, &y);	}
   	
   m[y][x]=1;
	
	}
  for (i=0; i<20; i++) {
   for (j=0; j<20; j++) {
  		if ( m[i][j] == 1 ) {
  			printf ("*"); }
  		
  		else { printf (" ");	
  			
  		} 
   }
  		printf ("\n");
  }
  	return 0;
}

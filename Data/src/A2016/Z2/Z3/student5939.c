#include <stdio.h>

int main() {
 int red=0,kolona=0,brojac=1,n,x,y;
 char koordinate[20][20]={' '};

 
 //unos broja tacaka
 do {
 printf ("Unesite broj tacaka:\n ");
 scanf ("%d", &n); 
 if (n<0 || n>10)
 	printf ("Pogresan unos\n"); 
 	} while (n<=0 || n>10); 
 	
 	
 	//unos tacaka sa tastaure i provjera
 	while (n>0) {
 		printf ("Unesite %d. tacku:\n ",brojac);
 		scanf ("%d %d",&x,&y);
 		if ((x>=0 || x<20) && (y>=0 || y<20)) 
 		{
 		koordinate [y][x]='*';
 		} else printf ("Pogresan unos\n");
 		n=n-1;
 		brojac++;

 		}
 		// ispis
 		for (red=0; red<20; red++) {
 			
 			for (kolona=0; kolona<20; kolona++) { 
 			 
 			 	printf ("%c", koordinate [red][kolona]);
 				
 			}
 			printf ("\n");
 		}
 	
 	
 	
 
 
	return 0;
}

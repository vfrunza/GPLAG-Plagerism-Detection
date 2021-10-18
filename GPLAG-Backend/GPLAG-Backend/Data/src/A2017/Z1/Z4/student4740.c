#include <stdio.h>

int main() {
int red,kol,sir;
int i,j,k,r;

/* unos */ 
do {
printf ("Unesite broj redova: "); scanf ("%d", &red);
}
 while (red<1 || red>10); 
 	
do {
printf ("Unesite broj kolona: "); scanf ("%d", &kol);
}
 while (kol<1 || kol>10 );
 
 do {
printf ("Unesite sirinu jedne kolone: "); scanf ("%d", &sir); 
}
 while (sir<1 || sir>10 );
 
 
 
/* ispis prvog reda crteza */
for (i=1; i<=kol; i++) {
	printf("+");
	for (j=1; j<=sir; j++) {
		printf ("-"); 	}
	}
	printf("+\n");
	 
/* ispis ostalih redova */
	 r=red*2;
for (i=1; i<=r; i++)
    { if (i%2==1){
    	        printf ("|");
    	        for (j=1; j<=kol; j++){
      for (k=1; k<=sir; k++)
           {
           printf(" ");	
           }
        printf ("|");}
        printf("\n");
    }
    else {
    	for (j=1; j<=kol; j++) {
	printf("+");
	for (k=1; k<=sir; k++) {
		printf ("-"); 	}
	}
	printf("+\n");
    }
	
}
	return 0;
}

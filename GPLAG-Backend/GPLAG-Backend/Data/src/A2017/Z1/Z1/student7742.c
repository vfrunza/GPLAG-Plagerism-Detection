#include <stdio.h>
#include <math.h>
int main() {
 char novi_red,m,t,b;
 printf("Unesite jelo za Tarika: ");
 scanf("%c", &t);
 scanf("%c", &novi_red);
 printf("Unesite jelo za Bojana: ");
 scanf("%c", &b);
 scanf("%c", &novi_red);
 printf("Unesite jelo za Mirzu: ");
 scanf("%c", &m);
 scanf("%c", &novi_red);
 printf("\n");
 char t1=t, b1=b, m1=m;
 float restoran,trovac,fud;
 if(t=='H' && b=='H' && m=='H') {
     trovac=3+3+3;
     printf("Najjeftiniji je Fast-food (%.2f KM).", trovac);
 printf("Sa popustom bi Restoran bio jeftiniji (%2.f KM)", restoran);
 }

 
 
	return 0;
}

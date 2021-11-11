#include <stdio.h>
#include <math.h>

int main () {
	int p=0, h=0, c=0;
	char jelo1, jelo2, jelo3;
	char novired;
	double rest, fast, bistro;
	double rest1,rest2,rest3;
	printf ("Unesite jelo za Tarika: ");
	scanf ("%c", &jelo1);
	scanf ("%c", &novired);
	printf ("Unesite jelo za Bojana: ");
	scanf ("%c", &jelo2);
	scanf ("%c", &novired);
	printf ("Unesite jelo za Mirzu: ");
	scanf ("%c", &jelo3);
	if (jelo1=='C') c++;
	if (jelo1=='H') h++;
	if (jelo1=='P') p++;
	if (jelo2=='C') c++;
	if (jelo2=='H') h++;
	if (jelo2=='P') p++;
	if (jelo3=='C') c++;
	if (jelo3=='H') h++;
	if (jelo3=='P') p++;

rest=p*6.8+h*3.3+c*5.0;
fast=p*8.0+h*3.0+c*3.9;
bistro=p*5.3+h*5.0+c*6.0;
//printf("%lf %lf %lf\n",rest,fast,bistro);

if (bistro<fast && bistro<rest)
printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2lf KM).", bistro);
if (rest<fast && rest<bistro) {
printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2lf KM).", rest);
return 0;}
if (fast<rest && fast<bistro) 
printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2lf KM).", fast);
rest1=rest-0.1*p*6.8;
rest2=rest-0.1*h*3.3;
rest3=rest-0.1*c*5.0;
if (rest1<fast && rest1<bistro && rest1<rest2 && rest1<rest3)
{printf ("\nSa popustom bi Restoran bio jeftiniji (%.2lf KM).", rest1); return 0;}
if (rest2<fast && rest2<bistro && rest2<rest1 && rest2<rest3)
{printf ("\nSa popustom bi Restoran bio jeftiniji (%.2lf KM).", rest2); return 0;}
if (rest3<fast && rest3<bistro && rest3<rest2 && rest3<rest1)
{printf ("\nSa popustom bi Restoran bio jeftiniji (%.2lf KM).", rest3); return 0;}
return 0;
}



#include <stdio.h>

int main() {
char n;
int ZC, ZS, ZP, ZV, ZB, maks;
double udio,suma;
ZC=0; ZS=0; ZP=0; ZV=0; ZB=0;
printf ("Unesite vozila: ");
suma=0;
do { scanf ("%c", &n);
    if ( n=='c' ||n=='C' || n=='b' || n=='B' || n=='s' || n=='S' || n=='v' || n=='V' || n=='p' || n=='P' || n=='k' || n=='K')
{ 
 if (n=='c' || n=='C')
 { ZC++; }
 else if (n=='B' || n=='b')
 { ZB++; }
 else  if (n=='s' || n=='S')
 { ZS++; }
 else    if (n=='v' || n=='V') 
 {ZV++; }    
 else     if (n=='p' || n=='P')
 { ZP++; }  }
else if (  n!='c' ||n!='C' || n!='b' || n!='B' || n!='s' || n!='S' || n!='v' || n!='V' || n!='p' || n!='P' || n!='k' || n!='K') 
{    printf ("Neispravan unos\n"); }
    
}
while (n!='K' && n!='k');

suma=ZC+ZB+ZS+ZV+ZP;


maks=ZC;
if (ZB>maks) { maks=ZB;}
if (ZS>maks) { maks=ZS;}
if (ZV>maks) {maks=ZV;}
if (ZP>maks){maks=ZP;}


udio= (maks*100)/suma;

if (suma==0) {printf ("Ukupno evidentirano 0 vozila. \nNajpopularnija boja je crna (0.00%).");}
else   {
printf ("Ukupno evidentirano %g vozila.", suma);

if (maks==ZC)
{ printf ("\nNajpopularnija boja je crna (%.2f%). ",  udio); }

else if (maks==ZB)
{ printf ("\nNajpopularnija boja je bijela (%.2f%). ",  udio); }

else if (maks==ZS)
{ printf ("\nNajpopularnija boja je siva (%.2f%). ",  udio); }

else if (maks==ZV)
{ printf ("\nNajpopularnija boja je crvena (%.2f%). ",  udio); }

else if (maks==ZP)
{ printf ("\nNajpopularnija boja je plava (%.2f%). ",  udio); }

}


	return 0;
}

#include <stdio.h>

int main() {
int u=0, najpopularnija=0;
int c=0,b=0,s=0,v=0,p=0;
char t;
float procenat;
printf ("Unesite vozila: ");
for (;;) {
scanf ("%c", &t);
if (t=='C' || t=='c') 
c=c+1;
else if (t=='b' || t=='B')
b=b+1;
else if (t=='s' || t=='S')
s=s+1;
else if (t=='v' || t=='V')
v=v+1;
else if (t=='p' || t=='P')
p=p+1;
else if (t=='k' || t=='K')
break;
else printf ("Neispravan unos\n");
}
u=c+b+s+v+p;
printf ("Ukupno evidentirano %d vozila.", u); 

najpopularnija=c;
if (b>c)
najpopularnija=b;
if (s>najpopularnija)
najpopularnija=s;
if (v>najpopularnija)
najpopularnija=v;
if (p>najpopularnija)
najpopularnija=p;

if (najpopularnija==c)
printf ("\nNajpopularnija boja je crna");
else if (najpopularnija==b)
printf ("\nNajpopularnija boja je bijela");
else if (najpopularnija==s)
printf ("\nNajpopularnija boja je siva");
else if (najpopularnija==v)
printf ("\nNajpopularnija boja je crvena");
else if (najpopularnija==p)
printf ("\nNajpopularnija boja je plava");

if (u==0)
u++;
procenat=(float)najpopularnija/u*100;
printf (" (%.2f%%).", procenat);

return 0;
}

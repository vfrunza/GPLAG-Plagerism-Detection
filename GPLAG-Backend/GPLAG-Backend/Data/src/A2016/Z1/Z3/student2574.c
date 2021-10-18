#include <stdio.h>
int main() 
{
int y,crna=0,bijela=0,crvena=0,siva=0,plava=0,ukupno=0;
double p=0;
char x;
printf ("Unesite vozila: ");
for (;;)
{
scanf ("%c", &x);
if (x=='c' || x=='C')
crna=crna+1;
else if (x=='P' || x=='p')
plava=plava+1;
else if (x=='V' || x=='v')
crvena=crvena+1;
else if (x=='s' || x=='S')
siva=siva+1;
else if (x=='B' || x=='b')
bijela=bijela+1;
else if (x=='k' || x=='K')
{
ukupno=crna+bijela+plava+crvena+siva;
printf ("Ukupno evidentirano %d vozila.\n",ukupno);
break;
}
else { 
printf ("Neispravan unos\n");
}
}
y=crvena;
if (crna>y) y=crna;
if (plava>y) y=plava;
if (siva>y) y=siva;
if (bijela>y) y=bijela;
if (y==crna)
{
    if (crna>0 && ukupno >0)
    {
    p=(float)crna/ukupno*100;
    printf ("Najpopularnija boja je crna (%.2f%%).",p);
    }
    else 
    printf ("Najpopularnija boja je crna (0.00%%).");
}
else if (y==bijela)
{
    if (bijela>0 && ukupno >0)
    {
    p=(float)bijela/ukupno*100;
    printf ("Najpopularnija boja je bijela (%.2f%%).",p);}
    else 
 printf ("Najpopularnija boja je crna (0.00%%).");
}
else if (y==siva)
{
    if (siva>0 && ukupno>0)
    {
    p=(float)siva/ukupno*100;
    printf ("Najpopularnija boja je siva (%.2f%%).",p);}
    else printf ("Najpopularnija boja je crna (0.00%%).");
}
else if (y==crvena) {
    if (crvena>0 && ukupno>0)
    {
    p=(float)crvena/ukupno*100;
    printf ("Najpopularnija boja je crvena (%.2f%%).",p);}
    else
   printf ("Najpopularnija boja je crna (0.00%%).");
}
else if (y==plava)
{
    if (plava>0 && ukupno>0)
    {
    p=(float)plava/ukupno*100;
    printf ("Najpopularnija boja je plava (%.2f%%).\n",p);}
    else 
    printf ("Najpopularnija boja je crna (0.00%%).");
}
return 0;
}
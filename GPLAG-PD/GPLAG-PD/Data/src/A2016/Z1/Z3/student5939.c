#include <stdio.h>

int main() {
int crna=0,bijela=0,siva=0,crvena=0,plava=0,suma=0;
float procenatc=0.0f,procenatb,procenats,procenatv,procenatp,najpopularnijaboja;
char uv=' ';
char najpopularnija_oznaka=' ';

printf ("Unesite vozila: ");
while (uv != 'k')
{
scanf ("%c", &uv);
if (uv == 'K')
    uv = 'k';
    
switch (uv)
{
case 'C':
case 'c':
crna=crna+1;
suma=suma+1;
break;
case 'B':
case 'b':
bijela=bijela+1;
suma=suma+1;
break;
case 'S':
case 's':
siva=siva+1;
suma=suma+1;
break;
case 'V':
case 'v':
crvena=crvena+1;
suma=suma+1;
break;
case 'P':
case 'p':
plava=plava+1;
suma=suma+1;
break;
case 'k':
break;
default:
printf ("Neispravan unos\n");
}
}
if (suma==0) {
    printf("Ukupno evidentirano %d vozila.\n",suma);
    printf ("Najpopularnija boja je crna (%.2f%%).\n", procenatc);
    return 1;
}

procenatc=(float)crna/suma*100;
procenatb=(float)bijela/suma*100;
procenats=(float)siva/suma*100;
procenatv=(float)crvena/suma*100;
procenatp=(float)plava/suma*100;
printf ("Ukupno evidentirano %d vozila.\n",suma);


najpopularnijaboja=procenatc;

if(procenatb>najpopularnijaboja)
{
    najpopularnijaboja=procenatb;
    najpopularnija_oznaka='b';
    
}

if(procenats>najpopularnijaboja)
{
    najpopularnijaboja=procenats;
    najpopularnija_oznaka='s';
    
}
if(procenatv>najpopularnijaboja)
{
    najpopularnijaboja=procenatv;
    najpopularnija_oznaka='v';
    
}
if(procenatp>najpopularnijaboja)
{
    najpopularnijaboja=procenatp;
    najpopularnija_oznaka='p';
    
}
switch (najpopularnija_oznaka)
{
case ('b'):
printf ("Najpopularnija boja je bijela (%.2f%%).\n", procenatb);
break;
case ('s'):
printf ("Najpopularnija boja je siva (%.2f%%).\n",procenats);
break;
case ('v'):
printf ("Najpopularnija boja je crvena (%.2f%%).\n",procenatv);
break;
case ('p'):
printf ("Najpopularnija boja je plava (%.2f%%).\n",procenatp);
break;
default:
printf ("Najpopularnija boja je crna (%.2f%%).\n", procenatc);


}
return 0;
}




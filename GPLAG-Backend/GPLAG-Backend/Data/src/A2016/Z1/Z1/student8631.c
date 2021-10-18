#include <stdio.h>
#include<stdlib.h>
int main() {
double IPT, IIPT, PT, ZT, ISPITT,IPB, IIPB,PB,ZB,ISPITB, IPM,IIPM,PM, ZM, ISPITM, SUMT, SUMB, SUMM;
int ukupnibrojocjena=0, O6=0, O7=0, O8=0, O9=0,O10=0, T=0, M=0, B=0;

printf("Unesite bodove za Tarika: \nI parcijalni ispit: ");
scanf("%lf", &IPT);
if (IPT<0 || IPT >20){
printf ("Neispravan broj bodova\n");
return 0;}
printf("II parcijalni ispit: ");
scanf("%lf", &IIPT);
if (IIPT<0 || IIPT >20)
{
printf ("Neispravan broj bodova\n");
return 0;}
printf("Prisustvo: ");
scanf("%lf", &PT);
if (PT<0 || PT>10)
{
printf ("Neispravan broj bodova\n");
return 0;}
printf("Zadace: ");
scanf("%lf", &ZT);
if (ZT<0 || ZT >10)
{
printf ("Neispravan broj bodova\n");
return 0;}
printf("Zavrsni ispit: ");
scanf("%lf", &ISPITT);
if (ISPITT<0 || ISPITT>40)
{
printf ("Neispravan broj bodova\n");
return 0;}

printf("Unesite bodove za Bojana: \nI parcijalni ispit: ");
scanf("%lf", &IPB);
if (IPB<0 || IPB >20)
{
printf ("Neispravan broj bodova\n");
return 0;}
printf("II parcijalni ispit: ");
scanf("%lf", &IIPB);
if (IIPB<0 || IIPB >20)
{
printf ("Neispravan broj bodova\n");
return 0;}
printf("Prisustvo: ");
scanf("%lf", &PB);
if (PB<0 || PB >10)
{
printf ("Neispravan broj bodova\n");
return 0;}
printf("Zadace: ");
scanf("%lf", &ZB);
if (ZB<0 || ZB >10)
{
printf ("Neispravan broj bodova\n");
return 0;}
printf("Zavrsni ispit: ");
scanf("%lf", &ISPITB);
if (ISPITB<0 || ISPITB >40)
{
printf ("Neispravan broj bodova\n");
return 0;}

printf("Unesite bodove za Mirzu: \nI parcijalni ispit: ");
scanf("%lf", &IPM);
if (IPM<0 || IPM >20)
{
printf ("Neispravan broj bodova\n");
return 0;}
printf("II parcijalni ispit: ");
scanf("%lf", &IIPM);
if (IIPM<0 || IIPM >20)
{
printf ("Neispravan broj bodova\n");
return 0;}
printf("Prisustvo: ");
scanf("%lf", &PM);
if (PM<0 || PM >10)
{
printf ("Neispravan broj bodova\n");
return 0;}
printf("Zadace: ");
scanf("%lf", &ZM);
if (PM<0 || PM >10)
{
printf ("Neispravan broj bodova\n");
return 0;}
printf("Zavrsni ispit: ");
scanf("%lf", &ISPITM);
if (ISPITM<0 || ISPITM >40)
{
printf ("Neispravan broj bodova\n");
return 0;}
if(IPT>=0 && IPT<=20 && IIPT>=0 && IIPT<=20 && PT>=0 && PT<=10 && ZT>=0 && ZT<=10 && ISPITT>=0 && ISPITT<=40 &&IPB>=0 && IPB<=20 && IIPB>=0 && IIPB<=20 && PB>=0 && PB<=10 && ZB>=0 && ZB<=10 && ISPITB>=0 && ISPITB<=40 && IPM>=0 && IPM<=20 && IIPM>=0 && IIPM<=20 && PM>=0 && PM<=10 && ZM>=0 && ZM<=10 && ISPITM>=0 && ISPITM<=40)
{
    SUMT= IPT+IIPT+PT+ZT+ISPITT;
    SUMB= IPB+IIPB+PB+ZB+ISPITB;
    SUMM= IPM+IIPM+PM+ZM+ISPITM;
}

if(SUMT>=55) T++;
if(SUMB>=55) B++;
if(SUMM>=55) M++;
ukupnibrojocjena= T+B+M;
if(ukupnibrojocjena==0)
printf("Nijedan student nije polozio. \n");
else if(ukupnibrojocjena==1)
printf("Jedan student je polozio. \n");
else if(ukupnibrojocjena==2)
printf("Dva studenta su polozila. \n");
else if(ukupnibrojocjena==3)
{printf("Sva tri studenta su polozila. \n");


if (SUMT>=92) O10++;
else if (SUMT<92 && SUMT>=85) O9++;
else if (SUMT<85 && SUMT>=75) O8++;
else if (SUMT<75 && SUMT>=65) O7++;
else O6++;

if (SUMB>=92) O10++;
else if (SUMB<92 && SUMB>=85) O9++;
else if (SUMB<85 && SUMB>=75) O8++;
else if (SUMB<75 && SUMB>=65) O7++;
else O6++;

if (SUMM>=92) O10++;
else if (SUMM<92 && SUMM>=85) O9++;
else if (SUMM<85 && SUMM>=75) O8++;
else if (SUMM<75 && SUMM>=65) O7++;
else O6++;


if (O6==3 || O7==3 || O8==3 || O9==3 || O10==3)
printf("Sva tri studenta imaju istu ocjenu. \n");
else if (O6==2 || O7==2 || O8==2 || O9==2 || O10==2)
printf("Dva od tri studenta imaju istu ocjenu. \n");
else 
printf("Svaki student ima razlicitu ocjenu. \n");
}

return 0;}








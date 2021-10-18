#include <stdio.h>

#define I_parcijalni 20 /* - Maximalan broj bodova */
#define II_parcijalni 20 /* - Maximalan broj bodova */
#define Zavrsni_ispit 40 /* - Maximalan broj bodova */
#define Zadace 10 /* - Maximalan broj bodova */
#define Prisustvo 10 /* - Maximalan broj bodova */

int main(){
int Ocjena1,Ocjena2,Ocjena3;
double Iparc,IIparc,Pr,Dz,Zi;
printf("Unesite bodove za Tarika: \n");
printf("I parcijalni ispit: ");
scanf("%lf",&Iparc);
if(Iparc<0 || Iparc>I_parcijalni)
{
    printf("Neispravan broj bodova");
    return 0;
}
printf("II parcijalni ispit: ");
scanf("%lf",&IIparc);
if(IIparc<0 || IIparc>II_parcijalni)
{
    printf("Neispravan broj bodova");
    return 0;
}
printf("Prisustvo: ");
scanf("%lf",&Pr);
if(Pr<0 || Pr>Prisustvo)
{
    printf("Neispravan broj bodova");
    return 0;
}
printf("Zadace: ");
scanf("%lf",&Dz);
if(Dz<0 || Dz>Zadace)
{
    printf("Neispravan broj bodova");
    return 0;
}
printf("Zavrsni ispit: ");
scanf("%lf",&Zi);
if(Zi<0 || Zi>Zavrsni_ispit)
{
    printf("Neispravan broj bodova ");
    return 0;
}

int suma1=Iparc+IIparc+Pr+Dz+Zi;
printf("Unesite bodove za Bojana: \n");
printf("I parcijalni ispit: ");
scanf("%lf",&Iparc);
if(Iparc<0 || Iparc>I_parcijalni)
{
    printf("Neispravan broj bodova");
    return 0;
}
printf("II parcijalni ispit: ");
scanf("%lf",&IIparc);
if(IIparc<0 || IIparc>II_parcijalni)
{
    printf("Neispravan broj bodova");
    return 0;
}
printf("Prisustvo: ");
scanf("%lf",&Pr);
if(Pr<0 || Pr>Prisustvo)
{
    printf("Neispravan broj bodova");
    return 0;
}
printf("Zadace: ");
scanf("%lf",&Dz);
if(Dz<0 || Dz>Zadace)
{
    printf("Neispravan broj bodova");
    return 0;
}

printf("Zavrsni ispit: ");
scanf("%lf",&Zi);
if(Zi<0 || Zi>Zavrsni_ispit)
{
    printf("Neispravan broj bodova");
    return 0;
}
 int suma2=Iparc+IIparc+Pr+Dz+Zi;
printf("Unesite bodove za Mirzu: \n");
printf("I parcijalni ispit: ");
scanf("%lf",&Iparc);
if(Iparc<0 || Iparc>I_parcijalni)
{
    printf("Neispravan broj bodova");
    return 0;
}
printf("II parcijalni ispit: ");
scanf("%lf",&IIparc);
if(IIparc<0 || IIparc>II_parcijalni)
{
    printf("Neispravan broj bodova");
    return 0;
}
printf("Prisustvo: ");
scanf("%lf",&Pr);
if(Pr<0 || Pr>Prisustvo)
{
    printf("Neispravan broj bodova");
    return 0;
}
printf("Zadace: ");
scanf("%lf",&Dz);
if(Dz<0 || Dz>Zadace)
{
    printf("Neispravan broj bodova");
    return 0;
}
printf("Zavrsni ispit: ");
scanf("%lf",&Zi);
if(Zi<0 || Zi>Zavrsni_ispit)
{
    printf("Neispravan broj bodova");
    return 0;
}

 int suma3=Iparc+IIparc+Pr+Dz+Zi;
 
 if(suma1<55) Ocjena1=5;
 else if(suma1>=55 && suma1<65) Ocjena1=6;
 else if(suma1>=65 && suma1<75) Ocjena1=7;
 else if(suma1>=75 && suma1<85) Ocjena1=8;
 else if(suma1>=85 && suma1<92) Ocjena1=9;
 else if(suma1>=92 && suma1<=100) Ocjena1=10;
 
 if(suma2<55) Ocjena2=5;
 else if(suma2>=55 && suma2<65) Ocjena2=6;
 else if(suma2>=65 && suma2<75) Ocjena2=7;
 else if(suma2>=75 && suma2<85) Ocjena2=8;
 else if(suma2>=85 && suma2<92) Ocjena2=9;
 else if(suma2>=92 && suma2<=100) Ocjena2=10;
 
 if(suma3<55) Ocjena3=5;
 else if(suma3>=55 && suma3<65) Ocjena3=6;
 else if(suma3>=65 && suma3<75) Ocjena3=7;
 else if(suma3>=75 && suma3<85) Ocjena3=8;
 else if(suma3>=85 && suma3<92) Ocjena3=9;
 else if(suma3>=92 && suma3<=100) Ocjena3=10;
 
 if(Ocjena1==5 && Ocjena2==5 && Ocjena3==5){
     printf("Nijedan student nije polozio.");
 }
 if((Ocjena1!=5 && Ocjena2==5 && Ocjena3==5) || (Ocjena1==5 && Ocjena2!=5 && Ocjena3==5) || (Ocjena1==5 && Ocjena2==5 && Ocjena3!=5)){
     printf("Jedan student je polozio.");
 }
 if((Ocjena1!=5 && Ocjena2!=5 && Ocjena3==5) || (Ocjena1!=5 && Ocjena2==5 && Ocjena3!=5) || (Ocjena1==5 && Ocjena2!=5 && Ocjena3!=5)){
printf("Dva studenta su polozila.");     
 }
 if(Ocjena1!=5 && Ocjena2!=5 && Ocjena3!=5){
     printf("Sva tri studenta su polozila.\n");
     if((Ocjena1==Ocjena2) && (Ocjena1==Ocjena3) && (Ocjena2==Ocjena3))
     printf("Sva tri studenta imaju istu ocjenu.");
     if((Ocjena1!=Ocjena2) && (Ocjena1!=Ocjena3) && (Ocjena2!=Ocjena3))
     printf("Svaki student ima razlicitu ocjenu.");
     if((Ocjena1==Ocjena2 && Ocjena1!= Ocjena3) || (Ocjena2==Ocjena3 && Ocjena2!= Ocjena1) || (Ocjena1==Ocjena3 && Ocjena1!= Ocjena2))
     printf("Dva od tri studenta imaju istu ocjenu.");
 }
 
	
	return 0;
}

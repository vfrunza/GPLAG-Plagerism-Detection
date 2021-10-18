#include <stdio.h>

int main() {
/*	printf("Zadaća 1, Zadatak 1");*/

double prvi_parcijalni, drugi_parcijalni, prisustvo, zavrsni_ispit, zadace;

printf("Unesite bodove za Tarika:\n");

printf("I parcijalni ispit: ");
scanf("%lf", &prvi_parcijalni);
if(prvi_parcijalni<0 || prvi_parcijalni>20)  
{ printf("Neispravan broj bodova\n");
  return 0;	}
  
printf("II parcijalni ispit: ");
scanf("%lf", &drugi_parcijalni);
if(drugi_parcijalni<0 || drugi_parcijalni>20) 
{ printf("Neispravan broj bodova\n");
  return 0;	}
  
printf("Prisustvo: ");
scanf("%lf", &prisustvo);
 if(prisustvo<0 || prisustvo>10) 
{ printf("Neispravan broj bodova\n");
  return 0;	}
  
printf("Zadace: ");
scanf("%lf", &zadace);
if(zadace<0 || zadace>10) 
{ printf("Neispravan broj bodova\n");
  return 0;	}
  
printf("Zavrsni ispit: ");
scanf("%lf", &zavrsni_ispit);
if(zavrsni_ispit<0 || zavrsni_ispit>40) 
{ printf("Neispravan broj bodova\n");
  return 0;	}


double prvi_parcijalni2, drugi_parcijalni2, prisustvo2, zavrsni_ispit2, zadace2;

printf("Unesite bodove za Bojana:\n");

printf("I parcijalni ispit: ");
scanf("%lf", &prvi_parcijalni2);
if(prvi_parcijalni2<0 || prvi_parcijalni2>20)  
{ printf("Neispravan broj bodova\n");
  return 0;	}

printf("II parcijalni ispit: ");
scanf("%lf", &drugi_parcijalni2);
if(drugi_parcijalni2<0 || drugi_parcijalni2>20) 
{ printf("Neispravan broj bodova\n");
  return 0;	}
  
printf("Prisustvo: ");
scanf("%lf", &prisustvo2);
if(prisustvo2<0 || prisustvo2>10) 
{ printf("Neispravan broj bodova\n");
  return 0;	}
  
printf("Zadace: ");
scanf("%lf", &zadace2);
if(zadace2<0 || zadace2>10) 
{ printf("Neispravan broj bodova\n");
  return 0;	}
  
printf("Zavrsni ispit: ");
scanf("%lf", &zavrsni_ispit2);
if(zavrsni_ispit2<0 || zavrsni_ispit2>40) 
{ printf("Neispravan broj bodova\n");
  return 0;	}

double prvi_parcijalni3, drugi_parcijalni3, prisustvo3, zavrsni_ispit3, zadace3;

printf("Unesite bodove za Mirzu:\n");

printf("I parcijalni ispit: ");
scanf("%lf", &prvi_parcijalni3);
if(prvi_parcijalni3<0 || prvi_parcijalni3>20)  
{ printf("Neispravan broj bodova\n");
  return 0;	}
  
printf("II parcijalni ispit: ");
scanf("%lf", &drugi_parcijalni3);
if(drugi_parcijalni3<0 || drugi_parcijalni3>20) 
{ printf("Neispravan broj bodova\n");
  return 0;	}
  
printf("Prisustvo: ");
scanf("%lf", &prisustvo3);
if(prisustvo3<0 || prisustvo3>10) 
{ printf("Neispravan broj bodova\n");
  return 0;	}
  
printf("Zadace: ");
scanf("%lf", &zadace3);
if(zadace3<0 || zadace3>10) 
{ printf("Neispravan broj bodova\n");
  return 0;	}
  
printf("Zavrsni ispit: ");
scanf("%lf", &zavrsni_ispit3);
if(zavrsni_ispit3<0 || zavrsni_ispit3>40) 
{ printf("Neispravan broj bodova\n");
  return 0;	}
  
double z1, z2, z3;

z1 = prvi_parcijalni + drugi_parcijalni + prisustvo + zadace + zavrsni_ispit;
z2 = prvi_parcijalni2 + drugi_parcijalni2 + prisustvo2 + zadace2 + zavrsni_ispit2;
z3 = prvi_parcijalni3 + drugi_parcijalni3 + prisustvo3 + zadace3 + zavrsni_ispit3;

if(z1<55 && z2<55 && z3<55) printf("Nijedan student nije polozio.");
else if(z1>=55 && z2>=55 && z3>=55) printf("Sva tri studenta su polozila.");
else if((z1>=55 && z2<55 && z3<55) || (z2>=55 && z1<55 && z3<55) || (z3>=55 && z1<55 && z2<55)) printf("Jedan student je polozio.");
else if((z1>=55 && z2>=55 && z3<55) || (z2>=55 && z3>=55 && z1<55) || (z1>=55 && z3>=55 && z2<55)) printf("Dva studenta su polozila.");

if(z1>=55 && z2>=55 && z3>=55) {
  
  int ocjena, ocjena2, ocjena3;
  
  if(z1>=55 && z1<65) ocjena=6;
  if(z1>=65 && z1<75) ocjena=7;
  if(z1>=75 && z1<85) ocjena=8;
  if(z1>=85 && z1<92) ocjena=9;
  if(z1>=92 && z1<=100) ocjena=10;
  
  if(z2>=55 && z2<65) ocjena2=6;
  if(z2>=65 && z2<75) ocjena2=7;
  if(z2>=75 && z2<85) ocjena2=8;
  if(z2>=85 && z2<92) ocjena2=9;
  if(z2>=92 && z2<=100) ocjena2=10;
  
  if(z3>=55 && z3<65) ocjena3=6;
  if(z3>=65 && z3<75) ocjena3=7;
  if(z3>=75 && z3<85) ocjena3=8;
  if(z3>=85 && z3<92) ocjena3=9;
  if(z3>=92 && z3<=100) ocjena3=10;
  
  if(ocjena==ocjena2 && ocjena2==ocjena3 && ocjena==ocjena3) printf("\nSva tri studenta imaju istu ocjenu.");
  if((ocjena==ocjena2 && ocjena2!=ocjena3 && ocjena!=ocjena3) || (ocjena==ocjena3 && ocjena3!=ocjena2 && ocjena!=ocjena2) || (ocjena2==ocjena3 && ocjena3!=ocjena && ocjena2!=ocjena)) printf("\nDva od tri studenta imaju istu ocjenu.");
  if(ocjena!=ocjena2 && ocjena2!=ocjena3 && ocjena!=ocjena3) printf("\nSvaki student ima razlicitu ocjenu.");
  
  
}


	return 0;
}

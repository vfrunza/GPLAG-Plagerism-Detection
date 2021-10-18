#include <stdio.h>
int main() {
  double Tp1,Tp2,Tp,Tz,Tzi,Bp1,Bp2,Bp,Bz,Bzi,Mp1,Mp2,Mp,Mz,Mzi;
  double Tb,Bb,Mb;
    int Toc,Boc,Moc;
    printf("Unesite bodove za Tarika:\n");
    printf("I parcijalni ispit: ");
    scanf("%lf",&Tp1);if(Tp1<0 || Tp1>20){printf("Neispravan broj bodova"); return 0;}
    printf("II parcijalni ispit: ");
    scanf("%lf",&Tp2);if(Tp2<0 || Tp2>20){printf("Neispravan broj bodova"); return 0;}
    printf("Prisustvo: ");
    scanf("%lf",&Tp);if (Tp<0 || Tp>10) {printf ("Neispravan broj bodova"); return 0; }
    printf("Zadace: ");
    scanf("%lf",&Tz);if(Tz<0 || Tz>10) {printf("Neispravan broj bodova"); return 0; }
    printf("Zavrsni ispit: ");
    scanf("%lf",&Tzi);if (Tzi<0 || Tzi >40) {printf("Neispravan broj bodova"); return 0; }
    printf("Unesite bodove za Bojana:\n");
    printf("I parcijalni ispit: ");
    scanf("%lf",&Bp1);if(Bp1<0 || Bp1>20) {printf("Neispravan broj bodova"); return 0; }
    printf("II parcijalni ispit: ");
    scanf("%lf",&Bp2); if(Bp2<0 || Bp2>20) {printf("Neispravan broj bodova"); return 0; }
    printf("Prisustvo: ");
    scanf("%lf",&Bp);if(Bp<0 || Bp>10) {printf("Neispravan broj bodova"); return 0; }
    printf("Zadace: ");
    scanf("%lf",&Bz);if(Bz<0 || Bz>10) {printf("Neispravan broj bodova"); return 0; }
    printf("Zavrsni ispit: ");
    scanf("%lf",&Bzi);if(Bzi<0 || Bzi>40) {printf("Neispravan broj bodova"); return 0; }
    printf("Unesite bodove za Mirzu:\n");
    printf("I parcijalni ispit: ");
    scanf("%lf",&Mp1);if(Mp1<0 || Mp1>20) {printf("Neispravan broj bodova"); return 0; }
    printf("II parcijalni ispit: ");
    scanf("%lf",&Mp2);if(Mp2<0 || Mp2>20) {printf("Neispravan broj bodova"); return 0; }
    printf("Prisustvo: ");
    scanf("%lf",&Mp);if(Mp<0 || Mp>10) {printf("Neispravan broj bodova"); return 0; }
    printf("Zadace: ");
    scanf("%lf",&Mz);if(Mz<0 || Mz>10) {printf("Neispravan broj bodova"); return 0; }
    printf("Zavrsni ispit: ");
    scanf("%lf",&Mzi);if( Mzi<0 || Mzi>40) {printf("Neispravan broj bodova"); return 0; }
    Tb=Tp1+Tp2+Tp+Tz+Tzi;
    Bb=Bp1+Bp2+Bp+Bz+Bzi;
    Mb=Mp1+Mp2+Mp+Mz+Mzi;
    if(Tb<55) {Toc=5;} else 
    if(Tb>=55 && Tb<65) {Toc=6;} else
    if(Tb>=65 && Tb<75) {Toc=7;} else
    if(Tb>=75 && Tb<85) {Toc=8;} else
    if(Tb>=85 && Tb<92) {Toc=9;} else
    if(Tb>=92 && Tb<=100) {Toc=10;}
    if(Bb<55) {Boc=5; } else
    if(Bb>=55 && Bb<65) {Boc=6;} else
    if(Bb>=65 && Bb<75) {Boc=7;} else
    if(Bb>=75 && Bb<85) {Boc=8;} else
    if(Bb>=85 && Bb<92) {Boc=9;} else
    if(Bb>=92 && Bb<=100) {Boc=10;}
    if(Mb<55) {Moc=5;} else
    if(Mb>=55 && Mb<65) {Moc=6;} else
    if(Mb>=65 && Mb<75) {Moc=7;} else
    if(Mb>=75 && Mb<85) {Moc=8;} else
    if(Mb>=85 && Mb<92) {Moc=9;} else
    if(Mb>=92 && Mb<=100) {Moc=10;}
    if(Toc==5 && Boc==5 && Moc==5) {
      printf ("Nijedan student nije polozio.\n");}
    else if((Toc>5 && Boc==5 && Moc==5) || (Toc==5 && Boc>5 && Moc==5) || (Toc==5 && Boc==5 && Moc>5)) {
      printf("Jedan student je polozio.\n");} 
      else if((Toc>5 && Boc>5 && Moc==5) || (Toc>5 && Boc==5 && Moc>5) || (Toc==5 && Boc>5 && Moc>5)) { 
      printf("Dva studenta su polozila.\n"); }
       else if(Toc>5 && Boc>5 && Moc>5) { printf("Sva tri studenta su polozila.\n");
       if((Tb>55 && Bb>55 && Mb>55) && (Toc==Boc && Boc==Moc)){ printf("Sva tri studenta imaju istu ocjenu.\n"); } 
      else if(Toc==Boc || Toc==Moc || Boc==Moc) { printf("Dva od tri studenta imaju istu ocjenu.\n"); }
      else if(Toc!=Boc && Toc!=Moc && Boc!=Moc) { printf("Svaki student ima razlicitu ocjenu.\n"); }
       }
      return 0; }

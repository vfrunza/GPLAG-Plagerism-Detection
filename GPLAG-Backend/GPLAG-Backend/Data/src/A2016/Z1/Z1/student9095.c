#include <stdio.h>
#include <math.h>
#define epsilon 0.001

int main() {
    int a, b, c, d, e, f, g, h, o, p, r, s, t, u, v, sum1, sum2, sum3 ;
    printf ("Unesite bodove za Tarika: ");
    printf ("\n I parcijalini: ");
    scanf  ("%d", &a);
    if  (a>20 || a<0){
        printf("Neispravan broj bodova: ");
        return 0;
    }
printf ("II parcijalni ispit: ");
scanf  ("%d", &b);
if  (b>20 || b<0){
    printf("Neispravan broj bodova: ");
    return 0;
}
printf ("Prisustvo: ");
scanf  ("%d", &c);
if  (c>10 || c<0){
    printf("Neispravan broj bodova: ");
    return 0;
}
printf ("Zadace: ");
scanf  ("%d", &d);
if  (d>10 || d<0){
    printf("Neispravan broj bodova: ");
    return 0;
}
printf ("Zavrsni ispit: ");
scanf  ("%d", &e);
if  (e>40 || e<0){
    printf("Neispravan broj bodova: ");
    return 0;
}
printf ("Unesite bodove za Bojana: ");
printf ("I parcijalini ispit: ");
scanf  ("%d", &f);
if  (f>20 || f<0){
    printf("Neispravan broj bodova: ");
    return 0;
}
printf ("II parcijalni: ");
scanf  ("%d", &g);
if  (g>20 || g<0){
    printf("Neispravan broj bodova: ");
    return 0;
}
printf ("Prisustvo: ");
scanf  ("%d", &h);
if  (h>10 || h<0){
    printf ("Neispravan broj bodova: ");
    return 0;
}
printf ("Zadace: ");
scanf  ("%d", &o);
if  (o>10 || o<0){
    printf ("Neispravan broj bodova: ");
    return 0;
}
printf ("Zavrsni ispit: ");
scanf  ("%d", &p);
if  (p>40 || p<0){
    printf("Neispravan broj bodova: ");
    return 0;
}
printf ("Unesite bodove za Mirzu: ");
printf ("\n I parcijalni ");
scanf  ("%d", &r);
if  (r>20 || r<0){
    printf("Neispravan broj bodova: ");
    return 0;
}
printf ("II parcijalni ispit:");
scanf  ("%d", &s);
if  (s>20 || s<0){
    printf("Neispravan broj bodova: ");
    return 0;
}
printf ("Prisustvo: ");
scanf ("%d", &t);
if  (t>10 || t<0){
    printf("Neispravan broj bodova: ");
    return 0;
}
printf ("Zadace: ");
scanf  ("%d", &u);
if  (u>10 || u<0){
    printf("Neispravan broj bodova: ");
    return 0;
}
printf ("Zavrsni ispit: ");
scanf ("%d", &v);
if  (v>40 || v<0){
    printf ("Neispravan broj bodova: ");
    return 0;
}
sum1= (a+b+c+d+e);
sum2= (f+g+h+o+p);
sum3= (r+s+t+u+v);
if(sum1< 55.00 && sum2<55.00 && sum3<55.00){
    printf("\n Nijedan student nije položio: ");
}
else if ((sum1>=55.00 && sum2>=55.00 && sum3<55.00) || (sum1>=55.00 && sum3>=55.00 && sum2<55.00) || (sum2>=55.00 && sum3>=55.00 && sum1<55.00)){
    printf("\n Dva studenta su polozila: ");
}
else if ((sum1>=55.00 && sum2<55.00 && sum3<55.00) || (sum2>=55.00 && sum1<55.00 && sum3<55.00) || (sum3>=55.00 && sum1<55.00 && sum2<55.00)){
    printf("\n Jedan student je polozio: ");
}
else if (sum1>=55.00 && sum2>=55.00 && sum3>=55.00){
    printf("\n Sva tri studenta su polozila: ");
}
if(sum1>=55.00 && sum2>=55.00 && sum3>=55.00){
    if((sum1==sum2)<epsilon && (sum2==sum3)<epsilon && (sum1==sum3)<epsilon){
        printf("\n Sva tri studenta imaju istu ocjenu. ");
    }
else if ((sum1==sum2)<epsilon || (sum2==sum3)<epsilon || (sum1==sum3)<epsilon){
    printf("\n Dva od tri studenta imaju istu ocjenu. ");
}    
else if ((sum1!=sum2)<epsilon && (sum2!=sum3)<epsilon && (sum1!=sum3)<epsilon){
    printf("\n Svaki student ima razlicitu ocjenu. ");
}
}
return 0;
}


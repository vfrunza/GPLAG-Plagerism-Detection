#include <stdio.h>
#define A 100
#define b 92
#define C 85
#define D 75
#define E 65
#define F 55
int main () {
    double t1,t2,t3,t4,t5,b1,b2,b3,b4,b5,m1,m2,m3,m4,m5,T,M,B;
scanf ("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &t1,&t2,&t3,&t4,&t5,&b1,&b2,&b3,&b4,&b5,&m1,&m2,&m3,&m4,&m5);
printf("Unesite bodove za Tarika:\n");
printf("I parcijalni ispit: ");
   if (t1>20||t1<0) { 
    printf ("Neispravan broj bodova\n");
    return 0;
    }
    printf("II parcijalni ispit: ");
    if (t2>20||t2<0) {
        printf ("Neispravan broj bodova\n");
        return 0;
    }
    printf("Prisustvo: ");
    if (t3<0||t3>10) {
        printf ("Neispravan broj bodova\n");
        return 0;
    }
    printf("Zadace: ");
    if (t4<0||t4>10) {
        printf ("Neispravan broj bodova\n");
        return 0;
    }
    printf("Zavrsni ispit: ");
    if (t5<0||t5>40) {
        printf ("Neispravan broj bodova\n");
        return 0;
    }
    printf("Unesite bodove za Bojana:\n");
    printf("I parcijalni ispit: ");
    if (b1>20||b1<0) { 
    printf ("Neispravan broj bodova\n");
    return 0;
    }
    printf("II parcijalni ispit: ");
    if (b2>20||b2<0) {
        printf ("Neispravan broj bodova\n");
        return 0;
    }
    printf("Prisustvo: ");
    if (b3<0||b3>10) {
        printf ("Neispravan broj bodova\n");
        return 0;
    }
    printf("Zadace: ");
    if (b4<0||b4>10) {
        printf ("Neispravan broj bodova\n");
        return 0;
    }
    printf("Zavrsni ispit: ");
    if (b5<0||b5>40) {
        printf ("Neispravan broj bodova\n");
        return 0;
    }
    printf("Unesite bodove za Mirzu:\n");
    printf("I parcijalni ispit: ");
    if (m1>20||m1<0) { 
    printf ("Neispravan broj bodova\n");
    return 0;
    }
    printf("II parcijalni ispit: ");
    if (m2>20||m2<0) {
        printf ("Neispravan broj bodova\n");
        return 0;
    }
    printf("Prisustvo: ");
    if (m3<0||m3>10) {
        printf ("Neispravan broj bodova\n");
        return 0;
    }
    printf("Zadace: ");
    if (m4<0||m4>10) {
        printf ("Neispravan broj bodova\n");
        return 0;
    }
    printf ("Zavrsni ispit: ");
    if (m5<0||m5>40) {
        printf ("Neispravan broj bodova\n");
        return 0;
    }
    T=t1+t2+t3+t4+t5;
    M=m1+m2+m3+m4+m5;
    B=b1+b2+b3+b4+b5;
    if (T<F&&B<F&&M<F) {
        printf ("Nijedan student nije polozio.\n");
        return 0;
    }
    if (T>=F&&B<F&&M<F) {
        printf ("Jedan student je polozio.\n");
        return 0;
    }
    if (T<F&&B>=F&&M<F) {
        printf("Jedan student je polozio.\n");
        return 0;
    }
    if  (T<F&&B<F&&M>=F) {
        printf ("Jedan student je polozio.\n");
        return 0;
    }
    if (T>=F&&(B<F||M<F)) {
        printf ("Dva studenta su polozila.\n");
        return 0;
    }
    if (T>=F&&B>=F&&M>=F) {
    printf ("Sva tri studenta su polozila.\n");
    }
    if (((T>b)&&(T<A))&&((B>b)&&(B<A))&&((M>b)&&(M<A))) {
        printf ("Sva tri studenta imaju istu ocjenu.\n");
    }
    if (((T>C)&&(T<b))&&((B>C)&&(B<C))&&((M>C)&&(M<b))) {
        printf ("Sva tri studenta imaju istu ocjenu.\n");
    }
    if (((T>D)&&(T<C))&&((B>D)&&(B<C))&&((M>D)&&(M<C))) {
        printf ("Sva tri studenta imaju istu ocjenu.\n");
    }
    if (((T>E)&&(T<D))&&((B>E)&&(B<D))&&((M>E)&&(M<D))) {
        printf ("Sva tri studenta imaju istu ocjenu.\n");
    }
    if (((T>F)&&(T<E))&&((B>F)&&(B<E))&&((M>F)&&(M<E))) {
        printf ("Sva tri studenta imaju istu ocjenu.");
    }
    if (((T>b)&&(T<A))&&((B>b)&&(B<A))&&((M>C)||(M>D)||(M>E))) {
        printf ("Dva od tri studenta imaju istu ocjenu.");
    }
    if (((T>C)&&(T<b))&&((B>C)&&(B<b))&&((M>b)&&(M<A)||(M<C))) {
        printf ("Dva od tri studenta imaju istu ocjenu.");
    }
    if (((T>D)&&(T<C))&&((B>D)&&(B<C))&&((M>C)||(M>D))) {
        printf ("Dva od tri studenta imaju istu ocjenu.");
    } 
    if (((T>E)&&(T<D))&&((B>E)&&(B<D))&&((M>D)||(M<E))) {
        printf ("Dva od tri studenta imaju istu ocjenu.");
    }
    if (((T>F)&&(T<E))&&((B>F)&&(B<E))&&((M>E))) {
        printf ("Dva od tri studenta imaju istu ocjenu.");
    }
    if ((((T>b)&&(T<A))&&((B<b)&&(M<b)))) {
        printf ("Svaki student ima razlicitu ocjenu.");
    }
    if ((((T>C)&&(T<b))&&((B<C)&&(M<C)||(B>D)&&(M>D)))) {
        printf ("Svaki student ima razlicitu ocjenu.");
    }
    if ((((T>D)&&(T<C))&&((B<D)&&(M<D)||(B>D)&&(M>D)))) {
        printf ("Svaki student ima razlicitu ocjenu.");
    }
    if ((((T>E)&&(T<F))&&((B<E)&&(M<E)||(B>D)&&(M>D)))) {
        printf ("Svaki student ima razlicitu ocjenu.");
    }
    if ((((T>F)&&(T<E))&&((B>E)&&(M>E)))) {
        printf ("Svaki student ima razlicitu ocjenu.");
    }
    return 0;
}
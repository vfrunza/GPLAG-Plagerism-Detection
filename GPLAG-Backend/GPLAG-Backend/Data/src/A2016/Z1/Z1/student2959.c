#include <stdio.h>
#define EPS 10e-6
int main () {
	int pad=0, oc6=6, oc7=7, oc8=8, oc9=9, oc10=10;
	float a, a1, a2, a3, a4, a5, b, b1, b2, b3, b4, b5, c, c1, c2, c3, c4, c5;
    printf ("Unesite bodove za Tarika:\n");
    printf ("I parcijalni ispit: ");
    scanf ("%f",&a1);
    if (a1<0 || a1>20) {
    	printf ("Neispravan broj bodova");
    	goto kraj;
    }
    printf ("II parcijalni ispit: ");
    scanf ("%f",&a2);
    if (a2<0 || a2>20) {
    	printf ("Neispravan broj bodova");
    	goto kraj;
    }
    printf ("Prisustvo: ");
    scanf ("%f",&a3);
    if (a3<0 || a3>10) {
    	printf ("Neispravan broj bodova");
    	goto kraj;
    }
    printf ("Zadace: ");
    scanf ("%f",&a4);
    if (a4<0 || a4>10) {
    	printf ("Neispravan broj bodova");
    	goto kraj;
    }
    printf ("Zavrsni ispit: ");
    scanf ("%f",&a5);
    if (a5<0 || a5>40) {
    	printf ("Neispravan broj bodova");
    	goto kraj;
    }
    printf ("Unesite bodove za Bojana:\n");
    printf ("I parcijalni ispit: ");
    scanf ("%f",&b1);
    if (b1<0 || b1>20) {
    	printf ("Neispravan broj bodova");
    	goto kraj;
    }
    printf ("II parcijalni ispit: ");
    scanf ("%f",&b2);
    if (b2<0 || b2>20) {
    	printf ("Neispravan broj bodova");
    	goto kraj;
    }
    printf ("Prisustvo: ");
    scanf ("%f",&b3);
    if (b3<0 || b3>10) {
    	printf ("Neispravan broj bodova");
    	goto kraj;
    }
    printf ("Zadace: ");
    scanf ("%f",&b4);
    if (b4<0 || b4>10) {
    	printf ("Neispravan broj bodova");
    	goto kraj;
    }
    printf ("Zavrsni ispit: ");
    scanf ("%f",&b5);
    if (b5<0 || b5>40) {
    	printf ("Neispravan broj bodova");
    	goto kraj;
    }
    printf ("Unesite bodove za Mirzu:\n");
    printf ("I parcijalni ispit: ");
    scanf ("%f",&c1);
    if (c1<0 || c1>20) {
    	printf ("Neispravan broj bodova");
    	goto kraj;
    }
    printf ("II parcijalni ispit: ");
    scanf ("%f",&c2);
    if (c2<0 || c2>20) {
    	printf ("Neispravan broj bodova");
    	goto kraj;
    }
    printf ("Prisustvo: ");
    scanf ("%f",&c3);
    if (c3<0 || c3>10) {
    	printf ("Neispravan broj bodova");
    	goto kraj;
    }
    printf ("Zadace: ");
    scanf ("%f",&c4);
    if (c4<0 || c4>10) {
    	printf ("Neispravan broj bodova");
    	goto kraj;
    }
    printf ("Zavrsni ispit: ");
    scanf ("%f",&c5);
    if (c5<0 || c5>40) {
    	printf ("Neispravan broj bodova");
    	goto kraj;
    }
    a = a1+a2+a3+a4+a5;
    b = b1+b2+b3+b4+b5;
    c = c1+c2+c3+c4+c5;
    if (a<55-EPS)  a=pad;
    if (a>=55 && a<65-EPS)  a=oc6;
    if (a>=65 && a<75-EPS)  a=oc7;
    if (a>=75 && a<85-EPS)  a=oc8;
    if (a>=85 && a<92-EPS)  a=oc9;
    if (a>=92)  a=oc10;
    if (b<55-EPS)  b=pad;
    if (b>=55 && b<65-EPS)  b=oc6;
    if (b>=65 && b<75-EPS)  b=oc7;
    if (b>=75 && b<85-EPS)  b=oc8;
    if (b>=85 && b<92-EPS)  b=oc9;
    if (b>=92)  b=oc10;
    if (c<55-EPS)  c=pad;
    if (c>=55 && c<65-EPS)  c=oc6;
    if (c>=65 && c<75-EPS)  c=oc7;
    if (c>=75 && c<85-EPS)  c=oc8;
    if (c>=85 && c<92-EPS)  c=oc9;
    if (c>=92)  c=oc10;
    if (a==pad && b==pad && c==pad)  printf ("Nijedan student nije polozio.");
    if ((a!=pad && b==pad && c==pad) || (a==pad && b!=pad && c==pad) || (a==pad && b==pad && c!=pad))  printf ("Jedan student je polozio.");
    if ((a==pad && b!=pad && c!=pad) || (a!=pad && b==pad && c!=pad) || (a!=pad && b!=pad && c==pad))  printf ("Dva studenta su polozila.");
    if (a!=pad && b!=pad && c!=pad) {
        printf ("Sva tri studenta su polozila.\n");
        if (a==b && a==c)  printf ("Sva tri studenta imaju istu ocjenu.");
        if ((a==b && a!=c) || (b==c && b!=a) || (c==a && c!=b))  printf ("Dva od tri studenta imaju istu ocjenu.");
        if (a!=b && a!=c)  printf ("Svaki student ima razlicitu ocjenu.");
    }
    kraj:
	return 0;
}

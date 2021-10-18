#include <stdio.h>
#include <math.h>
#define EPSILON 0.1
int main () {
	double p_p_t, d_p_t, p_t, z_t, z_i_t, p_p_b, d_p_b, p_b, z_b, z_i_b, p_p_m, d_p_m, p_m, z_m, z_i_m, o_t, o_b, o_m; 
	int s_p = 0, o_6 = 0, o_7 = 0, o_8 = 0, o_9 = 0, o_10 = 0;
	
	/*Unos bodova za sva tri studenta & ispis odgovarajuce poruke ukoliko bodovi nisu ispravno upisani*/
	
	printf ("Unesite bodove za Tarika: ");
	printf ("\nI parcijalni ispit: ");
	scanf ("%lf", &p_p_t);
	if (p_p_t < 0 || p_p_t > 20) {
		printf ("Neispravan broj bodova ");
		return 0;
	}
	else {
		printf ("II parcijalni ispit: ");
		scanf ("%lf", &d_p_t);
	}
	if (d_p_t < 0 || d_p_t > 20) {
		printf ("Neispravan broj bodova ");
		return 0;
	}
	else {
		printf ("Prisustvo: ");
		scanf ("%lf", &p_t);
	}
	if (p_t < 0 || p_t > 10) {
		printf ("Neispravan broj bodova ");
		return 0;
	}
	else {
		printf ("Zadace: ");
		scanf ("%lf", &z_t);
	}
	if (z_t < 0 || z_t > 10) {
		printf ("Neispravan broj bodova ");
		return 0;
	}
	else {
		printf ("Zavrsni ispit: ");
		scanf ("%lf", &z_i_t);
	}
	if (z_i_t < 0 || z_i_t > 40) {
		printf ("Neispravan broj bodova ");
		return 0;
	}
	else {
		printf ("Unesite bodove za Bojana: ");
		printf ("\nI parcijalni ispit: ");
		scanf ("%lf", &p_p_b);
	}
	if (p_p_b < 0 || p_p_b > 20) {
		printf ("Neispravan broj bodova ");
		return 0;
	}
	else {
		printf ("II parcijalni ispit: ");
		scanf ("%lf", &d_p_b);
	}
	if (d_p_b < 0 || d_p_b > 20) {
		printf ("Neispravan broj bodova ");
		return 0;
	}
	else {
		printf ("Prisustvo: ");
		scanf ("%lf", &p_b);
	}
	if (p_b < 0 || p_b > 10) {
		printf ("Neispravan broj bodova ");
		return 0;
	}
	else {
		printf ("Zadace: ");
		scanf ("%lf", &z_b);
	}
	if (z_b < 0 || z_b > 10) {
		printf ("Neispravan broj bodova ");
		return 0;
	}
	else {
		printf ("Zavrsni ispit: ");
		scanf ("%lf", &z_i_b);
	}
	if (z_i_b < 0 || z_i_b > 40) {
		printf ("Neispravan broj bodova ");
		return 0;
	}
	else {
		printf ("Unesite bodove za Mirzu: ");
		printf ("\nI parcijalni ispit: ");
		scanf ("%lf", &p_p_m);
	}
	if (p_p_m < 0 || p_p_m > 20) {
		printf ("Neispravan broj bodova ");
		return 0;
	}
	else {
		printf ("II parcijalni ispit: ");
		scanf ("%lf", &d_p_m);
	}
	if (d_p_m < 0 || d_p_m > 20) {
		printf ("Neispravan broj bodova ");
		return 0;
	}
	else {
		printf ("Prisustvo: ");
		scanf ("%lf", &p_m);
	}
	if (p_m < 0 || p_m > 10) {
		printf ("Neispravan broj bodova ");
		return 0;
	}
	else {
		printf ("Zadace: ");
		scanf ("%lf", &z_m);
	}
	if (z_m < 0 || z_m > 10) {
		printf ("Neispravan broj bodova ");
		return 0;
	}
	else {
		printf ("Zavrsni ispit: ");
		scanf ("%lf", &z_i_m);
	}
	if (z_i_m < 0 || z_i_m > 40) {
		printf ("Neispravan broj bodova ");
		return 0;
	}
	
	/*Obrada unesenih podataka & racunanje sume bodova & dodjela odgovarajuce ocjene*/
	
	o_t = p_p_t + d_p_t + p_t + z_t + z_i_t;
	o_b = p_p_b + d_p_b + p_b + z_b + z_i_b;
	o_m = p_p_m + d_p_m + p_m + z_m + z_i_m;
	
	if (o_t < 55) s_p++;
	else if (o_t >= 55 && o_t < 65) o_6++;
	else if (o_t >= 65 && o_t < 75) o_7++;
	else if (o_t >= 75 && o_t < 85) o_8++;
	else if (o_t >= 85 && o_t < 92) o_9++;
	else o_10++;
	if (o_b < 55) s_p++;
	else if (o_b >= 55 && o_b < 65) o_6++;
	else if (o_b >= 65 && o_b < 75) o_7++;
	else if (o_b >= 75 && o_b < 85) o_8++;
	else if (o_b >= 85 && o_b < 92) o_9++;
	else o_10++;
	if (o_m < 55) s_p++;
	else if (o_m >= 55 && o_m < 65) o_6++;
	else if (o_m >= 65 && o_m < 75) o_7++;
	else if (o_m >= 75 && o_m < 85) o_8++;
	else if (o_m >= 85 && o_m < 92) o_9++;
	else o_10++;
	
	/*Provjera prolaznosti studenata & provjera slicnosti ocjena & ispis rezultata*/
	
	if (s_p==3) {
		printf ("Nijedan student nije polozio.");
		return 0;
		}
	else if (s_p==2) {
		printf ("Jedan student je polozio.");
		return 0;
		}
	else if (s_p==1) {
		printf ("Dva studenta su polozila.");
		return 0;
		}
	else printf ("Sva tri studenta su polozila.");
	
		if (o_6==3 || o_7==3 || o_8==3 || o_9==3 || o_10==3) printf ("\nSva tri studenta imaju istu ocjenu.");
		else if (o_6==2 || o_7==2 || o_8==2 || o_9==2 || o_10==2) printf ("\nDva od tri studenta imaju istu ocjenu.");
		else printf ("\nSvaki student ima razlicitu ocjenu.");
		
return 0;
}
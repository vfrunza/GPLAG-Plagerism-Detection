#include <stdio.h>

int main() {
	double brojac_ocjena=0; double suma_tarik, suma_bojan, suma_mirza;
	double ocjena_tarik, ocjena_bojan, ocjena_mirza;
	double brojac_razlicitih=0;
	double prvi_parcijalni_tarik, drugi_parcijalni_tarik, prisustvo_tarik, zavrsni_ispit_tarik;
	double prvi_parcijalni_bojan, drugi_parcijalni_bojan, prisustvo_bojan, zavrsni_ispit_bojan;
	double prvi_parcijalni_mirza, drugi_parcijalni_mirza, prisustvo_mirza, zavrsni_ispit_mirza;
	double zadace_tarik, zadace_bojan, zadace_mirza;
	printf("Unesite bodove za Tarika:");
	printf("\nI parcijalni ispit: "); 
	scanf("%lf", &prvi_parcijalni_tarik); if(prvi_parcijalni_tarik<0 || prvi_parcijalni_tarik>20) { printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf", &drugi_parcijalni_tarik);  if(drugi_parcijalni_tarik<0 ||drugi_parcijalni_tarik>20) { printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%lf", &prisustvo_tarik); if(prisustvo_tarik<0 || prisustvo_tarik>10) { printf("Neispravan broj bodova"); return 0;}
	printf("Zadace:");
	scanf("%lf", &zadace_tarik); if (zadace_tarik<0 || zadace_tarik>10) { printf("Neispravan broj bodova"); return 0;}
	printf(" Zavrsni ispit: ");
	scanf("%lf", &zavrsni_ispit_tarik); if(zavrsni_ispit_tarik<0 || zavrsni_ispit_tarik>40) { printf("Neispravan broj bodova"); return 0;}
	printf("Unesite bodove za Bojana: ");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &prvi_parcijalni_bojan); if(prvi_parcijalni_bojan<0 || prvi_parcijalni_bojan>20) { printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf", &drugi_parcijalni_bojan); if(drugi_parcijalni_bojan<0 ||drugi_parcijalni_bojan>20) { printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%lf", &prisustvo_bojan); if(prisustvo_bojan<0 || prisustvo_bojan>10 ) { printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%lf", &zadace_bojan); if(zadace_bojan<0 || zadace_bojan>10) { printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf", &zavrsni_ispit_bojan); if(zavrsni_ispit_bojan<0 ||zavrsni_ispit_bojan>40) { printf("Neispravan broj bodova"); return 0;}
	printf("Unesite bodove za Mirzu: ");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &prvi_parcijalni_mirza); if (prvi_parcijalni_mirza<0 || prvi_parcijalni_mirza>20) { printf("Neispravan broj bodova"); return 0;}
 	printf("II parcijalni ispit: ");
	scanf("%lf", &drugi_parcijalni_mirza); if (drugi_parcijalni_mirza<0 ||drugi_parcijalni_mirza>20) { printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%lf", &prisustvo_mirza); if (prisustvo_mirza<0 || prisustvo_mirza>10) { printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%lf", &zadace_mirza); if (zadace_mirza<0 || zadace_mirza>10) { printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf", &zavrsni_ispit_mirza); if (zavrsni_ispit_mirza<0 || zavrsni_ispit_mirza>40) { printf("Neispravan broj bodova"); return 0;}
	if( prvi_parcijalni_mirza<0 || prvi_parcijalni_tarik <0 || prvi_parcijalni_bojan<0  || drugi_parcijalni_mirza <0 || drugi_parcijalni_bojan<0 || drugi_parcijalni_tarik<0 || prisustvo_mirza<0 || prisustvo_bojan<0 || prisustvo_tarik<0 || zavrsni_ispit_mirza<0 || zavrsni_ispit_bojan<0 || zavrsni_ispit_tarik<0 || zadace_mirza<0 || zadace_bojan<0 || zadace_tarik<0 || prvi_parcijalni_mirza>20 || prvi_parcijalni_tarik >20 || prvi_parcijalni_bojan>20  || drugi_parcijalni_mirza >20 || drugi_parcijalni_bojan>20 || drugi_parcijalni_tarik>20 || prisustvo_mirza>10 || prisustvo_bojan>10 || prisustvo_tarik>10 || zavrsni_ispit_mirza>40 || zavrsni_ispit_bojan>40 || zavrsni_ispit_tarik>40 || zadace_mirza>10 || zadace_bojan>10 || zadace_tarik>10)
{
	printf("Neispravan broj bodova");
	return 0;
}	
else
{ suma_tarik=prvi_parcijalni_tarik+drugi_parcijalni_tarik+prisustvo_tarik+zadace_tarik+zavrsni_ispit_tarik;
  suma_mirza=prvi_parcijalni_mirza+drugi_parcijalni_mirza+prisustvo_mirza+zadace_mirza+zavrsni_ispit_mirza;
  suma_bojan=prvi_parcijalni_bojan+drugi_parcijalni_bojan+prisustvo_bojan+zadace_bojan+zavrsni_ispit_bojan;
  if(suma_tarik>=55 && suma_tarik<65) { ocjena_tarik=6; }
  else if(suma_tarik>=65 && suma_tarik<75) { ocjena_tarik=7;}
  else if(suma_tarik>=75 && suma_tarik<85) {ocjena_tarik=8;}
  else if(suma_tarik>=85 && suma_tarik<92) { ocjena_tarik=9;}
  else if(suma_tarik>=92 && suma_tarik<=100) { ocjena_tarik=10;}
  else ocjena_tarik=5;
  if(suma_bojan>=55 && suma_bojan<65) { ocjena_bojan=6; }
  else if(suma_bojan>=65 && suma_bojan<75) { ocjena_bojan=7;}
  else if(suma_bojan>=75 && suma_bojan<85) {ocjena_bojan=8;}
  else if(suma_bojan>=85 && suma_bojan<92) { ocjena_bojan=9;}
  else if(suma_bojan>=92 && suma_bojan<=100) { ocjena_bojan=10;}
  else ocjena_bojan=5;
  if(suma_mirza>=55 && suma_mirza<65) { ocjena_mirza=6; }
  else if(suma_mirza>=65 && suma_mirza<75) { ocjena_mirza=7;}
  else if(suma_mirza>=75 && suma_mirza<85) {ocjena_mirza=8;}
  else if(suma_mirza>=85 && suma_mirza<92) { ocjena_mirza=9;}
  else if(suma_mirza>=92 && suma_mirza<=100) { ocjena_mirza=10;}
  else ocjena_mirza=5;
  
	if(ocjena_mirza>=6 && ocjena_mirza<=10) brojac_ocjena++;
	if(ocjena_tarik>=6 && ocjena_tarik<=10) brojac_ocjena++;
	if(ocjena_bojan>=6 && ocjena_bojan<=10) brojac_ocjena++;
	if(ocjena_mirza!=ocjena_bojan) brojac_razlicitih++;
	if(ocjena_mirza!=ocjena_tarik) brojac_razlicitih++;
	if(ocjena_tarik!=ocjena_bojan) brojac_razlicitih++;
	if(brojac_ocjena==0) { printf("Nijedan student nije polozio.\n"); }
	else if(brojac_ocjena==1) {printf("Jedan student je polozio.\n");}
	else if(brojac_ocjena==2) {printf("Dva studenta su polozila.\n"); }
	else if(brojac_ocjena==3) {printf("Sva tri studenta su polozila.\n"); }
	
	if(brojac_ocjena==3)
	{
		if(brojac_razlicitih==3) { printf("Svaki student ima razlicitu ocjenu.\n"); }
	else 	if(brojac_razlicitih==2) { printf("Dva od tri studenta imaju istu ocjenu.\n"); }
	else	if(brojac_razlicitih==0) { printf("Sva tri studenta imaju istu ocjenu.\n"); }
		
	}
	
	
}
	return 0;
	
}

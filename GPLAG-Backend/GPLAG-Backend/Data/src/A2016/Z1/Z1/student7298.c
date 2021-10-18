#include <stdio.h>

int main() {
	double prvi_parcijalni_Tarik,prvi_parcijalni_Bojan,prvi_parcijalni_Mirza;
	double drugi_parcijalni_Tarik,drugi_parcijalni_Bojan,drugi_parcijalni_Mirza;
	double prisustvo_Tarik,prisustvo_Bojan,prisustvo_Mirza;
	double zadace_Tarik,zadace_Bojan,zadace_Mirza;
	double zavrsni_ispit_Tarik,zavrsni_ispit_Bojan,zavrsni_ispit_Mirza;
	double zbir_Tarik,zbir_Bojan,zbir_Mirza;
	printf("Unesite bodove za Tarika:\nI parcijalni ispit: ");
	scanf("%lf", &prvi_parcijalni_Tarik);
	if(prvi_parcijalni_Tarik<0 || prvi_parcijalni_Tarik>20){printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf", &drugi_parcijalni_Tarik);
	if(drugi_parcijalni_Tarik<0 || drugi_parcijalni_Tarik>20){printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%lf", &prisustvo_Tarik);
	if(prisustvo_Tarik<0 || prisustvo_Tarik>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%lf", &zadace_Tarik);
	if(zadace_Tarik<0 || zadace_Tarik>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf", &zavrsni_ispit_Tarik);
	if(zavrsni_ispit_Tarik<0 || zavrsni_ispit_Tarik>40) {printf("Neispravan broj bodova"); return 0;}
	printf("Unesite bodove za Bojana:\nI parcijalni ispit: ");
	scanf("%lf", &prvi_parcijalni_Bojan);
	if(prvi_parcijalni_Bojan<0 || prvi_parcijalni_Bojan>20) {printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf", &drugi_parcijalni_Bojan);
	if(drugi_parcijalni_Bojan<0 || drugi_parcijalni_Bojan>20) {printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%lf", &prisustvo_Bojan);
	if(prisustvo_Bojan<0 || prisustvo_Bojan>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%lf", &zadace_Bojan);
	if(zadace_Bojan<0 || zadace_Bojan>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf", &zavrsni_ispit_Bojan);
	if(zavrsni_ispit_Bojan<0 || zavrsni_ispit_Bojan>40) {printf("Neispravan broj bodova"); return 0;}
	printf("Unesite bodove za Mirzu:\nI parcijalni ispit: ");
	scanf("%lf", &prvi_parcijalni_Mirza);
	if(prvi_parcijalni_Mirza<0 || prvi_parcijalni_Mirza>20) {printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf", &drugi_parcijalni_Mirza);
	if(drugi_parcijalni_Mirza<0 || drugi_parcijalni_Mirza>20) {printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%lf", &prisustvo_Mirza);
	if(prisustvo_Mirza<0 || prisustvo_Mirza>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%lf", &zadace_Mirza);
	if(zadace_Mirza<0 || zadace_Mirza>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
    scanf("%lf", &zavrsni_ispit_Mirza);
    if(zavrsni_ispit_Mirza<0 || zavrsni_ispit_Mirza>40) {printf("Neispravan broj bodova"); return 0;}
    zbir_Tarik=prvi_parcijalni_Tarik+drugi_parcijalni_Tarik+prisustvo_Tarik+zadace_Tarik+zavrsni_ispit_Tarik;
    zbir_Bojan=prvi_parcijalni_Bojan+drugi_parcijalni_Bojan+prisustvo_Bojan+zadace_Bojan+zavrsni_ispit_Bojan;
    zbir_Mirza=prvi_parcijalni_Mirza+drugi_parcijalni_Mirza+prisustvo_Mirza+zadace_Mirza+zavrsni_ispit_Mirza;
    if((zbir_Tarik>=55 && zbir_Bojan<55 && zbir_Mirza<55) || (zbir_Tarik<55 && zbir_Bojan>=55 && zbir_Mirza<55) || 
    (zbir_Tarik<55 && zbir_Bojan<55 && zbir_Mirza>=55)) printf("Jedan student je polozio.\n");
    else if((zbir_Tarik>=55 && zbir_Bojan>=55 && zbir_Mirza<55) || (zbir_Tarik>=55 && zbir_Bojan<55 && zbir_Mirza>=55) ||
    (zbir_Tarik<55 && zbir_Bojan>=55 && zbir_Mirza>=55)) printf("Dva studenta su polozila.\n");
    else if(zbir_Tarik>=55 && zbir_Bojan>=55 && zbir_Mirza>=55) printf("Sva tri studenta su polozila.\n");
    else printf("Nijedan student nije polozio.\n");
    if((zbir_Tarik>=55 && zbir_Tarik<65 && zbir_Bojan>=55 && zbir_Bojan<65 && zbir_Mirza>=55 && zbir_Mirza<65) || 
    (zbir_Tarik>=65 && zbir_Tarik<75 && zbir_Bojan>=65 && zbir_Bojan<75 && zbir_Mirza>=65 && zbir_Mirza<75) ||
    (zbir_Tarik>=75 && zbir_Tarik<85 && zbir_Bojan>=75 && zbir_Bojan<85 && zbir_Mirza>=75 && zbir_Mirza<85) ||
    (zbir_Tarik>=85 && zbir_Tarik<92 && zbir_Bojan>=85 && zbir_Bojan<92 && zbir_Mirza>=85 && zbir_Mirza<92) ||
    (zbir_Tarik>=92 && zbir_Tarik<=100 && zbir_Bojan>=92 && zbir_Bojan<=100 && zbir_Mirza>=92 && zbir_Mirza<=100)) 
    printf("Sva tri studenta imaju istu ocjenu.");
    else if((zbir_Tarik>=55 && zbir_Tarik<65 && ((zbir_Mirza>=55 && zbir_Mirza<65) || (zbir_Bojan>=55 && zbir_Bojan<65))) ||
    (zbir_Mirza>=55 && zbir_Mirza<65 && zbir_Bojan>=55 && zbir_Bojan<65) ||
    (zbir_Tarik>=65 && zbir_Tarik<75 && ((zbir_Mirza>=65 && zbir_Mirza<65) || (zbir_Bojan>=65 && zbir_Bojan<75))) ||
    (zbir_Mirza>=65 && zbir_Mirza<75 && zbir_Bojan>=65 && zbir_Bojan<75) ||
    (zbir_Tarik>=75 && zbir_Tarik<85 && ((zbir_Mirza>=75 && zbir_Mirza<85) || (zbir_Bojan>=75 && zbir_Bojan<75))) ||
    (zbir_Mirza>=75 && zbir_Mirza<85 && zbir_Bojan>=75 && zbir_Bojan<85) ||
    (zbir_Tarik>=85 && zbir_Tarik<92 && ((zbir_Mirza>=85 && zbir_Mirza<92) || (zbir_Bojan>=85 && zbir_Bojan<92))) ||
    (zbir_Mirza>=85 && zbir_Mirza<92 && zbir_Bojan>=85 && zbir_Bojan<92) ||
    (zbir_Tarik>=92 && zbir_Tarik<=100 && ((zbir_Mirza>=92 && zbir_Mirza<=100) || (zbir_Bojan>=92 && zbir_Bojan<=100))) ||
    (zbir_Mirza>=92 && zbir_Mirza<=100 && zbir_Bojan>=92 && zbir_Bojan<=100)) printf("Dva od tri studenta imaju istu ocjenu.");
    else if(zbir_Tarik<55 || zbir_Mirza<55 || zbir_Bojan<55) return 0;
    else printf("Svaki student ima razlicitu ocjenu.");
	return 0;
}

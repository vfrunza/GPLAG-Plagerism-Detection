#include <stdio.h>
#include<math.h>
#define EPSILON 0.001

int main() {
	double parc_tarik1,parc_tarik2,pr_t,z_t,zi_t,parc_bojan1,parc_bojan2,pr_b,z_b,zi_b;
	double parc_mirza1,parc_mirza2,pr_m,z_m,zi_m;
	double bt,bb,bm;
	int m,b,t;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: "); scanf("%lf", &parc_tarik1);
	if(parc_tarik1<0 || parc_tarik1>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: "); scanf("%lf", &parc_tarik2);
	if(parc_tarik2<0 || parc_tarik2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: "); scanf("%lf", &pr_t);
	if(pr_t<0 || pr_t>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: "); scanf("%lf", &z_t);
	if (z_t<0 || z_t>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: "); scanf("%lf", &zi_t);
	if(zi_t<0 || zi_t>40){
		printf("Neispravan broj bodova");
		return 0; 
	}
	
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: "); scanf("%lf", &parc_bojan1);
	if(parc_bojan1<0 || parc_bojan1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: "); scanf("%lf", &parc_bojan2);
	if(parc_bojan2<0 || parc_bojan2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: "); scanf("%lf", &pr_b);
	if(pr_b<0 || pr_b>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: "); scanf("%lf", &z_b);
	if(z_b<0 || z_b>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: "); scanf("%lf", &zi_b);
	if(zi_b<0 || zi_b>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: "); scanf("%lf", &parc_mirza1);
	if(parc_mirza1<0 || parc_mirza1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: "); scanf("%lf", &parc_mirza2);
	if(parc_mirza2<0 || parc_mirza2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: "); scanf("%lf", &pr_m);
	if(pr_m<0 || pr_m>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: "); scanf("%lf", &z_m);
	if(z_m<0 || z_m>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: "); scanf("%lf", &zi_m);
	if(zi_m<0 || zi_m>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	bt=parc_tarik1+parc_tarik2+pr_t+z_t+zi_t;
	bb=parc_bojan1+parc_bojan2+pr_b+z_b+zi_b;
	bm=parc_mirza1+parc_mirza2+pr_m+z_m+zi_m;
	

	
	
	if(bt<55 && bb<55 && bm<55){
		printf("Nijedan student nije polozio.\n");
	}
	if((bt>=55 && bb<55 && bm<55)|| (bt<55 && bb>=55 && bm<55)|| (bt<55 && bb<55 && bm>=55)){
		printf("Jedan student je polozio.\n");
	}
	if((bt>=55 && bb>=55 && bm<55)|| (bt>=55 && bb<55 && bm>=55)|| (bt<55 && bb>=55 && bm>=55)){
		printf("Dva studenta su polozila.\n");
	}
	if(bt>=55 && bb>=55 && bm>=55){
		printf("Sva tri studenta su polozila.\n");
	
	t=6+(bt-55)/10;
	b=6+(bb-55)/10;
	m=6+(bm-55)/10;
	if(fabs(t-b)<EPSILON && fabs(b-m)<EPSILON){
		printf("Sva tri studenta imaju istu ocjenu.\n");
	}
	if(fabs(t-b)<EPSILON && fabs(b-m)>EPSILON){
		printf("Dva od tri studenta imaju istu ocjenu.\n");
	}
	if(fabs(t-m)<EPSILON && fabs(b-m)>EPSILON){
		printf("Dva od tri studenta imaju istu ocjenu.\n");
	}
	if(fabs(m-b)<EPSILON && fabs(t-b)>EPSILON){
		printf("Dva od tri studenta imaju istu ocjenu.\n");
	}
	
	if(fabs(t-b)>EPSILON && fabs(t-b)>EPSILON){
		printf("Svaki student ima razlicitu ocjenu.\n");
	}
	
}
	
	return 0;
}

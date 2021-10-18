#include <stdio.h>


int main() {
	
	float ta = 0.0 ; 
	float tb=0.0;
	float tp=0.0;
	float tz=0.0;
	float tzi=0.0;
    float ba=0.0;
    float bb=0.0; 
    float bp=0.0;
    float bz=0.0;
    float bzi=0.0;
    float ma=0.0;
    float mb=0.0;
    float mp=0.0;
    float mz=0.0;
    float mzi=0.0;
	float tu=0.0;
	float bu=0.0;
	float mu=0.0;
	
	int Tarik=0,Bojan=0,Mirza=0;
	
	
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%f",&ta);
	if (ta<0 || ta>20 ) {printf("Neispravan broj bodova"); return 0 ;}
	printf("II parcijalni ispit: ");
	scanf("%f",&tb);
	if (tb<0 || tb>20) { printf("Neispravan broj bodova"); return 0 ;}
	printf("Prisustvo: ");
	scanf("%f",&tp);
	if (tp<0 || tp>10) { printf("Neispravan broj bodova"); return 0 ;}
	printf("Zadace: ");
	scanf("%f",&tz);
	if (tz<0 || tz>10) { printf("Neispravan broj bodova"); return 0 ;}
	printf("Zavrsni ispit: ");
	scanf("%f",&tzi);
	if (tzi<0 || tzi>40) {printf("Neispravan broj bodova"); return 0 ;}
	
	
	
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%f",&ba);
	if (ba<0 || ba>20) {printf("Neispravan broj bodova"); return 0 ;}
	printf("II parcijalni ispit: ");
	scanf("%f",&bb);
	if (bb<0 || bb>20){printf("Neispravan broj bodova"); return 0 ;}
	printf("Prisustvo: ");
	scanf("%f",&bp);
	if (bp<0 || bp>10){printf("Neispravan broj bodova"); return 0 ;}
	printf("Zadace: ");
	scanf("%f",&bz);
	if (bz<0 || bz>10){printf("Neispravan broj bodova"); return 0 ;}
	printf("Zavrsni ispit: ");
	scanf("%f",&bzi);
	if (bzi<0 || bzi>40){printf("Neispravan broj bodova"); return 0 ;}
	
	
	
	
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%f",&ma);
	if(ma<0 || ma>20){printf("Neispravan broj bodova"); return 0 ;}
	printf("II parcijalni ispit: ");
	scanf("%f",&mb);
	if(mb<0 || mb>20){printf("Neiapravan broj bodova"); return 0 ;}
	printf("Prisustvo: ");
	scanf("%f",&mp); 
	if(mp<0 || mp>10){printf("Neispravan broj bodova"); return 0 ;}
	printf("Zadace: ");
	scanf("%f",&mz);
	if (mz<0 || mz>10){printf("Neispravan broj bodova"); return 0 ;}
	printf("Zavrsni ispit: ");
	scanf("%f",&mzi);
	if(mzi<0 || mzi>40){printf("Neispravan broj bodova"); return 0 ;}
	
	/* dodao +0.00001 zato sto float ne zaokruzuje dobro*/
	tu=ta+tb+tp+tz+tzi+0.00001;
	bu=ba+bb+bp+bz+bzi+0.00001;
	mu=ma+mb+mp+mz+mzi+0.00001;
	
	if(tu>=55 && tu<65) Tarik=6;
	if(tu>=65 && tu<75) Tarik=7;
	if(tu>=75 && tu<85) Tarik=8;
	if(tu>=85 && tu<92) Tarik=9;
	if(tu>=92 && tu<=100) Tarik=10;
	
	
	if(bu>=55 && bu<65) Bojan=6;
	if(bu>=65 && bu<75) Bojan=7;
	if(bu>=75 && bu<85) Bojan=8;
	if(bu>=85 && bu<92) Bojan=9;
	if(bu>=92 && bu<=100) Bojan=10;
	
	
	if(mu>=55 && mu<65) Mirza=6;
	if(mu>=65 && mu<75) Mirza=7;
	if(mu>=75 && mu<85) Mirza=8;
	if(mu>=85 && mu<92) Mirza=9;
	if(mu>=92 && mu<=100) Mirza=10;
	

	
	if(tu<55 && bu<55 && mu<55) {printf("Nijedan student nije polozio.");return 0 ; }
	
	if((tu>=55 && bu<55 && mu<55) || (tu<55 && bu>=55 && mu<55) ||
	(tu<55 && bu<55 && mu>=55)) {printf("Jedan student je polozio."); return 0 ;}
	
	if((tu>=55 && bu>=55 && mu<55) || (tu>=55 && bu<55 && mu>=55) || 
	(tu<55 && bu>=55 && mu>=55)){ printf("Dva studenta su polozila."); return 0 ;}
	
	if(tu>=55 && bu>=55 && mu>=55) {printf("Sva tri studenta su polozila.\n");
	
	                                if  ( (Tarik!=Bojan) && (Tarik!=Mirza) && (Bojan!=Mirza)) {printf("Svaki student ima razlicitu ocjenu."); return 0 ;}
		                            else if  ((Tarik==Bojan) && (Tarik==Mirza) && (Bojan==Mirza)) printf("Sva tri studenta imaju istu ocjenu.");
		                            else if  (((Tarik==Bojan)&&(Bojan!=Mirza)) || ((Tarik==Mirza)&&(Tarik!=Bojan)) || ((Bojan==Mirza)&&(Bojan!=Tarik))) printf("Dva od tri studenta imaju istu ocjenu.");
	}
	
	
	
	
	
	
	
	return 0;
}
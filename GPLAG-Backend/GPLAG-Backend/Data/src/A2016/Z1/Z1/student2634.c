#include <stdio.h>

int main() {
	float  tp1, tp2, tp, tz, tzi, bp1, bp2, bp, bz, bzi, mp1, mp2, mp, mz, mzi;
	float bbt=0;
	float bbb=0;
	float bbm=0;
	int ot, ob, om;
	
	/*Unos za Tarika*/
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%f", &tp1);
	if (tp1<0|| tp1>20) 
	{ 
	printf("Neispravan broj bodova"); 
	return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &tp2);
	if (tp2<0 || tp2>20 ) 
	{ 
	printf("Neispravan broj bodova"); 
	return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &tp);
	if (tp <0 || tp>10) 
	{ 
	printf("Neispravan broj bodova"); 
	return 0;
	}
	
	printf("Zadace: ");
	scanf("%f", &tz);
	if ( tz<0 || tz>10) 
	{ 
	printf("Neispravan broj bodova"); 
	return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &tzi);
	if ( tzi<0 || tzi>40) 
	{ 
	printf("Neispravan broj bodova"); 
	return 0;
	} 
	
		bbt=tp1+tp2+tp+tz+tzi+0.1;

		if (bbt<55)  {
			ot=0;

		}
		else if (bbt>=55 && bbt<65) {
			ot=6;

		}
		else if (bbt>=65 && bbt<75) {
			ot=7;
	
		}
		else if (bbt>=75 && bbt<85) {
			ot=8;
	
		}
		else if (bbt>=85 && bbt<92) {
			ot=9;
		
		}
		else {
			ot=10;
	
	   	}

	/*Unos za Bojana*/
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%f", &bp1);
	if (bp1<0 || bp1>20 ) { 
		 printf("Neispravan broj bodova");
		 return 0;
	   	}
	printf("II parcijalni ispit: ");
	scanf("%f", &bp2);
	if (bp2<0 || bp2>20 ) { 
		 printf("Neispravan broj bodova");
		 return 0;
	   	}
	printf("Prisustvo: ");
	scanf("%f", &bp);
	if ( bp <0 || bp>10 ) { 
		 printf("Neispravan broj bodova");
		 return 0;
	   	}
	printf("Zadace: ");
	scanf("%f", &bz);
	if (bz<0 || bz>10 ) { 
		 printf("Neispravan broj bodova");
		 return 0;
	   	}
	printf("Zavrsni ispit: ");
	scanf("%f", &bzi);
	if ( bzi<0 || bzi>40) { 
		 printf("Neispravan broj bodova");
		 return 0;
	   	}
	   
		bbb=bp1+bp2+bp+bz+bzi;
		
		if (bbb<55)  {
			ob=0;
	
		}
		else if (bbb>=55 && bbb<65) {
			ob=6;
	
		}
		else if (bbb>=65 && bbb<75) {
			ob=7;
	
		}
		else if (bbb>=75 && bbb<85) {
			ob=8;
	
		}
		else if (bbb>=85 && bbb<92) {
			ob=9;
	
		}
		else {
			ob=10;
	
	   	}

	 	
	/*Unos za Mirzu*/
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%f", &mp1);
		if (mp1<0  || mp1>20 ) 
	{ 
		 printf("Neispravan broj bodova"); 
		 return 0;
	} 
	printf("II parcijalni ispit: ");
	scanf("%f", &mp2);
		if (mp2<0  || mp2>20 ) 
	{ 
		 printf("Neispravan broj bodova"); 
		 return 0;
	} 
	printf("Prisustvo: ");
	scanf("%f", &mp);
		if (mp <0 || mp>10 ) 
	{ 
		 printf("Neispravan broj bodova"); 
		 return 0;
	} 
	printf("Zadace: ");
	scanf("%f", &mz);
		if ( mz<0 || mz>10 ) 
	{ 
		 printf("Neispravan broj bodova"); 
		 return 0;
	} 
	printf("Zavrsni ispit: ");
	scanf("%f", &mzi);
	if ( mzi<0 || mzi>40) 
	{ 
		 printf("Neispravan broj bodova"); 
		 return 0;
	} 
		bbm=mp1+mp2+mp+mz+mzi;
			if (bbm<55)  {
			om=0;
	
		}
		else if (bbm>=55 && bbm<65) {
			om=6;

		}
		else if (bbm>=65 && bbm<75) {
			om=7;
		
		}
		else if (bbm>=75 && bbm<85) {
			om=8;
	
		}
		else if (bbm>=85 && bbm<92) {
			om=9;
	
		}
		else {
			om=10;

		}

	
 	if (ot==0 && ob==0 && om==0) printf("Nijedan student nije polozio."); 
	else if ((ot>5 || ot<=10) && ob==0 && om==0) printf("Jedan student je polozio.");
	else if ((ob>5 || ob<=10 )&& ot==0 && om==0) printf("Jedan student je polozio.");
	else if ((om>5 || om<=10) && ob==0 && ot==0) printf("Jedan student je polozio.");
	else if ((ot>5 || ot<=10) && (ob>5 || ob<=10) && om==0) printf("Dva studenta su polozila.");
	else if ((ot>5 || ot<=10) && (om>5 || om<=10) && ob==0) printf("Dva studenta su polozila.");
	else if ((ob>5 || ob<=10) && (om>5 || om<=10) && ot==0) printf("Dva studenta su polozila.");
	else printf ("Sva tri studenta su polozila.");
	
	if(ot!=0 && om!=0 && ob!=0){
	 if (ot==ob && ob==om) printf("\nSva tri studenta imaju istu ocjenu.");
	else if(ot==ob || ob==om || ot==om) printf("\nDva od tri studenta imaju istu ocjenu.");
	else printf("\nSvaki student ima razlicitu ocjenu.");
	}
	return 0;
}


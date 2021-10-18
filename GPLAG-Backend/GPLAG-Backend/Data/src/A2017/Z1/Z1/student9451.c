#include <stdio.h>

int main() {
	float tarikI,  tarikII, tarikPr, tarikZad, tarikZI, tarikSuma;
	float tarikOcjena;
	
	float bojanI, bojanII, bojanPr, bojanZad, bojanZI, bojanSuma;
	float  bojanOcjena;
	
	float mirzaI, mirzaII, mirzaPr, mirzaZad, mirzaZI, mirzaSuma;
	float  mirzaOcjena;
	 
	
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
    scanf("%f", &tarikI);
    if(tarikI<0 || tarikI>20) {
    	printf("Neispravan broj bodova");
    	return 0;
    }
    	printf("II parcijalni ispit: " );
	scanf("%f", &tarikII);
if(tarikII<0 || tarikII >20) {
	printf("Neispravan broj bodova");
	return 0;
}
	printf("Prisustvo: ");
scanf("%f", &tarikPr);
if(tarikPr<0 || tarikPr >10 ) {
	printf("Neispravan broj bodova");
	return 0;
}
	printf("Zadace: ");
scanf("%f", &tarikZad);
if(tarikZad<0 || tarikZad>10) {
	printf("Neispravan broj bodova");
	return 0;
	}
		printf("Zavrsni ispit: ");
	scanf("%f", &tarikZI);
	if(tarikZI<0 || tarikZI >40) {
	printf("Neispravan broj bodova");
	return 0;
	}
	
	 tarikSuma = tarikI + tarikII + tarikPr + tarikZad + tarikZI;
	 if(tarikSuma<=54.999) {
	 tarikOcjena=5;
	  } else if(tarikSuma <=65) {
	 	tarikOcjena = 6;
	 } else if(tarikSuma <=75) {
	 	tarikOcjena = 7;
	 } else if(tarikSuma <=85) {
	 	tarikOcjena = 8;
	 } else if(tarikSuma <=92) {
	 	tarikOcjena = 9;
	 } else {
	 	tarikOcjena = 10;
	 }
	 printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	 scanf("%f", &bojanI);
	if(bojanI<0 || bojanI>20) {
    printf("Neispravan broj bodova");
    return 0;
    }
    printf("II parcijalni ispit: ");
 scanf("%f", &bojanII);
if(bojanII<0 || bojanII >20) {
	printf("Neispravan broj bodova");
	return 0;
}
printf("Prisustvo: ");
scanf("%f", &bojanPr);
if(bojanPr<0 || bojanPr >10 ) {
	printf("Neispravan broj bodova");
	return 0;
}
printf("Zadace: ");
scanf("%f", &bojanZad);
if(bojanZad<0 || bojanZad>10) {
	printf("Neispravan broj bodova");
	return 0;
}
printf("Zavrsni ispit: ");
	scanf("%f", &bojanZI);
	if(bojanZI<0 || bojanZI >40) {
	printf("Neispravan broj bodova");
	return 0;
	}
	
	 bojanSuma = bojanI + bojanII + bojanPr + bojanZad + bojanZI;
	 if(bojanSuma<=54.999) {
	 bojanOcjena=5;
	  } else if(bojanSuma <=65) {
	 	bojanOcjena = 6;
	 } else if(bojanSuma <=75) {
	 	bojanOcjena = 7;
	 } else if(bojanSuma <=85) {
	 	bojanOcjena = 8;
	 } else if(bojanSuma <=92) {
	 	bojanOcjena = 9;
	 } else {
	 	bojanOcjena = 10;
	 
	 }
	 printf("Unesite bodove za Mirzu: \n");
	 printf("I parcijalni ispit: ");
	 scanf("%f", &mirzaI);
	if(mirzaI<0 || mirzaI>20) {
      printf("Neispravan broj bodova");
      return 0;
    }
     printf("II parcijalni ispit: ");
	 scanf("%f", &mirzaII);
if(mirzaII<0 || mirzaII >20) {
	printf("Neispravan broj bodova");
	return 0;
}
printf("Prisustvo: ");
	 scanf("%f", &mirzaPr);
if(mirzaPr<0 || mirzaPr >10 ) {
	printf("Neispravan broj bodova");
	return 0;
}
printf("Zadace: ");
scanf("%f", &mirzaZad);
if(mirzaZad<0 || mirzaZad>10) {
	printf("Neispravan broj bodova");
	return 0;
}
printf("Zavrsni ispit: ");
	scanf("%f", &mirzaZI);
	if(mirzaZI<0 || mirzaZI >40) {
	   printf("Neispravan broj bodova");
	   return 0;
	}
	
	 mirzaSuma = mirzaI + mirzaII + mirzaPr + mirzaZad + mirzaZI;
	 if(mirzaSuma<=54.999) {
	 mirzaOcjena=5;
	  } else if(mirzaSuma <=65) {
	 	mirzaOcjena = 6;
	 } else if(mirzaSuma <=75) {
	 	mirzaOcjena = 7;
	 } else if(mirzaSuma <=85) {
	 	mirzaOcjena = 8;
	 } else if(mirzaSuma <=92) {
	    mirzaOcjena = 9;
	 } else {
	 	mirzaOcjena = 10;
	 }

	if(tarikOcjena == 5 && bojanOcjena == 5 && mirzaOcjena==5) {
		printf("Nijedan student nije polozio.");
	} else if((tarikOcjena>=6 && bojanOcjena<6 && mirzaOcjena<6) 
				|| (bojanOcjena>=6 && tarikOcjena<6 && mirzaOcjena<6) 
				|| (mirzaOcjena>=6 && tarikOcjena<6 && bojanOcjena<6)) {
		printf("Jedan student je polozio.");
	} else if((tarikOcjena>=6 && bojanOcjena>=6 && mirzaOcjena<6) 
				|| (mirzaOcjena>=6 && tarikOcjena>=6 && bojanOcjena<6) 
				|| (mirzaOcjena>=6 && bojanOcjena>=6 && tarikOcjena<6)) {
		printf("Dva studenta su polozila.");
	} else{
		printf("Sva tri studenta su polozila.\n");
		
		if(tarikOcjena == bojanOcjena && tarikOcjena == mirzaOcjena) {
			printf("Sva tri studenta imaju istu ocjenu.");
		} else if ((tarikOcjena==bojanOcjena && tarikOcjena!=mirzaOcjena) 
					|| (tarikOcjena==mirzaOcjena && tarikOcjena != bojanOcjena) 
					|| (bojanOcjena == mirzaOcjena && bojanOcjena != tarikOcjena)) {
			printf("Dva od tri studenta imaju istu ocjenu.");
		} else {
			printf("Svaki student ima razlicitu ocjenu.");
		}
	}
	 
	 return 0;
}
	 
	 
	 	
	 
	 
	 
	 

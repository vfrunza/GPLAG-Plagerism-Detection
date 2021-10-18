#include <stdio.h>
#define e 0.0001
#include <math.h>

int main() {
	
	float Tprvi, Tdrugi, Tprisustvo, Tzadace, Tzavrsni, Tukupno, Tocena, Bprvi, Bdrugi, Bprisustvo, Bzadace, Bzavrsni, Bukupno, Bocena, Mprvi, Mdrugi, Mprisustvo, Mzadace, Mzavrsni, Mukupno, Mocena;
		printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%f", &Tprvi);
	if(Tprvi<0 || Tprvi>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &Tdrugi);
	if(Tdrugi<0 || Tdrugi>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &Tprisustvo);
	if(Tprisustvo<0 || Tprisustvo>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &Tzadace);
	if(Tzadace<0 || Tzadace>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &Tzavrsni);
	if(Tzavrsni<0 || Tzavrsni>40){
		printf("Neispravan broj bodova");
		return 0;
	}
		printf("Unesite bodove za Bojana: \n");
 	printf("I parcijalni ispit: ");
	scanf("%f", &Bprvi);
	if(Bprvi<0 || Bprvi>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &Bdrugi);
	if(Bdrugi<0 || Bdrugi>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &Bprisustvo);
	if(Bprisustvo<0 || Bprisustvo>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &Bzadace);
	if(Bzadace<0 || Bzadace>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &Bzavrsni);
	if(Bzavrsni<0 || Bzavrsni>40){
		printf("Neispravan broj bodova");
		return 0;
	}
		printf("Unesite bodove za Mirzu: \n");
 	printf("I parcijalni ispit: ");
	scanf("%f", &Mprvi);
	if(Mprvi<0 || Mprvi>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &Mdrugi);
	if(Mdrugi<0 || Mdrugi>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &Mprisustvo);
	if(Mprisustvo<0 || Mprisustvo>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &Mzadace);
	if(Mzadace<0 || Mzadace>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &Mzavrsni);
	if(Mzavrsni<0 || Mzavrsni>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	Tukupno=Tprvi+Tdrugi+Tprisustvo+Tzadace+Tzavrsni;
	Bukupno=Bprvi+Bdrugi+Bprisustvo+Bzadace+Bzavrsni;
	Mukupno=Mprvi+Mdrugi+Mprisustvo+Mzadace+Mzavrsni;
	if((Tukupno+e)<55){
		Tocena=5;
	}
	else if((Tukupno>55 || fabs(Tukupno-55)<e) && Tukupno<65){
		Tocena=6;
	}
		else if((Tukupno>65 || fabs(Tukupno-65)<e) && Tukupno<75){
		Tocena=7;
	}
		else if((Tukupno>75 || fabs(Tukupno-75)<e) && Tukupno<85){
		Tocena=8;
	}
		else if((Tukupno>85 || fabs(Tukupno-85)<e) && Tukupno<92){
		Tocena=9;
	}
		else {
		Tocena=10;
	}
	if(Bukupno<55){
		Bocena=5;
	}
	else if((Bukupno>55 || fabs(Bukupno-55)<e) && Bukupno<65){
		Bocena=6;
	}
		else if((Bukupno>65 || fabs(Bukupno-65)<e) && Bukupno<75){
		Bocena=7;
	}
		else if((Bukupno>75 || fabs(Bukupno-75)<e) && Bukupno<85){
		Bocena=8;
	}
		else if((Bukupno>85 || fabs(Bukupno-85)<e) && Bukupno<92){
		Tocena=9;
	}
		else {
		Bocena=10;
	}
	if(Mukupno<55){
		Mocena=5;
	}
	else if((Mukupno>55 || fabs(Mukupno-55)<e) && Mukupno<65){
		Mocena=6;
	}
		else if((Mukupno>65 || fabs(Mukupno-65)<e) && Mukupno<75){
		Mocena=7;
	}
		else if((Mukupno>75 || fabs(Mukupno-75)<e) && Mukupno<85){
		Tocena=8;
	}
		else if((Mukupno>85 || fabs(Mukupno-85)<e) && Mukupno<92){
		Mocena=9;
	}
		else {
		Mocena=10;
	}
	
	if((Tukupno+e)<55 && (Bukupno+e)<55 && (Mukupno+e)<55)
		printf("Nijedan student nije polozio.\n");
		else if(((Tukupno>55 || fabs(Tukupno-55)<e) && Bukupno<55 && Mukupno<55) || (Tukupno<55 && (Bukupno>55 || fabs(Bukupno-55)<e) && Mukupno<55) || (Tukupno<55 && Bukupno<55 && (Mukupno>55 || fabs(Mukupno-55)<e)))
		printf("Jedan student je polozio.\n");
		else if(((Tukupno>55 || fabs(Tukupno-55)<e) && (Bukupno>55 || fabs(Bukupno-55)<e) && Mukupno<55) || (Tukupno<55 && (Bukupno>55 || fabs(Bukupno-55)<e) && (Mukupno>55 || fabs(Mukupno-55)<e)) || ((Tukupno>55 || fabs(Tukupno-55)<e) && Bukupno<55 && (Mukupno>55 || fabs(Mukupno-55)<e)))
		printf("Dva studenta su polozila.\n");
		else
		{
			printf("Sva tri studenta su polozila.\n");
		if ((((Tukupno+e)>55 || fabs(Tukupno-55)<e) && Tukupno<65) && (((Bukupno+e)>55 || fabs(Bukupno-55)<e) && Bukupno<65) && (((Mukupno+e)>55 || fabs(Mukupno-55)<e) && Mukupno<65) ||
			(((Tukupno+e)>65 || fabs(Tukupno-65)<e) && Tukupno<75) && (((Bukupno+e)>65 || fabs(Bukupno-65)<e) && Bukupno<75) && (((Mukupno+e)>65 || fabs(Mukupno-65)<e) && Mukupno<75) ||
			(((Tukupno+e)>75 || fabs(Tukupno-75)<e) && Tukupno<85) && (((Bukupno+e)>75 || fabs(Bukupno-75)<e) && Bukupno<85) && (((Mukupno+e)>75 || fabs(Mukupno-75)<e) && Mukupno<85) ||
			(((Tukupno+e)>85 || fabs(Tukupno-85)<e) && Tukupno<92) && (((Bukupno+e)>85 || fabs(Bukupno-85)<e) && Bukupno<92) && (((Mukupno+e)>85 || fabs(Mukupno-85)<e) && Mukupno<92) ||
			(((Tukupno+e)>92 || fabs(Tukupno-92)<e) && (Tukupno<100 || fabs(Tukupno-100)<e)) && (((Bukupno+e)>92 || fabs(Bukupno-92)<e) && (Bukupno<100 || fabs(Bukupno-100)<e)) && (((Mukupno+e)>92 || fabs(Mukupno-92)<e) && (Mukupno<100 || fabs(Mukupno-100)<e)))
			printf("Sva tri studenta imaju istu ocjenu.");
 	else if ((((Tukupno+e)>55 || fabs(Tukupno-55)<e) && Tukupno<65) && (((Bukupno+e)>55 || fabs(Bukupno-55)<e) && Bukupno<65) && (((Mukupno+e)>65 || fabs(Mukupno-65)<e)) ||
 			(((Tukupno+e)>55 || fabs(Tukupno-55)<e) && Tukupno<65) && (((Bukupno+e)>65 || fabs(Bukupno-65)<e)) && (((Mukupno+e)>55 || fabs(Mukupno-55)<e) && Mukupno<65) ||
 			 ((Tukupno+e)>65 || fabs(Tukupno-65)<e) && (((Bukupno+e)>55 || fabs(Bukupno-55)<e) && Bukupno<65) && (((Mukupno+e)>55 || fabs(Mukupno-55)<e) && Mukupno<65) ||
 			
 	    	(((Tukupno+e)>65 || fabs(Tukupno-65)<e) && Tukupno<75) && (((Bukupno+e)>65 || fabs(Bukupno-65)<e) && Bukupno<75) && (Mukupno<65 || ((Mukupno+e)>75 || fabs(Mukupno-75)<e)) ||
 	    	(((Tukupno+e)>65 || fabs(Tukupno-65)<e) && Tukupno<75) && (Bukupno<65 || ((Bukupno+e)>75 || fabs(Bukupno-75)<e)) && (((Mukupno+e)>65 || fabs(Mukupno-65)<e) && Mukupno<75) ||
 	    	(Tukupno<65 || ((Tukupno+e)>75 || fabs(Tukupno-75)<e)) && (((Bukupno+e)>65 || fabs(Bukupno-65)<e) && Bukupno<75) && ((Mukupno>65 || fabs(Mukupno-65)<e) && Mukupno<75) ||
 	    	
			(((Tukupno+e)>75 || fabs(Tukupno-75)<e) && Tukupno<85) && (((Bukupno+e)>75 || fabs(Bukupno-75)<e) && Bukupno<85) && (Mukupno<75 || ((Mukupno+e)>85 || fabs(Mukupno-85)<e)) ||
			(((Tukupno+e)>75 || fabs(Tukupno-75)<e) && Tukupno<85) && ((Bukupno<75 || ((Bukupno+e)>85 || fabs(Bukupno-85)<e)) && ((Mukupno+e)>75 || fabs(Mukupno-75)<e)) && Mukupno<85 ||
			(Tukupno<75 || ((Tukupno+e)>85 || fabs(Tukupno-85)<e)) && (((Bukupno+e)>75 || fabs(Bukupno-75)<e) && Bukupno<85) && (((Mukupno+e)>75 || fabs(Mukupno-75)<e) && Mukupno<85) ||
			
			(((Tukupno+e)>85 || fabs(Tukupno-85)<e) && Tukupno<92) && (((Bukupno+e)>85 || fabs(Bukupno-85)<e) && Bukupno<92) && (Mukupno<85 || ((Mukupno+e)>92 || fabs(Mukupno-92)<e)) ||
			(((Tukupno+e)>85 || fabs(Tukupno-85)<e) && Tukupno<92) && (Bukupno<85 || ((Bukupno+e)>92 || fabs(Bukupno-92)<e)) && (((Mukupno+e)>85 || fabs(Mukupno-85)<e) && Mukupno<92) ||
			(Tukupno<85 || ((Tukupno+e)>92 || fabs(Tukupno-92)<e)) && (((Bukupno+e)>85 || fabs(Bukupno-85)<e) && Bukupno<92) && (((Mukupno+e)>85 || fabs(Mukupno-85)<e) && Mukupno<92) ||
			
			(((Tukupno+e)>92 || fabs(Tukupno-92)<e) && (Tukupno<100 || fabs(Tukupno-100)<e)) && (((Bukupno+e)>92 || fabs(Bukupno-92)<e) && (Bukupno<100 || fabs(Bukupno-100)<e)) && (Mukupno<92) ||
			(((Tukupno+e)>92 || fabs(Tukupno-92)<e) && (Tukupno<100 || fabs(Tukupno-100)<e)) && (Bukupno<92) && (((Mukupno+e)>92 || fabs(Mukupno-92)<e) && (Mukupno<100 || fabs(Mukupno-100)<e)) ||
			(Tukupno<92) && (((Bukupno+e)>92 || fabs(Bukupno-92)<e) && (Bukupno<100 || fabs(Bukupno-100)<e)) && (((Mukupno+e)>92 || fabs(Mukupno-92)<e) && (Mukupno<100 || fabs(Mukupno-100)<e)))
			printf("Dva od tri studenta imaju istu ocjenu.");
			else
				printf("Svaki student ima razlicitu ocjenu.");
			}
			return 0;
}
			
	

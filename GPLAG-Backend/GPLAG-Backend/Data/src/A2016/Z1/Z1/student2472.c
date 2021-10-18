#include <stdio.h>


int main() {
	double p1T, p2T, PT, ZT, ZIT, p1B, p2B, PB, ZB, ZIB, p1M, p2M, PM, ZM, ZIM, BOD1, BOD2, BOD3;
	/* tare*/

	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &p1T); if((p1T<0)||(p1T>20)){ printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf", &p2T); if((p2T<0)||(p2T>20)){ printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%lf", &PT); if((PT<0)||(PT>10)){ printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%lf", &ZT); if((ZT<0)||(ZT>10)){ printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf", &ZIT); if((ZIT<0)||(ZIT>40)){ printf("Neispravan broj bodova"); return 0;}
	
	BOD1=p1T+p2T+PT+ZT+ZIT;

	/* bojo*/
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &p1B); if((p1B<0)||(p1B>20)){ printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf", &p2B); if((p2B<0)||(p2B>20)){ printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%lf", &PB); if((PB<0)||(PB>10)){ printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%lf", &ZB); if((ZB<0)||(ZB>10)){ printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf", &ZIB); if((ZIB<0)||(ZIB>40)){ printf("Neispravan broj bodova"); return 0;}
	
	BOD2=p1B+p2B+PB+ZB+ZIB;

	/* mirza*/
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &p1M);if((p1M<0)||(p1M>20)){ printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf", &p2M);if((p2M<0)||(p2M>20)){ printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%lf", &PM);if((PM<0)||(PM>10)){ printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%lf", &ZM);if((ZM<0)||(ZM>10)){ printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf", &ZIM);if((ZIM<0)||(ZIM>40)){ printf("Neispravan broj bodova"); return 0;}

	BOD3=p1M+p2M+PM+ZM+ZIM;

	
	/*broj polozenih*/
	if (BOD1<55 && BOD2<55 && BOD3<55){
		printf("Nijedan student nije polozio.");
	}else if (BOD1>=55 && BOD2<55 && BOD3<55){
		printf("Jedan student je polozio.");
	}else if (BOD1<55 && BOD2>=55 && BOD3<55){
		printf("Jedan student je polozio.");
	}else if (BOD1<55 && BOD2<55 && BOD3>=55){
		printf("Jedan student je polozio.");
	}else if (BOD1>=55 && BOD2>=55 && BOD3<55){
		printf("Dva studenta su polozila.");
	}else if (BOD1<55 && BOD2>=55 && BOD3>=55){
		printf("Dva studenta su polozila.");
	}else if (BOD1>=55 && BOD2<55 && BOD3>=55){
		printf("Dva studenta su polozila.");
	}else if (BOD1>=55 && BOD2>=55 && BOD3>=55){
		printf("Sva tri studenta su polozila.");
		
		/*razlicitost ocjena*/
		if ((BOD1>=55 &&BOD1<65 && BOD2>=55 && BOD2<65 && BOD3>=55 && BOD3<65) || (BOD1>=65 &&BOD1<75 && BOD2>=65 && BOD2<75 && BOD3>=65 && BOD3<75) || (BOD1>=75 &&BOD1<85 && BOD2>=75 && BOD2<85 && BOD3>=75 && BOD3<85) || (BOD1>=85 &&BOD1<95 && BOD2>=85 && BOD2<95 && BOD3>=85 && BOD3<95) || (BOD1>=95 && BOD2>=95 && BOD3>=95)){
			printf("\nSva tri studenta imaju istu ocjenu.");
		}else if (BOD1>=55 && BOD1<65 && BOD2>=55 && BOD2<65 && BOD3>=55){
			printf("\nDva od tri studenta imaju istu ocjenu.");
		}else if (BOD1>=65 && BOD1<75 && BOD2>=65 && BOD2<75 && (BOD3<65 || BOD3>=75)){
			printf("\nDva od tri studenta imaju istu ocjenu.");
		}else if (BOD1>=75 && BOD1<85 && BOD2>=75 && BOD2<85 && (BOD3<75 || BOD3>=85)){
			printf("\nDva od tri studenta imaju istu ocjenu.");
		}else if (BOD1>=85 && BOD1<95 && BOD2>=85 && BOD2<95 && (BOD3<85 || BOD3>=95)){
		    printf("\nDva od tri studenta imaju istu ocjenu.");
		}else if (BOD1>=95 && BOD2>=95 && BOD3<95){                                      /*BOD1=BOD2*/
		    printf("\nDva od tri studenta imaju istu ocjenu.");
		}
		
		
		
		else if (BOD1>=55 && BOD1<65 && BOD3>=55 && BOD3<65 && BOD2>=55){
			printf("\nDva od tri studenta imaju istu ocjenu.");
		}else if (BOD1>=65 && BOD1<75 && BOD3>=65 && BOD3<75 && (BOD2<65 || BOD2>=75)){
			printf("\nDva od tri studenta imaju istu ocjenu.");
		}else if (BOD1>=75 && BOD1<85 && BOD3>=75 && BOD3<85 && (BOD2<75 || BOD2>=85)){
			printf("\nDva od tri studenta imaju istu ocjenu.");
		}else if (BOD1>=85 && BOD1<95 && BOD3>=85 && BOD3<95 && (BOD2<85 || BOD2>=95)){
		    printf("\nDva od tri studenta imaju istu ocjenu.");
		}else if (BOD1>=95 && BOD3>=95 && BOD2<95){
		    printf("\nDva od tri studenta imaju istu ocjenu.");                             /*BOD1=BOD3*/
		}
		
		
		
			else if (BOD2>=55 && BOD2<65 && BOD3>=55 && BOD3<65 && BOD1>=55){
			printf("\nDva od tri studenta imaju istu ocjenu.");
		}else if (BOD2>=65 && BOD2<75 && BOD3>=65 && BOD3<75 && (BOD1<65 || BOD1>=75)){
			printf("\nDva od tri studenta imaju istu ocjenu.");
		}else if (BOD2>=75 && BOD2<85 && BOD3>=75 && BOD3<85 && (BOD1<75 || BOD1>=85)){
			printf("\nDva od tri studenta imaju istu ocjenu.");
		}else if (BOD2>=85 && BOD2<95 && BOD3>=85 && BOD3<95 && (BOD1<85 || BOD1>=95)){
		    printf("\nDva od tri studenta imaju istu ocjenu.");
		}else if (BOD2>=95 && BOD3>=95 && BOD1<95){
		    printf("\nDva od tri studenta imaju istu ocjenu.");                             /*BOD2=BOD3*/
		}
		
		
		
		else{
			printf("\nSvaki student ima razlicitu ocjenu.");
		}
	}
	
	return 0;
}

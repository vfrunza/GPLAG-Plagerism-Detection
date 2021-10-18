#include <stdio.h>
#define PPI 20
#define DPI 20
#define P 10
#define Z 10
#define ZI 40

int main() {
    /* Unosenje ocjena za trojicu studenata iz svih ispita */
    
	double T1, T2, T3, T4, T5, B1, B2, B3, B4, B5, M1, M2, M3, M4, M5, sum1, sum2, sum3;
	
	
	 /* BROJ BODOVA KOJE JE OSVOJIO TARIK */
	    
	    printf ("Unesite bodove za Tarika: \n");
	    printf ("I parcijalni ispit: ");
	    scanf ("%lf", &T1);
	    if (T1<0 || T1>20 ){
	    	printf ("Neispravan broj bodova\n");
	    	return 0;
	    }
	    printf ("II parcijalni ispit: ");
	    scanf ("%lf", &T2);
	      if (T2<0 || T2>20 ){
	    	printf ("Neispravan broj bodova\n");
	    	return 0;
	    }
	    printf ("Prisustvo: ");
	    scanf ("%lf", &T3);
	      if (T3<0 || T3>10 ){
	    	printf ("Neispravan broj bodova\n");
	    	return 0;
	    }
	    printf ("Zadace: ");
	    scanf ("%lf", &T4);
	      if (T4<0 || T4>10 ){
	    	printf ("Neispravan broj bodova\n");
	    	return 0;
	    }
	    printf ("Zavrsni ispit: ");
	    scanf ("%lf", &T5);
	      if (T5<0 || T5>40 ){
	    	printf ("Neispravan broj bodova\n");
	    	return 0;
	    }
	    
	    /* BROJ BODOVA KOJE JE OSVOJIO BOJAN */
	    
	    printf ("Unesite bodove za Bojana: \n");
	    printf ("I parcijalni ispit: ");
	    scanf ("%lf", &B1);
	    if (B1<0 || B1>20 ){
	    	printf ("Neispravan broj bodova\n");
	    	return 0;
	    }
	    printf ("II parcijalni ispit: ");
	    scanf ("%lf", &B2);
	      if (B2<0 || B2>20 ){
	    	printf ("Neispravan broj bodova\n");
	    	return 0;
	    }
	    printf ("Prisustvo: ");
	    scanf ("%lf", &B3);
	      if (B3<0 || B3>10 ){
	    	printf ("Neispravan broj bodova\n");
	    	return 0;
	    }
	    printf ("Zadace: ");
	    scanf ("%lf", &B4);
	      if (B4<0 || B4>10 ){
	    	printf ("Neispravan broj bodova\n");
	    	return 0;
	    }
	    printf ("Zavrsni ispit: ");
	    scanf ("%lf", &B5);
	      if (B5<0 || B5>40 ){
	    	printf ("Neispravan broj bodova\n");
	    	return 0;
	    }
	    
	    /* BROJ BODOVA KOJE JE OSVOJIO MIRZA */
	    
	   printf ("Unesite bodove za Mirzu: \n");
	    printf ("I parcijalni ispit: ");
	    scanf ("%lf", &M1);
	    if (M1<0 || M1>20 ){
	    	printf ("Neispravan broj bodova\n");
	    	return 0;
	    }
	    printf ("II parcijalni ispit: ");
	    scanf ("%lf", &M2);
	      if (M2<0 || M2>20 ){
	    	printf ("Neispravan broj bodova\n");
	    	return 0;
	    }
	    printf ("Prisustvo: ");
	    scanf ("%lf", &M3);
	      if (M3<0 || M3>10 ){
	    	printf ("Neispravan broj bodova\n");
	    	return 0;
	    }
	    printf ("Zadace: ");
	    scanf ("%lf", &M4);
	      if (M4<0 || M4>10 ){
	    	printf ("Neispravan broj bodova\n");
	    	return 0;
	    }
	    printf ("Zavrsni ispit: ");
	    scanf ("%lf", &M5);
	      if (M5<0 || M5>40 ){
	    	printf ("Neispravan broj bodova\n");
	    	return 0;
	    }
	    
	
	
	   
	
	sum1 = (T1 + T2 + T3 + T4 + T5);
	sum2 = (B1 + B2 + B3 + B4 + B5);
	sum3 = (M1 + M2 + M3 + M4 + M5);
	
	int o1, o2, o3, pol;
	if (sum1<55){
		o1=5;
	}
	else if (sum1>= 55 && sum1<65){
		o1=6;
	}
	else if (sum1 >=65 && sum1<75){
		o1=7;
	}
	else if (sum1 >= 75 && sum1<85){
		o1=8;
	}
	else if (sum1 >= 85 && sum1<92){
		o1=9;
	}
	else if (sum1 >= 92 && sum1<=100){
		o1=10;
	}
	
		if (sum2<55){
		o2=5;
	}
	else if (sum2>= 55 && sum2<65){
		o2=6;
	}
	else if (sum2 >=65 && sum2<75){
		o2=7;
	}
	else if (sum2 >= 75 && sum2<85){
		o2=8;
	}
	else if (sum2 >= 85 && sum2<92){
		o2=9;
	}
	else if (sum2 >= 92 && sum2<=100){
		o2=10;
	}
	
		if (sum3<55){
		o3=5;
	}
	else if (sum3>= 55 && sum3<65){
		o3=6;
	}
	else if (sum3 >=65 && sum3<75){
		o3=7;
	}
	else if (sum3 >= 75 && sum3<85){
		o3=8;
	}
	else if (sum3 >= 85 && sum3<92){
		o3=9;
	}
	else if (sum3 >= 92 && sum3<=100){
		o3=10;
	}
	
	pol=0;
	if (o1>5){
		pol=pol + 1;
	}
	if (o2>5){
		pol++;
	}
	if (o3>5){
		pol++;
		
	}
	if (pol==3){
		printf ("Sva tri studenta su polozila.\n");
		if (o1==o2 && o2==o3){
			printf ("Sva tri studenta imaju istu ocjenu.\n");
			
		}
		else if (o1==o2|| o2==o3 || o1==o3){
			printf ("Dva od tri studenta imaju istu ocjenu.\n");
			
		}
		else {
			printf ("Svaki student ima razlicitu ocjenu.\n");
		}
	}
	else if (pol==2){
		printf ("Dva studenta su polozila.\n");
	}
	else if (pol==1){
		printf ("Jedan student je polozio.\n");
	}
	else {
		printf ("Nijedan student nije polozio.\n");
	}
	return 0;
}



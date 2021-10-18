#include <stdio.h>

int main() {
	double prviparcijalniT, drugiparcijalniT, prisustvoT, zadaceT, zavrsniT, prviparcijalniB, drugiparcijalniB, prisustvoB, zadaceB, zavrsniB, prviparcijalniM, drugiparcijalniM, prisustvoM, zadaceM, zavrsniM, sumaT, sumaB, sumaM;
	int T, B, M;
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &prviparcijalniT);
	if(prviparcijalniT<0 || prviparcijalniT>20)
	{	printf("Neispravan broj bodova");
		return 0;
	}
	else
	printf("II parcijalni ispit: ");
	scanf("%lf", &drugiparcijalniT);
	if(drugiparcijalniT<0 || drugiparcijalniT>20)
	{	printf("Neispravan broj bodova");
		return 0;
	}
	else
	printf("Prisustvo: ");
	scanf("%lf", &prisustvoT);
	if(prisustvoT<0 || prisustvoT>10)
	{	printf("Neispravan broj bodova");
		return 0;
	}
	else 
	printf("Zadace: ");
	scanf("%lf", &zadaceT);
	if(zadaceT<0 || zadaceT>10)
	{	printf("Neispravan broj bodova");
		return 0;
	}
	else
	printf("Zavrsni ispit: ");
	scanf("%lf", &zavrsniT);
	if(zavrsniT<0 || zavrsniT>40)
	{	printf("Neispravan broj bodova");
		return 0;
	}
	
	else
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &prviparcijalniB);
	if(prviparcijalniB<0 || prviparcijalniB>20)
	{	printf("Neispravan broj bodova");
		return 0;
	}
	else
	printf("II parcijalni ispit: ");
	scanf("%lf", &drugiparcijalniB);
	if(drugiparcijalniB<0 || drugiparcijalniB>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	else
	printf("Prisustvo: ");
	scanf("%lf", &prisustvoB);
	if(prisustvoB<0 || prisustvoB>10)
	{	printf("Neispravan broj bodova");
		return 0;
	}	
	else 
	printf("Zadace: ");
	scanf("%lf", &zadaceB);
	if(zadaceB<0 || zadaceB>10)
	{	printf("Neispravan broj bodova");
		return 0;
	}
	else
	printf("Zavrsni ispit: ");
	scanf("%lf", &zavrsniB);
	if(zavrsniB<0 || zavrsniB>40)
	{	printf("Neispravan broj bodova");
		return 0;
	}
	
	else
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &prviparcijalniM);
	if(prviparcijalniM<0 || prviparcijalniM>20)
	{	printf("Neispravan broj bodova");
		return 0;
	}
	else
	printf("II parcijalni ispit: ");
	scanf("%lf", &drugiparcijalniM);
	if(drugiparcijalniM<0 || drugiparcijalniM>20)
	{	printf("Neispravan broj bodova");
		return 0;
	}
	else
	printf("Prisustvo: ");
	scanf("%lf", &prisustvoM);
	if(prisustvoM<0 || prisustvoM>10)
	{	printf("Neispravan broj bodova");
		return 0;
	}
	else 
	printf("Zadace: ");
	scanf("%lf", &zadaceM);
	if(zadaceM<0 || zadaceM>10)
	{	printf("Neispravan broj bodova");
		return 0;
	}
	else
	printf("Zavrsni ispit: ");
	scanf("%lf", &zavrsniM);
	if(zavrsniM<0 || zavrsniM>40)
	{	printf("Neispravan broj bodova");
		return 0;
	}
	
	sumaT = prviparcijalniT + drugiparcijalniT + prisustvoT + zadaceT + zavrsniT;
	sumaB = prviparcijalniB + drugiparcijalniB + prisustvoB + zadaceB + zavrsniB;
	sumaM = prviparcijalniM + drugiparcijalniM + prisustvoM + zadaceM + zavrsniM;
	
	if (sumaT>=55 && sumaB>=55 && sumaM>=55)
	{
	printf("Sva tri studenta su polozila.");
	if (sumaT>=55 && sumaT<65)
		T=6; 
	else if(sumaT>=65 && sumaT<75)
		T=7;
	else if(sumaT>=75 && sumaT<85)
		T=8;
	else if(sumaT>=85 && sumaT<92)
		T=9;
	else T=10;
		
	if (sumaB>=55 && sumaB<65)
		B=6; 
	else if(sumaB>=65 && sumaB<75)
		B=7;
	else if(sumaB>=75 && sumaB<85)
		B=8;
	else if(sumaB>=85 && sumaB<92)
		B=9;
	else B=10;
	
	if (sumaM>=55 && sumaM<65)
		M=6; 
	else if(sumaM>=65 && sumaM<75)
		M=7;
	else if(sumaM>=75 && sumaM<85)
		M=8;
	else if(sumaM>=85 && sumaM<92)
		M=9;
	else M=10;
	
	if(T==B && B==M)
	printf("\nSva tri studenta imaju istu ocjenu.");
	else if(T!=B && T!=M && B!=M)
	printf("\nSvaki student ima razlicitu ocjenu.");
	else printf("\nDva od tri studenta imaju istu ocjenu.");
	}
	
	else if((sumaT<55 && sumaB>=55 && sumaM>=55) || (sumaT>=55 && sumaB<55 && sumaM>=55) || (sumaT>=55 && sumaB>=55 && sumaM<55))
	printf("Dva studenta su polozila.");
	else if((sumaT>=55 && sumaB<55 && sumaM<55) || (sumaT<55 && sumaB>=55 && sumaM<55) || (sumaT<55 && sumaB<55 && sumaM>=55))
	printf("Jedan student je polozio.");
	else printf("Nijedan student nije polozio.");
	return 0;
}

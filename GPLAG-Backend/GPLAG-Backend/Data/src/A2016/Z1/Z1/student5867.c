#include <stdio.h>
#include <math.h>

int main() 
{
	float I_par_T, II_par_T, prisustvo_T, zadace_T, zavrsni_T;
	float I_par_B, II_par_B, prisustvo_B, zadace_B, zavrsni_B;
	float I_par_M, II_par_M, prisustvo_M, zadace_M, zavrsni_M;
	float zbir_T, zbir_B, zbir_M;
	int ocjena_T, ocjena_B, ocjena_M;
	
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%f", &I_par_T);
	if(I_par_T<0 || I_par_T>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &II_par_T);
	if(II_par_T<0 || II_par_T>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &prisustvo_T);
	if(prisustvo_T<0 || prisustvo_T>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &zadace_T);
	if(zadace_T<0 || zadace_T>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &zavrsni_T);
	if(zavrsni_T<0 || zavrsni_T>40)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%f", &I_par_B);
	if(I_par_B<0 || I_par_B>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &II_par_B);
	if(II_par_B<0 || II_par_B>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &prisustvo_B);
	if(prisustvo_B<0 || prisustvo_B>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &zadace_B);
	if(zadace_B<0 || zadace_B>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &zavrsni_B);
	if(zavrsni_B<0 || zavrsni_B>40)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%f", &I_par_M);
	if(I_par_M<0 || I_par_M>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &II_par_M);
	if(II_par_M<0 || II_par_M>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &prisustvo_M);
	if(prisustvo_M<0 || prisustvo_M>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &zadace_M);
	if(zadace_M<0 || zadace_M>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &zavrsni_M);
	if(zavrsni_M<0 || zavrsni_M>40)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	zbir_T=I_par_T+II_par_T+zadace_T+prisustvo_T+zavrsni_T+0.01;
	zbir_B=I_par_B+II_par_B+zadace_B+prisustvo_B+zavrsni_B+0.01;
	zbir_M=I_par_M+II_par_M+zadace_M+prisustvo_M+zavrsni_M+0.01;
	
	if(zbir_T<55 && zbir_B<55 && zbir_M<55)
	printf("Nijedan student nije polozio.");
	else if((zbir_T>=55 && zbir_B<55 && zbir_M<55) || (zbir_T<55 && zbir_B>=55 && zbir_M<55) || (zbir_T<55 && zbir_B<55 && zbir_M>=55))
	printf("Jedan student je polozio.");
	else if((zbir_T>=55 && zbir_B>=55 && zbir_M<55) || (zbir_T>=55 && zbir_B<55 && zbir_M>=55) || (zbir_T<55 && zbir_B>=55 && zbir_M>=55))
	printf("Dva studenta su polozila.");
	else if(zbir_T>=55 && zbir_B>=55 && zbir_M>=55)
	printf("Sva tri studenta su polozila.");
	
	if(zbir_T>=55 && zbir_T<65)
	ocjena_T=6;
	else if(zbir_T>=65 && zbir_T<75)
	ocjena_T=7;
	else if(zbir_T>=75 && zbir_T<85)
	ocjena_T=8;
	else if(zbir_T>=85 && zbir_T<92)
	ocjena_T=9;
	else if(zbir_T>=92 && zbir_T<=100)
	ocjena_T=10;
	
	if(zbir_B>=55 && zbir_B<65)
	ocjena_B=6;
	else if (zbir_B>=65 && zbir_B<75)
	ocjena_B=7;
	else if(zbir_B>=75 && zbir_B<85)
	ocjena_B=8;
	else if(zbir_B>=85 && zbir_B<92)
	ocjena_B=9;
	else if(zbir_B>=92 && zbir_B<=100)
	ocjena_B=10;
	
	if(zbir_M>=55 && zbir_M<65)
	ocjena_M=6;
	else if(zbir_M>=65 && zbir_M<75)
	ocjena_M=7;
	else if(zbir_M>=75 && zbir_M<85)
	ocjena_M=8;
	else if(zbir_M>=85 && zbir_M<92)
	ocjena_M=9;
	else if(zbir_M>=92 && zbir_M<=100)
	ocjena_M=10;
	
	if(zbir_T>=55 && zbir_B>=55 && zbir_M>=55)
	{
	if(ocjena_T == ocjena_B && ocjena_T==ocjena_M && ocjena_B==ocjena_M)
	printf("\nSva tri studenta imaju istu ocjenu.");
	else if((ocjena_T == ocjena_B && ocjena_T!=ocjena_M && ocjena_B!=ocjena_M) || (ocjena_T==ocjena_M && ocjena_T!=ocjena_B && ocjena_B!=ocjena_M) || (ocjena_B==ocjena_M && ocjena_B!=ocjena_T && ocjena_M!=ocjena_T))
	printf("\nDva od tri studenta imaju istu ocjenu.");
	else if(ocjena_T!=ocjena_B && ocjena_T!=ocjena_M && ocjena_B!=ocjena_M)
	printf("\nSvaki student ima razlicitu ocjenu.");
	}
	
	return 0;
}

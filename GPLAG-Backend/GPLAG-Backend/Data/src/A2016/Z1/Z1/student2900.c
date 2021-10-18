#include <stdio.h>
#include <math.h>

int main() {
	double  t1,t2,t3,t4,t5,b1,b2,b3,b4,b5,m1,m2,m3,m4,m5,bt,bm,bb;
	int ocjena1=0,ocjena2=0,ocjena3=0;
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf ("%lf",&t1);
	if (t1<0 || t1>20)
	{
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&t2);
	if (t2<0 || t2>20)
	{
		printf("Neispravan broj bodova \n");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf",&t3);
		if (t3<0 || t3>10)
	{
		printf("Neispravan broj bodova \n");
		return 0;
	}
	
	printf("Zadace: ");
	scanf("%lf",&t4);
		if (t4<0 || t4>10)
	{
		printf("Neispravan broj bodova \n");
		return 0;
	}
	
	printf("Zavrsni ispit: ");
	scanf("%lf",&t5);
		if (t5<0 || t5>40)
	{
		printf("Neispravan broj bodova \n");
		return 0;
	}
	
	
	printf("Unesite bodove za Bojana: \n");
	
	printf("I parcijalni ispit: ");
	scanf("%lf",&b1);
		if (b1<0 || b1>20)
	{
		printf("Neispravan broj bodova \n");
		return 0;
	}
	 
	printf("II parcijalni ispit: ");
	scanf("%lf",&b2);
			if (b2<0 || b2>20)
	{
		printf("Neispravan broj bodova \n");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf",&b3);
			if (b3<0 || b3>10)
	{
		printf("Neispravan broj bodova \n");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf",&b4);
			if (b4<0 || b4>10)
	{
		printf("Neispravan broj bodova \n");
		return 0;
	}
	
	printf("Zavrsni ispit: ");
	scanf("%lf",&b5);
			if (b5<0 || b5>40)
	{
		printf("Neispravan broj bodova \n");
		return 0;
	}
	
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&m1);
			if (m1<0 || m1>20)
	{
		printf("Neispravan broj bodova \n");
		return 0;
	}
	
	printf("II parcijalni ispit: ");
	scanf("%lf",&m2);
				if (m2<0 || m2>20)
	{
		printf("Neispravan broj bodova \n");
		return 0;
	}
	
	printf("Prisustvo: ");
	scanf("%lf",&m3);
				if (m3<0 || m3>10)
	{
		printf("Neispravan broj bodova \n");
		return 0;
	}
	
	printf("Zadace: ");
	scanf("%lf",&m4);
				if (m4<0 || m4>10)
	{
		printf("Neispravan broj bodova \n");
		return 0;
	}
	
	
	printf("Zavrsni ispit: ");
	scanf("%lf",&m5);
				if (m5<0 || m5>40)
	{
		printf("Neispravan broj bodova \n");
		return 0;
	}
	bt=t1+t2+t3+t4+t5;
	bb=b1+b2+b3+b4+b5;
	bm=m1+m2+m3+m4+m5;
	
    if (bm<55)
    ocjena1=5;
    
	else if (bm>=55 && bm<65)
	ocjena1=6;
	
	else if (bm>=65 && bm<75)
	ocjena1=7;
	
	else if (bm>=75 && bm<85)
	ocjena1=8;
	
	else if (bm>=85 && bm<92)
	ocjena1=9;
	
	else if (bm>=92 && bm<=100)
	ocjena1 =10;
	
	if (bb<55)
	ocjena2=5;
	
	else if (bb>=55 && bb<65)
	ocjena2=6;
	
	else if (bb>=65 && bb<75)
	ocjena2=7;
	
	else if (bb>=75 && bb<85)
	ocjena2=8;
	
	else if (bb>=85 && bb<92)
	ocjena2=9;
	
	else if (bb>=92 && bb<=100)
	ocjena2=10;
	
	if (bt<55)
	ocjena3=5;
	else if (bt>=55 && bt<65)
	ocjena3=6;
	
	else if (bt>=65 && bt<75)
	ocjena3=7;
	
	else if (bt>=75 && bt<85)
	ocjena3=8;
	
	else if (bt>=85 && bt<92)
	ocjena3=9;
	
	else if (bt>=92 && bt<=100)
	ocjena3=10;
	
	
	 if (bm<55 && bt<55 && bb<55)
	 {
	 	printf ("Nijedan student nije polozio.\n");
	 	return 0;
	 }
	 else if (bm<55 && bt<55 && bb>=55){
	 	printf("Jedan student je polozio.\n");
	 }
	 else if (bm<55 && bb<55 && bt>=55)
	 {
	 	printf("Jedan student je polozio.\n");
	 	return 0;
	 }
	else if (bb<55 && bt<55 && bm>=55)
	{
		printf("Jedan student je polozio.\n");
		return 0;
	}
	else if (bm>=55 && bt>=55 && bb<55)
	{
		printf("Dva studenta su polozila.\n");
		return 0;
	}
	else if (bm>=55 && bb>=55 && bt<55)
	{
		printf("Dva studenta su polozila.\n");
		return 0;
	}
	else if (bb>=55 && bt>=55 && bm<55)
	{
		printf("Dva studenta su polozila.\n");
		return 0;
	}
	else {
		printf("Sva tri studenta su polozila.\n");
	}
	if (ocjena1==ocjena2 && ocjena2==ocjena3)
	{
		printf("Sva tri studenta imaju istu ocjenu.\n");
	}
	else if (ocjena1==ocjena2 && ocjena2!=ocjena3 && ocjena1!=ocjena3)
	{
		printf("Dva od tri studenta imaju istu ocjenu.\n");
	}
	else if (ocjena2==ocjena3 && ocjena1!=ocjena2 && ocjena1!=ocjena3)
	{
		printf("Dva od tri studenta imaju istu ocjenu.\n");
	}
	else if (ocjena1==ocjena3 && ocjena2!=ocjena1 && ocjena2!=ocjena3)
	{
		printf("Dva od tri studenta imaju istu ocjenu.\n");
	}
	else {
		printf("Svaki student ima razlicitu ocjenu.\n");
	}
	return 0;
}

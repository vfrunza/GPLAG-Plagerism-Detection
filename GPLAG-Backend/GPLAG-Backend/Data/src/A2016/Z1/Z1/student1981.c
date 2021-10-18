#include <stdio.h>

int main() {
	double prvip1,prvip2,prvip3,drugip1,drugip2,drugip3,p1,p2,p3,z1,z2,z3,zi1,zi2,zi3;
	float um,ub,ut;
	int o1,o2,o3;
	
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &prvip1);
	if(prvip1<=20 && prvip1>=0);
	else{ printf("Neispravan broj bodova\n"); 
	return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf", &drugip1);
	if(drugip1<=20 && drugip1>=0);
	else{ printf("Neispravan broj bodova\n"); 
	return 0;}
	printf("Prisustvo: ");
	scanf("%lf", &p1);
	if(p1<=10 && p1>=0);
	else{ printf("Neispravan broj bodova\n"); 
	return 0;}
	printf("Zadace: ");
	scanf("%lf", &z1);
	if(z1<=10 && z1>=0);
	else{ printf("Neispravan broj bodova\n"); 
	return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf", &zi1);
	if(zi1<=40 && zi1>=0);
	else{ printf("Neispravan broj bodova\n"); 
	return 0;}
	
	
	
	
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &prvip2);
	if(prvip2<=20 && prvip2>=0);
	else{ printf("Neispravan broj bodova\n"); 
	return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf", &drugip2);
	if(drugip2<=20 && drugip2>=0);
	else{ printf("Neispravan broj bodova\n"); 
	return 0;}
	printf("Prisustvo: ");
	scanf("%lf", &p2);
	if(p2<=10 && p2>=0);
	else{ printf("Neispravan broj bodova\n"); 
	return 0;}
	printf("Zadace: ");
	scanf("%lf", &z2);
	if(z2<=10 && z2>=0);
	else{ printf("Neispravan broj bodova\n"); 
	return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf", &zi2);
	if(zi2<=40 && zi2>=0);
	else{ printf("Neispravan broj bodova\n"); 
	return 0;}
	
	
	
	
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &prvip3);
	if(prvip3<=20 && prvip3>=0);
	else{ printf("Neispravan broj bodova\n"); 
	return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf", &drugip3);
	if(drugip3<=20 && drugip3>=0);
	else{ printf("Neispravan broj bodova\n"); 
	return 0;}	
	printf("Prisustvo: ");
	scanf("%lf", &p3);
	if(p3<=10 && p3>=0);
	else{ printf("Neispravan broj bodova\n"); 
	return 0;}
	printf("Zadace: ");
	scanf("%lf", &z3);
	if(z3<=10 && z3>=0);
	else{ printf("Neispravan broj bodova\n"); 
	return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf", &zi3);
	if(zi3<=40 && zi3>=0);
	else{ printf("Neispravan broj bodova\n"); 
	return 0;}
	
	
	
	
	
	
	ut=prvip1+drugip1+p1+z1+zi1;
	ub=prvip2+drugip2+p2+z2+zi2;
	um=prvip3+drugip3+p3+z3+zi3;

	
	
	if(um<55 && um>=0)  o1=5;
	if(ut<55 && ut>=0) o2=5;
	if(ub<55 && ub>=0) o3=5;
	
	if(um<65 && um>=55) o1=6;
	if(ut<65 && ut>=55) o2=6;
	if(ub<65 && ub>=55) o3=6;
	
	if(um<75 && um>=65) o1=7;
	if(ut<75 && ut>=65) o2=7;
	if(ub<75 && ub>=65) o3=7;
	
	if(um<85 && um>=75) o1=8;
	if(ut<85 && ut>=75) o2=8;
	if(ub<85 && ub>=75) o3=8;
	
	if(um<92 && um>=85)  o1=9;
	if(ut<92 && ut>=85) o2=9;
	if( ub<92 && ub>=85) o3=9;
	
	if(um<=100 && um>=92) o1=10;
	if(ut<=100 && ut>=92) o2=10;
	if(ub<=100 && ub>=92) o3=10;
	
	if(o1>5 && o2>5 && o3>5 ) printf("Sva tri studenta su polozila.\n");
	if(o1<6 && o2<6 && o3<6) {printf("Nijedan student nije polozio.\n");
	return 0;}
	if((o1==5 && o2==5 && o3>5) || (o2==5 && o3==5 && o1>5) || (o3==5 && o1==5 && o2>5 ) )
	{printf("Jedan student je polozio.\n");
	return 0;}

	if((o2>5 && o1>5 && o3==5) || (o3>5 && o1>5 && o2==5) || (o2>5 && o3>5 && o1==5) )
	{printf("Dva studenta su polozila.\n");
	return 0;}


	if(o1==o2 && o1==o3 && o2==o3) printf("Sva tri studenta imaju istu ocjenu.\n");
	else if((o1==o2 && o1!=o3) || (o1!=o2 && o1==o3) || (o1==o3 && o2!=o3) || (o1!=o3 && o2==o3) )
	printf("Dva od tri studenta imaju istu ocjenu.\n");
	else if(o1!=o2 && o2!=o3 && o1!=o3) printf("Svaki student ima razlicitu ocjenu.\n");

	
	
	
	
	return 0;
}

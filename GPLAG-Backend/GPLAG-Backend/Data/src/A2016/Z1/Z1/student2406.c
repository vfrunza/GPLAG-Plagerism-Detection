#include <stdio.h>
#include <math.h>
#define donja_granica 55

int main() 

{
	double parcijalaI, parcijalaII, zadace, prisustvo, zavrsni, 
	parcijalaImir, parcijalaIImir, zadacemir, prisustvomir, zavrsnimir, 
	parcijalaItar, parcijalaIItar, prisustvotar, zadacetar, zavrsnitar, u1, u2, u3, ocjenaT, ocjenaM, ocjenaB;
	printf("Unesite bodove za Tarika:\n");
	{
	
		printf("I parcijalni ispit: ");
	scanf("%lf", &parcijalaItar);
		if (parcijalaItar>20||parcijalaItar<0){
			printf("Neispravan broj bodova");
		return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf", &parcijalaIItar);
		if (parcijalaIItar>20||parcijalaIItar<0){
		printf("\nNeispravan broj bodova");
		return 0;}
		
			printf("Prisustvo: ");
	scanf("%lf", &prisustvotar);
		if (prisustvotar>10||prisustvotar<0){
		printf("Neispravan broj bodova");
		return 0;}
	
	printf("Zadace: ");
	scanf("%lf", &zadacetar);
		if (zadacetar>10||zadacetar<0){
		printf("Neispravan broj bodova");
		return 0;
	}

	printf("Zavrsni ispit: ");
	scanf("%lf", &zavrsnitar);
	if (zavrsnitar>40||zavrsnitar<0){
		printf("Neispravan broj bodova");
		return 0;}
	}

	/*Podaci se unose za svu trojicu studenata,mini
	blokovi koda se izvrsavaju linearno, posebno za svaku potrebnu info.*/	

	
	printf("Unesite bodove za Bojana:\n");
{	
	printf("I parcijalni ispit: ");
	scanf("%lf", &parcijalaI);
		if (parcijalaI>20||parcijalaI<0){
			printf("Neispravan broj bodova");
		return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf", &parcijalaII);
		if (parcijalaII>20||parcijalaII<0){
		printf("Neispravan broj bodova");
		return 0;}
		
		printf("Prisustvo: ");
	scanf("%lf", &prisustvo);
		if (prisustvo>10||prisustvo<0){
		printf("Neispravan broj bodova");
		return 0;}
	
	printf("Zadace: ");
	scanf("%lf", &zadace);
		if (zadace>10||zadace<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Zavrsni ispit: ");
	scanf("%lf", &zavrsni);
	if (zavrsni>40||zavrsni<0){
		printf("Neispravan broj bodova");
		return 0;}
}
	printf("Unesite bodove za Mirzu:\n");
	{
	
	
	printf("I parcijalni ispit: ");
	scanf("%lf", &parcijalaImir);
		if (parcijalaImir>20||parcijalaImir<0){
			printf("Neispravan broj bodova");
		return 1;}
	printf("II parcijalni ispit: ");
	scanf("%lf", &parcijalaIImir);
		if (parcijalaIImir>20||parcijalaIImir<0){
		printf("Neispravan broj bodova");
		return 0;}
	
	printf("Prisustvo: ");
	scanf("%lf", &prisustvomir);
		if (prisustvomir>10||prisustvomir<0){
		printf("Neispravan broj bodova");
		return 0;}
		
	printf("Zadace: ");
	scanf("%lf", &zadacemir);
		if (zadacemir>10||zadacemir<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Zavrsni ispit: ");
	scanf("%lf", &zavrsnimir);
	if (zavrsnimir>40||zavrsnimir<0){
		printf("Neispravan broj bodova");
		return 0;}
	}
{	u1=parcijalaItar+parcijalaIItar+prisustvotar+zadacetar+zavrsnitar;
	u2=parcijalaI+parcijalaII+prisustvo+zadace+zavrsni;
	u3=parcijalaImir+parcijalaIImir+prisustvomir+zadacemir+zavrsnimir;

}
		if(u1<donja_granica) ocjenaT=0;
			else if(u1<65&&u1>=55) ocjenaT=6;
			else if(u1<75&&u1>=65) ocjenaT=7;
			else if(u1<85&&u1>=75) ocjenaT=8;
			else if(u1<92&&u1>=85) ocjenaT=9;
			else ocjenaT=10;
		if(u2<donja_granica) ocjenaB=0;
			else if(u2<65&&u2>=55) ocjenaB=6;
			else if(u2<75&&u2>=65) ocjenaB=7;
			else if(u2<85&&u2>=75) ocjenaB=8;
			else if(u2<92&&u2>=85) ocjenaB=9;
			else ocjenaB=10;
		if(u3<donja_granica) ocjenaM=0;
			else if(u3<65&&u3>=55) ocjenaM=6;
			else if(u3<75&&u3>=65) ocjenaM=7;
			else if(u3<85&&u3>=75) ocjenaM=8;
			else if(u3<92&&u3>=85) ocjenaM=9;
		else ocjenaM=10;

if(ocjenaT&&ocjenaB&&ocjenaM) printf("Sva tri studenta su polozila.");
		else if((ocjenaT==0&&ocjenaB*ocjenaM!=0)||(ocjenaB==0&&ocjenaT*ocjenaM!=0)||(ocjenaM==0&&ocjenaT*ocjenaB!=0))
		printf("Dva studenta su polozila.");
		else if((ocjenaT==0&&ocjenaB==0&&ocjenaM!=0)||(ocjenaT!=0&&ocjenaB==0&&ocjenaM==0)||(ocjenaB!=0&&ocjenaM==0&&ocjenaT==0))
		printf("Jedan student je polozio.");
		else if(ocjenaM==0&&ocjenaT==0&&ocjenaB==0)
		printf("Nijedan student nije polozio.");
		if(ocjenaT!=0 && ocjenaB!=0 && ocjenaM!=0 && ocjenaT==ocjenaB&&ocjenaB==ocjenaM)
		printf("\nSva tri studenta imaju istu ocjenu.");
		else if((ocjenaT!=0&&ocjenaM!=0&&ocjenaB!=0)&&((ocjenaT==ocjenaB&&ocjenaB!=ocjenaM)||(ocjenaT==ocjenaM&&ocjenaM!=ocjenaB)||(ocjenaM==ocjenaB&&ocjenaB!=ocjenaT)))
		printf("\nDva od tri studenta imaju istu ocjenu.");
		else if(ocjenaT!=0 && ocjenaB!=0 && ocjenaM!=0 && ocjenaT!=ocjenaM&&ocjenaM!=ocjenaB)
		printf("\nSvaki student ima razlicitu ocjenu.");
	return 0;
}
	
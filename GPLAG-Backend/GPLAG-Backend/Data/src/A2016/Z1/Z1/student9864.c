#include <stdio.h>
#include <math.h>
/*Funkcija za poredenje realnih brojeva*/
int Poredi (double x,double y) 
{
	const double Eps=0.0000001 ;
	return fabs(x-y) <= Eps * (fabs(x)+fabs(y));
}

int main() {
	double nt,nb,nm,prvi1,drugi1,prisustvo1,zadace1,zavrsni1,prvi2,drugi2,prisustvo2,zadace2,zavrsni2,prvi3,drugi3,prisustvo3,zadace3,zavrsni3;
	int ocjena1=5,ocjena2=5,ocjena3=5;
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf" ,&prvi1);
	if((prvi1<0 && !Poredi(prvi1,0))||(prvi1>20 && !Poredi(prvi1,20))) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &drugi1);
	if((drugi1<0 && !Poredi(drugi1,0))||(drugi1>20 && !Poredi(drugi1,20))){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &prisustvo1);
	if((prisustvo1<0 && !Poredi(prisustvo1,0))||(prisustvo1>10 && !Poredi(prisustvo1,10))){
	printf("Neispravan broj bodova");
	return 0;
	}
	printf("Zadace: ");
	scanf("%lf" ,&zadace1);
	if((zadace1<0 && !Poredi(zadace1,0))||(zadace1>10 && !Poredi(zadace1,20))){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf" ,&zavrsni1);
	if((zavrsni1<0 && !Poredi(zavrsni1,0))||(zavrsni1>40 && !Poredi(zavrsni1,40))){
		printf("Neispravan broj bodova");
		return 0;
}
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &prvi2);
	if((prvi2<0 && !Poredi(prvi2,0))||(prvi2>20 && !Poredi(prvi2,20))){
	printf("Neispravan broj bodova");
	return 0;
}
	printf("II parcijalni ispit: ");
	scanf("%lf",&drugi2);
	if((drugi2<0 && !Poredi(drugi2,0))||(drugi2>20 && !Poredi(drugi2,20))) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &prisustvo2);
	if ((prisustvo2<0 && !Poredi(prisustvo2,0))||(prisustvo2>10 && !Poredi(prisustvo2,20))){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf" ,&zadace2);
	if((zadace2<0 && !Poredi(zadace2,0))||(zadace2>10 && !Poredi(zadace2,10))) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf" ,&zavrsni2);
	if ((zavrsni2<0 && !Poredi(zavrsni2,0))||(zavrsni2>40 && !Poredi(zavrsni2,40))){
		printf("Neispravan broj bodova");
		return 0;
		
	}
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf(" %lf" ,&prvi3);
	if((prvi3<0 && !Poredi(prvi3,0))||(prvi3>20 && !Poredi(prvi3,20))) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&drugi3);
	printf("Prisustvo: ");
	scanf("%lf",&prisustvo3);
	if ((prisustvo3<0 && !Poredi(prisustvo3,0))||(prisustvo3>10 && !Poredi(prisustvo3,10))){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf" ,&zadace3);
	if((zadace3<0 && !Poredi(zadace3,0))||(zadace3>10 && !Poredi(zadace3,10))) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf" ,&zavrsni3);
	if((zavrsni3<0 && !Poredi(zavrsni3,0))||(zavrsni3>40 && !Poredi(zavrsni3,40))){
		printf("Neispravan broj bodova");
		return 0;
	}
	nt=prvi1+drugi1+prisustvo1+zadace1+zavrsni1;
	nb=prvi2+drugi2+prisustvo2+zadace2+zavrsni2;
	nm=prvi3+drugi3+prisustvo3+zadace3+zavrsni3;
	/*printf("\n\n %lf \n\n", nm);*/
	if((nt>55 || Poredi(55,nt)) && (nt<65 && !Poredi(65,nt))) ocjena1=6;
	if((nt>65 || Poredi(65,nt)) && (nt<75 && !Poredi(75,nt))) ocjena1=7;
	if((nt>75 || Poredi(75,nt)) && (nt<85 && !Poredi(85,nt))) ocjena1=8;
	if((nt>85 || Poredi(85,nt)) && (nt<92 && !Poredi(92,nt))) ocjena1=9;
	if((nt>92 || Poredi(92,nt)) && (nt<100|| Poredi(100,nt))) ocjena1=10;
	if((nb>55 || Poredi(55,nb)) && (nb<65 && !Poredi(65,nb))) ocjena2=6;
	if((nb>65 || Poredi(65,nb)) && (nb<75 && !Poredi(75,nb))) ocjena2=7;
	if((nb>75 || Poredi(75,nb)) && (nb<85 && !Poredi(85,nb))) ocjena2=8;
	if((nb>85 || Poredi(85,nb)) && (nb<92 && !Poredi(92,nb))) ocjena2=9;
	if((nb>92 || Poredi(92,nb)) && (nb<100 || Poredi(100,nb))) ocjena2=10;
	if((nm>55 || Poredi(55,nm)) && (nm<65 && !Poredi(65,nm))) ocjena3=6;
	if((nm>65 || Poredi(65,nm)) && (nm<75 && !Poredi(75,nm))) ocjena3=7;
	if((nm>75 || Poredi(75,nm)) && (nm<85 && !Poredi(85,nm))) ocjena3=8;
	if((nm>85 || Poredi(85,nm)) && (nm<92 && !Poredi(92,nm))) ocjena3=9;
	if((nm>92 || Poredi(92,nm)) && (nm<100 || Poredi(100,nm))) ocjena3=10;
	
	
	if(nt<55&&nb<55&&nm<55&& !Poredi(55,nt) && !Poredi(55,nb) && !Poredi(55,nb)){
		printf("Nijedan student nije polozio.");
		return 0;
	}
	if(ocjena1>=6&&ocjena2>=6&&ocjena3>=6){
		printf("Sva tri studenta su polozila.\n");
		if((ocjena1==ocjena2)&&(ocjena2==ocjena3)&&(ocjena1==ocjena3))
			printf("Sva tri studenta imaju istu ocjenu.");
		else if((ocjena1==ocjena2)||(ocjena2==ocjena3)||(ocjena1==ocjena3))
			printf("Dva od tri studenta imaju istu ocjenu.");
		else
			printf("Svaki student ima razlicitu ocjenu.");
	}
	else if((ocjena1>=6&& ocjena2>=6) || (ocjena1>=6&& ocjena3>=6) || (ocjena2>=6 && ocjena3>=6))
		printf("Dva studenta su polozila.\n");
	else
		printf("Jedan student je polozio.\n");
	return 0;
}
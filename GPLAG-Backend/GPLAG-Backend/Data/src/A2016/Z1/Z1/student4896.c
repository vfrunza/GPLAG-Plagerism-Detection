#include <stdio.h>

int main() {
	float bodovi1,bodovi2,bodovi3,t=0,m=0,b=0;
	int ocjena1,ocjena2,ocjena3;
	int br=0;
	printf("Unesite bodove za Tarika: \n" );
	printf("I parcijalni ispit: ");
	scanf("%f",&bodovi1);
	if(bodovi1>20 || bodovi1<0) {printf("Neispravan broj bodova"); return 0;}
	t+=bodovi1;
	printf ("II parcijalni ispit: ");
	scanf("%f",&bodovi1);
	if(bodovi1>20 || bodovi1<0){printf("Neispravan broj bodova"); return 0;}
	t+=bodovi1;
	printf("Prisustvo: ");
	scanf("%f" ,&bodovi1);
	if (bodovi1>10 || bodovi1<0){printf("Neispravan broj bodova"); return 0;}
	t+=bodovi1;
	printf("Zadace: ");
	scanf("%f",&bodovi1);
	if(bodovi1>10 || bodovi1<0){printf("Neispravan broj bodova"); return 0;}
	t+=bodovi1;
	printf("Zavrsni ispit: ");
	scanf("%f",&bodovi1);
	if (bodovi1>40 || bodovi1<0){printf("Neispravan broj bodova"); return 0;}
	t+=bodovi1;
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%f",&bodovi2);
	if(bodovi2>20 || bodovi2<0){printf("Neispravan broj bodova");return 0;}
	b+=bodovi2;
	printf("II parcijalni ispit: ");
	scanf("%f",&bodovi2);
	if(bodovi2>20 || bodovi2<0){printf("Neispravan broj bodova");return 0;}
	b+=bodovi2;
	printf("Prisustvo: ");
	scanf("%f",&bodovi2);
	if(bodovi2>10 || bodovi2<0){printf("Neispravan broj bodova");return 0;}
	b+=bodovi2;
	printf("Zadace: ");
	scanf("%f",&bodovi2);
	if(bodovi2>10 || bodovi2<0){printf("Neispravan broj bodova");return 0;}
	b+=bodovi2;
	printf("Zavrsni ispit: ");
	scanf("%f",&bodovi2);
	if(bodovi2>40 || bodovi2<0){printf("Neispravan broj bodova");return 0;}
	b+=bodovi2;
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%f" , &bodovi3);
	if (bodovi3>20 || bodovi3<0){printf("Neispravan broj bodova"); return 0;}
	m+=bodovi3;
	printf("II parcijalni ispit: ");
	scanf ("%f" , &bodovi3);
	if (bodovi3>20 || bodovi3<0){printf("Neispravan broj bodova"); return 0;}
	m+=bodovi3;
	printf("Prisustvo: ");
	scanf("%f" , &bodovi3);
	if(bodovi3>10 || bodovi3<0){printf("Neispravan broj bodova"); return 0;}
	m+=bodovi3;
	printf("Zadace: ");
	scanf("%f", &bodovi3);
	if(bodovi3>10 || bodovi3<0){printf("Neispravan broj bodova"); return 0;}
	m+=bodovi3;
	printf("Zavrsni ispit: ");
	scanf("%f" , &bodovi3);
	if(bodovi3>40 || bodovi3<0){printf("Neispravan broj bodova");return 0;}
	m+=bodovi3;
	if(t>=55 && t<92)ocjena1=(int)(t/10+0.5);
	if(t<55)ocjena1=0;
	if(t>=92)ocjena1=10;
	if(b>=55 && b<92)ocjena2=(int)(b/10+0.5);
	if(b<55)ocjena2=0;
	if(b>=92)ocjena2=10;
	if(m>=55 && m<92)ocjena3=(int)(m/10+0.5);
	if(m<55)ocjena3=0;
	if(m>=92)ocjena3=10;
	if(ocjena1>=6)br++;
	if(ocjena2>=6)br++;
	if(ocjena3>=6)br++;
	if(br==0)printf("Nijedan student nije polozio.\n");
	if(br==1)printf("Jedan student je polozio.\n");
	if(br==2)printf("Dva studenta su polozila.\n");
	if(br==3)printf("Sva tri studenta su polozila.\n");
	if(br==3){
		if((ocjena1==ocjena2) && (ocjena1==ocjena3) && (ocjena2==ocjena3)){printf("Sva tri studenta imaju istu ocjenu.\n");goto l;}
		if((ocjena1!=ocjena2) && (ocjena2!=ocjena3) && (ocjena1!=ocjena3)){printf("Svaki student ima razlicitu ocjenu.\n");goto l;}
		else{printf("Dva od tri studenta imaju istu ocjenu.\n");}}
	l: 	return 0;}



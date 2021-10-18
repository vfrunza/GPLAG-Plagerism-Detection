#include <stdio.h>

int main() {
	printf("Unesite bodove za Tarika: \n");
	float a=0,b=0,c=0,d=0,e=0,suma=0;
	scanf("%f %f %f %f %f",&a,&b,&c,&d,&e);
	if(a<0 || a>20 || b<0 || b>20 || c<0 || c>10 || d<0 || d>10 || e<0 || e>40)
	{
		printf("Neispravan broj bodova\n");
		suma=-1;
	}
	else{
		printf("I parcijalni ispit: ",a);
		printf("II parcijalni ispit: ",b);
		printf("Prisustvo: ",c);
		printf("Zadace: ",d);
		printf("Zavrsni ispit: ",e);
		suma=a+b+c+d+e;
	}
	printf("Unesite bodove za Bojana: \n");
	float a1=0,b1=0,c1=0,d1=0,e1=0,suma1=0;
	scanf("%f %f %f %f %f",&a1,&b1,&c1,&d1,&e1);
	if(a1<0 || a1>20 || b1<0 || b1>20 || c1<0 ||c1>10 || d1<0 || d1>10 || e1<0 || e1>40)
	{
		printf("Neispravan broj bodova\n");
		suma1=-1;
	}
	else{
		printf("I parcijalni ispit: ",a1);
		printf("II parcijalni ispit: ",b1);
		printf("Prisustvo: ",c1);
		printf("Zadace: ",d1);
		printf("Zavrsni ispit: ",e1);
		suma1=a1+b1+c1+d1+e1;
	}
	printf("Unesite bodove za Mirzu: \n");
	float a2=0,b2=0,c2=0,d2=0,e2=0,suma2=0;
	scanf("%f %f %f %f %f",&a2,&b2,&c2,&d2,&e2);
	if(a2<0 || a2>20 || b2<0 || b2>20 || c2<0 || c2>10 || d2<0 || d2>10 || e2<0 || e2>40)
	{
		printf("Neispravan broj bodova\n");
		suma2=-1;
	}
	else{
		printf("I parcijalni ispit: ",a2);
		printf("II parcijalni ispit: ",b2);
		printf("Prisustvo: ",c2);
		printf("Zadace: ",d2);
		printf("Zavrsni ispit: ",e2);
		suma2=a2+b2+c2+d2+e2;
	}
	
	if(suma>=0 && suma<55 && suma1>=0 && suma1<55 && suma2>=0 && suma2<55)
	{
		printf("Nijedan student nije polozio.\n");
	}
	else if(suma>54 && suma<=100 && suma1>=0 && suma1<=54 && suma2>=0 && suma2<=54)
	{
		printf("Jedan student je polozio.\n");
	}
	else if(suma1>54 && suma1<=100 && suma>=0 && suma<=54 && suma2>=0 && suma2<=54)
	{
		printf("Jedan student je polozio.\n");
	}
	else if(suma2>54 && suma2<=100 && suma>=0 && suma<=54 && suma1>=0 && suma<=54)
	{
		printf("Jedan student je polozio.\n");
	}
	else if(suma>=55 && suma<=100 && suma1>=55 && suma1<=100 && suma2>=0 && suma2<55)
	{
		printf("Dva studenta su polozila.\n");
	}
	else if(suma1>=55 && suma1<=100 && suma2>=55 && suma2<=100 && suma>=0 && suma<55)
	{
		printf("Dva studenta su polozila.\n");
	}
	else if(suma>=55 && suma<=100 && suma2>=55 && suma2<=100 && suma1>=0 && suma2<55)
	{
		printf("Dva studenta su polozila.\n");
	}
	else if(suma>=55 && suma<=100 && suma1>=55 && suma1<=100 && suma2>=55 && suma2<=100)
	{
		printf("Sva tri studenta su polozila.\n");
	}

	if(suma!=-1 && suma>=55 && suma<=100 && suma1!=-1 && suma1>=55 && suma1<=100 && suma2!=-1 && suma2>=55 && suma2<=100)
	{
		
	if((suma>=55 && suma<65 && suma1>=55 && suma1<65 && suma2>=55 && suma2<65) || (suma>=65 && suma<75 && suma1>=65 && suma1<75 && suma2>=65 && suma2<75) || (suma>=75 && suma<85 && suma1>=75 && suma1<85 && suma2>=75 && suma2<85) || (suma>=85 && suma<92 && suma1>=85 && suma1<92 && suma2>=85 && suma2<92) || (suma>=92 && suma<=100 && suma1>=92 && suma1<=100 && suma2>=92 && suma2<=100))
	{
		printf("Sva tri studenta imaju istu ocjenu.\n");
	}
	else if((suma>=55 && suma<65 && suma1>=55 && suma1<65 && suma2>=65 && suma2<=100) || (suma>=65 && suma<75 && suma1>=65 && suma1<75 && suma2>=55 && suma2<65 || suma2>=75 && suma2<=100) || (suma>=75 && suma<85 && suma1>=75 && suma1<85 && suma2>=55 && suma2<75 || suma2>=85 && suma2<=100) || (suma>=85 && suma<92 && suma1>=85 && suma1<92 && suma2>=55 && suma2<85 || suma2>=92 && suma2<=100)|| (suma>=92 && suma<=100 && suma1>=92 && suma1<=100 && suma2>=55 && suma2<92))
	{
		printf("Dva od tri studenta imaju istu ocjenu.");
	}
	else if((suma1>=55 && suma1<65 && suma2>=55 && suma2<65 && suma>=65 && suma<=100) || (suma1>=65 && suma1<75 && suma2>=65 && suma2<75 && suma>=55 && suma<65 || suma>=75 && suma<=100) || (suma1>=75 && suma1<85 && suma2>=75 && suma2<85 && suma>=55 && suma<75 || suma>=85 && suma<=100) || (suma1>=85 && suma1<92 && suma2>=85 && suma2<92 && suma>=55 && suma<85 || suma>=92 && suma<=100)|| (suma1>=92 && suma1<=100 && suma2>=92 && suma2<=100 && suma>=55 && suma<92))
	{
		printf("Dva od tri studenta imaju istu ocjenu.");
	}
	else if((suma>=55 && suma<65 && suma2>=55 && suma2<65 && suma1>=65 && suma1<=100) || (suma>=65 && suma<75 && suma2>=65 && suma2<75 && suma1>=55 && suma1<65 || suma1>=75 && suma1<=100) || (suma>=75 && suma<85 && suma2>=75 && suma2<85 && suma1>=55 && suma1<75 || suma1>=85 && suma1<=100) || (suma>=85 && suma<92 && suma2>=85 && suma2<92 && suma1>=55 && suma1<85 || suma1>=92 && suma1<=100)|| (suma>=92 && suma<=100 && suma2>=92 && suma2<=100 && suma1>=55 && suma1<92))
	{
		printf("Dva od tri studenta imaju istu ocjenu.");
	}
	}
	
	
	
	
	
	
	
	return 0;
}

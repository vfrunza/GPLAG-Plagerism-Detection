#include <stdio.h>
#include <math.h>
#define d 0.001
int main() {
	float tarik,ppt,dpt,zt,pt,zit,bojan,ppb,dpb,zb,pb,zib,mirza,ppm,dpm,zm,pm,zim;
	int tarik2,mirza2,bojan2;
	
	printf("Unesite bodove za Tarika: ");
	printf("\nI parcijalni ispit: ");
	scanf("%f",&ppt);
	if(ppt>20 || ppt<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&dpt);
	if(dpt<0 || dpt>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&pt);
	if(pt<0 || pt>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f",&zt);
	if(zt<0 || zt>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&zit);
	if(zit<0 || zit>40){
		printf("Neispravan broj bodova");
		return 0;
	}
		printf("Unesite bodove za Bojana: ");
	printf("\nI parcijalni ispit: ");
	scanf("%f",&ppb);
	if(ppb>20 || ppb<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&dpb);
	if(dpb<0 || dpb>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&pb);
	if(pb<0 || pb>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f",&zb);
	if(zb<0 || zb>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&zib);
	if(zib<0 || zib>40){
		printf("Neispravan broj bodova");
		return 0;
	}
		printf("Unesite bodove za Mirzu: ");
	printf("\nI parcijalni ispit: ");
	scanf("%f",&ppm);
	if(ppm>20 || ppm<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&dpm);
	if(dpm<0 || dpm>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&pm);
	if(pm<0 || pm>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f",&zm);
	if(zm<0 || zm>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&zim);
	if(zim<0 || zim>40){
		printf("Neispravan broj bodova");
		return 0;
	}
    tarik=ppt+dpt+pt+zt+zit;
    bojan=ppb+dpb+pb+zb+zib;
    mirza=ppm+dpm+pm+zm+zim;
    if(tarik <55){
    	tarik2=5;
    }
   	else if(tarik<65 && tarik>=55){
   		tarik2=6;
   	}
   	else if(tarik>=65 && tarik<75){
   		tarik2=7;
   	}
   	else if(tarik>=75 && tarik<85){
   		tarik2=8;
   	}
   	else if(tarik>=85 && tarik<92){
   		tarik2=9;
   	}
   	else tarik2=10;
   	if(mirza<55){
   		mirza2=5;
   	}
   	else if(mirza<65 && mirza>=55){
   		mirza2=6;
   	}
   	else if(mirza>=65 && mirza<75){
   		mirza2=7;
   	}
   	else if(mirza>=75 && mirza<85){
   		mirza2=8;
   	}
   	else if(mirza>=85 && mirza<92){
   		mirza2=9;
   	}
   	else mirza2=10;
   	 if(bojan<55){
   	 	bojan2=5;
   	 }
    else if(bojan<65 && bojan>=55){
   		bojan2=6;
   	}
   	else if(bojan>=65 && bojan<75){
   		bojan2=7;
   	}
   	else if(bojan>=75 && bojan<85){
   		bojan2=8;
   	}
   	else if(bojan>=85 && bojan<92){
   		bojan2=9;
   	}
   	else bojan2=10;
   	 if(bojan>=55 && tarik>=55 && mirza>=55){
   	 	printf("Sva tri studenta su polozila.\n");
   	if(bojan2==tarik2 && tarik2==mirza2){
   		printf("Sva tri studenta imaju istu ocjenu.");
   	}
   	else if((tarik2==bojan2 && bojan2!=mirza2) || (tarik2==mirza2 && mirza2!=bojan2) || (mirza2==bojan2 && tarik2!=mirza2))
   {
   	printf("Dva od tri studenta imaju istu ocjenu.");
   }
   	else printf("Svaki student ima razlicitu ocjenu.");
   }
   else if((bojan >=55 && tarik>=55 && mirza<55)||(bojan>=55 && mirza>=55 && tarik<55)||(tarik>=55 && mirza>=55 && bojan<55))
 {
 	printf("Dva studenta su polozila.");
 }
   else if((bojan >=55 && tarik<55 && mirza<55 )||(bojan<55 && mirza>=55 && tarik<55)||(fabs(55-tarik)<d && mirza<55 && bojan<55))
 {
 	printf("Jedan student je polozio.");
 }
 else printf("Nijedan student nije polozio.");
 
   
	return 0;
}

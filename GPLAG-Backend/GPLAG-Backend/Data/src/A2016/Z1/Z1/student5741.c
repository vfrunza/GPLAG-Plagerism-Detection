#include <stdio.h>

int main() {
	double tpi1,tpi2,tpr,tz,tzi,bpi1,bpi2,bpr,bz,bzi,mpi1,mpi2,mpr,mz,mzi;
	int to,bo,mo,t,b,m;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&tpi1);
	if(tpi1<0 || tpi1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&tpi2);
	if(tpi2<0 || tpi2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf",&tpr);
	if(tpr<0 || tpr>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf",&tz);
	if(tz<0 || tz>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf",&tzi);
	if(tzi<0 || tzi>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&bpi1);
	if(bpi1<0 || bpi1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&bpi2);
	if(bpi2<0 || bpi2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf",&bpr);
	if(bpr<0 || bpr>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf",&bz);
	if(bz<0 || bz>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf",&bzi);
	if(bzi<0 || bzi>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&mpi1);
	if(mpi1<0 || mpi1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&mpi2);
	if(mpi2<0 || mpi2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf",&mpr);
	if(mpr<0 || mpr>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf",&mz);
	if(mz<0 || mz>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf",&mzi);
	if(mzi<0 || mzi>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	t=tpi1+tpi2+tpr+tz+tzi;
	b=bpi1+bpi2+bpr+bz+bzi;
	m=mpi1+mpi2+mpr+mz+mzi;

	if(t<55){
		to=0;
	}
	else if(t>=55 && t<65){
		to=6;
	}
	else if(t>=65 && t<75){
		to=7;
	}
	else if(t>=75 && t<85){
		to=8;
	}
	else if(t>=85 && t<92){
		to=9;
	}
	else to=10;
		
		
	if(b<55){
		bo=0;
	}
	else if(b>=55 && b<65){
		bo=6;
	}
	else if(b>=65 && b<75){
		bo=7;
	}
	else if(b>=75 && b<85){
		bo=8;
	}
	else if(b>=85 && b<92){
		bo=9;
	}
	else bo=10;
		
		
	if(m<55){
		mo=0;
	}
	else if(m>=55 && m<65){
		mo=6;
	}
	else if(m>=65 && m<75){
		mo=7;
	}
	else if(m>=75 && m<85){
		mo=8;
	}
	else if(m>=85 && m<92){
		mo=9;
	}
	else mo=10;
	
	if(t<55 && b<55 && m<55){
		printf("Nijedan student nije polozio.\n");
	}
	else if((t>=55 && b<55 && m<55) || (t<55 && b>=55 && m<55) || (t<55 && b<55 && m>=55)){
		printf("Jedan student je polozio.\n");
	}
	else if((t<55 && b>=55 && m>=55) || (t>=55 && b<55 && m>=55) || (t>=55 && b>=55 && m<55)){
		printf("Dva studenta su polozila.\n");
	}
	else printf("Sva tri studenta su polozila.\n");
		
	if(t>=55 && b>=55 && m>=55){
		if(to==bo && bo==mo && to==mo){
			printf("Sva tri studenta imaju istu ocjenu.\n");
		}
		else if(to!=bo && bo!=mo && to!=mo){
			printf("Svaki student ima razlicitu ocjenu.\n");
		}
		else printf("Dva od tri studenta imaju istu ocjenu.\n");
	}
	
	return 0;
}

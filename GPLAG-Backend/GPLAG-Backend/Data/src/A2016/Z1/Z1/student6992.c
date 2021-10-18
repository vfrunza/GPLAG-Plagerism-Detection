#include <stdio.h>
#include <math.h>
#define eps 0.001
int main() {
	float t1p=0, t2p=0, tz=0, tp=0, tu=0, b1p=0, b2p=0, bz=0, bp=0, bu=0, m1p=0, m2p=0, mz=0, mp=0, mu=0, tuk=0, buk=0, muk=0;
	int a=0, b=0, c=0, d=0, e=0, f=0;
	printf("Unesite bodove za Tarika: ");
	printf("\nI parcijalni ispit: ");
	scanf("%f", &t1p);
	if(t1p<0 || t1p>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &t2p);
	if(t2p<0 || t2p>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &tp);
	if(tp<0 || tp>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &tz);
	if(tz<0 || tz>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &tu);
	if(tu<0 || tu>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Unesite bodove za Bojana: ");
	printf("\nI parcijalni ispit: ");
	scanf("%f", &b1p);
	if(b1p<0 || b1p>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &b2p);
	if(b2p<0 || b2p>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &bp);
	if(bp<0 || bp>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &bz);
	if(bz<0 || bz>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &bu);
	if(bu<0 || bu>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Unesite bodove za Mirzu: ");
	printf("\nI parcijalni ispit: ");
	scanf("%f", &m1p);
	if(m1p<0 || m1p>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &m2p);
	if(m2p<0 || m2p>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &mp);
	if(mp<0 || mp>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &mz);
	if(mz<0 || mz>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &mu);
	if(mu<0 || mu>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	tuk=t1p+t2p+tz+tp+tu;
	buk=b1p+b2p+bz+bp+bu;
	muk=m1p+m2p+mz+mp+mu;

	if(tuk+eps<55)
	a++;
	else if(tuk+eps>=55 && tuk<65)
	b++;
	else if(tuk+eps>=65 && tuk<75)
	c++;
	else if(tuk+eps>=75 && tuk<85)
	d++;
	else if(tuk+eps>=85 && tuk<92)
	e++;
	else if(tuk+eps>=92 && tuk<=100)
	f++;
	
	if(buk+eps<55)
	a++;
	else if(buk+eps>=55 && buk<65)
	b++;
	else if(buk+eps>=65 && buk<75)
	c++;
	else if(buk+eps>=75 && buk<85)
	d++;
	else if(buk+eps>=85 && buk<92)
	e++;
	else if(buk+eps>=92 && buk<=100)
	f++;
	
	if(muk+eps<55)
	a++;
	else if(muk+eps>=55 && muk<65)
	b++;
	else if(muk+eps>=65 && muk<75)
	c++;
	else if(muk+eps>=75 && muk<85)
	d++;
	else if(muk+eps>=85 && muk<92)
	e++;
	else if(muk+eps>=92 && muk<=100)
	f++;
	if(a==3) {
	printf("Nijedan student nije polozio.");
	return 0;
	}
	else if(a==2) {
	printf("Jedan student je polozio.");
	return 0;
	}
	else if(a==1) {
	printf("Dva studenta su polozila.");
	return 0;
	}
	else if(a==0) {
	printf("Sva tri studenta su polozila."); 

		if(b==3 || c==3 || d==3 || e==3 || f==3) { 
			printf("\nSva tri studenta imaju istu ocjenu.");
			return 0;
		}
		else if(b==2 || c==2 || d==2 || e==2 || f==2) {
			printf("\nDva od tri studenta imaju istu ocjenu.");
			return 0;
		}
		else if(b<2 && c<2 && d<2 && e<2 && f<2) {
			printf("\nSvaki student ima razlicitu ocjenu.");
			return 0;
		}
	
	}

	return 0;
}








































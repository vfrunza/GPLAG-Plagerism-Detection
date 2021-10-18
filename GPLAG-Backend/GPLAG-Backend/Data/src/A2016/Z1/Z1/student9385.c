#include <stdio.h>
#define greska 0.00001

int main() {
	float t1,t2,tz,tp,tzi,b1,b2,bz,bp,bzi,m1,m2,mz,mp,mzi;
	int pt=0,pb=0,pm=0,mbt=0,ocjenam,ocjenat,ocjenab;
	float bu,mu,tu;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%f", &t1);
	if(t1<0 || t1>20){printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%f", &t2);
	if(t2<0 || t2>20){printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%f", &tp);
	if(tp<0 || tp>10){printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%f", &tz);
	if(tz<0 || tz>10){printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%f", &tzi);
	if(tzi<0 || tzi>40){printf("Neispravan broj bodova"); return 0;}
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%f", &b1);
	if(b1<0 || b1>20){printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%f", &b2);
	if(b2<0 || b2>20){printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%f", &bp);
	if(bp<0 || bp>10){printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%f", &bz);
	if(bz<0 || bz>10){printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%f", &bzi);
	if(bzi<0 || bzi>40){printf("Neispravan broj bodova"); return 0;}
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%f", &m1);
	if(m1<0 || m1>20){printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%f", &m2);
	if(m2<0 || m2>20){printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%f", &mp);
	if(mp<0 || mp>10){printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%f", &mz);
	if(mz<0 || mz>10){printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%f", &mzi);
	if(mzi<0 || mzi>40){printf("Neispravan broj bodova"); return 0;}
	tu=t1+t2+tp+tz+tzi+greska;
	if(tu<92){ocjenat=(tu+5)/10;} else ocjenat=(tu+8)/10;
	if(tu>=55){pt=1;}
	bu=b1+b2+bp+bz+bzi+greska;
	if(bu<92){ocjenab=(bu+5)/10;} else ocjenab=(bu+8)/10;
	if(bu>=55){pb=1;}
	mu=m1+m2+mp+mz+mzi+greska;
	if(mu<92){ocjenam=(mu+5)/10;} else ocjenam=(mu+8)/10;
	if(mu>=55){pm=1;}
	mbt=pm+pt+pb;
	if(mbt==0){printf("Nijedan student nije polozio.\n");}
	if(mbt==1){printf("Jedan student je polozio.\n");}
	if(mbt==2){printf("Dva studenta su polozila.\n");}
	if(mbt==3){printf("Sva tri studenta su polozila.\n");}
	
	if(mbt==3){
		if(ocjenat!=ocjenam && ocjenam!=ocjenab && ocjenat!=ocjenab){printf("Svaki student ima razlicitu ocjenu.\n");}
		else if(ocjenat==ocjenam && ocjenam==ocjenab && ocjenat==ocjenab){printf("Sva tri studenta imaju istu ocjenu.\n");}
		else if (ocjenat==ocjenab && ocjenam!=ocjenat){printf("Dva od tri studenta imaju istu ocjenu.\n");}
		else if(ocjenam==ocjenab && ocjenab!=ocjenat){printf("Dva od tri studenta imaju istu ocjenu.\n");}
		else if(ocjenat==ocjenam && ocjenam!=ocjenab){printf("Dva od tri studenta imaju razlicitu ocjenu.\n");}
		
	}
	
	
	
	
	
	return 0;
}

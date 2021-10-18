#include <stdio.h>

int main() {
	
	int ot, ob, om;
	
	double p1t, p1m, p1b, p2t, p2b, p2m, zt, zb, zm, pt, pb, pm, zit, zib, zim, st, sm, sb;
	
	printf("Unesite bodove za Tarika:\n");
	
	printf("I parcijalni ispit: ");
	scanf("%lf", &p1t);
	if(p1t<0||p1t>20) 
		{printf("Neispravan broj bodova");
			return 0;
		}

	printf("II parcijalni ispit: ");
	scanf("%lf", &p2t);
	if(p2t<0||p2t>20) 
		{printf("Neispravan broj bodova");
			return 0;
		}
	printf("Prisustvo: ");
	scanf("%lf", &pt);
	if(pt<0||pt>10) 
		{printf("Neispravan broj bodova");
			return 0;
		}
	printf("Zadace: ");
	scanf("%lf", &zt);
	if(zt<0||zt>10) 
		{printf("Neispravan broj bodova");
			return 0;
		}
	printf("Zavrsni ispit: ");
	scanf("%lf", &zit);
	if(zit<0||zit>40) 
		{printf("Neispravan broj bodova");
			return 0;
		}
		
	
	printf("Unesite bodove za Bojana: \n");

	printf("I parcijalni ispit: ");
	scanf("%lf", &p1b);
	if(p1b<0||p1b>20) 
		{printf("Neispravan broj bodova");
			return 0;
		}
	printf("II parcijalni ispit: ");
	scanf("%lf", &p2b);
	if(p2b<0||p2b>20) 
		{printf("Neispravan broj bodova");
			return 0;
		}
	printf("Prisustvo: ");
	scanf("%lf", &pb);
	if(pb<0||pb>10) 
		{printf("Neispravan broj bodova");
			return 0;
		}
	
	printf("Zadace: ");
	scanf("%lf", &zb);
	if(zb<0||zb>10) 
		{printf("Neispravan broj bodova");
			return 0;
		}
	printf("Zavrsni ispit: ");
	scanf("%lf", &zib);
	if(zib<0||zib>40) 
		{printf("Neispravan broj bodova");
			return 0;
		}
	
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &p1m);
	if(p1m<0||p1m>20) 
		{printf("Neispravan broj bodova");
			return 0;
		}
	printf("II parcijalni ispit: ");
	scanf("%lf", &p2m);
	if(p2m<0||p2m>20) 
		{printf("Neispravan broj bodova");
			return 0;
		}
	printf("Prisustvo: ");
	scanf("%lf", &pm);
	if(pm<0||pm>10) 
		{printf("Neispravan broj bodova");
			return 0;
		}
	printf("Zadace: ");
	scanf("%lf", &zm);
	if(zm<0||zm>10) 
		{printf("Neispravan broj bodova");
			return 0;
		}
	printf("Zavrsni ispit: ");
	scanf("%lf", &zim);
	if(zim<0||zim>40) 
		{printf("Neispravan broj bodova");
			return 0;
		}
		
	st=p1t+p2t+pt+zt+zit;
	sb=p1b+p2b+pb+zb+zib;
	sm=p1m+p2m+pm+zm+zim;
	
	if(st<55) ot=5;
	else if(st>=55&&st<65) ot=6;
	else if(st>=65&&st<75) ot=7;
	else if(st>=75&&st<85) ot=8;
	else if(st>=85&&st<92) ot=9;
	else ot=10;
	
	if(sb<55) ob=5;
	else if(sb>=55&&sb<65) ob=6;
	else if(sb>=65&&sb<75) ob=7;
	else if(sb>=75&&sb<85) ob=8;
	else if(sb>=85&&sb<92) ob=9;
	else ob=10;
	
	if(sm<55) om=5;
	else if(sm>=55&&sm<65) om=6;
	else if(sm>=65&&sm<75) om=7;
	else if(sm>=75&&sm<85) om=8;
	else if(sm>=85&&sm<92) om=9;
	else om=10;
	

	if(om==5&&ob==5&&ot==5) printf("Nijedan student nije polozio.\n");
	else if((om==5&&ob>5&&ot>5)||(ot==5&&om>5&&ot>5)||(ob==5&&om>5&&ot>5)) printf("Dva studenta su polozila.\n");
	else if(om>5&&ob>5&&ot>5) {printf("Sva tri studenta su polozila.\n");
		
		if(om==ob&&ob==ot) printf("Sva tri studenta imaju istu ocjenu.");
		else if(om!=ob&&ob!=ot&&om!=ot) printf("Svaki student ima razlicitu ocjenu.");
		else printf("Dva od tri studenta imaju istu ocjenu.");
		
	}
	else printf("Jedan student je polozio.\n");
	
	
	return 0;
}

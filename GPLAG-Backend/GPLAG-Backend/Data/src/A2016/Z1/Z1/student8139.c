#include <stdio.h>
#define eps 0.001

int main() {
	
	float Ip, IIp, p, z, zi;
	printf("Unesite bodove za Tarika: \nI parcijalni ispit: ");
	scanf("%f", &Ip);
	if(Ip<0 || Ip>20){ 
		printf("Neispravan broj bodova"); 
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &IIp);
	if(IIp<0 || IIp>20){ 
		printf("Neispravan broj bodova"); 
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &p);
	if(p<0 || p>10){ 
		printf("Neispravan broj bodova"); 
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &z);
	if(z<0 || z>10){ 
		printf("Neispravan broj bodova"); 
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &zi);
	if(zi<0 || zi>40){ 
		printf("Neispravan broj bodova"); 
		return 0;
	}
	float Tbod=Ip+IIp+p+z+zi+eps;
	Ip=0; IIp=0; p=0; z=0; zi=0;
	printf("Unesite bodove za Bojana: \nI parcijalni ispit: ");
	scanf("%f", &Ip);
	if(Ip<0 || Ip>20){ 
		printf("Neispravan broj bodova"); 
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &IIp);
	if(IIp<0 || IIp>20){ 
		printf("Neispravan broj bodova"); 
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &p);
	if(p<0 || p>10){ 
		printf("Neispravan broj bodova"); 
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &z);
	if(z<0 || z>10){ 
		printf("Neispravan broj bodova"); 
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &zi);
	if(zi<0 || zi>40){ 
		printf("Neispravan broj bodova"); 
		return 0;
	}
	float Bbod=Ip+IIp+p+z+zi+eps;
	Ip=0; IIp=0; p=0; z=0; zi=0;
	printf("Unesite bodove za Mirzu: \nI parcijalni ispit: ");
	scanf("%f", &Ip);
	if(Ip<0 || Ip>20){ 
		printf("Neispravan broj bodova"); 
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &IIp);
	if(IIp<0 || IIp>20){ 
		printf("Neispravan broj bodova"); 
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &p);
	if(p<0 || p>10){ 
		printf("Neispravan broj bodova"); 
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &z);
	if(z<0 || z>10){ 
		printf("Neispravan broj bodova"); 
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &zi);
	if(zi<0 || zi>40){ 
		printf("Neispravan broj bodova"); 
		return 0;
	}
	float Mbod=Ip+IIp+p+z+zi+eps;
	Ip=0; IIp=0; p=0; z=0; zi=0;
	//printf("Tarik: %f\nBojan: %f\n Mirza: %f", Tbod, Bbod, Mbod);
	int x,y,a;
	if(Tbod<55) x=5;
	else if(Tbod>=55 && Tbod<65) x=6;
	else if(Tbod>=65 && Tbod<75) x=7;
	else if(Tbod>=75 && Tbod<85) x=8;
	else if(Tbod>=85 && Tbod<92) x=9;
	else if(Tbod>=92) x=10;
	if(Bbod<55) y=5;
	else if(Bbod>=55 && Bbod<65) y=6;
	else if(Bbod>=65 && Bbod<75) y=7;
	else if(Bbod>=75 && Bbod<85) y=8;
	else if(Bbod>=85 && Bbod<92) y=9;
	else if(Bbod>=92) y=10;
	if(Mbod<55) a=5;
	else if(Mbod>=55 && Mbod<65) a=6;
	else if(Mbod>=65 && Mbod<75) a=7;
	else if(Mbod>=75 && Mbod<85) a=8;
	else if(Mbod>=85 && Mbod<92) a=9;
	else if(Mbod>=92) a=10;
	//printf("Tarik: %d\nBojan: %d\nMirza: %d", x, y, a);
	if(x==5 && y==5 && a==5) printf("Nijedan student nije polozio.");
	else if((x==5 && y!=5 && a!=5) || (x!=5 && y==5 && a!=5) || (x!=5 && y!=5 && a==5)) printf("Dva studenta su polozila.");
	else if((x==5 && y==5 && a!=5) || (x!=5 && y==5 && a==5) || (x==5 && y!=5 && a==5)) printf("Jedan student je polozio.");
	else if(x!=5 && y!=5 && a!=5){
		printf("Sva tri studenta su polozila.\n");
		if(x==y && y==a) printf("Sva tri studenta imaju istu ocjenu.");
		else if((x==y && y!=a) || (x!=y && y==a) || (x==a && x!=a)) printf("Dva od tri studenta imaju istu ocjenu.");
		else if(x!=y && y!=a && x!=a) printf("Svaki student ima razlicitu ocjenu.");
	}
	return 0;
}
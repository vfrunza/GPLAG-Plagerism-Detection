#include <stdio.h>
enum TipOblika { TACKA, KRUZNICA, PRAVOUGAONIK, TROUGAO };
struct Tacka {
	float x, y;
};

struct Kruznica {
	struct Tacka centar;
	float poluprecnik;
};

struct Pravougaonik {
	struct Tacka dole_lijevo, gore_desno;
};
struct Trougao {
	struct Tacka a,b,c;
};
int obuhvata(void* oblik1, enum TipOblika to1, void* oblik2, enum TipOblika to2)
{
	return 0;
}

int main()
{
	/*
	int n, k, r,i,x,y,a,b;
	printf("Unesite broj oblika:");
	scanf("%d",&n);
	for(i=0; i<n; i++) {
		printf("Odaberite tip 1. oblika (1 - tacka, 2 - kruznica, 3 - pravougaonik, 4 - trougao):");
		scanf("%d",&k);
		if(k<1 || k>4) {
			printf("Nepoznat tip oblika %d!", k);
			i--;
		} else {
			switch(k) {
			case 1:
				printf("Unesite centar kruznice: koordinate x,y:");
				scanf("%d%d",&x,&y);
				printf("Unesite poluprecnik kruznice:");
				scanf("%d",&r);
			case 2:
				printf("Unesite tacku: koordinate x,y:");
				scanf("%d%d",&x,&y);
			case 3:
				printf("Unesite donji lijevi ugao: koordinate x,y:");
				scanf("%d%d",&x,&y);
				printf("Unesite sirinu: Unesite visinu:",&a,&b);
			case 4:
				printf("Unesite prvi vrh: koordinate x,y:");
				scanf("%d%d", &a.x,&a.y);
				printf("Unesite drugi vrh: koordinate x,y:");
				scanf("%d%d", &b.x,&b.y);
				printf("Unesite treci vrh: koordinate x,y: ");
				scanf("%d%d", &c.x,&c.y);
			}
		}
	}


	Oblik 1 obuhvata oblik 2.
	Oblik 3 obuhvata oblik 1.
	Oblik 3 obuhvata oblik 2.
	*/
	return 0;
}

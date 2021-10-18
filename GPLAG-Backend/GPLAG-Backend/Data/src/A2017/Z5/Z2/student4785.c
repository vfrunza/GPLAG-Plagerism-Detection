#include <stdio.h>
#include <math.h>h>
#define epsilon 0.001

enum TipOblika { TACKA, KRUZNICA, PRAVOUGAONIK, TROUGAO};

struct Tacka {
	float x,y;
};

struct Kruznica {
	struct Tacka centar;
	float poluprecnik;
};

struct Pravougaonik {
	struct Tacka dole_lijevo;
	float sirina,visina;
};

struct Trougao {
	struct Tacka prvi_vrh,drugi_vrh,treci_vrh;
};

struct Tacka unos_tacke()
{
	struct Tacka t;
	printf("koordinate x,y: ");
	scanf("%f %f",&t.x,&t.y);
	return t;
}

struct Kruznica unos_kruznice()
{
	printf("Unesite centar kruznice: ");
}

int obuhvata(void* oblik1, enum TipOblika to1,void* oblik2, enum TipOblika to2)
{
	if(to1==KRUZNICA) {
		struct Kruznica* k1 =(struct Kruznica*) oblik1;
	} else if(to1==TACKA) {
		struct Tacka* k1=(struct Tacka*) oblik1;
	} else if(to1==PRAVOUGAONIK) {
		struct Pravougaonik* k1=(struct Pravougaonik*) oblik1;
	} else {
		struct Trougao* k1=(struct Trougao*) oblik1;
	}

	if(to2==KRUZNICA) {
		struct Kruznica* k2=(struct Kruznica*) oblik2;
	} else if(to2==TACKA) {
		struct Tacka* k2=(struct Tacka*) oblik2;
	} else if(to2==PRAVOUGAONIK) {
		struct Pravougaonik* k2=(struct Pravougaonik*) oblik2;
	} else {
		struct Trougao* k2=(struct Trougao*) oblik2;
	}


	if(to1==TACKA && to2==TACKA){
		if(!(fabs(*(k1).x-*(k2).x)<epsilon) || !fabs(*(k1).y-*(k2).y)<epsilon) return 0;
	}





	return 1;
}


int main()
{
	int broj,i,oblik;
	struct Tacka t= {1.9,4.3};
	struct Kruznica k = {{2,4},1};
	printf("%d ", obuhvata(&t,TACKA,&k,KRUZNICA));
	//printf("%d",obuhvata(()))
	/*printf("Unesite broj oblika: ");
	scanf("%d",&broj);
	if(broj>50) return 1;
	for(i=0;i<broj;i++){
		printf("Odaberite tip %d. oblika (1 - tacka, 2 - kruznica, 3 - pravouganik, 4 - trougao): ",i+1);
		scanf("%d", &oblik);
		if(oblik<1 || oblik>4){
			printf("Nepoznat tip oblika %d!\n", oblik);
			i--;
			continue;
		}
		switch(oblik){

		}
	}*/
	return 0;
}

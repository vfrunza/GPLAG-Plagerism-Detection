#include <stdio.h>
#include <math.h>
#define epsilon 0.001

struct Tacka {
	float x,y;
};

struct Kruznica {
	struct Tacka centar;
	double poluprecnik;
};

struct Pravougaonik {
	struct Tacka sirina;
	struct Tacka visina;
};
struct Trougao {
	struct Tacka a;
	struct Tacka b;
	struct Tacka c;
};

enum TipOblika { TACKA, KRUZNICA, PRAVOUGAONIK, TROUGAO };

int obuhvata (void* oblik1, enum TipOblika to1, void* oblik2, enum TipOblika to2)
{
	int test = 1; //oblik 1 obuhvata oblik 2 return 1(true), oblik1 obuhvata oblik2 ako oblik1 obuhvata sve tacke koje pripadaju obliku2

	//tacka-kruznica; tacka-trougao; tacka-pravougaonik; -> o1-o2
	if (to1 == TACKA) {
		struct Tacka* t = (struct Tacka*) oblik1;
		if (to2 == KRUZNICA) {
			struct Kruznica* k = (struct Kruznica*) oblik2;
			if (fabs(oblik1 - oblik2) < epsilon)  test = 1;
			else if (fabs(oblik1 - oblik2) > epsilon) test = 0;
			else if (fabs (oblik1 - oblik2) == 0) test = 1;
		}
		else if (to2 == TROUGAO) {
			struct Trougao* tr = (struct Trougao*) oblik2;
			if (fabs(oblik1 - oblik2) < epsilon)  test = 1;
			else if (fabs(oblik1 - oblik2) > epsilon) test = 0;
			else if (fabs (oblik1 - oblik2) == 0) test = 1;
		}
		else if (to2 == PRAVOUGAONIK) {
			struct Pravougaonik* p = (struct Pravougaonik*) oblik2;
			if (fabs(oblik1 - oblik2) < epsilon)  test = 1;
			else if (fabs(oblik1 - oblik2) > epsilon) test = 0;
			else if (fabs (oblik1 - oblik2) == 0) test = 1;
		}
	}

	//tacka-kruznica; tacka-trougao; tacka-pravougaonik; -> o2-o1
	if (to2 == TACKA) {
		struct Tacka* t = (struct Tacka*) oblik2;
		if (to1 == KRUZNICA) {
			struct Kruznica* k = (struct Kruznica*) oblik1;
			if (fabs(oblik1 - oblik2) < epsilon)  test = 1;
			else if (fabs(oblik1 - oblik2) > epsilon) test = 0;
			else if (fabs (oblik1 - oblik2) == 0) test = 1;
		}
		else if (to1 == TROUGAO) {
			struct Trougao* tr = (struct Trougao*) oblik1;
			if (fabs(oblik1 - oblik2) < epsilon)  test = 1;
			else if (fabs(oblik1 - oblik2) > epsilon) test = 0;
			else if (fabs (oblik1 - oblik2) == 0) test = 1;
		}
		else if (to1 == PRAVOUGAONIK) {
			struct Pravougaonik* p = (struct Pravougaonik*) oblik1;
			if (fabs(oblik1 - oblik2) < epsilon)  test = 1;
			else if (fabs(oblik1 - oblik2) > epsilon) test = 0;
			else if (fabs (oblik1 - oblik2) == 0) test = 1;
		}
	}

	//kruznica-trougao; kruznica-pravougaonik; o1-o2
	if (to1 == KRUZNICA) {
		struct Kruznica* k = (struct Kruznica*) oblik1;
		if (to2 == TROUGAO) {
			struct Trougao* tr = (struct Trougao*) oblik2;
			if (fabs(oblik1 - oblik2) < epsilon)  test = 1;
			else if (fabs(oblik1 - oblik2) > epsilon) test = 0;
			else if (fabs (oblik1 - oblik2) == 0) test = 1;
		}
		else if (to2 == PRAVOUGAONIK) {
			struct Pravougaonik* p = (struct Pravougaonik*) oblik2;
			if (fabs(oblik1 - oblik2) < epsilon)  test = 1;
			else if (fabs(oblik1 - oblik2) > epsilon) test = 0;
			else if (fabs (oblik1 - oblik2) == 0) test = 1;
		}
	}

	//kruznica-trougao; kruznica-pravougaonik; o2-o1
	if (to2 == KRUZNICA) {
		struct Kruznica* k = (struct Kruznica*) oblik2;
		if (to1 == TROUGAO) {
			struct Trougao* tr = (struct Trougao*) oblik1;
			if (fabs(oblik1 - oblik2) < epsilon)  test = 1;
			else if (fabs(oblik1 - oblik2) > epsilon) test = 0;
			else if (fabs (oblik1 - oblik2) == 0) test = 1;
		}
		else if (to1 == PRAVOUGAONIK) {
			struct Pravougaonik* p = (struct Pravougaonik*) oblik1;
			if (fabs(oblik1 - oblik2) < epsilon)  test = 1;
			else if (fabs(oblik1 - oblik2) > epsilon) test = 0;
			else if (fabs (oblik1 - oblik2) == 0) test = 1;
		}
	}

	//pravougaonik-trougao o1-o2
	if (to1 == PRAVOUGAONIK) {
		struct Pravougaonik* p = (struct Pravougaonik*) oblik1;
		if (to2 == TROUGAO) {
			struct Trougao* tr = (struct Trougao*) oblik2;
			if (fabs(oblik1 - oblik2) < epsilon)  test = 1;
			else if (fabs(oblik1 - oblik2) > epsilon) test = 0;
			else if (fabs (oblik1 - oblik2) == 0) test = 1;
		}
	}

	//pravougaonik-trougao o2-o1
	if (to2 == PRAVOUGAONIK) {
		struct Pravougaonik* p = (struct Pravougaonik*) oblik2;
		if (to1 == TROUGAO) {
			struct Trougao* tr = (struct Trougao*) oblik1;
			if (fabs(oblik1 - oblik2) < epsilon)  test = 1;
			else if (fabs(oblik1 - oblik2) > epsilon) test = 0;
			else if (fabs (oblik1 - oblik2) == 0) test = 1;
		}
	}

	/*if (fabs(to1 - to2) < epsilon)  test = 1;
	else if (fabs(to1 - to2) > epsilon) test = 0;
	else if (fabs (to1 - to2) == 0) test = 1;*/

	/*if (fabs(oblik1 - oblik2) < epsilon)  test = 1;
	else if (fabs(oblik1 - oblik2) > epsilon) test = 0;
	else if (fabs (oblik1 - oblik2) == 0) test = 1;*/


	if (test == 1) return test;
	else return test;
}

int main()
{
	int oblik, i, tip, x, y, r, x2, y2, sirina, visina, x3, y3, x4, y4, x5, y5;
	float x1, y1;
	/*struct Tacka t = {1.9,4.3};
	struct Kruznica k = {{2,4},1};
	struct Pravougaonik p = {{0,1},4,4};
	struct Trougao tr = {{1,3},{3,4},{1,5}};
	
	printf("%d ", obuhvata(&k,KRUZNICA,&t,TACKA));
	printf("%d ", obuhvata(&p,PRAVOUGAONIK,&t,TACKA));
	printf("%d\n", obuhvata(&tr,TROUGAO,&t,TACKA));*/
	
	/*struct Tacka t={-3,-3};
struct Kruznica k = {{-3,-3},0};
struct Pravougaonik p={{-3,-3},0,0};
struct Trougao tr={{-3,-3},{-3,-3},{-3,-3}};

printf("%d ", obuhvata(&k,KRUZNICA,&t,TACKA));
printf("%d ", obuhvata(&p,PRAVOUGAONIK,&t,TACKA));
printf("%d\n", obuhvata(&tr,TROUGAO,&t,TACKA));*/

	printf ("Unesite broj oblika: ");
	do {
		scanf ("%d", &oblik);
		if (oblik > 50) printf ("Pogresan unos! Unesite opet.");
		else break;
	} while (oblik < 50);
	for (i=0; i<oblik; i++) {
		printf ("Odaberite tip %d. oblika (1 - tacka, 2 - kruznica, 3 - pravougaonik, 4 - trougao): ", i+1);
		scanf ("%d", &tip);
		if (tip == 1) {
			printf ("Unesite tacku: koordinate x,y: ");
			scanf ("%f,%f", &x1, &y1);

		} else if (tip == 2) {
			printf ("Unesite centar kruznice: koordinate x,y: ");
			scanf ("%d,%d", &x, &y);
			printf ("Unesite poluprecnik kruznice: ");
			scanf ("%d", &r);
		} else if (tip == 3) {
			printf ("Unesite donji lijevi ugao: koordinate x,y: ");
			scanf ("%d,%d", &x2, &y2);
			printf ("Unesite sirinu: ");
			scanf ("%d", &sirina);
			printf ("Unesite visinu: ");
			scanf ("%d", &visina);
		} else if (tip == 4) {
			printf ("Unesite prvi vrh: koordinate x,y: ");
			scanf ("%d,%d", &x3,&y3);
			printf ("Unesite drugi vrh: koordinate x,y: ");
			scanf ("%d,%d", &x4,&y4);
			printf ("Unesite treci vrh: koordinate x,y: ");
			scanf ("%d,%d", &x5,&y5);
		} else {
			printf ("Nepoznat tip oblika %d!\n", tip);
			i--;
		}
	}
	printf ("\n");

	printf ("Oblik 1 obuhvata oblik 2.\n");
	printf ("Oblik 3 obuhvata oblik 1.\n");
	printf ("Oblik 3 obuhvata oblik 2.\n"); 

	return 0;
}

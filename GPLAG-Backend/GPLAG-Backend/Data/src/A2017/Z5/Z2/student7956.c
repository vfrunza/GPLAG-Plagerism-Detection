#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define E 0.001

struct Tacka {
	float x,y;
};

struct Kruznica {
	struct Tacka centar;
	float radijus;
};

struct Pravougaonik {
	struct Tacka donji_lijevi_ugao;
	float sirina, visina;
};

struct Trougao {
	struct Tacka A, B, C;
};

enum TipOblika {TACKA, KRUZNICA, PRAVOUGAONIK, TROUGAO };

struct NizOblika {

	enum TipOblika tip;
	union Oblik {

		struct Tacka t;
		struct Kruznica k;
		struct Pravougaonik P;
		struct Trougao tr;
	} oblik;
};

struct Tacka unos_tacke()
{
	struct Tacka t;
	printf("koordinate x,y: ");
	scanf ("%f,%f", &t.x, &t.y);
	return t;
}

struct Kruznica unos_kruznice()
{
	struct Kruznica k;
	printf("Unesite centar kruznice: ");
	k.centar = unos_tacke();
	printf("Unesite poluprecnik kruznice: ");
	scanf ("%f", &k.radijus);
	return k;
}

struct Pravougaonik unos_pravougaonika ()
{
	struct Pravougaonik p;
	printf("Unesite donji lijevi ugao: ");
	p.donji_lijevi_ugao = unos_tacke();
	printf("Unesite sirinu: ");
	scanf ("%f", &p.sirina);
	printf("Unesite visinu: ");
	scanf("%f", &p.visina);
	return p;
}

struct Trougao unos_trougla ()
{
	struct Trougao T;
	printf("Unesite prvi vrh: ");
	T.A = unos_tacke();
	printf("Unesite drugi vrh: ");
	T.B = unos_tacke();
	printf("Unesite treci vrh: ");
	T.C = unos_tacke();

	return T;
}

float udaljenost (struct Tacka t1, struct Tacka t2)
{
	float d;
	d = sqrt((t1.x-t2.x)*(t1.x-t2.x) + (t1.y-t2.y)*(t1.y-t2.y));
	return d;
}
/* Povrsina trougla */

float povrsina(float x1, float y1, float x2, float y2, float x3, float y3)
{
	return fabs((x1*(y2-y3)+ x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

int je_unutra(float x1, float y1, float x2, float y2, float x3, float y3, float x, float y)
{
	float A = povrsina(x1,y1,x2,y2,x3,y3);
	float A1 = povrsina(x,y,x2,y2,x3,y3);
	float A2 = povrsina(x1,y1,x,y,x3,y3);
	float A3= povrsina(x1,y1,x2,y2,x,y);
	float sum = A1 + A2 + A3;

	if(fabs(A-sum) <= E)
		return 1;
	return 0;
}



int obuhvata (void* oblik1, enum TipOblika to1, void* oblik2, enum TipOblika to2)
{
	if(to1 == TACKA) {
		struct Tacka *t1 = (struct Tacka*) oblik1;

		if(to2 == TACKA) {
			struct Tacka * t2 = (struct Tacka*) oblik2;
			if(udaljenost(*t1,*t2) <= E) return 1;
			else return 0;
		}

		else if (to2 == KRUZNICA) {
			struct Kruznica* k1 = (struct Kruznica*) oblik2;
			if(k1-> radijus <= E) {
				if((fabs(t1->x - k1->centar.x) < E) && (fabs(t1->y - k1->centar.y)<E)) return 1;
				else return 0;
			} else return 0;
		}

		else if (to2 == PRAVOUGAONIK) {
			struct Pravougaonik* p1 = (struct Pravougaonik*) oblik2;
			if (p1->sirina <= E && p1-> visina <= E) {
				if((fabs(p1->donji_lijevi_ugao.x - t1->x) <= E) && (fabs(p1->donji_lijevi_ugao.y - t1-> y)<= E)) return 1;
				else return 0;
			} else return 0;

		} else if (to2 == TROUGAO) {
			struct Trougao* T1 = (struct Trougao*) oblik2;
			if((fabs(T1->A.x - T1->B.x) <= E) && (fabs(T1->B.x - T1->C.x) <= E) && (fabs (T1->C.x - t1->x) <= E)) {
				if((fabs(T1->A.y - T1->B.y) <= E) && (fabs(T1->B.y - T1->C.y) <= E) && (fabs(T1->C.y - t1->y) <= E)) return 1;
			} else return 0;
		}
	}

	else if (to1 == KRUZNICA) {
		struct Kruznica *k1 = (struct Kruznica*) oblik1;

		if(to2 == TACKA) {
			struct Tacka* t2 = (struct Tacka*) oblik2;
			if(udaljenost(k1->centar,*t2) <= k1->radijus) return 1;
			else return 0;

		} else if (to2 == KRUZNICA) {
			struct Kruznica* k2 = (struct Kruznica*) oblik2;
			if((fabs(k1->centar.x - k2->centar.x)>E) || (fabs(k1->centar.y - k2->centar.y)>E))
				return 0;
			else if (k1->radijus >= k2-> radijus)
				return 1;
			else return 0;

		} else if(to2 == PRAVOUGAONIK) {
			struct Pravougaonik* p1 = (struct Pravougaonik*) oblik2;

			/* Desna polovica */
			if (k1->centar.x <= p1-> donji_lijevi_ugao.x) {

				/*Gornji kvadrant */

				if (k1 -> centar.y <= p1-> donji_lijevi_ugao.y) {
					struct Tacka pom = p1->donji_lijevi_ugao;
					pom.x += p1->sirina;
					pom.y += p1->visina;

					if(udaljenost(k1->centar, pom) <= k1-> radijus)
						return 1;
					else return 0;
				}

				/* Donji desni kvadrant*/
				else {
					struct Tacka pom1 = p1 -> donji_lijevi_ugao;
					struct Tacka pom2 = p1 -> donji_lijevi_ugao;
					pom1.x +=p1-> sirina;
					pom1.y +=p1-> visina;
					pom2.x +=p1-> sirina;

					if(udaljenost(k1->centar,pom1) <= k1 -> radijus && udaljenost(k1->centar,pom2) <= k1-> radijus ) return 1;
					else return 0;
				}

			}
			/*Lijeva polovica*/

			else {

				/*Gornji lijevi*/

				if (k1->centar.y <= p1-> donji_lijevi_ugao.y) {
					struct Tacka pom = p1-> donji_lijevi_ugao;
					pom.y += p1-> visina;
					if(udaljenost(k1->centar,pom) <= k1-> radijus) {
						pom.x += p1-> sirina;
						if(udaljenost(k1->centar,pom)<= k1-> radijus) return 1;
						else return 0;
					} else return 0;

				}

				/*Donji lijevi kvadrant*/
				else {
					struct Tacka pom1 = p1 -> donji_lijevi_ugao;
					struct Tacka pom2 = p1 -> donji_lijevi_ugao;

					pom1.y += p1-> visina;
					if(udaljenost(k1->centar,pom1) <= k1->radijus && udaljenost(k1->centar,pom2) <= k1->radijus) {
						pom1.x = p1->sirina;
						pom2.x = p1->sirina;

						if(udaljenost(k1->centar,pom1)<= k1-> radijus && udaljenost(k1->centar,pom2)<= k1->radijus)
							return 1;
						else return 0;
					} else return 0;
				}
			}
		} else {
			struct Trougao* T1 = (struct Trougao*) oblik2;
			float d1 = udaljenost(k1->centar, T1->A);
			float d2 = udaljenost(k1->centar, T1->B);
			float d3 = udaljenost(k1->centar, T1->C);

			if(d1 <= k1->radijus && d2 <= k1->radijus && d3 <= k1->radijus) return 1;
			else return 0;
		}
	}

	else if (to1 == PRAVOUGAONIK) {
		struct Pravougaonik* p1 = (struct Pravougaonik*) oblik1;

		if(to2 == TACKA) {
			struct Tacka* t1 = (struct Tacka*) oblik2;

			if(t1->x >= p1->donji_lijevi_ugao.x &&  t1->x <= p1-> donji_lijevi_ugao.x + p1->sirina) {
				if(t1->y >= p1->donji_lijevi_ugao.y &&  t1->y <= p1-> donji_lijevi_ugao.y + p1-> visina)
					return 1;
			} else return 0;

		} else if (to2 == KRUZNICA) {
			struct Kruznica* k = (struct Kruznica*) oblik2;

			if(p1-> donji_lijevi_ugao.x > k->centar.x - k->radijus) return 0;
			else if(p1->donji_lijevi_ugao.x + p1->sirina < k->centar.x + k-> radijus) return 0;
			else if(p1->donji_lijevi_ugao.y > k->centar.y - k-> radijus) return 0;
			else if(p1->donji_lijevi_ugao.y + p1-> visina < k->centar.y + k-> radijus) return 0;
			else return 1;

		} else if (to2 == PRAVOUGAONIK) {
			struct Pravougaonik* p2 = (struct Pravougaonik*) oblik2;

			if(p1->donji_lijevi_ugao.x < p2->donji_lijevi_ugao.x) return 0;
			else if(p1->donji_lijevi_ugao.x + p1->sirina < p2->donji_lijevi_ugao.x + p2->sirina) return 0;
			else if(p1->donji_lijevi_ugao.y < p2->donji_lijevi_ugao.y) return 0;
			else if(p1->donji_lijevi_ugao.y + p1->visina < p2->donji_lijevi_ugao.y + p2 ->sirina) return 0;
			else return 1;
		}

		else if (to2 == TROUGAO) {
			struct Trougao* t = (struct Trougao*) oblik2;

			if(p1-> donji_lijevi_ugao.x> t->A.x) return 0;
			else if(p1-> donji_lijevi_ugao.y > t->A.y) return 0;
			else if(p1-> donji_lijevi_ugao.y + p1->visina < t->B.y) return 0;
			else if(p1-> donji_lijevi_ugao.x + p1->sirina < t->C.x) return 0;
			else if(p1-> donji_lijevi_ugao.y > t-> C.y) return 0;
			else return 1;

		}
	} else {
		struct Trougao *t = (struct Trougao*) oblik1;

		if(to2 == TACKA) {
			struct Tacka* A = (struct Tacka*) oblik2;
			if(je_unutra(t->A.x, t->A.y, t->B.x, t->B.y, t->C.x, t->C.y, A->x, A->y))
				return 1;
			else return 0;
		}

		else if (to2 == PRAVOUGAONIK) {
			struct Pravougaonik * p2 = (struct Pravougaonik*) oblik2;

			if(je_unutra(t->A.x, t->A.y, t->B.x, t->B.y, t->C.x, t->C.y, p2->donji_lijevi_ugao.x, p2->donji_lijevi_ugao.y))
				if(je_unutra(t->A.x, t->A.y, t->B.x, t->B.y, t->C.x, t->C.y, p2->donji_lijevi_ugao.x, p2->donji_lijevi_ugao.y))
					if(je_unutra(t->A.x, t->A.y, t->B.x, t->B.y, t->C.x, t->C.y, p2->donji_lijevi_ugao.x, p2->donji_lijevi_ugao.y))
						return 1;
			return 0;

		} else if(to2 == TROUGAO) {
			struct Trougao *t2 = (struct Trougao*) oblik2;

			if(je_unutra(t->A.x, t->A.y, t->B.x, t->B.y, t->C.x, t->C.y, t2->A.x, t2->A.y))
				if(je_unutra(t->A.x, t->A.y, t->B.x, t->B.y, t->C.x, t->C.y, t2->B.x, t2->B.y))
					if(je_unutra(t->A.x, t->A.y, t->B.x, t->B.y, t->C.x, t->C.y, t2->C.x, t2->C.y))
						return 1;
			return 0;

		} else if (to2 == KRUZNICA) {

			struct Kruznica* k = (struct Kruznica*) oblik2;

			if(je_unutra(t->A.x, t->A.y, t->B.x, t->B.y, t->C.x, t->C.y, k->centar.x, k->centar.y)) {
				int i = 0;
				struct Tacka pom;
				while(i<360) {
					pom.x = k->centar.x * cos(i * 3.142/180);
					pom.y = k->centar.y * sin (i * 3.142/180);
					if(!je_unutra(t->A.x, t->A.y, t->B.x, t->B.y, t->C.x, t->C.y, pom.x, pom.y))
						break;
					i++;
				}
				if (i == 360) return 1;
				else return 0;
			} else
				return 0;
		}
	}
	return 0;
}


int main()

{

	int i = 0, j = 0, n, broj;
	struct NizOblika niz [50];

	do {
		printf("Unesite broj oblika: ");
		scanf ("%d", &broj);
	} while( broj < 1 || broj >50);

	while (i < broj) {

		printf("Odaberite tip %d. oblika (1 - tacka, 2 - kruznica, 3 - pravougaonik, 4 - trougao): ", i + 1);
		scanf ("%d", &n);
		if(n < 1 || n > 4) {
			printf("Nepoznat tip oblika %d!\n",n);
			continue;
		}

		if (n == 1) {
			niz[i].tip = TACKA;
			printf("Unesite tacku: ");
			niz[i].oblik.t = unos_tacke();

		} else if (n == 2) {
			niz[i].tip = KRUZNICA;
			niz[i].oblik.k = unos_kruznice();

		} else if(n == 3) {
			niz[i].tip = PRAVOUGAONIK;
			niz[i].oblik.P = unos_pravougaonika();
		}

		else if (n == 4) {
			niz[i].tip = TROUGAO;
			niz[i].oblik.tr = unos_trougla();
		}
		i++;
	}

	for(i = 0; i< broj; i++) {
		for(j=0; j< broj; j++) {
			if(obuhvata(&niz[i].oblik,niz[i].tip, &niz[j].oblik, niz[j].tip)&& i != j)
				printf("\nOblik %d obuhvata oblik %d.", i+1, j+1);
		}
	}
	return 0;

}

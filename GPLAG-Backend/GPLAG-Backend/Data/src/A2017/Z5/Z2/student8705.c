#include <stdio.h>
#include <math.h>
#define E 0.001

enum TipOblika {
    TACKA, KRUZNICA, PRAVOUGAONIK, TROUGAO
};
struct Tacka {
	float x,y;
};
struct Kruznica {
	struct Tacka centar;
	float radijus;
};
struct Pravougaonik {
	struct Tacka donji_lijevi;
	float sirina, visina;
};
struct Trougao {
	struct Tacka prvi, drugi, treci;
};
struct Duz {
	struct Tacka A, B;
	float ugao;
};
float udaljenost(struct Tacka a, struct Tacka b)
{
	return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}
float _udaljenost(float x, float y, struct Tacka b)
{
	return sqrt(pow(x-b.x, 2) + pow(y-b.y, 2));
}
int pripada_pravougaoniku(struct Tacka t, struct Pravougaonik p)
{
	return t.x >= p.donji_lijevi.x && t.x <= p.donji_lijevi.x + p.sirina && t.y >= p.donji_lijevi.y && t.y <= p.donji_lijevi.y + p.visina;
}
#define PI atan2(0,-1)
//Kreira duz izmedju tacaka A i B
struct Duz duz(struct Tacka A, struct Tacka B)
{
	struct Duz d;
	d.A = A;
	d.B = B;
	d.ugao = atan2(B.y-A.y, B.x-A.x);
	if (d.ugao < 0) d.ugao += 2*PI;
	return d;
}
//Vraca udaljenost izmedju tacke i duzi
float udaljenost_td(struct Tacka t, struct Duz d)
{
	float k = (d.A.y-d.B.y)/(d.A.x-d.B.x);
	if (fabs(d.A.x - d.B.x) < E) return fabs(t.x - d.A.x);
	return fabs(t.y -k * t.x - d.A.y + k * d.A.x) / sqrt(1 + k*k);
}
//Vraca da li je ugao a izmedju uglova b i c
int u_intervalu(float a, float b, float c)
{
	float m = fmin(b, c), M = fmax(b, c);
	if (M - m > PI) return a >= M || a <= m;
	else return a >= m && a <= M;
}
struct Tacka unesi_tacku()
{
	struct Tacka t;
	printf("koordinate x,y: ");
	scanf("%f,%f", &t.x, &t.y);
	return t;
}
#define _A tr.prvi
#define _B tr.drugi
#define _C tr.treci
int pripada(struct Tacka t, struct Trougao tr)
{
	struct Tacka a, b;
	struct Duz AB = duz(_A, _B), AC = duz(_A, _C), BC = duz(_B, _C),
	           BA = duz(_B, _A), AT = duz(_A, t), BT = duz(_B, t);
	int l = 0;
	//Ako je trougao tacka, mora biti identican sa tackom t
	if (udaljenost(_A, _B) < E && udaljenost(_A, _C) < E && udaljenost(_B, _C) < E)
		return udaljenost(t, _A) < E && udaljenost(t, _B) < E && udaljenost(t, _C) < E;
	if (udaljenost(_A, _B) < E) {
		a = _A;
		b = _C;
		l = 1;
	}
	if (udaljenost(_A, _C) < E) {
		a = _A;
		b = _B;
		l = 1;
	}
	if (udaljenost(_C, _B) < E) {
		a = _B;
		b = _C;
		l = 1;
	}
	//Ako su dva vrha identicna, provjerava da li tacka lezi na duzi odredjenoj njima i trecim vrhom
	if (l) {
		struct Duz v1 = duz(a, t), v2 = duz(a, b);
		return fabs(v1.ugao - v2.ugao) < E;
	}
	return udaljenost(t, _A) < E || udaljenost(t, _B) < E || udaljenost(t, _C) < E || (u_intervalu(AT.ugao, AB.ugao, AC.ugao) && u_intervalu(BT.ugao, BA.ugao, BC.ugao));
}
#undef _A
#undef _B
#undef _C
#define pp radijus
#define cx centar.x
#define cy centar.y
#define dlx donji_lijevi.x
#define dly donji_lijevi.y
#define _A tr1.prvi
#define _B tr1.drugi
#define _C tr1.treci
int obuhvata(void *oblik1, enum TipOblika to1, void *oblik2, enum TipOblika to2)
{
	struct Tacka t1, t2;
	struct Kruznica k1, k2;
	struct Pravougaonik p1, p2;
	struct Trougao tr1, tr2;
	float dx, dy, d;
	switch (to2) {
	case TACKA:
		t2 = *((struct Tacka*) oblik2);
	case KRUZNICA:
		k2 = *((struct Kruznica*) oblik2);
	case PRAVOUGAONIK:
		p2 = *((struct Pravougaonik*) oblik2);
	case TROUGAO:
		tr2 = *((struct Trougao*) oblik2);
	}
	switch(to1) {
	case TACKA:
		t1 = *((struct Tacka*) oblik1);
		switch(to2) {
		case TACKA:
			return fabs(t2.x - t1.x) < E && fabs(t2.y - t1.y) < E;
		case KRUZNICA:
			return k2.pp < E && fabs(k2.cx - t1.x) < E && fabs(k2.cy - t1.y) < E;
		case PRAVOUGAONIK:
			return p2.sirina < E && p2.visina < E && fabs(p2.dlx - t1.x) < E && fabs(p2.dly - t1.y) < E;
		case TROUGAO:
			return fabs(tr2.prvi.x - t1.x) < E && fabs(tr2.drugi.x - t1.x) < E && fabs(tr2.treci.x - t1.x) < E
			       && fabs(tr2.prvi.y - t1.y) < E && fabs(tr2.drugi.y - t1.y) < E && fabs(tr2.treci.y - t1.y) < E;
		}
	case KRUZNICA:
		k1 = *((struct Kruznica*) oblik1);
		switch (to2) {
		case TACKA:
			return udaljenost(t2, k1.centar) <= k1.pp;
		case KRUZNICA:
			dx = k2.cx - k1.cx;
			dy = k2.cy - k1.cy;
			d = udaljenost(k2.centar, k1.centar);
			return k1.pp >= k2.pp && (d < E || sqrt(pow(dx + dx/d * k2.pp, 2) + pow(dy + dy/d * k2.pp, 2)) <= k1.pp);
		case PRAVOUGAONIK:
			return udaljenost(p2.donji_lijevi, k1.centar) <= k1.pp && _udaljenost(p2.dlx + p2.sirina, p2.dly, k1.centar) <= k1.pp
			       && _udaljenost(p2.dlx + p2.sirina, p2.dly + p2.visina, k1.centar) <= k1.pp && _udaljenost(p2.dlx, p2.dly + p2.visina, k1.centar) <= k1.pp;
		case TROUGAO:
			return udaljenost(tr2.prvi, k1.centar) <= k1.pp && udaljenost(tr2.drugi, k1.centar) <= k1.pp && udaljenost(tr2.treci, k1.centar) <= k1.pp;
		}
	case PRAVOUGAONIK:
		p1 = *((struct Pravougaonik*) oblik1);
		switch (to2) {
		case TACKA:
			return t2.x >= p1.dlx && t2.x <= p1.dlx + p1.sirina && t2.y >= p1.dly && t2.y <= p1.dly + p1.visina;
		case KRUZNICA:
			return k2.cx - k2.pp >= p1.dlx && k2.cx + k2.pp <= p1.dlx + p1.sirina && k2.cy - k2.pp >= p1.dly && k2.cy + k2.pp <= p1.dly + p1.visina;
		case PRAVOUGAONIK:
			return p2.dlx >= p1.dlx && p2.dlx + p2.sirina <= p1.dlx + p1.sirina && p2.dly >= p1.dly && p2.dly + p2.visina <= p1.dly + p1.visina;
		case TROUGAO:
			return pripada_pravougaoniku(tr2.prvi, p1) && pripada_pravougaoniku(tr2.drugi, p1) && pripada_pravougaoniku(tr2.treci, p1);
		}
	case TROUGAO:
		tr1 = *((struct Trougao*) oblik1);
		switch (to2) {
		case TACKA:
			return pripada(t2, tr1);
		case KRUZNICA: {
			struct Duz AB = duz(_A, _B), AC = duz(_A, _C), BC = duz(_B, _C);
			return pripada(k2.centar, tr1) && udaljenost_td(k2.centar, AB) >= k2.pp && udaljenost_td(k2.centar, AC) >= k2.pp && udaljenost_td(k2.centar, BC) >= k2.pp;
		}
		case PRAVOUGAONIK: {
			struct Tacka B, C, D;
			B.x = C.x = p2.dlx + p2.sirina;
			D.x = p2.dlx;
			C.y = D.y = p2.dly + p2.visina;
			B.y = p2.dly;
			return pripada(p2.donji_lijevi, tr1) && pripada(B, tr1) && pripada(C, tr1) && pripada(D, tr1);
		}
		case TROUGAO:
			return pripada(tr2.prvi, tr1) && pripada(tr2.drugi, tr1) && pripada(tr2.treci, tr1);
		}
	}
	return 0;
}
#undef pp
#undef cx
#undef cy
#undef dlx
#undef dly

int main()
{
	int tip, n, i = 0, j;
	void *oblici[50];
	enum TipOblika tipovi[50];
	struct Tacka t;
	struct Kruznica k;
	struct Pravougaonik p;
	struct Trougao tr;
	printf("Unesite broj oblika: ");
	scanf("%d", &n);
	do {
		printf("Odaberite tip %d. oblika (1 - tacka, 2 - kruznica, 3 - pravougaonik, 4 - trougao): ", i+1);
		scanf("%d", &tip);
		if (tip == 1) {
			printf("Unesite tacku: ");
			t = unesi_tacku();
			oblici[i] = &t;
			tipovi[i] = TACKA;
		} else if(tip == 2) {
			printf("Unesite centar kruznice: ");
			k.centar = unesi_tacku();
			printf("Unesite poluprecnik kruznice: ");
			scanf("%f", &k.radijus);
			oblici[i] = &k;
			tipovi[i] = KRUZNICA;
		} else if (tip == 3) {
			printf("Unesite donji lijevi ugao: ");
			p.donji_lijevi = unesi_tacku();
			printf("Unesite sirinu: ");
			scanf("%f", &p.sirina);
			printf("Unesite visinu: ");
			scanf("%f", &p.visina);
			oblici[i] = &p;
			tipovi[i] = PRAVOUGAONIK;
		} else if (tip == 4) {
			printf("Unesite prvi vrh: ");
			tr.prvi = unesi_tacku();
			printf("Unesite drugi vrh: ");
			tr.drugi = unesi_tacku();
			printf("Unesite treci vrh: ");
			tr.treci = unesi_tacku();
			oblici[i] = &tr;
			tipovi[i] = TROUGAO;
		} else {
			printf("Nepoznat tip oblika %d!\n", tip);
			continue;
		}
		i++;
	} while (i < 50 && i < n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (i != j && obuhvata(oblici[i], tipovi[i], oblici[j], tipovi[j]))
				printf("\nOblik %d obuhvata oblik %d.", i+1, j+1);
	return 0;
}
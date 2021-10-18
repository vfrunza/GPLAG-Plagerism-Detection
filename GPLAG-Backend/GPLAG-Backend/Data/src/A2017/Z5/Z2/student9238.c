#include <stdio.h>
#include <math.h>
#define EQ(x, y) (fabs((x) - (y)) < 0.001)
struct Tacka {double x, y;};
struct Kruznica {struct Tacka centar; double radijus;};
struct Pravougaonik {struct Tacka DL; double sirina, visina;};
struct Trougao {struct Tacka A, B, C;};
enum TipOblika {TACKA, KRUZNICA, PRAVOUGAONIK, TROUGAO};
struct Pravougaonik NapraviPravougaonik (double x, double y, double w, double h) {struct Pravougaonik p; p.DL.x = x; p.DL.y = y; p.sirina = w; p.visina = h; return p;}
struct Pravougaonik tacka2pravougaonik (void *x) {struct Tacka *t = (struct Tacka *)x; return NapraviPravougaonik (t->x, t->y, 0, 0);}
struct Pravougaonik kruznica2pravougaonik (void *x) {struct Kruznica *k = (struct Kruznica *)x; return NapraviPravougaonik(k->centar.x - k->radijus, k->centar.y - k->radijus, 2 * k->radijus, 2 * k->radijus);}
struct Pravougaonik pravougaonik2pravougaonik (void *x) {struct Pravougaonik *p = (struct Pravougaonik *)x; return *p;}
struct Pravougaonik trougao2pravougaonik (void *x) 
{
	struct Trougao *t = (struct Trougao *)x;
	double xs[] = {t->A.x, t->B.x, t->C.x}, ys[] = {t->A.y, t->B.y, t->C.y};
	double minx = xs[0], miny = ys[0], maxx = minx, maxy = miny;
	int i;
	for (i = 0; i < 3; ++i)
		{
			if (minx > xs[i])
				minx = xs[i];
			if (miny > ys[i])
				miny = ys[i];
			if (maxx < xs[i])
				maxx = xs[i];
			if (maxy < ys[i])
				maxy = ys[i];
		}
	return NapraviPravougaonik(minx, miny, maxx - minx, maxy - miny);
}
int Obuhvata (struct Pravougaonik p1, struct Pravougaonik p2)
{
	return (p1.DL.x < p2.DL.x || EQ (p1.DL.x, p2.DL.x)) &&
		   (p1.DL.y < p2.DL.y || EQ (p1.DL.y, p2.DL.y)) &&
		   (p1.DL.x + p1.sirina > p2.DL.x + p2.sirina || EQ (p1.DL.x + p1.sirina, p2.DL.x + p2.sirina)) &&
		   (p1.DL.y + p1.visina > p2.DL.y + p2.visina || EQ (p1.DL.y + p1.visina, p2.DL.y + p2.visina));
}
int obuhvata(void* oblik1, enum TipOblika to1, void* oblik2, enum TipOblika to2)
{
	static struct Pravougaonik (*p[])(void *) = {tacka2pravougaonik, kruznica2pravougaonik, pravougaonik2pravougaonik, trougao2pravougaonik};
	struct Pravougaonik p1 = p[to1](oblik1), p2 = p[to2](oblik2), P;
	// P = p1;
	// printf ("\nP1: (%f, %f), %f, %f\n", P.DL.x, P.DL.y, P.sirina, P.visina);
	// P = p2;
	// printf ("P2: (%f, %f), %f, %f\n\n\n", P.DL.x, P.DL.y, P.sirina, P.visina);
	return Obuhvata(p1, p2);
}
int main() {
	printf ("EQ %d", EQ (1, 1.0));
	/* AT2: Da li oblici obuhvataju same sebe? */
struct Tacka t={1.9,4.3};
struct Kruznica k = {{2,4},1};
struct Pravougaonik P = kruznica2pravougaonik (&k);
//printf ("(%f, %f), %f, %f\n", P.DL.x, P.DL.y, P.sirina, P.visina);

struct Pravougaonik p={{0,1},4,4};
struct Trougao tr={{1,3},{3,4},{1,5}};

printf("%d ", obuhvata(&t,TACKA,&t,TACKA));
printf("%d ", obuhvata(&k,KRUZNICA,&k,KRUZNICA));
printf("%d ", obuhvata(&p,PRAVOUGAONIK,&p,PRAVOUGAONIK));
printf("%d ", obuhvata(&tr,TROUGAO,&tr,TROUGAO));

/* Za slucaj da funkcija uvijek vraca 1 */
printf("%d ", obuhvata(&t,TACKA,&k,KRUZNICA));
//1 1 1 1 0 
	return 0;
}

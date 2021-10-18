#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define E 0.001
#define PI 3.1415926535
enum TipOblika { TACKA, KRUZNICA, PRAVOUGAONIK, TROUGAO };
typedef enum TipOblika TipOblika;

struct Prava {
	/* Ax+By+C=0 */
	double A,B,C;
};

struct Tacka {
	double x,y;
};

struct Tacka unos_tacke()
{
	struct Tacka t;
	printf ("koordinate x,y: ");
	scanf ("%lf,%lf", &t.x, &t.y);
	return t;
}

struct Kruznica {
	struct Tacka centar;
	double radijus;
};

struct Kruznica unos_kruznice()
{
	struct Kruznica k;
	printf ("Unesite centar kruznice: ");
	k.centar = unos_tacke();
	printf ("Unesite poluprecnik kruznice: ");
	scanf("%lf", &k.radijus);
	return k;
}

struct Pravougaonik {
	struct Tacka A; /* Donja lijeva tacka */
	double sirina,visina;
};

struct Pravougaonik unos_pravougaonika()
{
	struct Pravougaonik p;
	printf("Unesite donji lijevi ugao: ");
	p.A=unos_tacke();
	printf("Unesite sirinu: ");
	scanf("%lf",&p.sirina);
	printf("Unesite visinu: ");
	scanf("%lf",&p.visina);

	return p;
}

struct Trougao {
	/* Vrhovi */
	struct Tacka A;
	struct Tacka B;
	struct Tacka C;
};

struct Trougao unos_trougla()
{
	struct Trougao tr;
	printf ("Unesite prvi vrh: ");
	tr.A = unos_tacke();
	printf ("Unesite drugi vrh: ");
	tr.B = unos_tacke();
	printf ("Unesite treci vrh: ");
	tr.C = unos_tacke();
	return tr;
}

double udaljenost(struct Tacka t1, struct Tacka t2)
{
	return sqrt( pow((t2.x-t1.x),2) + pow((t2.y-t1.y),2) );
}

double udaljenost_tacka_prava(struct Prava p, struct Tacka t)
{
	return (fabs(p.A*t.x+p.B*t.y+p.C))/sqrt(pow(p.A,2)+pow(p.B,2));
}

double povrsina_pravougaonika(struct Pravougaonik p)
{
	return p.visina*p.sirina;
}

double povrsina_kruga(struct Kruznica k)
{
	return pow(k.radijus,2)*PI;
}

double povrsina_trougla(struct Trougao t)
{
	double a=udaljenost(t.B,t.A);
	double b=udaljenost(t.B,t.C);
	double c=udaljenost(t.C,t.A);
	double s=(a+b+c)/2;
	/* Heronova formula */
	return sqrt(s*(s-a)*(s-b)*(s-c));
}

int ista_strana(struct Tacka T1,struct Tacka T2, struct Tacka T3, struct Tacka T4)
{
	double a = (T3.y - T1.y)*(T2.x - T1.x) - (T2.y - T1.y) * (T3.x - T1.x);
	double b = (T4.y - T1.y)*(T2.x - T1.x) - (T2.y - T1.y) * (T4.x - T1.x);

	return (a*b>=0);
}

void zamjena(struct Tacka *x, struct Tacka *y)
{
	double temp;

	temp=(*x).x;
	(*x).x=(*y).x;
	(*y).x=temp;

	temp=(*x).y;
	(*x).y=(*y).y;
	(*y).y=temp;
}

int obuhvata(void* oblik1, TipOblika to1, void* oblik2, TipOblika to2)
{
	double povrsina_o1;
	double povrsina_o2;

	if (to1 == KRUZNICA) {
		struct Kruznica* o1 = (struct Kruznica*) oblik1;
		povrsina_o1=povrsina_kruga(*o1);

		if (to2 == KRUZNICA) {
			struct Kruznica* o2 = (struct Kruznica*) oblik2;
			float d=udaljenost(o1->centar,o2->centar);

			if((d+o2->radijus)<=o1->radijus)
				return 1;

			return 0;
		}

		if (to2 == TACKA) {
			struct Tacka* o2 = (struct Tacka*) oblik2;
			if(udaljenost(*o2,o1->centar)>o1->radijus)
				return 0;

			return 1;
		}

		if (to2 == PRAVOUGAONIK) {
			struct Pravougaonik* o2 = (struct Pravougaonik*) oblik2;
			struct Tacka B;
			struct Tacka C;
			struct Tacka D;
			double d1,d2,d3,d4;

			/* Donja desna tacka */
			B.x=o2->A.x+o2->sirina;
			B.y=o2->A.y;
			/* Gornja desna tacka */
			C.x=B.x;
			C.y=B.y+o2->visina;
			/* Gornja lijeva tacka */
			D.x=o2->A.x;
			D.y=o2->A.y+o2->visina;

			povrsina_o2=povrsina_pravougaonika(*o2);

			if(povrsina_o2>povrsina_o1)
				return 0;

			else {
				/* Udaljenost rubnih tacaka pravougla do centra kruznice */
				d1=udaljenost(o2->A,o1->centar);
				d2=udaljenost(B,o1->centar);
				d3=udaljenost(C,o1->centar);
				d4=udaljenost(D,o1->centar);

				if(d1-o1->radijus<E && d2-o1->radijus<E && d3-o1->radijus<E && d4-o1->radijus<E)
					return 1;

				return 0;
			}
		}

		if (to2 == TROUGAO) {
			struct Trougao* o2 = (struct Trougao*) oblik2;
			double d1,d2,d3;
			povrsina_o2=povrsina_trougla(*o2);

			if(povrsina_o2>povrsina_o1)
				return 0;

			else {
				/* Udaljenost vrhova trougla do centra kruznice */
				d1=udaljenost(o2->A,o1->centar);
				d2=udaljenost(o2->B,o1->centar);
				d3=udaljenost(o2->C,o1->centar);

				if(d1-o1->radijus<E && d2-o1->radijus<E && d3-o1->radijus<E)
					return 1;

				return 0;
			}
		}
	}

	if (to1 == TACKA) {
		struct Tacka* o1 = (struct Tacka*) oblik1;

		if(to2==KRUZNICA) {
			struct Kruznica* o2 = (struct Kruznica*) oblik2;
			if(o2->radijus<E && o2->centar.x-o1->x<E && o2->centar.y-o1->y<E)
				return 1;

			return 0;
		}

		if(to2==TACKA) {
			struct Tacka* o2 = (struct Tacka*) oblik2;
			if((o1->x-o2->x)>=0 && (o1->x-o2->x)<E && (o1->y-o2->y)>=0 && (o1->y-o2->y)<E)
				return 1;

			return 0;
		}

		if(to2==PRAVOUGAONIK) {
			struct Pravougaonik* o2 = (struct Pravougaonik*) oblik2;
			if(o2->A.x-o1->x<E && o2->A.y-o1->y<E && o2->visina<E && o2->sirina<E)
				return 1;

			return 0;
		}

		if(to2==TROUGAO) {
			struct Trougao* o2 = (struct Trougao*) oblik2;
			if(povrsina_trougla(*o2)<E && o2->A.x-o1->x<E && o2->A.y-o1->y<E)
				return 1;

			return 0;
		}
	}

	if (to1 == PRAVOUGAONIK) {
		struct Pravougaonik* o1 = (struct Pravougaonik*) oblik1;
		struct Tacka B;
		struct Tacka C;
		struct Tacka D;

		B.x=o1->A.x+o1->sirina;
		B.y=o1->A.y;
		C.x=B.x;
		C.y=B.y+o1->visina;
		D.x=o1->A.x;
		D.y=o1->A.y+o1->visina;

		povrsina_o1=povrsina_pravougaonika(*o1);

		if(to2 == KRUZNICA) {
			struct Kruznica* o2 = (struct Kruznica*) oblik2;
			povrsina_o2=povrsina_kruga(*o2);

			if(povrsina_o2>povrsina_o1)
				return 0;

			else {
				if((o2->centar.x-o2->radijus)>=o1->A.x && (o2->centar.x+o2->radijus)<=B.x &&
				        (o2->centar.y+o2->radijus)<=D.y && (o2->centar.y-o2->radijus)>=o1->A.y)
					return 1;

				return 0;
			}
		}

		if(to2==TACKA) {
			struct Tacka* o2 = (struct Tacka*) oblik2;

			if(o2->x>=o1->A.x && o2->x<=B.x && o2->y>=B.y && o2->y<=C.y)
				return 1;

			return 0;
		}

		if(to2==PRAVOUGAONIK) {
			struct Pravougaonik* o2 = (struct Pravougaonik*) oblik2;
			struct Tacka B1;
			struct Tacka C1;
			struct Tacka D1;

			B1.x=o2->A.x+o2->sirina;
			B1.y=o2->A.y;
			C1.x=B1.x;
			C1.y=B1.y+o2->visina;
			D1.x=o2->A.x;
			D1.y=o2->A.y+o2->visina;
			povrsina_o2=povrsina_pravougaonika(*o2);

			if(povrsina_o2>povrsina_o1)
				return 0;

			else {
				if(o2->A.x<o1->A.x || o2->A.x>B.x || o2->A.y<o1->A.y || o2->A.y>C.y) return 0;
				if(B1.x>B.x || B1.y<B.y || B1.y>C.y || B1.x<o2->A.x) return 0;
				if(C1.x<o2->A.x || C1.x>B.x || C1.y<B.y || C1.y>C.y) return 0;
				if(D1.x<o2->A.x || D1.x>B.x || D1.y<B.y || D1.y>D.y) return 0;

				return 1;
			}
		}

		if(to2==TROUGAO) {
			struct Trougao* o2 = (struct Trougao*) oblik2;
			povrsina_o2=povrsina_trougla(*o2);

			if(povrsina_o2>povrsina_o1) return 0;

			else {
				if(o2->A.x<o1->A.x || o2->A.x>B.x || o2->A.y<o1->A.y || o2->A.y>C.y) return 0;
				if(o2->B.x<o1->A.x || o2->B.x>B.x || o2->B.y<o1->A.y || o2->B.y>C.y) return 0;
				if(o2->C.x<o1->A.x || o2->C.x>B.x || o2->C.y<o1->A.y || o2->C.y>C.y) return 0;

				return 1;
			}
		}
	}

	if (to1 == TROUGAO) {
		struct Trougao* o1= (struct Trougao*) oblik1;

		povrsina_o1=povrsina_trougla(*o1);

		if(to2==TACKA) {
			struct Tacka *o2 = (struct Tacka*) oblik2;

			if(ista_strana(o1->A,o1->B,o1->C,*o2) && ista_strana(o1->B,o1->C,o1->A,*o2)
			        && ista_strana(o1->A,o1->C,o1->B,*o2)) return 1;

			return 0;
		}

		if(to2==KRUZNICA) {
			struct Kruznica *o2=(struct Kruznica*) oblik2;
			struct Prava p1, p2, p3;
			double d1,d2,d3;
			/* p1 - lijevi krak trougla;
			p2 - desni krak trougla;
			p3 - osnovica */
			povrsina_o2=povrsina_kruga(*o2);

			/* Predstavimo krakove trougla kao prave sa njihovim jednacinama */
			p3.A=o1->A.y-o1->C.y;
			p3.B=o1->C.x-o1->A.x;
			p3.C=(o1->A.x-o1->C.x)*(o1->A.y) + (o1->A.x)*(o1->C.y-o1->A.y);

			p2.A=(o1->C.y-o1->B.y);
			p2.B=(o1->B.x-o1->C.x);
			p2.C=(o1->C.x-o1->B.x)*(o1->C.y)+ (o1->C.x)*(o1->B.y-o1->C.y);

			p1.A=o1->B.y-o1->A.y;
			p1.B=o1->A.x-o1->B.x;
			p1.C=(o1->B.x-o1->A.x)*(o1->B.y) + (o1->B.x)*(o1->A.y-o1->B.y);

			/* Najkraca udaljenost svake prave(kraka) trougla do centra kruznice */
			d1=udaljenost_tacka_prava(p3,o2->centar);
			d2=udaljenost_tacka_prava(p2,o2->centar);
			d3=udaljenost_tacka_prava(p1,o2->centar);

			if(povrsina_o2>povrsina_o1) return 0;

			else {
				/* Ako je udaljenost kraca od radijusa kruznice, slijedi da krak trougla (prava)
				sijece kruznicu ==> cijeli krug nije unutar trougla */
				if(d1<o2->radijus || d2<o2->radijus || d3<o2->radijus) return 0;

				return 1;
			}

		}

		if(to2==PRAVOUGAONIK) {
			struct Pravougaonik *o2 = (struct Pravougaonik*) oblik2;
			struct Tacka B;
			struct Tacka C;
			struct Tacka D;

			B.x=o2->A.x+o2->sirina;
			B.y=o2->A.y;
			C.x=B.x;
			C.y=B.y+o2->visina;
			D.x=o2->A.x;
			D.y=o2->A.y+o2->visina;

			povrsina_o2=povrsina_pravougaonika(*o2);

			if(povrsina_o2>povrsina_o1) return 0;

			else {

				/* Da li su svi vrhovi pravouoganika unutar trougla */
				if(!(ista_strana(o1->A,o1->B,o1->C,o2->A) && ista_strana(o1->B,o1->C,o1->A,o2->A)
				        && ista_strana(o1->A,o1->C,o1->B,o2->A))) return 0;

				if(!(ista_strana(o1->A,o1->B,o1->C,B) && ista_strana(o1->B,o1->C,o1->A,B)
				        && ista_strana(o1->A,o1->C,o1->B,B))) return 0;

				if(!(ista_strana(o1->A,o1->B,o1->C,C) && ista_strana(o1->B,o1->C,o1->A,C)
				        && ista_strana(o1->A,o1->C,o1->B,C))) return 0;

				if(!(ista_strana(o1->A,o1->B,o1->C,D) && ista_strana(o1->B,o1->C,o1->A,D)
				        && ista_strana(o1->A,o1->C,o1->B,D))) return 0;


				return 1;
			}
		}

		if(to2==TROUGAO) {
			struct Trougao* o2 = (struct Trougao*) oblik2;
			povrsina_o2=povrsina_trougla(*o2);

			if(povrsina_o2>povrsina_o1) return 0;

			else {
				/* Da li su svi vrhovu drugog trougla unutar prvog */
				if(!(ista_strana(o1->A,o1->B,o1->C,o2->A) && ista_strana(o1->B,o1->C,o1->A,o2->A)
				        && ista_strana(o1->A,o1->C,o1->B,o2->A))) return 0;

				if(!(ista_strana(o1->A,o1->B,o1->C,o2->B) && ista_strana(o1->B,o1->C,o1->A,o2->B)
				        && ista_strana(o1->A,o1->C,o1->B,o2->B))) return 0;

				if(!(ista_strana(o1->A,o1->B,o1->C,o2->C) && ista_strana(o1->B,o1->C,o1->A,o2->C)
				        && ista_strana(o1->A,o1->C,o1->B,o2->C))) return 0;

				return 1;
			}
		}
	}

	return 0;
}

int main()
{
	void* oblik[50];
	TipOblika oblik_ime[50];
	int n,i=0,j;
	int d;
	struct Tacka t[50];
	int t_int=0;
	struct Kruznica k[50];
	int k_int=0;
	struct Pravougaonik p[50];
	int p_int=0;
	struct Trougao tr[50];
	int tr_int=0;

	do {
		printf("Unesite broj oblika: ");
		scanf("%d",&n);

		if(n>50)
			printf("Maksimalan unos je 50!\n");

	} while(n>50);

	do {

		printf("Odaberite tip %d. oblika (1 - tacka, 2 - kruznica, 3 - pravougaonik, 4 - trougao): ",i+1);
		scanf("%d",&d);

		if(d>4) {
			printf("Nepoznat tip oblika %d!\n",d);
			i--;
		}

		else if(d==1) {
			printf("Unesite tacku: ");
			t[t_int]=unos_tacke();
			oblik[i]=&t[t_int];
			t_int++;
			oblik_ime[i]=TACKA;
		}

		else if(d==2) {
			k[k_int]=unos_kruznice();
			oblik[i]=&k[k_int];
			k_int++;
			oblik_ime[i]=KRUZNICA;
		}

		else if(d==3) {
			p[p_int]=unos_pravougaonika();
			oblik[i]=&p[p_int];
			p_int++;
			oblik_ime[i]=PRAVOUGAONIK;
		}

		else if(d==4) {
			tr[tr_int]=unos_trougla();
			oblik[i]=&tr[tr_int];
			tr_int++;
			oblik_ime[i]=TROUGAO;
		}

		i++;

	} while(i<n);

	printf("\n");
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			if(j!=i && obuhvata(oblik[i],oblik_ime[i],oblik[j],oblik_ime[j]))
				printf("Oblik %d obuhvata oblik %d.\n",i+1,j+1);
		}
	}

	return 0;
}

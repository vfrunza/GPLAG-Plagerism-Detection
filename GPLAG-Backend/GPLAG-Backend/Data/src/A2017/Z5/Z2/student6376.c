#include <stdio.h>
#include <math.h>

#define EPSILON 0.001
#define PI 3.1415296

struct Tacka {
	double x,y;
};
struct Kruznica {
	struct Tacka centar;
	double radijus;
};
struct Pravougaonik {
	struct Tacka dole_lijevo;
	double sirina, visina;
};
struct PPFixed {
	struct Tacka dl, dd, gl, gd;
};

struct Trougao {
	struct Tacka A, B, C;
};

enum TipOblika { TACKA, KRUZNICA, PRAVOUGAONIK, TROUGAO };

int jednako(double x, double y) { return fabs(x-y)<EPSILON; }
int leq(double x, double y) { return x-y<EPSILON; }

struct PPFixed izracunaj_pravougaonik(struct Pravougaonik p) {
	struct PPFixed rezultat;
	rezultat.dl = rezultat.dd = rezultat.gl = rezultat.gd = p.dole_lijevo;
	rezultat.dd.x += p.sirina;
	rezultat.gd.x += p.sirina;
	rezultat.gl.y += p.visina;
	rezultat.gd.y += p.visina;
	return rezultat;
}

double udaljenost(struct Tacka a, struct Tacka b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
double sign (struct Tacka p1, struct Tacka p2, struct Tacka p3) {
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

double udaljenost_od_prave(struct Tacka A, struct Tacka B, struct Tacka C) {
	/* Jednacina prave kroz tacke B i C u obliku ax+by+c=0, b=1 */
	double a;
	if (jednako(C.x,B.x)) {
		return fabs(A.x-B.x);
	} else
		a = (C.y-B.y)/(C.x-B.x);
	double c = a*B.x -  B.y;
	
	//printf("y - %g = %g * (x - %g)\n", B.y, a, B.x);
	a = -a;
	//printf("%gx + y + %g\n", a, c);
	
	/* Udaljenost tacke A od ove prave je abs(ax_0+by_0+c)/sqrt(a^2+b^2) */
	double d = fabs(a*A.x+A.y+c)/sqrt(a*a+1);
	return d;
}


/* Funkcije za ispis */
void ispisi_tacku(struct Tacka t) {
	printf("(%g,%g)", t.x, t.y);
}
void ispisi_ppfixed(struct PPFixed p) {
	printf("DL: ");
	ispisi_tacku(p.dl);
	printf(" DD: ");
	ispisi_tacku(p.dd);
	printf(" GL: ");
	ispisi_tacku(p.gl);
	printf(" GD: ");
	ispisi_tacku(p.gd);
	printf("\n");
}

int obuhvata(void* oblik1, enum TipOblika to1, void* oblik2, enum TipOblika to2) {
	struct Tacka* t1, *t2; 
	struct Kruznica* k1, *k2; 
	struct PPFixed p1, p2; 
	struct Trougao* tr1, *tr2;
	
	switch(to1) {
		case TACKA: t1=(struct Tacka*)oblik1; break;
		case KRUZNICA: k1=(struct Kruznica*)oblik1; break;
		case PRAVOUGAONIK: p1=izracunaj_pravougaonik(*(struct Pravougaonik*)oblik1); break;
		case TROUGAO: tr1=(struct Trougao*)oblik1; break;
	}
	switch(to2) {
		case TACKA: t2=(struct Tacka*)oblik2; break;
		case KRUZNICA: k2=(struct Kruznica*)oblik2; break;
		case PRAVOUGAONIK: p2=izracunaj_pravougaonik(*(struct Pravougaonik*)oblik2); break;
		case TROUGAO: tr2=(struct Trougao*)oblik2; break;
	}
	
	//ispisi_ppfixed(p1);
	
	if (to1==TACKA && to2==TACKA) {
		if (jednako(t1->x,t2->x) && jednako(t1->y,t2->y)) return 1;
		return 0;
	}
	if (to1==TACKA && to2==KRUZNICA)
		return (obuhvata(oblik1, TACKA, &k2->centar, TACKA) && jednako(k2->radijus, 0));
	if (to1==TACKA && to2==PRAVOUGAONIK)
		return (obuhvata(oblik1, TACKA, &p2.dl, TACKA) && obuhvata(oblik1, TACKA, &p2.dd, TACKA) && obuhvata(oblik1, TACKA, &p2.gl, TACKA) && obuhvata(oblik1, TACKA, &p2.gd, TACKA));
	if (to1==TACKA && to2==TROUGAO)
		return (obuhvata(oblik1, TACKA, &tr2->A, TACKA) && obuhvata(oblik1, TACKA, &tr2->B, TACKA) && obuhvata(oblik1, TACKA, &tr2->C, TACKA));
	
	if (to1==KRUZNICA && to2==TACKA)
		return leq(udaljenost(k1->centar, *t2), k1->radijus);
	if (to1==KRUZNICA && to2==PRAVOUGAONIK)
		return obuhvata(oblik1, KRUZNICA, &p2.dl, TACKA) && obuhvata(oblik1, KRUZNICA, &p2.dd, TACKA) && obuhvata(oblik1, KRUZNICA, &p2.gl, TACKA) && obuhvata(oblik1, KRUZNICA, &p2.gd, TACKA);
	if (to1==KRUZNICA && to2==TROUGAO)
		return obuhvata(oblik1, KRUZNICA, &tr2->A, TACKA) && obuhvata(oblik1, KRUZNICA, &tr2->B, TACKA) && obuhvata(oblik1, KRUZNICA, &tr2->C, TACKA);
	if (to1==KRUZNICA && to2==KRUZNICA) {
		double d = udaljenost(k1->centar, k2->centar);
		return leq(d, k1->radijus - k2->radijus);
	}
	
	if(to1==PRAVOUGAONIK && to2==TACKA) {
		return (leq(p1.dl.x, t2->x) && leq(t2->x, p1.dd.x) && leq(p1.dl.y, t2->y) && leq(t2->y, p1.gl.y));
	}
	if(to1==PRAVOUGAONIK && to2==KRUZNICA) {
		double d1 = k2->centar.x - p1.dl.x;
		double d2 = p1.dd.x - k2->centar.x;
		double d3 = k2->centar.y - p1.dl.y;
		double d4 = p1.gl.y - k2->centar.y;
		return (leq(k2->radijus,d1) && leq(k2->radijus,d2) && leq(k2->radijus,d3) && leq(k2->radijus,d4));
	}
	if(to1==PRAVOUGAONIK && to2==PRAVOUGAONIK)
		return obuhvata(oblik1, PRAVOUGAONIK, &p2.dl, TACKA) && obuhvata(oblik1, PRAVOUGAONIK, &p2.dd, TACKA) && obuhvata(oblik1, PRAVOUGAONIK, &p2.gl, TACKA) && obuhvata(oblik1, PRAVOUGAONIK, &p2.gd, TACKA);
	if(to1==PRAVOUGAONIK && to2==TROUGAO)
		return obuhvata(oblik1, PRAVOUGAONIK, &tr2->A, TACKA) && obuhvata(oblik1, PRAVOUGAONIK, &tr2->B, TACKA) && obuhvata(oblik1, PRAVOUGAONIK, &tr2->C, TACKA);
	
	if(to1==TROUGAO && to2==TACKA) {
		/* Moramo odvojeno provjeriti da li tacka lezi na stranicama trougla */
		double d1 = udaljenost_od_prave(*t2, tr1->A, tr1->B);
		double d2 = udaljenost_od_prave(*t2, tr1->B, tr1->C);
		double d3 = udaljenost_od_prave(*t2, tr1->C, tr1->A);
		//printf("(%g,%g): %g %g %g\n", t2->x, t2->y, d1, d2, d3);
		if (jednako(d1, 0) || jednako(d2, 0) || jednako(d3, 0))
			return 1;
		int s1 = leq(sign(*t2, tr1->A, tr1->B), 0);
		int s2 = leq(sign(*t2, tr1->B, tr1->C), 0);
		int s3 = leq(sign(*t2, tr1->C, tr1->A), 0);
		return ((s1==s2) && (s2==s3));
	}
	if(to1==TROUGAO && to2==KRUZNICA) {
		double d1 = udaljenost_od_prave(k2->centar, tr1->A, tr1->B);
		double d2 = udaljenost_od_prave(k2->centar, tr1->B, tr1->C);
		double d3 = udaljenost_od_prave(k2->centar, tr1->C, tr1->A);
		return (obuhvata(oblik1, TROUGAO, &k2->centar, TACKA) && leq(k2->radijus,d1) && leq(k2->radijus,d2) && leq(k2->radijus,d3));
	}
	if(to1==TROUGAO && to2==PRAVOUGAONIK)
		return obuhvata(oblik1, TROUGAO, &p2.dl, TACKA) && obuhvata(oblik1, TROUGAO, &p2.dd, TACKA) && obuhvata(oblik1, TROUGAO, &p2.gl, TACKA) && obuhvata(oblik1, TROUGAO, &p2.gd, TACKA);
	if(to1==TROUGAO && to2==TROUGAO)
		return obuhvata(oblik1, TROUGAO, &tr2->A, TACKA) && obuhvata(oblik1, TROUGAO, &tr2->B, TACKA) && obuhvata(oblik1, TROUGAO, &tr2->C, TACKA);
		
	// Nepoznat tip?
	return 0;
}

struct Tacka unos_tacke() {
	struct Tacka t;
	printf("koordinate x,y: ");
	scanf("%lf,%lf", &t.x, &t.y);
	return t;
}

int main() {
	void* oblici[50];
	struct Kruznica kruznice[50];
	struct Tacka tacke[50];
	struct Pravougaonik prnici[50];
	struct Trougao trouglovi[50];
	enum TipOblika tipovi[50];
	int i, j, unos, broblika=0, brkruznica=0, brtacaka=0, brprnika=0, brtrouglova=0;
	
struct Kruznica k = {{2,4},1};
struct Trougao tr={{1,3},{2,5},{3,3}};
printf("%d ", obuhvata(&tr,TROUGAO,&k,KRUZNICA));
k.radijus = 0.5;
printf("%d ", obuhvata(&tr,TROUGAO,&k,KRUZNICA));
k.radijus = 0.45;
printf("%d ", obuhvata(&tr,TROUGAO,&k,KRUZNICA));
k.radijus = 0.44;
printf("%d ", obuhvata(&tr,TROUGAO,&k,KRUZNICA));


   return 0;

	/*
	struct Tacka t={2.9,3.3};
	struct Kruznica k = {{3,3},1};
	struct Pravougaonik p={{5,0},4,4,PI/2};
	struct Trougao tr={{2,2},{4,3},{2,4}};
	
	ispisi_ppfixed(izracunaj_pravougaonik(p));
	return 0;
	
	p.rotacija += PI/2;
	ispisi_ppfixed(izracunaj_pravougaonik(p));
	p.rotacija += PI/2;
	ispisi_ppfixed(izracunaj_pravougaonik(p));
	p.rotacija += PI/2;
	ispisi_ppfixed(izracunaj_pravougaonik(p));
	return 0;
	
	printf("%d ", obuhvata(&t,TACKA,&t,TACKA));
	printf("%d ", obuhvata(&t,TACKA,&t,TACKA));
	return 0;  
	*/
	
	printf("Unesite broj oblika: ");
	scanf("%d", &broblika);
	j=0;
	for (i=0; i<broblika; i++) {
		printf("Odaberite tip %d. oblika (1 - tacka, 2 - kruznica, 3 - pravougaonik, 4 - trougao): ", i+1);
		scanf("%d", &unos);
		switch(unos) {
			case 1:
				printf("Unesite tacku: ");
				tacke[brtacaka]=unos_tacke();
				tipovi[j] = TACKA;
				oblici[j++] = &tacke[brtacaka++];
				break;
				
			case 2:
				printf("Unesite centar kruznice: ");
				kruznice[brkruznica].centar = unos_tacke();
				printf("Unesite poluprecnik kruznice: ");
				scanf("%lf", &kruznice[brkruznica].radijus);
				tipovi[j] = KRUZNICA;
				oblici[j++] = &kruznice[brkruznica++];
				break;
				
			case 3:
				printf("Unesite donji lijevi ugao: ");
				prnici[brprnika].dole_lijevo = unos_tacke();
				printf("Unesite sirinu: ");
				scanf("%lf", &prnici[brprnika].sirina);
				printf("Unesite visinu: ");
				scanf("%lf", &prnici[brprnika].visina);
				tipovi[j] = PRAVOUGAONIK;
				oblici[j++] = &prnici[brprnika++];
				break;
				
			case 4:
				printf("Unesite prvi vrh: ");
				trouglovi[brtrouglova].A = unos_tacke();
				printf("Unesite drugi vrh: ");
				trouglovi[brtrouglova].B = unos_tacke();
				printf("Unesite treci vrh: ");
				trouglovi[brtrouglova].C = unos_tacke();
				tipovi[j] = TROUGAO;
				oblici[j++] = &trouglovi[brtrouglova++];
				break;
			
			default:
				printf("Nepoznat tip oblika %d!\n", unos);
				i--;
		}
	}
	printf("\n");
	
	for (i=0; i<broblika; i++)
		for (j=0; j<broblika; j++)
			if (i!=j && obuhvata(oblici[i],tipovi[i],oblici[j],tipovi[j]))
				printf("Oblik %d obuhvata oblik %d.\n", i+1, j+1);
	
	return 0;
}

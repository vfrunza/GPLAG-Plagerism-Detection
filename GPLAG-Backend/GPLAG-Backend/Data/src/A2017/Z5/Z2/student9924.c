#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define EPS 0.001

struct Tacka {
	float x, y;	
};
struct Trougao {
	struct Tacka vrh1, vrh2, vrh3;
};
struct Kruznica {
	struct Tacka centar;
	float radijus;
};
struct Pravougaonik {
	struct Tacka dole_lijevo;
	float sirina, visina;
};
typedef enum TipOblika {TACKA, KRUZNICA, PRAVOUGAONIK, TROUGAO} TipOblika;

int tut(struct Tacka t1, struct Tacka t2) {
	return t1.x == t2.x && t1.y == t2.y;
} //tacka u tacci
float skalarno(struct Tacka a, struct Tacka b, struct Tacka c, struct Tacka d) {
	return ((b.x-a.x)*(d.x-c.x) + (b.y-a.y)*(d.y-c.y));
} //skalarni proizvod vektora(za trougao)
int tutr(struct Tacka t, struct Trougao tr) {
	float u, v, sk1, sk2, sk3, sk4, sk5;
	if (tut(tr.vrh1,tr.vrh2) && tut(tr.vrh2,tr.vrh3)) return tut(tr.vrh1,t);
	sk1 = skalarno(tr.vrh1,tr.vrh3,tr.vrh1,tr.vrh3);
	sk2 = skalarno(tr.vrh1,tr.vrh3,tr.vrh1,tr.vrh2);
	sk3 = skalarno(tr.vrh1,tr.vrh3,tr.vrh1,t);
	sk4 = skalarno(tr.vrh1,tr.vrh2,tr.vrh1,tr.vrh2);
	sk5 = skalarno(tr.vrh1,tr.vrh2,tr.vrh1,t);
	u = (sk4*sk3 - sk2*sk5)/(sk1*sk4 - sk2*sk2);
	v = (sk1*sk5 - sk2*sk3)/(sk1*sk4 - sk2*sk2);
	return (u >= 0 && v >= 0 && u+v <= 1);
} // tacka u trouglu
int tuk(struct Tacka p, struct Kruznica k) {
	float d = (p.x-k.centar.x)*(p.x-k.centar.x) + (p.y-k.centar.y)*(p.y-k.centar.y);
	return (d <= k.radijus*k.radijus);
} // tacka u kruznici
int kutr(struct Kruznica k, struct Trougao tr) {
	float rcos = k.radijus * (float)cos(45);
	int a, b, c, d, e, f, g, h, i, j, l, m;
	struct Tacka centar;
	centar.x = k.centar.x; centar.y = k.centar.y+k.radijus;
	a = tutr(centar,tr);
	centar.y = k.centar.y-k.radijus;
	b = tutr(centar,tr);
	centar.x = k.centar.x-k.radijus; centar.y = k.centar.y;
	c = tutr(centar,tr);
	centar.x = k.centar.x+k.radijus;
	d = tutr(centar,tr);
	centar.x = k.centar.x+rcos; centar.y = k.centar.y+rcos;
	e = tutr(centar,tr);
	centar.y = k.centar.y-rcos;
	f = tutr(centar,tr);
	centar.x = k.centar.x-rcos;
	g = tutr(centar,tr);
	centar.y = k.centar.y+rcos;
	h = tutr(centar,tr);
	centar.x = k.centar.x-k.radijus*cos(15.25); centar.y = k.centar.y+k.radijus*sin(15.25);
	i = tutr(centar,tr);
	centar.x = k.centar.x+k.radijus*cos(15.25);
	j = tutr(centar,tr);
	centar.y = k.centar.y-k.radijus*sin(15.25);
	l = tutr(centar,tr);
	centar.x = k.centar.x-k.radijus*cos(15.25);
	m = tutr(centar,tr);
	return (tutr(k.centar,tr) && a && b && c && d && e && f && g && h && i && j && l && m);
} // kruznica u trouglu
int tupr(struct Tacka t, struct Pravougaonik p) {
	return t.x >= p.dole_lijevo.x && t.x <= p.dole_lijevo.x+p.sirina && t.y >= p.dole_lijevo.y && t.y <= p.dole_lijevo.y+p.visina;
} // tacka u pravougaoniku
int prukr(struct Pravougaonik pr, struct Kruznica kr) {
	struct Tacka gore_lijevo = {pr.dole_lijevo.x,pr.dole_lijevo.y+pr.visina};
	struct Tacka dole_desno = {pr.dole_lijevo.x+pr.sirina, pr.dole_lijevo.y};
	struct Tacka gore_desno = {dole_desno.x,gore_lijevo.y};
	return tuk(pr.dole_lijevo, kr) && tuk(dole_desno, kr) && tuk(gore_lijevo, kr) && tuk(gore_desno, kr);
} // pravougaonik u kruznici
int prupr(struct Pravougaonik pr1, struct Pravougaonik pr2) {
	return tupr(pr1.dole_lijevo,pr2) && pr1.sirina-pr1.dole_lijevo.x <= pr2.sirina-pr1.dole_lijevo.x && pr1.visina-pr1.dole_lijevo.y <= pr2.visina - pr1.dole_lijevo.y;
} // pravougaonik u pravougaoniku
int krupr(struct Kruznica k, struct Pravougaonik pr) {
	float rcos = k.radijus * (float)cos(45);
	int a, b, c, d, e, f, g, h, i, j, l, m;
	struct Tacka centar;
	centar.x = k.centar.x; centar.y = k.centar.y+k.radijus;
	a = tupr(centar,pr);
	centar.y = k.centar.y-k.radijus;
	b = tupr(centar,pr);
	centar.x = k.centar.x-k.radijus; centar.y = k.centar.y;
	c = tupr(centar,pr);
	centar.x = k.centar.x+k.radijus;
	d = tupr(centar,pr);
	centar.x = k.centar.x+rcos; centar.y = k.centar.y+rcos;
	e = tupr(centar,pr);
	centar.y = k.centar.y-rcos;
	f = tupr(centar,pr);
	centar.x = k.centar.x-rcos;
	g = tupr(centar,pr);
	centar.y = k.centar.y+rcos;
	h = tupr(centar,pr);
	centar.x = k.centar.x-k.radijus*cos(15.25); centar.y = k.centar.y+k.radijus*sin(15.25);
	i = tupr(centar,pr);
	centar.x = k.centar.x+k.radijus*cos(15.25);
	j = tupr(centar,pr);
	centar.y = k.centar.y-k.radijus*sin(15.25);
	l = tupr(centar,pr);
	centar.x = k.centar.x-k.radijus*cos(15.25);
	m = tupr(centar,pr);
	return (tupr(k.centar,pr) && a && b && c && d && e && f && g && h && i && j && l && m);
} // kruznica u pravougaoniku

int obuhvata(void* oblik1, TipOblika to1, void* oblik2, enum TipOblika to2) {
	struct Trougao *tr1 = NULL,*tr2 = NULL;
	struct Kruznica *kr1 = NULL,*kr2 = NULL;
	struct Pravougaonik *pr1 = NULL,*pr2 = NULL;
	struct Tacka *t1 = NULL, *t2 = NULL;
	switch(to1) {
		case TROUGAO:
			tr1 = (struct Trougao*) oblik1;
			switch(to2) {
				case TROUGAO:
					tr2 = (struct Trougao*) oblik2;
					return tutr(tr2->vrh1,*tr1) && tutr(tr2->vrh2,*tr1) && tutr(tr2->vrh3,*tr1);
				case KRUZNICA:
					kr2= (struct Kruznica*) oblik2;
					return kutr(*kr2,*tr1);
				case PRAVOUGAONIK:
					pr2 = (struct Pravougaonik*) oblik2;
				case TACKA:
					t2 = (struct Tacka*) oblik2;
					return tutr(*t2,*tr1);
			}
		case KRUZNICA:
			kr1 = (struct Kruznica*) oblik1;
			switch(to2) {
				case TROUGAO:
					tr2 = (struct Trougao*) oblik2;
					return tuk(tr2->vrh1,*kr1) && tuk(tr2->vrh2,*kr1) && tuk(tr2->vrh3,*kr1);
				case KRUZNICA:
					kr2 = (struct Kruznica*) oblik2;
					return tuk(kr2->centar,*kr1) && (kr2->centar.x-kr1->centar.x)*(kr2->centar.x-kr1->centar.x)+(kr2->centar.y-kr1->centar.y)*(kr2->centar.y-kr1->centar.y)+kr2->radijus*kr2->radijus <= kr1->radijus*kr1->radijus;
				case PRAVOUGAONIK:
					pr2 = (struct Pravougaonik*) oblik2;
					return prukr(*pr2,*kr1);
				case TACKA:
					t2 = (struct Tacka*) oblik2;
					return tuk(*t2,*kr1);
			}
		case PRAVOUGAONIK:
			pr1 = (struct Pravougaonik*) oblik1;
			switch(to2) {
				case TROUGAO: 
					tr2 = (struct Trougao*) oblik2;
					return tupr(tr2->vrh1,*pr1) && tupr(tr2->vrh2,*pr1) && tupr(tr2->vrh3,*pr1); 
				case KRUZNICA:
					kr2 = (struct Kruznica*) oblik2;
					return krupr(*kr2,*pr1);
				case PRAVOUGAONIK:
					pr2 = (struct Pravougaonik*) oblik2;
					return prupr(*pr2,*pr1);
				case TACKA:
					t2 = (struct Tacka*) oblik2;
					return tupr(*t2,*pr1);
			}
		case TACKA:
			t1 = (struct Tacka*) oblik1;
			switch(to2) {
				case TROUGAO: 
					tr2 = (struct Trougao*) oblik2;
					return tut(*t1,tr2->vrh1) && tut(*t1,tr2->vrh2) && tut(*t1,tr2->vrh3);
				case KRUZNICA:
					kr2 = (struct Kruznica*) oblik2;
					return tut(*t1,kr2->centar) && kr2->radijus <= (float)EPS;
				case PRAVOUGAONIK:
					pr2 = (struct Pravougaonik*) oblik2;
					return tut(*t1,pr2->dole_lijevo) && pr2->visina <= (float)EPS && pr2->sirina <=(float)EPS;
				case TACKA:
					t2 = (struct Tacka*) oblik2;
					return tut(*t1,*t2);
			}
	}
	return 0;
}

void unesiTacku( struct Tacka *t) {
	printf("Unesite tacku: ");
	printf("koordinate x,y: ");
	scanf("%f,%f", &t->x, &t->y);
}
void unesiKruznicu(struct Kruznica *k) {
	printf("Unesite centar kruznice: ");
	printf("koordinate x,y: ");
	scanf("%f,%f", &k->centar.x, &k->centar.y);
	printf("Unesite poluprecnik kruznice: ");
	scanf("%f", &k->radijus);
}
void unesiPravougaonik(struct Pravougaonik *p) {
	printf("Unesite donji lijevi ugao: ");
	printf("koordinate x,y: ");
	scanf("%f,%f", &p->dole_lijevo.x, &p->dole_lijevo.y);
	printf("Unesite sirinu: ");
	scanf("%f", &p->sirina);
	printf("Unesite visinu: ");
	scanf("%f", &p->visina);
}
void unesiTrougao(struct Trougao *t) {
	printf("Unesite prvi vrh: ");
	printf("koordinate x,y: ");
	scanf("%f,%f", &t->vrh1.x, &t->vrh1.y);
	printf("Unesite drugi vrh: ");
	printf("koordinate x,y: ");
	scanf("%f,%f", &t->vrh2.x, &t->vrh2.y);
	printf("Unesite treci vrh: ");
	printf("koordinate x,y: ");
	scanf("%f,%f", &t->vrh3.x, &t->vrh3.y);
}

int main() {
	void* oblici[50] = {NULL};
	struct Tacka tacke[50];
	struct Kruznica kruznice[50];
	struct Pravougaonik pravougaonici[50];
	struct Trougao trouglovi[50];
	int vel, i, j;
	int a = 0 ,b = 0, c = 0, d = 0;
	TipOblika tip[50];
	do {
		printf("Unesite broj oblika: ");
		scanf("%d", &vel);
	} while (vel < 0 || vel > 50);
	for(i = 0; i < vel; i++) {
		do {
			printf("Odaberite tip %d. oblika (1 - tacka, 2 - kruznica, 3 - pravougaonik, 4 - trougao): ", i+1);
			scanf("%d", &tip[i]);
			if (tip[i] < TACKA+1 || tip[i] > TROUGAO+1) printf("Nepoznat tip oblika %d!\n", tip[i]);
		}while (tip[i] < TACKA+1 || tip[i] > TROUGAO+1);
		if(tip[i] == TACKA+1) {
			unesiTacku(&(tacke[a]));
			oblici[i] = &(tacke[a]);
			a++;
		}
		else if(tip[i] == KRUZNICA+1) {
			unesiKruznicu(&(kruznice[b]));
			oblici[i] = &(kruznice[b]);
			b++;
		}
		else if(tip[i] == PRAVOUGAONIK+1) {
			unesiPravougaonik(&(pravougaonici[c]));
			oblici[i] = &pravougaonici[c];
			c++;
		}
		else {
			unesiTrougao(&(trouglovi[d]));
			oblici[i] = &trouglovi[d];
			d++;
		}
	}
	for (i = 0; i < vel; i++) {
		for (j = 0; j < vel; j++) {
			if (i != j && obuhvata(oblici[i], tip[i]-1, oblici[j], tip[j]-1) == 1)
				printf("\nOblik %d obuhvata oblik %d.", i+1, j+1);
		}
	}
	
	return 0;
}


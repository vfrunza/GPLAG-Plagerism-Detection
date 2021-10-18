#include <stdio.h>
#include <math.h>

#define eps 0.001

/* operator -> ima istu funkciju kao dereferenciranje tj * na pok pa onda pristup sa operatorom ., dakle -> mijenja *. */
/*PROVJERITI NAKON AT OVO <= i eps*/

struct Tacka {
	float x, y;
};

struct Kruznica {
	struct Tacka centar;
	float poluprecnik;
};

struct Pravougaonik {
	struct Tacka dole_lijevo;
	float sirina, visina;
};

struct Trougao {
	struct Tacka vrh1, vrh2, vrh3;
};

enum TipOblika { TACKA, KRUZNICA, PRAVOUGAONIK, TROUGAO };

int tacka_u_trouglu(struct Trougao tr, struct Tacka tk)
{
	/*koristi se metod zasnovan na baricentričnim koordinatama*/
	double a, b, A;

	a = tr.vrh1.y * tr.vrh3.x - tr.vrh1.x * tr.vrh3.y + (tr.vrh3.y - tr.vrh1.y) * tk.x + (tr.vrh1.x - tr.vrh3.x) * tk.y;
	b = tr.vrh1.x * tr.vrh2.y - tr.vrh1.y * tr.vrh2.x + (tr.vrh1.y - tr.vrh2.y) * tk.x + (tr.vrh2.x - tr.vrh1.x) * tk.y;


	if ((a < 0) != (b < 0))         /*ili a < 0 && b >= 0 || a >= 0 && b < */
		return 0;

	A = -1 * tr.vrh2.y * tr.vrh3.x + tr.vrh1.y * (tr.vrh3.x - tr.vrh2.x) + tr.vrh1.x * (tr.vrh2.y - tr.vrh3.y) + tr.vrh2.x * tr.vrh3.y;

	if (A < 0.0) {
		a = -a;
		b = -b;
		A = - A;
	}

	return (a > 0 || fabs(a - eps) > 0)  && (b > 0 || fabs(b - eps) > 0) && (a + b < A || fabs(a + b - A) < eps);
}

int obuhvata(void *oblik1, enum TipOblika to1, void *oblik2, enum TipOblika to2)
{
	float d1, d2, d3, d4;
	struct Tacka *tk1, *tk2;
	struct Kruznica *k1, *k2;
	struct Pravougaonik *p1, *p2;
	struct Trougao *tr1, *tr2;
	int uslov1, uslov2, uslov3, uslov4;
	/*OVO JE DODANO ZBOG PRILAGODJAVANJA ZADATKA STRUKTURI, PRVOBITNO SAM RADILA STRUKTURU KAO NA TUTORIJALU(CUVALA DVIJE TACKE)*/
	struct Tacka gore_desno;


	if (to1 == TACKA && to2 == TACKA) {
		/*pretvaranje u tacku tj u pkazivac na tacku*/
		tk1 = (struct Tacka*) oblik1;
		/*slucajevi 1. tacka-tacka, 2. tacka-kruznica, 3. tacka-pravougaonik, 4. tacka-trougao*/
		/*ovdje se samo moze porediti tacka sa tackom, ne moze nikako tacka obuhvatiti pravougaonik(osim ako ne bude da su obje tacke u pravougaoniku iste?)*/
		tk2 = (struct Tacka*) oblik2;
		if (fabs(tk1->x - tk2->x) < eps && fabs(tk1->y - tk2->y) < eps)
			return 1;
	} else if (to1 == KRUZNICA) {
		k1 = (struct Kruznica*) oblik1;
		/*kruznica-slucajevi: 1. kruznica-tacka, 2. kruznica - kruznica, 3. kruznica-pravougaonik, 4. kruznica-trougao*/
		if (to2 == TACKA) {
			tk2 = (struct Tacka*) oblik2;
			/*udaljenost tacke kao oblika 2 od centra kruznice manja je od poluprecnika kruznice, tada obuhvata*/
			/*asocijativnost za -> i . je left-to-right tj prvo se izvrsava onaj sa lijeve strane*/
			d1 = sqrt((tk2->x - k1->centar.x) * (tk2->x - k1->centar.x) + (tk2->y - k1->centar.y) * (tk2->y - k1->centar.y));
			if (d1 < k1->poluprecnik || fabs(d1 - k1->poluprecnik) < eps)
				return 1;
		} else if (to2 == KRUZNICA) {
			/*nadjemo provjerimo da li je poluprecnik velike kruznice veci od d + r2 gdje je d udaljenost izmedju 2 centra*/
			k2 = (struct Kruznica*) oblik2;
			d1 = sqrt((k2->centar.x - k1->centar.x) * (k2->centar.x - k1->centar.x) + (k2->centar.y - k1->centar.y) * (k2->centar.y - k1->centar.y));
			/*ako je k1 manja kruznica, nema sanse da k2 bude unutar nje pa zato imamo prvi dio uslova*/
			if ((k1->poluprecnik > k2->poluprecnik || fabs(k1->poluprecnik - k2->poluprecnik) < eps) &&
			        k1->poluprecnik > d1 + k2->poluprecnik || fabs(k1->poluprecnik - (d1 + k2->poluprecnik)) < eps)
				return 1;
		} else if (to2 == PRAVOUGAONIK) {
			/*ako su obje(kao i one pored njih) tacke kojima je definisan pravougaonik unutar kruznice*/
			p2 = (struct Pravougaonik*) oblik2;
			/*d1 je distanca izmedju centra i prve tacke, a d2 izmedju centra i druge tacke*/
			/*-----------------------provjeriti kako se zovu tacke u pravougaoniku za onu strukturu definisanu na serveru kako pise u zadatku-----------------------------*/
			/*OVO JE DODANO ZBOG PRILAGODJAVANJA ZADATKA STRUKTURI, PRVOBITNO SAM RADILA STRUKTURU KAO NA TUTORIJALU(CUVALA DVIJE TACKE)*/
			gore_desno = (struct Tacka) {
				p2->dole_lijevo.x + p2->sirina, p2->dole_lijevo.y + p2->visina
			};

			d1 = sqrt((k1->centar.x - p2->dole_lijevo.x) * (k1->centar.x - p2->dole_lijevo.x) + (k1->centar.y - p2->dole_lijevo.y) * (k1->centar.y - p2->dole_lijevo.y));
			d2 = sqrt((k1->centar.x - gore_desno.x) * (k1->centar.x - gore_desno.x) + (k1->centar.y - gore_desno.y) * (k1->centar.y - gore_desno.y));
			/*za tacku gore lijevo*/
			d3 = sqrt((k1->centar.x - p2->dole_lijevo.x) * (k1->centar.x - p2->dole_lijevo.x) + (k1->centar.y - gore_desno.x) * (k1->centar.y - gore_desno.x));
			d4 = sqrt((k1->centar.x - gore_desno.x) * (k1->centar.x - gore_desno.x) + (k1->centar.y - p2->dole_lijevo.y) * (k1->centar.y - p2->dole_lijevo.y));

			if ((k1->poluprecnik > d1 || fabs(k1->poluprecnik - d1) < eps) &&
			        (k1->poluprecnik > d2 || fabs(k1->poluprecnik - d2) < eps) &&
			        (k1->poluprecnik > d3 || fabs(k1->poluprecnik - d3) < eps) &&
			        (k1->poluprecnik > d4 || fabs(k1->poluprecnik - d4) < eps))
				return 1;

		} else if (to2 == TROUGAO) {
			/*ako su sve tri tacke trougla u kruznici*/
			tr2 = (struct Trougao*) oblik2;
			d1 = sqrt((k1->centar.x - tr2->vrh1.x) * (k1->centar.x - tr2->vrh1.x) + (k1->centar.y - tr2->vrh1.y) * (k1->centar.y - tr2->vrh1.y));
			d2 = sqrt((k1->centar.x - tr2->vrh2.x) * (k1->centar.x - tr2->vrh2.x) + (k1->centar.y - tr2->vrh2.y) * (k1->centar.y - tr2->vrh2.y));
			d3 = sqrt((k1->centar.x - tr2->vrh3.x) * (k1->centar.x - tr2->vrh3.x) + (k1->centar.y - tr2->vrh3.y) * (k1->centar.y - tr2->vrh3.y));

			if ((k1->poluprecnik > d1 || fabs(k1->poluprecnik - d1) < eps) &&
			        (k1->poluprecnik > d2 || fabs(k1->poluprecnik - d2) < eps) &&
			        (k1->poluprecnik > d3 || fabs(k1->poluprecnik - d3) < eps))
				return 1;
		}
	} else if (to1 == PRAVOUGAONIK) {
		p1 = (struct Pravougaonik*) oblik1;
		gore_desno = (struct Tacka) {
			p1->dole_lijevo.x + p1->sirina, p1->dole_lijevo.y + p1->visina
		};

		if (to2 == TACKA) {
			tk2 = (struct Tacka*) oblik2;

			uslov1 = (gore_desno.x > tk2->x || fabs(gore_desno.x - tk2->x) < eps) && (gore_desno.y > tk2->y || fabs(gore_desno.y - tk2->y) < eps)
			         && (p1->dole_lijevo.x < tk2->x || fabs(p1->dole_lijevo.x - tk2->x) < eps) && (p1->dole_lijevo.y < tk2->y || fabs(p1->dole_lijevo.y - tk2->y) < eps);

			if (uslov1)
				return 1;
		} else if (to2 == KRUZNICA) {
			k2 = (struct Kruznica*) oblik2;
			/*provjeravamo centar kruznice plus poluprecnik u pravcu x i pravcu y*/
			d1 = k2->centar.x + k2->poluprecnik; /*ovo je po x osi*/
			d2 = k2->centar.x - k2->poluprecnik;
			d3 = k2->centar.y + k2->poluprecnik; /*po y osi*/
			d4 = k2->centar.y - k2->poluprecnik;
			if ((gore_desno.x > d1 || fabs(gore_desno.x - d1) < eps) && (gore_desno.y > d3 || fabs(gore_desno.y - d3) < eps) &&
			        (p1->dole_lijevo.x < d2 || fabs(p1->dole_lijevo.x - d2) < eps) && (p1->dole_lijevo.y < d4 || fabs(p1->dole_lijevo.y - d4) < eps))
				return 1;

		} else if (to2 == PRAVOUGAONIK) {
			p2 = (struct Pravougaonik*) oblik2;
			/*ako su obje tacke kojima je definisan pravougaonik 2 u pravougaoniku 1*/
			/*tacka gore desno iz p2*/
			/*DODANO ZBOG RAZLICITIH STRUKTURA KAO STO JE RANIJE NAPOMENUTO*/
			struct Tacka gd_p2 = { p2->dole_lijevo.x + p2->sirina, p2->dole_lijevo.y + p2-> visina };

			uslov1 = (gore_desno.x > gd_p2.x || fabs(gore_desno.x - gd_p2.x) < eps) &&
			         (gore_desno.y > gd_p2.y || fabs(gore_desno.y - gd_p2.y) < eps) &&
			         (p1->dole_lijevo.x < p2->dole_lijevo.x || fabs(p1->dole_lijevo.x - p2->dole_lijevo.x) < eps) &&
			         (p1->dole_lijevo.y < p2->dole_lijevo.y || fabs(p1->dole_lijevo.y - p2->dole_lijevo.y) < eps);
			if (uslov1)
				return 1;
		} else if (to2 == TROUGAO) {
			tr2 = (struct Trougao*) oblik2;
			/*sve tri tacke pravougaonika u trouglu*/
			/*vrh1*/
			uslov1 = (tr2->vrh1.x < gore_desno.x || fabs(tr2->vrh1.x - gore_desno.x) < eps) && (tr2->vrh1.y < gore_desno.y ||
			         fabs(tr2->vrh1.y - gore_desno.y)) && (tr2->vrh1.x > p1->dole_lijevo.x || fabs(tr2->vrh1.x - p1->dole_lijevo.x) < eps)
			         && (tr2->vrh1.y > p1->dole_lijevo.y || fabs(tr2->vrh1.y - p1->dole_lijevo.y));
			/*vrh2*/
			uslov2 = (tr2->vrh2.x < gore_desno.x || fabs(tr2->vrh2.x - gore_desno.x) < eps) && (tr2->vrh2.y < gore_desno.y ||
			         fabs(tr2->vrh2.y - gore_desno.y)) && (tr2->vrh2.x > p1->dole_lijevo.x || fabs(tr2->vrh2.x - p1->dole_lijevo.x) < eps)
			         && (tr2->vrh2.y > p1->dole_lijevo.y || fabs(tr2->vrh2.y - p1->dole_lijevo.y));
			/*vrh3*/
			uslov3 = (tr2->vrh3.x < gore_desno.x || fabs(tr2->vrh3.x - gore_desno.x) < eps) && (tr2->vrh3.y < gore_desno.y ||
			         fabs(tr2->vrh3.y - gore_desno.y)) && (tr2->vrh3.x > p1->dole_lijevo.x || fabs(tr2->vrh3.x - p1->dole_lijevo.x) < eps)
			         && (tr2->vrh3.y > p1->dole_lijevo.y || fabs(tr2->vrh3.y - p1->dole_lijevo.y));

			if (uslov1 && uslov2 && uslov3)
				return 1;
		}
	} else if (to1 == TROUGAO) {
		tr1 = (struct Trougao*) oblik1;

		if (to2 == TACKA) {
			tk2 = (struct Tacka*) oblik2;
			if (tacka_u_trouglu(*tr1, *tk2)) /*šaljemo vrijednost a ne adresu*/
				return 1;
		} else if (to2 == KRUZNICA) {
			k2 = (struct Kruznica*) oblik2;
			/*nije implementirano*/
			return 0;
		} else if (to2 == PRAVOUGAONIK) {
			/*Ako su sve tacke pravougaonika u trouglu*/
			p2 = (struct Pravougaonik*) oblik2;
			/*DODANO ZBOG RAZLICITIH STRUKTURA KAO STO JE RANIJE NAPOMENUTO*/
			struct Tacka gd_p2 = { p2->dole_lijevo.x + p2->sirina, p2->dole_lijevo.y + p2-> visina };

			uslov1 = tacka_u_trouglu(*tr1, gd_p2);
			uslov2 = tacka_u_trouglu(*tr1, p2->dole_lijevo);

			struct Tacka dole_desno =  { p2->dole_lijevo.x, gd_p2.y };
			struct Tacka gore_lijevo = { gd_p2.x, p2->dole_lijevo.y };
			uslov3 = tacka_u_trouglu(*tr1, gore_lijevo);
			uslov4 = tacka_u_trouglu(*tr1, dole_desno);

			if (uslov1 && uslov2 && uslov3 && uslov4)
				return 1;
		} else if (to2 == TROUGAO) {
			tr2 = (struct Trougao*) oblik2;
			/*ako su sve tacke trougla 2 u trouglu 1*/
			uslov1 = tacka_u_trouglu(*tr1, tr2->vrh1);
			uslov2 = tacka_u_trouglu(*tr1, tr2->vrh2);
			uslov3 = tacka_u_trouglu(*tr1, tr2->vrh3);

			if (uslov1 && uslov2 && uslov3)
				return 1;
		}
	}

	return 0;
}

int main()
{
	void *oblici[50];
	enum TipOblika tipovi[50];
	int i, j, br_oblika, tip;
	float sirina, visina;

	struct Tacka tacke[50];
	struct Kruznica kruznice[50];
	struct Pravougaonik pravougaonici[50];
	struct Trougao trouglovi[50];
	int br_tk = 0, br_k = 0, br_p = 0, br_tr = 0;


	printf("Unesite broj oblika: ");
	scanf("%d", &br_oblika);

	for (i = 0; i < br_oblika; i++) {
		printf("Odaberite tip %d. oblika (1 - tacka, 2 - kruznica, 3 - pravougaonik, 4 - trougao): ", i + 1);
		scanf("%d", &tip);

		if (tip == 1) {
			/*unos tacke*/
			printf("Unesite tacku: koordinate x,y: ");
			scanf("%f,%f", &tacke[br_tk].x, &tacke[br_tk].y);
			oblici[i] = &tacke[br_tk];
			tipovi[i] = TACKA;

			br_tk++;
		} else if (tip == 2) {
			/*unos kruznice*/
			printf("Unesite centar kruznice: koordinate x,y: ");
			scanf("%f,%f", &kruznice[br_k].centar.x, &kruznice[br_k].centar.y);
			printf("Unesite poluprecnik kruznice: ");
			scanf("%f", &kruznice[br_k].poluprecnik);
			oblici[i] = &kruznice[br_k];
			tipovi[i] = KRUZNICA;

			br_k++;
		} else if (tip == 3) {
			/*pravougaonik*/
			printf("Unesite donji lijevi ugao: koordinate x,y: ");
			scanf("%f,%f", &pravougaonici[br_p].dole_lijevo.x, &pravougaonici[br_p].dole_lijevo.y);
			printf("Unesite sirinu: ");
			scanf("%f", &pravougaonici[br_p].sirina);
			printf("Unesite visinu: ");
			scanf("%f", &pravougaonici[br_p].visina);

			oblici[i] = &pravougaonici[br_p];
			tipovi[i] = PRAVOUGAONIK;

			br_p++;
		} else if (tip == 4) {
			/*trougao*/
			printf("Unesite prvi vrh: koordinate x,y: ");
			scanf("%f,%f", &trouglovi[br_tr].vrh1.x, &trouglovi[br_tr].vrh1.y);
			printf("Unesite drugi vrh: koordinate x,y: ");
			scanf("%f,%f", &trouglovi[br_tr].vrh2.x, &trouglovi[br_tr].vrh2.y);
			printf("Unesite treci vrh: koordinate x,y: ");
			scanf("%f,%f", &trouglovi[br_tr].vrh3.x, &trouglovi[br_tr].vrh3.y);

			oblici[i] = &trouglovi[br_tr];
			tipovi[i] = TROUGAO;

			br_tr++;
		} else {
			/*pogresan tip*/
			printf("Nepoznat tip oblika %d!\n", tip);
			i--; /*i++ na kraju petlje nas vrati na isto*/
		}

	}

	for (i = 0; i < br_oblika; i++) {
		for (j = 0; j < br_oblika; j++) {
			if (i != j && obuhvata(oblici[i], tipovi[i], oblici[j], tipovi[j]))
				printf("\nOblik %d obuhvata oblik %d.", i+1, j+1);
		}
	}

	return 0;
}

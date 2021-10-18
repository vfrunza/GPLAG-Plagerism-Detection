#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
enum TipOblika {TACKA, KRUZNICA, PRAVOUGAONIK, TROUGAO};


struct Tacka {
	float x;
	float y;
};
struct Kruznica {
	struct Tacka centar;
	float radijus;
};
struct Pravougaonik {
	struct Tacka tacka;
	float visina;
	float sirina;
};

struct Pravougaonik_u_koordinatama {
	struct Tacka A;
	struct Tacka B;
	struct Tacka C;
	struct Tacka D;
};
struct Trougao {
	struct Tacka vrh1;
	struct Tacka vrh2;
	struct Tacka vrh3;
};


struct Tacka unesi_tacku()
{
	struct Tacka tacka;
	printf("koordinate x,y: ");
	scanf("%f,%f", &tacka.x, &tacka.y);
	return tacka;
}

struct Kruznica unesi_kruznicu()
{
	struct Kruznica k;
	printf("Unesite centar kruznice: ");
	k.centar=unesi_tacku();
	printf("Unesite poluprecnik kruznice: ");
	scanf("%f", &k.radijus);
	return k;
}

struct Pravougaonik unesi_pravougaonik()
{
	struct Pravougaonik p;
	printf("Unesite donji lijevi ugao: ");
	p.tacka=unesi_tacku();
	printf("Unesite sirinu: ");
	scanf("%f", &p.sirina);
	printf("Unesite visinu: ");
	scanf("%f", &p.visina);
	return p;
}

struct Trougao unesi_trougao()
{
	struct Trougao t;
	printf("Unesite prvi vrh: ");
	t.vrh1=unesi_tacku();
	printf("Unesite drugi vrh: ");
	t.vrh2=unesi_tacku();
	printf("Unesite treci vrh: ");
	t.vrh3=unesi_tacku();
	return t;
}

float udaljenost_dve_tacke(struct Tacka t1, struct Tacka t2)
{
	return sqrt((t1.x-t2.x)*(t1.x-t2.x)+(t1.y-t2.y)*(t1.y-t2.y));
}

float visina_iz_zadnjeg_parametra(struct Tacka a, struct Tacka b, struct Tacka c)
{
	float povrsina;
	float visina=0;
	float AB=udaljenost_dve_tacke(a,b);
	if(fabs(AB)<EPSILON) return 0;
	float BC=udaljenost_dve_tacke(b,c);
	float CA=udaljenost_dve_tacke(c,a);
	float s=(AB+BC+CA)/2; //
	povrsina=(s*(s-AB)*(s-CA)*(s-BC)); //POVRSINA je bila NA KVADRAT
	visina=sqrt((4*povrsina)/(AB*AB)); //VISINA je bila NA KVADRAT, radi oboje
	return visina;
}

struct Pravougaonik_u_koordinatama rotiraj_pravougaonik(struct Pravougaonik p)
{
	struct Pravougaonik_u_koordinatama novi_pravougaonik;
	novi_pravougaonik.A=p.tacka;
	novi_pravougaonik.B.x=p.tacka.x+p.sirina;
	novi_pravougaonik.B.y=p.tacka.y;
	novi_pravougaonik.C.x=p.tacka.x+p.sirina;
	novi_pravougaonik.C.y=p.tacka.y+p.visina;
	novi_pravougaonik.D.x=p.tacka.x;
	novi_pravougaonik.D.y=p.tacka.y+p.visina;
	return novi_pravougaonik;

}

int tacka_tacka(struct Tacka t1, struct Tacka t2)
{
	if(fabs(t1.y-t2.y)<EPSILON && fabs(t1.x-t2.x)<EPSILON) return 1;
	return 0;
}


int kruznica_tacka(struct Tacka t, struct Kruznica k)
{
	float udaljenost=udaljenost_dve_tacke(t, k.centar);
	if(udaljenost<k.radijus) return 1;
	if(fabs(udaljenost-k.radijus)<EPSILON) return 1;
	return 0;

}

int kruznica_kruznica(struct Kruznica k1, struct Kruznica k2)
{
	float udaljenost=udaljenost_dve_tacke(k1.centar, k2.centar);
	if(udaljenost<k1.radijus+k2.radijus)	return 1;
	if(fabs(udaljenost-k1.radijus-k2.radijus)<EPSILON) return 1;
	return 0;
}

int tacka_kruznica(struct Tacka t, struct Kruznica k)
{
	if(k.radijus<EPSILON && fabs(k.centar.x-t.x)<EPSILON && fabs(k.centar.y-t.y<EPSILON)) return 1;
	return 0;
}

int trougao_tacka(struct Tacka t, struct Trougao tr)
{

	double skalarni1=(tr.vrh2.y-tr.vrh1.y)*(t.x-tr.vrh1.x)+(tr.vrh1.x-tr.vrh2.x)*(t.y-tr.vrh1.y);
	double skalarni2=(tr.vrh3.y-tr.vrh2.y)*(t.x-tr.vrh2.x)+(tr.vrh2.x-tr.vrh3.x)*(t.y-tr.vrh2.y);
	double skalarni3=(tr.vrh1.y-tr.vrh3.y)*(t.x-tr.vrh3.x)+(tr.vrh3.x-tr.vrh1.x)*(t.y-tr.vrh3.y);

	if(skalarni1<=0 && skalarni2<=0 && skalarni3<=0 || skalarni1>=0 && skalarni2>=0 && skalarni3>=0) return 1; //ovo prepravi ovamo na fabs pa preko epsilon
	return 0;

}

int tacka_trougao(struct Tacka t, struct Trougao tr)
{
	if(fabs(tr.vrh1.x-tr.vrh2.x)<EPSILON && fabs(tr.vrh2.x-tr.vrh3.x)<EPSILON && fabs(tr.vrh1.y-tr.vrh2.y)<EPSILON && fabs(tr.vrh2.y-tr.vrh3.y)<EPSILON && fabs(tr.vrh3.x-t.x)<EPSILON && fabs(tr.vrh3.y-t.y)<EPSILON) return 1;
	return 0;
}


int pravougaonik_tacka(struct Tacka t, struct Pravougaonik p)
{
	struct Pravougaonik_u_koordinatama novi_pravougaonik=rotiraj_pravougaonik(p);
	struct Tacka nova_tacka=t;
	if(t.x>=novi_pravougaonik.A.x && t.x<=novi_pravougaonik.B.x && t.y>=novi_pravougaonik.A.y && t.y<=novi_pravougaonik.D.y) return 1;
	return 0;

}

int tacka_pravougaonik(struct Tacka t, struct Pravougaonik p)
{
	if(fabs(p.visina)<EPSILON && fabs(p.sirina)<EPSILON && fabs(p.tacka.x-t.x)<EPSILON && fabs(p.tacka.y-t.y)<EPSILON) return 1;
	return 0;
}

int kruznica_trougao(struct Kruznica k, struct Trougao t)
{
	if(kruznica_tacka(t.vrh1, k) && kruznica_tacka(t.vrh2, k) && kruznica_tacka(t.vrh3, k)) return 1;
	return 0;

}

int trougao_kruznica(struct Trougao t, struct Kruznica k)
{

	if(!trougao_tacka(k.centar,t ) || kruznica_tacka(t.vrh1, k) || kruznica_tacka(t.vrh2, k) || kruznica_tacka(t.vrh3, k)) {
		return 0;
	}
	float visina1=visina_iz_zadnjeg_parametra(t.vrh1, t.vrh2, k.centar);
	float visina2=visina_iz_zadnjeg_parametra(t.vrh2, t.vrh3, k.centar);
	float visina3=visina_iz_zadnjeg_parametra(t.vrh3, t.vrh1, k.centar);
	if((visina1>k.radijus || fabs(visina1-k.radijus)<EPSILON) && (visina2>k.radijus || fabs(k.radijus-visina2)<EPSILON) && (visina3>k.radijus || fabs(visina3-k.radijus)<EPSILON)) return 1;
	return 0;
}

int kruznica_pravougaonik(struct Kruznica k, struct Pravougaonik p)
{
	struct Pravougaonik_u_koordinatama novi_pravougaonik=rotiraj_pravougaonik(p);
	if(kruznica_tacka(novi_pravougaonik.A, k) && kruznica_tacka(novi_pravougaonik.B, k) && kruznica_tacka(novi_pravougaonik.C, k) && kruznica_tacka(novi_pravougaonik.D, k)) return 1;
	return 0;
}
int pravougaonik_kruznica(struct Pravougaonik p, struct Kruznica k) //provjeri ovo
{
	struct Pravougaonik_u_koordinatama novi_pravougaonik=rotiraj_pravougaonik(p);
	if(!pravougaonik_tacka(k.centar, p) || (kruznica_tacka(novi_pravougaonik.A,k)) || (kruznica_tacka(novi_pravougaonik.B,k)) || (kruznica_tacka(novi_pravougaonik.C, k)) || (kruznica_tacka(novi_pravougaonik.D,k))) return 0;
	if(k.centar.x-k.radijus>=novi_pravougaonik.A.x && k.centar.x+k.radijus<=novi_pravougaonik.B.x && k.centar.y+k.radijus>=novi_pravougaonik.A.y && k.centar.y-k.radijus<=novi_pravougaonik.C.y) return 1;
	return 0;
}

int pravougaonik_pravougaonik(struct Pravougaonik p1, struct Pravougaonik p2)
{
	struct Pravougaonik_u_koordinatama novi_pravougaonik=rotiraj_pravougaonik(p2);
	if(pravougaonik_tacka(novi_pravougaonik.A,p1) && pravougaonik_tacka(novi_pravougaonik.B, p1) && pravougaonik_tacka(novi_pravougaonik.C, p1) && pravougaonik_tacka(novi_pravougaonik.D, p1)) return 1;
	return 0;
}
int trougao_trougao(struct Trougao t1, struct Trougao t2)
{
	if(trougao_tacka(t2.vrh1, t1) && trougao_tacka(t2.vrh2, t1) && trougao_tacka(t2.vrh3, t1)) return 1;
	return 0;
}
int pravougaonik_trougao(struct Pravougaonik p, struct Trougao t)
{
	if(pravougaonik_tacka(t.vrh1, p), pravougaonik_tacka(t.vrh2, p), pravougaonik_tacka(t.vrh3, p)) return 1;
	return 0;
}
int trougao_pravougaonik(struct Trougao t, struct Pravougaonik p)
{
	struct Pravougaonik_u_koordinatama novi_pravougaonik=rotiraj_pravougaonik(p);
	if(trougao_tacka(novi_pravougaonik.A, t) && trougao_tacka(novi_pravougaonik.B,t) && trougao_tacka(novi_pravougaonik.C, t) && trougao_tacka(novi_pravougaonik.D, t)) return 1;
	return 0;
}


int obuhvata(void* oblik1, enum TipOblika to1, void* oblik2, enum TipOblika to2)
{

	if(to1==TACKA && to2==TACKA) {
		struct Tacka* t1=(struct Tacka*) oblik1;
		struct Tacka* t2=(struct Tacka*) oblik2;
		if(tacka_tacka(*t1, *t2)) {
			return 1;
		}

		return 0;
	}
	if(to1==KRUZNICA && to2==KRUZNICA) {
		struct Kruznica* k1=(struct Kruznica*) oblik1;
		struct Kruznica* k2=(struct Kruznica*) oblik2;
		if(kruznica_kruznica(*k1, *k2)) {
			return 1;
		}
		return 0;
	}


	if(to1==TACKA && to2==KRUZNICA) {
		struct Tacka* t=(struct Tacka*) oblik1;
		struct Kruznica* k=(struct Kruznica*) oblik2;
		if(tacka_kruznica(*t,*k)) {
			return 1;
		}
		return 0;
	}

	if(to1==KRUZNICA && to2==TACKA) {
		struct Kruznica* k=(struct Kruznica*) oblik1;
		struct Tacka* t=(struct Tacka*) oblik2;
		if(kruznica_tacka(*t,*k)) {
			return 1;
		}
		return 0;
	}

	if(to1==PRAVOUGAONIK && to2==TACKA) {
		struct Pravougaonik* p=(struct Pravougaonik*) oblik1;
		struct Tacka* t=(struct Tacka*) oblik2;
		if(pravougaonik_tacka(*t, *p)) {
			return 1;
		}
		return 0;
	}

	if(to1==TACKA && to2==PRAVOUGAONIK) {
		struct Tacka* t=(struct Tacka*) oblik1;
		struct Pravougaonik* p=(struct Pravougaonik*) oblik2;
		if(tacka_pravougaonik(*t,*p)) {
			return 1;
		}

		return 0;
	}

	if(to1==TROUGAO && to2==TACKA) {
		struct Tacka* t=(struct Tacka*) oblik2;
		struct Trougao* tr=(struct Trougao*) oblik1;
		if(trougao_tacka(*t,*tr)) {
			return 1;
		}

		return 0;
	}

	if(to1==TACKA && to2==TROUGAO) {
		struct Tacka* t=(struct Tacka*) oblik1;
		struct Trougao* tr=(struct Trougao*) oblik2;
		if(tacka_trougao(*t,*tr)) {
			return 1;
		}

		return 0;
	}

	if(to1==KRUZNICA && to2==TROUGAO) {
		struct Kruznica* k=(struct Kruznica*) oblik1;
		struct Trougao* t=(struct Trougao*) oblik2;
		if(kruznica_trougao(*k,*t)) {
			return 1;
		}

		return 0;
	}

	if(to1==TROUGAO && to2==KRUZNICA) {
		struct Trougao* t=(struct Trougao*) oblik1;
		struct Kruznica* k=(struct Kruznica*) oblik2;
		if(trougao_kruznica(*t,*k)) {
			return 1;
		}

		return 0;
	}

	if(to1==KRUZNICA && to2==PRAVOUGAONIK) {
		struct Kruznica* k=(struct Kruznica*) oblik1;
		struct Pravougaonik *p=(struct Pravougaonik*) oblik2;
		if(kruznica_pravougaonik(*k,*p)) {
			return 1;
		}

		return 0;
	}

	if(to1==PRAVOUGAONIK && to2==KRUZNICA) {
		struct Pravougaonik* p=(struct Pravougaonik*) oblik1;
		struct Kruznica* k=(struct Kruznica*) oblik2;
		if(pravougaonik_kruznica(*p,*k)) {
			return 1;
		}

		return 0;
	}

	if(to1==PRAVOUGAONIK && to2==PRAVOUGAONIK) {
		struct Pravougaonik* p1=(struct Pravougaonik*) oblik1;
		struct Pravougaonik* p2=(struct Pravougaonik*) oblik2;
		if(pravougaonik_pravougaonik(*p1, *p2)) {
			return 1;
		}
		return 0;
	}

	if(to1==TROUGAO && to2==TROUGAO) {
		struct Trougao* t1=(struct Trougao*) oblik1;
		struct Trougao* t2=(struct Trougao*) oblik2;
		if(trougao_trougao(*t1, *t2)) {
			return 1;
		}
		return 0;
	}

	if(to1==PRAVOUGAONIK && to2==TROUGAO) {
		struct Pravougaonik* p=(struct Pravougaonik*) oblik1;
		struct Trougao* t=(struct Trougao*) oblik2;
		if(pravougaonik_trougao(*p, *t)) {
			return 1;
		}
		return 0;
	}

	if(to1==TROUGAO && to2==PRAVOUGAONIK) {
		struct Trougao* t=(struct Trougao*) oblik1;
		struct Pravougaonik* p=(struct Pravougaonik*) oblik2;
		if(trougao_pravougaonik(*t,*p)) {
			return 1;
		}
		return 0;
	}

	return 0;
}

int main()
{
	int n;
	int kontrolna;
	struct Tacka t[50];
	struct Trougao tr[50];
	struct Pravougaonik p[50];
	struct Kruznica k[50];
	enum TipOblika niz[50];
	printf("Unesite broj oblika: ");
	scanf("%d", &n);
	int pomocna=n;
	int i=0;
	int brojimt=0;
	int brojimk=0;
	int brojimp=0;
	int brojimtr=0;
	do {
		printf("Odaberite tip %d. oblika (1 - tacka, 2 - kruznica, 3 - pravougaonik, 4 - trougao): ", i+1);
		scanf("%d", &kontrolna);
		if(kontrolna>4 || kontrolna<1) {
			printf("Nepoznat tip oblika %d!\n", kontrolna);
			continue;
		} else if(kontrolna==1) {
			printf("Unesite tacku: ");
			t[brojimt]=unesi_tacku();
			brojimt++;
			niz[i]=kontrolna-1;
			i++;
		} else if(kontrolna==2) {
			k[brojimk]=unesi_kruznicu();
			brojimk++;
			niz[i]=kontrolna-1;
			i++;
		} else if(kontrolna==3) {
			p[brojimp]=unesi_pravougaonik();
			brojimp++;
			niz[i]=kontrolna-1;
			i++;
		} else if(kontrolna==4) {
			tr[brojimtr]=unesi_trougao();
			brojimtr++;
			niz[i]=kontrolna-1;
			i++;
		}
		n--;
	} while(n);

	int j;
	int u;
	printf("\n");

	struct Tacka* pom1=t;
	struct Tacka* pom12=t;
	struct Kruznica* pom2=k;
	struct Kruznica* pom22=k;
	struct Pravougaonik* pom3=p;
	struct Pravougaonik* pom32=p;
	struct Trougao* pom4=tr;
	struct Trougao* pom42=tr;

	for(j=0; j<pomocna; j++) {
		void *prva;
		void *druga;
		if(niz[j]==0) {
			prva=pom1;
			pom1++;
		} else if(niz[j]==1) {
			prva=pom2;
			pom2++;
		} else if(niz[j]==2) {
			prva=pom3;
			pom3++;
		} else if(niz[j]==3) {
			prva=pom4;
			pom4++;
		}

		for(u=0; u<pomocna; u++) {
			if(u==j) continue;
			if(niz[u]==0) {
				druga=pom12;
				pom12++;
			} else if(niz[u]==1) {
				druga=pom22;
				pom22++;
			} else if(niz[u]==2) {
				druga=pom32;
				pom32++;
			} else if(niz[u]==3) {
				druga=pom42;
				pom42++;
			}
			if(obuhvata(prva, (enum TipOblika)niz[j], druga, (enum TipOblika)niz[u])) printf("Oblik %d obuhvata oblik %d.\n", j+1, u+1);

		}
		pom12=t;
		pom22=k;
		pom32=p;
		pom42=tr;

	}

	return 0;
}

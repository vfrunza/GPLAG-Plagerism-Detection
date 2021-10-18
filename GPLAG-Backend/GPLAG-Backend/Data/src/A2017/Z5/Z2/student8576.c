#include <stdio.h>
#include <math.h>
#define Eps  0.001


struct Tacka {
	double x,y;
};

struct Kruznica {
	struct Tacka centar;
	double radijus;
};

struct Pravougaonik {
	struct Tacka DL; // koordinate donjeg lijevog vrha pravougaonika
	double sirina;
	double visina;
};

struct Trougao {
	struct Tacka A,B,C;
};
enum TipOblika { TACKA, KRUZNICA, PRAVOUGAONIK, TROUGAO };


double povrsinaTrougla(struct Trougao tr)
{
	return fabs( (tr.B.x-tr.A.x)*(tr.C.y-tr.A.y) - (tr.C.x-tr.A.x)*(tr.B.y-tr.A.y) );
}

double udaljenost_tacke_od_duzi(struct Tacka t0, struct Tacka t1, struct Tacka t2){
	double A = (t2.y - t1.y)/(t2.x-t1.x);
	double B = -1;
	double C = (t1.y*t2.x - t1.x*t2.y)/(t2.x-t1.x);
	
	return fabs(A*t0.x +B*t0.y +C)/(sqrt(A*A+B*B));
}

int poredi(double x, double y)
{
	return fabs(x - y) <= Eps * (fabs(x) + fabs(y));
}



int obuhvata_tacka_tacku(struct Tacka t1, struct Tacka t2)
{
	return t1.x==t2.x && t1.y==t2.y;
}
int obuhvata_tacka_kruznicu(struct Tacka t, struct Kruznica k)
{
	return k.radijus==0 && k.centar.x==t.x&&k.centar.y==t.y;
}
int obuhvata_tacka_pravougaonik(struct Tacka t, struct Pravougaonik p)
{
	return p.visina==0&&p.sirina==0&&t.x==p.DL.x&&t.y==p.DL.y;
}
int obuhvata_tacka_trougao(struct Tacka t, struct Trougao tr)
{
	return t.x==tr.A.x&&t.y==tr.A.y&&t.x==tr.B.x&&t.y==tr.B.y&&t.x==tr.C.x&&t.y==tr.C.y;
}

double udaljenost(struct Tacka t1, struct Tacka t2)
{
	return sqrt( (t1.x-t2.x)*(t1.x-t2.x) +(t1.y-t2.y)*(t1.y-t2.y));
}

int obuhvata_kruznica_tacku(struct Kruznica k, struct Tacka t)
{
	double d = udaljenost(k.centar,t);
	return (d<k.radijus || poredi(d,k.radijus));
}


int obuhvata_kruznica_kruznicu(struct Kruznica k1, struct Kruznica k2)
{
	double d = udaljenost(k1.centar,k2.centar);
	double f = d + k2.radijus;
	return f<k1.radijus || poredi(f,k1.radijus);
}

int obuhvata_kruznica_pravougaonik(struct Kruznica k, struct Pravougaonik p)
{
	struct Tacka A = p.DL;
	struct Tacka B = {A.x+p.sirina,A.y};
	struct Tacka C = {A.x+p.sirina , A.y+p.visina};
	struct Tacka D = {A.x, A.y+ p.visina};

	return obuhvata_kruznica_tacku(k,A)&&
	       obuhvata_kruznica_tacku(k,B)&&
	       obuhvata_kruznica_tacku(k,C)&&
	       obuhvata_kruznica_tacku(k,D);
}

int obuhvata_kruznica_trougao(struct Kruznica k, struct Trougao tr)
{
	return obuhvata_kruznica_tacku(k, tr.A)&&
	       obuhvata_kruznica_tacku(k, tr.B)&&
	       obuhvata_kruznica_tacku(k, tr.C);
}

int obuhvata_pravougaonik_tacku(struct Pravougaonik p, struct Tacka t)
{
	return t.x>=p.DL.x &&t.x<=p.DL.x+p.sirina && t.y>=p.DL.y&&t.y<=p.DL.y+p.visina;
}

int obuhvata_pravougaonik_kruznicu(struct Pravougaonik p, struct Kruznica k)
{
	return k.centar.x-k.radijus >=p.DL.x && k.centar.x+k.radijus<=p.DL.x+p.sirina&&
	       k.centar.y-k.radijus>=p.DL.y && k.centar.y+k.radijus<=p.DL.y+p.visina;
}

int obuhvata_pravougaonik_pravougaonik(struct Pravougaonik p1, struct Pravougaonik p2)
{
	return p2.DL.x >= p1.DL.x && p2.DL.x+p2.sirina <= p1.DL.x+p1.sirina &&
	       p2.DL.y >=p1.DL.y && p2.DL.y+p2.visina <= p1.DL.y+p1.visina;
}


int obuhvata_pravougaonik_trougao(struct Pravougaonik p, struct Trougao tr)
{
	return obuhvata_pravougaonik_tacku(p,tr.A)&&obuhvata_pravougaonik_tacku(p,tr.B)&&
	       obuhvata_pravougaonik_tacku(p,tr.C);
}

int obuhvata_trougao_tacku(struct Trougao tr, struct Tacka t)
{
	double P = povrsinaTrougla(tr);

	struct Trougao tr1 = {tr.A, tr.B, t};
	struct Trougao tr2 = {tr.B, tr.C, t};
	struct Trougao tr3 = {tr.A, tr.C, t};
	double P1 = povrsinaTrougla(tr1);
	double P2 = povrsinaTrougla(tr2);
	double P3 = povrsinaTrougla(tr3);

	return poredi(P, P1+P2+P3);
}

int obuhvata_trougao_kruznicu(struct Trougao tr, struct Kruznica k)
{
	double d1 = udaljenost_tacke_od_duzi(k.centar,tr.A,tr.B);
	double d2 = udaljenost_tacke_od_duzi(k.centar,tr.A,tr.C);
	double d3 = udaljenost_tacke_od_duzi(k.centar,tr.C,tr.B);
	return (poredi(d1,k.radijus)||d1>k.radijus)&&
		   (poredi(d2,k.radijus)||d2>k.radijus)&&
		   (poredi(d3,k.radijus)||d3>k.radijus)
			&&obuhvata_trougao_tacku(tr,k.centar);
}

int obuhvata_trougao_pravougaonik(struct Trougao tr, struct Pravougaonik p)
{
	struct Tacka A = p.DL;
	struct Tacka B = {A.x+p.sirina,A.y};
	struct Tacka C = {A.x+p.sirina , A.y+p.visina};
	struct Tacka D = {A.x, A.y+ p.visina};
	return
	    obuhvata_trougao_tacku(tr,A)&&
	    obuhvata_trougao_tacku(tr,B)&&
	    obuhvata_trougao_tacku(tr,C)&&
	    obuhvata_trougao_tacku(tr,D);
}


int obuhvata_trougao_trougao(struct Trougao tr1, struct Trougao tr2)
{
	return
	    obuhvata_trougao_tacku(tr1,tr2.A)&&
	    obuhvata_trougao_tacku(tr1,tr2.B)&&
	    obuhvata_trougao_tacku(tr1,tr2.C);
}

int obuhvata(void* oblik1,enum TipOblika to1, void* oblik2,enum TipOblika to2)
{
	struct Tacka*t1,*t2;
	struct Kruznica*k1,*k2;
	struct Pravougaonik*p1,*p2;
	struct Trougao* tr1,* tr2;

	if(to1 == TACKA&&to2==TACKA) {
		t1  = (struct Tacka*)oblik1;
		t2 =  (struct Tacka*)oblik2;
		return obuhvata_tacka_tacku(*t1,*t2);
	}

	else if(to1==TACKA&&to2==KRUZNICA) {
		t1 = (struct Tacka*)oblik1;
		k2 = (struct Kruznica*)oblik2;
		return obuhvata_tacka_kruznicu(*t1,*k2);
	} else if(to1==TACKA&&to2==PRAVOUGAONIK) {
		t1 = (struct Tacka*)oblik1;
		p2 = (struct Pravougaonik*)oblik2;
		return obuhvata_tacka_pravougaonik(*t1,*p2);
	} else if(to1==TACKA&&to2==TROUGAO) {
		t1 = (struct Tacka*)oblik1;
		tr2 = (struct Trougao*)oblik2;
		return obuhvata_tacka_trougao(*t1,*tr2);
	} else if(to1==KRUZNICA&&to2==TACKA) {
		k1=(struct Kruznica*)oblik1;
		t2=(struct Tacka*)oblik2;

		return obuhvata_kruznica_tacku(*k1,*t2);
	} else if(to1==KRUZNICA&&to2==KRUZNICA) {
		k1=(struct Kruznica*)oblik1;
		k2=(struct Kruznica*)oblik2;

		return obuhvata_kruznica_kruznicu(*k1,*k2);
	} else if(to1==KRUZNICA&&to2==PRAVOUGAONIK) {
		k1=(struct Kruznica*)oblik1;
		p2=(struct Pravougaonik*)oblik2;

		return obuhvata_kruznica_pravougaonik(*k1,*p2);
	} else if(to1==KRUZNICA&&to2==TROUGAO) {
		k1=(struct Kruznica*)oblik1;
		tr2=(struct Trougao*)oblik2;

		return obuhvata_kruznica_trougao(*k1,*tr2);
	} else if(to1==PRAVOUGAONIK&&to2==TACKA) {
		p1 = (struct Pravougaonik*)oblik1;
		t2 = (struct Tacka*)oblik2;

		return obuhvata_pravougaonik_tacku(*p1,*t2);
	} else if(to1==PRAVOUGAONIK&&to2==KRUZNICA) {
		p1 = (struct Pravougaonik*)oblik1;
		k2 = (struct Kruznica*)oblik2;

		return obuhvata_pravougaonik_kruznicu(*p1,*k2);
	} else if(to1==PRAVOUGAONIK&&to2==PRAVOUGAONIK) {
		p1 = (struct Pravougaonik*)oblik1;
		p2 = (struct Pravougaonik*)oblik2;

		return obuhvata_pravougaonik_pravougaonik(*p1,*p2);
	} else if(to1==PRAVOUGAONIK&&to2==TROUGAO) {
		p1=(struct Pravougaonik*)oblik1;
		tr2=(struct Trougao*)oblik2;
		return obuhvata_pravougaonik_trougao(*p1,*tr2);
	} else if(to1==TROUGAO&&to2==TACKA) {
		tr1=(struct Trougao*)oblik1;
		t2 = (struct Tacka*)oblik2;

		return obuhvata_trougao_tacku(*tr1,*t2);
	} else if(to1==TROUGAO&&to2==KRUZNICA) {
		tr1 = (struct Trougao*)oblik1;
		k2 = (struct Kruznica*)oblik2;

		return obuhvata_trougao_kruznicu(*tr1,*k2);
	} else if(to1==TROUGAO&&to2==PRAVOUGAONIK) {
		tr1 = (struct Trougao*)oblik1;
		p2 = (struct Pravougaonik*)oblik2;

		return obuhvata_trougao_pravougaonik(*tr1,*p2);
	} else {
		tr1 = (struct Trougao*)oblik1;
		tr2 = (struct Trougao*)oblik2;

		return obuhvata_trougao_trougao(*tr1,*tr2);
	}
}


struct Tacka unesi_tacku()
{
	struct Tacka t;
	printf("koordinate x,y: ");
	scanf("%lf,%lf",&t.x,&t.y);
	return t;
}

struct Kruznica unesi_kruznicu()
{
	struct Kruznica k;
	printf("Unesite centar kruznice: ");
	k.centar = unesi_tacku();
	printf("Unesite poluprecnik kruznice: ");
	scanf("%lf ",&k.radijus);

	return k;
}

struct Pravougaonik unesi_pravougaonik()
{
	struct Pravougaonik p;
	printf("Unesite donji lijevi ugao: ");
	p.DL = unesi_tacku();
	printf("Unesite sirinu: ");
	scanf("%lf",&p.sirina);
	printf("Unesite visinu: ");
	scanf("%lf",&p.visina);
	return p;
}

struct Trougao unesi_trougao()
{
	struct Trougao tr;
	printf("Unesite prvi vrh: ");
	tr.A = unesi_tacku();
	printf("Unesite drugi vrh: ");
	tr.B = unesi_tacku();
	printf("Unesite treci vrh: ");
	tr.C = unesi_tacku();
	return tr;
}


int main()
{

	int broj_oblika,i,j,tip;
	struct Tacka tacke[50];
	struct Pravougaonik pravougaonici[50];
	struct Kruznica kruznice[50];
	struct Trougao trouglovi[50];
	void* oblici[50];
	enum TipOblika tipovi[50];
	printf("Unesite broj oblika: ");
	scanf("%d",&broj_oblika);

	for(i=0; i<broj_oblika; i++) {
		printf("Odaberite tip %d. oblika (1 - tacka, 2 - kruznica, 3 - pravougaonik, 4 - trougao): ",i+1);
		scanf("%d",&tip);

		switch(tip) {
		case 1:
			tipovi[i]=TACKA;
			printf("Unesite tacku: ");
			tacke[i] = unesi_tacku();
			oblici[i]=&tacke[i];
			break;
		case 2:
			tipovi[i]=KRUZNICA;
			kruznice[i] = unesi_kruznicu();
			oblici[i]=&kruznice[i];
			break;
		case 3:
			tipovi[i]=PRAVOUGAONIK;
			pravougaonici[i]=unesi_pravougaonik();
			oblici[i]=&pravougaonici[i];
			break;
		case 4:
			tipovi[i]=TROUGAO;
			trouglovi[i]=unesi_trougao();
			oblici[i]=&trouglovi[i];
			break;
		default:
			printf("Nepoznat tip oblika %d!\n",tip);
			i--;
		}
	}


	for ( i = 0; i < broj_oblika; i++) {
		for ( j = 0; j < broj_oblika; j++) {
			if(i==j)continue;
			if(obuhvata(oblici[i],tipovi[i],oblici[j],tipovi[j])) {
				printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
			}

		}
	}

	return 0;
}

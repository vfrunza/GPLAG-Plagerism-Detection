#include <stdio.h>
#include <math.h>
#define eps 0.001

enum TipOblika { TACKA, KRUZNICA, PRAVOUGAONIK, TROUGAO };

/* Definicije oblika: */
struct Tacka {
	float x,y;
};
struct Kruznica {
	struct Tacka centar;
	float radijus;
};
struct Pravougaonik {
	struct Tacka donji_lijevi;
	int visina;
	int sirina;

};
struct Trougao {
	struct Tacka vrh1;
	struct Tacka vrh2;
	struct Tacka vrh3;
};

float povrsina_trougla (struct Tacka t1, struct Tacka t2, struct Tacka t3) {
	return 0.5*fabs(t1.x*(t2.y-t3.y) + t2.x*(t3.y-t1.y) + t3.x*(t1.y-t2.y));
}

float povrsina_pravougaonika (struct Pravougaonik p) {
	return p.visina*p.sirina;
}

float udaljenost_tacke (struct Tacka t1, struct Tacka t2) {
	return sqrt((t1.x-t2.x)*(t1.x-t2.x)+(t1.y-t2.y)*(t1.y-t2.y));
}

int pripadnost_tacke_trouglu (struct Tacka t, struct Trougao tr) {
	if (fabs(povrsina_trougla(tr.vrh1, tr.vrh2, tr.vrh3)-(povrsina_trougla(t, tr.vrh1, tr.vrh2)+povrsina_trougla(t, tr.vrh1, tr.vrh3)+povrsina_trougla(t, tr.vrh2, tr.vrh3)))>eps) return 0;
	return 1;
}

int pripadnost_tacke_pravougaoniku (struct Tacka t, struct Pravougaonik p) {
	if (t.x>p.donji_lijevi.x+p.sirina || t.x<p.donji_lijevi.x || t.y>p.donji_lijevi.y+p.visina || t.y<p.donji_lijevi.y) return 0;
	return 1;
}

int obuhvata(void* oblik1, enum TipOblika to1, void* oblik2, enum TipOblika to2) {
	
	struct Tacka t1, t2;
	struct Kruznica k1, k2;
	struct Pravougaonik p1, p2;
	struct Trougao tr1, tr2;
	
	struct Tacka gornji_desni;
	struct Tacka gornji_lijevi;
	struct Tacka donji_desni;
	
	/* Konvertujemo parametar tipe void*: */
	if (to1==TACKA) t1=*(struct Tacka*)oblik1;
	else if (to1==KRUZNICA) k1=*(struct Kruznica*)oblik1;
	else if (to1==PRAVOUGAONIK) p1=*(struct Pravougaonik*)oblik1;
	else if (to1==TROUGAO) tr1=*(struct Trougao*)oblik1;
	
	if (to2==TACKA) t2=*(struct Tacka*)oblik2;
	else if (to2==KRUZNICA) k2=*(struct Kruznica*)oblik2;
	else if (to2==PRAVOUGAONIK) p2=*(struct Pravougaonik*)oblik2;
	else if (to2==TROUGAO) tr2=*(struct Trougao*)oblik2;
	
	
	if (to1==TACKA && to2==TACKA) {
		if (udaljenost_tacke(t1, t2)>eps) return 0;
	}
	
	else if (to1==TACKA && to2==KRUZNICA) {
		if (fabs(k2.centar.x-t1.x)>eps || fabs(k2.centar.y-t1.y)>eps || k2.radijus>eps) return 0;
	}
	
	else if (to1==TACKA && to2==PRAVOUGAONIK) {
		if (udaljenost_tacke(t1, p2.donji_lijevi)>eps || p2.visina!=0 || p2.sirina!=0) return 0;
	}
	
	else if (to1==TACKA && to2==TROUGAO) {
		if (udaljenost_tacke(t1, tr2.vrh1)>eps || udaljenost_tacke(t1, tr2.vrh2)>eps || udaljenost_tacke(t1, tr2.vrh3)>eps) return 0;
	}
	
	else if (to1==KRUZNICA && to2==TACKA) {
		if (udaljenost_tacke(k1.centar, t2)-k1.radijus>eps) return 0;
	}
	
	else if (to1==PRAVOUGAONIK && to2==TACKA) {
		return pripadnost_tacke_pravougaoniku(t2, p1);
	}
	
	else if (to1==TROUGAO && to2==TACKA) {
		return pripadnost_tacke_trouglu(t2, tr1);
	}
	
	else if (to1==PRAVOUGAONIK && to2==KRUZNICA) {
		if (k2.centar.x+k2.radijus>p1.donji_lijevi.x+p1.sirina || k2.centar.x+k2.radijus<p1.donji_lijevi.x || k2.centar.y+k2.radijus>p1.donji_lijevi.y+p1.visina || k2.centar.y+k2.radijus<p1.donji_lijevi.y) return 0;
	}
	
	else if (to1==KRUZNICA && to2==PRAVOUGAONIK) {
		gornji_desni.x=p2.donji_lijevi.x+p2.sirina;
		gornji_desni.y=p2.donji_lijevi.y+p2.visina;
		gornji_lijevi.x=p2.donji_lijevi.x;
		gornji_lijevi.y=gornji_desni.y;
		donji_desni.x=gornji_desni.x;
		donji_desni.y=p2.donji_lijevi.y;
		if (udaljenost_tacke(p2.donji_lijevi, k1.centar)>k1.radijus || udaljenost_tacke(gornji_desni, k1.centar)>k1.radijus || udaljenost_tacke(gornji_lijevi, k1.centar)>k1.radijus || udaljenost_tacke(donji_desni, k1.centar)>k1.radijus) return 0;
	}
	
	else if (to1==KRUZNICA && to2==TROUGAO) {
		if (udaljenost_tacke(k1.centar, tr2.vrh1)>k1.radijus || udaljenost_tacke(k1.centar, tr2.vrh2)>k1.radijus || udaljenost_tacke(k1.centar, tr2.vrh3)>k1.radijus) return 0;
	}
	
	else if (to1==TROUGAO && to2==KRUZNICA) {
		if (2*povrsina_trougla(k2.centar, tr1.vrh1, tr1.vrh2)/udaljenost_tacke(tr1.vrh1, tr1.vrh2)<k2.radijus) return 0;
		if (2*povrsina_trougla(k2.centar, tr1.vrh1, tr1.vrh3)/udaljenost_tacke(tr1.vrh1, tr1.vrh3)<k2.radijus) return 0;
		if (2*povrsina_trougla(k2.centar, tr1.vrh2, tr1.vrh3)/udaljenost_tacke(tr1.vrh2, tr1.vrh3)<k2.radijus) return 0; 
	}
	
	else if (to1==PRAVOUGAONIK && to2==TROUGAO) {
		if (pripadnost_tacke_pravougaoniku(tr2.vrh1, p1)==0 || pripadnost_tacke_pravougaoniku(tr2.vrh2, p1)==0 || pripadnost_tacke_pravougaoniku(tr2.vrh3, p1)==0) return 0; 
	}
	
	else if (to1==TROUGAO && to2==PRAVOUGAONIK) {
		gornji_desni.x=p2.donji_lijevi.x+p2.sirina;
		gornji_desni.y=p2.donji_lijevi.y+p2.visina;
		gornji_lijevi.x=p2.donji_lijevi.x;
		gornji_lijevi.y=gornji_desni.y;
		donji_desni.x=gornji_desni.x;
		donji_desni.y=p2.donji_lijevi.y;
		if (pripadnost_tacke_trouglu(p2.donji_lijevi, tr1)==0 || pripadnost_tacke_trouglu(gornji_desni, tr1)==0 || pripadnost_tacke_trouglu(gornji_lijevi, tr1)==0 || pripadnost_tacke_trouglu(donji_desni, tr1)==0) return 0;
	}
	
	else if (to1==KRUZNICA && to2==KRUZNICA) {
		if (k1.radijus<udaljenost_tacke(k1.centar, k2.centar)+k2.radijus) return 0;
	}
	
	else if (to1==PRAVOUGAONIK && to2==PRAVOUGAONIK) {
		if (p2.donji_lijevi.x<p1.donji_lijevi.x || p2.donji_lijevi.y<p1.donji_lijevi.y) return 0;
		if (p2.donji_lijevi.x+p2.sirina>p1.donji_lijevi.x+p1.sirina || p2.donji_lijevi.y+p2.visina>p1.donji_lijevi.y+p1.visina) return 0;
	}
	
	else if (to1==TROUGAO && to2==TROUGAO) {
		if (pripadnost_tacke_trouglu(tr2.vrh1, tr1)==0 || pripadnost_tacke_trouglu(tr2.vrh2, tr1)==0 || pripadnost_tacke_trouglu(tr2.vrh3, tr1)==0) return 0;
	}
	
	return 1;
}

/* Funkcije za unos: */
struct Tacka unos_tacke() {
	struct Tacka t;
	printf("koordinate x,y: ");
	scanf("%f,%f", &t.x, &t.y);
	return t;
}

struct Kruznica unos_kruznice() {
	struct Kruznica k;
	printf("Unesite centar kruznice: ");
	k.centar=unos_tacke();
	printf("Unesite poluprecnik kruznice: ");
	scanf("%f", &k.radijus);
	return k;
}

struct Pravougaonik unos_pravougaonika() {
	struct Pravougaonik p;
	printf("Unesite donji lijevi ugao: ");
	p.donji_lijevi=unos_tacke();
	printf("Unesite sirinu: ");
	scanf("%d", &p.sirina);
	printf("Unesite visinu: ");
	scanf("%d", &p.visina);
	return p;
}

struct Trougao unos_trougla() {
	struct Trougao tr;
	printf("Unesite prvi vrh: ");
	tr.vrh1=unos_tacke();
	printf("Unesite drugi vrh: ");
	tr.vrh2=unos_tacke();
	printf("Unesite treci vrh: ");
	tr.vrh3=unos_tacke();
	return tr;
}

int main() {
	int n, i, j, a;
	void* oblik[50];
	struct Tacka t[50];
	int broj_t=0;
	struct Kruznica k[50];
	int broj_k=0;
	struct Pravougaonik p[50];
	int broj_p=0;
	struct Trougao tr[50];
	int broj_tr=0;
	enum TipOblika tip[50];
	do {
		printf ("Unesite broj oblika: ");
		scanf("%d", &n);
	} while (n<0 || n>50);
	
	for (i=0; i<n; i++) {
		printf("Odaberite tip %d. oblika (1 - tacka, 2 - kruznica, 3 - pravougaonik, 4 - trougao): ", i+1);
		scanf("%d", &a);
		if(a<1 || a>4) {
			printf("Nepoznat tip oblika %d!\n", a);
			i--;
		}
		
		else if (a==1) {
			printf("Unesite tacku: ");
			t[broj_t]=unos_tacke();
			oblik[i]=&t[broj_t];
			broj_t++;
			tip[i]=TACKA;
		}
		else if (a==2) {
			k[broj_k]=unos_kruznice();
			oblik[i]=&k[broj_k];
			broj_k++;
			tip[i]=KRUZNICA;
		}
		else if (a==3) {
			p[broj_p]=unos_pravougaonika();
			oblik[i]=&p[broj_p];
			broj_p++;
			tip[i]=PRAVOUGAONIK;
		}
		else if (a==4) {
			tr[broj_tr]=unos_trougla();
			oblik[i]=&tr[broj_tr];
			broj_tr++;
			tip[i]=TROUGAO;
		}
		
	}
	
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			if (i!=j && obuhvata(oblik[i], tip[i], oblik[j], tip[j])) printf("\nOblik %d obuhvata oblik %d.", i+1, j+1);
		}
	}
	return 0;
}

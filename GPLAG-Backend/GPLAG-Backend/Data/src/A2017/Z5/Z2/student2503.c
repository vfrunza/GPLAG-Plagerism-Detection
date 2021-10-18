#include <stdio.h>
#include <math.h>
#define epsilon 0.001

/* Strukture osnovnih elemenata*/
struct Tacka {
	float x,y;
};
struct Kruznica {
	struct Tacka centar;
	float radijus;
};
struct Pravougaonik {
	struct Tacka dole_lijevo;
	float sirina;
	float visina;
};
struct Trougao {
	struct Tacka prvi_vrh;
	struct Tacka drugi_vrh;
	struct Tacka treci_vrh;
};

/* Funkcije za unos */
struct Tacka unos_tacke ()
{
	struct Tacka t;
	printf ("koordinate x,y: ");
	scanf ("%f,%f", &t.x, &t.y);
	return t;
}
struct Kruznica unos_kruznice()
{
	struct Kruznica k;
	printf ("Unesite centar kruznice: ");
	k.centar = unos_tacke();
	printf ("Unesite poluprecnik kruznice: ");
	scanf("%f", &k.radijus);
	return k;
}
struct Pravougaonik unos_pravougaonika()
{
	struct Pravougaonik p;
	printf("Unesite donji lijevi ugao: ");
	p.dole_lijevo=unos_tacke();
	printf("Unesite sirinu: ");
	scanf("%f",&p.sirina);
	printf("Unesite visinu: ");
	scanf("%f",&p.visina);
	return p;
}
struct Trougao unos_trougla()
{
	struct Trougao tr;
	printf("Unesite prvi vrh: ");
	tr.prvi_vrh=unos_tacke();
	printf("Unesite drugi vrh: ");
	tr.drugi_vrh=unos_tacke();
	printf("Unesite treci vrh: ");
	tr.treci_vrh=unos_tacke();
	return tr;
}
/* Funkcija za udaljenost izmedju dvije tacke koristeci koordinate tih tacaka*/
float udaljenost(float x1,float y1,float x2,float y2)
{
	return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}
/*Funkcija koja racuna povrsinu trougla datog preko koordinata vrhova*/
float povrsina(float x1, float y1, float x2, float y2, float x3, float y3)
{
	return (fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)))/2.;
}
/*Funkcija koja racuna diskriminantu kvadratne jednacine koja se dobije rjesavanje sistema jednacina prave i kruznice u ravni*/
float diskriminanta(float x1,float y1,float x2,float y2,float xc,float yc,float r)
{
	return (2.*(((y2-y1)/(x2-x1))*((y1-x1*((y2-y1)/(x2-x1)))-yc)-xc))*(2.*(((y2-y1)/(x2-x1))*((y1-x1*((y2-y1)/(x2-x1)))-yc)-xc))-4.*(1+((y2-y1)/(x2-x1))*((y2-y1)/(x2-x1)))*(((y1-x1*((y2-y1)/(x2-x1)))-yc)*((y1-x1*((y2-y1)/(x2-x1)))-yc)+xc*xc-r*r);
}
/*pobrojni tip "TipOblika" */
enum TipOblika { TACKA, KRUZNICA, PRAVOUGAONIK, TROUGAO };

/* funckija za provjeru da li jedan element obuhvata drugi */
int obuhvata(void* oblik1, enum TipOblika to1, void* oblik2, enum TipOblika to2)
{
	struct Tacka* t1 = (struct Tacka*) oblik1;
	struct Tacka* t2 = (struct Tacka*) oblik2;
	struct Kruznica* k1 = (struct Kruznica*) oblik1;
	struct Kruznica* k2 = (struct Kruznica*) oblik2;
	struct Pravougaonik* p1=(struct Pravougaonik*) oblik1;
	struct Pravougaonik* p2 = (struct Pravougaonik*) oblik2;
	struct Trougao *tr1=(struct Trougao*) oblik1;
	struct Trougao* tr2 = (struct Trougao*) oblik2;

	/*Tacka obuhvata tacku ako se poklapaju*/
	if(to1==TACKA && to2==TACKA && fabs(t1->x-t2->x)<epsilon && fabs(t1->y-t2->y)<epsilon) return 1;
	/*Tacka obuhvata kruznicu ako je kruznica poluprecnika 0, a centar kruznice se poklapa s tackom*/
	else if(to1==TACKA && to2==KRUZNICA && fabs(t1->x-k2->centar.x)<epsilon && fabs(t1->y-k2->centar.y)<epsilon && k2->radijus<epsilon && k2->radijus>-epsilon) return 1;
	/*Tacka obuhvata pravougaonik ako se tacka poklapa s donjim lijevim uglom pravougaonika a dimenzije pravougaonika su nula*/
	else if(to1==TACKA && to2==PRAVOUGAONIK && fabs(t1->x-p2->dole_lijevo.x)<epsilon && fabs(t1->y-p2->dole_lijevo.y)<epsilon && p2->sirina<epsilon && p2->sirina>-epsilon && p2->visina<epsilon && p2->visina>-epsilon) return 1;
	/*Tacka obuhvata trougao ako se koordinate svih vrhova trougla poklapaju s koordinatama tacke*/
	else if(to1==TACKA && to2==TROUGAO && fabs(t1->x-tr2->prvi_vrh.x)<epsilon && fabs(t1->y-tr2->prvi_vrh.y)<epsilon && fabs(t1->x-tr2->drugi_vrh.x)<epsilon && fabs(t1->y-tr2->drugi_vrh.y)<epsilon && fabs(t1->x-tr2->treci_vrh.x)<epsilon && fabs(t1->y-tr2->treci_vrh.y)<epsilon) return 1;
	/*Kruznica obuhvata tacku ako je udaljenost tacke od centra kruznice manja ili jednaka poluprecniku kruznice*/
	else if(to1==KRUZNICA && to2==TACKA && (k1->radijus-udaljenost(k1->centar.x,k1->centar.y,t2->x,t2->y))>-epsilon) return 1;
	/*Kruznica obuhvata kruznicu ako je poluprecnik kruznice 1 veci ili jednak od zbira poluprecnika kruznice 2 i udaljenosti izmedju centara*/
	else if(to1==KRUZNICA && to2==KRUZNICA && (k1->radijus-(k2->radijus+udaljenost(k1->centar.x,k1->centar.y,k2->centar.x,k2->centar.y)))>-epsilon) return 1;
	/*Kruznica obuhvata pravougaonik ako je svaki vrh pravougaonika unutar kruznice, a da li je vrh unutar kruznice provjeravamo kao u slucaju kruznica-tacka*/
	else if(to1==KRUZNICA && to2==PRAVOUGAONIK && (k1->radijus-udaljenost(k1->centar.x,k1->centar.y,p2->dole_lijevo.x,p2->dole_lijevo.y))>-epsilon && (k1->radijus-udaljenost(k1->centar.x,k1->centar.y,p2->dole_lijevo.x+p2->sirina,p2->dole_lijevo.y))>-epsilon && (k1->radijus-udaljenost(k1->centar.x,k1->centar.y,p2->dole_lijevo.x+p2->sirina,p2->dole_lijevo.y+p2->visina))>-epsilon && (k1->radijus-udaljenost(k1->centar.x,k1->centar.y,p2->dole_lijevo.x,p2->dole_lijevo.y+p2->visina))>-epsilon) return 1;
	/*Kruznica obuhvata trougao ako je svaki vrh trougala unutar kruznice, a to provjeravamo kao u slucaju kruznica-tacka*/
	else if(to1==KRUZNICA && to2==TROUGAO && (k1->radijus-udaljenost(k1->centar.x,k1->centar.y,tr2->prvi_vrh.x,tr2->prvi_vrh.y))>-epsilon && (k1->radijus-udaljenost(k1->centar.x,k1->centar.y,tr2->drugi_vrh.x,tr2->drugi_vrh.y))>-epsilon && (k1->radijus-udaljenost(k1->centar.x,k1->centar.y,tr2->treci_vrh.x,tr2->treci_vrh.y))>-epsilon) return 1;
	/*Pravougaonik obuhvata tacku ako je x koordinata tacke izmedju donjeg lijevog ugla i donjeg desnog ugla; Na isti nacin funkcionise i za y koordinatu tacke*/
	else if(to1==PRAVOUGAONIK && to2==TACKA && (t2->x-p1->dole_lijevo.x)>-epsilon && (p1->dole_lijevo.x+p1->sirina-t2->x)>-epsilon && (t2->y-p1->dole_lijevo.y)>-epsilon && (p1->dole_lijevo.y+p1->visina-t2->y)>-epsilon) return 1;
	/*Pravougaonik obuhvata kruznicu ako su tacke : "najniza, najvisa, najljevlja, najdesnija" unutar pravougaonika; Da li je tacka unutar pravougaonika provjeravamo kao u slucaju pravougaonik-tacka*/
	else if(to1==PRAVOUGAONIK && to2==KRUZNICA && (p1->dole_lijevo.y+p1->visina-(k2->centar.y+k2->radijus))>-epsilon && (p1->dole_lijevo.x+p1->sirina-(k2->centar.x+k2->radijus))>-epsilon && ((k2->centar.x-k2->radijus)-p1->dole_lijevo.x)>-epsilon && ((k2->centar.y-k2->radijus)-p1->dole_lijevo.y)>-epsilon) return 1;
	/*Pravougaonik obuhvata pravougaonik ako su cetiri vrha pravougaonika 2 unutar pravougaonika 1; Vrhove provjeravamo kao u slucaju pravougaonik-tacka*/
	else if(to1==PRAVOUGAONIK && to2==PRAVOUGAONIK && (p2->dole_lijevo.x-p1->dole_lijevo.x)>-epsilon && ((p1->dole_lijevo.x+p1->sirina)-(p2->dole_lijevo.x-p2->sirina))>-epsilon && (p2->dole_lijevo.y-p1->dole_lijevo.y)>-epsilon && ((p1->dole_lijevo.y+p1->visina)-(p2->dole_lijevo.y-p2->visina))>-epsilon) return 1;
	/*Pravougaonik obuhvata trougao ako su sva tri vrha trougla unutar pravougaonika;*/
	else if(to1==PRAVOUGAONIK && to2==TROUGAO && ((tr2->prvi_vrh.x-p1->dole_lijevo.x)>-epsilon && ((p1->dole_lijevo.x+p1->sirina)-tr2->prvi_vrh.x)>-epsilon && (tr2->prvi_vrh.y-p1->dole_lijevo.y)>-epsilon && ((p1->dole_lijevo.y+p1->visina)-tr2->prvi_vrh.y)>-epsilon) && ((tr2->drugi_vrh.x-p1->dole_lijevo.x)>-epsilon && ((p1->dole_lijevo.x+p1->sirina)-tr2->drugi_vrh.x)>-epsilon && (tr2->drugi_vrh.y-p1->dole_lijevo.y)>-epsilon && ((p1->dole_lijevo.y+p1->visina)-tr2->drugi_vrh.y)>-epsilon) && ((tr2->treci_vrh.x-p1->dole_lijevo.x)>-epsilon && ((p1->dole_lijevo.x+p1->sirina)-tr2->treci_vrh.x)>-epsilon && (tr2->treci_vrh.y-p1->dole_lijevo.y)>-epsilon && ((p1->dole_lijevo.y+p1->visina)-tr2->treci_vrh.y)>-epsilon)) return 1;
	/*Trougao obuhvata tacku ako je povrsina trougla jednaka zbriru povrsina trouglova koje formiramo tackama (tacka2 i 2 od tri vrha trougla)*/
	else if(to1==TROUGAO && to2==TACKA && fabs(povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,tr1->treci_vrh.x,tr1->treci_vrh.y)-povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,t2->x,t2->y)-povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,t2->x,t2->y,tr1->treci_vrh.x,tr1->treci_vrh.y)-povrsina(t2->x,t2->y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,tr1->treci_vrh.x,tr1->treci_vrh.y))<epsilon) return 1;
	/*Trougao obuhvata pravougaonik ako su sva cetiri vrha pravougaonika unutar trougla*/
	else if(to1==TROUGAO && to2==PRAVOUGAONIK && fabs(povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,tr1->treci_vrh.x,tr1->treci_vrh.y)-povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,p2->dole_lijevo.x,p2->dole_lijevo.y)-povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,p2->dole_lijevo.x,p2->dole_lijevo.y,tr1->treci_vrh.x,tr1->treci_vrh.y)-povrsina(p2->dole_lijevo.x,p2->dole_lijevo.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,tr1->treci_vrh.x,tr1->treci_vrh.y))<epsilon && fabs(povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,tr1->treci_vrh.x,tr1->treci_vrh.y)-povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,p2->dole_lijevo.x+p2->sirina,p2->dole_lijevo.y)-povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,p2->dole_lijevo.x+p2->sirina,p2->dole_lijevo.y,tr1->treci_vrh.x,tr1->treci_vrh.y)-povrsina(p2->dole_lijevo.x+p2->sirina,p2->dole_lijevo.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,tr1->treci_vrh.x,tr1->treci_vrh.y))<epsilon && fabs(povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,tr1->treci_vrh.x,tr1->treci_vrh.y)-povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,p2->dole_lijevo.x,p2->dole_lijevo.y+p2->visina)-povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,p2->dole_lijevo.x,p2->dole_lijevo.y+p2->visina,tr1->treci_vrh.x,tr1->treci_vrh.y)-povrsina(p2->dole_lijevo.x,p2->dole_lijevo.y+p2->visina,tr1->drugi_vrh.x,tr1->drugi_vrh.y,tr1->treci_vrh.x,tr1->treci_vrh.y))<epsilon && fabs(povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,tr1->treci_vrh.x,tr1->treci_vrh.y)-povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,p2->dole_lijevo.x+p2->sirina,p2->dole_lijevo.y+p2->visina)-povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,p2->dole_lijevo.x+p2->sirina,p2->dole_lijevo.y+p2->visina,tr1->treci_vrh.x,tr1->treci_vrh.y)-povrsina(p2->dole_lijevo.x+p2->sirina,p2->dole_lijevo.y+p2->visina,tr1->drugi_vrh.x,tr1->drugi_vrh.y,tr1->treci_vrh.x,tr1->treci_vrh.y))<epsilon) return 1;
	/*Trougao obuhvata kruznicu ako su cetiri "bitne" tacke kruznice prethodno navedene unutar trougla, s tim sto jos nijedna stranica trougla ne smije sjeci kruznicu, to provjeracamo uslovom zajednicikih tacaka prave na kojoj lezi stranica trougla i kruznice*/
	else if(to1==TROUGAO && to2==KRUZNICA && fabs(povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,tr1->treci_vrh.x,tr1->treci_vrh.y)-povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,k2->centar.x,k2->centar.y-k2->radijus)-povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,k2->centar.x,k2->centar.y-k2->radijus,tr1->treci_vrh.x,tr1->treci_vrh.y)-povrsina(k2->centar.x,k2->centar.y-k2->radijus,tr1->drugi_vrh.x,tr1->drugi_vrh.y,tr1->treci_vrh.x,tr1->treci_vrh.y))<epsilon && fabs(povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,tr1->treci_vrh.x,tr1->treci_vrh.y)-povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,k2->centar.x,k2->centar.y+k2->radijus)-povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,k2->centar.x,k2->centar.y+k2->radijus,tr1->treci_vrh.x,tr1->treci_vrh.y)-povrsina(k2->centar.x,k2->centar.y+k2->radijus,tr1->drugi_vrh.x,tr1->drugi_vrh.y,tr1->treci_vrh.x,tr1->treci_vrh.y))<epsilon && fabs(povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,tr1->treci_vrh.x,tr1->treci_vrh.y)-povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,k2->centar.x+k2->radijus,k2->centar.y)-povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,k2->centar.x+k2->radijus,k2->centar.y,tr1->treci_vrh.x,tr1->treci_vrh.y)-povrsina(k2->centar.x+k2->radijus,k2->centar.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,tr1->treci_vrh.x,tr1->treci_vrh.y))<epsilon && fabs(povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,tr1->treci_vrh.x,tr1->treci_vrh.y)-povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,k2->centar.x-k2->radijus,k2->centar.y)-povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,k2->centar.x-k2->radijus,k2->centar.y,tr1->treci_vrh.x,tr1->treci_vrh.y)-povrsina(k2->centar.x-k2->radijus,k2->centar.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,tr1->treci_vrh.x,tr1->treci_vrh.y))<epsilon && diskriminanta(tr1->prvi_vrh.x,tr1->prvi_vrh.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,k2->centar.x,k2->centar.y,k2->radijus)<epsilon &&  diskriminanta(tr1->drugi_vrh.x,tr1->drugi_vrh.y,tr1->treci_vrh.x,tr1->treci_vrh.y,k2->centar.x,k2->centar.y,k2->radijus)<epsilon &&  diskriminanta(tr1->treci_vrh.x,tr1->treci_vrh.y,tr1->prvi_vrh.x,tr1->prvi_vrh.y,k2->centar.x,k2->centar.y,k2->radijus)<epsilon) return 1;
	/*Trougao obuhvata trougao ako su svi vrhovi trougla 2 unutar trougla 1*/
	else if(to1==TROUGAO && to2==TROUGAO && fabs(povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,tr1->treci_vrh.x,tr1->treci_vrh.y)-povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,tr2->prvi_vrh.x,tr2->prvi_vrh.y)-povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,tr2->prvi_vrh.x,tr2->prvi_vrh.y,tr1->treci_vrh.x,tr1->treci_vrh.y)-povrsina(tr2->prvi_vrh.x,tr2->prvi_vrh.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,tr1->treci_vrh.x,tr1->treci_vrh.y))<epsilon && fabs(povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,tr1->treci_vrh.x,tr1->treci_vrh.y)-povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,tr2->drugi_vrh.x,tr2->drugi_vrh.y)-povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,tr2->drugi_vrh.x,tr2->drugi_vrh.y,tr1->treci_vrh.x,tr1->treci_vrh.y)-povrsina(tr2->drugi_vrh.x,tr2->drugi_vrh.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,tr1->treci_vrh.x,tr1->treci_vrh.y))<epsilon && fabs(povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,tr1->treci_vrh.x,tr1->treci_vrh.y)-povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,tr2->treci_vrh.x,tr2->treci_vrh.y)-povrsina(tr1->prvi_vrh.x,tr1->prvi_vrh.y,tr2->treci_vrh.x,tr2->treci_vrh.y,tr1->treci_vrh.x,tr1->treci_vrh.y)-povrsina(tr2->treci_vrh.x,tr2->treci_vrh.y,tr1->drugi_vrh.x,tr1->drugi_vrh.y,tr1->treci_vrh.x,tr1->treci_vrh.y))<epsilon) return 1;
	/*U svim ostalim slucajevima, oblik1 ne obuhvata oblik2*/
	else return 0;
}
int main()
{
	int i=0,j=0,n=0;
	int niz[50]= {0};
	struct Tacka t[50];
	struct Kruznica k[50];
	struct Pravougaonik p[50];
	struct Trougao tr[50];
	printf("Unesite broj oblika: ");
	do {
		scanf("%d",&n);
	} while(n>50 || n<0);
	for(i=0; i<n; i++) {
		printf("Odaberite tip %d. oblika (1 - tacka, 2 - kruznica, 3 - pravougaonik, 4 - trougao): ",i+1);
		scanf("%d",&j);
		if(j>4 || j<1) {
			printf("Nepoznat tip oblika %d!\n",j);
			i--; /*Smanjujemo brojac da bi ponovo mogli koristiti isti broj jer je ovo bio prazan hod*/
			continue;
			/* Unosimo odgovarajuce elemente pozivajuci funkcije*/
		} else if (j==1) {
			niz[i]=0;
			printf("Unesite tacku: ");
			t[i]=unos_tacke();
		} else if(j==2) {
			niz[i]=1;
			k[i]=unos_kruznice();
		} else if(j==3) {
			niz[i]=2;
			p[i]=unos_pravougaonika();
		} else if(j==4) {
			niz[i]=3;
			tr[i]=unos_trougla();
		}
	}
	for(i=0; i<n; i++) {
		if(niz[i]==0) {
			for(j=0; j<n; j++) {
				if(j==i) continue;
				else {
					/* U tipu enum, odgovarajuci oblici imaju odgovarajuce brojeve krenuvis od 0 pa do 3*/
					if(niz[j]==0) {
						if(obuhvata(&t[i],0,&t[j],0)) printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					} else if(niz[j]==1) {
						if(obuhvata(&t[i],0,&k[j],1)) printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					} else if(niz[j]==2) {
						if(obuhvata(&t[i],0,&p[j],2)) printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					} else if(niz[j]==3) {
						if(obuhvata(&t[i],0,&tr[j],3)) printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					}
				}
			}
		} else if(niz[i]==1) {
			for(j=0; j<n; j++) {
				if(j==i) continue;
				else {
					if(niz[j]==0) {
						if(obuhvata(&k[i],1,&t[j],0)) printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					} else if(niz[j]==1) {
						if(obuhvata(&k[i],1,&k[j],1)) printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					} else if(niz[j]==2) {
						if(obuhvata(&k[i],1,&p[j],2)) printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					} else if(niz[j]==3) {
						if(obuhvata(&k[i],1,&tr[j],3)) printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					}
				}
			}
		} else if(niz[i]==2) {
			for(j=0; j<n; j++) {
				if(j==i) continue;
				else {
					if(niz[j]==0) {
						if(obuhvata(&p[i],2,&t[j],0)) printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					} else if(niz[j]==1) {
						if(obuhvata(&p[i],2,&k[j],1)) printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					} else if(niz[j]==2) {
						if(obuhvata(&p[i],2,&p[j],2)) printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					} else if(niz[j]==3) {
						if(obuhvata(&p[i],2,&tr[j],3)) printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					}
				}
			}
		} else if(niz[i]==3) {
			for(j=0; j<n; j++) {
				if(j==i) continue;
				else {
					if(niz[j]==0) {
						if(obuhvata(&tr[i],3,&t[j],0)) printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					} else if(niz[j]==1) {
						if(obuhvata(&tr[i],3,&k[j],1)) printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					} else if(niz[j]==2) {
						if(obuhvata(&tr[i],3,&p[j],2)) printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					} else if(niz[j]==3) {
						if(obuhvata(&tr[i],3,&tr[j],3)) printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					}
				}
			}
		}
	}
	return 0;
}

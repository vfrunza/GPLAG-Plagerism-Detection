#include <stdio.h>
#include <math.h>
#define epsilon 0.001

enum TipOblika{TACKA, KRUZNICA, PRAVOUGAONIK, TROUGAO};

struct Tacka{
	float x,y;
};

struct Kruznica {
	struct Tacka centar;
	float radijus;
};

struct Pravougaonik{
	struct Tacka dole_lijevo;
	float sirina,visina;
};

struct Trougao{
	struct Tacka A;
	struct Tacka B;
	struct Tacka C;
};

struct Tacka unos_tacke(){
	struct Tacka t;
	printf("koordinate x,y: ");
	scanf ("%f,%f", &t.x, &t.y);
	return t;
}

struct Kruznica unos_kruznice() {
	struct Kruznica k;
	printf("Unesite centar kruznice: ");
	k.centar = unos_tacke();
	printf("Unesite poluprecnik kruznice: ");
	scanf("%f", &k.radijus);
	return k;
}

struct Pravougaonik unos_pravougaonika(){
	struct Pravougaonik p;
	printf("Unesite donji lijevi ugao: ");
	p.dole_lijevo = unos_tacke();
	printf("Unesite sirinu: ");
	scanf("%f", &p.sirina);
	printf("Unesite visinu: ");
	scanf("%f", &p.visina);
	return p;
}

struct Trougao unos_trougla(){
	struct Trougao tr;
	printf("Unesite prvi vrh: ");
	tr.A=unos_tacke();
	printf("Unesite drugi vrh: ");
	tr.B=unos_tacke();
	printf("Unesite treci vrh: ");
	tr.C=unos_tacke();
	return tr;
}

/*Funkcija koja racuna udaljenost izmedju dvije tacke*/
float udaljenost(struct Tacka t1, struct Tacka t2) {
	return sqrt( (t1.x-t2.x)*(t1.x-t2.x) + (t1.y-t2.y)*(t1.y-t2.y) );
}

/*Funkcija koja racuna povrsinu trougla*/
float povrsina(int x1, int y1, int x2, int y2, int x3, int y3)
{
   return fabs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

/*Neka su tacke trougla A(x1,y1), B(x2,y2) i C(x3,y3) i neka su koordinate tacke P(x,y)*/
int TackaPripadaTrouglu(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{   
/*Racunamo povrsinu trougla ABC*/
   float A = povrsina (x1, y1, x2, y2, x3, y3);
 
/*Racunamo povrsinu trougla PBC*/  
   float A1 = povrsina (x, y, x2, y2, x3, y3);
 
/*Racunamo povrsinu trougla PAC*/  
   float A2 = povrsina (x1, y1, x, y, x3, y3);
 
/*Racunamo povrsinu trougla PAB*/   
   float A3 = povrsina (x1, y1, x2, y2, x, y);
   
/*Ako je suma povrsina A1, A2 i A3 jednaka A onda tacka pripada trouglu */
   if(A == A1 + A2 + A3)return 1;
   else return 0;
}

int obuhvata(void* oblik1, enum TipOblika to1, void* oblik2, enum TipOblika to2){
	
	int d;
/*Figura obuhvata samu sebe*/	
	if(to1==to2)return 1;

/*Kruznica sadrzi tacku ako je udaljenost tacke od centra kruznice manja ili jednaka poluprecniku kruznice*/
	if(to1==KRUZNICA && to2==TACKA){
		struct Kruznica* k = (struct Kruznica*) oblik1;
		struct Tacka* t = (struct Tacka*) oblik2;
		d=udaljenost(*t, k->centar);
		if (d<=k->radijus)return 1;
	}

/*Pravougaonik obuhvata tacku ako su koordinate tacke vece od koordinata donjeg lijevog ugla i manje od koordinata gornjeg desnog ugla pravougaonika*/	
	if(to1==PRAVOUGAONIK && to2==TACKA){
		struct Pravougaonik* p = (struct Pravougaonik*) oblik1;
		struct Tacka* t = (struct Tacka*) oblik2;
		if(t->x>=p->dole_lijevo.x && t->x<=p->dole_lijevo.x+p->sirina && t->y>=p->dole_lijevo.y && t->y<=p->dole_lijevo.y+p->visina)return 1;
	
	}

/*Trougao obuhvata tacku*/
	if(to1==TROUGAO && to2==TACKA){
		struct Trougao* tr = (struct Trougao*) oblik1;
		struct Tacka* t = (struct Tacka*) oblik2;
		if(TackaPripadaTrouglu(tr->A.x,tr->A.y,tr->B.x,tr->B.y,tr->C.x,tr->C.y,t->x,t->y)==1)return 1;
	}

/*Tacka obuhvata kruznicu ako je radijus kruznice nula i ako su koordinate centra iste kao koordinate tacke*/
	if(to1==TACKA && to2==KRUZNICA){
		struct Tacka* t = (struct Tacka*) oblik1;
		struct Kruznica* k = (struct Kruznica*) oblik2;
		if(t->x==k->centar.x && t->y==k->centar.y && k->radijus==0)return 1;
	}

/*Pravougaonik obuhvata kruznicu ako donja lijeva i gornja desna tacka kruznice, dobivena presjekom kruznice i dijagonale koja prolazi kod cetar kruznice i coskove pravougaonika, su unutar pravougaonika*/
	if(to1==PRAVOUGAONIK && to2==KRUZNICA){
		struct Pravougaonik* p = (struct Pravougaonik*) oblik1;
		struct Kruznica* k = (struct Kruznica*) oblik2;
		if(k->centar.x-k->radijus>=p->dole_lijevo.x && k->centar.y-k->radijus>=p->dole_lijevo.y && k->centar.x+k->radijus<=p->dole_lijevo.x+p->sirina && k->centar.y+k->radijus<=p->dole_lijevo.y+p->visina)return 1;
	}

/*Tacka obuhvata pravogaonik ako su dimnezija pravougaonika nula i ako su koordinate donjeg lijevog ugla i tacke iste*/
	if(to1==TACKA && to2==PRAVOUGAONIK){
		struct Tacka* t = (struct Tacka*) oblik1;
		struct Pravougaonik* p = (struct Pravougaonik*) oblik2;
		if(t->x==p->dole_lijevo.x && t->y==p->dole_lijevo.y && p->sirina==0 && p->visina==0)return 1;
	}
 
/*Kruznica obuhvata pravougaonik ako su njegovi coskovi unutar kruznice*/ 
	if(to1==KRUZNICA && to2==PRAVOUGAONIK){
		struct Kruznica* k = (struct Kruznica*) oblik1;
		struct Pravougaonik* p = (struct Pravougaonik*) oblik2;
		if(p->dole_lijevo.x>=k->centar.x-k->radijus && p->dole_lijevo.y>=k->centar.y-k->radijus && p->dole_lijevo.x+p->sirina<=k->centar.x+k->radijus && p->dole_lijevo.y+p->visina<=k->centar.y+k->radijus)return 1;
	} 
	
/*Tacka obuhvata trougao ako su koordinate sve tri tacke trougla iste kao koordinate tacke*/	
	if(to1==TACKA && to2==TROUGAO){
		struct Tacka* t = (struct Tacka*) oblik1;
		struct Trougao* tr = (struct Trougao*) oblik2;
		if(t->x==tr->A.x && t->y==tr->A.y && t->x==tr->B.x && t->y==tr->B.y && t->x==tr->C.x && t->y==tr->C.y )return 1;
	}
	
/*Pravougaonik obuhvata trougao ako su koordinate sve tri tacke vece od koordinate donjeg lijevog i gornjeg desnog coska pravougaonika*/	
	if(to1==PRAVOUGAONIK && to2==TROUGAO){
		struct Pravougaonik* p = (struct Pravougaonik*) oblik1;
		struct Trougao* tr = (struct Trougao*) oblik2;
		if((tr->A.x || tr->B.x || tr->C.x)>=p->dole_lijevo.x && (tr->A.y || tr->B.y || tr->C.y)>=p->dole_lijevo.y && (tr->A.x || tr->B.x || tr->C.x)<=p->dole_lijevo.x+p->sirina && (tr->A.y || tr->B.y || tr->C.y)<=p->dole_lijevo.y+p->visina)return 1;
	}
	
	return 0;
}


int main() {
	enum TipOblika{TACKA, KRUZNICA, PRAVOUGAONIK, TROUGAO};
	int i=0,j=0,k=0,l=0,m=0,broj_oblika,tip[50];
	struct Tacka tacke[50];
	struct Kruznica kruznice[50];
	struct Pravougaonik pravougaonici[50];
	struct Trougao trouglovi[50];

	printf("Unesite broj oblika: ");
	scanf("%d", &broj_oblika);
	
	for(i=0;i<broj_oblika;i++){
		printf("Odaberite tip %d. oblika (1 - tacka, 2 - kruznica, 3 - pravougaonik, 4 - trougao): ",i+1);
		scanf("%d", &tip[i]);
		if(tip[i]!=1 && tip[i]!=2 && tip[i]!=3 && tip[i]!=4){
			printf("Nepoznat tip oblika 5!\n");
			i--;
			continue;
		}
		if(tip[i]==1){
			printf("Unesite tacku: ");
			tacke[j++]=unos_tacke();
		}
		if(tip[i]==2){
			kruznice[k++]=unos_kruznice();
		}
		if(tip[i]==3){
			pravougaonici[l++]=unos_pravougaonika();
		}
		if(tip[i]==4){
			trouglovi[m++]=unos_trougla();
			
		}
	}
	
	return 0;
}

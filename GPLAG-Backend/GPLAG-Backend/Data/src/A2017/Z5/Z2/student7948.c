#include <stdio.h>
#define epsilon 0.001

struct Tacka{
	double x,y;
};

struct Kruznica{
	struct Tacka centar; 
	double poluprecnik;
};

struct Pravougaonik{
	struct Tacka donjaLijeva;
	double sirina,visina;	
};

struct Trougao{
	struct Tacka t1,t2,t3;	
};

enum TipOblika{TACKA,KRUZNICA,PRAVOUGAONIK,TROUGAO};

int obuhvata(void *oblik1,enum TipOblika to1,void *oblik2,enum TipOblika to2){
	struct Tacka gornjaLijeva,donjaDesna,gornjaDesna;
	if(to1==TACKA){
		struct Tacka *t1=(struct Tacka*)oblik1;
	}else if(to1==KRUZNICA){
		struct Kruznica *k1=(struct Kruznica*)oblik1;
	}else if(to1==PRAVOUGAONIK){
		struct Pravougaonik *p1=(struct Pravougaonik*)oblik1;
	}else if(to1==TROUGAO){
		struct Trougao *tr1=(struct Trougao*)oblik1;
	}
	if(to2==TACKA){
		struct Tacka *t2=(struct Tacka*)oblik2;
	}else if(to2==KRUZNICA){
		struct Kruznica *k2=(struct Kruznica*)oblik2;
	}else if(to2==PRAVOUGAONIK){
		struct Pravougaonik *p2=(struct Pravougaonik*)oblik2;
	}else if(to2==TROUGAO){
		struct Trougao *tr2=(struct Trougao*)oblik2;
	}
	if(to1==TACKA && to2==TACKA){
		if(t1->x==t2->x && t1->y==t2->y)return 1;
		return 0;
	}else if(to1==KRUZNICA && to2==TACKA){
		if( (t2.x-k1->centar.x)*(t2.x-k1->centar.x)+(t2.y-k1->centar.y)*(t2.y-k1->centar.y)<k1->poluprecnik )return 1;
		return 0;
	}else if(to1==PRAVOUGAONIK && to2==TACKA){
		gornjaLijeva.x=p1->donjaLijeva.x;
		gornjaLijeva.y=p1->donjaLijeva.y+p1->visina;
		donjaDesna.x=p1->donjaLijeva.x+p1->sirina;
		donjaDesna.y=p1->donjaDesna.y;
		if(p1->donjaLijeva.x<=t2.x && donjaDesna.x>=t2.x && donjaDesna.y<=t2.y && gornjaLijeva.y>=t2.y)return 1;
		return 0;
	}else if(to1==TROUGAO && to2==TACKA){
		
	}
	
}

int main() {
	struct Tacka t;
	struct Kruznica k;
	struct Pravougaonik p;
	struct Trougao tr;
	int n,odabir,i;
	printf("Unesite broj oblika: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Odaberite tip oblika (1 - tacka, 2 - kruznica, 3 - pravougaonik, 4 - trougao): ");
		scanf("%d",&odabir);
		if(odabir<=0 || odabir>4){
			printf("Nepoznat tip oblika %d!\n",odabir);
			i--;
			continue;
		}
		switch(odabir){
			case 1:
			printf("Unesite tacku: koordinate x,y: ");
			scanf("%lf %lf",&t.x,&t.y);
			break;
			case 2:
			printf("Unesite centar kruznice: koordinate x,y: ");
			scanf("%lf %lf",&k.centar.x,&k.centar.y);
			printf("Unesite poluprecnik kruznice: ");
			scanf("%lf",&k.poluprecnik);
			break;
			case 3:
			printf("Unesite donji lijevi ugao: koordinate x,y: ");
			scanf("%lf %lf",&p.donjaLijeva.x,&p.donjaLijeva.y);
			printf("Unesite sirinu: ");
			scanf("%lf",&p.sirina);
			printf("Unesite visinu: ");
			scanf("%lf",&p.visina);
			break;
			case 4:
			printf("Unesite prvi vrh: koordinate x,y: ");
			scanf("%lf %lf",&tr.t1.x,&tr.t1.y);
			printf("Unesite drugi vrh: koordinate x,y: ");
			scanf("%lf %lf",&tr.t2.x,&tr.t2.y);
			printf("Unesite treci vrh: koordinate x,y: ");
			scanf("%lf %lf",&tr.t3.x,&tr.t3.y);
			break;
		}
	}

	return 0;
}

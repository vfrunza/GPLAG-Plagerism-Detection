#include <stdio.h>
#include <math.h>
struct Tacka {
	float x;
	float y;
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
	struct Tacka tjeme1;
	struct Tacka tjeme2;
	struct Tacka tjeme3;
};

enum TipOblika { TACKA, KRUZNICA, PRAVOUGAONIK, TROUGAO };

float max(float t1,float t2,float t3)
{
	if(t1>=t2 && t1>=t3) return t1;
	if(t2>=t1 && t2>=t3) return t2;
	return t3;
}
float min(float t1,float t2,float t3)
{
	if(t1<=t2 && t1<=t3) return t1;
	if(t2<=t1 && t2<=t3) return t2;
	return t3;
}
struct Tacka unos_tacke()
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

float udaljenost(struct Tacka t1, struct Tacka t2)
{
	return sqrt( (t1.x-t2.x)*(t1.x-t2.x) + (t1.y-t2.y)*(t1.y-t2.y) );
}

struct Pravougaonik unos_pravugaonika()
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
	struct Trougao t;
	printf("Unesite prvi vrh: ");
	t.tjeme1=unos_tacke();
	printf("Unesite drugi vrh: ");
	t.tjeme2=unos_tacke();
	printf("Unesite treci vrh: ");
	t.tjeme3=unos_tacke();
	return t;
}
int obuhvata(void* oblik1,enum TipOblika to1,void* oblik2,enum TipOblika to2)
{
	struct Tacka* t1;
	struct Tacka* t2;
	struct Tacka*t3,*t;
	struct Tacka gore_desno;
	struct Tacka gore_desno2;
	struct Kruznica* k1;
	struct Kruznica* k2;
	struct Pravougaonik* p1;
	struct Pravougaonik* p2;
	struct Trougao* tr1;
	struct Trougao* tr2;
	float k,n,r,p,q;
	if(to1==TACKA && to2==TACKA) {
		t1=(struct Tacka*) oblik1;
		t2=(struct Tacka*) oblik2;
		if(fabs((t1->x) - (t2->x))<0.001 && fabs((t1->y) - (t2->y))<0.001) return 1;
	}
	if(to1==TACKA && to2==KRUZNICA) {
		t1=(struct Tacka*) oblik1;
		k1=(struct Kruznica*) oblik2;
		if((udaljenost(*t1,(k1->centar)))<0.001 && k1->radijus<0.001) return 1;
	}
	if(to1==KRUZNICA && to2==TACKA) {
		t1=(struct Tacka*) oblik2;
		k1=(struct Kruznica*) oblik1;
		if((udaljenost(*t1,k1->centar)<=k1->radijus)) return 1;
	}
	if(to1==TACKA && to2==PRAVOUGAONIK) {
		t1=(struct Tacka*) oblik1;
		p1=(struct Pravougaonik*) oblik2;
		if(p1->sirina<0.001 && p1->visina<0.001 && udaljenost(*t1,p1->dole_lijevo)<0.001) return 1;
	}
	if(to1==TACKA && to2==TROUGAO) {
		t1=(struct Tacka*) oblik1;
		tr1=(struct Trougao*) oblik2;
		if(udaljenost(*t1,tr1->tjeme1)<0.001 && udaljenost(*t1,tr1->tjeme2)<0.001 && udaljenost(*t1,tr1->tjeme3)<0.001) return 1;
	}
	if(to1==TROUGAO && to2==TACKA) {
		t=(struct Tacka*) oblik2;
		tr1=(struct Trougao*) oblik1;
		t1=&(tr1->tjeme1);
		t2=&(tr1->tjeme2);
		t3=&(tr1->tjeme3);
		if(t1->x*(t2->y-t3->y)-t2->x*(t1->y-t3->y)+t->x*(t1->y-t2->y)>=0 && t1->x*(t2->y-t->y)-t2->x*(t1->y-t->y)+t->x*(t1->y-t2->y)>=0 && t2->x*(t3->y-t->y)-t3->x*(t2->y-t->y)+t->x*(t2->y-t3->y)>=0 && t3->x*(t1->y-t->y)-t1->x*(t3->y-t->y)+t->x*(t3->y-t1->y)>=0) return 1;
		if(t1->x*(t2->y-t3->y)-t2->x*(t1->y-t3->y)+t->x*(t1->y-t2->y)<=0 && t1->x*(t2->y-t->y)-t2->x*(t1->y-t->y)+t->x*(t1->y-t2->y)<=0 && t2->x*(t3->y-t->y)-t3->x*(t2->y-t->y)+t->x*(t2->y-t3->y)<=0 && t3->x*(t1->y-t->y)-t1->x*(t3->y-t->y)+t->x*(t3->y-t1->y)<=0) return 1;
	}
	if(to1==PRAVOUGAONIK && to2==TACKA) {
		t1=(struct Tacka*) oblik2;
		p1=(struct Pravougaonik*) oblik1;
		gore_desno.x=((*p1).dole_lijevo.x)+(p1->sirina);
		gore_desno.y=((*p1).dole_lijevo.y)+(p1->visina);
		if((t1->x)<=(gore_desno.x) && (t1->x)>=((*p1).dole_lijevo.x) &&  (t1->y)<=(gore_desno.y) && (t1->y)>=((*p1).dole_lijevo.y)) return 1;
	}
	if(to1==KRUZNICA && to2==KRUZNICA) {
		k1=(struct Kruznica*) oblik1;
		k2=(struct Kruznica*) oblik2;
		if(udaljenost((*k1).centar,(*k2).centar)<=fabs((*k1).radijus-(*k2).radijus)) return 1;
	}
	if(to1==PRAVOUGAONIK && to2==TROUGAO) {
		p1=(struct Pravougaonik*) oblik1;
		tr1=(struct Trougao*) oblik2;
		gore_desno.x=((*p1).dole_lijevo.x+(p1->sirina));
		gore_desno.y=((*p1).dole_lijevo.y+(p1->visina));
		if(max((*tr1).tjeme1.x,(*tr1).tjeme2.x,(*tr1).tjeme3.x)<=gore_desno.x && max((*tr1).tjeme1.y,(*tr1).tjeme2.y,(*tr1).tjeme3.y)<=gore_desno.y)
			if(min((*tr1).tjeme1.x,(*tr1).tjeme2.x,(*tr1).tjeme3.x)>=(*p1).dole_lijevo.x && min((*tr1).tjeme1.y,(*tr1).tjeme2.y,(*tr1).tjeme3.y)>=(*p1).dole_lijevo.y)
				return 1;
	}
	if(to1==PRAVOUGAONIK && to2==PRAVOUGAONIK) {
		p1=(struct Pravougaonik*) oblik1;
		p2=(struct Pravougaonik*) oblik2;
		gore_desno.x=((*p1).dole_lijevo.x)+(p1->sirina);
		gore_desno.y=((*p1).dole_lijevo.y)+(p1->visina);
		gore_desno2.x=((*p2).dole_lijevo.x)+(p2->sirina);
		gore_desno2.y=((*p2).dole_lijevo.y)+(p2->visina);
		if(gore_desno.x>=gore_desno2.x && (*p1).dole_lijevo.x<=(*p2).dole_lijevo.x && gore_desno.y>=gore_desno2.y && (*p1).dole_lijevo.y<=(*p2).dole_lijevo.y) return 1;
	}
	if(to1==TROUGAO && to2==TROUGAO) {
		tr1=(struct Trougao*) oblik1;
		tr2=(struct Trougao*) oblik2;
		if(max((*tr1).tjeme1.x,(*tr1).tjeme2.x,(*tr1).tjeme3.x)>=max((*tr2).tjeme1.x,(*tr2).tjeme2.x,(*tr2).tjeme3.x))
			if(max((*tr1).tjeme1.y,(*tr1).tjeme2.y,(*tr1).tjeme3.y)>=max((*tr2).tjeme1.y,(*tr2).tjeme2.y,(*tr2).tjeme3.y))
				if(min((*tr1).tjeme1.x,(*tr1).tjeme2.x,(*tr1).tjeme3.x)<=min((*tr1).tjeme1.x,(*tr1).tjeme2.x,(*tr1).tjeme3.x))
					if(min((*tr1).tjeme1.y,(*tr1).tjeme2.y,(*tr1).tjeme3.y)<=min((*tr2).tjeme1.y,(*tr2).tjeme2.y,(*tr2).tjeme3.y))
						return 1;
	}
	if(to1==PRAVOUGAONIK && to2==KRUZNICA) {
		p1=(struct Pravougaonik*) oblik1;
		k1=(struct Kruznica*) oblik2;
		gore_desno.x=((*p1).dole_lijevo.x)+(p1->sirina);
		gore_desno.y=((*p1).dole_lijevo.y)+(p1->visina);
		p=(*k1).centar.x;
		q=(*k1).centar.y;
		r=k1->radijus;
		if(p+r<=gore_desno.x && q+r<=gore_desno.y && p-r>=(*p1).dole_lijevo.x && q-r>=(*p1).dole_lijevo.y) return 1;
	}
	if(to1==TROUGAO && to2==PRAVOUGAONIK) {
		p1=(struct Pravougaonik*) oblik2;
		tr1=(struct Trougao*) oblik1;
		gore_desno.x=((*p1).dole_lijevo.x+(p1->sirina));
		gore_desno.y=((*p1).dole_lijevo.y+(p1->visina));
		if(max((*tr1).tjeme1.x,(*tr1).tjeme2.x,(*tr1).tjeme3.x)>=gore_desno.x && max((*tr1).tjeme1.y,(*tr1).tjeme2.y,(*tr1).tjeme3.y)>=gore_desno.y)
			if(min((*tr1).tjeme1.x,(*tr1).tjeme2.x,(*tr1).tjeme3.x)<=(*p1).dole_lijevo.x && min((*tr1).tjeme1.y,(*tr1).tjeme2.y,(*tr1).tjeme3.y)<=(*p1).dole_lijevo.y)
				return 1;
	}
	if(to1==TROUGAO && to2==KRUZNICA) {
		tr1=(struct Trougao*) oblik1;
		k1=(struct Kruznica*) oblik2;
		k=((*tr1).tjeme2.y-(*tr1).tjeme1.y)/((*tr1).tjeme2.x-(*tr1).tjeme1.x);
		n=((-(*tr1).tjeme1.x*((*tr1).tjeme2.y-(*tr1).tjeme1.y))/((*tr1).tjeme2.x-(*tr1).tjeme1.x))+(*tr1).tjeme1.y;
		r=k1->radijus;
		p=(*k1).centar.x;
		q=(*k1).centar.y;
		if(max((*tr1).tjeme1.x,(*tr1).tjeme2.x,(*tr1).tjeme3.x)>=p && max((*tr1).tjeme1.y,(*tr1).tjeme2.y,(*tr1).tjeme3.y)>=q)
			if(min((*tr1).tjeme1.x,(*tr1).tjeme2.x,(*tr1).tjeme3.x)<=p && min((*tr1).tjeme1.y,(*tr1).tjeme2.y,(*tr1).tjeme3.y)<=q)
				if(r*r*(k*k+1)-(k*p-q+n)*(k*p-q+n)<=0) {
					k=((*tr1).tjeme2.y-(*tr1).tjeme3.y)/((*tr1).tjeme2.x-(*tr1).tjeme3.x);
					n=((-(*tr1).tjeme3.x*((*tr1).tjeme2.y-(*tr1).tjeme3.y))/((*tr1).tjeme2.x-(*tr1).tjeme3.x))+(*tr1).tjeme3.y;
					if(r*r*(k*k+1)-(k*p-q+n)*(k*p-q+n)<=0) {
						k=((*tr1).tjeme1.y-(*tr1).tjeme3.y)/((*tr1).tjeme1.x-(*tr1).tjeme3.x);
						n=((-(*tr1).tjeme3.x*((*tr1).tjeme1.y-(*tr1).tjeme3.y))/((*tr1).tjeme1.x-(*tr1).tjeme3.x))+(*tr1).tjeme3.y;
						if(r*r*(k*k+1)-(k*p-q+n)*(k*p-q+n)<=0) return 1;
					}
				}
	}
	if(to1==KRUZNICA && to2==TROUGAO) {
		tr1=(struct Trougao*) oblik2;
		k1=(struct Kruznica*) oblik1;
		p=(*k1).centar.x;
		q=(*k1).centar.y;
		r=k1->radijus;
		if(max((*tr1).tjeme1.x,(*tr1).tjeme2.x,(*tr1).tjeme3.x)<=p+r && max((*tr1).tjeme1.y,(*tr1).tjeme2.y,(*tr1).tjeme3.y)<=q+r)
			if(min((*tr1).tjeme1.x,(*tr1).tjeme2.x,(*tr1).tjeme3.x)>=p-r && min((*tr1).tjeme1.y,(*tr1).tjeme2.y,(*tr1).tjeme3.y)>=q-r) {
				k=((*tr1).tjeme2.y-(*tr1).tjeme1.y)/((*tr1).tjeme2.x-(*tr1).tjeme1.x);
				n=((-(*tr1).tjeme1.x*((*tr1).tjeme2.y-(*tr1).tjeme1.y))/((*tr1).tjeme2.x-(*tr1).tjeme1.x))+(*tr1).tjeme1.y;
				if(r*r*(k*k+1)-(k*p-q+n)*(k*p-q+n)<=0) {
					k=((*tr1).tjeme2.y-(*tr1).tjeme3.y)/((*tr1).tjeme2.x-(*tr1).tjeme3.x);
					n=((-(*tr1).tjeme3.x*((*tr1).tjeme2.y-(*tr1).tjeme3.y))/((*tr1).tjeme2.x-(*tr1).tjeme3.x))+(*tr1).tjeme3.y;
					if(r*r*(k*k+1)-(k*p-q+n)*(k*p-q+n)<=0) {
						k=((*tr1).tjeme1.y-(*tr1).tjeme3.y)/((*tr1).tjeme1.x-(*tr1).tjeme3.x);
						n=((-(*tr1).tjeme3.x*((*tr1).tjeme1.y-(*tr1).tjeme3.y))/((*tr1).tjeme1.x-(*tr1).tjeme3.x))+(*tr1).tjeme3.y;
						if(r*r*(k*k+1)-(k*p-q+n)*(k*p-q+n)<=0) return 1;
					}
				}
			}
	}
	if(to1==KRUZNICA && to2==PRAVOUGAONIK) {
		k1=(struct Kruznica*) oblik1;
		p1=(struct Pravougaonik*) oblik2;
		p=(*k1).centar.x;
		q=(*k1).centar.y;
		r=k1->radijus;
		gore_desno.x=(*p1).dole_lijevo.x+p1->sirina;
		gore_desno.y=(*p1).dole_lijevo.y+p1->visina;
		if(gore_desno.x<=p+r && gore_desno.y<=q+r && (*p1).dole_lijevo.x>=p-r && (*p1).dole_lijevo.y>=q-r) {
			k=0;
			n=gore_desno.y;
			if(r*r*(k*k+1)-(k*p-q+n)*(k*p-q+n)<=0) {
				k=0;
				n=(*p1).dole_lijevo.y;
				if(r*r*(k*k+1)-(k*p-q+n)*(k*p-q+n)<=0) return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int k=0,i=0,m=0,j=0;
	struct Tacka niz1[50]= {{0,0}};
	struct Kruznica niz2[50]= {{{0,0},0}};
	struct Pravougaonik niz3[50]= {{{0,0},0,0}};
	struct Trougao niz4[50]= {{{0,0},{0,0},{0,0}}};
	int niz[50]= {0,0};
	do {
		printf("Unesite broj oblika: ");
		scanf("%d",&k);
	} while(k>50 || k<0);

	for(i=0; i<k; i++) {
		printf("Odaberite tip %d. oblika (1 - tacka, 2 - kruznica, 3 - pravougaonik, 4 - trougao): ",i+1);
		scanf("%d",&m);
		if(m<1 || m>4) {
			printf("Nepoznat tip oblika %d!\n",m);
			i--;
		}
		if(m==1) {
			printf("Unesite tacku: ");
			niz1[i]=unos_tacke();
			niz[i]=0;
		}
		if(m==2) {
			niz2[i]=unos_kruznice();
			niz[i]=1;
		}
		if(m==3) {
			niz3[i]=unos_pravugaonika();
			niz[i]=2;
		}
		if(m==4) {
			niz4[i]=unos_trougla();
			niz[i]=3;
		}
	}
	for(i=0; i<k-1; i++) {
		for(j=i+1; j<k; j++) {
			if(niz[i]==0 && niz[j]==0)
				if(obuhvata(&niz1[i],niz[i],&niz1[j],niz[j])==1) printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
			if(niz[i]==1 && niz[j]==0)
				if(obuhvata(&niz2[i],niz[i],&niz1[j],niz[i])==1) printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
		}
	}
	for(i=k-1; i>=1; i--) {
		for(j=0; j<i; j++) {
			if(niz[i]==2 && niz[j]==0)
				if(obuhvata(&niz3[i],niz[i],&niz1[j],niz[j])==1) printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
			if(niz[i]==2 && niz[j]==1)
				if(obuhvata(&niz3[i],niz[i],&niz2,niz[j])==1)    printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
		}
	}
	return 0;
}

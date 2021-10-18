#include <stdio.h>
#include <math.h>

#define e 0.001

enum TipOblika {TACKA, KRUZNICA, PRAVOUGAONIK, TROUGAO};

struct Tacka{
	float x,y;
};

struct Kruznica{
	struct Tacka centar;
	float poluprecnik;
};

struct Pravougaonik{
	struct Tacka donji_lijevi;
	float visina, sirina;
};

struct Trougao{
	struct Tacka prvi_vrh, drugi_vrh, treci_vrh;
};

float min (float a, float b, float c){
	if(a<b && a<c) return a;
	else if(b<a && b<c) return b;
	return c;
}

float max(float a, float b, float c){
	if(a>b && a>c) return a;
	else if(b>a && b>c) return b;
	return c;
}

int obuhvata (void *oblik1, enum TipOblika to1, void *oblik2, enum TipOblika to2){
	struct Kruznica *k1=NULL, *k2=NULL; 
	struct Tacka *t1=NULL, *t2=NULL;
	struct Pravougaonik *p1=NULL, *p2=NULL;
	struct Trougao *tr1=NULL, *tr2=NULL;
	
	
	if(to1==KRUZNICA && to2==TACKA){
		k1= (struct Kruznica*) oblik1;
		t2= (struct Tacka*) oblik2;
		if((sqrt((*t2.x - *k1.centar.x)*(*t2.x - *k1.centar.x) + (*t2.y - *k1.centar.y)*(*t2.y - *k1.centar.y)) - *k1.poluprecnik) > e ) return 0;
	}
	
	
	if(to1==PRAVOUGAONIK && to2==TACKA){
		p1= (struct Pravougaonik*) oblik1;
		t2= (struct Tacka*) oblik2;
		if((*t2.x < *t1.donji_lijevi.x - e) || (*t2.x > *t1.donji_lijevi.x + *t1.sirina + e) || (*t2.y < *t1.donji_lijevi.y - e) || (*t2.y > *t1.donji_lijevi.y + *t1.visina + e)) return 0;
	}
	
	if(to1==TROUGAO && to2==TACKA){
		tr1= (struct Trougao*) oblik1;
		t2= (struct Tacka*) oblik2;
		if(! ((*t2.x > min(*tr1.prvi_vrh.x, *tr1.drugi_vrh.x, *tr1.treci_vrh.x) + e)  && (*t2.x < max(*tr1.prvi_vrh.x, *tr1.drugi_vrh.x, *tr1.treci_vrh.x) - e) 
				&& (*t2.y > min(*tr1.prvi_vrh.y, *tr1.drugi_vrh.y, *tr1.treci_vrh.y) + e) && (*t2.y > max(*tr1.prvi_vrh.y, *tr1.drugi_vrh.y, *tr1.treci_vrh.y) + e))) return 0;
	}
	
	
	
	return 1; /*svaki oblik obuhvata sam sebe*/
}

int main() {
	printf("Zadaća 5, Zadatak 2");
	return 0;
}

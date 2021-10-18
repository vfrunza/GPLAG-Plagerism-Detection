#include <stdio.h>
#include <math.h>
#define eps  0.001

struct Tacka { double x,y; };
struct Kruznica { struct Tacka c; double radijus; };
struct Pravougaonik { struct Tacka t; double visina,sirina; };
struct Trougao { struct Tacka a,b,c; };

enum TipOblika { TACKA, KRUZNICA, PRAVOUGAONIK, TROUGAO };

float udaljenost(struct Kruznica k, struct Tacka t)
{
	return sqrt((k.c.x-t.x)*(k.c.x-t.x)-(k.c.y-t.y)*(k.c.y-t.y));
}

float udaljenost1(struct Pravougaonik k, struct Tacka t)
{
	return sqrt((k.t.x-t.x)*(k.t.x-t.x)-(k.t.y-t.y)*(k.t.y-t.y));
}


float provjera(struct Pravougaonik p,struct Tacka t)
{
	return (p.t.x>=t.x && p.t.x+p.sirina<=t.x && p.t.y>=t.y && p.t.y+p.visina<=t.y);
}

int obuhvata(void* oblik1, enum TipOblika to1, void* oblik2,enum TipOblika to2)
{
	
	if (to1 == TACKA && to2 == TACKA ) {
		struct Tacka* t1 = (struct Tacka*) oblik1;
		struct Tacka* t2 = (struct Tacka*) oblik2;
		if(t1->x==t2->x && t1->y==t2->y) return 1;
		return 0;
	}
	else if(to1 == TACKA && to2 == KRUZNICA ) {
		struct Tacka* t1 = (struct Tacka*) oblik1;
		struct Kruznica* t2 = (struct Kruznica*) oblik2;
		if(udaljenost(*t2,*t1)<=t2->radijus) return 1;
		return 0;
	}
	else if(to1 == TACKA && to2 == PRAVOUGAONIK ) {
		struct Tacka* t1 = (struct Tacka*) oblik1;
		struct Pravougaonik* t2 = (struct Pravougaonik*) oblik2;
		if(udaljenost1(*t2,*t1)<=t2->visina && udaljenost1(*t2,*t1)<=t2->sirina) return 1;
		return 0;
	}
	else if(to1 == TACKA && to2 == TROUGAO ) {
		struct Tacka* t1 = (struct Tacka*) oblik1;
		struct Trougao* t2 = (struct Trougao*) oblik2;
		if(1) return 1;
		return 0;
	}

	
	if (to1 == KRUZNICA && to2 == KRUZNICA ) {
		struct Kruznica* t1 = (struct Kruznica*) oblik1;
		struct Kruznica* t2 = (struct Kruznica*) oblik2;
		//if(t1->x==t2->x && t1->y==t2->y) return 1; uslov kad se dvije kruznice sijeku
		return 0;
	}
	else if(to1 == KRUZNICA && to2 == TACKA ) {
		struct Tacka* t2 = (struct Tacka*) oblik1;
		struct Kruznica* t1 = (struct Kruznica*) oblik2;
		//if(udaljenost(*t2,*t1)<=t2->radijus) return 1; //Kada se kruznica i tacka sijeku 
		return 0;
	}
	else if(to1 == KRUZNICA && to2 == PRAVOUGAONIK ) {
		struct Kruznica* t1 = (struct Kruznica*) oblik1;
		struct Pravougaonik* t2 = (struct Pravougaonik*) oblik2;
		//if(udaljenost1(*t2,*t1)<=t2->visina && udaljenost1(*t2,*t1)<=t2->sirina) return 1;
		return 0;
	}
	else if(to1 == KRUZNICA && to2 == TROUGAO ) {
		struct Kruznica* t1 = (struct Kruznica*) oblik1;
		struct Trougao* t2 = (struct Trougao*) oblik2;
		//if(1) return 1;
		return 0;
	}


return 0;
}


int main() 
	
struct Tacka t={1.9,4.3};
struct Kruznica k = {{2,4},1};
struct Pravougaonik p={{0,1},4,4};
struct Trougao tr={{1,3},{3,4},{1,5}};




printf("%d ", obuhvata(&k,KRUZNICA,&t,TACKA));
printf("%d ", obuhvata(&p,PRAVOUGAONIK,&t,TACKA));
printf("%d\n", obuhvata(&tr,TROUGAO,&t,TACKA));

printf("%d ", obuhvata(&t,TACKA,&k,KRUZNICA));
printf("%d ", obuhvata(&p,PRAVOUGAONIK,&k,KRUZNICA));
printf("%d\n", obuhvata(&tr,TROUGAO,&k,KRUZNICA));

printf("%d ", obuhvata(&t,TACKA,&p,PRAVOUGAONIK));
printf("%d ", obuhvata(&k,KRUZNICA,&p,PRAVOUGAONIK));
printf("%d\n", obuhvata(&tr,TROUGAO,&p,PRAVOUGAONIK));

printf("%d ", obuhvata(&t,TACKA,&tr,TROUGAO));
printf("%d ", obuhvata(&k,KRUZNICA,&tr,TROUGAO));
printf("%d ", obuhvata(&p,PRAVOUGAONIK,&tr,TROUGAO));

return 0;
}

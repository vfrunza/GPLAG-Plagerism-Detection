#include <stdio.h>
#include <math.h>
#define eps 0.001

struct Tacka
{
	double x,y;
};

struct Kruznica
{
	struct Tacka t1;
	double radijus;
};

struct Pravougaonik
{
	struct Tacka t1;
	double sirina,visina;
};

struct Trougao
{
	struct Tacka t1,t2,t3;
};


enum TipOblika { TACKA, KRUZNICA, PRAVOUGAONIK, TROUGAO };

float Udaljenost(struct Kruznica k,struct Tacka t)
{
	return sqrt((k.t1.x-t.x)*(k.t1.x-t.x)-(k.t1.y-t.y)*(k.t1.y-t.y));
}

float Provjera(struct Pravougaonik p,struct Tacka t)
{
	return (p.t1.x>=t.x && p.t1.x+p.sirina<=t.x && p.t1.y>=t.y && p.t1.y+p.visina<=t.y);
}
int obuhvata(void* oblik1,enum TipOblika to1, void* oblik2,enum TipOblika to2)
{
	struct Tacka *t1,*t2;
	struct Kruznica *k1,*k2;
	struct Pravougaonik *p1,*p2;
	struct Trougao *d1,*d2;
	
		
	if(to1==TACKA)
	{
		t1=(struct Tacka*)oblik1;
		
		if(to2==TACKA)
		{
			t2=(struct Tacka*)oblik2;
			if(t1->x-t2->x<eps && t1->y-t2->y<eps) return 1;
		}
		else if(to2==KRUZNICA)
		{
			k2=(struct Kruznica*)oblik2;
			if(Udaljenost(*k2,*t1)-k2->radijus<eps) return 1;
		}
		else if(to2==PRAVOUGAONIK)
		{
			p2=(struct Pravougaonik*)oblik2;
			if(Provjera(*p2,*t1)) return 1;
		}
		else if(to2==TROUGAO)
		{
			d2=(struct Trougao*) oblik2;
			
		}
	}
	else if(to1==KRUZNICA)
	{
		k1=(struct Kruznica*)oblik1;
		
	}
	else if(to1==PRAVOUGAONIK)
	{
		p1=(struct Pravougaonik*)oblik1;
		
	}
	else if(to1==TROUGAO)
	{
		d1=(struct Trougao*)oblik1;
		
	}
	
return 0;	
}


int main() {
	
	
	/* AT2: Da li oblici obuhvataju same sebe? */
struct Tacka t={1.9,4.3};
struct Kruznica k = {{2,4},1};
struct Pravougaonik p={{0,1},4,4};
struct Trougao tr={{1,3},{3,4},{1,5}};

printf("%d ", obuhvata(&t,TACKA,&t,TACKA));
printf("%d ", obuhvata(&k,KRUZNICA,&k,KRUZNICA));
printf("%d ", obuhvata(&p,PRAVOUGAONIK,&p,PRAVOUGAONIK));
printf("%d ", obuhvata(&tr,TROUGAO,&tr,TROUGAO));

/* Za slucaj da funkcija uvijek vraca 1 */
printf("%d ", obuhvata(&t,TACKA,&k,KRUZNICA));

	
	return 0;
}

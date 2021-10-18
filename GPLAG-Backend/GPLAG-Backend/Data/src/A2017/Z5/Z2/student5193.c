#include <stdio.h>

struct Tacka
{
	double x;
	double y;
};
struct Tacka unos_tacke()
{
	struct Tacka t;
	printf("Unesite tacku: koordinate x,y: ");
	scanf("%lf,%lf",&t.x,&t.y);
	return t;
}
struct Kruznica
{
	struct Tacka t;
	float r;
};
struct Kruznica unos_kruznice()
{
	struct Kruznica k;
	printf("Unesite centar kruznice: koordinate x,y: ");
	scanf("%lf,%lf",&k.t.x,&k.t.y);
	scanf("%lf",&k.r);
	return k;
}
struct Pravougaonik
{
    int sirina;
    int visina;
    struct Tacka t;
};
struct Pravougaonik unos_pravougaonika()
{
	struct Pravougaonik p;
	printf("Unesite donji lijevi ugao: koordinate x,y: ");
	scanf("%lf,%lf",&p.t.x,&p.t.y);
	printf("Unesite sirinu: ");
	scanf("%d",&p.sirina);
	printf("Unesite visinu: ");
	scanf("%d",&p.visina);
}
struct Trougao
{
	struct Tacka t1,t2,t3;
	
};
struct Trougao unos_trougla()
{
	struct Trougao t;
	printf("Unesite prvi vrh: koordinate x,y: ");
	scanf("%lf,%lf",&t.t1.x,&t.t1.y);
	printf("Unesite drugi vrh: koordinate x,y: ");
	scanf("%lf,%lf",&t.t2.x,&t.t2.y);
	printf("Unesite prvi vrh: koordinate x,y: ");
	scanf("%lf,%lf",&t.t3.x,&t.t3.y);
}
enum TipOblika { TACKA, KRUZNICA, PRAVOUGAONIK, TROUGAO };

int obuhvata(void* oblik1, enum TipOblika to1, void* oblik2, enum TipOblika to2)
{
	if(to1==TACKA)
	{
		struct Tacka* t = (struct Tacka*) oblik1;
		if(to2==TACKA)
		{
			struct Tacka* t1 = (struct Tacka*) oblik2;
			//if(t1.x!=t.x || t1.y!=t.y) return 0; 
		}
		else if(to2==KRUZNICA)
		{
			struct Kruznica* k1 = (struct Kruznica*) oblik2;
		}
		else if(to2==PRAVOUGAONIK)
		{
			struct Pravougaonik* p1 = (struct Pravougaonik*) oblik2;
		}
		else if(to2==TROUGAO)
		{
			struct Trougao* tr1 = (struct Trougao*) oblik2;
		}
	}
	else if(to1==KRUZNICA)
	{
		struct Kruznica* k = (struct Kruznica*) oblik1;
		if(to2==TACKA)
		{
			struct Tacka* t1 = (struct Tacka*) oblik2;
		}
		else if(to2==KRUZNICA)
		{
			struct Kruznica* k1 = (struct Kruznica*) oblik2;
		}
		else if(to2==PRAVOUGAONIK)
		{
			struct Pravougaonik* p1 = (struct Pravougaonik*) oblik2;
		}
		else if(to2==TROUGAO)
		{
			struct Trougao* tr1 = (struct Trougao*) oblik2;
		}
	}
	else if(to1==PRAVOUGAONIK)
	{
		struct Pravougaonik* p = (struct Pravougaonik*) oblik1;
		if(to2==TACKA)
		{
			struct Tacka* t1 = (struct Tacka*) oblik2;
		}
		else if(to2==KRUZNICA)
		{
			struct Kruznica* k1 = (struct Kruznica*) oblik2;
		}
		else if(to2==PRAVOUGAONIK)
		{
			struct Pravougaonik* p1 = (struct Pravougaonik*) oblik2;
		}
		else if(to2==TROUGAO)
		{
			struct Trougao* tr1 = (struct Trougao*) oblik2;
		}
	}
	else if(to1==TROUGAO)
	{
		struct Trougao* tr = (struct Trougao*) oblik1;
		if(to2==TACKA)
		{
			struct Tacka* t1 = (struct Tacka*) oblik2;
		}
		else if(to2==KRUZNICA)
		{
			struct Kruznica* k1 = (struct Kruznica*) oblik2;
		}
		else if(to2==PRAVOUGAONIK)
		{
			struct Pravougaonik* p1 = (struct Pravougaonik*) oblik2;
		}
		else if(to2==TROUGAO)
		{
			struct Trougao* tr1 = (struct Trougao*) oblik2;
		}
	}
	return 1;
}
int main() {
	int n;
	int oblik;
	do{
		printf("Unesite broj oblika: ");
		scanf("%d",&n);
	}while(n>50);
	do{
		printf("Odaberite tip 1. oblika (1 - tacka, 2 - kruznica, 3 - pravougaonik, 4 - trougao): ");
		scanf("%d",&oblik);
		if(oblik<1 || oblik >4)
		{
			printf("Nepoznat tip oblika %d!\n",oblik);
		}
		else
		{
			if(oblik==1)
			{
				//tacka
			}
			else if(oblik==2)
			{
				//kruznica
			}
			else if(oblik==3)
			{
				//pravougaonik
			}
			else if(oblik==4)
			{
				//trougao
			}
			
			n--;
		}
	}while(n>0);
	return 0;
}

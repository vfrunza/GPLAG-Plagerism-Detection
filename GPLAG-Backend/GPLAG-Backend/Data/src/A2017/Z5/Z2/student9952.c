#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
#define PI 3.1415926535897932384626433832

enum TipOblika { TACKA , KRUZNICA , PRAVOUGAONIK , TROUGAO};

struct Tacka
{
	double x,y;
};

struct Kruznica
{
	struct Tacka centar;
	double radijus;
};

struct Pravougaonik
{
	struct Tacka t;
	double sirina,visina;
};

struct Trougao
{
	struct Tacka A,B,C;
};

void unesi_tacku(struct Tacka *t);

void unesi_kruznicu(struct Kruznica *k);

void unesi_pravougaonik(struct Pravougaonik *p);

void unesi_trougao(struct Trougao *a);

struct Tacka vektoriziraj(struct Tacka t1, struct Tacka t2);

double udaljenost_tacaka(struct Tacka t1, struct Tacka t2);

double modul_vektora(struct Tacka t);

double skalarni_proizvod(struct Tacka t1, struct Tacka t2);

struct Tacka min_distance_from_segment(struct Tacka A, struct Tacka B, struct Tacka X);

int tacka_tacku(struct Tacka t1, struct Tacka t2);

int tacka_trougao(struct Tacka t, struct Trougao a);

int tacka_kruznicu(struct Tacka t, struct Kruznica k);

int tacka_pravougaonik(struct Tacka t, struct Pravougaonik p);

int kruznica_tacku(struct Kruznica k, struct Tacka t);

int kruznica_kruznicu(struct Kruznica k1, struct Kruznica k2);

int kruznica_pravougaonik(struct Kruznica k, struct Pravougaonik p);

int kruznica_trougao(struct Kruznica k, struct Trougao a);

int pravougaonik_tacku(struct Pravougaonik p, struct Tacka t);

int pravougaonik_kruznicu(struct Pravougaonik p, struct Kruznica k);

int pravougaonik_pravougaonik(struct Pravougaonik p1, struct Pravougaonik p2);

int pravougaonik_trougao(struct Pravougaonik p, struct Trougao a);

int trougao_tacku(struct Trougao a, struct Tacka t);

int trougao_pravougaonik(struct Trougao a, struct Pravougaonik p);

int trougao_trougao(struct Trougao a1, struct Trougao a2);

int trougao_kruznicu(struct Trougao a, struct Kruznica k);

int obuhvata(void* oblik1, enum TipOblika to1, void* oblik2, enum TipOblika to2);

int main()
{
	int t;
	int n;
	int i,j;
	int niz[50]= {0};
	struct Tacka T[50], *pt, *pt1;
	struct Kruznica K[50], *pk, *pk1;
	struct Pravougaonik P[50], *pp, *pp1;
	struct Trougao A[50], *pa, *pa1;
	pt=pt1=T;
	pk=pk1=K;
	pp=pp1=P;
	pa=pa1=A;
	printf("\nUnesite broj oblika: ");
	scanf("%d",&n);

	//kad unesem trebam ucitavati jedan po jedan for petljom s while petljom

	for(i=0; i<n; i++)
	{
		do
		{
			t=1;
			printf("Odaberite tip %d. oblika (1 - tacka, 2 - kruznica, 3 - pravougaonik, 4 - trougao): ",i+1);
			scanf("%d",niz+i);

			switch(*(niz+i))
			{
			case TACKA+1:
			{
				printf("Unesite tacku: ");
				unesi_tacku(pt);
				pt++;
				break;
			}
			case KRUZNICA+1:
			{
				unesi_kruznicu(pk);
				pk++;
				break;
			}
			case PRAVOUGAONIK+1:
			{
				unesi_pravougaonik(pp);
				pp++;
				break;
			}
			case TROUGAO+1:
			{
				unesi_trougao(pa);
				pa++;
				break;
			}

			default:
				t=0;
				printf("Nepoznat tip oblika %d!\n",*(niz+i));
				break;
			}
		}
		while(t==0);
	}
	pt=T;
	pk=K;
	pa=A;
	pp=P;
	for(i=0; i<n; i++)
	{
		pt1=T;
		pk1=K;
		pa1=A;
		pp1=P;
		switch(niz[i])
		{
		case TACKA+1:
		{
			for(j=0; j<n; j++)
			{
				switch(niz[j])
				{
				case TACKA+1:
					if(i!=j && obuhvata(pt,TACKA,pt1,TACKA))printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					pt++;
					pt1++;
					break;

				case KRUZNICA+1:
					if(i!=j && obuhvata(pt,TACKA,pk1,KRUZNICA))printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					pt++;
					pk1++;
					break;

				case PRAVOUGAONIK+1:
					if(i!=j && obuhvata(pt,TACKA,pp1,PRAVOUGAONIK))printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					pt++;
					pp1++;
					break;

				case TROUGAO+1:
					if(i!=j && obuhvata(pt,TACKA,pa1,TROUGAO))printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					pt++;
					pa1++;
					break;

				}

			}
			break;
		}
		case KRUZNICA+1:
		{
			for(j=0; j<n; j++)
			{
				switch(niz[j])
				{
				case TACKA+1:
					if(i!=j && obuhvata(pk,KRUZNICA,pt1,TACKA))printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					pk++;
					pt1++;
					break;

				case KRUZNICA+1:
					if(i!=j && obuhvata(pk,KRUZNICA,pk1,KRUZNICA))printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					pk++;
					pk1++;
					break;

				case PRAVOUGAONIK+1:
					if(i!=j && obuhvata(pk,KRUZNICA,pp1,PRAVOUGAONIK))printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					pk++;
					pp1++;
					break;

				case TROUGAO+1:
					if(i!=j && obuhvata(pk,KRUZNICA,pa1,TROUGAO))printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					pk++;
					pa1++;
					break;
				}
			}
			break;
		}
		case PRAVOUGAONIK+1:
		{
			for(j=0; j<n; j++)
			{
				switch(niz[j])
				{
				case TACKA+1:
					if(i!=j && obuhvata(pp,PRAVOUGAONIK,pt1,TACKA))printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					pp++;
					pt1++;
					break;

				case KRUZNICA+1:
					if(i!=j && obuhvata(pp,PRAVOUGAONIK,pk1,KRUZNICA))printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					pp++;
					pk1++;
					break;

				case PRAVOUGAONIK+1:
					if(i!=j && obuhvata(pp,PRAVOUGAONIK,pp1,PRAVOUGAONIK))printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					pp++;
					pp1++;
					break;

				case TROUGAO+1:
					if(i!=j && obuhvata(pp,PRAVOUGAONIK,pa1,TROUGAO))printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					pp++;
					pa1++;
					break;
				}

			}

			break;
		}
		case TROUGAO+1:
		{
			for(j=0; j<n; j++)
			{
				switch(niz[j])
				{
				case TACKA+1:
					if(i!=j && obuhvata(pa,TROUGAO,pt1,TACKA))printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					pa++;
					pt1++;
					break;

				case KRUZNICA+1:
					if(i!=j && obuhvata(pa,TROUGAO,pk1,KRUZNICA))printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					pa++;
					pk1++;
					break;

				case TROUGAO+1:
					if(i!=j && obuhvata(pa,TROUGAO,pa1,TROUGAO))printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					pa++;
					pa1++;
					break;

				case PRAVOUGAONIK+1:
					if(i!=j && obuhvata(pa,TROUGAO,pp1,PRAVOUGAONIK))printf("\nOblik %d obuhvata oblik %d.",i+1,j+1);
					pa++;
					pp1++;
					break;
				}
			}



			break;
		}



		}
	}



	return 0;
}

void unesi_tacku(struct Tacka *t)
{
	printf("koordinate x,y: ");
	scanf("%lf,%lf",&((*t).x),&((*t).y));
}

void unesi_kruznicu(struct Kruznica *k)
{
	printf("Unesite centar kruznice: ");
	unesi_tacku(&((*k).centar));
	printf("Unesite poluprecnik kruznice: ");
	scanf("%lf",&((*k).radijus));
}

void unesi_pravougaonik(struct Pravougaonik *p)
{
	printf("Unesite donji lijevi ugao: ");
	unesi_tacku(&((*p).t));
	printf("Unesite sirinu: ");
	scanf("%lf",&((*p).sirina));
	printf("Unesite visinu: ");
	scanf("%lf",&((*p).visina));
}

void unesi_trougao(struct Trougao *a)
{
	printf("Unesite prvi vrh: ");
	unesi_tacku(&((*a).A));
	printf("Unesite drugi vrh: ");
	unesi_tacku(&((*a).B));
	printf("Unesite treci vrh: ");
	unesi_tacku(&((*a).C));
}

double udaljenost_tacaka(struct Tacka t1, struct Tacka t2)
{
	double d=0;
	d=sqrt( (t1.x-t2.x)*(t1.x-t2.x)  +  (t1.y-t2.y)*(t1.y-t2.y)  );
	return d;
}

int tacka_tacku(struct Tacka t1, struct Tacka t2)
{
	if(udaljenost_tacaka(t1,t2)<EPSILON)return 1;
	return 0;
}

int tacka_trougao(struct Tacka t, struct Trougao a)
{
	if(udaljenost_tacaka(t,a.A)<EPSILON && udaljenost_tacaka(t,a.B)<EPSILON && udaljenost_tacaka(t,a.C)<EPSILON)return 1;
	return 0;
}

int tacka_kruznicu(struct Tacka t, struct Kruznica k)
{
	if(udaljenost_tacaka(t,k.centar)+k.radijus<EPSILON)return 1;
	return 0;
}

int tacka_pravougaonik(struct Tacka t, struct Pravougaonik p)
{
	struct Tacka X;
	X.x= p.t.x+p.sirina;
	X.y=p.t.y+p.visina;
	if(udaljenost_tacaka(t,p.t)<EPSILON && udaljenost_tacaka(t,X)<EPSILON)return 1;
	return 0;
}

int kruznica_tacku(struct Kruznica k, struct Tacka t)
{
	if(udaljenost_tacaka(k.centar,t)>k.radijus)return 0;
	return 1;
}

int kruznica_kruznicu(struct Kruznica k1, struct Kruznica k2)
{
	if(udaljenost_tacaka(k1.centar,k2.centar)+k2.radijus>k1.radijus)return 0;
	return 1;
}

int kruznica_pravougaonik(struct Kruznica k, struct Pravougaonik p)
{
	struct Tacka gornja_desno;
	gornja_desno.x=p.t.x+p.sirina;
	gornja_desno.y=p.t.y+p.visina;

	if(kruznica_tacku(k,p.t)&&kruznica_tacku(k,gornja_desno))return 1;
	return 0;
}

int kruznica_trougao(struct Kruznica k, struct Trougao a)
{
	if(kruznica_tacku(k,a.A)&&kruznica_tacku(k,a.B)&&kruznica_tacku(k,a.C))return 1;
	return 0;
}

int pravougaonik_tacku(struct Pravougaonik p, struct Tacka t)
{
	if(p.t.x>t.x||p.t.y>t.y||p.t.x+p.sirina<t.x||p.t.y+p.visina<t.y)return 0;
	return 1;
}

int pravougaonik_trougao(struct Pravougaonik p, struct Trougao a)
{
	if(pravougaonik_tacku(p,a.A)&&pravougaonik_tacku(p,a.B)&&pravougaonik_tacku(p,a.C))return 1;
	return 0;
}

int pravougaonik_pravougaonik(struct Pravougaonik p1, struct Pravougaonik p2)
{
	struct Tacka gornja_desno;
	gornja_desno.x=p2.t.x+p2.sirina;
	gornja_desno.y=p2.t.y+p2.visina;
	if(pravougaonik_tacku(p1,p2.t)&&pravougaonik_tacku(p1,gornja_desno))return 1;
	return 0;
}

int pravougaonik_kruznicu(struct Pravougaonik p, struct Kruznica k)
{
	struct Pravougaonik test;
	test.t.x=k.centar.x-k.radijus;
	test.t.y=k.centar.y-k.radijus;
	test.sirina=k.radijus;
	test.visina=k.radijus;
	if(pravougaonik_pravougaonik(p,test))return 1;
	return 0;
}

int trougao_tacku(struct Trougao a, struct Tacka t)
{
	struct Tacka vektor1,vektor2,vektor3,X;
	double ugao=0;

	X=min_distance_from_segment(a.A,a.B,t);
	if(udaljenost_tacaka(X,t)<EPSILON)return 1;

	X=min_distance_from_segment(a.A,a.C,t);
	if(udaljenost_tacaka(X,t)<EPSILON)return 1;

	X=min_distance_from_segment(a.B,a.C,t);
	if(udaljenost_tacaka(X,t)<EPSILON)return 1;

	vektor1=vektoriziraj(t,a.A);
	vektor2=vektoriziraj(t,a.B);
	vektor3=vektoriziraj(t,a.C);

	ugao+=fabs(     acos(  (skalarni_proizvod(vektor1,vektor2))/(double)(modul_vektora(vektor1)*modul_vektora(vektor2))  )  );
	ugao+=fabs(     acos(  (skalarni_proizvod(vektor1,vektor3))/(double)(modul_vektora(vektor1)*modul_vektora(vektor3))  )  );
	ugao+=fabs(     acos(  (skalarni_proizvod(vektor2,vektor3))/(double)(modul_vektora(vektor2)*modul_vektora(vektor3))  )  );

	if(fabs(ugao-2*PI)<EPSILON) return 1;

	return 0;
}

double modul_vektora(struct Tacka t)
{
	return sqrt((double)((t.x)*(t.x)+(t.y)*(t.y)));
}

double skalarni_proizvod(struct Tacka t1, struct Tacka t2)
{
	return (double)((t1.x)*(t2.x)+(t1.y)*(t2.y));
}

struct Tacka vektoriziraj(struct Tacka t1, struct Tacka t2)
{
	struct Tacka t;
	t.x=t2.x-t1.x;
	t.y=t2.y-t1.y;
	return t;
}

int trougao_pravougaonik(struct Trougao a, struct Pravougaonik p)
{
	struct Tacka A,B,C,D;
	A=p.t;
	B.x=p.t.x+p.sirina;
	B.y=p.t.y;
	C.x=p.t.x+p.sirina;
	C.y=p.t.y+p.visina;
	D.x=p.t.x;
	D.y=p.t.y+p.visina;

	if(trougao_tacku(a,A)&&trougao_tacku(a,B)&&trougao_tacku(a,C)&&trougao_tacku(a,D))return 1;
	return 0;
}

int trougao_trougao(struct Trougao a1, struct Trougao a2)
{

	if(trougao_tacku(a1,a2.A)&&trougao_tacku(a1,a2.B)&&trougao_tacku(a1,a2.C))return 1;
	return 0;

}

int trougao_kruznicu(struct Trougao a, struct Kruznica k)
{

	struct Tacka h12,h23,h13;

	h12=min_distance_from_segment(a.A,a.B,k.centar);
	h23=min_distance_from_segment(a.B,a.C,k.centar);
	h13=min_distance_from_segment(a.A,a.C,k.centar);

	if(udaljenost_tacaka(h12,k.centar)>k.radijus && udaljenost_tacaka(h13,k.centar)>k.radijus && udaljenost_tacaka(h23,k.centar))return 1;
	return 0;
}

struct Tacka min_distance_from_segment(struct Tacka A, struct Tacka B, struct Tacka X)
{
	struct Tacka max, min, mid;
	max=A;
	min=B;

	do
	{
		mid.x=(max.x+min.x)/2.0;
		mid.y=(max.y+min.y)/2.0;

		if(udaljenost_tacaka(max,X)>udaljenost_tacaka(min,X))
		{
			max=mid;
		}
		else if(udaljenost_tacaka(max,X)<udaljenost_tacaka(min,X))
		{
			min=mid;
		}
	}
	while(fabs(udaljenost_tacaka(max,X)-udaljenost_tacaka(min,X))>EPSILON);

	return max;


}

int obuhvata(void* oblik1, enum TipOblika to1, void* oblik2, enum TipOblika to2)
{

	switch(to1)
	{
	case TACKA:
		{
		    struct Tacka *t;
		    t=(oblik1);

		    switch(to2)
	{
	case TACKA:
		{
		    struct Tacka *S;
		    S=(oblik2);
		    return tacka_tacku(*t,*S);
		    break;
		}
		case KRUZNICA:
			{
			    struct Kruznica *k;
			    k=(oblik2);
			    return tacka_kruznicu(*t,*k);
			    break;
			}
			case PRAVOUGAONIK:
				{
				    struct Pravougaonik *p;
				    p=(oblik2);
				    return tacka_pravougaonik(*t,*p);
				    break;
				}
				case TROUGAO:
					{
					    struct Trougao *a;
					    a=(oblik2);
					    return tacka_trougao(*t,*a);
					    break;

					}

	}



}
case KRUZNICA:
{
	struct Kruznica *k;
	k=(oblik1);
		switch(to2)
		{
		case TACKA:
		{
			struct Tacka *t;
			t=(oblik2);
			return kruznica_tacku(*k,*t);
			break;
		}
		case KRUZNICA:
		{
			struct Kruznica *k1;
			k1=(oblik2);
			return kruznica_kruznicu(*k,*k1);
			break;
		}
		case TROUGAO:
		{
			struct Trougao *a;
			a=(oblik2);
			return kruznica_trougao(*k,*a);
			break;
		}
		case PRAVOUGAONIK:
		{
			struct Pravougaonik *p;
			p=(oblik2);
			return kruznica_pravougaonik(*k,*p);
			break;
		}
		
			


		}
	}
	case TROUGAO:
	{
		struct Trougao *a;
		a=(oblik1);
		switch(to2)
		{
		case TACKA:
		{
			struct Tacka *t;
			t=(oblik2);
			return trougao_tacku(*a,*t);
			break;
		}
		case KRUZNICA:
		{
			struct Kruznica *k;
			k=(oblik2);
			return trougao_kruznicu(*a,*k);
			break;
		}
		case TROUGAO:
		{
			struct Trougao *a1;
			a1=(oblik2);
			return trougao_trougao(*a,*a1);
			break;
		}
		case PRAVOUGAONIK:
		{
			struct Pravougaonik *p;
			p=(oblik2);
			return trougao_pravougaonik(*a,*p);
			break;
		}
	
			
		}

	}
	case PRAVOUGAONIK:
	{
		struct Pravougaonik *p;
		p=(oblik1);
		switch(to2)
		{
		case TACKA:
		{
			struct Tacka *t;
			t=(oblik2);
			return pravougaonik_tacku(*p,*t);
			break;
		}
		case KRUZNICA:
		{
			struct Kruznica *k;
			k=(oblik2);
			return pravougaonik_kruznicu(*p,*k);
			break;
		}
		case TROUGAO:
		{
			struct Trougao *a;
			a=(oblik2);
			return pravougaonik_trougao(*p,*a);
			break;
		}
		case PRAVOUGAONIK:
		{
			struct Pravougaonik *p1;
			p1=(oblik2);
			return pravougaonik_pravougaonik(*p,*p1);
			break;
		}
	
		}
	}
	}
}
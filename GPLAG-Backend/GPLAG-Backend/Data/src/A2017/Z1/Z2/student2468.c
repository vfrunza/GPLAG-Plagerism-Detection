#include <stdio.h>
#include <math.h>
#define E 0.0001
#define PI 3.1415926535
int main() {
	double x1, x2, x3, y1, y2, y3, P, s, a, b,c,A, B, C, Am, Bm, Cm, As, Bs, Cs;




    printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);

	/* Zadatak mozemo rijesiti primjenom analiticke geometrije */

	/* U ovom djelu cemo izracunati duzine stranica trougla koje cemo oznaciti sa a, b i c */
	a=sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	b=sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));
	c=sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));

	s=(a+b+c)/2; /* s je srednja linija trougla */
	P=sqrt (s*(s-a)*(s-b)*(s-c));

	/* Sada cemo pronaci vrijednosti uglova izmedju stranica i oznacicemo ih sa A, B i C, a koristicemo kosinusnu teoremu  pa cemo ih pretovriti u stepene*/

	C=acos((a*a + b*b - c*c)/(2*a*b))*(180.)/PI;
	B=acos((a*a + c*c - b*b)/(2*a*c))*(180.)/PI;
	A=acos((b*b + c*c - a*a)/(2*c*b))*(180.)/PI;



	/* Ovdje cemo dobiti rezultat za minute navedenih uglova, Am, Bm i Cm su minute uglova, a As, Bs i Cs su sekunde, oboje respektivno */
	Cm= (C- floor (C))*60;
	Bm=(B- floor(B))*60;
	Am=(A- floor(A))*60;



	/* Ovdje cemo izracunati sekunde uglova */

	Cs=(Cm -floor(Cm))*60;
	Bs=(Bm -floor(Bm))*60;
	As=(Am -floor(Am))*60;
	A=floor(A);
	B=floor(B);
	C=floor(C);


	/* Kada je povrsina trougla jednaka nuli tada se radi o liniji, odnosno tacke su kolinearne */

	if(P==0) {
		printf("Linija \n");

	printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");

	}
	else {

	/* Sada cemo analizirati druge tipove trouglova */

	 if(fabs(A-90)<E || fabs(B-90)<E || fabs(C-90)<E) /* Ako je vrijednost bar jednog ugla 90 stepeni taj trougao je pravougli */
	 {
	 	printf("Pravougli \n");

	 }

	if( fabs(A-60)<E || fabs(B-60)<E || fabs(C-60)<E )	/* Ako su svi uglovi trougla 60 stepeni, trougao je jednakostranicni */
	{
		printf("Jednakostranicni \n");
	}

	else if( fabs(a-b)<E || fabs(a-c)<E || fabs(b-c)<E && ( fabs(A-60)>E && fabs(B-60)>E && fabs(C-60)>E ))	/* Ako su dva ugla u trouglu jednaka onda je trougao jednakokraki, postoji mogucnost i pravouglog jednakokrakog */
	{

		printf("Jednakokraki \n");

	}


	if( fabs(a-b)>E && fabs(a-c)>E && fabs(b-c)>E ) /* Kada su svi uglovi razliciti onda je trougao raznostranicni */
		{
			printf("Raznostranicni \n");
		}


	if (a>b && a>c || fabs(b-c)<E && a>b && a>c) /* Sada cemo naci najveci ugao u trouglu */
	{
		printf("Najveci ugao ima %.f stepeni, %.f minuta i %.f sekundi.", A, Am, As);
	}

	if(b>a && b>c || fabs(a-c)<E && b>a && b>c)
	{
		printf("Najveci ugao ima %.f stepeni, %.f minuta i %.f sekundi.", B, Bm, Bs);
	}

	if(c>a && c>b || fabs(a-b)<E && c>a && c>b )
	{
		printf("Najveci ugao ima %.f stepeni, %.f minuta i %.f sekundi.", C, Cm, Cs);
	}

/* Na ovaj nacin smo napravili program koji za unesene koordinate daje ispis vrste trougla i najveceg ugla u njemu. Nadam se da ste uzivali pregledajuci ovaj zadatak */








	}
	return 0;
}

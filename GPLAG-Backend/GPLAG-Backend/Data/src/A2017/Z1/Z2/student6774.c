#include <stdio.h>
#include <math.h>
#define E 0.0001
#define PI 3.14159265

int main() {
	double x1, x2, x3, y1, y2, y3, a, b, c, DA=1,DB=1, DC=1, l, t, g, val;
	printf("Unesite koordinate tacke t1:");
	scanf("%lf%lf", &x1, &y1);
	printf("Unesite koordinate tacke t2:");
	scanf("%lf%lf", &x2, &y2);
	printf("Unesite koordinate tacke t3:");
	scanf("%lf%lf", &x3, &y3);
	b=sqrt((x3 - x1) * (x3 -x1) + (y3-y1) * (y3-y1));
	c=sqrt((x2 - x1) * (x2 -x1) + (y2-y1) * (y2-y1));
	a=sqrt((x2 - x3) * (x2 -x3) + (y2-y3) * (y2-y3));
	DA=(b*b+c*c-a*a)/2.*b*c;
	DB=(a*a+c*c-b*b)/2.*a*c;
	DC=(a*a+b*b-c*c)/2.*a*b;
	val=180.0/PI;
	l=acos(DA)*val;
	t=acos(DB)*val;
	g=acos(DC)*val;
	printf("%f      %f       %f", l, t, g);
	return 0;
}


/*
Date su tri tačke u dvodimenzionalnom Dekartovom prostoru preko koordinata x i y. Ove tri tačke čine trougao.

Potrebno je napraviti program koji omogućuje unos ovih tačaka (koordinate su realni brojevi), zatim ispisuje koju vrstu trougla one čine, te ispisuje najveći ugao u trouglu (u stepenima). 

Vrsta trougla može biti: Linija (ako sve tri tačke leže na istom pravcu onda u pitanju uopšte nije trougao nego linija), Jednakostranični, Pravougli, Jednakokraki, Raznostranični. Vrsta trougla se ispisuje u zasebnoj liniji, bez naših slova. Ako je trougao istovremeno jednakokraki i pravougli, ispisuje se oboje. Iznosi stepeni, minuta i sekundi su uvijek cijeli brojevi.

Primjer ulaza i izlaza:
	Unesite koordinate tacke t1: 0.1 0.1
	Unesite koordinate tacke t2: 0.1 0.2
	Unesite koordinate tacke t3: 0.2 0.2
	Pravougli
	Jednakokraki
	Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.*/

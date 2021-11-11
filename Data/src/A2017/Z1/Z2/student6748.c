#include <stdio.h>
#include <math.h>

#define eps 0.0001
#define PI (4.0 * atan(1))

int main() {
 double x1, x2, x3, y1, y2, y3, a, b, c, d, e, f, g, AB, BC, AC, alpha, beta, gama, najveci_ugao;
 int ukupno_sekundi, sekunde, minute, stepeni;

	printf ("Unesite koordinate tacke t1: ");
	scanf ("%lf %lf", &x1, &y1);
	printf ("Unesite koordinate tacke t2: ");
	scanf ("%lf %lf", &x2, &y2);
	printf ("Unesite koordinate tacke t3: ");
	scanf ("%lf %lf", &x3, &y3);
	
	/* Racunanje duzine stranica trougla */
	
	a = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		AB = sqrt(a);
	b = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
		BC = sqrt(b);
	c = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
		AC = sqrt(c);
		
	if ((fabs(AC * AC + BC * BC - AB * AB) < eps) || (fabs(AB * AB + AC * AC - BC * BC) < eps) || (fabs(AB * AB + BC * BC - AC * AC) < eps))
		printf("Pravougli\n");
		
	g = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
	if (fabs(g) < eps)
		printf ("Linija\n");
		
	else if ((fabs(AB - AC) < eps && fabs(AB - BC) > eps && fabs(AC - BC) > eps) || (fabs(AB - BC) < eps && fabs(AB - AC) > eps && fabs(BC - AC) > eps) ||
			(fabs(AC - BC) < eps && fabs(AC - AB) > eps && fabs(BC - AB) > eps))
		printf ("Jednakokraki\n");
		
	else if ((fabs(AB - BC) > eps) && (fabs(AB - AC) > eps) && (fabs(BC - AC) > eps))
		printf ("Raznostranicni\n");

	else if ((fabs(AB - BC) < eps) && (fabs(BC - AC) < eps) && (fabs(AC - AB) < eps))
		printf ("Jednakostranicni\n");
	/* Racunanje uglova u trouglu */
	
	d = (AC * AC + AB * AB - (BC * BC)) / (2 * AC * AB);
		alpha = acos (d);
	e = (BC * BC + AB * AB - (AC * AC)) / (2 * BC * AB);
		beta = acos (e);
	f = (BC * BC + AC * AC - (AB * AB)) / (2 * BC * AC);
		gama = acos (f);
		
	if ((AB > AC) && (AB > BC))
		najveci_ugao = gama;
	else if ((AC > AB) && (AC > BC))
		najveci_ugao = beta;
	else if ((BC > AC) && (BC > AB))
		najveci_ugao = alpha;
		
	/* Konverzija radijana u stepene, minute i sekunde */
	
	ukupno_sekundi = (int) round(najveci_ugao * 180 * 60 * 60 / PI);
	sekunde = ukupno_sekundi % 60;
	minute = (ukupno_sekundi / 60) % 60;
	stepeni = ukupno_sekundi / (60 * 60);
	
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
	
			
	return 0;
}

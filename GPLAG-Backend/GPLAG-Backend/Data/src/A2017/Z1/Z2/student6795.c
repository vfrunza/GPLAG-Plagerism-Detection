#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
#define PI 3.14159265359	

int main() {
	double tx1,ty1,tx2,ty2,tx3,ty3;
	double AB,BC,AC;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&tx1, &ty1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&tx2, &ty2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&tx3, &ty3);

//------------------------------------------------------------------------------

	AB = sqrt((tx2 - tx1) * (tx2 - tx1) + (ty2 - ty1) * (ty2 - ty1));
	BC = sqrt((tx3 - tx2) * (tx3 - tx2) + (ty3 - ty2) * (ty3 - ty2));
	AC = sqrt((tx1 - tx3) * (tx1 - tx3) + (ty1 - ty3) * (ty1 - ty3));
	
	double a,b,c;
	a = AB;
	b = BC;
	c = AC;
	
	double alfa,beta,gama;
	alfa = acos((a*a + b*b - c*c)/(2*a*b)) * (180./PI);
	beta = acos((c*c + a*a - b*b)/(2*c*a)) * (180./PI);
	//gm = 180.;
	gama = 180. - beta - alfa;
	
	float najveci;
	if ((gama > alfa) && (gama > beta))
	najveci = gama;
	else if ((beta > alfa) && (beta > gama))
	najveci = beta;
	else if ((alfa > gama) && (alfa > beta))
	najveci = alfa;
	int bt = (int)beta;
	int af = (int)alfa;
	int gm = (int)gama;
	


	int aa,bb,cc;
	aa = (int)(a);
	bb = (int)(b);
	cc = (int)(c);
//ISPITIVANJE
	int ugao = (int) najveci;
	if (ugao == 180)
	{
	printf("Linija\n");
	printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	return 0;
	}
	else if (ugao == 60)
	{
	printf("Jednakostranicni\n");
	printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
	return 0;
	}
	
	
	
	
	 if (ugao == 90)
	{
	printf("Pravougli\n");
	}
	
	
	
	
	//if(   ((fabs(a-b)>EPSILON) && (a != c) && (b != c)) || ((fabs(b-c)>EPSILON) && (b != a) && (c != a)) || ((fabs(a-c)>EPSILON) && (a != b) && (b != c)))
	//if (a>=(b + EPSILON) || a<=(b - EPSILON) && b>=(c + EPSILON) || b<=(c - EPSILON) && a>=(c + EPSILON) || a<=(c - EPSILON))
	if((a!=b) && (a!=c) && (b!=c) && (fabs(a-b)>EPSILON) && (fabs(a-c)>EPSILON) && (fabs(b-c)>EPSILON))
	printf("Raznostranicni\n");
	//if ( ((a == b) && (a != c)) || ((b == c) && (b != a)) || ((a == c) && (a != b)))
	if(   ((fabs(a-b)<EPSILON) && (a != c) && (b != c)) || ((fabs(b-c)<EPSILON) && (b != a) && (c != a)) || ((fabs(a-c)<EPSILON) && (a != b) && (b != c)))
	printf("Jednakokraki\n");
	
//	printf("%.15lf %.15lf %lf",a,b,c);
//	printf("%i %i %i",aa,bb,cc);
	
	
	
	
	
	float u,m,s;
	
	
	u = najveci - ugao;
	m = (u * 60.);
	int min = (int)(m);
	s = (u - min/60.) * 3600.;
	int sec = (int)(s);
	
	
	printf("Najveci ugao ima %i stepeni, %i minuta i %i sekundi.",ugao,min,sec);
	
	//printf("%lf %lf %lf, %lf",a,b,c,ugao);

	return 0;
}

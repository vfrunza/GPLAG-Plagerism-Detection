#include <stdio.h>
#include <math.h>
#define EPS 0.0001
#define PI 3.141593

int main() {
	int Au, Ast, Am, Asek, Bu, Bst, Bm, Bsek, Gu, Gst, Gm, Gsek;
	double x1, x2, y1, y2, x3, y3, alfa, beta, gama, a, b, c;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	/* stranice */
	a=sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
	b=sqrt(pow(x3-x1, 2) + pow(y3-y1, 2));
	c=sqrt(pow(x2-x3, 2) + pow(y2-y3, 2));
	
    /* uglovi */
	alfa=acos((pow(c,2)+pow(b,2)-pow(a,2))/(2*b*c));
	beta=acos((pow(c,2)+pow(a,2)-pow(b,2))/(2*a*c));
	gama=acos((pow(a,2)+pow(b,2)-pow(c,2))/(2*b*a));
	
	/* racunanje uglova i tako to */ 
	Au = (int)round(alfa*360*60*60/(2*PI));
	Asek = Au%60;
	Am = (Au/60)%60;
	Ast = Au/(60*60);
	
	/* "Bu" is for educational purposes only. 
	Even though it resembles a typical ghost's 'BOO' it is not intended to scare random folk, just a witty coincidence. */
	Bu = (int)round(beta*360*60*60/(2*PI));
	Bsek = Bu%60;
	Bm = (Bu/60)%60;
	Bst = Bu/(60*60);
	
	Gu=(int)round(gama*360*60*60/(2*PI));
	Gsek = Gu%60;
	Gm = (Gu/60)%60;
	Gst = Gu/(60*60);
	
	/* vrsta trougla */ 
	
    if (((Ast==180)&&(Am==0)&&(Asek==0)) || ((Bst==180)&&(Bm==0)&&(Bsek==0)) || ((Gst==180)&&(Gm==0)&&(Gsek==0)))
	printf("Linija\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	else
	{
	if(fabs(a-b)<EPS && fabs(b-c)<EPS && fabs(a-c)<EPS)
	printf("Jednakostranicni\n");
	
	if(((Ast==90)&&(Am==0)&&(Asek==0)) || ((Bst==90)&&(Bm==0)&&(Bsek==0)) || ((Gst==90)&&(Gm==0)&&(Gsek==0)))
	printf ("Pravougli\n");
	 
	if(fabs(a-b)<EPS && fabs(a-c)>EPS && fabs(b-c)>EPS)
	printf("Jednakokraki\n");
	else if(fabs(a-c)<EPS && fabs(b-c)>EPS && fabs(a-b)>EPS)
	printf("Jednakokraki\n");
	else if(fabs(b-c)<EPS && fabs(a-b)>EPS && fabs(a-c)>EPS)
	printf("Jednakokraki\n");
	else if(fabs(a-b)>EPS && fabs(c-b)>EPS && fabs(a-c)>EPS)
	printf("Raznostranicni\n");

	
	/* najveci ugao ispis*/ 
	if ((alfa>beta) && (alfa>gama))
	printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", Ast, Am, Asek);
	else if ((gama>alfa) && (gama>beta))
	printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", Gst, Gm, Gsek);
	else if ((beta>alfa) && (beta>gama))
    printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", Bst, Bm, Bsek);
	}
	
	return 0;
}

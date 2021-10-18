#include <stdio.h>
#include <math.h>

#define eps 0.0001
#define PI 3.14159265

int main() {
	double x1, y1, x2, y2, x3, y3;
	double a, b, c, max_ugao=0; /*stranice trougle*/
	int stepen, minute, sekunde;
	double A, B, C, P;	
	printf("Unesite koordinate tacke t1: ");
	scanf ("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	/*duzine stranica*/
	a=sqrt(pow(x2-x3, 2)+pow(y2-y3, 2));
	b=sqrt(pow(x1-x3, 2)+pow(y1-y3, 2));
	c=sqrt(pow(x1-x2, 2)+pow(y1-y2, 2));
	
	/*pocrsina trougla,da bi provjerili postoji li taj trougao*/
	P=x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2);
	P=fabs(P);
	/*uglovi po kosinusnomj teoremi*/

	A=acos((b*b+c*c-a*a)/(2*b*c))*(180./PI);
	B=acos((a*a+c*c-b*b)/(2*a*c))*(180./PI);
	C=acos((b*b+a*a-c*c)/(2*b*a))*(180./PI);
	
	if(fabs(P)<eps) printf("Linija\n");
	else {
		if(fabs(A-90)<eps || fabs(B-90)<eps || fabs(C-90)<eps ) printf("Pravougli\n");
		if (fabs(a-b)<eps && fabs(b-c)<eps) printf("Jednakostranicni\n");
		else if(fabs(a-b)<eps || fabs(a-c)<eps || fabs(b-c)<eps) printf("Jednakokraki\n");
		else printf ("Raznostranicni\n");
		
		}
	
	if(P<eps) max_ugao = 180;
	else if(A>=B && A>=C ) max_ugao = A;
	else if (B>=A && B>=C) max_ugao= B;
	else max_ugao = C;
	
	stepen= (int)max_ugao;
	minute = (int)((max_ugao - (int)max_ugao)* 60);
	sekunde = (int)((((max_ugao - (int)max_ugao)* 60)-minute)*60);
	
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, minute, sekunde);
	
	return 0;
}

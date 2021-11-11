#include <stdio.h>
#include <math.h>
#define PI 3.14
#define E 0.0001

int main() 
{
	double x1,x2,x3,y1,y2,y3;
	double a,b,c,L,B,C,max;
	int ukupnosekundi,istina=1;
	int s,min,stepen;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);

	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	L=acos((b*b+c*c-a*a)/(2*b*c));
	B=acos((c*c+a*a-b*b)/(2*c*a));
	L=acos((a*a+b*b-c*c)/(2*a*b));
	
	if(fabs((a*a+b*b)-c*c)<E || fabs((a*a+c*c)-b*b)<E || fabs((b*b+c*c)-a*a)<E) {
			printf("Pravougli\n"); }
	if(fabs(a-b)<E && fabs(b-c)<E) {
			printf("Jednakostranicni\n"); }
	if(fabs((a+b)-c)<E || fabs((a+c)-b)<E || fabs((b+c)-a)<E) {	
			istina=0;
			printf("Linija\n"); }
	if(((fabs(a-b)<E && fabs(a-c)>E && fabs(b-c)>E) || (fabs(a-c)<E && fabs(a-b)>E && fabs(c-b)>E) || (fabs(c-b)<E && fabs(b-a)>E && fabs(c-a)>E)) && (istina=1)) {
			printf("Jednakokraki\n"); }
	if(fabs(a-b)>E && fabs(a-c)>E && fabs(b-c)>E) {
			printf("Raznostranicni\n"); }
	if(L>B && L>C) {
			max=L; }
	if(B>L && B>C) {
			max=B; }	
	if(C>L && C>B) {
			max=C; }
	ukupnosekundi=(max*360*60*60/(2*M_PI));
	s=ukupnosekundi%60;
	min=(ukupnosekundi/60)%60;
	stepen=ukupnosekundi/(60*60);
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen,min,s);
	
return 0;
	}		
	
	
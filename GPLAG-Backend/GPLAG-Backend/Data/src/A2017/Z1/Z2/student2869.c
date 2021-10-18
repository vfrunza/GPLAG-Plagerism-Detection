#include <stdio.h>
#include <math.h>
const double PI = 3.1415;
const double EPSILON = 0.0001;
int main()
{
	double x1,x2,x3,y1,y2,y3,a,b,c,P,kut1,kut2,kut3,min1,min2,min3,sec1,sec2,sec3;
	int kut11,kut22,kut33,min11,min22,min33,sec11,sec22,sec33;
	printf ("Unesite koordinate tacke t1: ");
	scanf ("%lf%lf", &x1, &y1);
	printf ("Unesite koordinate tacke t2: ");
	scanf ("%lf%lf", &x2, &y2);
	printf ("Unesite koordinate tacke t3: ");
	scanf ("%lf%lf", &x3, &y3);
	a = sqrt ((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));
	b = sqrt ((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1));
	c = sqrt ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	P= 1/2. * ((fabs (x1*(y2-y3)))+(fabs(x2*(y3-y1)))+(fabs(x3*(y1-y2))));
	if (P=0) {
		printf ("\nLinija");
	}
	if ((fabs(a-b)<EPSILON) && (fabs(b-c)<EPSILON) && (fabs(c-a)<EPSILON)) {
		printf ("\nJednakostranicni"); 
		} else if ( ((fabs(a*a-b*b-c*c))<EPSILON) || ((fabs(b*b-a*a-c*c))<EPSILON) || ((fabs (c*c-b*b-a*a))<EPSILON) ) {
			printf ("\nPravougaoni");
		} else if ( (((fabs(a-b))<EPSILON) && ((fabs(b-c))>EPSILON) && ((fabs(c-a))>EPSILON)) || ((fabs(a-c))<EPSILON && (fabs(b-c))>EPSILON && (fabs(a-b))>EPSILON) || ((fabs(b-c))<EPSILON && (fabs(a-b))>EPSILON && (fabs(a-c))>EPSILON)) {
			printf ("\nJednakokraki");
		} else if ((fabs(a-b))>EPSILON && (fabs(a-c))>EPSILON && (fabs(b-c))>EPSILON) {
			printf ("Raznostranicni");
		}
		kut1 = acos((b*b + c*c - a*a)/(2*b*c))*(180/PI)+EPSILON;
		kut2 = acos((a*a + c*c - b*b)/(2*a*c))*(180/PI)+EPSILON;
		kut3 = acos((b*b + a*a - c*c)/(2*b*a))*(180/PI)+EPSILON;

		kut11 = kut1/1;
		kut22 = kut2/1;
		kut33 = kut3/1;
		
		min1= (kut1-kut11)*60;
		min11= min1/1;
		sec1 = (min1-min11)*60;
		sec11 = sec1/1;
		
		min2 = (kut2-kut22)*60;
		min22= min2/1;
		sec2=(min2-min22)*60;
		sec22=sec2/1;
		
		min3 = (kut3-kut33)*60;
		min33 = min3/1;
		sec3 = (min3-min33)*60;
		sec33 = sec3/1;
		
if (kut1==kut2 && kut3==kut2 && kut3==kut1);
	printf ("\nNajveci ugao ima 60 stepeni, 0 minuta i 0 sekundi");
if (kut1>kut2 && kut1>kut3) {
	printf ("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", kut11, min11, sec11); }
else if (kut2>kut1 && kut2>=kut3) {
	printf ("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", kut22, min22, sec22); }
else if (kut3>kut1 && kut3>kut2) {
	printf ("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", kut33, min33, sec33); }
	return 0;
}

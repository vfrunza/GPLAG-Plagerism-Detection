#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.14159265


	int main() {
	double t1x, t1y, t2x, t2y, t3x, t3y, a, b, c, s, vr1, vr2, vr3, alfa1, alfa2, alfa3;
	int stepeni, minute, sekunde;
	
	printf ("Unesite koordinate tacke t1: ");
	scanf ("%lf %lf", &t1x, &t1y);
	
	printf ("Unesite koordinate tacke t2: ");
	scanf ("%lf %lf", &t2x, &t2y);

	printf ("Unesite koordinate tacke t3: ");
	scanf ("%lf %lf", &t3x, &t3y);
	
	/*racunanje duzina stranica*/
	a = sqrt (pow ((t3x-t2x), 2) + pow ((t3y-t2y), 2));
	b = sqrt (pow ((t1x-t3x), 2) + pow ((t1y-t3y), 2));
	c = sqrt (pow ((t1x-t2x), 2) + pow ((t1y-t2y), 2));
	s = (a+b+c)/2;
	
	/*racunanje uglova preko kosinusne teoreme*/
		vr1=(b*b + c*c - a*a)/(2.0*b*c);
		vr2=(a*a + c*c - b*b)/(2.0*a*c);
		vr3=(a*a + b*b - c*c)/(2.0*a*b);
		alfa1=acos (vr1)*(180.0/PI);
		alfa2=acos (vr2)*(180.0/PI);
		alfa3=acos (vr3)*(180.0/PI);
	
	if (fabs(s-a)<EPSILON || fabs(s-b)<EPSILON || fabs(s-c)<EPSILON) { /*ako je povrsina jednaka nuli*/
		printf ("Linija\n");
		if (a>=b && a>=c) { /*naspram najvece stranice u trouglu se nalazi najveci ugao*/
			stepeni = alfa1;
			minute = (alfa1 - stepeni)*60;
			sekunde = ((alfa1 - stepeni)*60.0 - minute)*60;
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
		} else if (b>=a && b>=c) {
			stepeni = alfa2;
			minute = (alfa2 - stepeni)*60;
			sekunde = ((alfa2 - stepeni)*60.0 - minute)*60;;
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
		} else {
			stepeni = alfa3;
			minute = (alfa3 - stepeni)*60;
			sekunde = ((alfa3 - stepeni)*60.0 - minute)*60;
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
		}
		
		
	} else if (fabs (a-b)<EPSILON && fabs (b-c)<EPSILON) {
		printf ("Jednakostranicni\n");
		if (a>=b && a>=c) { 
			stepeni = alfa1;
			minute = (alfa1 - stepeni)*60;
			sekunde = ((alfa1 - stepeni)*60.0 - minute)*60;
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
		} else if (b>=a && b>=c) {
			stepeni = alfa2;
			minute = (alfa2 - stepeni)*60;
			sekunde = ((alfa2 - stepeni)*60.0 - minute)*60;;
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
		} else {
			stepeni = alfa3;
			minute = (alfa3 - stepeni)*60;
			sekunde = ((alfa3 - stepeni)*60.0 - minute)*60;
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
		}
		
	} else if (fabs(c-sqrt(pow(a,2) + pow(b,2)))<EPSILON || fabs(a-sqrt(pow(b,2) + pow(c,2)))<EPSILON || fabs(b-sqrt(pow(a,2) + pow(c,2)))<EPSILON) {
		printf ("Pravougli\n");
		if (fabs (a-b)<EPSILON || fabs (b-c)<EPSILON || fabs (a-c)<EPSILON) {
			printf ("Jednakokraki\n");
		} else printf ("Raznostranicni\n");
		
		if (a>=b && a>=c) { /*naspram najvece stranice u trouglu se nalazi najveci ugao*/
			stepeni = alfa1;
			minute = (alfa1 - stepeni)*60;
			sekunde = ((alfa1 - stepeni)*60.0 - minute)*60;
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
		} else if (b>=a && b>=c) {
			stepeni = alfa2;
			minute = (alfa2 - stepeni)*60;
			sekunde = ((alfa2 - stepeni)*60.0 - minute)*60;;
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
		} else {
			stepeni = alfa3;
			minute = (alfa3 - stepeni)*60;
			sekunde = ((alfa3 - stepeni)*60.0 - minute)*60;
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
		}
		
	} else if (fabs (a-b)<EPSILON || fabs (b-c)<EPSILON || fabs (a-c)<EPSILON) {
		printf ("Jednakokraki\n");
		
		
		if (a>=b && a>=c) { 
			stepeni = alfa1;
			minute = (alfa1 - stepeni)*60;
			sekunde = ((alfa1 - stepeni)*60.0 - minute)*60;
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
		} else if (b>=a && b>=c) {
			stepeni = alfa2;
			minute = (alfa2 - stepeni)*60;
			sekunde = ((alfa2 - stepeni)*60.0 - minute)*60;;
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
		} else {
			stepeni = alfa3;
			minute = (alfa3 - stepeni)*60;
			sekunde = ((alfa3 - stepeni)*60.0 - minute)*60;
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
		}
	} else  {
		printf ("Raznostranicni\n");
	
		if (a>=b && a>=c) {
			stepeni = alfa1;
			minute = (alfa1 - stepeni)*60;
			sekunde = ((alfa1 - stepeni)*60.0 - minute)*60;
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
		} else if (b>=a && b>=c) {
			stepeni = alfa2;
			minute = (alfa2 - stepeni)*60;
			sekunde = ((alfa2 - stepeni)*60.0 - minute)*60;
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
		} else {
			stepeni = alfa3;
			minute = (alfa3 - stepeni)*60;
			sekunde = ((alfa3 - stepeni)*60.0 - minute)*60;
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
		}
		
		
	}
	
	
	return 0;
}

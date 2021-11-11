#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.141592653589793238
int main() {
	double x1, y1, x2, y2, x3, y3, d1, d2, d3, alfa, ugao;
	 int stepeni, minute, sekunde;
	printf("Unesite koordinate tacke t1: ");
	scanf ("%lf %lf", &x1, &y1);
	printf ("Unesite koordinate tacke t2: ");
	scanf ("%lf %lf", &x2, &y2);
	printf ("Unesite koordinate tacke t3: ");
	scanf ("%lf %lf", &x3, &y3);
	d1=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	d2=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	d3=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	  
	  
      if ((fabs(d1*d1-d2*d2+d3*d3)<EPSILON)||(fabs(d2*d2-d1*d1+d3*d3)<EPSILON)||(fabs(d3*d3-d1*d1+d2*d2)<EPSILON)){ printf ("Pravougli\n");}

	
	  
	
	if (fabs((x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)))<EPSILON){ printf ("Linija\n");}
	else if ((fabs(d1-d2)<EPSILON) && (fabs(d1-d3)<EPSILON) && (fabs(d2-d3)<EPSILON)) printf ("Jednakostranicni\n");
	
	 else if (((fabs(d1-d2)<EPSILON) && (d1!=d3))||((fabs(d2-d3)<EPSILON) && (d2!=d1))||((fabs(d1-d3)<EPSILON) && (d1!=d2))){ printf ("Jednakokraki\n"); }
	 else if ((d1!=d3) && (d1!=d2) && (d2!=d3)) { printf ("Raznostranicni\n");}
	if ((d1>=d2)&& (d1>=d3)){
			alfa=((d2*d2+d3*d3-d1*d1)/(2*d2*d3));
			ugao=((acos(alfa))*(180/PI));}
	   
		else if ((d2>=d1)&&(d2>=d3)){
			alfa=((d1*d1+d3*d3-d2*d2)/(2*d1*d3));
			ugao=((acos(alfa))*(180/PI));}
		
		else if ((d3>d2)&&(d3>d1)){
			alfa=((d2*d2+d1*d1-d3*d3)/(2*d2*d1));
			ugao=((acos(alfa))*(180/PI));
		}
		stepeni=(int)ugao;
			ugao=ugao-(int)ugao;
			ugao=ugao*60;
			minute=(int)ugao;
			ugao=ugao-(int)ugao;
			ugao=ugao*60;
			sekunde=trunc(ugao);
			
		printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
	
	return 0;
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPSILON 0.0001
#define PI 3.1415926

int main() {
	double x1, x2, x3, y1, y2, y3, a, b, c, alfa, beta, gama, min1, min2, min3;
	int step1, step2, step3, ost1, ost2, ost3, sek1, sek2, sek3;
	/*unos koordinata tacaka*/
	printf ("Unesite koordinate tacke t1: ");
	scanf ("%lf %lf", &x1, &y1);
	printf ("Unesite koordinate tacke t2: ");
	scanf ("%lf %lf", &x2, &y2);
	printf ("Unesite koordinate tacke t3: ");
	scanf ("%lf %lf", &x3, &y3);
	/*racunanje stranica trougla*/
	a = sqrt ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	b = sqrt ((y2-y3)*(y2-y3)+(x2-x3)*(x2-x3));
	c = sqrt ((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	
	/*racunanje uglova - kosinusna teorema*/
	gama = acos ((a*a+b*b-c*c)/(2*a*b));
	alfa = acos ((b*b+c*c-a*a)/(2*c*b));
	beta = acos ((a*a+c*c-b*b)/(2*a*c));
	
	/* pretvaranje radijana u stepene*/ 
	alfa = alfa*(180/PI);
	step1 = (int) (alfa);
	min1 = (alfa-step1) * 60;
	ost1 = (int) min1;
	sek1 = (min1-ost1)*60;
	
	beta = beta*(180/PI);
	step2 = (int) (beta);
	min2 = (beta-step2)*60;
	ost2 = (int) (min2);
	sek2 = (min2-ost2)*60;
	
	gama = gama*(180/PI);
	step3 = (int) (gama);
	min3 = (gama-step3)*60;
	ost3 = (int) (min3);
	sek3 = (min3-ost3)*60;
	
	/*nejednakost trougla*/
	if (a<b+c && b<a+c && c<a+b)
	   {
	   	   	/*jednakostranicni*/
        	if (fabs(a-b)<EPSILON && fabs (a-c)<EPSILON)
	        {
	        	printf ("Jednakostranicni\n"); /*svi uglovi jednaki*/
                printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", step1, ost1, sek1);
	        }  
	               /*jednakokraki*/
	      else if (fabs (b-c)<EPSILON || fabs (a-c)<EPSILON || fabs (a-b)<EPSILON)
	        {
	        	if (step1==90 || step2==90 || step3==90) printf ("Pravougli\n");
	        	printf ("Jednakokraki\n");
	        	if  (alfa>=gama*beta)
	        	printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", step1, ost1, sek1);
	        	else if (beta>=alfa*gama) printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", step2, ost2, sek2);
	        	else printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", step3, ost3, sek3);
	        }	
    
            	/*raznostranicni*/        
	    else {
	    	if (step1==90 || step2==90 || step3==90) printf ("Pravougli\n");
	    	printf ("Raznostranicni\n");
		    if (gama>beta && gama>alfa)
		    printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", step3, ost3, sek3);
		    else if (alfa>beta && alfa>gama)
	    	printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", step1, ost1, sek1);
		    else printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", step2, ost2, sek2);
         	}
	   } 	
	/*linija*/
else {
	   	printf ("Linija\n");
	   	if (alfa>beta && alfa>gama)
	   	printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", step1, ost1, sek1);
	   	if (beta>alfa && beta>gama)
	   	printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", step2, ost2, sek2);
        else printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", step3, ost3, sek3);
	   }
	return 0;
}

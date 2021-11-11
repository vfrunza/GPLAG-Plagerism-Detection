#include <stdio.h>
#define EPSILON 0.0001
#include <math.h>

int main() {
	double t1_x, t1_y, t2_x, t2_y, t3_x, t3_y, t1t2, t2t3, t3t1;
	int jednakokraki=0, max, stepeni, minuta, sekunda;
	double alfa, beta, gama;
	printf ("\nUnesite koordinate tacke t1: ");
	scanf("%lf %lf", &t1_x, &t1_y);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &t2_x, &t2_y);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &t3_x, &t3_y);
	
	t1t2=sqrt ((t2_x-t1_x)*(t2_x-t1_x) + (t2_y-t1_y)*(t2_y-t1_y));
	t3t1=sqrt ((t3_x-t1_x)*(t3_x-t1_x) + (t3_y-t1_y)*(t3_y-t1_y));
	t2t3=sqrt ((t3_x-t2_x)*(t3_x-t2_x) + (t3_y-t2_y)*(t3_y-t2_y));
	
	if( (t1t2 + t2t3 == t3t1) || (t1t2 + t3t1 == t2t3) || (t3t1 + t2t3 == t1t2)) printf("Linija");
	else if (fabs(t1t2 - t2t3) < EPSILON  && fabs(t2t3 - t3t1) < EPSILON) printf("Jednakostranicni");
	else if(fabs(t1t2 - t2t3) > EPSILON && fabs(t2t3 - t3t1) > EPSILON && fabs(t1t2 - t3t1) > EPSILON)
	printf("Raznostranicni");
	else if(fabs (t1t2 - t2t3) < EPSILON || fabs (t1t2 - t3t1) < EPSILON || (t3t1-t2t3)< EPSILON) {
		jednakokraki=1; 
		printf("Jednakokraki"); }
	else if(fabs(t1t2*t1t2 + t2t3*t2t3 - t3t1*t3t1) < EPSILON || fabs(t2t3*t2t3 + t3t1*t3t1 - t1t2*t1t2) < EPSILON || fabs(t3t1*t3t1 + t1t2*t1t2 - t2t3*t2t3)<EPSILON) printf("\nPravougli");
	else if(fabs(t1t2*t1t2 + t2t3*t2t3 - t3t1*t3t1) < EPSILON && jednakokraki==1 || fabs(t2t3*t2t3 + t3t1*t3t1 - t1t2*t1t2) < EPSILON && jednakokraki==1 || fabs(t3t1*t3t1 +  t1t2*t1t2 - t2t3*t2t3) < EPSILON && jednakokraki==1){
	printf("Pravougli \nJednokraki");
	}
	else if((fabs(t1t2 - t2t3) > EPSILON && fabs(t2t3 - t3t1) > EPSILON && fabs(t1t2 - t3t1) > EPSILON) && (fabs(t1t2*t1t2 + t2t3*t2t3 - t3t1*t3t1) < EPSILON || fabs(t2t3*t2t3 + t3t1*t3t1 - t1t2*t1t2) < EPSILON || fabs(t3t1*t3t1 + t1t2*t1t2 - t2t3*t2t3)<EPSILON))
	printf("Raznostranicni \nPravougli");
	alfa=acos((t3t1*t3t1 + t1t2*t1t2 - t2t3*t2t3)/(2*t3t1*t1t2))*180./(4* atan(1));
	beta=acos((t2t3*t2t3 + t1t2*t1t2 - t3t1*t3t1)/(2*t2t3*t1t2))*180./(4* atan(1));
	gama=acos((t2t3*t2t3 + t3t1*t3t1 - t1t2*t1t2)/(2*t2t3*t3t1))*180./(4* atan(1));
    max = alfa;
    if(beta>max) max=beta;
    else if(gama>max) max=gama;
   stepeni = (int) max;
	max-=stepeni;
   minuta= (int) (60*max);
	max-=minuta;
	max*=60;
	sekunda = (int) (60*max);
	
	printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minuta, sekunda);
	
	return 0;
}

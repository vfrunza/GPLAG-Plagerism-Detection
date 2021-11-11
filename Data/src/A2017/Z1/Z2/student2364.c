#include <stdio.h>
#define epsilon 0.0001
#define pi 3.1415926535897932384
#include <math.h>

int main() {
	double x1,x2,x3,y1,y2,y3;
	double ug1,ug2,ug3,o,p,q,max;
	int sek,min,stepe;
	int uksek,ist=1;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	o=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	p=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	q=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	
		ug1=acos((p*p+q*q-o*o)/(2*p*q));
		ug2=acos((q*q+o*o-p*p)/(2*q*o));
		ug3=acos((o*o+p*p-q*q)/(2*o*p));
	
					if(fabs((o*o+p*p)-q*q)<epsilon || fabs((o*o+q*q)-p*p)<epsilon || fabs((p*p+q*q)-o*o)<epsilon) {
						printf("Pravougli\n");
	}
					if(fabs((o+p)-q)<epsilon || fabs((o+q)-p)<epsilon || fabs((p+q)-o)<epsilon) {
		  				ist=0;
						printf("Linija\n");
	}
					if(fabs(o-p)<epsilon && fabs(p-q)<epsilon) {
					   ist=0;
						printf("Jednakostranicni\n");
					}
					
					if(fabs(o-p)>epsilon && fabs(p-q)>epsilon && fabs(o-q)>epsilon) {
						printf("Raznostranicni\n");
					}
					if((fabs(o-p)<epsilon || fabs(o-q)<epsilon || fabs(q-p)<epsilon) && (ist==1))   {
						
						printf("Jednakokraki\n");
					}
					
						if(ug1>ug2 && ug1>ug3) {
							max=ug1;
						}
						if(ug2>ug3 && ug2>ug1) {
							max=ug2;
						}
						if(ug3>ug2 && ug3>ug1) {
							max=ug3;
						}
						
						uksek=(max*360*60*60/(2*pi));
						sek=uksek%60;
						min=(uksek/60)%60;
						stepe=uksek/(60*60);
						
					printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepe,min,sek);
					
	return 0;
}

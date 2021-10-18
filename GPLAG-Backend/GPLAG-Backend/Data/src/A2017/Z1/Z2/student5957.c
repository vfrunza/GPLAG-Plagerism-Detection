#include <stdio.h>
#include <math.h>
#define epsilon 0.0001

int main() {
	double  a=0,b=0,c=0,x1=0,y1=0,x2=0,y2=0,x3=0,y3=0,ugao_bar=0,ugao_car=0,ugao_cbr=0,stepeni_max=0;
	double sekunde_ba=0,sekunde_ca=0,sekunde_cb=0,minute_ba=0,minute_ca=0,minute_cb=0,stepeni_ba=0,stepeni_ca=0,stepeni_cb=0;
	double PI=4*atan(1);
	printf("Unesite koordinate tacke t1: ");
	scanf(" %lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf(" %lf %lf",&x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf(" %lf %lf",&x3,&y3);
	
		a=(sqrt(((x3-x1)*(x3-x1)) + ((y3-y1)*(y3-y1))));
		b=(sqrt(((x2-x1)*(x2-x1))+ ((y2-y1)*(y2-y1))));
		c=(sqrt(((x3-x2)*(x3-x2))+((y3-y2)*(y3-y2))));
		ugao_bar=acos((a*a+b*b-c*c)/(2*a*b));
		ugao_car=acos((c*c+a*a-b*b)/(2*c*a));
		ugao_cbr=acos((b*b+c*c-a*a)/(2*b*c));
		
		stepeni_ba=(ugao_bar*(180./PI));
		stepeni_ca=(ugao_car*(180./PI));
		stepeni_cb=(ugao_cbr*(180./PI));
		
		if(fabs(stepeni_ba-(90.00))<=epsilon || fabs(stepeni_cb-(90.00))<=epsilon || fabs(stepeni_ca-(90.00))<=epsilon){
			printf("Pravougli\n");
		}
		if(fabs(a-b)<=epsilon && fabs(b-c)<=epsilon) {
			printf("Jednakostranicni");
		} else if((fabs(stepeni_ca-180)<=epsilon || fabs(stepeni_cb-180)<=epsilon || fabs(stepeni_ba-180)<=epsilon)) {
			printf("Linija");
		
		}else if((fabs(a-b)<=epsilon && fabs(c-a)>epsilon) || (fabs(a-c)<=epsilon && fabs(a-b)>epsilon) || (fabs(b-c)<=epsilon && fabs(a-b)>epsilon)) {
			printf("Jednakokraki");
		} else if (fabs(a-b)>epsilon && fabs(b-c)>epsilon) {
			printf("Raznostranicni");
		}  
		
		

		
		
		if (stepeni_ba>stepeni_max) {
			stepeni_max=(int)stepeni_ba;
		}
		minute_ba=(stepeni_ba- (int)stepeni_ba)*60;
		sekunde_ba=(minute_ba- (int)minute_ba)*60;
		
		
		if (stepeni_ca>stepeni_max) {
			stepeni_max=(int)stepeni_ca;
		}
		minute_ca=(stepeni_ca-(int)stepeni_ca)*60;
		sekunde_ca=(minute_ca-(int)minute_ca)*60;
			
		
		if(stepeni_cb>stepeni_max) {
			stepeni_max=(int)stepeni_cb; 
			
		}
		minute_cb=(stepeni_cb-(int)stepeni_cb)*60;
		sekunde_cb=(minute_cb-(int)minute_cb)*60;
		
			
	
		
		if ((int)stepeni_max==(int)stepeni_ba) {
			printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.",(int)stepeni_max,(int)minute_ba,(int)sekunde_ba);
		} else if((int)stepeni_max==(int)stepeni_ca) {
			printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.",(int)stepeni_max,(int)minute_ca,(int)sekunde_ca);
		} else if((int)stepeni_max==(int)stepeni_cb) {
			printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.",(int)stepeni_max,(int)minute_cb,(int)sekunde_cb);
		}
	
		
	
	return 0;
}

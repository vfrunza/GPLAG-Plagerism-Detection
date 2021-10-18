#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.14159

int main() {
	double a, b, c, x1, x2, x3, y1, y2, y3, ugao1, ugao2, ugao1_step, ugao2_step, ugao3_step;
	int  ugao1_cijelistep, ugao2_cijelistep,  ugao1_min,   ugao2_min,  ugao1_sek, ugao2_sek, ugao3_cijelistep, ugao3_min, ugao3_sek;

	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);

	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);

	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	b=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	c=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	ugao1=acos((b*b+c*c-a*a)/(2*b*c));
	ugao2=acos((a*a+c*c-b*b)/(2*a*c));
	
	ugao1_step=(ugao1*180)/PI;
	ugao1_cijelistep=(int)(ugao1_step);
	ugao1_min=(ugao1_step-ugao1_cijelistep)*60;
	ugao1_sek=( ((ugao1_step-ugao1_cijelistep)*60)-(int)((ugao1_step-ugao1_cijelistep)*60) )*60;	

	ugao2_step=(ugao2*180)/PI;
	ugao2_cijelistep=(int)(ugao2_step);
	ugao2_min=(ugao2_step-ugao2_cijelistep)*60;
	ugao2_sek=( ((ugao2_step-ugao2_cijelistep)*60)-(int)((ugao2_step-ugao2_cijelistep)*60) )*60;	
	
	ugao3_step=180-ugao1_step-ugao2_step;
	ugao3_cijelistep=(int)(ugao3_step);
	ugao3_min=(ugao3_step-ugao3_cijelistep)*60;
	ugao3_sek=( ((ugao3_step-ugao3_cijelistep)*60)-(int)((ugao3_step-ugao3_cijelistep)*60) )*60;	
	
	if(!((a+b)>c) || !((a+c)>b) || !((b+c)>a)){
	printf("Linija");
	printf("\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	return 0;
	}
	
	
	if(fabs(a-b)<EPSILON && fabs(a-c)<EPSILON){
		printf("Jednakostranicni");
		printf("\nNajveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
		return 0;
	}
	
		if(fabs((c*c)-(a*a)-(b*b))<EPSILON || fabs((a*a)-(b*b)-(c*c))<EPSILON || fabs((b*b)-(a*a)-(c*c))<EPSILON){
			printf("Pravougli");
			if((fabs(a-b)<EPSILON && fabs(a-c)>=EPSILON) || (fabs(b-c)<EPSILON && fabs(b-a)>=EPSILON) || (fabs(a-c)<EPSILON && fabs(a-b)>=EPSILON))
			printf("\nJednakokraki");
			else if(fabs(a-EPSILON)!=fabs(b-EPSILON) && fabs(a-EPSILON)!=fabs(c-EPSILON))
			printf("\nRaznostranicni");
			printf("\nNajveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
		
			
		}
		
	
		
	else if((fabs(a-b)<EPSILON && fabs(a-c)>=EPSILON) || (fabs(b-c)<EPSILON && fabs(b-a)>=EPSILON) || (fabs(a-c)<EPSILON && fabs(a-b)>=EPSILON)){
		if(fabs((c*c)-(a*a)-(b*b))>=EPSILON || fabs((a*a)-(b*b)-(c*c))>=EPSILON || fabs((b*b)-(a*a)-(c*c))>=EPSILON){
			printf("Jednakokraki");
			
			if (ugao1_step>ugao2_step && ugao1_step>ugao3_step)
			printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", ugao1_cijelistep, ugao1_min, ugao1_sek);
			
			else if(ugao2_step>ugao1_step && ugao2_step>ugao3_step)
			printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", ugao2_cijelistep, ugao2_min, ugao2_sek);
		
			else if(ugao3_step>ugao2_step && ugao3_step>ugao1_step)
			printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", ugao3_cijelistep, ugao3_min, ugao3_sek);
		}
			
	}
	
	else {
		
			printf("Raznostranicni");
			
			if(ugao1_step>ugao2_step && ugao1_step>ugao3_step)
			printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", ugao1_cijelistep, ugao1_min, ugao1_sek);
			
			else if(ugao2_step>ugao1_step && ugao2_step>ugao3_step)
			printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", ugao2_cijelistep, ugao2_min, ugao2_sek);
			
			else if(ugao3_step>ugao2_step && ugao3_step>ugao1_step)
			printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", ugao3_cijelistep, ugao3_min, ugao3_sek);
		}
	
	return 0;
}

#include <stdio.h>
#include <math.h>
#define E 0.0001
#define PI 3.1415926589793
int main()
{

	double x1, x2, x3, y1, y2, y3;
	double P, s, e, e1, f, f1, r, r1;
    double a, b, c;
	double  radA, radB, radC;
    double A,B,C;
    int  stepeni1, minute1, sekunde1, stepeni2, minute2, sekunde2, stepeni3,minute3, sekunde3;
   
	

	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf ", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf ", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf ", &x3, &y3);
    e=fabs(x2-x1);
    e1=fabs(y2-y1);
    f=fabs(x3-x2);
    f1=fabs(y3-y2);
    r=fabs(x1-x3);
    r1=fabs(y1-y3);
	a=sqrt((e*e)+(e1*e1));
	b=sqrt((f*f)+(f1*f1));
	c=sqrt((r*r)+(r1*r1));
	s=(a+b+c)/2;
	P=sqrt(s*(s-a)*(s-b)*(s-c));

	radA=acos(((b*b) + (c*c) - (a*a))/(2*b*c));
	radB=acos(((a*a)+(c*c)-(b*b))/(2*a*c));
	radC=acos(((b*b)+(a*a)-(c*c))/(2*a*b));
  
	A=(radA*180)/PI;
	B=(radB*180)/PI;
	C=(radC*180)/PI;
   
    
    

	if(P==0) {
		printf("Linija");
		printf("\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	}	else {
		 

		
		
		if(fabs(A-60)<E && fabs(B-60)<E && fabs(C-60)<E){
				printf("Jednakostranicni");
				printf("\nNajveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
			}


		else if(fabs(a-b)<E || fabs(a-c)<E || fabs(b-c)<E) {

            if(fabs(A-90)<E || fabs(B-90)<E  || fabs(C-90)<E) {
				printf("Pravougli");
				printf("\nJednakokraki");
				printf("\nNajveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
		    }
			else if(A>B && A>C && (B-C)<E) {
				stepeni1=floor(A);
				minute1=((A-stepeni1)*60);
				sekunde1=((minute1-(minute1/60)*3600));
				printf("Jednakokraki");
				printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni1, minute1, sekunde1);
			} else if(B>A && B>C && (A-C)<E) {
				stepeni2=floor(B);
				minute2=((B-stepeni2)*60);
				sekunde2=((minute2-(minute2/60)*3600));
				printf("Jednakokraki");
				printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni2, minute2, sekunde2);

			} else if(C>B && C>A && (A-B)<E ) {
				stepeni3=floor(C);
				minute3=((C-stepeni3)*60);
				sekunde3=((minute3-(minute3/60)*3600));
				printf("Jednakokraki");
				printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni3, minute3, sekunde3);

			} 
		    
		} 
		
		else if(a!=b && a!=c && b!=c) {

			if(fabs(A-90)<E || fabs(B-90)<E  || fabs(C-90)<E){
				
				printf("Pravougli");
				printf("\nRaznostranicni");
				printf("\nNajveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
			}
			else if(A>B && A>C) {
				stepeni1=floor(A);
				minute1=((A-stepeni1)*60);
			    sekunde1=(A-stepeni1-(floor(minute1)/60))*3600;
				printf("Raznostranicni");
				printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni1, minute1, sekunde1);
			} else if(B>A && B>C) {
				stepeni2=floor(B);
				minute2=((B-stepeni2)*60);
			    sekunde2=(B-stepeni2-(floor(minute2)/60))*3600;
				printf("Raznostranicni");
				printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni2, minute2, sekunde2);

			} else if(C>A && C>B) {
				stepeni3=floor(C);
				minute3=(C-stepeni3)*60;
				sekunde3=(C-stepeni3-(floor(minute3)/60))*3600;	
				printf("Raznostranicni");
				printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni3, minute3, sekunde3);

			} 
		} 


		}
	


	return 0;
}

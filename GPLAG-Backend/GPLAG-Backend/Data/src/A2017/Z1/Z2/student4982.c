#include <stdio.h>
#include <math.h>
#define e 0.0001
#define pi 3.1415926535

int main() {
	double x1,y1,x2,y2,x3,y3,a,b,c,ugao,ugao2,ugao3,S;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3,&y3);
    
     a=sqrt(pow(x2-x1,2) + pow(y2-y1,2));
     b=sqrt(pow(x3-x2,2) + pow(y3-y2,2));
     c=sqrt(pow(x1-x3,2) + pow(y1-y3,2));
     
     ugao=acos(a*a+b*b-c*c)/(2*a*b);
     ugao2=acos(c*c+a*a-b*b)/(2*c*a);
     ugao3=acos(b*b+c*c-a*a)/(2*b*c);
	 
	 if (fabs(x1-x2)<e && fabs(x2-x3)<e) {
	 	printf("Linija\n");
	 	printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.\n");
	 	return 0;
	 } else if (fabs(y1-y2)<e && fabs(y2-y3)<e) {
	 	printf("Linija\n");
	 	printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.\n");
	 	return 0;
	 }
	 
	 if(a>b && a>c && b!=c) {
	 	printf("Raznostranicni\n");
	 	ugao3=acos(b*b+c*c-a*a)/(2*b*c);
	 	S=ugao3*180.0/pi;
	 	printf("Najveci ugao ima %lf stepeni, 0 minuta i 0 sekundi.\n", S);
	 }
     
     
     if (fabs(a-b)<e && fabs(b-c)<e) {
     	printf("Jednakostranicni\n");
     	ugao=acos(a*a+b*b-c*c)/(2*a*b);
     	ugao = S*180.0/pi;
     	printf("Najveci ugao ima %lf stepeni, 0 minuta i 0 sekundi.\n", ugao);
     	return 0;
    
     
     	
     	
     	
     	
     /*	printf("%lf", a);
     	printf("%lf", b);
     	printf("%lf", c);
     	printf("%lf", B);*/
     	
     	
     		
     }return 0;
}
     	

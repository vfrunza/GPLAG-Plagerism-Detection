#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

int main() {
	
	int kontrola=0;
	double x1,y1,x2,y2,x3,y3,s1,s2,s3,P1,P2,L;
	double pi,A,B,C,s,area,R,deg,min,sek;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	
	s1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	s2=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	s3=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	
	L=s1+s3;
	if(fabs(s2-L)<EPSILON){
		printf("Linija");
		printf("\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
		return 0;
	}
	
	P1=s1*s1 + s3*s3;
	P2=s2*s2;
    
    if(fabs(P1 - P2)<EPSILON){
    	printf("Pravougli\n");
     kontrola=1;}
    
    if(fabs(s1-s2)<EPSILON && fabs(s2-s3)<EPSILON && fabs(s1-s3)<EPSILON){
    	printf("Jednakostranicni\n");
    	printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
   return 0;
    }
    	
    else if(fabs(s1-s2)<EPSILON || fabs(s2-s3)<EPSILON || fabs(s1-s3)<EPSILON){
    	printf("Jednakokraki\n");
   if(kontrola==1){printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
   return 0;}
    }
   
    else {printf("Raznostranicni\n");
    if(kontrola==1)printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");}
    
    
 pi = acos(-1);

  s = (s1 + s2 + s3) / 2;
  area = sqrt(s * (s - s1) * (s - s2) * (s - s3));

    R = (s1 * s2 * s3) / (4 * area);

    A = (180 / pi) * asin(s1 / (2 * R));
    B = (180 / pi) * asin(s3 / (2 * R));
    C = (180 / pi) * asin(s2 / (2 * R));

    if(C>A && C>B){
    	if(180-A-B>C)C=180-A-B;
        
        deg=(int)C;
        min=(C-deg)*60;
        C=(int)min;
        sek=(min-C)*60;
        sek=(int)sek;
        min=(int)min;
        
        
  printf("\nNajveci ugao ima %g stepeni, %g minuta i %g sekundi.",deg,min,sek);
  
 } else if(A>C && A>B){
    if(180-C-B>A)A=180-C-B;
    deg=(int)A;
        min=(A-deg)*60;
        A=(int)min;
        sek=(min-A)*60;
        sek=(int)sek;
        min=(int)min;
    printf("\nNajveci ugao ima %g stepeni, %g minuta i %g sekundi.",deg,min,sek);
  
  
    } else if(B>C && B>A){
    	if(180-A-C>B)B=180-A-C;
    
     deg=(int)B;
        min=(B-deg)*60;
        B=(int)min;
        sek=(min-B)*60;
        sek=(int)sek;
        min=(int)min;
     printf("\nNajveci ugao ima %g stepeni, %g minuta i %g sekundi.",deg,min,sek);
 

    }
	
	
	
	
	
	return 0;
}

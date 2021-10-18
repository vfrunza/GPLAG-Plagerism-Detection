#include <stdio.h>
#include <math.h> 
#define PI 3.141592
#define epsilon 0.001

 int main() 
{
  double xa, ya, xb, yb, xc, yc, a, b, c, alfa, beta, gama, max=0, ugao, stepeni, sec, min;
  
  
  printf("Unesite koordinate tacke t1: "); 
  scanf("%lf %lf", &xa, &ya);
  printf("Unesite koordinate tacke t2: ");
  scanf("%lf %lf", &xb, &yb);
  printf("Unesite koordinate tacke t3: "); 
  scanf("%lf %lf" ,&xc, &yc);
  
  a = sqrt(pow(xb-xc,2) + pow(yb-yc,2));
  b = sqrt(pow(xa-xc,2) + pow(ya-yc,2)); 
  c = sqrt(pow(xa-xb,2) + pow(ya-yb,2));
  
  
 if (fabs(a*a + b*b -c*c)<epsilon || (fabs(c*c+b*b-a*a)<epsilon) || (fabs(c*c+a*a-b*b)<epsilon)){
    printf ("Pravougli\n");
   }
    if ((xa*(yb-yc)+xb*(yc-ya)+xc*(ya-yb))==0) {
    printf ("Linija\n");
    }
   else if ((fabs(a-b)>epsilon && fabs(b-c)<epsilon && fabs(c-b)<epsilon) ||(fabs(c-a)>epsilon && fabs(a-b)<epsilon && fabs(b-a)<epsilon) || (fabs(c-b)>epsilon && fabs(a-c)<epsilon && fabs(c-a)<epsilon)){
    printf ("Jednakokraki\n");
    }
    if (fabs(a-b)<epsilon && fabs(b-c)<epsilon && fabs(c-a)<epsilon){
   printf ("Jednakostranicni\n");
     }
    if (fabs(a-b)>epsilon && fabs(b-c)>epsilon && fabs(c-a)>epsilon){
    printf ("Raznostranicni\n");
    
      
       }
  
   alfa=acos((c*c+b*b-a*a)/(2*a*b));
   beta=acos((a*a+c*c-b*b)/(2*a*c));
   gama=acos((a*a+b*b-c*c)/(2*a*b)); 
   
 if (alfa>max)max=alfa;
 if (beta>max)max=beta;
 if (gama>max)max=gama;
 
 ugao=max*(180/(4*atan(1)));
 
 stepeni=(int)ugao; 
 min=(ugao - (int)ugao)*60;
 sec=(min - (int)min)*60;
 min=(int)min;
 sec=(int)sec;

printf ("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.", stepeni, min, sec);
   
   
    
   	return 0;
   	
  }

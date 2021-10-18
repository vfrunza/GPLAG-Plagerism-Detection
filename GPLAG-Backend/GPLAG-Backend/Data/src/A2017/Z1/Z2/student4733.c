#include <stdio.h>
#include <math.h>
#define epsilon 0.0001

int main() {
 
     int min,sec,step;
     double x1,x2,y1,y2,x3,y3,a,b,c,a1,b1,c1,alfa,beta,gama,max;
  
   
   printf("Unesite koordinate tacke t1: ");
   scanf ("%lf %lf",&x1,&y1);
   printf("Unesite koordinate tacke t2: ");
   scanf ("%lf %lf",&x2,&y2);
   printf("Unesite koordinate tacke t3: ");
   scanf ("%lf %lf",&x3,&y3);
   
   
   
   a1=((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
   b1=((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
   c1=((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
  
  a=sqrt(a1);
  b=sqrt(b1);
  c=sqrt(c1);


   alfa=acos((b*b+c*c-a*a)/(2*b*c));
   beta=acos((a*a+c*c-b*b)/(2*a*c));
   gama=acos((b*b+a*a-c*c)/(2*b*a));
   alfa=alfa*180/3.14159265359;
   beta=beta*180/3.14159265359;
   gama=gama*180/3.14159265359;

  
   if(alfa>=beta && alfa>=gama) max=alfa;
   else if (beta>=alfa && beta>=gama) max=beta;
   else max=gama;
   
   if(fabs(max-90)<epsilon)
   printf("Pravougli\n");
   if (fabs(max-180)<epsilon)
   printf("Linija\n");
   else if(fabs(a-b)<epsilon && fabs(a-c)<epsilon)
   printf("Jednakostranicni\n");
   else if (fabs(a-b)<epsilon||fabs(a-c)<epsilon||fabs(b-c)<epsilon)
   printf("Jednakokraki\n");
   
   else printf ("Raznostranicni\n");
   

   step=max+epsilon;
   min=(max-step)*60;
   sec=(((max-step)*60)-min)*60;
   printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi." ,step,min,sec);
   
   
   
   
	return 0;
}

#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.141592

int main ()
{

   double x1, y1, x2, y2, x3, y3, alfa, beta, gama, a, b, c, ugao1=0, ugao2=0, ugao3=0;
   int sek, min, step;

   printf ("Unesite koordinate tacke t1: ");
   scanf ("%lf %lf", &x1, &y1);

   printf ("Unesite koordinate tacke t2: ");
   scanf ("%lf %lf", &x2, &y2);

   printf ("Unesite koordinate tacke t3: ");
   scanf ("%lf %lf", &x3, &y3);

   a = sqrt ((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)); /*Stranica a*/
   b = sqrt ((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1)); /*Stranica b*/
   c = sqrt ((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2)); /*Stranica c*/

   /*KOSINUSNA TEOREMA   a*a=b*b+c*c-2*b*c*cos(alfa);
                         b*b=c*c+a*a-2*c*a*cos(beta);
                         c*c=a*a+b*b-2*a*b*cos(gama); */

   alfa = acos((b*b+c*c-a*a)/(2*b*c));
   beta = acos((a*a+c*c-b*b)/(2*a*c));
   gama = acos((a*a+b*b-c*c)/(2*a*b));
   ugao1=(alfa*180)/PI;
   ugao2=(beta*180)/PI;
   ugao3=(gama*180)/PI;

if (a>=(b+c) || b>=(a+c) || c>=(a+b)) {
      printf ("Linija\n");
      printf ("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");   /*Ispruzena linija*/
      return 0;
   }

  else if((fabs(a*a+b*b-c*c)<EPSILON) || (fabs(c*c+b*b-a*a)<EPSILON) || (fabs(a*a+c*c-b*b)<EPSILON)) {
      printf ("Pravougli\n");
   }

 if (fabs(a-b)<EPSILON && fabs(a-c)<EPSILON) {
      printf ("Jednakostranicni\n");
   }

   else if (fabs(a-b)>EPSILON && fabs(a-c)>EPSILON) {
      printf ("Raznostranicni\n");
   }

   else {
      printf ("Jednakokraki\n");
}

   if (ugao1>ugao2 && ugao1>ugao3) {

      step=(int)ugao1;
      ugao1=ugao1-step;
      ugao1=ugao1*60;
      min=(int)ugao1;
      ugao1=ugao1-min;
      ugao1=ugao1*60;
      sek=(int)ugao1;
      
      printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", step, min, sek);
      
   }
   else if (ugao2>ugao1 && ugao2>ugao1) {
      
      step=(int)ugao2;
      ugao2=ugao2-step;
      ugao2=ugao2*60;
      min=(int)ugao2;
      ugao2=ugao2-min;
      ugao2=ugao2*60;
      sek=(int)ugao2;
      
      printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", step, min, sek);
   }

   else if(ugao3>ugao1 && ugao3>ugao2) {
      
      step=(int)ugao3;
      ugao3=ugao3-step;
      ugao3=ugao3*60;
      min=(int)ugao3;
      ugao3=ugao3-min;
      ugao3=ugao3*60;
      sek=(int)ugao3;
      
      printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", step, min, sek);
   }

   return 0;

}

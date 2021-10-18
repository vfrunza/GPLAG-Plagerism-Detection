/**/
#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001 
#define PI 3.1415926

int main()

{
    double  x1=0, y1=0, x2=0, y2=0, x3=0, y3=0 , a=0, b=0, c=0, P=0, veca=0, srednja=0, manja=0, x=0, ugao=0, stepen=0, minuta=0, sekunda=0;
 
      printf ("Unesite koordinate tacke t1: ");
         scanf ("%lf %lf", &x1,&y1);
      printf ("Unesite koordinate tacke t2: ");
         scanf ("%lf %lf", &x2,&y2);
      printf ("Unesite koordinate tacke t3: ");   
		 scanf ("%lf %lf", &x3,&y3);
		 
     a = sqrt ((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
     b = sqrt ((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
     c = sqrt ((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
     
    
     
     if (a>b && a>c) veca = a;
     else if (b>a && b>c) veca = b;
     else if (c>b && a<c) veca = c;
     
     if ((a>b && a<c) || (a<b && a>c)) srednja = a;
     else if ((b<a && b>c) || (b>a && b<c )) srednja = b;
     else if ((c>b && a>c) || (c<b && a<c)) srednja = c;
     else if ((c==b && c<a)) srednja = c;
     else if ((c==a && c<b)) srednja = c;
     else if ((b==a && c>b)) srednja = b;
     else if ((b==a && a>b)) srednja = b; 
     else if ((c==a && a<b)) srednja =a;
     else if ((b==a && a<c)) srednja =a;
     
     if (a<b && a<c) manja = a;
     else if (b<a && b<c) manja = b;
     else if (c<b && a>c) manja = c;
     else if ((c==b && c<a)) manja = c;
     else if ((c==a && c<b)) manja = c;
     else if ((b==a && c>b)) manja = b;
     else if ((b==a && a>b)) manja = b; 
     else if ((c==a && a<b)) manja =a;
     else if ((b==a && a<c)) manja =a;
    
    
     P= (1/2.)* fabs ((x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)));
     
      if (  (fabs (veca -  manja - srednja)<EPSILON) || (fabs (P)<EPSILON))  {printf ("Linija"); printf ("\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");return 0;}
       
     
      if (fabs(a - b) < EPSILON && fabs(b - c) < EPSILON)  {  printf ("Jednakostranicni");
      
                                                        printf ("\nNajveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
                                                     }
    
      else if (fabs(a - b) < EPSILON || fabs(b - c) < EPSILON || fabs(c - a) < EPSILON) {
     	   if (fabs (veca*veca - srednja*srednja - manja*manja) < EPSILON) {printf ("Pravougli\nJednakokraki"); printf ("\nNajveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");} 
     	      else {
                            x= (manja*manja + srednja*srednja - veca*veca)/(2.*manja*srednja);
                            ugao = acos (x)*180/PI;
                            stepen=floor (ugao);
                            ugao=ugao-stepen;
                            ugao=ugao*60;
                            minuta=floor ( ugao); 
                            ugao=ugao-minuta;
                            ugao=ugao*60;
                            sekunda=floor ( ugao); 
                         
                            printf ("\Jednakokraki");
                            printf ("\nNajveci ugao ima %g stepeni, %g minuta i %g sekundi.", stepen, minuta, sekunda);
                         }
    							 }

     
      else 
                         { if (fabs (veca*veca-srednja*srednja-manja*manja)<EPSILON ) {printf ("Pravougli\n");printf ("Raznostranicni"); printf ("\nNajveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");}
                         else {
                            x= (manja*manja + srednja*srednja - veca*veca)/(2.*manja*srednja);
                            ugao = acos (x)*180/PI;
                            stepen=floor (ugao);
                            ugao=ugao-stepen;
                            ugao=ugao*60;
                            minuta=floor ( ugao); 
                            ugao=ugao-minuta;
                            ugao=ugao*60;
                            sekunda=floor ( ugao); 
                            printf ("Raznostranicni");
                            printf ("\nNajveci ugao ima %g stepeni, %g minuta i %g sekundi.", stepen, minuta, sekunda);
                         }}
   

     return 0;

}
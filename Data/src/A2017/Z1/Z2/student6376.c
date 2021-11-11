#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.14

int main () {
    double x1,x2,x3,y1,y2,y3,a,c,b,alfa,beta,gama;
    double minute,sekunde;
    printf("Unesite koordinate tacke t1: ");
    scanf("%lf %lf",&x1,&y1);
    printf("Unesite koordinate tacke t2: ");
    scanf("%lf %lf",&x2,&y2);
    printf("Unesite koordinate tacke t3: ");
    scanf("%lf %lf",&x3,&y3);
    
    
    a=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
    b=sqrt(pow((x2-x3),2)+pow((y2-y3),2));
    c=sqrt(pow((x3-x1),2)+pow((y3-y1),2));
     
      
    alfa=(pow(a,2)-pow(b,2)-pow(c,2))/-2*c*b;
    beta=(pow(b,2)-pow(a,2)-pow(c,2))/-2*a*c;
    gama=(pow(c,2)-pow(b,2)-pow(a,2))/-2*a*b;
     
     if (alfa<1 && alfa>-1) {
         alfa=acos(alfa) * (180/PI);
     } 
     else {
         alfa=180;
     }
     if (beta<1 && beta>-1) {
         beta=acos(beta) * (180/PI);
     } 
     else {
         beta=180;
     }
     if (gama<1 && gama>-1) {
         gama=acos(gama) * (180/PI);
     } 
     else {
         gama=180;
     }
    
   if(!(180-alfa <=EPSILON)) {
       if (fabs(90-alfa)<=EPSILON || fabs(90-beta)<=EPSILON || fabs(90-gama)<=EPSILON) {
           printf("Pravougli\n");
       }
       if(fabs(60-alfa)<=EPSILON && fabs(60-beta)<=EPSILON && fabs(60-gama)<=EPSILON) {
           printf("Jednaskostranicni\n");
       }
       else if 
           ( fabs(alfa-beta)<=EPSILON || fabs(alfa-gama)<=EPSILON || fabs(gama-beta)<=EPSILON) {
       printf("Jednakokraki\n");
   }
   else {
       printf("Raznostranicni\n");
   }
   }
   else {
       printf("Linija\n");
   }
   
   if (alfa>beta && alfa>gama) {
         minute=((alfa-(int)alfa)*0.6)*100;
         sekunde=((minute-(int)minute)*0.6)*100;
  
       printf("Najveci ugao ima %.0f stepeni, %.0f minuta i %.0f sekundi.",floor(alfa),floor(minute),floor(sekunde));
   }
   else if (beta>gama && beta>alfa) {
        minute=((beta-(int)beta)*0.6)*100;
    sekunde=((minute-(int)minute)*0.6)*100;
  
       printf("Najveci ugao ima %.0f stepeni, %.0f minuta i %.0f sekundi.",floor(beta),floor(minute),floor(sekunde));
   }
   else {
       minute=((gama-(int)gama)*0.6)*100;
   sekunde=((minute-(int)minute)*0.6)*100;
       printf("Najveci ugao ima %.0f stepeni, %.0f minuta i %.0f sekundi.",floor(gama),floor(minute),floor(sekunde));
   }
   
 
    return 0;
}
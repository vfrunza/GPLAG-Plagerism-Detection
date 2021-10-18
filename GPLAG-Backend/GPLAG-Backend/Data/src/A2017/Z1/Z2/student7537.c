#include <stdio.h>
#include <math.h>
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923
#define e 0.0001
int main(){
	
	 /*Pa da pocnemo*/
	 
	 double a, b, c, x1, x2, x3, y1, y2, y3, P, alfa, beta, gama, min, sec;
	 printf("Unesite koordinate tacke t1: ");
	 scanf("%lf %lf", &x1, &y1);
	 printf("Unesite koordinate tacke t2: ");
	 scanf("%lf %lf", &x2, &y2);
	 printf("Unesite koordinate tacke t3: ");
	 scanf("%lf %lf", &x3, &y3);
	 P=fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2;
	 a=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
	 b=sqrt(pow((x3-x1),2)+pow((y3-y1),2));
	 c=sqrt(pow((x3-x2),2)+pow((y3-y2),2));
	 
	 /*Malo trigonometrije i racunanja*/
	 
	 if(fabs(P-0)<e){
	 printf("Linija");
	 printf("\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	 return 1;}
	 if(fabs(a*a-b*b-c*c)<e || fabs(b*b-a*a-c*c)<e || fabs(c*c-a*a-b*b)<e)
	  printf("Pravougli\n");
	 if((fabs(a-b)<e && fabs(a-c)>e) || (fabs(a-c)<e && fabs(a-b)>e) || (fabs(b-c)<e && fabs(a-b)>e))
	 printf("Jednakokraki");
	 else{
	 if(fabs(a-b)>e && fabs(a-c)>e && fabs(b-c)>e)
	 printf("Raznostranicni");
	 else
	 printf("Jednakostranicni");}
	 
	 gama=acos((a*a+b*b-c*c)/(2*a*b))*(180/PI);
	 beta=acos((a*a+c*c-b*b)/(2*a*c))*(180/PI);
	 alfa=180-(gama+beta);
	 
    if(alfa>=gama && alfa>=beta){
	     min=((alfa-(int)alfa)*60);
         sec=((min-(int)min)*60);
         min=(int)min;
	     printf("\nNajveci ugao ima %d stepeni, %g minuta i %d sekundi.", (int)alfa, min, (int)sec);
	     return 1;
	 }
	 if(beta>=alfa && beta>=gama){
	 	 min=((beta-(int)beta)*60);
         sec=((min-(int)min)*60);
         min=(int)min;
	 	 printf("\nNajveci ugao ima %d stepeni, %g minuta i %d sekundi.", (int)beta, min, (int)sec);
	 	 return 1;
	 }
	 if(gama>=alfa && gama>=beta){
	 	 min=((gama-(int)gama)*60);
         sec=((min-(int)min)*60);
         min=(int)min;
	 	 printf("\nNajveci ugao ima %d stepeni, %g minuta i %d sekundi.", (int)gama, min, (int)sec);
	 	 return 1;
	 }
return 0;
}
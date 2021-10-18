#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.1415926535

int main() {
 double x1,x2,x3,y1,y2,y3,a,b,c,alfa,beta,gama,max,minuta1,minuta2,minuta3,sekunda1,sekunda2,sekunda3,alfaa,betaa,gamaa,minutaa1,minutaa2,minutaa3;
 printf("Unesite koordinate tacke t1: ");
 scanf("%lf %lf", &x1, &y1);
 printf("Unesite koordinate tacke t2: ");
 scanf("%lf %lf", &x2, &y2);
 printf("Unesite koordinate tacke t3: ");
 scanf("%lf %lf", &x3, &y3);
 a=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
 b=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
 c=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
 alfa=(acos((b*b+c*c-a*a)/(2*b*c)))*(180/PI);
 beta=(acos((a*a+c*c-b*b)/(2*a*c)))*(180/PI);
 gama=(acos((a*a+b*b-c*c)/(2*b*a)))*(180/PI);
 	minuta1=(alfa-(int)alfa)*60;
 	minutaa1=floor(minuta1);
  sekunda1=floor((minuta1-(int)minuta1)*60);
  minuta2=(beta-(int)beta)*60;
  minutaa2=floor(minuta2);
  sekunda2=floor((minuta2-(int)minuta2)*60);
  minuta3=(gama-(int)gama)*60;
  minutaa3=floor(minuta3);
  sekunda3=floor((minuta3-(int)minuta3)*60);
  alfaa=floor(alfa);
  betaa=floor(beta);
  gamaa=floor(gama);
  if(x1==x2 && x2==x3 || y1==y2 && y2==y3 || x1==x2 && x2!=x3 && y1==y2 && y3!=y2 || x1==x3 && x3!=x2 && y1==y3 && y3!=y2 || x2==x3 && x3!=x1 && y2==y3 && y3!=y1 || alfa>=180 || beta>=180 || gama>=180)
  {
  printf("Linija\n");
   if(alfa>beta && alfa>gama)
  printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.\n", alfaa, minutaa1, sekunda1);
  if(beta>alfa && beta>gama)
  printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.\n", betaa, minutaa2, sekunda2);
  if(gama>alfa && gama>beta)
  printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.\n", gamaa, minutaa3, sekunda3);
  if(alfa==beta && beta>gama || alfa==gama && gama>beta)
  printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.\n", alfaa, minutaa1, sekunda1);
  if(beta==gama && gama>alfa)
  printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.\n", betaa, minutaa2, sekunda2);
  return 1;
  }
  if((fabs(alfa-90)<EPSILON) || (fabs(beta-90)<EPSILON) || (fabs(gama-90)<EPSILON))
  printf("Pravougli\n");
  if(fabs(a-b)>=EPSILON && fabs(b-c)>=EPSILON && fabs(c-a)>=EPSILON)
  printf("Raznostranicni\n");
  if(fabs(a-b)<EPSILON && fabs(b-c)>=EPSILON || fabs(a-c)<EPSILON && fabs(c-b)>=EPSILON || fabs(b-c)<EPSILON && fabs(c-a)>=EPSILON)
  printf("Jednakokraki\n");
  if(fabs(a-b)<EPSILON && fabs(b-c)<EPSILON)
  printf("Jednakostranicni\n");
  if(alfa>beta && alfa>gama)
  printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.\n", alfaa, minutaa1, sekunda1);
  if(beta>alfa && beta>gama)
  printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.\n", betaa, minutaa2, sekunda2);
  if(gama>alfa && gama>beta)
  printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.\n", gamaa, minutaa3, sekunda3);
  if(alfa==beta && beta>gama || alfa==gama && gama>beta)
  printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.\n", alfaa, minutaa1, sekunda1);
  if(beta==gama && gama>alfa)
  printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.\n", betaa, minutaa2, sekunda2);
  return 0;
}

#include <stdio.h>
#include <math.h>
#define E 0.0001
#define PI 3.1415926535

int main() {
  double x1, x2, x3, y1, y2, y3, a, b, c, alfa, min;
  int minut, stepen, sekund;
  int p=0;
  printf ("Unesite koordinate tacke t1: ");
  scanf ("%lf %lf", &x1, &y1);
  printf ("Unesite koordinate tacke t2: ");
  scanf ("%lf %lf", &x2, &y2);
  printf ("Unesite koordinate tacke t3: ");
  scanf ("%lf %lf", &x3, &y3);
  
  a=sqrt ((x3-x2)*(x3-x2)+ (y3-y2)*(y3-y2));
  b=sqrt ((x3-x1)*(x3-x1)+ (y3-y1)*(y3-y1));
  c=sqrt ((x2-x1)*(x2-x1)+ (y2-y1)*(y2-y1));
  if (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)==0){
  printf ("Linija\n");
  printf ("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi." );
  return 0;
  }
    else if ((fabs((a*a)+(b*b)-(c*c))<E) ||(fabs((b*b)+ (c*c)- (a*a))< E)|| (fabs((a*a)+(c*c)-(b*b))<E)){
  printf ("Pravougli\n");
  stepen=90;
  minut =0;
  sekund=0;
  p=1;
  }
  if ((fabs(a-b)<E)&&(fabs(b-c)<E)&& (fabs(a-c)<E)){
    printf ("Jednakostranicni\n");
    stepen = 60;
    minut =0;
    sekund=0;
  }
    else if (((fabs (a-b)<E)&&(fabs(a-c)<E))||((fabs(a-c)<E)&&(fabs(a-b)>=E))||((fabs(b-c)<E)&&(fabs(c-a)>=E))){
    printf ("Jednakokraki\n");
    if (p==0){
      if((a>=b)&&(a>=c))
      alfa=acos(((b*b)+(c*c)-(a*a))/(2*a*b))*(180/PI);
    else if ((b>=a)&&(b>=c))
    alfa=acos(((a*a)+(c*c)-(b*b))/(2*a*b))*(180/PI);
    else
    alfa =acos(((b*b)+(a*a)-(c*c))/(2*a*b))*(180/PI);
    stepen=(int)alfa;
    min=(alfa-stepen)*60;
    minut=(int)min;
    sekund=(min-minut)*60;
    }
    }
    else {
      printf ("Raznostranicni\n");
      if (p==0){
        if ((a>=b)&&(a>=c))
        alfa=acos(((b*b)+(c*c)-(a*a))/(2*b*c))*(180/PI);
        else if ((b>=a)&&(b>=c))
        alfa =acos (((a*a)+(c*c)-(b*b))/(2*a*c))*(180/PI);
        else
        alfa =acos (((b*b)+(a*a)-(c*c))/(2*a*b))*(180/PI);
        stepen =(int)alfa;
        min=(alfa-stepen)*60;
        minut=(int)min;
        sekund=(min-minut)*60;
      }
    }
    

  
  printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, minut, sekund);
    return 0;
    }
    
    
  
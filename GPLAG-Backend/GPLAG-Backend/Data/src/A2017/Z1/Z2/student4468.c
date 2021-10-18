#include <stdio.h>
#include <math.h>
#define epsilon 10e-4
#define PI 3.14159265359

int poredi (double x, double y)
{
  return (fabs(x-y)<=(epsilon*(fabs(x)-fabs(y))));
}
int main()
{
  double x1,x2,x3,y1,y2,y3;
  float d1,d2,d3;
  double a=0,b=0,c=0;
  int najveci, minuta, sekundi;
  double ostatak=0,minutepom=0, sekundepom=0, ostataksekunde=0;
  double ugao1,ugao2,ugao3;
  int p1=0,p2=0,p3=0;
  int pravougli=0;
  float k1,k2,k3,n1,n2,n3;


  printf ("Unesite koordinate tacke t1: ");
  scanf ("%lf %lf", &x1, &y1);
  printf ("Unesite koordinate tacke t2: ");
  scanf ("%lf %lf", &x2, &y2);
  printf ("Unesite koordinate tacke t3: ");
  scanf ("%lf %lf", &x3, &y3);

  d1=(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));

  d3=(sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1)));
  d2=(sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3)));
  a=fabs(d1);
  b=fabs(d2);
  c=fabs(d3);
  ugao2=(acos(((b*b)+(c*c)-(a*a))/(2*b*c))*(180/PI));
  ugao3=(acos(((a*a)+(c*c)-(b*b))/(2*c*a))*(180/PI));
  ugao1=(acos(((b*b)+(a*a)-(c*c))/(2*b*a))*(180/PI));
  p1=ugao1;
  p2=ugao2;
  p3=ugao3;
  najveci=p1;
  ostatak=p1;


  n1=(((y2-y1)/(x2-x1))*(-x1))+y1;
  n2=(((y3-y2)/(x3-x2))*(-x2))+y2;
  n3=(((y1-y3)/(x1-x3))*(-x3))+y3;
  k1=((y2-y1)/(x2-x1));
  k2=((y3-y2)/(x3-x2));
  k3=((y3-y2)/(x3-x2));



  if(p1>p2 && p1> p3) {
    najveci=p1;
    ostatak=ugao1;
  } else if (p2>p1 && p2>p3) {

    najveci=p2;
    ostatak=ugao2;

  } else {
    najveci=p3;
    ostatak=ugao3;
  }

  ostatak=ostatak-najveci;
  minutepom=ostatak*60;
  minuta=(int)minutepom;

  ostataksekunde=minutepom-minuta;
  sekundepom=ostataksekunde*60;
  sekundi=(int)sekundepom;

  if(((x1==x2 && y1!=y2) || (x1==x3 && y1!=y3) || (x2==x3 && y2!=y3)) && (((x1!=x2 && y1==y2) || (x1!=x3 && y1==y3) || (x2!=x3 && y2==y3)))) {

    printf("Pravougli\n");
    if(najveci==90) {
      sekundi=0;
      minuta=0;
      pravougli=1;
    }

  }
  if(((y1==y2 && y2==y3 && y1==y3 )&& (x1!=x2 && x2!=x3 && x1!=x3) || (y1!=y2 && y2!=y3 && y1!=y3 )&& (x1==x2 && x2==x3 && x1==x3)) || (k1=k2 && k2==k3 && k1==k3 && n1==n2 && n2==n3 && n1==n3)) {

    printf("Linija\n");
    printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");

    if(najveci==180) {
      sekundi=0;
      minuta=0;
    }
    return 0;
  }

  if(!poredi(a,b) &&  !poredi(b,c) && !poredi(c,a) ) {
    printf("Raznostranicni\n");
    // printf("%d %d %d",a,b,c);
    if(najveci==89 && minuta ==59 && sekundi ==59)
      printf("Najveci ugao ima %d stepeni, 0 minuta i 0 sekundi.",najveci+1);
    else
      printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",najveci, minuta, sekundi);
  }

  else  if( ((poredi(a,b) && !poredi(a,c)) || (poredi(b,c) && !poredi(a,c)) || (poredi(c,a) && poredi(c,b)))  && najveci!=180 && (p1!=60 && p2!=59 && p3!=59))  {

    {

      printf("Jednakokraki\n");


      if(pravougli==1) {
        minuta=0;
        sekundi=0;
        printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", najveci, minuta, sekundi);
      } else
        printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", najveci, minuta, sekundi);
    }
  } else if((p1=60 && p2==59 && p3==59) || (p1=59 && p2==60 && p3==59)  || (p1=59 && p2==59 && p3==60)) {
    printf("Jednakostranicni\n");

    printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
  }

  return 0;
}

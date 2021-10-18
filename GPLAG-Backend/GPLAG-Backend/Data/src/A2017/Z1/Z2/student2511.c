#include <stdio.h>
#include <math.h>
#define PI 3.14159
#define EPSILON 0.0001
int main()
{
    double a,b,c,d,e,f,stranica1=0,stranica2=0,stranica3=0,alfa=0,beta=0,gama=0,najveci=0,povrsina=0,s=0,radijan,min,sek;
    int stepeni=0,minute=0,sekunde=0,step=0;
    radijan=180.0/PI;
    printf("Unesite koordinate tacke t1: ");
    scanf("%lf %lf",&a,&b);
    printf("Unesite koordinate tacke t2: ");
    scanf("%lf %lf",&c,&d);
    printf("Unesite koordinate tacke t3: ");
    scanf("%lf %lf",&e,&f);
    stranica1=sqrt((c-a)*(c-a) +(d-b)*(d-b));
    stranica2=sqrt((c-e)*(c-e) +(f-d)*(f-d));
    stranica3=sqrt((a-e)*(a-e)+(b-f)*(b-f));
   s=(stranica1+stranica2+stranica3)/2;
   povrsina=sqrt(s*(s-stranica1)*(s-stranica2)*(s-stranica3));
   alfa=acos((stranica2*stranica2+stranica3*stranica3-stranica1*stranica1)/(2*stranica2*stranica3))*radijan;
   beta=acos((stranica1*stranica1+stranica3*stranica3-stranica2*stranica2)/(2*stranica1*stranica3))*radijan;
   gama=acos((stranica1*stranica1+stranica2*stranica2-stranica3*stranica3)/(2*stranica1*stranica2))*radijan;
  najveci=alfa;
  if(beta>alfa)
  najveci=beta;
  if(gama>alfa)
  najveci=gama;
  stepeni=(int)najveci;
  min=((najveci-stepeni)*60);
  minute=(int)min;
  sek=(min-minute)*60;
  sekunde=(int)sek;
  if(povrsina==0)
  {
      printf("Linija");
      printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni,minute,sekunde);
  return 0;
  }
  else
  {
      if((fabs(stranica1-stranica2)<EPSILON) && (fabs(stranica2-stranica3)<EPSILON) && (fabs(stranica1-stranica3)<EPSILON))
      {
          printf("Jednakostranicni\n");
          printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni,minute,sekunde);
          return 0;
      }
      if(fabs(alfa-90.0)<EPSILON || fabs(beta-90.0)<EPSILON || fabs(gama-90.0)<EPSILON)
      {
          printf("Pravougli\n");
      }
      if((fabs(stranica1-stranica2)<EPSILON) || (fabs(stranica2-stranica3)<EPSILON) || (fabs(stranica1-stranica3)<EPSILON))
      {
          printf("Jednakokraki\n");
  }
  if(fabs(stranica1-stranica2)>EPSILON && fabs(stranica1-stranica3)>EPSILON && fabs(stranica2-stranica3)>EPSILON)
  {
      printf("Raznostranicni\n");
  }
  }
  printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni,minute,sekunde);
   
   
  
    return 0;
    
}
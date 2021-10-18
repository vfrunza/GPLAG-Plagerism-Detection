#include <stdio.h>
#include <math.h>
#define e 0.0001
#define PI 3.14159265359
int main()
{
   double x1,x2,x3,y1,y2,y3,d1,d2,d3,Alfa,Beta,Gama,maxugao;
   int sekunde,minute,stepeni,usekunde;
   
   printf("Unesite koordinate tacke t1: ");
   scanf("%lf %lf", &x1, &y1);
   printf("Unesite koordinate tacke t2: ");
   scanf("%lf %lf", &x2, &y2);
   printf("Unesite koordinate tacke t3: ");
   scanf("%lf %lf", &x3, &y3);
   
   d1=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
   d2=sqrt(pow(x3-x2,2)+pow(y3-y2,2));
   d3=sqrt(pow(x1-x3,2)+pow(y1-y3,2));
   
   Alfa=acos((d2*d2+d3*d3-d1*d1)/(2*d2*d3))*(180/PI);
   Beta=acos((d1*d1+d2*d2-d3*d3)/(2*d1*d2))*(180/PI);
   Gama=acos((d1*d1+d3*d3-d2*d2)/(2*d1*d3))*(180/PI);
   
   if(Alfa>Beta && Alfa>Gama) maxugao=Alfa;
   else if(Beta>Alfa && Beta>Gama) maxugao=Beta;
   else maxugao=Gama;
   
   if(fabs(maxugao-90)<e) printf("Pravougli\n");
   if(fabs(maxugao-180)<e) printf("Linija\n");
   else if(fabs(d1-d2)<e && fabs(d2-d3)<e) printf("Jednakostranicni\n");
   else if((fabs(d1-d2)<e && fabs(d2-d3)>e) || (fabs(d2-d3)<e && fabs(d1-d3)>e) || (fabs(d1-d3)<e && fabs(d1-d2)>e)) printf("Jednakokraki\n");
   else printf("Raznostranicni\n");
   maxugao+=e;
   usekunde=(int)(maxugao*3600);
   sekunde=usekunde%60;
   usekunde/=60;
   minute=usekunde%60;
   usekunde/=60;
   stepeni=usekunde;
   
   printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni,minute,sekunde);
   
    return 0;
}
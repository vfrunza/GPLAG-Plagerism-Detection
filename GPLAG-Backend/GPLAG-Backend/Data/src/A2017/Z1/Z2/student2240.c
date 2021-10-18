#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPSILON 0.0001
#define pi 3.14159265
int main()
{
    double x1,x2,x3,y1,y2,y3,pretvaranje,alfa,beta,gama,a,b,c,najveci;
    printf("Unesite koordinate tacke t1: ");
    scanf("%lf %lf",&x1,&y1);
    printf("Unesite koordinate tacke t2: ");
    scanf("%lf %lf",&x2,&y2);
    printf("Unesite koordinate tacke t3: ");
    scanf("%lf %lf",&x3,&y3);
    a=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
    b=sqrt(pow((x3-x2),2)+pow((y3-y2),2));
    c=sqrt(pow((x3-x1),2)+pow((y3-y1),2));
    pretvaranje=180.0/pi;
    alfa=pretvaranje*acos(((a*a)+(b*b)-(c*c))/(2*a*b));
    beta=pretvaranje*acos(((c*c)+(a*a)-(b*b))/(2*c*a));
    gama=pretvaranje*acos(((c*c)+(b*b)-(a*a))/(2*b*c));
    najveci=alfa;
    if(beta>alfa && beta>gama)
        najveci=beta;
    if(gama>alfa && gama>beta)
        najveci=gama;
   /*printf("%lf %lf %lf",a,b,c);*/
   int sve, sekunde, minute, stepeni;
     sve=najveci*3600;
     sekunde=sve %60;
     minute=(sve/60)%60;
     stepeni=sve/3600;
    if(a+b<c || a+c<b || b+c<a)
    printf("Nije trougao\n");
    if(stepeni==180)
        {
            printf("Linija\n");
        }
    if(najveci>=90-EPSILON && najveci<=90+EPSILON)
        printf("Pravougli\n");
    
    if((fabs(alfa-beta)<EPSILON) && (fabs(beta-gama)<EPSILON) && (fabs(alfa-gama)<EPSILON))
    printf("Jednakostranicni\n");
    if(((fabs(alfa-beta)<EPSILON) && (fabs(alfa-gama)>EPSILON)) || ((fabs(alfa-gama)<EPSILON) && (fabs(alfa-beta)>EPSILON)) || ((fabs(beta-gama)<EPSILON) && (fabs(beta-alfa)>EPSILON)))
    printf("Jednakokraki\n");
    if ((fabs(alfa-beta)>=EPSILON) && (fabs(alfa-gama)>=EPSILON) && (fabs(beta-gama)>=EPSILON))
    printf("Raznostranicni\n");
    printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n",stepeni,minute,sekunde);
    return 0;
}

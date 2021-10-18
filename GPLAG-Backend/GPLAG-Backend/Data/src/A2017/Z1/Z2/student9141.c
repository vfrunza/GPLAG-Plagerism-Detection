#include <stdio.h>
#include <math.h>
#define eps 0.0001
#define PI 3.14159265359

int main(){
    double t1x=0, t1y=0, t2x=0, t2y=0, t3x=0, t3y=0;
    long double a, b, c, najveci=0, stepeni, minuta, sekundi;
    
    printf("Unesite koordinate tacke t1: ");
    scanf("%lf %lf", &t1x, &t1y);
    printf("Unesite koordinate tacke t2: ");
    scanf("%lf %lf", &t2x, &t2y);
    printf("Unesite koordinate tacke t3: ");
    scanf("%lf %lf", &t3x, &t3y);
    a=sqrt(pow((t2x-t3x), 2)+pow((t2y-t3y), 2));
    b=sqrt(pow((t1x-t3x), 2)+pow((t1y-t3y), 2));
    c=sqrt(pow((t2x-t1x), 2)+pow((t2y-t1y), 2));
    if(((fabs((t2x-t1x)/(t3x-t1x)-(t2y-t1y)/(t3y-t1y))<eps)) || (fabs(t1x-t2x)<eps && fabs(t2x-t3x)<eps) || (fabs(t1y-t2y)<eps && fabs(t2y-t3y)<eps))
        printf("Linija\n");
    
    else if(fabs(a-b)<eps && fabs(b-c)<eps) printf("Jednakostranicni\n");
    
    else if((fabs((pow(a, 2)+pow(b, 2))-pow(c, 2)))<eps || (fabs((pow(a, 2)+pow(c, 2))-pow(b, 2)))<eps || (fabs((pow(c, 2)+pow(b, 2))-pow(a, 2)))<eps){
         printf("Pravougli\n");
          if(fabs(a-b)<eps || fabs(b-c)<eps || fabs(c-a)<eps) printf("Jednakokraki\n");
          if(fabs(a-b)>eps && fabs(a-c)>eps && fabs(b-c)>eps) printf("Raznostranicni\n");
    }
    else if(fabs(a-b)<eps || fabs(b-c)<eps || fabs(c-a)<eps) printf("Jednakokraki\n");
    else if(fabs(a-b)>eps && fabs(a-c)>eps && fabs(b-c)>eps) printf("Raznostranicni\n");
    
    if(a>=b && a>=c) najveci=acos((b*b+c*c-a*a)/(2*b*c));
    else if(b>=a && b>=c) najveci=acos((c*c+a*a-b*b)/(2*a*c));
    else if(c>=a && c>=b) najveci=acos((b*b+a*a-c*c)/(2*a*b));
    najveci=najveci*180/PI;
    stepeni=najveci;
    minuta=(najveci-(int)stepeni)*60;
    sekundi=(minuta-(int)minuta)*60;
    if(sekundi-(int)sekundi>=0.55) sekundi+=0.5;
    else if(sekundi-(int)sekundi<=-0.55) sekundi-=0.5;
    if((int)sekundi==60){
        minuta=minuta+1;
        sekundi=0;
    }
    if((int)minuta==60){
        stepeni=stepeni+1;
        minuta=0;
    }
    if((int)sekundi<=-60){
        minuta-=1;
        sekundi=0;
    }
    if((int)minuta<=-60){
        stepeni-=1;
        minuta=0;
    }
    
    
    printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", (int)stepeni, (int)minuta, (int)sekundi);
    return 0;
}
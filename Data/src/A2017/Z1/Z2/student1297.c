#include <stdio.h>
#include <math.h>
#define PI 3.1415923163123612318232163217312
#define EPSILON 0.0001

int main()
{

    double x1,y1,x2,y2,x3,y3,a,b,c,stepenA,stepenB,stepenC;
    int stepenA1,stepenB1,stepenC1,minA,minB,minC,sekA,sekB,sekC;

    printf("Unesite koordinate tacke t1: ");
    scanf("%lf %lf", &x1, &y1);

    printf("Unesite koordinate tacke t2: ");
    scanf("%lf %lf", &x2, &y2);

    printf("Unesite koordinate tacke t3: ");
    scanf("%lf %lf", &x3, &y3);

    a = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    b = sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
    c = sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));

    /*SARUSOVO PRAVILO*/
    if(x1*y2+y1*x3+x2*y3-y1*x2-x1*y3-y2*x3==0) {
        printf("Linija\n");
        printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.\n");
        return 0;
    }

    if(fabs(a-b)<EPSILON && fabs(b-c)<EPSILON)
        printf("Jednakostranicni\n");

    if(fabs(a*a+b*b-c*c)<EPSILON || fabs(a*a+c*c-b*b)<EPSILON || fabs(b*b+c*c-a*a)<EPSILON)
        printf("Pravougli\n");

    if((fabs(a-b)<EPSILON && fabs(b-c)>EPSILON) || (fabs(a-c)<EPSILON && fabs(c-b)>EPSILON) || (fabs(c-b)<EPSILON && fabs(b-a)>EPSILON))
        printf("Jednakokraki\n");

    if(fabs(b-c)>EPSILON && fabs(b-a)>EPSILON && fabs(a-c)>EPSILON)
        printf("Raznostranicni\n");



    /*KOSINUSNA TEOREMA*/

    stepenA = acos((b*b+c*c-a*a) / (2*b*c));
    stepenB = acos((a*a+c*c-b*b) / (2*a*c));
    stepenC = acos((b*b+a*a-c*c) / (2*b*a));

    stepenA *= 180/PI;
    stepenB *= 180/PI;
    stepenC *= 180/PI;

    /*flooruj stepene minute i sekunde*/
    stepenA1 = floor(stepenA);
    stepenB1 = floor(stepenB);
    stepenC1 = floor(stepenC);

    minA = floor((stepenA-stepenA1)*60);
    minB = floor((stepenB-stepenB1)*60);
    minC = floor((stepenC-stepenC1)*60);



    sekA = floor(((stepenA-stepenA1)*60 - minA)*60);
    sekB = floor(((stepenB-stepenB1)*60 - minB)*60);
    sekC = floor(((stepenC-stepenC1)*60 - minC)*60);



    if(stepenA>stepenB && stepenA>stepenC)
        printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepenA1, minA, sekA);


    if(stepenB>stepenA && stepenB>stepenC)
        printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepenB1, minB, sekB);


    if(stepenC>stepenA && stepenC>stepenB)
        printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepenC1, minC, sekC);


    return 0;
}

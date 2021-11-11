#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.14159265
int main()
{
    double a,b,c,x1,y1,x2,y2,x3,y3,ALFA,BETA,GAMA,max;

    printf ("Unesite koordinate tacke t1: ");
    scanf ("%lf%lf", &x1,&y1);
    printf ("Unesite koordinate tacke t2: ");
    scanf ("%lf%lf", &x2,&y2);
    printf ("Unesite koordinate tacke t3: ");
    scanf ("%lf%lf", &x3,&y3);

    /* Fiesta */

    a = sqrt(pow(x2-x3,2) + pow(y2-y3,2));
    b = sqrt(pow(x1-x3,2) + pow(y1-y3,2));
    c = sqrt(pow(x1-x2,2) + pow(y1-y2,2));

    ALFA = acos((b*b+c*c-a*a)/(2*b*c)) * 180/PI;
    BETA = acos((c*c+a*a-b*b)/(2*c*a)) * 180/PI;
    GAMA = acos((a*a+b*b-c*c)/(2*a*b)) * 180/PI;

    /* KRAMPANJE*/
    if  ((fabs(ALFA-90)<=EPSILON) || (fabs(BETA-90)<=EPSILON) || (fabs(GAMA-90)<=EPSILON)
            && ( fabs(ALFA-BETA)<=EPSILON || fabs(ALFA-GAMA)<=EPSILON || fabs (BETA-GAMA)<=EPSILON )) {
        printf ("Pravougli\n");
    }
    if (fabs(ALFA-180)<=EPSILON || fabs(BETA-180)<=EPSILON || fabs(GAMA-180)<=EPSILON) {
        printf ("Linija\n");
    } else if (fabs(a-b)<=EPSILON && fabs(b-c)<=EPSILON && fabs(a-c)<=EPSILON) {
        printf ("Jednakostranicni\n");
    } else if (fabs(a-b)<=EPSILON || fabs(b-c)<=EPSILON || fabs(a-c)<=EPSILON) {
        printf ("Jednakokraki\n");
    } else {
        printf ("Raznostranicni\n");
    }

    max = ALFA;
    if (BETA>max) max=BETA;
    if (GAMA>max) max=GAMA;

    int stepeni,minute,sekunde;

    stepeni = (int)max;
    max   -= stepeni;
    minute = max*=60;
    minute = (int)max;
    max   -= minute;
    sekunde= max*=60;
    sekunde= (int)max;

    printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
    return 0;
}

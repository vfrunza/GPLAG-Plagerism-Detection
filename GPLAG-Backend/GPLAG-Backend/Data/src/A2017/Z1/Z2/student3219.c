#include <stdio.h>
#include <math.h>
#define eps 0.0001
#define PI 3.141592653

int main()
{
    double x1,x2,x3,y1,y2,y3,st1,st2,st3;
    double ug1,ug2,ug3; int step1,step2,step3,min1,min2,min3,sek1,sek2,sek3;
    printf("Unesite koordinate tacke t1: ");
    scanf("%lf %lf",&x1,&y1);
    printf("Unesite koordinate tacke t2: ");
    scanf("%lf %lf",&x2,&y2);
    printf("Unesite koordinate tacke t3: ");
    scanf("%lf %lf",&x3,&y3);
    st1=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    st2=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
    st3=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
    ug1=(acos((st3*st3+st1*st1-st2*st2)/(2*st3*st1)))*180/PI;
    ug2=(acos((st2*st2+st1*st1-st3*st3)/(2*st2*st1)))*180/PI;
    ug3=(acos((st2*st2+st3*st3-st1*st1)/(2*st2*st3)))*180/PI;
    step1=(int)ug1;
    min1=(int)((ug1-step1)*60);
    sek1=(int)((((ug1-step1)*60)-min1)*60);
    step2=(int)ug2;
    min2=(int)((ug2-step2)*60);
    sek2=(int)((((ug2-step2)*60)-min2)*60);
    step3=(int)ug3;
    min3=(int)((ug3-step3)*60);
    sek3=(int)((((ug3-step3)*60)-min3)*60);
    if(fabs(st1-st2)<eps && fabs(st1-st3)<eps && fabs(st2-st3)<eps) printf("Jednakostranicni\n");
    else if(fabs(st1-st2)>eps && fabs(st1-st3)>eps && fabs(st2-st3)>eps) printf("Raznostranicni\n");
    //else if(fabs(st1-st2)<eps || fabs(st1-st3)<eps || fabs(st2-st3)<eps) printf("Jednakokraki\n");
    else if(fabs(ug1-90)<eps || fabs(ug2-90)<eps || fabs(ug3-90)<eps) printf("Pravougli\n");
    else if(step1==0 ||step1==180 || step2==0 || step2==180 || step3==0 || step3==180) printf("Linija\n");
    if(ug1>=ug2 && ug1>=ug3)
        printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",step1,min1,sek1);
    else if(ug2>=ug1 && ug2>=ug3)
        printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",step2,min2,sek2);
    else if(ug3>=ug1 && ug3>=ug2)
        printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",step3,min3,sek3);
    return 0;
}
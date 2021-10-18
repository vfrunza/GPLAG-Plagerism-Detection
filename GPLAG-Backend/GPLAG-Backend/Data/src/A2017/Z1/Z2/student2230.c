#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.141592
int main ()
{
    double x1, x2, x3, y1, y2, y3, a, b, c, alf, bt, gm, mina, minb, ming, seca, secb, secg;
    int stepa, minal, secal, stepb, minbt, secbt, stepg, mingm, secgm, max, maxm, maxs;
    printf("Unesite koordinate tacke t1: ");
    scanf("%lf %lf", &x1, &y1);
    printf("Unesite koordinate tacke t2: ");
    scanf("%lf %lf", &x2, &y2);
    printf("Unesite koordinate tacke t3: ");
    scanf("%lf %lf", &x3, &y3);
    a=sqrt(pow(x2-x1,2)+pow(y2-y1,2)); /*stranica a*/
    b=sqrt(pow(x3-x2,2)+pow(y3-y2,2)); /*stranica b*/
    c=sqrt(pow(x3-x1,2)+pow(y3-y1,2)); /*stranica c*/
    alf=acos((pow(b,2)+pow(c,2)-pow(a,2))/(2*b*c));
    bt=acos((pow(a,2)+pow(c,2)-pow(b,2))/(2*a*c));
    gm=acos((pow(a,2)+pow(b,2)-pow(c,2))/(2*a*b));
    alf=alf*180/PI;
    bt=bt*180/PI;
    gm=gm*180/PI;
    stepa=(int)alf;
    mina=(alf-stepa)*60;
    minal=(int)mina;
    seca=(mina-minal)*60;
    secal=(int)seca;
    stepb=(int)bt;
    minb=(bt-stepb)*60;
    minbt=(int)minb;
    secb=(minb-minbt)*60;
    secbt=(int)secb;
    stepg=(int)gm;
    ming=(gm-stepg)*60;
    mingm=(int)ming;
    secg=(ming-mingm)*60;
    secgm=(int)secg;
    if((fabs(x1-x2)<EPSILON&&fabs(x2-x3)<EPSILON&&fabs(x1-x3)<EPSILON)||(fabs(y1-y2)<EPSILON&&fabs(y2-y3)<EPSILON&&fabs(y1-y3)<EPSILON)||(fabs(alf-180)<EPSILON||fabs(bt-180)<EPSILON||fabs(gm-180)<EPSILON))
        printf("Linija\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
    else if((fabs(alf-bt)<EPSILON&&fabs(bt-gm)<EPSILON&&fabs(gm-alf)<EPSILON)&&(fabs(a-b)<EPSILON&&fabs(b-c)<EPSILON&&fabs(a-c)<EPSILON)) {
        printf("Jednakostranicni");
        max=stepa;
        if(stepb>=max) {
            max=stepb;
            maxm=minbt;
            maxs=secbt;
        }
        if(stepg>max) {
            max=stepg;
            maxm=mingm;
            maxs=secgm;
        }
        if(stepa>=max) {
            max=stepa;
            maxm=minal;
            maxs=secal;
        }
        printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", max, maxm, maxs);

    } else if((fabs(alf-90)<EPSILON||fabs(bt-90)<EPSILON||fabs(gm-90)<EPSILON)&&((fabs(a-b)<EPSILON)||fabs(b-c)<EPSILON||fabs(a-c)<EPSILON)) {
        printf("Pravougli\nJednakokraki");
        max=stepa;
        if(stepb>=max) {
            max=stepb;
            maxm=minbt;
            maxs=secbt;
        }
        if(stepg>max) {
            max=stepg;
            maxm=mingm;
            maxs=secgm;
        }
        if(stepa>=max) {
            max=stepa;
            maxm=minal;
            maxs=secal;
        }
        printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", max, maxm, maxs);

    } else if((fabs(alf-90)<EPSILON||fabs(bt-90)<EPSILON||fabs(gm-90)<EPSILON)&&(fabs(a-b)>=EPSILON&&fabs(b-c)>=EPSILON&&fabs(a-c)>=EPSILON)) {
        printf("Pravougli\nRaznostranicni");
        max=stepa;
        if(stepb>=max) {
            max=stepb;
            maxm=minbt;
            maxs=secbt;
        }
        if(stepg>max) {
            max=stepg;
            maxm=mingm;
            maxs=secgm;
        }
        if(stepa>=max) {
            max=stepa;
            maxm=minal;
            maxs=secal;
        }
        printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", max, maxm, maxs);

    } else if(fabs(alf-90)<EPSILON||fabs(bt-90)<EPSILON||fabs(gm-90)<EPSILON) {
        printf("Pravougli");
        max=stepa;
        if(stepb>=max) {
            max=stepb;
            maxm=minbt;
            maxs=secbt;
        }
        if(stepg>max) {
            max=stepg;
            maxm=mingm;
            maxs=secgm;
        }
        if(stepa>=max) {
            max=stepa;
            maxm=minal;
            maxs=secal;
        }
        printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", max, maxm, maxs);

    } else if(fabs(a-c)<EPSILON||fabs(c-b)<EPSILON||fabs(a-b)<EPSILON) {
        printf("Jednakokraki");
        max=stepa;
        if(stepb>max) {
            max=stepb;
            maxm=minbt;
            maxs=secbt;
        }
        if(stepg>max) {
            max=stepg;
            maxm=mingm;
            maxs=secgm;
        }
        if(stepa>=max) {
            max=stepa;
            maxm=minal;
            maxs=secal;
        }
        printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", max, maxm, maxs);

    } else {
        printf("Raznostranicni");
        max=stepa;
        if(stepb>max) {
            max=stepb;
            maxm=minbt;
            maxs=secbt;
        }
        if(stepg>max) {
            max=stepg;
            maxm=mingm;
            maxs=secgm;
        }
        if(stepa>=max) {
            max=stepa;
            maxm=minal;
            maxs=secal;
        }
        printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", max, maxm, maxs);

    }
    return 0;
}
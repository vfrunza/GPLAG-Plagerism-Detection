#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define e 0.0001
#define PI 3.14159265

int main()
{
    double x_1,y_1,x_2,y_2,x_3,y_3,d_1,d_2,d_3,alfa,beta,gama,maxugao;
    double val = 180.0 / PI;
    printf("Unesite koordinate tacke t1: ");
    scanf("%lf %lf",&x_1,&y_1);
    printf("Unesite koordinate tacke t2: ");
    scanf("%lf %lf",&x_2,&y_2);
    printf("Unesite koordinate tacke t3: ");
    scanf("%lf %lf",&x_3,&y_3);

    d_1=sqrt(pow((x_2-x_1),2)+pow((y_2-y_1),2));
    d_2=sqrt(pow((x_3-x_2),2)+pow((y_3-y_2),2));
    d_3=sqrt(pow((x_3-x_1),2)+pow((y_3-y_1),2));

    alfa=acos((d_1*d_1+d_2*d_2-d_3*d_3)/(2*d_1*d_2))*val;
    beta=acos((d_3*d_3+d_1*d_1-d_2*d_2)/(2*d_3*d_1))*val;

    gama=180.0-alfa-beta;

    if(alfa>beta && alfa>gama)
    {
        maxugao=alfa;
    }
    else if(beta>alfa && beta>gama)
    {
        maxugao=beta;
    }
    else
    {
        maxugao=gama;
    }

int sveusekundama=maxugao*60*60;
int sekunde = sveusekundama % 60;
int minute = (sveusekundama / 60) % 60;
int stepeni = sveusekundama / (60 * 60);
if((maxugao+e)>=90 && (maxugao-e)<=90)
{
    printf("Pravougli\n");
}

if(stepeni==180) printf("Linija\n");

else if(d_1<=(d_2+e) && d_1>=(d_2-e) && d_2<=(d_3+e) && d_2>=(d_3-e))
{
printf("Jednakostranicni\n");
}
else if((d_1>=(d_2+e) || d_1<=(d_2-e)) && (d_2>=(d_3+e) || d_2<=(d_3-e)) && (d_1>=(d_3+e) || d_1<=(d_3-e)))
{
    printf("Raznostranicni\n");
}
else
{
printf("Jednakokraki\n");
}

printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni,minute,sekunde);


    return 0;
}

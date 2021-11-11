#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPSILON 0.0001
#define PI 3.141592

int main() {
double x1,x2,x3,y1,y2,y3,a,b,c,ALFA,BETA,GAMA,min1,min2,min3,sek1,sek2,sek3;
int stepeni1,minuta1,sekundi1,stepeni2,minuta2,sekundi2,stepeni3,minuta3,sekundi3,naj,najm,najs;
printf("Unesite koordinate tacke t1: ");
scanf("%lf %lf", &x1,&y1);
printf("Unesite koordinate tacke t2: ");
scanf("%lf %lf", &x2,&y2);
printf("Unesite koordinate tacke t3: ");
scanf("%lf %lf", &x3,&y3);

a=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
b=sqrt(pow(x2-x3,2)+pow(y2-y3,2));
c=sqrt(pow(x3-x1,2)+pow(y3-y1,2));
ALFA=acos((pow(b,2)+pow(c,2)-pow(a,2))/(2*b*c));
BETA=acos((pow(a,2)+pow(c,2)-pow(b,2))/(2*a*c));
GAMA=acos((pow(a,2)+pow(b,2)-pow(c,2))/(2*a*b));
ALFA=ALFA*(180./PI);
BETA=BETA*(180./PI);
GAMA=GAMA*(180./PI);
stepeni1=(int)ALFA;
min1=(ALFA-stepeni1)*60;
minuta1=(int)min1;
sek1=(min1-minuta1)*60;
sekundi1=(int)sek1;
stepeni2=(int)BETA;
min2=(BETA-stepeni2)*60;
minuta2=(int)min2;
sek2=(min2-minuta2)*60;
sekundi2=(int)sek2;
stepeni3=(int)GAMA;
min3=(GAMA-stepeni3)*60;
minuta3=(int)min3;
sek3=(min3-minuta3)*60;
sekundi3=(int)sek3;

    if((fabs(x1-x2)<EPSILON && fabs(x1-x3)<EPSILON && fabs(x2-x3)<EPSILON) || (fabs(y1-y2)<EPSILON && fabs(y1-y3)<EPSILON && fabs(y2-y3)<EPSILON) || (fabs(ALFA-180)<EPSILON || fabs(BETA-180)<EPSILON || fabs(GAMA-180)<EPSILON)){
        printf("Linija\n");
        printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.\n");}
    else if(fabs(ALFA-BETA)<EPSILON && fabs(BETA-GAMA)<EPSILON && fabs(GAMA-ALFA)<EPSILON && fabs(a-b)<EPSILON && fabs(a-c)<EPSILON && fabs(b-c)<EPSILON){
        printf("Jednakostranicni");
        naj=stepeni1;
        if(stepeni2>=naj){
            naj=stepeni2;
            najm=minuta2;
            najs=sekundi2;
        }
        if(stepeni3>naj){
            naj=stepeni3;
            najm=minuta3;
            najs=sekundi3;
        }
        if(stepeni1>=naj){
            naj=stepeni1;
            najm=minuta1;
            najs=sekundi1;
        }
        printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", naj,najm,najs);}
        
        else if((fabs(ALFA-90)<EPSILON || fabs(BETA-90)<EPSILON || fabs(GAMA-90)<EPSILON) && ((fabs(a-b)<EPSILON) || fabs(a-c)<EPSILON || fabs(b-c)<EPSILON)){
            printf("Pravougli");
            printf("\nJednakokraki");
             naj=stepeni1;
        if(stepeni2>=naj){
            naj=stepeni2;
            najm=minuta2;
            najs=sekundi2;
        }
        if(stepeni3>naj){
            naj=stepeni3;
            najm=minuta3;
            najs=sekundi3;
        }
        if(stepeni1>=naj){
            naj=stepeni1;
            najm=minuta1;
            najs=sekundi1;
        }
         printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", naj,najm,najs);}
         
         else if((fabs(ALFA-90)<EPSILON || fabs(BETA-90)<EPSILON || fabs(GAMA-90)<EPSILON) && (fabs(a-b)>=EPSILON && fabs(a-c)>=EPSILON && fabs(c-b)>=EPSILON)){
            printf("Pravougli");
            printf("\nRaznostranicni");
             naj=stepeni1;
        if(stepeni2>=naj){
            naj=stepeni2;
            najm=minuta2;
            najs=sekundi2;
        }
        if(stepeni3>naj){
            naj=stepeni3;
            najm=minuta3;
            najs=sekundi3;
        }
        if(stepeni1>=naj){
            naj=stepeni1;
            najm=minuta1;
            najs=sekundi1;
        }
         printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", naj,najm,najs);}
        
        else if(fabs(ALFA-90)<EPSILON || fabs(BETA-90)<EPSILON || fabs(GAMA-90)<EPSILON){
            printf("Pravougli");
                 naj=stepeni1;
        if(stepeni2>=naj){
            naj=stepeni2;
            najm=minuta2;
            najs=sekundi2;
        }
        if(stepeni3>naj){
            naj=stepeni3;
            najm=minuta3;
            najs=sekundi3;
        }
        if(stepeni1>=naj){
            naj=stepeni1;
            najm=minuta1;
            najs=sekundi1;
        }
        printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", naj,najm,najs);}
        
        else if(fabs(a-b)<EPSILON || fabs(a-c)<EPSILON || fabs(b-c)<EPSILON){
            printf("Jednakokraki");
                naj=stepeni1;
        if(stepeni2>=naj){
            naj=stepeni2;
            najm=minuta2;
            najs=sekundi2;
        }
        if(stepeni3>naj){
            naj=stepeni3;
            najm=minuta3;
            najs=sekundi3;
        }
        if(stepeni1>=naj){
            naj=stepeni1;
            najm=minuta1;
            najs=sekundi1;
        }
        printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", naj,najm,najs);}
        
        else{
            printf("Raznostranicni");
                   naj=stepeni1;
        if(stepeni2>=naj){
            naj=stepeni2;
            najm=minuta2;
            najs=sekundi2;
        }
        if(stepeni3>naj){
            naj=stepeni3;
            najm=minuta3;
            najs=sekundi3;
        }
        if(stepeni1>=naj){
            naj=stepeni1;
            najm=minuta1;
            najs=sekundi1;
        }
        printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", naj,najm,najs);}
	return 0;
}

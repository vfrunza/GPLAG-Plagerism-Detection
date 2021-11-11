#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.14159265359
  int main() {
   double x1,y1,x2,y2,x3,y3,a,b,c,alfa,min;
   int minut,stepen,sekund;
   int p=0;
   printf("Unesite koordinate tacke t1: ");
   scanf ("%lf %lf", &x1,&y1);
   printf("Unesite koordinate tacke t2: ");
   scanf("%lf%lf",&x2,&y2);
   printf("Unesite koordinate tacke t3: ");
   scanf("%lf %lf", &x3,&y3);
   
   
   a=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
   b=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
   c=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
   
   
   if(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)==0)
                                        {
                                        printf("Linija\n");
                                         printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
                                         return 0;
                                       }
     
     else if( fabs((a*a)+(b*b)-(c*c) )< EPSILON  ||  fabs((b*b)+(c*c)-(a*a) )< EPSILON || fabs ((a*a)+(c*c)-(b*b))<EPSILON )
                                 {
                                     printf("Pravougli\n");
                                     stepen=90;
                                     minut=0;
                                     sekund=0;
                                     p=1;
                                 }
    
     if(    (fabs(a-b) < EPSILON )  &&   (fabs(b-c)<EPSILON)   &&    (fabs(a-c) < EPSILON)  )
                                                 {
                                                    printf("Jednakostranicni\n");
                                                    stepen=60;
                                                    minut=0;
                                                    sekund=0;
                                                }
    else if( (fabs(a-b) <EPSILON)    &&  (fabs(a-c)<EPSILON)     || (     (fabs(a-c)<EPSILON)     &&  (fabs(a-b)>EPSILON)    )||(    (fabs(b-c)<EPSILON)&&(fabs(c-a)>=EPSILON)   ))
                    {
                    printf("Jednakokraki \n");
                    if(p==0){
                        if((a>=b)&&(a>=c))
                        alfa=round(acos(((b*b)+(c*c)-(a*a))/(2*b*c))*(180/PI)*100000)/100000.;
                        else if ((b>=a)&&(b>=c))
                        alfa=round(acos(((a*a)+(c*c)-(b*b))/(2*a*c))*(180/PI)*100000)/100000.;
                        else
                        alfa=round(acos(((b*b)+(a*a)-(c*c))/(2*a*b))*(180/PI)*100000)/100000.;
                        stepen=(int)alfa;
                        min=(alfa-stepen)*60;
                        minut=(int)min;
                        sekund=(min-minut)*60;
                    }}
                    
        else {
            printf("Raznostranicni \n");
            if(p==0){
                if((a>b)&&(a>c))
                alfa=round(acos(((b*b)+(c*c)-(a*a))/(2*b*c))*(180/PI)*100000)/100000.;
                else if((b>a)&&(b>c))
                alfa=round(acos(((a*a)+(c*c)-(b*b))/(2*a*c))*(180/PI)*100000)/100000.;
                else
                alfa=round(acos(((b*b)+(a*a)-(c*c))/(2*a*b))*(180/PI)*100000)/100000.;
                stepen=(int)alfa;
                min=(alfa-stepen)*60;
                minut=(int)min;
                sekund=(min-minut)*60;
              }
        }
        
        printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, minut,sekund);
        return 0;
        }
    
  
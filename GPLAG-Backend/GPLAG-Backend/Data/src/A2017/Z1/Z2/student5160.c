#include <stdio.h>
#include <math.h>
#define epsilon 0.0001

int main() 
{
    /* Unosenje koordinata*/
    
    double x1,x2,x3,y1,y2,y3,a,b,c,a2,b2,c2;
    double alfa,beta,gama,najveci,najvecim,razlika1,minute,minutez,razlika2,sekunde,sekundez,pi;
    printf("Unesite koordinate tacke t1: ");
    scanf("%lf %lf",&x1,&y1);
    printf("Unesite koordinate tacke t2: ");
    scanf("%lf %lf",&x2,&y2);
    printf("Unesite koordinate tacke t3: ");
    scanf("%lf %lf",&x3,&y3);
    
     /* Racunanje duzine stranica trougla */
        a=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
        b=sqrt(pow(x2-x3,2)+pow(y2-y3,2));
        c=sqrt(pow(x1-x3,2)+pow(y1-y3,2));
    
    /* Linija (paralelno osama) */
    if( (fabs(x1-x2)<epsilon && fabs(x2-x3)<epsilon && fabs(x1-x3)<epsilon) || (fabs(y1-y2)<epsilon && fabs(y2-y3)<epsilon && fabs(y1-y3)<epsilon) ) 
    { 
      printf("Linija\n");
      /*Izlaz*/
      printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.\n");
    }

    /* Linija */
    else if( fabs((x3-x2)-(x2-x1))<epsilon && fabs((y3-y2)-(y2-y1))<epsilon ) 
    { 
     printf("Linija\n"); 
     /*Izlaz*/
     printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.\n");
    }
    
    else
    {
       /* Da li je pravougli? */
        if ( fabs( (pow(a,2)+pow(b,2) ) - pow(c,2) )<epsilon || fabs( (pow(a,2)+pow(c,2) ) - pow(b,2) )<epsilon || fabs( (pow(b,2)+pow(c,2) ) - pow(a,2) )<epsilon ) { printf("Pravougli\n"); }
        
        /*Jednakostranicni*/
        if ( fabs(a-b)<epsilon && fabs(b-c)<epsilon && fabs(a-c)<epsilon) { printf("Jednakostranicni\n"); }
        
        /* Raznostranicni*/
        else if ( fabs(a-b)>epsilon && fabs(a-c)>epsilon && fabs(b-c)>epsilon) { printf("Raznostranicni\n"); }
        
        /*Jednakokraki*/
        else if ( (fabs(a-b)<epsilon && fabs(a-c)>epsilon) || (fabs(a-c)<epsilon && fabs(c-b)>epsilon) || (fabs(b-c)<epsilon && fabs(b-a)>epsilon) ){printf("Jednakokraki\n"); }
       
        /*Racunanje uglova*/
        pi=4*atan(1);
        alfa=(acos(((b*b+c*c-a*a)/(2*b*c)))*180/pi);
        beta=(acos(((c*c+a*a-b*b)/(2*b*c)))*180/pi);
        gama=(acos(((b*b+a*a-c*c)/(2*b*c)))*180/pi);

        /*Odredjivanje najveceg*/
        najveci=alfa;
        if(beta>najveci) { najveci=beta; }
        if(gama>najveci) { najveci=gama; }
        
        /*Racunanje minuta*/
        najvecim=(int)najveci;
        razlika1=najveci-najvecim;
        minute=razlika1*60;
        minutez=(int)minute;
        
        /*Racunanje sekundi*/
        razlika2=minute-minutez;
        sekunde=razlika2*60;
        sekundez=(int)sekunde;
        
        /*Izlaz*/
        printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.\n",najvecim,minutez,sekundez);
    }
return 0;
}

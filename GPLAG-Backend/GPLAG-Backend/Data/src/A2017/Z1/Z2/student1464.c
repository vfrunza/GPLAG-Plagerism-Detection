#include <stdio.h>
#include <math.h>
#define PI 3.14159265
#define eps 0.001


int main() {
    
    double a, b, c, A, B, C, x1, x2, y1, y2, x3, y3;
    double alfa, beta, gama;
    int stepeni, minute, sekunde;
    double najveciugao;
    
    
printf("Unesite koordinate tacke t1: ");
scanf("%lf %lf", &x1, &y1);

printf("Unesite koordinate tacke t2: ");
scanf("%lf %lf", &x2, &y2);

printf("Unesite koordinate tacke t3: ");
scanf("%lf %lf", &x3, &y3);

/*Racunanje stranica a, b, c*/

    a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    b=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
    c=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));

           
    /*Racunanje uglova*/
    
    A= acos((-a*a+b*b+c*c)/(2*b*c));
    B= acos((-b*b+a*a+c*c)/(2*a*c));
    C= acos((-c*c+a*a+b*b)/(2*a*b));
    
    alfa= A*(180./PI);
    beta=B*(180./PI);
    gama= C*(180./PI);
    
    
    /*Najveci ugao u trouglu*/
    
    if(alfa>=beta && alfa>=gama) { najveciugao=alfa; }
    if(beta>=alfa && beta>=gama) { najveciugao=beta; }
    if(gama>=alfa && gama>=beta) { najveciugao=gama; }
    
    
    /*Vrste trougla*/

    if (fabs(najveciugao-90)<=eps)
    { 
            printf("Pravougli\n"); 
          
    }
    
    if ((fabs(najveciugao-180)<eps)) {
            printf("Linija\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi."); return 0;
        
    }
    
    else if((fabs(a-c)<=eps && fabs(a-b)<=eps)) { 
            printf("Jednakostranicni\nNajveci ugao ima 60 stepeni, 0 minuta i 0 sekundi."); return 0;
        
    }
    else if((fabs(a-b)>eps) && (fabs(b-c)>eps) && (fabs(c-a)>eps)) {
            printf("Raznostranicni\n");
    }
    else if(fabs(a-b)<eps || fabs(b-c)<eps || fabs(a-c)<eps) {
            printf("Jednakokraki\n");
        
    }
    
    /*Stepeni, minute, sekunde*/
    
        stepeni=(int)najveciugao;
        minute=(int)((najveciugao-stepeni)*60);
        sekunde=(int)((najveciugao-stepeni-minute/60.)*3600 );
        
            printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
        

    	return 0;
    }

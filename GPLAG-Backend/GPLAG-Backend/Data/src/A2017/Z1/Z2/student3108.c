#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.14159265

int main() {
    double x1=0,x2=0,x3=0,y1=0,y2=0,y3=0;
    double a=0, b=0, c=0, A=0, B=0, G=0; 
    double m1=0, m2=0, m3=0, s1=0, s2=0, s3=0;
    
	
	/*-----------------------------*/
	/*    ULAZNI DIO PROGRAMA      */
	/*-----------------------------*/
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	

	/*-----------------------------*/
	/*       DUZINE STRANICA       */
	/*-----------------------------*/
	
	c=sqrt(pow((x1-x2), 2)+pow((y1-y2), 2));
	a=sqrt(pow((x2-x3), 2)+pow((y2-y3), 2));
	b=sqrt(pow((x3-x1), 2)+pow((y3-y1), 2));
	
	/*------------------------------*/
	/*       VRIJEDNOSTI UGLOVA     */
	/*------------------------------*/
	
	A=(acos((pow(b, 2) + pow(c, 2) - pow(a, 2))/(2 * b * c)))*180/PI;
    B=(acos((pow(a, 2) + pow(c, 2) - pow(b, 2))/(2 * c * a)))*180/PI;
    G=(acos((pow(a, 2) + pow(b, 2) - pow(c, 2))/(2 * a * b)))*180/PI;
    
    /*---------------------------------------*/
	/*                LINIJA                 */
	/*---------------------------------------*/
	
	if(round(A)==180 || round(B)==180 || round(G)==180) {
		printf("Linija\n");
		printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi."); return 0;
	}
   
    /*--------------------------------------------------------*/
	/*                       TROUGLOVI                        */
	/*--------------------------------------------------------*/
	
	
	/*-----------------------------------------*/
	/*               PRAVOUGLI                 */
	/*-----------------------------------------*/
	
	if(round(A) == 90 || round(B) == 90 || round(G) == 90) {
		printf("Pravougli\n"); 
		 
	}
	
	/*-----------------------------------------*/
	/*             JEDNAKOSTRANICNI            */
	/*-----------------------------------------*/
	
	
	if(fabs(a-b)<EPSILON && fabs(a-c)<EPSILON && fabs(b-c)<EPSILON ) {
	    printf("Jednakostranicni\n"); 
}
    /*-----------------------------------------*/
    /*              JEDNAKOKRAKI               */
    /*-----------------------------------------*/
    
    else if(fabs(a-b)<EPSILON  || fabs(a-c)<EPSILON  || fabs(b-c)<EPSILON) {
	    printf("Jednakokraki\n"); 
	}

    /*-----------------------------------------*/
    /*             RAZNOSTRANICNI              */
    /*-----------------------------------------*/
	
	else if(fabs(a-b)>EPSILON || fabs(a-c)>EPSILON || fabs(b-c)>EPSILON) {
	    printf("Raznostranicni\n");
	}
	

    /*------------------------------------------*/
    /*             VELICINE UGLOVA              */
    /*------------------------------------------*/
    
    m1=(A - (int)A) * 60;
    m2=(B - (int)B) * 60;
    m3=(G - (int)G) * 60;
    
    s1=(m1 - (int)m1) * 60;
    s2=(m2 - (int)m2) * 60;
    s3=(m3 - (int)m3) * 60;
    
    
    /*------------------------------------------*/
    /*             POREDJENJE UGLOVA            */
    /*------------------------------------------*/

    if(A>B && A>G) {
    	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", (int)A, (int)m1, (int)s1 );
    }
    
    else if(B>A && B>G) {
    	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", (int)B, (int)m2, (int)s2 );
    }
    
    else {
    	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", (int)G, (int)m3, (int)s3 );
    }
    
	return 0;
}

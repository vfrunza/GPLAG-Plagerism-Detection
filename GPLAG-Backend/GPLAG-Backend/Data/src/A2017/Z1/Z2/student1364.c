#include <stdio.h>
#include <math.h>
#define E 0.000001
#define PI 3.1415926535
int main() {
    
    double x1, x2, x3, y1, y2, y3, a, b, c, P, s, A, B, C, Am, Bm, Cm, As, Bs, Cs;
    
    printf("Unesite koordinate tacke t1: ");
    scanf("%lf %lf", &x1, &y1);
    printf("Unesite koordinate tacke t2: ");
    scanf("%lf %lf", &x2, &y2);
    printf("Unesite koordinate tacke t3: ");
    scanf("%lf %lf", &x3, &y3);
    
    
    a=sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    b=sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));
    c=sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));
    
    s=(a+b+c)/2;
    P=sqrt(s*(s-a)*(s-b)*(s-c));
    
    A=(acos((b*b + c*c - a*a)/(2*c*b))*((180.)/PI));
    B=(acos((a*a + c*c - b*b)/(2*c*a))*((180.)/PI));
    C=(acos((b*b + a*a - c*c)/(2*a*b))*((180.)/PI));
 
    
    Am=(A - floor(A))*60;
    Bm=(B - floor(B))*60;
    Cm=(C - floor(C))*60;
    
    
    As=(Am - floor(Am))*60;
    Bs=(Bm - floor(Bm))*60;
    Cs=(Cm - floor(Cm))*60;
    
    A= floor (A) ;
    B= floor (B) ;
    C= floor (C) ; 
    
    if(P==0){
    	printf("Linija \n");
    	}
    else {
    	
    	if((fabs(A-90)<E) || (fabs(B-90)<E) || (fabs(C-90)<E)){
    		printf("Pravougli\n");
    	}
    	if((fabs(A-60)<E) || (fabs(B-60)<E) || (fabs(C-60)<E)){
    		printf("Jednakostranicni\n");
    	}
    	if((fabs(a-b)<E || fabs(a-c)<E || fabs(b-c)<E) && ((fabs(A-60)>E) && (fabs(B-60)>E) && (fabs(C-60)>E))){
    		printf("Jednakokraki\n");
    	}
    		if(fabs(a-b)>E && fabs(a-c)>E && fabs(c-b)>E){
    		printf("Raznostranicni\n");
    	}
    	
    }
    if((a>b) && (a>c) || (fabs(b-c)<E) && (a>b) && (a>c)){
    	printf("Najveci ugao ima %.f stepeni, %.f minuta i %.f sekundi.", A, Am, As);
    }
     if(b>a && b>c || fabs(a-c)<E && b>a && b>c){
    	printf("Najveci ugao ima %.f stepeni, %.f minuta i %.f sekundi.", B, Bm, Bs);
    }
     if(c>a && c>b || fabs(b-a)<E && c>a && c>b){
    	printf("Najveci ugao ima %.f stepeni, %.f minuta i %.f sekundi.", C, Cm, Cs);
    }
	return 0;
}

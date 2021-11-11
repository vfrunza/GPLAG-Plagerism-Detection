#include <stdio.h>
#include <math.h>
#define eps 0.0001
#define PI 3.1415

int main() {
    int i;
    double a,b,c;
    double l,j,k,q,y,z;
    double x1,x2,x3,y1,y2,y3;
    double alfa, beta, gama;
	
	printf ("Unesite koordinate tacke t1: ");
	scanf ("%lf %lf", &x1, &y1);
	printf ("Unesite koordinate tacke t2: ");
	scanf ("%lf %lf", &x2, &y2);
	printf ("Unesite koordinate tacke t3: ");
	scanf ("%lf %lf", &x3, &y3);
    
    a=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
    b=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
    c=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    
    l=a+b;
    j=a+c;
    k=b+c;
    q=a*a;
    y=b*b;
    z=c*c;
    
     for(i=0;i<1;i--){
        
        if((j<=b)||(l<=c)||(k<=a)){
            printf("Linija\n");
            printf ("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
            break;
        }
        
        if((fabs(a-b)<eps) && (fabs(a-c)<eps) && (fabs(b-c)<eps)){
            printf("Jednakostranicni\n");
            printf ("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
        }
        
        else{
        	
            if ((fabs(a-b)<eps)||(fabs(b-c)<eps)||(fabs(a-c)<eps)){
                printf("Pravougli\n");
                
                if ((fabs(q-(y+z))<eps)||(fabs(y-(q+z))<eps)||(fabs(z-(y+q))<eps)){
                	printf("Jednakokraki\n");
                    printf ("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
                }
                break;
            }
            
            if ((fabs(q-(y+z))<eps)||(fabs(y-(q+z))<eps)||(fabs(z-(y+q))<eps)){
                printf("Pravougli\n");
                printf ("Raznostranicni\n");
                printf ("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
                
                break;
            }
            printf("Raznostranicni.\n");
            
            alfa = ((acos (b*b + c*c - a*a)) / (2*b*c))*(180/PI);
            beta = ((acos (c*c + a*a - b*b)) / (2*a*c))*(180/PI);
            gama = ((acos (a*a + b*b - c*c)) / (2*a*b))*(180/PI);
        
             break;
        }
        break;
    }
    return 0;
}
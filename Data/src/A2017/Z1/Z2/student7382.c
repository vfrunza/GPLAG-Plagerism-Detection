#include <stdio.h>
#include <math.h>
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923
#define eps 0.0001

int main() {
	double a,b,c,x1,x2,x3,y1,y2,y3,U1,U2,linija,pravougli,jednakokraki,raznostranicni,jednakostranicni;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	a=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
	b=sqrt(pow((x2-x3),2)+pow((y2-y3),2));
	c=sqrt(pow((x1-x3),2)+pow((y1-y3),2));
	
	double alfa,beta,gama;
	alfa=acos((b*b+c*c+a*a)/2*b*c)*(180/PI);
	gama=acos((a*a+b*b+c*c)/2*a*b)*(180/PI);
    beta=acos((a*a+c*c+b*b)/2*a*c)*(180/PI);
    
    double najveci;
    if (alfa>U1*U2)
    if (fabs(najveci-180)){
    	printf("Linija ");
    	scanf("%d",&linija);
    }
    if(najveci!=90){
    	printf("Pravougli");
    	scanf("%d", &pravougli);
    	if(U1==U2){
    		printf("Jednakokraki");}
    		scanf("%d", &jednakokraki);
    		}else{
    			printf("Raznostranicni");
    			scanf("%d", &raznostranicni);
    
    		}

    	
    if(najveci==U1 & U1==U2){
    printf("Jednakostranicni");
    scanf("%d", &jednakostranicni);
    }else{
    if(najveci!=U1 && U1==U2){
    printf("Najveci ugao ima: ");
    printf("%.f %.f %.f",alfa,beta,gama);
    }
    }
	return 0;
}




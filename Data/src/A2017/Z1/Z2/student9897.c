#include <stdio.h>
#define e=0.0001
#include <math.h>
#define PI 3.1415926


int main() {
	double x1,x2,x3,y1,y2,y3,d1,d2,d3,alfa,beta,gama,minuta1,minuta2,minuta3;
	int tsekunda1,tsekunda2,tsekunda3,sekunda1,sekunda2,sekunda3,stepen1,stepen2,stepen3;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3,&y3);
	
	if (x1==y1 && x2==x1 && y2>y1 && x3>x1 && y3==x3) {
		printf("Pravougli\nJednakokraki");
	} else if (x1<0 && x2<0 && x3<0 || y1<0 && y2<0 && y3<0) {
		printf("Jednakokraki");
	}
	
		else if(x1>x2 && x2>x3 && x1>x3 ||  y1<y2 && y3<y2 && y1==y3) {
		printf("Jednakostranicni");
	}
	 else if(x1!=x2 && x2!=x3 && y1==y2 && y2==y3 && y1==y3 || x1<x2 && x2<x3 && y1<y2 && y2<y3) 
	{
		printf("Linija");
	} 
	  else if (x1!=x2 && x2!=x3  && y1!=y3 && y3!=y2 && y1!=y2 ) {
		printf("Raznostranicni");
	}
	 else if  (x1==y1 && x1==x2 && y2>y1 && x3>x1 && y3==y2) {
		printf("Pravougli\nRaznostranicni");
	}
	
	d1=sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
	d2=sqrt(((x3-x2)*(x3-x2))+((y3-y2)*(y3-y2)));
	d3=sqrt(((x3-x1)*(x3-x1))+((y3-y1)*(y3-y1)));
	
	alfa= acos((d3*d3-d1*d1+d2*d2)/(2*d2*d3));
	
	beta=acos((d1*d1-d2*d2+d3*d3)/(2*d1*d3));
		
	gama=acos((d2*d2-d3*d3+d1*d1)/(2*d1*d2));

	
    alfa=(alfa*(180/PI));
    stepen1=((int)alfa);
    minuta1=((alfa-stepen1)*60);
    tsekunda1=((int)minuta1);
    sekunda1=(((minuta1-tsekunda1)*60));
    
    
    beta=(beta*(180/PI));
    stepen2=((int)beta);
    minuta2=((beta-stepen2)*60);
    tsekunda2=((int)minuta2);
    sekunda2=((minuta2-tsekunda2)*60);
    
    
    gama=(gama*(180/PI));
    stepen3=((int)gama);
    minuta3=((gama-stepen3)*60);
    tsekunda3=((int)minuta3);
    sekunda3=(((minuta3-tsekunda3)*60));

			
		if(alfa>beta && alfa>gama) {
		printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi." ,stepen1, tsekunda1,sekunda1);
	} else if(beta>alfa && beta>gama)
	{
		printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen2,tsekunda2,sekunda2);
	} else if (gama>alfa && gama>beta) {
		printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen3,tsekunda3,sekunda3);
	} 

	return 0;
}

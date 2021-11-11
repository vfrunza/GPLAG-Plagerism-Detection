#include <stdio.h>
#include<math.h>
#define e 0.0001
#define PI 3.14

int main() {
	double x1,y1,x2,y2,x3,y3,a,b,c,P,alfa,beta,gama;
	char n;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	scanf("%c",&n);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	scanf("%c",&n);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	scanf("%c",&n);

	a=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	b=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	c=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	P=1./2*fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
	if(P==0){
		printf("Linija\n");
		printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.\n");
	}
    if(fabs(P-((a*c)/2))<=e){
		printf("Pravougli\n");
		printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.\n");
		
	}
    if(fabs(P-((a*a*sqrt(3))/4))<=e){
    	printf("Jednakostranicni\n");
    	printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.\n");
    }
    if((fabs(a-b)<e)&&(fabs(a-c)<e)&&(fabs(b-c)<e)){
    	printf("Raznostranicni\n");
    	
    }
    if(fabs(P-((b*sqrt(4*c*c-b*b))/4))<=e && P!=0 && a-b>=e){
    	printf("Jednakokraki\n");
    	
    }
    if((fabs(P-((b*sqrt(4*c*c-b*b))/4))<=e && P!=0 && a-b>=e) && (fabs(P-((a*c)/2))<=e)){
    	printf("Jednakokraki\n");
    	printf("Pravougli\n");
    	printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.\n");
    }
 
 return 0;
}
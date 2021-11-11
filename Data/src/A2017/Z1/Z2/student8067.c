#include <stdio.h>
#include <math.h>
#define EPS 0.0001
#define PI 3.14159

int main() {
	double x1,y1,x2,y2,x3,y3,a,b,c,alfa,beta,gama,max=0,S;
	int step,min,sek;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	b=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	c=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	
	alfa=acos(((b*b)+(c*c)-(a*a))/(2*b*c));
	beta=acos(((a*a)+(c*c)-(b*b))/(2*a*c));
	gama=acos(((a*a)+(b*b)-(c*c))/(2*a*b));
	
	
	
	if(alfa>=beta && alfa>=gama) {
		max=alfa;
	}
	else if(beta>=alfa && beta>=gama) {
		max=beta;
	}
	else if(gama>=alfa && gama>=beta) {
		max=gama;
	}

	
	S=max*180/PI;
		
	step=(int)(S);
	
	min=(int)((S-step)*60);
	
	sek=(int)(S*3600)%60;
	
	if(step==180) {
		printf("Linija\n");
		printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
		return 0;
	}
		if((c==sqrt((a*a)+(b*b)) || a==sqrt((b*b)+(c*c)) || b==sqrt((a*a)+(c*c)))) {
		printf("Pravougli\n");
		
		
	}
	
	
	if(fabs(a-b)<EPS && fabs(b-c)<EPS ) {
		printf("Jednakostranicni\n");
	
		
	}

	else if((fabs(a-b)<EPS && fabs(b-c)>EPS) || (fabs(a-c)<EPS && fabs(c-b)>EPS) || (fabs(b-c)<EPS && fabs(c-a)>EPS)) {
		printf("Jednakokraki\n");
		
		
	}

	
	else if(a!=b && b!=c) {
		printf("Raznostranicni\n");
		
		
	}
	
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",step,min,sek);
	

	
	return 0;
}

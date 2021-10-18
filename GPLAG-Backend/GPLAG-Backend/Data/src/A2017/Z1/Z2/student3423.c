#include <stdio.h>
#define E 0.0001
#include <math.h>
#define PI 3.141592653

int main() {
	double x1, x2, x3, y1, y2, y3;
	double a,b,c;
	double maxstr, minstr, srstr;
	double u1, u2, u3, maxu;
	int stepeni, minute, sekunde;
		
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
		
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
		
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	
	a=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
	b=sqrt(pow(x3-x2,2)+pow(y3-y2,2));
	c=sqrt(pow(x1-x3,2)+pow(y1-y3,2));
	
	if (a>=b && b>=c){
		maxstr=a;
		srstr=b;
		minstr=c;
	}
	
	else if(a>=c && c>=b){
		maxstr=a;
		srstr=c;
		minstr=b;
	}
	
	else if(b>=a && a>=c){
		maxstr=b;
		srstr=a;
		minstr=c;
	}
	
	else if(b>=c && c>=a){
		maxstr=b;
		srstr=c;
		minstr=a;
	}
	else if(c>=a && a>=b){
		maxstr=c;
		srstr=a;
		minstr=b;
	}
	
	else if (c>=b && b>=a) {
		maxstr=c;
		srstr=b;
		minstr=a;
	}

	
	u1=acos((pow(a,2)+pow(c,2)-pow(b,2))/(2*a*c));
	u2=acos((pow(a,2)+pow(b,2)-pow(c,2))/(2*a*b));
	u3=acos((pow(b,2)+pow(c,2)-pow(a,2))/(2*b*c));
	
	u1=u1*(180/PI);
	u2=u2*(180/PI);
	u3=u3*(180/PI);
	
	if (u1>=u2 && u2>=u3){
		maxu=u1;
	}
	else if(u1>=u3 && u3>=u2){
		maxu=u1;
	}
	else if(u2>=u3 && u3>=u1){
		maxu=u2;
	}
	else if (u2>=u1 && u1>=u3){
		maxu=u2;
	}
	else if(u3>=u2 && u2>=u1){
		maxu=u3;
	}
	else if(u3>=u1 && u1>=u2){
		maxu=u3;
	}
	
	
	
	stepeni=(int)(maxu);
	minute=(int)((maxu-stepeni)*60);
	sekunde=(int)(((maxu-stepeni)*60-minute)*60);
	
	if ((stepeni<=E)  || (fabs(stepeni-180)<=E)){
		printf("Linija\n");
		
	}
	else {
		if(fabs(pow(maxstr,2)-pow(srstr,2)-pow(minstr,2))<E){
		printf("Pravougli\n");
	}
	if(fabs(a-b)<=E && fabs(a-c)<=E && fabs(b-c)<=E){
		printf("Jednakostranicni\n");
	}
	else if(fabs(a-c)<=E || fabs(a-b)<=E || fabs(b-c)<=E ){
		printf("Jednakokraki\n");
	}
	else { printf("Raznostranicni\n"); }

	

		
	}
	
	
	
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi." , stepeni, minute, sekunde);
	
	
	
	
	return 0;
}

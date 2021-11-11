#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.141592
int main() {
	
	double x1,y1,x2,y2,x3,y3,a,b,c,A,B,C,cos1,cos2,cos3,r1,r2,r3,v,n,o;
    int s,m,se;
	v=180.0/PI;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf%lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf%lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf%lf",&x3,&y3);
	
    b=(sqrt(pow((x2-x1),2)+pow((y2-y1),2)));
    a=(sqrt(pow((x3-x2),2)+pow((y3-y2),2)));
    c=(sqrt(pow((x3-x1),2)+pow((y3-y1),2)));
    
	A=(((b*b)+(c*c)-(a*a))/(2*b*c));
	B=(((a*a)+(c*c)-(b*b))/(2*a*c));
	C=(((a*a)+(b*b)-(c*c))/(2*b*a));
	
	r1=acos(A)*v;
	r2=acos(B)*v;
	r3=acos(C)*v;
	
	if((fabs(r1-90)<EPSILON) || (fabs(r2-90)<EPSILON) || fabs(r3-90)<EPSILON){
		printf("Pravougli\n");
	}
	if((fabs(r1-180)<EPSILON)||(fabs(r2-180)<EPSILON)||(fabs(r3-180)<EPSILON)){
		printf("Linija\n");
	}
    
    else if(((int)r1==(int)r2) && ((int)r2==(int)r3) && ((int)r1==(int)r3)){
    	printf("Jednakostranicni\n");
    }
	else if(((int)r1!=(int)r2) && ((int)r2!=(int)r3) && ((int)r1!=(int)r3)){
		printf("Raznostranicni\n");
	}
	else{
		printf("Jednakokraki\n");
	}
	
	if((r1>=r2) && (r1>=r3)){
	s=(int)r1;
	n=(fabs(r1-s)*60);
	m=(int)n;
	o=(fabs(m-n)*60);
	se=(int)o;
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",s,m,se);	     }
	
	if((r2>=r3) && (r2>=r1)){
	s=(int)r2;
	n=(fabs(r2-s)*60);
	m=(int)n;
	o=(fabs(m-n)*60);
	se=(int)o;
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",s,m,se);
	     }
	     
	if((r3>=r1) && (r3>=r2)){
	s=(int)r3;
	n=(fabs(r3-s)*60);
	m=(int)n;
	o=(fabs(m-n)*60);
	se=(int)o;
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",s,m,se);
	     }
	return 0;
}

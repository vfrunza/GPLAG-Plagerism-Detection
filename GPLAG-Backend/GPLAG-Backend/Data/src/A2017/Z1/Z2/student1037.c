#include <stdio.h>
#include <math.h>
#define PI 3.14159265359

int main() {
	
	double x1,y1,x2,y2,x3,y3,t1,t2,t3,a,b,c,ug1,ug2,ug3,m1,m2,m3,p;
	int ug11,ug22,ug33,m11,m22,m33,s11,s22,s33;
	float E=0.0001;
	printf("Unesite koordinate tacke t1: ");
	scanf("%f %f", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%f %f", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%f %f", &x3, &y3);
	
	

	a=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	b=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	c=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	
	
	if(p==0){
		printf("Linija\n");
	}
		if(((fabs(a*a-b*b-c*c))<E)||((fabs (b*b-c*c-a*a))<E ||((fabs(c*c-a*a-b*b))))){
			printf("Pravougli\n");
		}
			
		if( (fabs (a-b)) > E && (fabs (b-c)) >E && (fabs (a-c) >E )){
			printf("Jednakostranicni\n");
		}
	
		
		if(((fabs(c-a)<E) || (fabs(a-b)>E) || (fabs(b-c)>E))){
			printf("Jednakokraki\n");
		}
		if(fabs(a-b)>E && fabs(b-c)>E && fabs(c-a)>E){
			printf("Raznostranicni\n");
		}
		 
	
  ug1=(acos((b*b+c*c-a+a)/(2*b*c)))*180/3.14159265359+E ;
  ug2=(acos((a*a+c*c-b*b)/(2*a*c)))*180/3.14159265359+E ;
  ug3=(acos((b*b+a*a-c*c)/(2*b*a)))*180/3.14159265359+E ;
    ug11=ug1/1;
    ug22=ug2/1;
    ug33=ug3/1;
    m1=(ug1-ug11)*60;
    m2=(ug2-ug22)*60;
    m3=(ug3-ug33)*60;
    m11=m1/1;
    m22=m2/1;
    m33=m3/1;
    s11=(m1-m11)*60;
    s22=(m2-m22)*60;
    s33=(m3-m33)*60;
    if((ug1>ug2) && (ug1>ug3)){
      printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi, ug1 m1 s11", ug11, m11, s11);
    	}
    if((ug2>ug1)&&(ug2>ug3)){
    	printf("Najveci ugao ima %d stepeni, %d minuta i %sekundi", ug22, m22, s22);
    }
    if((ug3>ug2)&&(ug3>ug1)){
    	printf("Najveci ugao ima %d stepeni, %d minuta i %sekundi", ug33, m33, s33);
    }
    return 0;
}
    
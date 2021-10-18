#include <stdio.h>
#include <math.h>
#define E 0.0001
int main() {
	double ug1,ug2,ug3,x1,x2,x3,y1,y2,y3,a,b,c,p,m1,m2,m3;
	int ug11,ug22,ug33,m11,m22,m33,s11,s22,s33;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	a=sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
	c=sqrt(((x3-x2)*(x3-x2))+((y3-y2)*(y3-y2)));
	b=sqrt(((x1-x3)*(x1-x3))+((y1-y3)*(y1-y3)));
	p=fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2;
	if(p==0){
		printf("Linija\n");
		}else{
		if(((fabs(a-b))<E)&&((fabs(b-c))<E)){
			printf("Jednakostranicni\n");
		}
		if((a==sqrt(b*b+c*c))||(b==sqrt(c*c+a*a))||(c==sqrt(b*b+a*a))){
	printf("Pravougli\n");}
		if(((fabs(a-c)<E)&&(fabs(b-c)>E)&&(fabs(b-a)>E)) || ((fabs(b-c)<E)&&(fabs(a-c)>E)&&(fabs(b-a)>E)) || ((fabs(a-b)<E)&&(fabs(b-c)>E)&&(fabs(a-c)>E))){
			printf("Jednakokraki\n");
	}
	
		if(((fabs(a-b))>=E)&&((fabs(b-c))>=E)&&(fabs(a-c))>=E){
		printf("Raznostranicni\n");
	}
		
	}	
	ug1=(acos((b*b+c*c-a*a)/(2*b*c)))*180/3.14159265359+E; 
			ug2=(acos((a*a+c*c-b*b)/(2*a*c)))*180/3.14159265359+E;
			ug3=(acos((b*b+a*a-c*c)/(2*b*a)))*180/3.14159265359+E;
			
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
			if((ug1>ug2)&&(ug1>ug3)){
				printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", ug11,m11,s11);
			} if((ug2>ug1)&&(ug2>ug3)){
				printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", ug22,m22,s22);}
				
		if((ug3>ug2)&&(ug3>ug1)){
				printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", ug33,m33,s33);}
	return 0;
}

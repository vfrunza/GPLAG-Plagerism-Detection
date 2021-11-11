#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159
#define e 0.0001

int main(){
	
	float x1, x2, x3, y1, y2, y3, a, b, c, t1, t2, t3, P, S, A, B, C;
	float stepen, m, s;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%f", &x1);
	scanf("%f", &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%f", &x2);
	scanf("%f", &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%f", &x3);
	scanf("%f", &y3);
	
	t1 = pow(x3-x2, 2) + pow(y3-y2, 2);
	a = sqrt(t1);
	t2 = pow(x3-x1, 2) + pow(y3-y1, 2);
	b = sqrt(t2);
	t3 = pow(x1-x2, 2) + pow(y1-y2, 2);
	c = sqrt(t3);
	
	A = acos((b*b+c*c-a*a)/(2*b*c))*(180/PI);
	B = acos((a*a+c*c-b*b)/(2*a*c))*(180/PI);
	C = acos((b*b+a*a-c*c)/(2*b*a))*(180/PI);
	
	P = fabs((x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2);
	
	if(P<e){
		
		printf("Linija\n");
		printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
		return 0;
		
	}else{
		
		if((fabs(a-b)<=e) && (fabs(a-c)<=e) && (fabs(b-c)<=e)){
		
		printf("Jednakostranicni\n");
		
	}else if(((fabs(A-90)<=e)) || ((fabs(B-90)<=e)) || ((fabs(C-90)<=e))){
		
		printf("Pravougli\n");
		
	}if(((fabs(a-b)<e) && (fabs(a-c)>e)) || ((fabs(a-c)<e) && (fabs(a-b)>e)) || ((fabs(b-c)<e) && (fabs(b-a)>e))){
		
		printf("Jednakokraki\n");
	
    }if((fabs(a-b)>e) && (fabs(a-c)>e) && (fabs(b-c)>e)){
		
		printf("Raznostranicni\n");
		
}
}

if(a>=b && a>=c){
	
	stepen=(int) A;
	A = A - stepen;
	m = (int)(A*60);
	A = A*60;
	A = A - (int)(A);
	s = (int)(A*60);
	
	printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.", stepen, m, s);

	
}else if(b>=a && b>=c){
	
	stepen=(int) B;
	B = B - stepen;
	m = (int)(B*60);
	B = B*60;
	B = B - (int)(B);
	s = (int)(B*60);
	
	printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.", stepen, m, s);
	
}else if(c>=a && c>=b){
	
	stepen=(int) C;
	C = C - stepen;
	m = (int)(C*60);
	C = C*60;
	C = C - (int)(C);
	s = (int)(C*60);
	
	printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.", stepen, m, s);
	
}
	return 0;
}
	



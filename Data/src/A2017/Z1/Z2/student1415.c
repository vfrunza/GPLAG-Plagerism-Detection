#include <stdio.h>
#include <math.h>
#define PI 3.14159
#define E 0.0001

int main() {
	double Ax, Ay, Bx, By, Cx, Cy, D1, D2, D3, C1, C2, C3, P1, P2, P3, A1, A2, A3, U, m, s, L1, L2, L3;
	int S, se, M;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&Ax, &Ay);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&Bx, &By);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&Cx, &Cy);
	
	D1=sqrt(pow((Ax-Bx),2)+pow((Ay-By),2));
	D2=sqrt(pow((Ax-Cx),2)+pow((Ay-Cy),2));
	D3=sqrt(pow((Cx-Bx),2)+pow((Cy-By),2));
	
	C1=(pow(D2,2)+pow(D3,2)-pow(D1,2))/(2*D2*D3);
	C2=(pow(D1,2)+pow(D3,2)-pow(D2,2))/(2*D1*D3);
	C3=(pow(D1,2)+pow(D2,2)-pow(D3,2))/(2*D1*D2);
	
	A1=acos(C1);
	A2=acos(C2);
	A3=acos(C3);
	
	P3=sqrt(pow(D1,2)+pow(D2,2));
	P2=sqrt(pow(D1,2)+pow(D3,2));
	P1=sqrt(pow(D3,2)+pow(D2,2));
	
	L1=fabs((Cy-By)/(Cx-Bx));
	L2=fabs((Cy-Ay)/(Cx-Ax));
	L3=fabs((By-Ay)/(Bx-Ax));
	

	if(fabs(L1-L2)<E && fabs(L2-L3)<E && fabs(L1-L3)<E){
		printf("Linija");
	}
	
	else {
	if(fabs(P1-D1)<E || fabs(P2-D2)<E || fabs(P3-D1)<E) {
		printf("Pravougli\n");
	}
	
	if((fabs(D1-D2)<E) && fabs(D2-D3)<E && fabs(D1-D3)<E) {
		printf("Jednakostranicni");
	}
	else if (fabs(D1-D2)<E || fabs(D1-D3)<E || fabs(D2-D3)<E ) {
		printf("Jednakokraki");
	}
	
	else {

		printf ("Raznostranicni");
	}
	}

	
	
	if(A1>A2 && A1>A3) {
		U=A1;
	}
	else if(A2>A1 && A2>A3) {
		U=A2;
	}
	else {
		U=A3;
	}
	s=U*180/PI;
	S=(int)s;
	m=(s-S)*60;
	M=(int)m;
	se=(int)((m-M)*60);

	printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.",S,M,se);
	return 0;
}

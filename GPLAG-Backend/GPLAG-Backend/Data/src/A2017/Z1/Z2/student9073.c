#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979
#define G 0.0001

int main()
{
	float x1, x2, x3, y1, y2, y3, A, B, C, A1, B1, C1, z, t, g, h, p, q, r, c, l, m, n, j;
	printf("Unesite koordinate tacke t1: ");
	scanf("%f %f", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%f %f", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%f %f", &x3, &y3);

	A1=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	B1=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	C1=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));

	if((fabs(A1+B1-C1)<=G)||(fabs(C1+B1-A1)<=G)||(fabs(A1+C1-B1)<=G)) {
		printf("Linija\n");
		printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
		return 0;
	}

	if((fabs(A1*A1-B1*B1-C1*C1)<=G)||(fabs(B1*B1-C1*C1-A1*A1)<=G)||(fabs(C1*C1-B1*B1-A1*A1)<=G)){
		printf("Pravougli\n");
}
	if((fabs(A1-B1)>G)&&(fabs(B1-C1)>G)&&(fabs(C1-A1)>G)){
		printf("Raznostranicni\n");
}

	if((fabs(A1-B1)<=G)&&(fabs(B1-C1)<=G)&&(A1-C1)<=G){
		printf("Jednakostranicni\n");
}

	if(((fabs(A1-B1)<=G)&&(fabs(B1-C1)>G))||((fabs(A1-C1)<=G)&&(fabs(C1-B1)>G))||((fabs(C1-B1)<=G)&&(fabs(B1-A1)>G))){
		printf("Jednakokraki\n");
}


	A=acos((B1*B1+C1*C1-A1*A1)/(2*B1*C1));
	A=(180*A)/(PI);
	z=A-(int)A;
	t=z*60;
	g=t-(int)t;
	h=g*60;

	B=acos((A1*A1+C1*C1-B1*B1)/(2*A1*C1));
	B=(180*B)/(PI);
	p=B-(int)B;
	r=p*60;
	q=r-(int)r;
	c=q*60;

	C=acos((A1*A1+B1*B1-C1*C1)/(2*A1*B1));
	C=(180*C)/(PI);
	l=C-(int)C;
	m=l*60;
	n=m-(int)m;
	j=n*60;

	if(((A1>=B1)&&(B1>=C1))||((A1>=C1)&&(C1>=B1))) {
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", (int)A, (int)t, (int)h);}
	else if(((B1>=A1)&&(A1>=C1))||((B1>=C1)&&(C1>=A1))){
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", (int)B, (int)r, (int)c);}
	else if(((C1>=B1)&&(B1>=A1))||((C1>=A1)&&(A1>=B1))){
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", (int)C, (int)m, (int)j);}

	return 0;
}

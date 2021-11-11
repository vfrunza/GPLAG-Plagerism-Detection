#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.14159

int main() {
	double ax,ay,bx,by,cx,cy,a,b,c,alfa,beta,gama;
	double minut1, minut2, minut3, sekund1, sekund2,sekund3;
	int stepen1, stepen2, stepen3, minut11, minut22, minut33, sekund11, sekund22, sekund33;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &ax, &ay);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &bx, &by);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &cx, &cy);
	a=sqrt((bx-cx)*(bx-cx)+(by-cy)*(by-cy)); 
	b=sqrt((ax-cx)*(ax-cx)+(ay-cy)*(ay-cy)); 
	c=sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
	alfa=acos((c*c+b*b-a*a)/(2*c*b))*(180/PI); 
	beta=acos((a*a+c*c-b*b)/(2*a*c))*(180/PI);
	gama=acos((a*a+b*b-c*c)/(2*a*b))*(180/PI);
	stepen1=(int)alfa; stepen2=(int)beta; stepen3=(int)gama;
	if ((a<b+c) && (b<a+c) && (c<a+b)){
		if ((fabs(a-b)<EPSILON) && (fabs(a-c)<EPSILON) && (fabs(b-c)<EPSILON) && (fabs(stepen2-stepen3)<EPSILON) && (fabs(stepen1-stepen2)<EPSILON)) 
		printf("Jednakostranicni\n");
		else if ((fabs(a-b)<EPSILON) || (fabs(a-c)<EPSILON) || (fabs(b-c)<EPSILON)){
			if((fabs(stepen1-90)<EPSILON) || (fabs(stepen2-90)<EPSILON) || (fabs(stepen3-90)<EPSILON)) printf("Pravougli\n");
			printf("Jednakokraki\n");
		}
		else if(((fabs(stepen1-90)<EPSILON) || (fabs(stepen2-90)<EPSILON) || (fabs(stepen3-90)<EPSILON)) && (fabs(a-b)>EPSILON) && (fabs(b-c)>EPSILON) && (fabs(a-c)>EPSILON)) {
		printf("Pravougli");
		printf("\nRaznostranicni");}
		else printf("Raznostranicni");
	}
	else if((fabs(a-(b+c))<EPSILON) || (fabs(b-(a+c))<EPSILON) || (fabs(c-(a+b))<EPSILON)) printf("Linija\n");
	minut1=(alfa-stepen1)*60; minut2=(beta-stepen2)*60; minut3=(gama-stepen3)*60;
	minut11=(int)minut1; minut22=(int)minut2; minut33=(int)minut3;
	sekund1=(minut1-minut11)*60; sekund2=(minut2-minut22)*60; sekund3=(minut3-minut33)*60;
	sekund11=(int)sekund1; sekund22=(int)sekund2; sekund33=(int)sekund3;
	if((stepen1>=stepen2) && (stepen1>=stepen3)) printf ("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen1, minut11,sekund11);
	else if((stepen2>stepen1) && (stepen2>=stepen3)) printf ("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen2, minut22, sekund22);
	else printf ("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen3, minut33,sekund33);
	return 0;
}

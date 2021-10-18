#include <stdio.h>
#include <math.h>
#define E 0.0001
#define PI 3.141592
int main () {
	double x1,y1,x2,y2,x3,y3,a,b,c,L,B,Y,max;
	int stepen,minut,sekund;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3,&y3);
	
	a=sqrt(pow(x3-x2,2)+pow(y3-y2,2) );
	b=sqrt(pow(x3-x1,2)+pow(y3-y1,2) );
	c=sqrt(pow(x2-x1,2)+pow(y2-y1,2) );
	
	L=acos( (b*b+c*c-a*a)/(2*b*c) );
	B=acos( (a*a+c*c-b*b)/(2*a*c) );
	Y=acos( (a*a+b*b-c*c)/(2*a*b) );
	L*=180/PI;
	B*=180/PI;
	Y*=180/PI;
	
	if( (90-E)<B && B<(90+E) || (90-E)<L && L<(90+E) || (90-E)<Y && Y<(90+E) ){
		printf("Pravougli\n");
	}
	if( (180-L)<E || (180-B)<E || (180-Y)<E ){
		printf("Linija\n");
	}
	else if( (fabs(a-b)<E && fabs(a-c)<E) || (fabs(b-a)<E && fabs(b-c)<E) ){
		printf("Jednakostranicni\n");
	}
	else if( fabs(a-b)<E || fabs(a-c)<E || fabs(b-c)<E ){
		printf("Jednakokraki\n");
	}
	else if(a!=b && a!=c){
		printf("Raznostranicni\n");
	}
	
	max=L;
	if(L<B){
		max=B;
	}
	if(L<Y){
		max=Y;
	}
	if(Y<B){
		max=B;
	}
	if(B<Y){
		max=Y;
	}
	stepen=(int)max;
	max-=stepen;
	max*=60;
	minut=(int)max;
	max-=minut;
	max*=60;
	sekund=(int)max;
	
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen,minut,sekund);

	return 0;
}
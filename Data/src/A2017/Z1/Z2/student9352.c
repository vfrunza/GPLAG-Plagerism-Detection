#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.14159265

int main() {
	double x1, x2, x3, y1, y2, y3, a, b, c, ugao1, ugao2, ugao3, najveci_ugao, sekunde, minute, stepen;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	a = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
	b = sqrt((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1));
	c = sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));
	ugao1 = (double)(b*b + c*c -a*a)/2*b*c;
	ugao2 = (double)(c*c +a*a-b*b)/2*a*c;
	printf("%g, %g, %g", ugao1, ugao2, ugao3);
	ugao1 = acos(ugao1);
	ugao2 = acos(ugao2);
	ugao3 = 180.0000 - ugao2 - ugao1;
	printf("%g, %g, %g", ugao1, ugao2, ugao3);
	
	if((ugao1>=ugao2-EPSILON && ugao1<=ugao2+EPSILON) && (ugao1>=ugao3-EPSILON && ugao1<=ugao3+EPSILON)) najveci_ugao = ugao1;
	else if((ugao2>=ugao1-EPSILON && ugao2<=ugao1+EPSILON) && (ugao2>=ugao3-EPSILON && ugao2<=ugao3+EPSILON)) najveci_ugao = ugao2;
	else najveci_ugao = ugao3;
	najveci_ugao = najveci_ugao*180.00/PI;
	stepen = (int) najveci_ugao;
	minute = (int)((najveci_ugao-stepen)*60);
	sekunde = (int) (((najveci_ugao-stepen)*60 - minute)*60);
	
	
	if(( a>=b-EPSILON && a<=b+EPSILON ) && ( a>=c-EPSILON && a<=c+EPSILON ) && ( c>=b-EPSILON && c<=b+EPSILON )) printf("Jednakostranicni\n");
	if( (fabs(c*c-a*a-b*b) <= EPSILON) || ( fabs(-c*c+a*a-b*b) <= EPSILON) || ( fabs(-c*c-a*a+b*b) <= EPSILON)) printf("Pravougli\n");
	
	if(( a<b-EPSILON || a>b+EPSILON ) && ( a<c-EPSILON || a>c+EPSILON ) && ( c<b-EPSILON || c>b+EPSILON )) printf("Raznostranicni\n");
	
	printf("Najveci ugao ima %.2f stepeni, %.2f minuta i %.2f sekundi.", stepen, minute, sekunde);
	
	return 0;
}

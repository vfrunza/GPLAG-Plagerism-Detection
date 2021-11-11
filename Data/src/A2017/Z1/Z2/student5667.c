#include<stdio.h>
#include<math.h>
#define epsilon 0.0001

int main(){double PI = 4 * atan(1);
	double x1,y1,x2,y2,x3,y3;char a;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1,&y1);
	scanf("%c", &a);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2,&y2);
	scanf("%c", &a);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3,&y3);
	double help1 = x1 * (y2 - y3);
	double help2 = x2 * (y3 - y1);
	double help3 = x3 * (y1 - y2);
	double aa = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
	double b = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
	double c = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	double P = 1./2 * fabs(help1 + help2 + help3);
	if(P == 0)printf("Linija\n");
	else if(fabs(P - (aa * c / 2)) <= epsilon)printf("Pravougli\n");
	else if(fabs(P - ((aa * aa * sqrt(3) / 4))) <= epsilon)printf("Jednakostranicni\n");
    if(fabs(P - (b * sqrt(4 * c * c - b * b) / 4)) <= epsilon && P != 0 && fabs(aa - b) >= epsilon) printf("Jednakokraki\n");
    if(fabs(aa - b) > epsilon && fabs(aa - c) > epsilon && fabs(b - c) > epsilon)printf("Raznostranicni\n");
	double alfa = acos((aa * aa - b * b - c * c) / -(2 * b * c));
	double beta = acos((b * b - aa * aa - c * c) / -(2 * aa * c));
	double gama = acos((c * c - aa * aa - b * b) / -(2 * aa * b));
	double max;
	if(alfa > beta && alfa > gama)max = alfa;
	else if(beta > alfa && beta > gama)max = beta;
	else max = gama;
	max = max * 180 / PI;
	int stepen = (int)max;
	double m = (max - stepen) * 60;
	int minute = (int)m;
	if(P == 0)printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.\n");
	else printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, minute, (int)((m - minute) * 60));
	return 0;
}
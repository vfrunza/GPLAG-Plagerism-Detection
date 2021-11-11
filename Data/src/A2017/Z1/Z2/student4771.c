#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.14
int main() {
	int stepeni, minute, sekunde;
	double x1, y1, x2, y2, x3, y3, S;
	double t1, t2, t3, max = 0;
	double alfa1, alfa2, alfa3;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
		t1 = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
		t2 = sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
		t3 = sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	S = x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2);
	alfa1 = acos((t1*t1 + t2*t2 - t3*t3)/(2*t1*t2));
	alfa2 = acos((t2*t2 + t3*t3 - t1*t1)/(2*t2*t3));
	alfa3 = acos((t1*t1 + t3*t3 - t2*t2)/(2*t1*t3));
	if(fabs(S) < EPSILON ) printf("Linija\n");
	else {
		if(t1 + t2 > t3 || t2 + t3 > t1 || t1 + t3 > t2){
			if(fabs(t1*t1 + t2*t2 - t3*t3) < EPSILON || fabs(t2*t2 + t3*t3 - t1*t1) < EPSILON || fabs(t1*t1 + t3*t3 - t2*t2) < EPSILON){
				printf("Pravougli\n");
				if(fabs(t1 - t2) < EPSILON || fabs(t2 - t3) < EPSILON || fabs(t1 - t3) < EPSILON) printf("Jednakokraki\n");
				else if(fabs(t1 - t2) > EPSILON && fabs(t2 - t3) > EPSILON && fabs(t1 - t3) > EPSILON) printf("Raznostranicni\n");
				else return 0;
			}
			else if((fabs(t1 - t2) < EPSILON || fabs(t2 - t3) < EPSILON || fabs(t1 - t3) < EPSILON) && !(fabs(t1*t1 + t2*t2 - t3*t3) < EPSILON || fabs(t2*t2 + t3*t3 - t1*t1) < EPSILON || fabs(t1*t1 + t3*t3 - t2*t2) < EPSILON))
				printf("Jednakokraki\n");
			else if(fabs(t1 - t2) < EPSILON && fabs(t2 - t3) < EPSILON) printf("Jednakostranicni\n");
			else printf("Raznostranicni\n");
		}
	}
	if(alfa1 < alfa2 && alfa1 < alfa3) max = alfa1;
	else if(alfa2 < alfa1 && alfa2 < alfa3) max = alfa2;
	else if(alfa3 < alfa1 && alfa3 < alfa2) max = alfa3;
	stepeni = (int) (max*180)/PI;
	minute = (int) stepeni * 60;
	sekunde = (int) stepeni * 3600;
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
	return 0;
}

#include <stdio.h>
#include <math.h>
#define PI 3.14159

int main() {
	double x1, y1, x2, y2, x3, y3, d1, d2, d3, P;
	double epsilon = 0.0001;
	double ugao_d1d2, ugao_d1d3, ugao_d2d3, max_ugao;
	double max_ugao_step, max_ugao_min, max_ugao_sec;

	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	/*Vrste trougla*/
	/*d(t1,t2)*/ d1 = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
	/*printf("%lf\n", d1);*/
	/*d(t1,t3)*/ d2 = sqrt((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1));
	/*printf("%lf\n", d2);*/
	/*d(t2,t3)*/ d3 = sqrt((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));
	/*printf("%lf\n", d3);*/
	P = fabs((1.0/2)*((x1*(y2-y3)) + (x2*(y3-y1)) + (x3*(y1-y2))));
	/*printf("%lf\n", P);*/
	/*printf("d1 - d2 je %lf a d2 - d3 je %lf.\n", fabs(d1-d2), fabs(d2-d3));*/
	
	if (fabs(P) <= epsilon){
		printf("Linija\n");
	} 
	else {
		if(fabs(d1 - d2) <= epsilon && fabs(d2 - d3) <= epsilon){
			printf("Jednakostranicni\n");
		} 
		if( fabs(d1*d1 - (d2*d2 + d3*d3)) <= epsilon || fabs(d2*d2 - (d1*d1 + d3*d3)) <= epsilon || fabs(d3*d3 - (d1*d1 + d2*d2)) <= epsilon){
			printf("Pravougli\n");
		} 
		if( ( fabs(d1 - d2) <= epsilon && fabs(d1 - d3) > epsilon) || ( fabs(d2 - d3) <= epsilon && fabs(d2 - d1) > epsilon) || ( fabs(d3 - d1) <= epsilon && fabs(d3 - d2) > epsilon)){
			printf("Jednakokraki\n");
		} 
		if( fabs(d1 - d2) > epsilon && fabs(d2 - d3) > epsilon && fabs(d3 - d1) > epsilon){
			printf("Raznostranicni\n");
		}
	}
	
	ugao_d1d2 = acos((d1*d1+d2*d2-d3*d3)/(2*d1*d2));
	ugao_d1d3 = acos((d1*d1+d3*d3-d2*d2)/(2*d1*d3));
	ugao_d2d3 = acos((d2*d2+d3*d3-d1*d1)/(2*d2*d3));
	
	max_ugao = ugao_d1d2;
	if (ugao_d1d3 > max_ugao) 
		max_ugao = ugao_d1d3;
	if (ugao_d2d3 > max_ugao)
		max_ugao = ugao_d2d3;

	max_ugao_step = (max_ugao * 180) / PI;
	max_ugao_min = (max_ugao_step - (int) max_ugao_step) * 60;
	max_ugao_sec = (max_ugao_min - (int) max_ugao_min) * 60;
	
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n", (int) max_ugao_step, (int) max_ugao_min, (int) max_ugao_sec);
	
	
	return 0;
	
	
}

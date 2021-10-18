#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14
#define EPSILON 0.0001

int main() {
	double x1, x2, x3, y1, y2, y3, k1, k2, k3, a, b, c, ugao1, ugao2, ugao3, alfa, beta, gama, radalfa, radbeta, radgama, najugao;
	double min=0, minuta=0, sek=0, sekunda=0, stnajugao=0;
	int m, s, d;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	k1 = (y2-y1)/(x2-x1);
	k2 = (y3-y2)/(x3-x2);
	k3 = (y1-y3)/(x1-x3);
	
	if(k1 == k2 && k2 == k3) 
		printf("Linija\n");
		
	else {
		a = sqrt((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
		b = sqrt((x2-x3) * (x2-x3) + (y2-y3) * (y2-y3));
		c = sqrt((x3-x1) * (x3-x1) + (y3-y1) * (y3-y1)); 
		
		if(k1 == 1/k2 || k2 == 1/k3 || k3 == 1/k1) {
			printf("Pravougli\n");
			if((a==b && b!=c) || (b==c && c!=a) || (c==a && a!=b)) {
				printf("Jednakokraki\n");
			}
		}
			
		else if((a-b)<EPSILON && (b-c)<EPSILON && (c-a)<EPSILON) {
			printf("Jednakostranicni\n");
		}
			
		else if((a-b)>EPSILON || (b-c)>EPSILON || (c-a)>EPSILON) {
				printf("Raznostranicni\n");
		}
			ugao1 = (pow(a,2) + pow(b,2) - pow(c,2)) / (2*a*b);
			ugao2 = (pow(b,2) + pow(c,2) - pow(a,2)) / (2*b*c);
			ugao3 = (pow(a,2) + pow(c,2) - pow(b,2)) / (2*a*c);
	
			radalfa = acos(ugao1);
			radbeta = acos(ugao2);
			radgama = acos(ugao3);
	
			alfa = (radalfa*180)/PI;
			beta = (radbeta*180)/PI;
			gama = (radgama*180)/PI;
	
			if(alfa>beta && alfa>gama)
				najugao = alfa;
			else if(beta>alfa && beta>gama)
				najugao = beta;
			else
				najugao = gama;
				
			stnajugao = (int)najugao;
			if(stnajugao<90) {
				min = (najugao - stnajugao)*60;
				minuta = (int)min;
				sek = (min - minuta)*60;
				sekunda = (int)sek;
			}
			
			printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.", stnajugao, minuta, sekunda);
	
	}
	return 0;
}
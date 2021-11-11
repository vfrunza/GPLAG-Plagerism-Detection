#include <stdio.h>
#include <math.h>

#define epsilon 0.0001
#define PI 3.14159265

int main() {
	/*koord tacaka*/
	double x1, y1, x2, y2, x3, y3;
	
	/*Unos*/
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	double a = 0, b = 0, c = 0;
	
	/*stranice trougla*/
	a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
	c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
	
	double hip, k1, k2, alpha;
	
	/**/
	if (a > b && a > c){
		hip = a;
		k1 = b;
		k2 = c;
	} 
	else if (b > a && b > c){
		hip = b;
		k1 = a;
		k2 = c;
	} 
	else if (c > b && c > a){
		hip = c;
		k1 = b;
		k2 = a;
	} 
	
	alpha = acos( (k1*k1 + k2*k2 - hip*hip) / (2*k1*k2) );
	alpha *= (180/PI);
	
	alpha = fabs(alpha);
	double maxAng = alpha;
	
	
	int deg = floor(alpha);
	alpha -= deg;
	alpha *= 60;
	int min = floor(alpha);
	alpha -= min;
	alpha *= 60;
	int sec = floor(alpha);
	
	alpha = maxAng;
	
	if(fabs(alpha - 180) <= epsilon){
		printf("Linija\n");
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n", deg, min, sec);
		return 0;
	}
	
	if(fabs(alpha - 90) <= epsilon){
		printf("Pravougli\n");
	}
	if(fabs(k1 - hip) <= epsilon || fabs(k2 - hip) <= epsilon){
		if(fabs(k1 - k2) <= epsilon){
			printf("Jednakostranicni\n");
		}else{
			printf("Jednakokraki\n");
		}
	}else{
		if(fabs(k1 - k2) <= epsilon){
			printf("Jednakokraki\n");
		}else{
			printf("Raznostranicni\n");
		}
	}
	
	
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n", deg, min, sec);
	
	return 0;
}

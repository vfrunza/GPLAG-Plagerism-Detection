#include <stdio.h>
#include <math.h>
#define PI 3.14159265
float max(float a, float b) {
	if(a>b)
	return a;
	else
	return b;
return round (n * 1000.0)/1000.0; 
}
int main () {
	int stepeni, minuta, sekundi;
	float x1, x2, x3, y1, y2, y3;
	printf("Unesite koordinate tacke t1: ");
	scanf("%f %f", &x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%f %f", &x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%f %f",&x3,&y3);
	
	float a = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
	float b = (x2-x3)*(x2-x3) + (y2-y3)*(y2-y3);
	float c = (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3);
	
	if(sqrt(a) + sqrt(b) == sqrt(c) || sqrt(a) + sqrt(c) == sqrt(b) || sqrt(b) + sqrt(c) == sqrt(a)) {
	printf("Linija\n");
	}
	if(a + b == c || a + c == b*b || b + c == a) {
	printf("Pravougli\n");
	}
	if(a == b && b == c) {
	printf("Jednakostranicni\n");
	}
	else if(a == b || b == c || a == c) {
	printf("Jednakokraki\n");
	}
	else {
	printf("Raznostranicni\n");
	}
	
	float ugao1 = acos((b + c - a)/(2*sqrt(b)*sqrt(c))) * 180.0 / PI;
	float ugao2 = acos((b + a - c)/(2*sqrt(b)*sqrt(a))) * 180.0 / PI;
	float ugao3 = acos((c + a - b)/(2*sqrt(c)*sqrt(a))) * 180.0 / PI;
	
	float max_ugao = max(ugao1,max(ugao2, ugao3));
	
	float stepeni = floor(max_ugao);
	float minuta = floor((max_ugao-stepeni)*60);
	float sekundi = floor((max_ugao-stepeni-minuta/60)*3600);
	printf("Naveci ugao trougla je %d stepeni, %d minuta, %d sekund");
}
return 0;
}


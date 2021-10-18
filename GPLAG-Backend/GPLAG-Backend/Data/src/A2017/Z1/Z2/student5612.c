#include <stdio.h>
#include <math.h>
#define epsilon 0.0001
#define PI 3.14159
int main() {
	double x1,y1,x2,y2,x3,y3;
	double stranica1,stranica2,stranica3;
	int stepen,minute,sekunde;
	double u1,u2,u3,max,t;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	stranica1 = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	stranica3 = sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	stranica2 = sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	
	if(fabs((stranica1*stranica1 + stranica2*stranica2) - stranica3*stranica3) < epsilon || fabs((stranica1*stranica1 + stranica3*stranica3) - stranica2*stranica2) < epsilon || fabs((stranica2*stranica2 + stranica3*stranica3) - stranica1*stranica1) < epsilon){
	printf("Pravougli\n");
	}
	if (x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2) == 0) printf("Linija\n");
	else if(fabs(stranica1-stranica2) < epsilon && fabs(stranica2 - stranica3) < epsilon){
	printf("Jednakostranicni\n");
	}
	else if(fabs(stranica1 - stranica2) > epsilon && fabs(stranica2 - stranica3) > epsilon){
	printf("Raznostranicni\n");
	}
	else if (fabs(stranica1 - stranica2) < epsilon || fabs(stranica1 - stranica3) < epsilon || fabs(stranica2 - stranica3) < epsilon) {
	printf("Jednakokraki\n");
	}
	
	// Dodati ugao//
	u1 = acos((-stranica1*stranica1+stranica2*stranica2 + stranica3*stranica3)/(2*stranica2*stranica3))*180/PI;
	u2 = acos((-stranica2*stranica2+stranica1*stranica1 + stranica3*stranica3)/(2*stranica1*stranica3))*180/PI;
	u3 = acos((-stranica3*stranica3+stranica2*stranica2 + stranica1*stranica1)/(2*stranica2*stranica1))*180/PI;
	max = u1;
	if (u2 > max && u2 > u3) max = u2;
	else if(u3 > max) max = u3;
	
	stepen = max;
	t = (max - stepen)*60;
	minute = t;
	sekunde = (t - minute)*60;
	
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen,minute,sekunde);
	return 0;
}

#include <stdio.h>
#include <math.h>
#define e 0.0001
#define Pi 3.14159

int main() {
	double t1x, t1y, t2x, t2y, t3x, t3y, s1=0, s2=0, s3=0, naj_ugao=0, L1=0, L2=0, L3=0, P=0;
	int st=0, min=0, sec=0;
	
	printf ("Unesite koordinate tacke t1: ");
	scanf ("%lf %lf", &t1x, &t1y);
	
	printf ("Unesite koordinate tacke t2: ");
	scanf ("%lf %lf", &t2x, &t2y);
	
	printf ("Unesite koordinate tacke t3: ");
	scanf ("%lf %lf", &t3x, &t3y);
	
	s1 = sqrt(pow(t2y-t1y, 2) + pow(t2x-t1x, 2));
	s2 = sqrt(pow(t3y-t2y, 2) + pow(t3x-t2x, 2));
	s3 = sqrt(pow(t3y-t1y, 2) + pow(t3x-t1x, 2));
	
	L1 = acos((pow(s2,2) + pow(s3,2) - pow(s1,2)) / (2*s2*s3)) * (180 / Pi);
	L2 = acos((pow(s1,2) + pow(s2,2) - pow(s3,2)) / (2*s1*s2)) * (180 / Pi);
	L3 = acos((pow(s1,2) + pow(s3,2) - pow(s2,2)) / (2*s1*s3)) * (180 / Pi);
	
	P = ((t2x-t1x)*(t2y+t1y) + (t3x-t2x)*(t3y+t2y) + (t1x-t3x)*(t1y+t3y) / 2);
	
	if (fabs(P-0)<e) {
		printf ("Linija\n");
	}
	if (fabs(s1-s2)<=e && fabs(s2-s3)<=e && fabs(s3-s1)<=e) {
		printf ("Jednakostranicni\n");
	}
	if ((fabs(L1-90)<e || fabs(L2-90)<e || fabs(L3-90)<e)) {
		printf ("Pravougli\n");
	}
	if ((fabs(s1-s2)<=e && fabs(s1-s3)>e) || (fabs(s2-s3)<=e && fabs(s3-s1)>e) || (fabs(s1-s3)<=e && fabs(s1-s2)>e)) {
		printf ("Jednakokraki\n");
	}
	if (fabs(s1-s2)>e && fabs(s2-s3)>e && fabs(s3-s1)>e) {
		printf ("Raznostranicni\n");
	}
	if (L1>L2 && L1>L3) {
		naj_ugao=L1;
	} else if (L2>L3 && L2>L1) {
		naj_ugao=L2;
	} else naj_ugao=L3;
	
	st = fabs(naj_ugao);
	min = fabs((naj_ugao-(int)(naj_ugao)) / 60);
	sec = fabs((int)naj_ugao / 3600);
	
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", st,min,sec);
	
	return 0;
}

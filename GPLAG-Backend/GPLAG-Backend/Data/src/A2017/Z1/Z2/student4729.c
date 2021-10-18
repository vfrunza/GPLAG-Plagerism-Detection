#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

int main()
{
	double a,b,c,x1,y1,x2,y2,x3,y3;
	int alfa,beta,gama,minut,sekunda;

	printf("Unesite koordinate tacke t1:");
	scanf ("%lf %lf", &x1, &y1);
	printf ("Unesite koordinate tacke t2:");
	scanf ("%lf %lf", &x2, &y2);
	printf ("Unesite koordinate tacke t3:");
	scanf ("%lf %lf", &x3, &y3);

	if (x1==x2 && x2==x3 && y1==y2 && y2==y3){
		printf ("Linija");
	}
	a=sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
	b=sqrt ((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));
	c=sqrt((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1));
	alfa=acos((b*b+c*c-a*a)/2);
	beta=acos((a*a+c*c-b*b)/2);
	gama=acos((a*a+b*b-c*c)/2);

	
	if ((c*c==a*a+b*b) && fabs((c-(a+b))<EPSILON)) {
		printf ("Pravougli\n");
		if (a==b) {
			printf ("Jednakokraki\n");
		}
		printf ("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.\n");
	}

	if ((a==b) || (b==c) || (a==c)) {
		printf ("Jednakokraki\n");

		if ((alfa==beta || alfa==gama) && (gama<90 || beta<90)) {
			minut=((int)alfa)%60;
			sekunda=((int)minut)%60;
			printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi", alfa,minut,sekunda);
		}
		else if (beta==gama && alfa<90) {
			minut=((int)beta)%60;
			sekunda=((int)minut)%60;
			printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi", beta,minut,sekunda);
		}
		if (alfa==beta && gama>90) {
			minut=((int)gama)%60;
			sekunda=((int)minut)%60;
			printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi", gama,minut,sekunda);
		}
		else if (alfa==gama && beta>90) {
			minut=((int)beta)%60;
			sekunda=((int)minut)%60;
			printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi", beta,minut,sekunda);
		}
		if (beta==gama && alfa>90) {
			minut=((int)alfa)%60;
			sekunda=((int)minut)%60;
			printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi", alfa,minut,sekunda);
		}
	}
	if (alfa==beta && beta==gama && a==b && b==c) {
		printf ("Jednakostranicni\n");
		printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi");
	}
	if (alfa!=beta && beta!=gama && alfa!=gama && a!=b && b!=c && a!=c) {
		printf("Raznostranicni");
		if (a==b)
		if (alfa>beta && alfa>gama) {
			minut=((int)alfa)%60;
			sekunda=((int)minut)%60;
			printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi", alfa,minut,sekunda);
		}
		if (beta>alfa && beta>gama) {
			minut=((int)beta)%60;
			sekunda=((int)minut)%60;
			printf("Najveci ugao ima %d stepeni, %d minuta i %d stepeni", beta,minut,sekunda);
		}

		if (gama>alfa && gama>beta) {
			minut=((int)gama)%60;
			sekunda=((int)minut)%60;
			printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi", gama,minut,sekunda);

		}
	}



return 0;
}

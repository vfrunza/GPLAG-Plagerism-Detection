#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.1415926
int main()
{

	double tx1, ty1, tx2, ty2, tx3, ty3,d12, d23, d31, sx1,sy1,sx2,sy2,sx3,sy3;

	printf ("Unesite koordinate tacke t1: ");

	scanf ("%lf %lf",  &tx1, &ty1);

	printf ("Unesite koordinate tacke t2: ");

	scanf ("%lf %lf", &tx2, &ty2);

	printf ("Unesite koordinate tacke t3: ");
	scanf ("%lf %lf", &tx3, &ty3);
	sx1=tx1-tx2;
	sy1=ty1-ty2;
	sx2=tx3-tx2;
	sy2=ty3-ty2;
	sx3=tx1-tx3;
	sy3=ty1-ty3;
	d12=sqrt(pow (sx1, 2) +   pow(sy1, 2));

	d23=sqrt(pow(sx2,2) + pow(sy2,2));
	d31=sqrt(pow(sx3, 2) + pow(sy3, 2));

	/* hipotenuza i katete*/
	double h, k, kk, alfica;
	if (d12 > d23 && d12 > d31 ) {
		h=d12;
		k=d23;
		kk=d31;
	} else if (d23 > d12 && d23 > d31) {
		h=d23;
		k=d12;
		kk=d31;
	} else if (d31 > d12 && d31 > d23) {
		h=d31;
		k=d23;
		kk=d12;

	}

	double a;
	a=h;


	alfica=acos ( (k*k+kk*kk - h*h) / (2*k*kk)  );

	/* Funkcija acos daje rezultat u radijanima, pretvaranje u stepene */

	alfica*= (180/PI);


	double nU = alfica  ;

	int st =  alfica ;
	alfica -= st;
	alfica *= 60;

	int min =  alfica;
	alfica-= min;
	alfica*=60 ;

	int sec =  alfica;
	alfica-= sec;
	alfica*=60 ;



	if (fabs(kk+k-h)<=EPSILON || fabs(k+h-kk)<=EPSILON || fabs(kk+h-k)<=EPSILON ) {
		printf ("Linija\n");
		printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n ", st, min, sec);
		return 0;
	}


	if	(fabs (h- (sqrt(pow(k, 2 ) +(pow (kk,2)))))<= EPSILON) {
		printf ("Pravougli\n");
	}







	if(fabs (k-h)<=EPSILON || fabs(kk-h)<=EPSILON) {

		if (fabs (k-kk)<=EPSILON) {
			printf ("Jednakostranicni\n");
		}

		else {
			printf ("Jednakokraki\n");

		}
	} else {
		if (fabs (k-kk)<=EPSILON) {

			printf ("Jednakokraki\n");
		} else {
			printf ("Raznostranicni\n");
		}
	}
	printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n ", st, min, sec);

	return 0;

}

#include <stdio.h>
#include <math.h>
#define PI 3.14159
#define EP 0.0001
int main()
{
	double x1,x2,x3,y1,y2,y3,t12,t23,t13,a,b,c,da,ma,sa,db,mb,sb,dc,mc,sc;
	printf ("Unesite koordinate tacke t1: ");
	scanf ("%lf %lf", &x1, &y1);
	printf ("Unesite koordinate tacke t2: ");
	scanf ("%lf %lf", &x2, &y2);
	printf ("Unesite koordinate tacke t3: ");
	scanf ("%lf %lf", &x3, &y3);

	t12 = sqrt ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	t23 = sqrt ((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));
	t13 = sqrt ((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));

	a = (acos ((t12*t12+t23*t23-t13*t13)/(2*t12*t23)))*(180/PI);
	b = (acos ((t12*t12+t13*t13-t23*t23)/(2*t12*t13)))*(180/PI);
	c = 180 - a-b;

	da = (int) a;
	ma = (int) ((a-da)*60);
	sa = (int) (((a-da)*60-ma)*60);

	db = (int) b;
	mb = (int) ((b-db)*60);
	sb = (int) (((b-db)*60-mb)*60);

	dc = (int) c;
	mc = (int) ((c-dc)*60);
	sc = (int) (((c-dc)*60-mc)*60);

	if (fabs(da - 180)<EP || fabs(db - 180)<EP || fabs(dc - 180)<EP) {
		printf ("Linija\n");
		printf ("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
		return 1;
	}

	if ((fabs (t13 - t23) < EP) && (fabs (t13 - t12) < EP) && (fabs (t12 - t23) < EP) ) {
		printf ("Jednakostranicni\n");
		printf ("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
		return 1;
	}

	if (fabs(t12 - sqrt (t23*t23 + t13*t13))<EP || fabs(t23 - sqrt (t12*t12 + t13*t13))<EP || fabs(t13 - sqrt (t23*t23 + t12*t12))<EP) {
		printf ("Pravougli\n");
		if ((fabs (t13 - t23) < EP) || (fabs (t13 - t12) < EP) || (fabs (t12 - t23) < EP))
			printf ("Jednakokraki\n");
		else
			printf ("Raznostranicni\n");
		if (a>=b && a>=c)
			printf ("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.\n",da,ma,sa);
		else if (b>=a && b>=c)
			printf ("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.\n",db,mb,sb);
		else if (c >=a && c>=b)
			printf ("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.\n",dc,mc,sc);
		return 1;
	}

	else if ((fabs (t13 - t23) < EP) || (fabs (t13 - t12) < EP) || (fabs (t12 - t23) < EP)) {
		printf ("Jednakokraki\n");
		if (a>=b && a>=c)
			printf ("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.\n",da,ma,sa);
		else if (b>=a && b>=c)
			printf ("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.\n",db,mb,sb);
		else if (c >=a && c>=b)
			printf ("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.\n",dc,mc,sc);
	}

	else {
		printf ("Raznostranicni\n");
		if (a>=b && a>=c)
			printf ("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.\n",da,ma,sa);
		else if (b>=a && b>=c)
			printf ("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.\n",db,mb,sb);
		else if (c >=a && c>=b)
			printf ("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.\n",dc,mc,sc);
	}
	return 0;
}
#include <stdio.h>
#include <math.h>
#define e 0.0001

int main()
{

	double t1_X, t1_Y, t2_X, t2_Y, t3_X, t3_Y, a, b, c,alpha,beta,gamma,najveci_ugao;
	int stepeni = 0, minute = 0, sekunde = 0, ispisao = 0;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &t1_X, &t1_Y);

	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &t2_X, &t2_Y);

	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &t3_X, &t3_Y);

	a = sqrt ((t1_X-t2_X)*(t1_X-t2_X) + (t1_Y-t2_Y)*(t1_Y-t2_Y));
	b = sqrt ((t1_X-t3_X)*(t1_X-t3_X) + (t1_Y-t3_Y)*(t1_Y-t3_Y));
	c = sqrt ((t3_X-t2_X)*(t3_X-t2_X) + (t3_Y-t2_Y)*(t3_Y-t2_Y));


	if ((fabs(a + b - c) < e || fabs(a + c - b) < e || fabs( b + c - a) < e)) {
		printf("Linija\n");
		stepeni = 180;
	} else {
		if (fabs(a - b) < e && fabs(a - c) < e ) {
			printf("Jednakostranicni\n");
			ispisao = 1;
			stepeni = 60;
		}

		if (fabs(a*a + b*b - c*c) < e || fabs(a*a + c*c - b*b) < e ||
		        fabs(b*b + c*c - a*a) < e)  {
			printf("Pravougli\n");
			stepeni = 90;
		}
		if ((fabs(a - b) < e && fabs(a - c) > e) ||
		(fabs(c - b) < e && fabs(a - b) > e) || 
		(fabs(a - c) < e && fabs(a - b) > e)) {
			printf("Jednakokraki\n");
			ispisao = 1;
			alpha = acos((b*b+c*c-a*a)/(2*b*c));
			beta = acos((a*a+c*c-b*b)/(2*a*c));
			gamma = acos((b*b+a*a-c*c)/(2*a*b));
			najveci_ugao=alpha;
			if(beta>najveci_ugao)najveci_ugao=beta;
			if(gamma>najveci_ugao)najveci_ugao=gamma;
			najveci_ugao = 180*najveci_ugao/(atan(1)*4);
			stepeni = najveci_ugao;
			minute = (najveci_ugao - stepeni)*60;
			sekunde = ((najveci_ugao - stepeni)*60 - minute)*60;
		}
		if (ispisao == 0) {
			printf("Raznostranicni\n");
			alpha = acos((b*b+c*c-a*a)/(2*b*c));
			beta = acos((a*a+c*c-b*b)/(2*a*c));
			gamma = acos((b*b+a*a-c*c)/(2*a*b));
			najveci_ugao=alpha;
			if(beta>najveci_ugao)najveci_ugao=beta;
			if(gamma>najveci_ugao)najveci_ugao=gamma;
			najveci_ugao = 180*najveci_ugao/(atan(1)*4);
			stepeni = najveci_ugao;
			minute = (najveci_ugao - stepeni)*60;
			sekunde = ((najveci_ugao - stepeni)*60 - minute)*60;
		}
	}


	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);








	return 0;
}

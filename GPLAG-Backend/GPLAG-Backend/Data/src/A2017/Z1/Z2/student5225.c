#include <stdio.h>
#include <math.h>
#define praviugao 90
#define nemaugla 0
#define PI 3.14159265
#define EPSILON 0.0001

int main() {
	double x1, y1, x2, y2, x3, y3, d12, d13, d23, alfa, beta, gama, minutanajveci, sekundanajveci;
	double kos_alfa, kos_beta, kos_gama, najveci, P;
	int stepen_najveci, minuta_najveci, sekunda_najveci, stepen_alfa, stepen_beta, stepen_gama;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	d12 = sqrt((pow(x2-x1,2) + pow(y2-y1,2)));
	d13 = sqrt((pow(x3-x1,2) + pow(y3-y1,2)));
	d23 = sqrt((pow(x3-x2,2) + pow(y3-y2,2)));
	
	kos_alfa = (d13*d13 + d12*d12 - d23*d23)/(2*d12*d13);
	kos_beta = (d23*d23 + d12*d12 - d13*d13)/(2*d12*d23);
	kos_gama = (d13*d13 + d23*d23 - d12*d12)/(2*d13*d23);
	alfa = acos(kos_alfa)*180./PI;
	beta = acos(kos_beta)*180./PI;
	gama = acos(kos_gama)*180./PI;

	if ((alfa-beta) >= 0 && fabs(alfa-beta) > EPSILON && (alfa - gama) >= 0 && fabs(alfa - gama) > EPSILON)
	{
		najveci = alfa;
	}
	else if (beta - alfa > 0 && fabs(beta - alfa) > EPSILON && beta - gama > 0 && fabs(beta - gama) > EPSILON)
	{
		najveci = beta;
	}
	else  {
		najveci = gama;
	}
	
	
	stepen_najveci = (int)najveci;
	minutanajveci = (najveci - stepen_najveci)*60;
	minuta_najveci = (int)minutanajveci;
	sekundanajveci = (minutanajveci - minuta_najveci)*60;
	sekunda_najveci = (int)sekundanajveci;
	
	
	
	stepen_alfa = (int)alfa;
	
	stepen_beta = (int)beta;

	stepen_gama = (int)gama;
	
	
	P = (1./2) * fabs( x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));

	 if (P == 0) {
			printf("Linija\n");
			printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	 }
 	
 	else if((fabs(d12-d13) < EPSILON) && (fabs(d12-d23) < EPSILON)) 
	{
		printf("Jednakostranicni\n");
		printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
	}
	else if((fabs(d13-d23) < EPSILON && fabs(d13-d12) > EPSILON) || (fabs(d12-d13) < EPSILON && fabs(d12=d23) > EPSILON) || (fabs(d12-d23) < EPSILON && fabs(d12-d13) > EPSILON)) 
	{
		if(stepen_alfa == praviugao || stepen_beta == praviugao || stepen_gama == praviugao) {
			printf("Pravougli\n"); }
			printf("Jednakokraki\n"); 
			
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen_najveci, minuta_najveci, sekunda_najveci);
	}

	
		else if(fabs(d12-d13) > EPSILON && fabs(d12-d23) > EPSILON && fabs(d13-d23) > EPSILON) {
		
			if(stepen_alfa == praviugao || stepen_beta == praviugao || stepen_gama == praviugao) {
			printf("Pravougli\n"); }
			
			printf("Raznostranicni\n"); 
			
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen_najveci, minuta_najveci, sekunda_najveci);
		}
	
		
		
	return 0;
}

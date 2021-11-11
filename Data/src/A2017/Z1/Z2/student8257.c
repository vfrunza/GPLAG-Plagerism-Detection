#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159

int main() {
	double E = 0.0001;
	double x1,y1;	// Tacka A
	double x2,y2;	// Tacka B
	double x3,y3;	// Tacka C
	double alfa,beta,gama; // Uglovi 
	double a,b,c; // Stranice
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	c = sqrt(pow(x1-x2,2)+pow(y1-y2,2)); // stranica AB
	a = sqrt(pow(x2-x3,2)+pow(y2-y3,2)); // stranica BC
	b = sqrt(pow(x3-x1,2)+pow(y3-y1,2)); // stranica CA
	
	alfa = acos((b*b+c*c-a*a) / (2*b*c)) * (180/PI);
	
	beta = acos((a*a+c*c-b*b) / (2*a*c)) * (180/PI);
	
	gama = acos((a*a+b*b-c*c) / (2*a*b)) * (180/PI);
	
	double stepeni,minute;
	
	// Alfa  -  Stepeni,minute,sekunde
	
    double DecMinute = modf(alfa, &stepeni);// // Cijeli dio ide u &stepeni a decimalni ide u DecMinute 
    DecMinute*=60.; 
	double DecSekunde = modf(DecMinute,&minute); // 
	DecSekunde*=60.;
	
	int Lstepeni = stepeni;
	int Lminute = minute;
	int Lsekunde = DecSekunde;
	
	// Beta   -||-

    DecMinute = modf(beta, &stepeni);
    DecMinute*=60.; 
	DecSekunde = modf(DecMinute,&minute);
	DecSekunde*=60.;
	
	int Bstepeni = stepeni;
	int Bminute = minute;
	int Bsekunde = DecSekunde;
	
	// Gama -||-
	
	DecMinute = modf(gama, &stepeni); 
    DecMinute*=60.; 
	DecSekunde = modf(DecMinute,&minute);
	DecSekunde*=60.;

	int Gstepeni = stepeni;
	int Gminute = minute;
	int Gsekunde = DecSekunde;

		if ( fabs(alfa)<E || fabs(beta) < E || fabs(gama) < E ) {
			printf("Linija\n");
		}
		else if (fabs(alfa-60)<E && fabs(beta-60)<E && fabs(gama-60)<E) {
			printf("Jednakostranicni\n");
		}
		else if ( fabs(alfa-90)<E || fabs(beta-90)<E || fabs(gama-90)<E) {
			printf("Pravougli\n");
			if(fabs(45-alfa) < E || fabs(45-beta) <E || fabs(45-gama) < E) 
				printf("Jednakokraki\n");
			else 
				printf("Raznostranicni\n");
		}
		else if (fabs(a-b)>E && fabs(b-c)>E && fabs(a-c)>E) {
			printf("Raznostranicni\n");
		}
		else {
			printf("Jednakokraki\n");
		}
		if(alfa>beta && alfa>gama) 
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n",Lstepeni,Lminute,Lsekunde);
		else if(beta>alfa && beta>gama)
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n",Bstepeni,Bminute,Bsekunde);
		else 
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n",Gstepeni,Gminute,Gsekunde);
	
	return 0;
}

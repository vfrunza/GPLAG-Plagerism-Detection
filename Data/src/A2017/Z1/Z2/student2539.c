#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846643383279502884197169399375
#define e 0.0001
int main()
{
	double x1,x2,x3,y1,y2,y3;
	double a,b,c,P;
	double alfa,beta,gama;
	double alfastepeni,alfaminuta,alfasekundi,betastepeni,betaminuta,betasekundi,gamastepeni,gamaminuta,gamasekundi;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	a = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	b = sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	c = sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	P=0.5*fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
	alfa = acos ((b*b+c*c-a*a)/(2*c*b));
	beta = acos ((a*a+c*c-b*b)/(2*a*c));
	gama = acos ((a*a+b*b-c*c)/(2*a*b));
	alfa = (180/PI)*alfa;
	beta = (180/PI)*beta;
	gama = (180/PI)*gama;
	alfastepeni = (int) alfa;
	betastepeni = (int) beta;
	gamastepeni = (int) gama;
	alfaminuta = (alfa - alfastepeni) * 60;
	betaminuta = (beta - betastepeni) * 60;
	gamaminuta = (gama - gamastepeni) * 60;
	alfasekundi = (alfaminuta - (int)alfaminuta) * 60;
	betasekundi = (betaminuta - (int)betaminuta) * 60;
	gamasekundi = (gamaminuta - (int)gamaminuta) * 60;
	alfaminuta = (int)alfaminuta;
	betaminuta = (int)betaminuta;
	gamaminuta = (int)gamaminuta;
	alfasekundi = (int)alfasekundi;
	betasekundi = (int)betasekundi;
	gamasekundi = (int)gamasekundi;
	if (fabs(alfastepeni-90)<e || fabs(betastepeni-90)<e || fabs(gamastepeni-90)<e) {
		printf ("Pravougli\n");
		if(fabs(a-b)<e || fabs(a-c)<e || fabs(c-b)<e) printf("Jednakokraki\n");
		if(fabs(a-b)>e && fabs(a-c)>e && fabs(c-b)>e) printf("Raznostranicni\n");
		printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
	} else if (fabs(P-0)<e) {
		printf("Linija\n");
		printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	} else if (fabs(a-b)<e && fabs(a-c)<e && fabs(c-b)<e) {
		printf("Jednakostranicni\n");
		printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
	} else if (fabs(a-b)<e || fabs(a-c)<e || fabs(c-b)<e) {
		printf("Jednakokraki\n");
		if (alfa>=beta && alfa>=gama) printf("Najveci ugao ima %.lf stepeni, %.lf minuta i %.lf sekundi.",alfastepeni,alfaminuta,alfasekundi);
		else if (beta>=alfa && beta>=gama) printf("Najveci ugao ima %.lf stepeni, %.lf minuta i %.lf sekundi.",betastepeni,betaminuta,betasekundi);
		else if (gama>=beta && gama>=alfa) printf("Najveci ugao ima %.lf stepeni, %.lf minuta i %.lf sekundi.",gamastepeni,gamaminuta,gamasekundi);
	} else if (fabs(a-b)>e && fabs(a-c)>e && fabs(c-b)>e) {
		printf("Raznostranicni\n");
		if (alfa>beta && alfa>gama) printf("Najveci ugao ima %.lf stepeni, %.lf minuta i %.lf sekundi.",alfastepeni,alfaminuta,alfasekundi);
		if (beta>alfa && beta>gama) printf("Najveci ugao ima %.lf stepeni, %.lf minuta i %.lf sekundi.",betastepeni,betaminuta,betasekundi);
		if (gama>beta && gama>alfa) printf("Najveci ugao ima %.lf stepeni, %.lf minuta i %.lf sekundi.",gamastepeni,gamaminuta,gamasekundi);
	}
	return 0;
}
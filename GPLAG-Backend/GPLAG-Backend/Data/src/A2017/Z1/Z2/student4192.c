#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.141592
int main()
{
	double stepen1=0, minut1=0, sekund1=0, stepen2=0, minut2=0, sekund2=0, stepen3=0, minut3=0, sekund3=0;
	double t1x, t1y, t2x, t2y, t3x, t3y, d12=0, d13=0, d23=0, alfa=0, beta=0, gama=0;

	/*Ulaz programa*/
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &t1x, &t1y);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &t2x, &t2y);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &t3x, &t3y);

	/*Primjenom analiticke geometrije pronalazimo sljedece podatke*/
	/*Duzine stranica d12, d13 i d23*/
	d12=sqrt(((t2x-t1x)*(t2x-t1x))+((t2y-t1y)*(t2y-t1y)));
	d13=sqrt(((t3x-t1x)*(t3x-t1x))+((t3y-t1y)*(t3y-t1y)));
	d23=sqrt(((t3x-t2x)*(t3x-t2x))+((t3y-t2y)*(t3y-t2y)));

	/*Primjenom kosinusne teoreme ponalazimo uglove alfa, beta i gama*/
	alfa=acos((d13*d13+d23*d23-d12*d12)/(2*d13*d23))*((180.)/PI);
	beta=acos((d12*d12+d23*d23-d13*d13)/(2*d12*d23))*((180.)/PI);
	gama=acos((d12*d12+d13*d13-d23*d23)/(2*d12*d13))*((180.)/PI);

	/*Ovdje racunamo uglove izrazene u stepenima, minutama i sekundama*/
	stepen1=(int)alfa;
	alfa-=stepen1;
	alfa*=60;
	minut1=(int)alfa;
	alfa-=minut1;
	alfa*=60;
	sekund1=(int)alfa;

	stepen2=(int)beta;
	beta-=stepen2;
	beta*=60;
	minut2=(int)beta;
	beta-=minut2;
	beta*=60;
	sekund2=(int)beta;

	stepen3=(int)gama;
	gama-=stepen3;
	gama*=60;
	minut3=(int)gama;
	gama-=minut3;
	gama*=60;
	sekund3=(int)gama;

	/*Akoje bar jedan ugao jednak 90 stepeni onda je trougao pravougli*/
	if((fabs(alfa-90)<EPSILON)||(fabs(beta-90)<EPSILON)||(fabs(gama-90)<EPSILON)) {
		printf("Pravougli\n");
	}
	/*Ako su sve stranice jednake duzine tada je trougao jedakostranicni*/
	if((fabs(d12-d13)<EPSILON)&&(fabs(d13-d23)<EPSILON)&&(fabs(d23-d12)<EPSILON)&&(fabs(alfa-beta)<EPSILON)&& (fabs(beta-gama)<EPSILON)&&(fabs(alfa-gama)<EPSILON)) {
		printf("Jednakostranicni");
	}
	/*Ako su dvije stranice jednake tada je trougao jednakokraki*/
	else if(((fabs(d12-d13)<EPSILON)&&(fabs(d13-d23)<EPSILON)&&(fabs(d23-d12)>EPSILON))||((fabs(d12-d13)<EPSILON)&&(fabs(d13-d23)>EPSILON)&&(fabs(d23-d12)<EPSILON))||((fabs(d12-d13)>EPSILON)&&(fabs(d13-d23)<EPSILON)&&(fabs(d23-d12)<EPSILON)&&((fabs(alfa-beta)<EPSILON)||(fabs(beta-gama)<EPSILON)||(fabs(alfa-gama)<EPSILON)))) {
		printf("Jednakokraki");
	}
	/*Ako su sve stranice razlicite onda je trougao raznostranicni*/
	else if((fabs(d12-d13)>EPSILON)&&(fabs(d13-d23)>EPSILON)&&(fabs(d23-d12)>EPSILON)&&(fabs(alfa-beta)>EPSILON)&&(fabs(beta-gama)>EPSILON)) {
		printf("Raznostranicni");
	}
	/*Ako je bar jedan ugao 180 stepeni onda je to linija a ne trougao*/
	else if((t1x*(t2y-t3y)+t2x*(t3y-t1y)+t3x*(t1y-t2y))==0){
		printf("Linija");
	}
	
	/*Poredenjem uglova naci cemo najveci ugao trougla*/
	if(alfa>beta&&alfa>gama) {
		printf("\nNajveci ugao ima %.f stepeni, %.f minuta i %.f sekundi.", stepen1, minut1, sekund1);
	} else if(alfa<beta&&beta<gama) {
		printf("\nNajveci ugao ima %.f stepeni, %.f minuta i %.f sekundi.", stepen3, minut3, sekund3);
	} else if(alfa<beta&&beta>gama) {
		printf("\nNajveci ugao ima %.f stepeni, %.f minuta i %.f sekundi.", stepen2, minut2, sekund2);
	}

	return 0;
}
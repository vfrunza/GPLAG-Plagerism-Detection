#include <stdio.h>
#include <math.h>
#define PI 3.1415926535
#define epsilon 0.0001
int main()
{
	double x1,x2,x3,y1,y2,y3,D1,D2,D3,alfa,beta,gama,najveciugao;
	int stepennajveciugao,minnajveciugao,secnajveciugao;

	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3,&y3);

	/*udaljenost tacaka=duzine stranica*/
	D1=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
	D2=sqrt(pow(x1-x3,2)+pow(y1-y3,2));
	D3=sqrt(pow(x2-x3,2)+pow(y2-y3,2));

	/*racunanje uglova*/
	alfa=(acos((pow(D2,2)+pow(D3,2)-pow(D1,2))/(2*D2*D3)))*(180/PI);
	beta=(acos((pow(D1,2)+pow(D3,2)-pow(D2,2))/(2*D1*D3)))*(180/PI);
	gama=(acos((pow(D1,2)+pow(D2,2)-pow(D3,2))/(2*D1*D2)))*(180/PI);/*pretvaranje u stepene radi definisanja trouglova*/

	/*uslovi za najveci ugao*/
	if(alfa>beta && alfa>gama)
		najveciugao=alfa;
	else if(beta>alfa && beta>gama)
		najveciugao=beta;
	else if(gama>alfa && gama>beta)
		najveciugao=gama;

	if (fabs(alfa-90)<epsilon || fabs(beta-90)<epsilon || fabs(gama-90)<epsilon)
		printf("Pravougli\n");
		
	/*poredenje stranica trougla*/
	if(fabs(najveciugao-180)<epsilon)
		printf("Linija");
	else if(fabs(D1-D2)<epsilon && fabs(D2-D3)<epsilon)
		printf("Jednakostranicni");
	else if((fabs(D1-D2)<epsilon && fabs(D2-D3)>epsilon) || (fabs(D1-D3)<epsilon && fabs(D3-D2)>epsilon) || (fabs(D2-D3)<epsilon && fabs(D3-D1)>epsilon))
		printf("Jednakokraki");
	else
		printf("Raznostranicni");


	/*pretvaranje iz radijana u stepene*/
	stepennajveciugao=(int)najveciugao;
	minnajveciugao=(najveciugao-(int)stepennajveciugao)*60;
	minnajveciugao=(int)minnajveciugao;
	secnajveciugao=((najveciugao-(int)stepennajveciugao)*60-minnajveciugao)*60;
	printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepennajveciugao,minnajveciugao,secnajveciugao);

	return 0;
}
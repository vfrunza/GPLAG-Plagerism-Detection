#include <stdio.h>
#include <math.h>

#define pi 4*atan(1)
#define e 0.0001

int main()
{
	double xa, ya, xb, yb, xc, yc, d_ab, d_ac, d_bc, alfa, beta, gama, a, b, c, deg;
	
	printf ("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &xa, &ya);
	printf ("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &xb, &yb);
	printf ("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &xc, &yc);
	
	d_ab=sqrt(pow(xb-xa, 2) + pow(yb-ya, 2));
	d_ac=sqrt(pow(xc-xa, 2) + pow(yc-ya, 2));
	d_bc=sqrt( pow(xc-xb, 2) + pow(yc-yb, 2));
	
	a=d_bc;
	b=d_ac;
	c=d_ab;
	
	
	deg=180/pi;
	
	alfa=deg* acos( (b*b + c*c - a*a)/(2*b*c) );
	
	beta=deg* acos((a*a + c*c - b*b)/(2*a*c) );
	
	gama=deg* acos((a*a + b*b - c*c)/(2*a*b));
	
	
	
	if( alfa==0 ||  beta==0 || gama==0 )
	{
	printf("Linija\n");
	}
	
	if( (alfa==90 || beta==90 || gama==90) || (alfa+beta==90 || alfa+gama==90  || beta+gama==90) )
	{
		printf("Pravougli\n");
	}
	
	if ( ( ( fabs(alfa-beta)<e && fabs(alfa-gama)>e ) || ( fabs(alfa-gama)<e && fabs(alfa-beta)>e ) || (fabs(beta-gama)<e && fabs(beta-alfa)>e) ) && alfa!=0 && beta!=0 && gama!=0 )
	{
	printf ("Jednakokraki\n");
	}
	
	if( fabs(alfa-beta)<e && fabs(alfa-gama)<e  )
	{
		printf("Jednakostranicni\n");
	}
	
	if( fabs(alfa-beta)>e && fabs(beta-gama)>e && fabs(alfa-gama)>e)
	{
		printf("Raznostranicni\n");
	}
	
	double alfa_minuta, ostatak1_alfa, ostatak2_alfa, alfa_sekundi;
	
	ostatak1_alfa=alfa - (int)alfa;
	alfa_minuta= 60 *ostatak1_alfa;
	
	ostatak2_alfa= alfa_minuta - (int)alfa_minuta;
	alfa_sekundi=60 *ostatak2_alfa;
	
	
	double beta_minuta, ostatak1_beta, ostatak2_beta, beta_sekundi;
	
	ostatak1_beta=beta - (int)beta;
	beta_minuta= 60 *ostatak1_beta;
	
	ostatak2_beta= beta_minuta - (int)beta_minuta;
	beta_sekundi=60 *ostatak2_beta;
	
	
	double gama_minuta, ostatak1_gama, ostatak2_gama, gama_sekundi;
	
	ostatak1_gama=gama - (int)gama;
	gama_minuta= 60 *ostatak1_gama;
	
	ostatak2_gama= gama_minuta - (int)gama_minuta;
	gama_sekundi=60 *ostatak2_gama;
	
	
	if(alfa>beta && alfa>gama)
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", (int)alfa, (int)alfa_minuta, (int)alfa_sekundi);
	else if(beta>alfa && beta>gama)
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", (int)beta, (int)beta_minuta, (int)beta_sekundi);
	else if(gama>alfa && gama>beta)
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", (int)gama, (int)gama_minuta, (int)gama_sekundi);
	else if(alfa==beta && alfa==gama )
	printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");

	return 0;
}

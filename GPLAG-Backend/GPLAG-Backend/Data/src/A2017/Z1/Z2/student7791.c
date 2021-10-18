#include <stdio.h>
#include <math.h>
#define epsilon 0.0001
#define PI 3.1415926

int main() {
	int sekunda1,sekunda2,sekunda3,stepen1,stepen2,stepen3,alfa_sekunde,beta_sekunde,gama_sekunde;
	double x1,x2,x3,y1,y2,y3,d12,d13,d23,alfa,beta,gama,minuta1,minuta2,minuta3,P;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	d12 = sqrt(((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)));
	d13 = sqrt(((x3-x1)*(x3-x1)) + ((y3-y1)*(y3-y1)));
	d23 = sqrt(((x3-x2)*(x3-x2)) + ((y3-y2)*(y3-y2)));
	
	P = (fabs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))) / 2);
	
	alfa = acos((d13*d13 - d12*d12 + d23*d23) / (2 * d23 * d13));
	beta = acos((d12*d12 - d23*d23 + d13*d13) / (2 * d12 * d13));
	gama = acos((d23*d23 - d13*d13 + d12*d12) / (2 * d12 * d23));
	
	alfa = (alfa*(180. / PI));
	stepen1 =((int)alfa);
	minuta1 =((alfa - stepen1)*60);
	sekunda1 = ((int)minuta1);
	alfa_sekunde = ((minuta1 - sekunda1)*60);
	
	
	beta = (beta*(180. / PI));
	stepen2 = ((int) beta);
	minuta2 =((beta - stepen2)*60);
	sekunda2 = ((int) minuta2);
	beta_sekunde = ((minuta2 - sekunda2)*60);
	
	gama = (gama*(180. / PI));
	stepen3 = ((int) gama);
	minuta3 = ((gama - stepen3)*60);
	sekunda3 = ((int) minuta3);
	gama_sekunde = (((minuta3 - sekunda3)*60));
	
	 if(P < epsilon)   
	{
		printf("Linija");
		printf("\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
		return 0;
	}
	
	
	
	if((fabs(d12-d23)<epsilon) && (fabs(d23-d13)<epsilon))
	{
		printf("Jednakostranicni");
	}
	else if((sqrt(d12 * d12 + d13*d13)) == d23 || (sqrt(d12*d12 + d23*d23)) == d13 || (sqrt(d13*d13 + d23*d23))==d12) 
	{
			printf("Pravougli");
		
		if((fabs(d12-d23)<epsilon) || (fabs(d12-d13)<epsilon) || (fabs(d23-d13)<epsilon))
		{
			printf("\nJednakokraki");
		}
		else if((fabs(d12-d23)>epsilon) && (fabs(d23-d13)>epsilon))
		{
			printf("\nRaznostranicni");
		}
	}
	else if((fabs(d12-d23)<epsilon) || (fabs(d12-d13)<epsilon) || (fabs(d23-d13)<epsilon))
	{
		 printf("Jednakokraki");
	}
	else if((fabs(d12-d23)>epsilon) && (fabs(d23-d13)>epsilon))
	{
		printf("Raznostranicni");
	}
	
		
	
	if(alfa > beta && alfa > gama)
	{
		printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen1,sekunda1,alfa_sekunde);
	}
	else if(beta > alfa && beta > gama)
	{
		printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen2,sekunda2,beta_sekunde);
	}
	else if(gama > alfa && gama > beta)
	{
		printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen3,sekunda3,gama_sekunde);
	}
	return 0;
	
	
}


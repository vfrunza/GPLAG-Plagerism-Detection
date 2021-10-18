#include <stdio.h>
float maxtemp(float p[8])
{
	int i;
	float max=p[0];
	for(i=0;i<8;i++)
	 {
	   if(p[i]>max)
	   max=p[i];
	 }
	 return max;
}
float prtemp(float p[8])
{
	float suma=0,pt;
	int i;
	for(i=0;i<8;i++)
      	{
		  suma=suma+p[i];
    	}
    	pt=suma/8;
	return pt;
}
int main()
{
	int i;
	float niz[8];
	printf("Unesite temperature: ");
	for(i=0;i<8;i++)
	{
		scanf("%f",&niz[i]);
	}
	printf("Maksimalna temperatura: %.1f \n",maxtemp(niz));
	printf("Prosjecna temperatura: %.1f \n",prtemp(niz));
	return 0;
}


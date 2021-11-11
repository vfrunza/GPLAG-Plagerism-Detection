#include <stdio.h>
#define PI 3.1415926

int main() {
	int unos = 1;
	float a[500];
	printf("Unesite broj uglova: ");
	scanf("%d", &unos);
	if(unos > 0 && unos <= 500)
	{
		int i = 0;
		int brojac = 0;
		for(i; i<unos; i++)
		{
			float k;
			scanf("%f", &k);
			int ugao = 0, min, mnozac = 1;
			if(k < 0)
				mnozac*=-1;
			ugao = mnozac*k*180/PI;
			min=(mnozac*k*180.0/PI-ugao)*60;
			float s;
			int sekunde;
			s = (((mnozac*k*180.0/PI-ugao)*60.0) - min)*60.0 + 0.5;
			sekunde = (int) s;
			if(sekunde == 60){
				sekunde = 0;
				min++;
				if(min == 60){
					ugao++;
					min = 0;
				}
				
			}
			if (sekunde<=30)
			{
				if(brojac == 0)
					printf("Uglovi su:\n");
		
				a[brojac] = k;
				printf("%d stepeni %d minuta %d sekundi\n",mnozac*ugao,min,sekunde); 
			    brojac++;
			}
		}
	}
	return 0;
}

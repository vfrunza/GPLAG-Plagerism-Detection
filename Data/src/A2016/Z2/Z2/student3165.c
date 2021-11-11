#include <stdio.h>
#define PI 3.1415926

int main() {
	double ugao_u_radijanima, niz[500];
	int br_u, stepen, sekunda, minuta, i, j;
	
	br_u = 1000;
	while (br_u > 500){
		printf ("\nUnesite broj uglova: ");
		scanf ("%d", &br_u);
	}
	
	for (i=0; i<br_u; i++){
		scanf ("%lf", &niz[i]);
	}
	
	printf ("Uglovi su:");
	
	for(i = 0; i < br_u; i++)
	{
		
	int neg = 0;
	/*stepeni*/
	ugao_u_radijanima = niz[i];
	if(ugao_u_radijanima < 0)
	{
		ugao_u_radijanima *= -1;
		neg = 1;
	}
		ugao_u_radijanima = ugao_u_radijanima * (180/PI);
		stepen = (int)ugao_u_radijanima;
		
		ugao_u_radijanima = ugao_u_radijanima - stepen;
		
		/*minute*/
		ugao_u_radijanima = ugao_u_radijanima * 60;
		minuta = (int)ugao_u_radijanima;
		
		ugao_u_radijanima = ugao_u_radijanima - minuta;
		
		/*sekunde*/
		ugao_u_radijanima = ugao_u_radijanima *60 +0.5555555;
		sekunda = (int)ugao_u_radijanima;
		
	if(sekunda > 30)
	{
		for(j = i; j < br_u - 1; j++)
		{
			niz[j] = niz[j+1];
		}
		br_u--;
		i--;
	}
	else
	{
		if(neg)
				printf ("\n-%d stepeni %d minuta %d sekundi", stepen, minuta, sekunda);

		else
		printf ("\n%d stepeni %d minuta %d sekundi", stepen, minuta, sekunda);
	}
	}

	return 0;
}

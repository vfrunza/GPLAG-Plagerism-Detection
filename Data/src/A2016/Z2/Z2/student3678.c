#include <stdio.h>
#include <math.h>
#define MAX 500
#define PI 3.1415926f

int main() 
{
	int N, i, j;
	float niz[MAX], stepen, minut, sek;
	do{
		printf("Unesite broj uglova: ");
		scanf("%d", &N);}
		
	while (N<0 || N>MAX);

	for(i=0;i<N;i++)
	    scanf("%f", &niz[i]);
	  printf("Uglovi su:\n");
	  for(i=0;i<N;i++)
	  {
	  	stepen=niz[i]*(180/PI);
	  	minut=fmod(stepen,1.0)*60;
	  	sek=fmod(minut,1.0)*60;
	  	sek=ceil(sek);
	  	if(sek<=30)
	  {
	  	
	  	 printf("%.0f stepeni ", floor(stepen));
	  	 printf("%.0f minuta ", floor(minut));
	  	 printf("%.0f sekundi\n", sek); }
	  	 
	  	else
	  	{
	  		for(j=i;j<N-1;j++)
	  		   niz[j]=niz[j+1];
	  		   N--;
	  		   i--;
	  	}
	  }
	return 0;
}

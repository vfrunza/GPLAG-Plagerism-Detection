#include <stdio.h>
#include <math.h>
void zaokruzil(float niz[],int n){
	int i;
	double broj;
	for(i=0;i<n;i++){
		broj=roundf(niz[i]*10)/10;
		niz[i]=broj;
	}
}

void preslozi(float niz[],int n, int k){
	int i,j;
	int brojac=0;
	int suma=0,broj;
	double temp;
	
	zaokruzil(niz,n);
	for(i=0;i<n;i++){
		for(broj=niz[i]*10;broj!=0;broj=broj/10) suma=suma+fabs(broj%10);
		if(suma>=k)
		{
			if(i!=brojac)
			{
			temp=niz[brojac];
			niz[brojac]=niz[i];
			for(j=i;j>brojac;j--){
				niz[j]=niz[j-1];
			}
			brojac++;
			niz[brojac]=temp;
	
			}
			else brojac++;
	}
	
	
}
}



int main()
{
	
	int i;
	float niz[6]={2,2,3,1,2,3};
	preslozi(niz,6,5);
	printf("Niz glasi: ");
	for(i=0;i<6;i++){
	printf("%g",niz[i]);
	}
	
	
	return 0;
}

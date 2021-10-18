#include <stdio.h>
#include <math.h>

void zaokruzi1(float niz[],int a){
	 int i;
	 for(i=0;i<a;i++){
	 	niz[i]*=10;
	 	niz[i]=round(niz[i]);
	 	niz[i] /=10;
	 }
}

void preslozi(float niz[],int vel,int k){
	int i,j=0,broj,pomocni[10000],brojac=0;
	float rezultat[10000];
	
	zaokruzi1(niz,vel);
	for(i=0;i<vel;i++){
		pomocni[i]=fabs(niz[i]*10);  
	}
	
	for(i=0;i<vel;i++){
		broj=pomocni[i];
		while(broj>0){
		brojac+=broj%10;
		broj/=10;
		}
		if(brojac>=k){
			rezultat[j]=niz[i];
			j++;
	}
	brojac=0; 
	}
	
	for(i=0;i<vel;i++){
		broj=pomocni[i];
		while(broj>0){
		brojac+=broj%10;
		broj/=10;
		}
		if(brojac<k){
			rezultat[j]=niz[i];
			j++;
	}
	brojac=0; 
	}
	for(i=0;i<vel;i++){
		niz[i]=rezultat[i];
	}
}


int main()
{

int i;
float niz[] = { -1.0, -0.1, 0.19999, -4.449999, -4.45001 };
preslozi(niz, 5, 8);
printf("Niz glasi: ");
for (i=0; i<5; i++)
    printf("%g ", niz[i]);
 
return 0;
}


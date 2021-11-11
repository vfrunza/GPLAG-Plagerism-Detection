#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void zaokruzi1(float niz[], int vel){
	int i;
	for(i=0;i<vel;i++){
	niz[i]=niz[i]*10;
	niz[i]=roundf(niz[i]);
	niz[i]=niz[i]/10;
	}
}
void duplicirati(float niz[], float niz2[],int vel){
	int i;
	for(i=0;i<vel;i++){
		niz2[i]=niz[i];
	}
}
int razloziti(float niz[], int i){
	int suma=0;
	float temp=0;;
	niz[i]=niz[i]*10;
	niz[i]=abs(niz[i]);
	while((int)niz[i]!=0){
		temp=(int)niz[i]%10;
		suma=suma+temp;
		niz[i]=niz[i]/10;
		niz[i]=(int)niz[i];
	}
	return suma;
}
void preslozi(float niz[], int vel, int k){
	int j1=0, j2=0;
	int i;
	float niz3[100],niz4[100],niz2[1000];
	zaokruzi1(niz,vel);
	duplicirati(niz,niz2,vel);
	for(i=0;i<vel;i++){
	if(razloziti(niz2,i)>=k){
		niz3[j1]=niz[i];
		j1++;
	}
	else if(razloziti(niz2,i)<k){
		niz4[j2]=niz[i];
		j2++;
		}
	}
	j2=0;
	for(i=0;i<vel;i++){
		if(i<j1){
			niz[i]=niz3[i];
		}
		else{
			niz[i]=niz4[j2];
			j2++;
		}
	}
	
}
int main(){
	float niz[5];
	int i;
	int vel=5;
	int k=14;
	printf("Unesite clanove niza: ");
	for(i=0;i<vel;i++){
		scanf("%f",&niz[i]);
	
	}
preslozi(niz,vel,k);	

for(i=0;i<5;i++){
	printf("%g ",niz[i]);}

	return 0;
}


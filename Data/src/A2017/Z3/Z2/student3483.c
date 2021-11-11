#include <stdio.h>
#include <math.h>

int SumaCifara(int broj){
	int suma=0;
	while(broj!=0){
		suma+=broj%10;
		broj/=10;
	}
	return suma;
}

float pomocna(float broj){
	return broj < 0 ? (int)(broj*10-0.5)/10. : (int)(broj*10+0.5)/10.;
}

void zaokruzi1(float niz_real[], int vel_niza){
	int i;
	for(i=0;i<vel_niza;i++){
		niz_real[i]=pomocna(niz_real[i]);
	}
}

void preslozi(float niz_real[], int vel_niza, int k){
	int i,p=0,broj=0;
	float temp[100000]={0};/*pomocni niz u kojem cuvamo vrijednosti*/
	/*prvo zaokruzimo broj*/
	zaokruzi1(niz_real,vel_niza);
	
	/*prvi slucaj kada je suma cifara >= od k*/
	for(i=0;i<vel_niza;i++){
		broj=niz_real[i]*10;
		if(fabs(SumaCifara(broj))>=k){  /*voditi racuna da suma moze biti negativna*/
			temp[p++]=niz_real[i];
		}
	}
	/*Drugi slucaj kada je suma < od k*/
	for(i=0;i<vel_niza;i++){
		broj=niz_real[i]*10;
		if(fabs(SumaCifara(broj))<k){
			temp[p++]=niz_real[i];
		}
	}
	/*Konacno dodjelimo preslozeni temp nizu niz_real*/
	for(i=0;i<vel_niza;i++){
		niz_real[i]=temp[i];
	}
}

int main() {
	int i;
	float niz[]={12.332,15.4552,9.33245};
	preslozi(niz,3,10);
	printf("Novi niz glasi: ");
	for(i=0;i<3;i++){
		printf("%g ", niz[i]);
	}
	return 0;
}

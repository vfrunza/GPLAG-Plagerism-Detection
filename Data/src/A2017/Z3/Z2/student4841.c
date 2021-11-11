#include <stdio.h>
#include <math.h>
#define e 0.01

void zaokruzi1(float* niz, int el){
	int i=0;
	for(i=0; i<el; i++){
		*(niz+i)=round(*(niz+i)*10)/10;
	}
}

void preslozi(float* niz, int el, int k){
	int i, temp[5002], temp1[5002];
	float  var, vartemp;
	zaokruzi1(niz, el);
	for(i=0; i<el; i++){
		if(niz[i]>=0) temp1[i]=fabs(floor(niz[i]));
		else temp1[i]=fabs(ceil(niz[i]));
		temp[i]=(int)(((fabs(niz[i])+e)-(temp1[i]))*10);
		do{
			temp[i]+=temp1[i]%10;
			temp1[i]=temp1[i]/10;
		}while(temp1[i]>0);
	}
	temp[el]=-1;
	temp[el+1]=-1;
	i=-1;
	do{
		i++;
		if(temp[i]<k && temp[i+1]>=k){
			vartemp=temp[i];
			temp[i]=temp[i+1];
			temp[i+1]=vartemp;
			var=niz[i];
			niz[i]=niz[i+1];
			niz[i+1]=var;
			i=-1;
		}
	}while(i<el);
	
}

int main() {
	float niz[5000]; 
	int broj_el, k, i;
	printf("Unesite broj elemenata: ");
	do{
		scanf("%d", &broj_el);
	}while(broj_el<1 || broj_el>5000);
	for(i=0; i<broj_el; i++){
		printf("Unesite %d. clan niza: ",  i+1);
		scanf("%f", &niz[i]);
	}
	printf("Unesite broj k: ");
	scanf("%d", &k);
	preslozi(niz, broj_el, k);
	printf("Niz glasi: ");
	for(i=0; i<broj_el; i++){
		printf("%g ", niz[i]);
	}
	return 0;
}

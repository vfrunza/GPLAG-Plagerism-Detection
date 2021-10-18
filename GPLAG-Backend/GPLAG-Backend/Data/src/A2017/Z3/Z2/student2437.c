#include <stdio.h>
#define vel 5

float zaokruzi1(float niz[],int velicina){
	int i,novi;
	float zb,*p;
	for(i=0;i<velicina;i++){
		novi=niz[i]*100;
	novi=novi+5;
	zb=novi/100.;
	p=zb;
	p++;
	}return *p;
}
float preslozi(float niz[],int velicina,int k){
	int i,suma=0,x,cifra;
	zaokruzi1(niz,velicina);
	for(i=0;i<velicina;i++){
		x=niz[i]*10;
		while(x!=0){
	cifra=x%10;
	x=x/10;
	suma=suma+cifra;
		if(suma<=k && i==velicina-1)
		printf("%g",niz[i]);
		else if(suma<=k)printf("%g, ",niz[i]);
	
	}

}return 0;}
int main() {
int i,k,brojac=0;
float niz[vel];
printf("Unesi niz: ");
for(i=0;i<vel;i++){
	scanf("%f", &niz[i]);
	if(niz[i]==-1)break;
	brojac++;
	}
printf("Unesi prirodan broj k: ");
scanf("%d", &k);
preslozi(niz,brojac,k);

	return 0;
}

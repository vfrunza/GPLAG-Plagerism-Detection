#include <stdio.h>
#include <math.h>

void zaokruzi1(float niz[], int velicina){
	int i;
	float pomocna;
	for(i=0;i<velicina;i++){
		if(niz[i]>=0){
		
	    	pomocna=(int)(niz[i]*100);
		    if((int)(pomocna)%10>=5)pomocna=pomocna+5;
		    pomocna=(int)(pomocna/10);
		    pomocna=(pomocna/10.);
		    
		 }
		 else if(niz[i]<0){
		 	pomocna=(int)(niz[i]*100);
		 	if((int)(pomocna)%10>5)pomocna=pomocna-5;
		 	pomocna=pomocna-5;
		 	pomocna=(int)(pomocna/10);
		 	pomocna=(pomocna/10.);
		 }
		 niz[i]=pomocna;
   }
}
int suma_cifara(float a){
	int suma=0,cifra,b;
	if(a<0)a=(fabs)(a);
	b=(int)(a*10);
	while(b!=0){
		cifra=b%10;
		suma=suma+cifra;
		b=b/10;
	}
	return suma;
}

void preslozi (float niz[], int velicina,int k){
	int i,brojac=0,j;
	float temp;
	zaokruzi1(niz,velicina);
     for(i=0;i<velicina;i++){
     	if(suma_cifara(niz[i])<k){
     		for(j=i;j<velicina-1;j++){
     			temp=niz[j];
     			niz[j]=niz[j+1];
     			niz[j+1]=temp;
     		}
     		i--;
     	}
     	brojac++;
     	if(brojac==velicina)break;
     }
}
    
   

	int main() {
	float niz[100];
	float *p;
	int n,i,k;
	printf("Unijeti broj clanova niza: ");
	scanf("%d",&n);
	printf("Unijeti niz: ");
	for(i=0;i<n;i++){
		scanf("%f",&niz[i]);
	}
	p=&niz[0];
	zaokruzi1(p,n);
	for(i=0;i<n;i++){
		printf("%g ",niz[i]);
	}

	k=14;
	preslozi(p,n,k);
	for(i=0;i<n;i++){
	  printf("%g ",niz[i]);
	}
	return 0;
}

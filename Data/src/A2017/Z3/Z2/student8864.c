#include <stdio.h>
#include <math.h>
#define epsilon 0.01

void zaokruzi1(float *a,int duzina){
	int i;
	for(i=0;i<duzina;i++){
		a[i]=round(a[i]*10)/10;
	}
}
void preslozi(float *a,int duzina,int k){
	int i,j,l,suma,brojac=0, novi2;
	float novi1,temp;
	zaokruzi1(a, duzina);
	j=0;
	for(i=0;i<duzina;i++){
		novi2=(int)fabs(a[i]*10);
		suma=0;
		do{
			suma=suma+novi2%10;
			novi2=novi2/10;
		}while(novi2>0);
		if(suma>=k){
			for(l=0;l<i-j;l++){
				temp=a[i-l];
				a[i-l]=a[i-l-1];
				a[i-l-1]=temp;
			}
			j++;
			brojac++;
		}
		
	
	}
}

int main() {
	int i;
float niz[] = { -1.0, -0.1, -0.19999, -4.449999, -4.45001 };
preslozi(niz, 5, 8);
printf("Niz glasi: ");
for (i=0; i<5; i++)
    printf("%g ", niz[i]);
	
	return 0;
}

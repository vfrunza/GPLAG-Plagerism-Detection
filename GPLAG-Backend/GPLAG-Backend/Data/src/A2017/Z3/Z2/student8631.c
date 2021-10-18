#include <stdio.h>
#include<math.h>

void zaokruzi1(float niz[], int vel )
{
	int i;
	for(i=0; i<vel; i++){
		if(niz[i]>0) niz[i]=((int)(niz[i]*10+0.5))/10.;
		else niz[i]=-1*((int)(fabs(niz[i]*10)+0.5))/10.;
	}
/*
    float *p=niz;
	do {
		if((*p)>0) {
			*p=((int)((*p)*10+0.5))/10.;

		} else {
			*p=-1*((int)(fabs((*p)*10)+0.5))/10.;
		}
		p++;
	} while ((p-niz)<vel);*/
}

int suma_cifara(float broj)
{
	int suma=0;
	if(broj <0) broj*=-1;
	int n=broj*10;
	
	while (n!=0) {
		suma+=n%10;
		n/=10;
	}
	return suma;

}
void preslozi(float *niz, int vel, int k)
{
	int i;
    float temp;
    zaokruzi1(niz, vel);
    float niz1[1000];
    int j=0;
    int n=0;
    for(i=0; i<vel; i++){
    	n=suma_cifara(niz[i]);
    	if(n>=k)
    		{niz1[j++]=niz[i];
    		}
    }
    for(i=0; i<vel; i++){
    	n=suma_cifara(niz[i]);
    	if(n<k)
    		{niz1[j]=niz[i];
    		j++;}
    }
    for( i=0; i<vel; i++){
    	niz[i]=niz1[i];
    }/*
	for(i=0 ; i<vel; i++) {
		for(j=1; j<vel; j++) {
			if(suma_cifara(niz[i])<k) {
				temp=niz[i];
				niz[i]=niz[j];
				niz[j]= temp;
			}
		}
	}*/
}

int main()
{
	int i;
float niz[] = { -1.0, -0.1, -0.19999, -4.449999, -4.45001 };
preslozi(niz, 5, 8);
printf("Niz glasi: ");
for (i=0; i<5; i++)
    printf("%g ", niz[i]);
	//ISPIS -4.4 -4.5 -1 -0.1 -0.2   
	return 0;
}

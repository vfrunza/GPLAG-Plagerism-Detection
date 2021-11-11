#include <stdio.h>
#include <math.h>

void zaokruzi1(float *niz,int vel)
{
	int i;
	for(i=0;i<vel;i++) niz[i]=(round)(niz[i]*10)/10;
}

int suma_cifara(float broj)
{
	int suma=0;
	int tmp;
	if(broj<0) broj*=(-10);
else broj*=10;
	tmp=broj;
	do{
		suma+=tmp%10;
		tmp/=10;
	} while(tmp!=0);
	
	return suma;
}


void preslozi(float *niz,int vel,int k)
{
	int i;
	float tmp;
	int j;
	int pomoc=vel;
	zaokruzi1(niz,vel);
	for(i=0;i<pomoc;i++){
		if(suma_cifara(niz[i])<k){
			tmp=niz[i];
			for(j=i;j<vel-1;j++) niz[j]=niz[j+1];
			niz[vel-1]=tmp;
			i--;
			pomoc--;
		}
	}
}


int main(){
	int i;
	float a[5]={-23.2,-15.8999,25.80,-17.222,78.1};
	preslozi(a,5,24);
	for(i=0;i<5;i++) printf("%g",a[i]);
	

	return 0;
}
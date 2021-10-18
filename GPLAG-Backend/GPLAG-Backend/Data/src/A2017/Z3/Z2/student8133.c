#include <stdio.h>

void zaokruzi1(float *niz, int vel){
	int i;
	float a;
	for(i=0; i<vel; i++){
		int b=0;
		if(niz[i]<0){
			b=1;
			niz[i]=niz[i]*-1.;
		}
		a=(int)(niz[i]*10+0.5);
		niz[i]=a/10;
		if(b==1){
			niz[i]=niz[i]*-1.;
		}
		}
}
int suma(float b){
	int suma=0;
	if(b<0){
		b=b*-1.;
	}
	b=b*10;
	int x=b;
	while(x!=0){
		suma+=x%10;
		x=x/10;
	}
	return suma;
}


void preslozi(float *niz, int vel, int k){
	zaokruzi1(niz, vel);
	int i,j;
	int o=0;
 float pom[100];
 
	for(i=0; i<vel; i++){
		if(suma(niz[i])>=k)
			pom[o++]=niz[i];
	
			}
	for(i=0;i<vel;i++)
		if(suma(niz[i])<k)
			pom[o++]=niz[i];
		
	for(i=0;i<vel;i++)
		niz[i]=pom[i];
}
int main() {
	
	return 0;
}

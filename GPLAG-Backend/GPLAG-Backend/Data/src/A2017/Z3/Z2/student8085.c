//printf("Zadaća 3, Zadatak 2");
#include <stdio.h>
#include <math.h>

void zaokruzi1(float *niz,int vel) {
int i;
int pom, pom1, znak=0; 
float temp, temp1;

for(i=0; i<vel; i++) {
	znak=0; 
	
	if(niz[i]<0) znak=1;
		temp=fabs(niz[i]);
		pom=fabs(niz[i]);
		temp1=temp-pom;
		temp1*=100;
		pom1=temp1;
		if(pom1%10>=5) {
			pom1/=10;
			pom1++;
		}
		else {
		pom1/=10;
	}

temp1=pom1/10.;
niz[i]=pom+temp1;
if(znak==1) niz[i]*=-1;
	}

}

int SaberiCifre(float n) {
	int suma=0; 
	if(n<0) n*=-1;
	int temp=n;
	float pom=n-temp;
	
	suma=pom*100;
	if(suma%10>=5) {
		suma/=10;
		suma++;
	}
	else {
	suma/=10;
	}
	
while(temp!=0) {
	suma+=temp%10;
	temp/=10;
}
return suma;
}

void preslozi(float *niz, int vel, int k) {
	float temp;
	int i,j,br=0; 
	
	zaokruzi1(niz,vel);
	
for(i=0; i<vel; i++ ){
	if(SaberiCifre(niz[i])>=k) {
		for(j=0; j<i; j++) {
			temp=niz[j];
			niz[j]=niz[i];
			niz[i]=temp;
		}
		br++;
	}
}

for(i=0; i<br;i++) {
	for(j=0; j<i; j++) {
		temp=niz[i];
		niz[i]=niz[j];
		niz[j]=temp;
	}
}

}

int main() {

float niz[1000];
int vel,i;
int k;
float a;
printf("Uneiste velicinu niza: ");
scanf("%d", &vel);

printf("Uneiste elemente niza: ");
for(i=0; i<vel; i++) {
	scanf("%f", &niz[i]);
}

printf("Uneiste broj: ");
scanf("%d", &k);

preslozi(niz,vel,k);
for(i=0; i<vel; i++) 
printf(" %.1f", niz[i]);

return 0;
}

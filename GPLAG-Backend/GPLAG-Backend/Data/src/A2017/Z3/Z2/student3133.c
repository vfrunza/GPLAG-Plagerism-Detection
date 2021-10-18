#include <stdio.h>
#include <math.h>
#define epsilon 0.0001

int poredi(float x,float y){
		return (fabs(x-y)<epsilon); 
}

void zaokruzi1(float niz[],int vel){
	int i;
for(i=0;i<vel;++i){
	if(niz[i]>=0.)
	niz[i]=((int)(niz[i]*10 + 0.5)/10.);
	else
	niz[i]=((int)(niz[i]*10 - 0.5)/10.);
	}
}

void preslozi(float niz[],int vel,int k){
	int i,j,temp=0,x=0,kum=0,y=0,suma=0;
	zaokruzi1(niz,vel);
	for(i=0;i<vel;++i){
		for(j=i+1;j<vel;++j){
			x=(int)(niz[j]*10);
			suma=0;
			do{
			y=x%10;
			suma+=y;
			x/=10;
			}while(x!=0);
			
			if(suma>=14){
				temp=niz[i];
				niz[i]=niz[j];
				niz[j]=temp;}
		}
	}
}
int main() {
int i;
    float niz[] = { 13.1, 15.749999, 15.75, 9.222, 78.1 };
    preslozi(niz, 5, 14);
    printf("Niz glasi: ");
    for (i=0; i<5; i++)
        printf("%g ", niz[i]);
 
	return 0;
}

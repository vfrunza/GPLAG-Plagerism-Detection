#include <stdio.h>
#include <math.h>
void zaokruzi1(float niz[], int vel){
	int i;
	for(i=0; i<vel; i++)
	niz[i]=round(10*niz[i])/10;
}

void preslozi(float niz[], int vel, int k){
	int i;
	int temp1;
	int temp2;
	int temp3;
	int suma=0;
	zaokruzi1(niz, vel);
	for(i=0; i<vel; i++){
	temp1=(int)(10*niz[i]);
	temp1=0;
	while(temp1!=0){
		temp2=temp1%10;
		temp1/=10;
		suma+=temp2;
	}
	
	if(suma>=k){
		for(k=i; k<vel; k++){
			temp3=niz[k];
			niz[k]=niz[k+1];
			niz[k+1]=temp3;
		}
	}
	
  }
	
	
}

int main() {
	return 0;
}

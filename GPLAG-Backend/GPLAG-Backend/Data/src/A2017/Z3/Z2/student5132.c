#include <stdio.h>
#include <math.h>

void zaokruzi1(float niz[],int broj_elemenata) {
	float pomocni2,pomocni3;
	int i=0,pomocni,p;
	for(i=0; i<broj_elemenata;i++){
	    pomocni2 = niz[i]*100;
	    pomocni=(int)pomocni2;
	    p = fabs(pomocni);
	    if(p%10>=5){
	    	pomocni2/=10;
	    	if(pomocni2>0) pomocni2++;
	    	else pomocni2--;
	    	pomocni3 = (int)pomocni2;
	    }
	    else{
	    	pomocni2/=10;
	    	pomocni3 = (int)pomocni2;
	    }
	    pomocni3=(float)pomocni3/10;
	    niz[i]=pomocni3;
	   
	}
}

int broj_cifara(float x) {
	int suma=0;
	int y= fabs((int)(x*10));
	while(y!=0) {
			suma+= y%10;
			y/=10;
		}
	return suma;
}
void preslozi(float niz[], int velicina, int k) {
	int i=0, br1=0, br2=0, br3=0;
	float pomocni1[1000], pomocni2[1000];
	
	zaokruzi1(niz,velicina);
	
	for(i=0; i<velicina; i++) {
		
		if(broj_cifara(niz[i])>=k){
			pomocni1[br1++] = niz[i]; 
		}
		else {
			pomocni2[br2++] = niz[i];
		}
	}
	for(i=0; i<br1; i++) {
		niz[br3++] = pomocni1[i];
	}
	for(i=0; i<br2; i++) {
		niz[br3++] = pomocni2[i];
	}
}

int main() {
	float niz[100]={0};
	int broj_el, i, k;
	
	printf("Unesite broj elemenata ");
	scanf("%d", &broj_el);
	
	printf("Unesite elemente niza: ");
	for(i=0; i<broj_el; i++) {
		printf("%d.-ti element: ", i+1);
		scanf("%f", &niz[i]);
	}
	
	zaokruzi1(niz,broj_el);
	
	printf("Unesite broj k ");
	scanf("%d", &k);
	
	preslozi(niz, broj_el, k);
	
	printf("Krajnji niz glasi: ");
	for(i=0; i<broj_el; i++) {
		printf("%g ", niz[i]);
	}
	
	return 0;
}

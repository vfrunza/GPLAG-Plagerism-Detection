#include <stdio.h>
#include <math.h>

void zaokruzi1(float niz[],int vel){
	int i;
	for(i=0;i<vel;i++){
		niz[i]=(round(niz[i]*10))/10;
		 
	}
}

int suma_cifara(int broj){
	int suma=0;
	while (broj!=0) {
		suma+=broj%10;
		broj=broj/10;
	}
	return suma;
}

void preslozi(float niz[],int vel,int k){
	zaokruzi1(niz,vel);
	int i;
	int n_niz[100];
	for(i=0;i<vel;i++){
		n_niz[i]=(int)(niz[i]*10);
		if(n_niz[i] < 0){
			n_niz[i]*=-1;
		}
	}

	int s_c;
	float niz_vecih[100];
	int vel_vecih=0;
	int vel_manjih=0;
	float niz_manjih[100];
	int pos_manjih = 0;
	int pos_vecih = 0;
	for(i=0;i<vel;i++){
		s_c=suma_cifara(n_niz[i]);
	
		if (s_c>=k) {
			niz_vecih[pos_vecih]=niz[i];
			vel_vecih++;
			pos_vecih++;
	
		}
		else {
			niz_manjih[pos_manjih]=niz[i];	
			vel_manjih++;
			pos_manjih++;
			
		}
	}
	int pos_poredanih = 0;
	for( i=0;i<vel_vecih;i++){
		niz[pos_poredanih]=niz_vecih[i];
		pos_poredanih++;
	}
	for (i = 0;i<vel_manjih;i++){
		niz[pos_poredanih]=niz_manjih[i];
		pos_poredanih++;
	}

}

int main() {
	int broj=156;
 float niz[]={13.1,15.74999,15.75,9.2222,78.1};
preslozi(niz,5,14);
int sum;
sum = suma_cifara(broj);
	return 0;
}

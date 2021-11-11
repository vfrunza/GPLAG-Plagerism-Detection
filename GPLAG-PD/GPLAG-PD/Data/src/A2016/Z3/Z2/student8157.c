#include <stdio.h>
#define vel 20

void ubaci(int* niz, int vell){
	int i,j,a,b,c,zbir;
	for(i=(vell); i>=0; i--){
		if(2*i>=0 && 2*i<=(2*vell-1)){
			niz[2*i]=niz[i];
		}
	}
	for(j=0; j<(2*vell); j+=2){
		if(niz[j]<0){
			a=-1*niz[j];
		}
		else{
			a=niz[j];
		}
		b=1;
		zbir=0;
		while(b!=0){
			while(a%10==0 && a!=0){
				a=a/10;
			}
			c=a/10;
			b=a%10;
			zbir+=b;
			a=c;
		}
		niz[j+1]=zbir;
	}

}

int izbaci (int niz[], int vell){
	int i,j,k,temp,max,feb_cl_1=1,feb_cl_2=1;
	max=niz[0];
	for(i=0; i<vell; i++){
		if(niz[i]>max){
			max=niz[i];
		}
	}
	while (feb_cl_2<=max){
		for(j=0; j<vell; j++){
			if(niz[j]==feb_cl_2){
				for(k=j; k<vell; k++){
					if(k+1<vell){
						niz[k]=niz[k+1];
					}
				}
				vell--;
				j--;
			}
		}
	temp=feb_cl_2;
	feb_cl_2+=feb_cl_1;
	feb_cl_1=temp;
	}
	return vell;
}

int main() {
	int niz[vel],i,nova_vel;
	//Unos
	printf("Unesite niz od %d brojeva: ", (vel/2));
	for(i=0; i<(vel/2); i++){
		scanf("%d", &niz[i]);
	}
	//Obrada podataka
	ubaci(niz,(vel/2));
	nova_vel=izbaci(niz,vel);
	//Ispis
	printf("Modificirani niz glasi:");
	for(i=0; i<nova_vel; i++){
		if(i==(nova_vel-1)){
			printf(" %d.", niz[i]);
		}
		else{
			printf(" %d,", niz[i]);
		}
	}
	return 0;
}
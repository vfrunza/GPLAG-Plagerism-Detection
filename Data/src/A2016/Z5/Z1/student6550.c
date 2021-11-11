#include <stdio.h>
#include <string.h>
#include <math.h>

struct Student {
char ime[20], prezime[20];
int ocjene[50];
	int br_ocjena;
};

float prosjek1(struct Student st){
	int i=0;
	float pro=0,suma=0;
	if(st.br_ocjena==0) return 5.0;
	for(i=0;i<st.br_ocjena;i++){
		if(st.ocjene[i]>5.0){
		suma=suma+st.ocjene[i];
		}
		else
		return 5.0;
	}
	pro=(float)suma/st.br_ocjena;
	return pro;
}

int genijalci(struct Student* niz,int vel,float prosjek){
	int i=0,j=0,n=0;
	float b=0,prosjj[50]={0},max=0;
	for(i=0;i<vel;i++){
		b=prosjek1(niz[i]);
		prosjj[i]=b;
		if(b<prosjek){
			for(j=i;j<vel-1;j++){
				niz[j]=niz[j+1];
			}
			i--;
			vel--;
		}
	}
	for(i=0;i<vel;i++)
	printf("%s  %s  %f\n",niz[i].prezime,niz[i].ime,prosjj[i]);
	
		
	return vel;
}

int main() {

	return 0;
}

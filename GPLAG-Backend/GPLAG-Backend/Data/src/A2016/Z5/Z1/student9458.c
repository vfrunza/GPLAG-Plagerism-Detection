#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define E 0.0000001
struct Student{
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};
int veci(int k, int j, struct Student niz[]){
	int i;
	for(i=0; i<20; i++){
		if(niz[k].prezime[i] < niz[j].prezime[i])return k;
		else if(niz[k].prezime[i] > niz[j].prezime[i])return j;
		else continue;
	}
	for(i=0; i<20; i++){
		if(niz[k].ime[i] < niz[j].ime[i]){return k;}
		else if(niz[k].ime[i] > niz[j].ime[i]){return j;}
		else continue;
	}
	return k;
}
double prosjek(struct Student niz[],int k){
	int i;
	double zbir=0,prosjekk,s=5.0;
	if(niz[k].br_ocjena==0)return s;
	for(i=0; i<niz[k].br_ocjena; i++){
		if(niz[k].ocjene[i]==5) return s;
		else zbir+=niz[k].ocjene[i];
	}
	prosjekk=zbir/niz[k].br_ocjena;
	return prosjekk;
}


int genijalci(struct Student niz[], int br, double pro){
	double pros;
	int i,n=br,j,m=0,k=0;
	int red[3]={-1,-1,-1};
	for(i=0;i<n;i++){
		pros=prosjek(niz,i);
		if(pros<pro){
			for(j=i;j<n-1;j++){
				niz[j]=niz[j+1];
			}
			n--;
			i--;
		}
	}
	if(n==0){return n;}
	if(n==1){printf("%s %s\n",niz[0].prezime,niz[0].ime);return n;}
	if(n==2){
		if(prosjek(niz,0) > prosjek(niz,1)){
			printf("%s %s\n",niz[0].prezime,niz[0].ime);
			printf("%s %s\n",niz[1].prezime,niz[1].ime);
		}
		else if(prosjek(niz,0) < prosjek(niz,1)){
			printf("%s %s\n",niz[1].prezime,niz[1].ime);
			printf("%s %s\n",niz[0].prezime,niz[0].ime);
		}
		else if(fabs(prosjek(niz,k) - prosjek(niz,j))<E){
			if(veci(0,1,niz)==0){printf("%s %s\n",niz[0].prezime,niz[0].ime);
			printf("%s %s\n",niz[1].prezime,niz[1].ime);
			}
			else {printf("%s %s\n",niz[1].prezime,niz[1].ime);
			printf("%s %s\n",niz[0].prezime,niz[0].ime);}
		}
		return n;
	}
	for(i=0; i<3;++i){
		for(j=0; j<n; ++j){
			if(j==red[0] || j==red[1] || j==red[2])continue;
			if(prosjek(niz,k) < prosjek(niz,j))k=j;
			else if(fabs(prosjek(niz,k) - prosjek(niz,j))<E)k=veci(k,j,niz);
	}	
		red[m]=k;m++;
		printf("%s %s\n",niz[k].prezime,niz[k].ime);
		k=0;
	}
	return n;
}
int main() {
    struct Student studenti[6] ={
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Meho", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Pero", "Peric", { 8,8,8,8,7}, 5}, 
	{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Fata", "Fatic", { 7,7,7,7,8}, 5}, 
};
genijalci(studenti, 6, 6.5);
  
	return 0;
}

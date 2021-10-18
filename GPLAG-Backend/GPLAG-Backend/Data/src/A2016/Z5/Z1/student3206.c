#include <stdio.h>
struct Student{
	char ime[20],prezime[20];
	int ocjene[50];
	int br_ocjena;
};
int leksikografsko_poredjenje(const char *s1, const char *s2){
	while(*s1!='\0' && *s2!='\0'){
		if(*s1<*s2){}
		else if(*s1>*s2){
			return -1;
			break;
		}
		else{
			s1++;
			s2++;
		}
	}
	if(*s1=='\0' && *s2=='\0')
	return 0;
	else if(*s1=='\0')
	return 1;
}
float prosjek_ocjena(struct Student x){
	float pros;
	int i=0,suma=0;
	if(x.br_ocjena==0)
	return 5.0;
	else{
	while(i<x.br_ocjena && i<50){
		suma=suma+x.ocjene[i];
		if(x.ocjene[i]==5){
			return 5.0;
		}
		i++;
	}
	pros=(float)suma/x.br_ocjena;
	return pros;
	}
}
int genijalci(struct Student* niz,int vel,float prosjek){
	int i=0,j,maxk=0,k=0,p,n[3],vell=0,bl;
	float maxpr;
	while(i<vel){
		if(prosjek_ocjena(niz[i])<prosjek){
			for(j=i;j<vel-1;j++){
				niz[j]=niz[j+1];
			}
			i--;
			vel--;
		}
		i++;
	}
	p=vel;
	i=0;
	while(i<3){
		k=0;
		maxpr=prosjek;
	while(k<vel){
		bl=0;
		for(j=0;j<vell;j++)
		if (n[j]==k)
		bl=1;
		if(bl==1){
			k++;
			continue;
		}
         if(prosjek_ocjena(niz[k])>maxpr){
         	maxk=k;
         	maxpr=prosjek_ocjena(niz[k]);
         }
         else if(prosjek_ocjena(niz[k])==maxpr){
         	if(leksikografsko_poredjenje(niz[k].prezime,niz[maxk].prezime)==1){
         	   maxk=k;
         	   maxpr=prosjek_ocjena(niz[k]);
         	}
         	else if(leksikografsko_poredjenje(niz[k].prezime,niz[maxk].prezime)==0){
         		if(leksikografsko_poredjenje(niz[k].ime,niz[maxk].ime)==1){
         		   maxk=k;
         	       maxpr=prosjek_ocjena(niz[k]);
         		}
         	}
         }
         k++;
	}
	n[vell++]=maxk;
	p--;
	if(p>=0)
	printf("%s %s\n",niz[maxk].prezime,niz[maxk].ime);
	i++;
	}
	return vel;
}
int main() {
	printf("Zadaća 5, Zadatak 1");
	return 0;
}

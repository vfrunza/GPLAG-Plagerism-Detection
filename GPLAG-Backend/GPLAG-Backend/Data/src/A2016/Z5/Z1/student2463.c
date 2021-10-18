#include <stdio.h>
#include <string.h>
#include<math.h>
#define EPSILON 0.0001
struct Student {
	char ime[20];
	char prezime[20];
	int ocjene[50];
	int br_ocjena;
};

int vece(float a,float b) {
	if(a>b) return 1;
	return 0;
}

int manje(float a,float b) {
	if(a<b) return 1;
	return 0;
}

int jednako(float a,float b) {
	if(fabs(a-b)<EPSILON) return 1;
	return 0;
}

int manjejednako(float a,float b) {
	return manje(a,b) || jednako(a,b);
}

int vecejednako(float a,float b) {
	return vece(a,b) || jednako(a,b);
}
float Izracunaj(struct Student s) {
	if(s.br_ocjena==0) return 5;	
	int i=0;
	float suma=0,vrati;
	for(i=0;i<s.br_ocjena;i++) {
		
		if(s.ocjene[i]==5) return 5;
	
		suma+=s.ocjene[i];
	}
	vrati=suma/s.br_ocjena;
	
	return vrati;
}

int duzina(char* niz) {
	int brojac=0;
	while(*niz!='\0')  { niz++; brojac++; }
		return brojac;
	}
	
	
int veci(struct Student a,struct Student b) {
	
	int i,j;
	float prosjek1,prosjek2;
	int c=0;
	prosjek1=Izracunaj(a);
	prosjek2=Izracunaj(b);
	if(jednako(prosjek1,prosjek2)) { 
        if(strcmp(a.prezime,b.prezime)==0) {
        	if(strcmp(a.ime,b.ime)<0) 
        		return 1; 
        	
        	else if(strcmp(a.ime,b.ime)==0) 
        		 return 1; 
        	
             else  return 0; 
        	
        }
        else if (strcmp(a.prezime,b.prezime)<0)  return 1;
		
	}
	
	if(prosjek1>prosjek2) return 1;
	else return 0;
}
 
int genijalci(struct Student* niz,int vel,float prosjek ) {
	
	int i=0,brojac=vel,j;
	float provjera=0; 
	struct Student*max1=&niz[0];
	struct Student*max2=&niz[0];
	struct Student*max3=&niz[0];
	
	for(i=0;i<vel;i++) {
		provjera=Izracunaj(niz[i]);
		if(manje(provjera,prosjek)) {
			for(j=i;j<vel-1;j++) 
			niz[j]=niz[j+1];
			
			brojac--;
			vel--;
			i--;
		}
	}
	if(vel==0) return brojac;
	

	
	for(i=0;i<vel;i++) {
		if(veci(niz[i],*max1)) max1=&niz[i];
	}
	if(max2==max1) max2++;
	if(vel>1) {
		for(i=0;i<vel;i++) {
			if(veci(niz[i],*max2) && &niz[i]!=max1) max2=&niz[i];
		}
		
	}
	while(max3==max1 || max3==max2) max3++;
	if(vel>2) {
		for(i=0;i<vel;i++) {
			if(veci(niz[i],*max3) && &niz[i]!=max1 && &niz[i]!=max2) max3=&niz[i];
		}
	}
	if(vel>0)
  printf("%s %s\n",max1->prezime,max1->ime);
   if ( vel>1 )
  printf("%s %s\n",max2->prezime,max2->ime);
   if ( vel>2)
  printf("%s %s\n",max3->prezime,max3->ime);
	
return brojac;	
}




int main() {

	return 0;
}

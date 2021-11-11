#include <stdio.h>
#include <string.h>
#include <math.h>
#define EPSILON 0.001
struct Student {
    char ime[20], prezime[20];
    int ocjene[50];
    int br_ocjena;
};
void unesi(char niz[], int velicina) {
    
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i=0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}
int genijalci (struct Student* s,int velicina, float prosjek){
	int i,j,k,zbirocjena=0,max,pao=0,temp;
	float pros [100]={0};
	int pomocni [100]={0};
	float prosjekocjena;
	float temp1;
	for (i=0; i<velicina; i++) {
		pao=0;
		zbirocjena=0;
		for (k=0;k<s[i].br_ocjena;k++){
			if (s[i].ocjene[k]==5) {pao=1;break;}
		    zbirocjena+=s[i].ocjene[k];
		    }
		prosjekocjena=((float) zbirocjena)/s[i].br_ocjena;
		if(s[i].br_ocjena==0 || pao==1) prosjekocjena=5.0;
        if (prosjekocjena < prosjek) {
            for (j=i; j<velicina-1; j++) {
                 s[j] = s[j+1];
            }
			velicina--;
			i--;
		}
	} 
	for (i=0;i<velicina;i++){
		zbirocjena=0;
		for (k=0;k<s[i].br_ocjena;k++){
		    zbirocjena+=s[i].ocjene[k];
		    }
		prosjekocjena=((float)zbirocjena)/s[i].br_ocjena;
		pros[i]=prosjekocjena;
	}
	
	for (i=0;i<velicina;i++)
	    pomocni[i]=i;
	for (i=0;i<velicina;i++){
	    for(j=i+1;j<velicina;j++){
		    if (fabs(pros[i]-pros[j])<EPSILON && strcmp (s[i].prezime,s[j].prezime)>0){
			   temp1=pomocni[i];
			   pomocni[i]=pomocni[j];
			   pomocni[j]=temp1;
			   
			}
			else if (fabs(pros[i]-pros[j])<EPSILON && strcmp (s[i].prezime,s[j].prezime)==0 && strcmp (s[i].ime,s[j].ime)>0){
				temp1=pomocni[i];
			    pomocni[i]=pomocni[j];
			    pomocni[j]=temp1;
			}
		}
	}
	for(i=0;i<velicina;i++){
		max=i;
		for(j=i+1;j<velicina;j++){
				if(pros[j]>pros[max])
				max=j;
		}
		temp = pros[i];
        pros[i] = pros[max];
        pros[max] = temp;
        temp = pomocni[i];
        pomocni[i] = pomocni[max];
        pomocni[max] = temp;
	}

	if (velicina>=3){
	   for (i=0;i<3;i++){
	       printf("%s %s",s[pomocni[i]].prezime,s[pomocni[i]].ime);
	       printf("\n");
	   }
	}
	else {
		for (i=0;i<velicina;i++){
	         printf("%s %s",s[pomocni[i]].prezime,s[pomocni[i]].ime);
	         printf("\n");
		}
	}
	return velicina;
}
int main() {
	struct Student student[100];
	int i,j,velicina=0;
	float prosjek;
	for (i=0;i<5;i++){
		printf("Unesite prezime: ");
		unesi(student[i].prezime,20);
		printf("Unesite ime: ");
		unesi(student[i].ime,20);
		printf("Unesite broj ocjena: ");
		scanf("%d",&student[i].br_ocjena);
		printf("Unesite ocjene: ");
		for (j=0;j<student[i].br_ocjena;j++)
		scanf("%d",&student[i].ocjene[j]);
		velicina++;
	}
	printf("Unesite prosjek: ");
	scanf("%f",&prosjek);
	genijalci(student,velicina,prosjek);
	return 0;
}

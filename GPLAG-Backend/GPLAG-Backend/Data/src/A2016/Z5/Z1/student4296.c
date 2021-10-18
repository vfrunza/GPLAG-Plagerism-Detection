#include <stdio.h>
#include <math.h>
#define EPSILON 0.00000001
struct Student{
	char ime[20],prezime[20];
	int ocjene[50];
	int br_ocjena;
};
/*Izbacivanje studenta iz niza*/
void izbaci(struct Student *s,int i,int vel){
	int j;
	for(j=i;j<vel-1;j++){
		s[j]=s[j+1];
	}
}
int provjera_imena(struct Student *s,int zapamti,int i){
	char *p,*q;
	int manji=0;
	p=s[zapamti].prezime;
	q=s[i].prezime;
	/*Provjeravamo prezime*/
	while(*p!='\0' && 'q'!='\0'){
		if(*p==*q){
			p++;
			q++;
		}
		if(*p>*q){
			manji=1;
			break;
		}
		if(*p<*q)
			return zapamti;
	}
	
	if(manji==1)
		return i;
	/*Provjeravamo ime*/ 
	p=s[zapamti].ime;
	q=s[i].ime;
	while(*p!='\0' && 'q'!='\0'){
		if(*p>*q)
			manji=1;
		p++;
		q++;
	}
	if(manji==1)
		return i;
	return zapamti;
}
int genijalci(struct Student *s,int vel,float prosjek){
	int i,j,PR=0,zapamti1=0,zapamti2=0,zapamti3=0;
	float niz[50]={0};
	float prosjek_studenta=0,suma=0,max=0;
	/*Racunamo prosjek studenta i izbacujemo one studente ciji je prosjek manji od unesenog*/
	for(i=0; i<vel; i++){
		for(j=0; j<s[i].br_ocjena; j++){
			suma+=s[i].ocjene[j];
			if(s[i].ocjene[j]==5)
				PR=1;
		}
		if(s[i].br_ocjena==0)
			PR=1;
		if(PR==1){
			prosjek_studenta=5.;
			PR=0;
		}
		else prosjek_studenta=suma/s[i].br_ocjena;
		if(prosjek_studenta<prosjek){
			izbaci(s,i,vel);
			vel--;
			i--;
		}
		suma=0;
	}
	/*Ubacujemo prosjeke studenata u niz*/
	for(i=0; i<vel; i++){
		for(j=0; j<s[i].br_ocjena; j++){
			suma+=s[i].ocjene[j];
			if(s[i].ocjene[j]==5)
				PR=1;
		}
		if(s[i].br_ocjena==0)
			PR=1;
		if(PR==1){
			prosjek_studenta=5.;
			PR=0;
		}
		else prosjek_studenta=suma/s[i].br_ocjena;
		if(prosjek_studenta>=prosjek)
			niz[i]=prosjek_studenta;
		suma=0;
	}
	max=0;
	i=0;
	/*Trazimo najveci prosjek*/
	while(i<=vel){
		if(niz[i]>max){
			max=niz[i];
			zapamti1=i;
		}
		i++;
	}
	i=0;
	/*Provjeravmo da li ima jos neki student sa istim prosjekom*/
	while(i<=vel){
		if(fabs(niz[i]-niz[zapamti1])<EPSILON){
			/*Ako ima, provjeravamo cije je prezime i ime ipred po leksikografskom redoslijedu*/
			zapamti1=provjera_imena(s,zapamti1,i);
		}
		i++;
	}
	niz[zapamti1]=0;
	max=0;
	i=0;
	while(i<=vel){
		if(niz[i]>max){
			max=niz[i];
			zapamti2=i;
		}
		i++;
	}
	i=0;
	while(i<=vel){
		if(fabs(niz[i]-niz[zapamti2])<EPSILON){
			zapamti2=provjera_imena(s,zapamti2,i);
		}
		i++;
	}
	max=0;
	i=0;
	niz[zapamti2]=0;
	while(i<=vel){
		if(niz[i]>max){
			max=niz[i];
			zapamti3=i;
		}
		i++;
	}
	i=0;
	while(i<=vel){
		if(fabs(niz[i]-niz[zapamti3])<EPSILON){
			zapamti3=provjera_imena(s,zapamti3,i);
		}
		i++;
	}
	niz[zapamti3]=0;
	if(vel>=3){
		printf("\n%s %s",s[zapamti1].prezime,s[zapamti1].ime);
		printf("\n%s %s",s[zapamti2].prezime,s[zapamti2].ime);
		printf("\n%s %s",s[zapamti3].prezime,s[zapamti3].ime);
	}
	if(vel==2){
		printf("\n%s %s",s[zapamti1].prezime,s[zapamti1].ime);
		printf("\n%s %s",s[zapamti2].prezime,s[zapamti2].ime);
	}
	if(vel==1)
		printf("\n%s %s",s[zapamti1].prezime,s[zapamti1].ime);
	
	return vel;
}
int main() {
	int i;
	float vel;
	struct Student studenti[1000];
	scanf("%s %s",studenti[0].ime,studenti[0].prezime);
	for(i=0; i<29; i++)
		scanf("%d",&studenti[0].ocjene[i]);
	studenti[0].br_ocjena=30;
	vel=genijalci(studenti,1,10);
	printf("%.2f",vel);
	return 0;
}

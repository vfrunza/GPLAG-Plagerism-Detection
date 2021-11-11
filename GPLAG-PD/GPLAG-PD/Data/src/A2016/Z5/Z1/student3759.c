#include <stdio.h>
#include <string.h>

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

void unesi(char niz[], int velicina){
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	int i=0;
	while(i<velicina-1 && znak!='\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

int poredba(char *Student1, char *Student2){
	char *pok1;
	char *pok2;
	//char *pok3;
	pok1=&Student1[0];
	pok2=&Student2[0];
	/*	pok3=pok1;
	while(*pok3!='\0'){
		printf("%c", *pok3);
		pok3++;
	}*/
	while(*pok1!='\0' && *pok2!='\0'){
		if(*pok1<*pok2) return 1;
		if(*pok1>*pok2) return -1;
		pok1++;
		pok2++;
	}
	return 69;	
}

int genijalci(struct Student studenti[], int brojSTUD, double prosjek){
	
	int i, j, k, Max, Max2=20, Max3=20,uslov=0, poredbaPOVRATprez, poredbaPOVRATime;
	double prosjekSTUD[150]={0};
	char *pokPRVI;
	char *pokDRUGI;
	char *pokTRECI;
	
	for(i=0;i<brojSTUD;i++){
		uslov=0;//reset uslova
		//printf("%s, %s, %d\n", studenti[i].ime, studenti[i].prezime, studenti[i].br_ocjena);
		for(j=0;j<studenti[i].br_ocjena;j++){
			//manje-jednako pet
			if(studenti[i].ocjene[j]<=5){
				prosjekSTUD[i]=5;
				uslov=1;
				break;
			}
			prosjekSTUD[i]=prosjekSTUD[i]+studenti[i].ocjene[j];
			
		}
			if(uslov==1) prosjekSTUD[i]=5;
			else{
				prosjekSTUD[i]=prosjekSTUD[i]/studenti[i].br_ocjena;
			}
		//printf("Prosjek od %s: %f", studenti[i].ime, prosjekSTUD[i]);
	}
	j=0;
	for(i=0;i<brojSTUD;i++){
		if(prosjekSTUD[i]<prosjek || prosjekSTUD[i]==5){
			for(j=i;j<brojSTUD-1;j++){
				studenti[j]=studenti[j+1];
				prosjekSTUD[j]=prosjekSTUD[j+1];
			}
			i--;
			brojSTUD--;
		}
	}
	//pronalazak najboljih:
	for(i=0;i<brojSTUD;i++){
		if(prosjekSTUD[i]>prosjekSTUD[i+1]){
			Max=i;
		}
		else if(prosjekSTUD[i]==prosjekSTUD[i+1]){
		
		poredbaPOVRATprez=poredba(&studenti[i].prezime, &studenti[i+1].prezime);
		if(poredbaPOVRATprez==1){
			Max=i;
		}
		else if(poredbaPOVRATprez==-1){
			Max=i+1;
		}
		else if(poredbaPOVRATprez==69){
			poredbaPOVRATime=poredba(&studenti[i].ime, &studenti[i+1].ime);
			if(poredbaPOVRATime==1){
				Max=i;
			}
			else if(poredbaPOVRATime==-1){
				Max=i+1;
			}
		}
	
		}
	}
	
	for(i=0;i<brojSTUD;i++){
		if(prosjekSTUD[i]>prosjekSTUD[i+1] && i!=Max){
			Max2=i;
		}
		else if(prosjekSTUD[i]==prosjekSTUD[i+1]){
			poredbaPOVRATprez=poredba(&studenti[i].prezime, &studenti[i].prezime);
			if(poredbaPOVRATprez==1){
				Max2=i;
			}
			else if(poredbaPOVRATprez==-1){
				Max2=i+1;
			}
			else if(poredbaPOVRATprez==69){
				poredbaPOVRATime=poredba(&studenti[i].ime, &studenti[i].ime);
				if(poredbaPOVRATime==1){
					Max2=i;
				}
				else if(poredbaPOVRATime==-1){
					Max2=i+1;
				}
			}
		}
	}
	
	for(i=0;i<brojSTUD;i++){
		if(prosjekSTUD[i]>prosjekSTUD[i+1] && i!=Max && i!=Max2){
			Max3=i;
		}
		else if(prosjekSTUD[i]==prosjekSTUD[i+1]){
			poredbaPOVRATprez=poredba(&studenti[i].prezime, &studenti[i+1].prezime);
			if(poredbaPOVRATprez==1){
				Max3=i;
			}
			else if(poredbaPOVRATprez==-1){
				Max3=i+1;
			}
			else if(poredbaPOVRATprez==69){
				poredbaPOVRATime=poredba(&studenti[i].ime, &studenti[i].ime);
				if(poredbaPOVRATime==1){
					Max3=i;
				}
				else if(poredbaPOVRATime==-1){
					Max3=i+1;
				}
			}
		}
	}
/*	pokPRVI=&studenti[Max].prezime[0];
	while(*pokPRVI!='\0'){
		printf("%c", *pokPRVI);
		pokPRVI++;
	}printf(" ");
	pokPRVI=&studenti[Max].ime[0];
	while(*pokPRVI!='\0'){
		printf("%c", *pokPRVI);
		pokPRVI++;
	}printf("\n");
	pokDRUGI=&studenti[Max2].prezime[0];
	while(*pokDRUGI!='\0'){
		printf("%c", *pokDRUGI);
		pokDRUGI++;
	}printf(" ");
	pokDRUGI=&studenti[Max2].ime[0];
	while(*pokDRUGI!='\0'){
		printf("%c", *pokDRUGI);
		pokDRUGI++;
	}printf("\n");
	pokTRECI=&studenti[Max3].prezime[0];
	while(*pokTRECI!='\0'){
		printf("%c", *pokTRECI);
		pokTRECI++;
	}printf(" ");
	pokTRECI=&studenti[Max3].ime[0];
	while(*pokTRECI!='\0'){
		printf("%c", *pokTRECI);
		pokTRECI++;
	}printf("\n");
	//printf("%s %s\n", studenti[Max3].prezime, studenti[Max3].ime);*/
/*	printf("%s",studenti[Max].prezime);printf(" %s\n", studenti[Max].ime);
	if(Max2!=20)printf("%s", studenti[Max2].prezime);printf(" %s\n", studenti[Max2].ime);
	if(Max3!=20)printf("%s", studenti[Max3].prezime);printf(" %s\n", studenti[Max3].ime);
	//for(i=0;i<sizeof(studenti[Max].prezime))
	/*printf("%s %s\n", studenti[Max].prezime, studenti[Max].ime);
	printf("%s %s\n", studenti[Max2].prezime, studenti[Max2].ime);
	printf("%s %s\n", studenti[Max3].prezime, studenti[Max3].ime);

	printf("\nINDEX najboljeg: %d", Max);
	printf("\nINDEX drugog: %d", Max2);
	printf("\nINDEX treceg: %d", Max3);
	printf("\nNAJBOLJI: %s", studenti[Max].ime);
	printf("\nDRUGI: %s", studenti[Max2].ime);
	printf("\nTRECI: %s", studenti[Max3].ime);*/
	return brojSTUD;
}


int main() {
	int i, k, brojSTUD=0;
	double prosjek;
	struct Student studenti[100];
	
	for(i=0;i<100;i++){
		printf("Unesite ime %d. studenta: ", i+1);
		unesi(studenti[i].ime, 20);
		
		printf("Unesite prezime %d. studenta: ", i+1);
		unesi(studenti[i].prezime, 20);
		printf("Unesite broj ocjena od '%s': ", studenti[i].ime);
		scanf("%d", &studenti[i].br_ocjena);
		
		printf("Unesite ocjene od '%s':  ", studenti[i].ime);
			for(k=0;k<studenti[i].br_ocjena;k++){
				scanf("%d", &studenti[i].ocjene[k]);
			}
		brojSTUD++;
		
		}
	printf("Unesite prosjek za funkciju 'genijalci': ");
	scanf("%lf", &prosjek);
	k=genijalci(studenti, brojSTUD, prosjek);
	printf("\nBROJSTD:%d", genijalci(studenti, brojSTUD, prosjek));
	/*for(i=0;i<k;i++){
		printf("\n%s %s %d", studenti[i].prezime, studenti[i].ime, studenti[i].br_ocjena);
	}*/
	return 0;
}

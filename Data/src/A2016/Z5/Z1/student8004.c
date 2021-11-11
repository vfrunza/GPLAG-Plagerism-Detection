#include <stdio.h>
#include <string.h>
#define epsilon 0.00001
void unesi(char* niz,int vel){
	int i=0;
	char znak=getchar();
	if(znak=='\n')
		znak=getchar();
	while(i<vel-1 && znak!='\0'){
		niz[i++]=znak;
		znak=getchar();
	}
	niz[i]='\0';
}
struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

int genijalci(struct Student *studenti,int vel,float prosjek){
	int i,j,suma_ocjena=0,logicki_prosjek,broj_studenta[3]={0};
	float pojedinacni_prosjek=5.0,max[3]={0};
	//trazenje prosjek studenta pojedinacno
	for(i=0;i<vel;i++){
		suma_ocjena=0;
		logicki_prosjek=1;
		if(studenti[i].br_ocjena==0){
			pojedinacni_prosjek=5.0;
			logicki_prosjek=0;
			
		}
		for(j=0;j<studenti[i].br_ocjena;j++){
			if(studenti[i].ocjene[j]==5){
				logicki_prosjek=0;
				pojedinacni_prosjek=5.0;
				break;
			}
			else
			suma_ocjena+=studenti[i].ocjene[j];
		}
		if(logicki_prosjek)
		pojedinacni_prosjek=(float)suma_ocjena/studenti[i].br_ocjena;
		//izbacivanje iz niza
		if(pojedinacni_prosjek<prosjek){
			for(j=i;j<vel-1;j++){
				studenti[j]=studenti[j+1];
			}
			
			vel--;
			i--;
			continue;
			}
		//trazenje najboljih/maximalnih u nizu i leksikografsko poredjenje po potrebi
		if(pojedinacni_prosjek>max[0] || (pojedinacni_prosjek==max[0] && strcmp(studenti[i].prezime,studenti[broj_studenta[0]].prezime)<0)||(pojedinacni_prosjek==max[0] && strcmp(studenti[i].prezime,studenti[broj_studenta[0]].prezime)==0 && strcmp(studenti[i].ime,studenti[broj_studenta[0]].ime)<0)){
			max[2]=max[1];
			max[1]=max[0];
			max[0]=pojedinacni_prosjek;
			broj_studenta[2]=broj_studenta[1];
			broj_studenta[1]=broj_studenta[0];
			broj_studenta[0]=i;
		}
		else if(pojedinacni_prosjek>max[1] || (pojedinacni_prosjek==max[1] && strcmp(studenti[i].prezime,studenti[broj_studenta[1]].prezime)<0)||(pojedinacni_prosjek==max[1] && strcmp(studenti[i].prezime,studenti[broj_studenta[1]].prezime)==0 && strcmp(studenti[i].ime,studenti[broj_studenta[1]].ime)<0)){
			max[2]=max[1];
			max[1]=pojedinacni_prosjek;
			broj_studenta[2]=broj_studenta[1];
			broj_studenta[1]=i;
		}
		else if(pojedinacni_prosjek>max[2] || (pojedinacni_prosjek==max[2] && strcmp(studenti[i].prezime,studenti[broj_studenta[2]].prezime)<0)||(pojedinacni_prosjek==max[2] && strcmp(studenti[i].prezime,studenti[broj_studenta[2]].prezime)==0 && strcmp(studenti[i].ime,studenti[broj_studenta[2]].ime)<0)){
			max[2]=pojedinacni_prosjek;
			broj_studenta[2]=i;
	
		}
		}
		//ispis najboljih
		if(max[0]!=0) printf("%s %s\n",studenti[broj_studenta[0]].prezime,studenti[broj_studenta[0]].ime);
		if(max[1]!=0) printf("%s %s\n",studenti[broj_studenta[1]].prezime,studenti[broj_studenta[1]].ime);
		if(max[2]!=0) printf("%s %s\n",studenti[broj_studenta[2]].prezime,studenti[broj_studenta[2]].ime);
	return vel;
}

int main() {
	struct Student studenti[100];
	int i=0,prekid;
	do{
		printf("Unesite ime i prezime studenta %d: ",i+1);
		unesi(studenti[i].ime,20);
		unesi(studenti[i].prezime,20);
		i++;
		printf("Ako ste zavrsili sa unosom studenata pritisnite 0, ako ne onda 1.");
		scanf("%d",&prekid);
	}while(i<100 && prekid);
	return 0;
}

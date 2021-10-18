#include <stdio.h>


struct Student {
char ime[20], prezime[20];
int ocjene[50];
int br_ocjena;
};


int strcmp (char *a1, char *a2){
	int i=0;
	while(a1[i]!='\0' || a2[i]!='\0'){
	    if(a1[i]<a2[i]){
	        return 0;
	    }
	    if(a1[i]>a2[i]){
	        return 1;
	    }
	    if(a1[i]=='\0' && a2[i]!='\0'){
	        return 0;
	    }
	    if(a2[i]=='\0' && a2[i]!='\0'){
	        return 1;
	    }
	    i++;
	}
	return -1;
}


int genijalci(struct Student student[],int broj_studenata, float prosjek){
	int i,j,k,l,m;
	float prosjek_studenta[30];
	for(i=0;i<broj_studenata;i++){
		prosjek_studenta[i]=0;
		for(j=0;j<student[i].br_ocjena;j++){
			prosjek_studenta[i]+=student[i].ocjene[j];
			if(student[i].ocjene[j]==5){
				prosjek_studenta[i]=5;
				break;
			}
		}
		if(prosjek_studenta[i]>5){
			prosjek_studenta[i]/=student[i].br_ocjena;
		}
		if(prosjek_studenta[i]<prosjek){
			for(k=i;k<broj_studenata-1;k++){
				
				m=0;
				while(student[k+1].ime[m]!='\0'){
					student[k].ime[m]=student[k+1].ime[m];
					m++;
				}
				student[k].ime[m]='\0';
				
				m=0;
				while(student[k+1].prezime[m]!='\0'){
					student[k].prezime[m]=student[k+1].prezime[m];
					m++;
				}
				student[k].prezime[m]='\0';
				
				student[k].br_ocjena=student[k+1].br_ocjena;
				for(l=0;l<student[k+1].br_ocjena;l++){
					student[k].ocjene[l]=student[k+1].ocjene[l];
				}
			}
			broj_studenata--;
			i--;
		}
	}

	for(i=0;i<broj_studenata;i++){
		prosjek_studenta[i]=0;
		for(j=0;j<student[i].br_ocjena;j++){
			prosjek_studenta[i]+=student[i].ocjene[j];
		}
		prosjek_studenta[i]/=student[i].br_ocjena;
	}
	
	
	float max;
	for(j=0;j<3;j++){
		max=0;
		for(i=0;i<broj_studenata;i++){
			if(prosjek_studenta[i]>max){
				max=prosjek_studenta[i];
			}
		}
		for(i=0;i<broj_studenata;i++){
			if(prosjek_studenta[i]==max && prosjek_studenta[i]>=prosjek){
				printf("%s %s\n",student[i].prezime,student[i].ime);
				prosjek_studenta[i]=0;
				break;
			}
		} 
		
		
		
	}
	return broj_studenata;
	
}

int main() {
	
	float prosjek=6.5;
	int preostali;
	int broj_studenata=5;
	struct Student studenti[5] ={
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Pero", "Peric", { 8,8,8,8,7}, 5}, 
	{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Fata", "Fatic", { 7,7,7,8,8}, 5},
	};
	broj_studenata=genijalci(studenti,broj_studenata,prosjek);
	printf("\nBroj studenata: %d",broj_studenata);
	return 0;
}

#include <stdio.h>
#include <string.h>
#define epsilon 0.0001

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

float prosjek_svih_studenata(int niz[], int vel) {
	float prosjek_svih=0.0;
	int i;
	float suma=0;
	for(i=0;i<vel;i++) {
		if(niz[i]==5 || vel==0) return 5.0;
		suma+=niz[i];
		prosjek_svih=suma/vel;
	}
	return prosjek_svih;
}

int uporedi(char* s1, char* s2) {
	if(strcmp(s1,s2)==0) return 0;
	if(strcmp(s1,s2)<0) return -1;
	if(strcmp(s1,s2)>0) return 1;
	while(*s1!='\0' && *s2!='\0') {
		if(*s1<*s2) return -1;
		if(*s1>*s2) return 1;
		s1++;
		s2++;
	}
	if(*s1!='\0') return 1;
	if(*s2!='\0') return -1;
	return 0;
}
 int redoslijed(struct Student prvi, struct Student drugi) {
	float prosjek1=prosjek_svih_studenata(prvi.ocjene,prvi.br_ocjena);
	float prosjek2=prosjek_svih_studenata(drugi.ocjene,drugi.br_ocjena);
		if(prosjek1>prosjek2) return 1;
		else if(prosjek1<prosjek2) return 0;
		
		if(uporedi(prvi.prezime,drugi.prezime)==-1) return 1;
		else if(uporedi(prvi.prezime,drugi.prezime)==1) return 0;
		
		if(uporedi(prvi.ime,drugi.ime)==-1) return 1;
		else if(uporedi(prvi.ime,drugi.ime)==1) return 0;
		else return 1;
}

int genijalci(struct Student niz[], int vel, float prosjekk) {
	int i, j, index1, index2, index3, indexmin=0;
	double temp_prosjek, min=10;
	for(i=0;i<vel;i++) {
		if(prosjekk-prosjek_svih_studenata(niz[i].ocjene,niz[i].br_ocjena)>epsilon) {
              for(j=i;j<vel-1;j++) {
			  niz[j]=niz[j+1];
			}
			vel--;
			i--;
		}
	}
	for(i=0;i<vel;i++) {
		temp_prosjek=prosjek_svih_studenata(niz[i].ocjene, niz[i].br_ocjena);
		if(min-prosjek_svih_studenata(niz[i].ocjene,niz[i].br_ocjena)>epsilon)
		{
			min=temp_prosjek;
			indexmin=i;
		}
	}
		if(vel==0) return 0;
		if(vel==1) goto jedan;
		if(vel>1) goto dva;
		
		jedan:
		index1=indexmin;
		printf("\n%s %s", niz[index1].prezime,niz[index1].ime);
		return vel;
		
		dva:
		index1=indexmin;
		for(i=0;i<vel;i++) {
			if(redoslijed(niz[i],niz[index1]))
			index1=i;
		}
		index2=indexmin;
		for(i=0;i<vel;i++) {
			if(i==index1) continue;
			if(redoslijed(niz[i],niz[index2]))
			index2=i;
		}
		printf("\n%s %s",niz[index1].prezime,niz[index1].ime);
		printf("\n%s %s",niz[index2].prezime,niz[index2].ime);
		
		if(vel>2) {
			index3=indexmin;
			for(i=0;i<vel;i++) {
				if(i==index1 || i==index2) continue;
				if(redoslijed(niz[i],niz[index3]))
				index3=i;
			}
			printf("\n%s %s",niz[index3].prezime,niz[index3].ime);
		}
		return vel;
}

int main() {
	struct Student studenti[] = {
		{"Ajla", "Smajic", {7, 9, 10, 10}, 4},
		{"Sajra", "Gujic", {6, 8, 9}, 3},
		{"Imad", "Fazlinovic", {7, 9, 5, 8}, 4}
	};
	int i;
  int vel=genijalci(studenti,4,7.7);
  printf("Vel:%dStudenti:",vel);
  for(i=0;i<vel;i++);
  printf("%s %s", studenti[i].prezime,studenti[i].ime);
	return 0;
}

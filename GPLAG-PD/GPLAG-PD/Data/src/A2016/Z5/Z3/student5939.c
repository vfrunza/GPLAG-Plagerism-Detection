#include <stdio.h>
#include <string.h>
#define KAPACITET 200

typedef struct Vrijeme {
	int sati, minute, sekunde;
} Vrijeme;

typedef struct Cas {
	char predmet[10];
	int dan_u_sedmici;
	struct Vrijeme pocetak, kraj;
} Cas;

void unos (char niz[], int vel) {
	
	int i=0;
	int c=0;
	char simbol = getchar();
	
	if (simbol == "\n")
	simbol=getchar();
	
	vel=vel-1;
	while (simbol != '\n' && i<vel) {
		
		niz[i]=simbol;
		i++;
		simbol=getchar();
	}
	
	niz[i] = '\0';
	
	if (simbol != '\n') {
		while (c= getchar() != '\n' && c != EOF) {}
	}
}

int vrijeme (Vrijeme v1, Vrijeme v2) {
	
	int s2=v2.sati*3600 + v2.minute*60 + v2.sekunde;
	int s1=v1.sati*3600 + v1.minute*60 + v1.sekunde;
	
	if (s1==s2)
	return 0;
	else if (s1>s2)
	return 1;
	else if (s1<s2)
	return -1;
	
	return -2;
}

int preklapanje (struct Cas raspored[], int broj_casova, struct Cas cas) {
 int i=0;
 int status = 0;

 
 
int uslov1=0;
int uslov2=0;
int uslov3=0;


for (i=0; i<broj_casova; i++) {
	uslov1=vrijeme(raspored[i].kraj, cas.pocetak) ==1;
	uslov2=vrijeme (cas.kraj, raspored[i].pocetak)==1;
	uslov3=cas.dan_u_sedmici==raspored[i].dan_u_sedmici;
	
	if (uslov1 && uslov2 && uslov1) {
		status =1;
		break;
	}
	return status;
}
}

int dodaj_cas (struct Cas raspored[], int broj_casova, const char* predmet, int trajanje) {
	struct Cas cas;
	int status=0;
	int status1=0;
	int i=0;
	int j=0;
	int k=0;
	cas.pocetak.sekunde=0;
	
	if(trajanje >10)
	return 0;
	
	for (i=1; i<7 && status==0; i++) {
		cas.dan_u_sedmici=i;
		status1=0;
		
		for (j=9; j<19 && status==0 && status1==0; j++)
		cas.pocetak.sati=j;
		cas.kraj.sati=cas.kraj.sati + trajanje;
		cas.kraj=cas.pocetak;
		
		for (k=0; k<60 && status==0 && status1==0; k++) {
			cas.pocetak.minute==k;
			cas.kraj.sati=cas.kraj.sati+trajanje;
			
			
			if(cas.kraj.sati >= 19) {
				if(cas.kraj.minute > 0 && cas.kraj.sati ==19)
				status1=1;
			}
			
			else if (cas.kraj.sati >19)
			status1=1;
		}
	}
}
int main() {
	printf("Zadaća 5, Zadatak 3");
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void kompresuj(char ime_ulazne[],char ime_izlazne[])
{
	FILE *ulazna, *izlazna;
	int broj_rijeci=0,brojac=0,razmak=1,broj_ponavljanja[1001]= {0},i,indeksi_maskimalnih[10],j,max=0,temp;
	char razlicite_rijeci[1001][10],znak,neka_rijec[20];
	char kopirani_niz[1001];
	if((ulazna=fopen(ime_ulazne,"r")) == NULL) {
		printf("Greska pri otvaranju datoteke %s",ime_ulazne);
		exit(1);
	}
	while ((znak=fgetc(ulazna)) != EOF) {
		if(znak==' ' || znak=='\n'  || znak=='\t' || znak<'A' || (znak>'Z' && znak<'a') || znak>'z') {
			if(brojac>0 && brojac<10) {
				razlicite_rijeci[broj_rijeci-1][brojac] = 0;
				for(i=0; i<broj_rijeci-1; i++) {
					if(!strcmp(razlicite_rijeci[i],razlicite_rijeci[broj_rijeci-1])) {
						broj_ponavljanja[i]++;
						broj_rijeci--;
						break;
					}

				}
			}
			razmak=1;
			brojac=0;
		} else if (razmak && !brojac) {
			broj_rijeci++;
			broj_ponavljanja[broj_rijeci-1]=1;
			razmak=0;
		}
		if(!razmak) {
			if(brojac==10)
				continue;
			if(brojac==9) {
				for(i=0; i<10; i++)
					razlicite_rijeci[broj_rijeci-1][i]=0;
				brojac++;
				broj_rijeci--;
				continue;
			}
			razlicite_rijeci[broj_rijeci-1][brojac] = znak;
			brojac++;
		}
	}
	if(!razmak && brojac>0 && brojac<11) {
		razlicite_rijeci[broj_rijeci-1][brojac]=0;
		for(i=0; i<broj_rijeci-1; i++) {
			if(!strcmp(razlicite_rijeci[i],razlicite_rijeci[broj_rijeci-1])) {
				broj_ponavljanja[i]++;
				broj_rijeci--;
				break;
			}
		}
	}

	fclose(ulazna);
	brojac=0;
	for(i=0; i<broj_rijeci; i++) {
		kopirani_niz[i]=broj_ponavljanja[i];
	}
	/*Pravljenje tabele */
	for(i=0; i+brojac<10; i++) {
		for(j=0; j<broj_rijeci; j++) {
			if(kopirani_niz[j]>kopirani_niz[max])
				max=j;
		}
		indeksi_maskimalnih[i]=max;
		kopirani_niz[max]=-1;

		if(i) {
			if(indeksi_maskimalnih[i]==indeksi_maskimalnih[i-1]) {
				i--;
				brojac++;
			}
		}
	}
	/*Leksikografsko redanje*/
	for(j=0; j<i-1; j++) {
		for(brojac=j+1; brojac<i ; brojac++) {
			if(broj_ponavljanja[indeksi_maskimalnih[brojac]] == broj_ponavljanja[indeksi_maskimalnih[j]]) {
				if(strcmp(razlicite_rijeci[indeksi_maskimalnih[brojac]], razlicite_rijeci[indeksi_maskimalnih[j]])<0) {
					temp=indeksi_maskimalnih[j];
					indeksi_maskimalnih[j]=indeksi_maskimalnih[brojac];
					indeksi_maskimalnih[brojac]=temp;
				}
			}
		}
	}

	izlazna=fopen(ime_izlazne,"w");
	ulazna = fopen(ime_ulazne,"r");

	/*Upisivanje tabele*/
	for(brojac=0; brojac<i; brojac++) {
		fputs(razlicite_rijeci[indeksi_maskimalnih[brojac]],izlazna);
		fputs("\n",izlazna);
	}
	if(i<10)
		fputs("\n",izlazna);
	/*Kompresiranje*/
	brojac=0;
	razmak = 1;
	while ((znak=fgetc(ulazna)) != EOF) {
		if(znak==' ' || znak=='\n'  || znak=='\t' || znak<'A' || (znak>'Z' && znak<'a') || znak>'z' || brojac==10) {
			if(brojac>0 && brojac<10) {
				neka_rijec[brojac] = 0;
				for(i=0; i<broj_rijeci; i++) {
					if(!strcmp(neka_rijec,razlicite_rijeci[indeksi_maskimalnih[i]]))
						break;
				}
				if(i<broj_rijeci)
					fputc((20+i),izlazna);
				else if(i==broj_rijeci)
					fputs(neka_rijec,izlazna);
			} 
			else if(brojac==10) {
				fputs(neka_rijec,izlazna);
			}
			fputc(znak,izlazna);
			brojac=0;
			razmak=1;

		} 
		else if (razmak) {
			razmak=0;
		}
		if(!razmak) {
			neka_rijec[brojac] = znak;
			brojac++;
			if(brojac==10)
				neka_rijec[10]=0;
		}
	}
	if(brojac>0 && brojac<10) {
		neka_rijec[brojac] = 0;
		for(i=0; i<broj_rijeci; i++) {
			if(!strcmp(neka_rijec,razlicite_rijeci[indeksi_maskimalnih[i]]))
				break;
		}
		if(i<broj_rijeci)
			fputc((20+i),izlazna);
		else if(i==broj_rijeci)
			fputs(neka_rijec,izlazna);
	}
	else if(brojac==10)
		fputs(neka_rijec,izlazna);

	fclose(izlazna);
	fclose(ulazna);
	printf("Datoteka kompresovana.\n");
}

void dekompresuj(char ime_kompresovane[], char ime_originalne[])
{
	FILE *kompresovana, *originalna;
	int broj_rijeci=0,brojac=0,novi_red;
	char rijeci_zamjene[10][10],znak;
	if((kompresovana=fopen(ime_kompresovane,"r"))==NULL) {
		printf("Greska pri otvaranju kompresovane datoteke !");
		exit(1);
	}
	novi_red=0;
	while(((znak=fgetc(kompresovana)) !=EOF) && broj_rijeci<11) {
		if(znak=='\n' && novi_red) {
			broj_rijeci++;
			break;
		} else if(znak=='\n' && !novi_red) {
			novi_red=1;
			rijeci_zamjene[broj_rijeci][brojac]=0;
			brojac=0;
			broj_rijeci++;
			continue;
		}
		novi_red=0;
		rijeci_zamjene[broj_rijeci][brojac]=znak;
		brojac++;
	}
	originalna=fopen(ime_originalne,"w");
	while ((znak=fgetc(kompresovana)) != EOF) {
		if(znak>=20 && znak<=20+broj_rijeci-1) {
			fprintf(originalna,"%s",rijeci_zamjene[znak-20]);
		} else
			fprintf(originalna,"%c",znak);
	}

	fclose(originalna);
	fclose(kompresovana);
	printf("Datoteka dekompresovana.\n");
}

int main(){
	int ulaz;
	char ulazna[40],izlazna[40];
	do {
		printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
		scanf("%d",&ulaz);
		switch(ulaz) {
		case 1:
			printf("Unesite ime ulazne datoteke: ");
			scanf("%s",ulazna);
			printf("Unesite ime izlazne datoteke: ");
			scanf("%s",izlazna);
			kompresuj(ulazna,izlazna);
			break;
		case 2:
			printf("Unesite ime ulazne datoteke: ");
			scanf("%s",ulazna);
			printf("Unesite ime izlazne datoteke: ");
			scanf("%s",izlazna);
			dekompresuj(ulazna,izlazna);
			break;
		case 0:
			printf("\n");
			break;
		}
	} while(ulaz);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* UNOS STRINGA */

void unesi(char niz[], int velicina){
	char znak=getchar();
	int i=0;
	while(znak==' ')znak=getchar();
    while(znak=='\n')znak=getchar();
    while(i<velicina-1 && znak!='\n') {
        niz[i]=znak;
        i++;
        znak=getchar();
    }
    niz[i]='\0';
}

/* MIJENJA DVA STRINGA */

void zamjeni(char *rijec1, char *rijec2){
	int i;
	char temp;
	for(i=0;i<11;i++){
		temp=rijec1[i];
		rijec1[i]=rijec2[i];
		rijec2[i]=temp;
	}
}

/* KOMPRESUJE DATOTEKU UZ POSTOVANJE PRAVILA O KOMPRESOVANJU */

void kompresuj(char *imeulazne, char *imeizlazne){
	FILE* ulaz=fopen(imeulazne, "r");
	if(ulaz==NULL)return;
	FILE* izlaz=fopen(imeizlazne, "w");
	if(izlaz==NULL){
		fclose(ulaz);
		return;
	}
	int i;
	int brojrazl=0;
	char rijeci[1000][11];
	int koliko[1000];
	for(i=0;i<1000;i++){
		rijeci[i][0]='\0';
		koliko[i]=0;
	}
	char rijec[1000];
	int c;
	int j;
	int duzina=0;
	int tempint;
	/* PAMTI RAZLICITE RIJECI I CUVA BROJ NJIHOVIH PONAVLJANJA */
	do{
		c=fgetc(ulaz);
		if((c>='a' && c<='z')||(c>='A' && c<='Z')){
			if(duzina>9){
				duzina++;
			} else {
				rijec[duzina]=c;
				duzina++;
				rijec[duzina]='\0';
			}
		} else {
			if(duzina>1 && duzina<10){
				for(i=0;i<brojrazl;i++){
					if(strcmp(rijec, rijeci[i])==0){
						koliko[i]++;
						break;
					}
				}
				if(i==brojrazl){
					strcpy(rijeci[i], rijec);
					koliko[i]=1;
					brojrazl++;
				}
			}
			duzina=0;
			rijec[0]='\0';
		}
	}while(c!=EOF);
	/* SORTIRANJE RAZLICITIH RIJECI PO BROJU PONAVLJANJA UZ OCUVANJE LEKSIKOGRAFSKOG PORETKA */
	for(i=0;i<brojrazl;i++){
		for(j=i;j<brojrazl;j++){
			if(koliko[i]<koliko[j]){
				tempint=koliko[i];
				koliko[i]=koliko[j];
				koliko[j]=tempint;
				zamjeni(rijeci[i], rijeci[j]);
			} else if(koliko[i]==koliko[j]){
				if(strcmp(rijeci[i], rijeci[j])>0){
					tempint=koliko[i];
					koliko[i]=koliko[j];
					koliko[j]=tempint;
					zamjeni(rijeci[i], rijeci[j]);
				}
			}
		}
	}
	/* ISPIS PRVIH 10/9/8/7/6/5/4/3/2/1/0 NAJUCESTALIJIH RIJECI U DATOTEKU */ 
	for(i=0;i<brojrazl;i++){
		if(i<10)fprintf(izlaz, "%s\n", rijeci[i]);
	}
	if(brojrazl<10)fprintf(izlaz, "\n");
	fclose(ulaz);
	duzina=0;
	rijec[0]='\0';
	ulaz=fopen(imeulazne, "r");
	/* MJENJANJE NAJCESCIH RIJECI ODGOVARAJUCIM KARAKTERIMA TE POPUNJAVANJE DATOTEKE */
	do{
		c=fgetc(ulaz);
		if((c>='a' && c<='z')||(c>='A' && c<='Z')){
			if(duzina>9){
				duzina++;
				fprintf(izlaz, "%c", c);
			} else {
				rijec[duzina]=c;
				duzina++;
				rijec[duzina]='\0';
				if(duzina==10)fprintf(izlaz, "%s", rijec);
			}
			
		} else {
			if(duzina<10){
				for(i=0;i<brojrazl;i++){
					if(i<10 && strcmp(rijec, rijeci[i])==0){
						fprintf(izlaz, "%c", 20+i);
						break;
					}
				}
				if(i==brojrazl){
					fprintf(izlaz, "%s", rijec);
				}
			}
			if(c!=EOF)fprintf(izlaz, "%c", c);
			duzina=0;
			rijec[0]='\0';
		}
	}while(c!=EOF);
	printf("Datoteka kompresovana.\n");
	fclose(ulaz);
	fclose(izlaz);
}

/* DEKOMPRESUJE DATOTEKU UZ POSTOVANJE PRAVILA O DEKOMPRESOVANJU */

void dekompresuj(char *imeulazne, char *imeizlazne){
	FILE* ulaz=fopen(imeulazne, "r");
	if(ulaz==NULL)return;
	FILE* izlaz=fopen(imeizlazne, "w");
	if(izlaz==NULL){
		fclose(ulaz);
		return;
	}
	
	char top[10][10];
	int c;
	int duzina=0;
	int brojac=0;
	/* PRIDRUZIVANJE INDEKSA NAJCESCIM RIJECIMA */
	do{
		c=fgetc(ulaz);
		if(c==EOF)break;
		if(c!='\n'){
			top[brojac][duzina]=c;
			duzina++;
		} else {
			if(duzina==0){
				break;
			}
			top[brojac][duzina]='\0';
			brojac++;
			if(brojac==10)break;
			duzina=0;
		}
	}while(c!=EOF);
	/* ISPISIVANJE DEKOMPRESOVANIH KARAKTERA U DATOTEKU */
	do{
		c=fgetc(ulaz);
		if(c==EOF)break;
		if(c>=20 && c<=29){
			fprintf(izlaz, "%s", top[c-20]);
		} else {
			fprintf(izlaz, "%c", c);
		}
	}while(c!=EOF);
	
	fclose(ulaz);
	fclose(izlaz);
	printf("Datoteka dekompresovana.\n");
}

int main() {
	int a;
	char datoteka1[500]="gg";
	char datoteka2[500]="izlaz.txt";
	do{
		printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
		scanf("%d", &a);
		if(a==1){
			printf("Unesite ime ulazne datoteke: ");
			unesi(datoteka1, 500);
			printf("Unesite ime izlazne datoteke: ");
			unesi(datoteka2, 500);
			kompresuj(datoteka1, datoteka2);
		} if(a==2){
			printf("Unesite ime ulazne datoteke: ");
			unesi(datoteka1, 500);
			printf("Unesite ime izlazne datoteke: ");
			unesi(datoteka2, 500);
			dekompresuj(datoteka1, datoteka2);
		}
	}while(a);
	return 0;
}

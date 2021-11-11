#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Rijec{
	char ime[15];
	int count;
};

void unesi (char niz[], int velicina){
	char znak=getchar();
	int i=0;
	if(znak=='\n') znak=getchar();
	while(i<velicina-1 && znak!='\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

void kompresuj(char* ime_ulazne, char* ime_izlazne){
	FILE *ulaz;
	FILE* izlaz;
	char c;
	struct Rijec rijeci[1010], temp, novo;
	int i=0, j=0, x=0, istina=0, max, velicina=0, broj=0, m=0;
	ulaz=fopen(ime_ulazne, "r");
	if(ulaz==NULL){
			printf("Datoteka ne postoji!");
			exit(4);
	}
	izlaz=fopen(ime_izlazne, "w");
	if(izlaz==NULL){
			printf("Datoteka ne postoji!");
			exit(3);
	}
	do{
		if(i>=1001) break;
		j=0;
		c=fgetc(ulaz);
		rijeci[i].count=0;
		if((c>='a' && c<='z') || (c>='A' && c<='Z')){
			while(((c>='a' && c<='z') || (c>='A' && c<='Z')) && j<9){
				rijeci[i].ime[j]=c;
				j++;
				c=fgetc(ulaz);
			}
			rijeci[i].ime[j]='\0';
			
			if(((c>='a' && c<='z') || (c>='A' && c<='Z')) && j==9){
				i++;
				do{
					c=fgetc(ulaz);
				}while(((c>='a' && c<='z') || (c>='A' && c<='Z')) && c != EOF);
				continue;
			}
			rijeci[i].count++;
			for(j=0; j<i; j++){
				if(strcmp(rijeci[i].ime, rijeci[j].ime)==0){
					if(rijeci[j].count == 0) {
						i--;
						continue;
					}
					rijeci[j].count++;
					rijeci[i].count=0;
				}
			}
		}
		else{
			continue;
		}
		i++;
	}while(c != EOF);
	velicina=i;
	/*Selection sort*/
	for(i=0; i<velicina; i++){      
		max=i;
		for(j=i+1; j<velicina; j++){
			if(rijeci[j].count>rijeci[max].count) max=j;
			if((rijeci[j].count==rijeci[max].count) && strcmp(rijeci[j].ime, rijeci[max].ime)<0) max=j;
		}
		strcpy(temp.ime, rijeci[i].ime);
		strcpy(rijeci[i].ime, rijeci[max].ime);
		strcpy(rijeci[max].ime, temp.ime);
		temp.count=rijeci[i].count;
		rijeci[i].count=rijeci[max].count;
		rijeci[max].count=temp.count;
	}
	if(velicina>=10) j=10;
	else j=velicina;
	for(i=0; i<j; i++){
		if(rijeci[i].count==0) continue;
		fputs(rijeci[i].ime, izlaz);
		fputc('\n', izlaz);
		broj++;
	}
	if(broj<10) fputc('\n', izlaz);
	fseek(ulaz, 0, SEEK_SET);
	if(velicina>=10) m=10;
	else m=velicina;
	do{
		istina=0;
		j=0;
		c=fgetc(ulaz);
		if((c>='a' && c<='z') || (c>='A' && c<='Z')){
			while(((c>='a' && c<='z') || (c>='A' && c<='Z')) && j<9){
				novo.ime[j]=c;
				j++;
				c=fgetc(ulaz);
				if(c==EOF) break;
			}
			novo.ime[j]='\0';
			if(((c>='a' && c<='z') || (c>='A' && c<='Z')) && j==9){
				fputs(novo.ime, izlaz);
				fputc(c, izlaz);
				continue;
			}
			else{
				for(x=0; x<m; x++){
					if(strcmp(novo.ime, rijeci[x].ime)==0){
						fputc(20+x, izlaz);
						istina=1;
						break;
					}
				}
				if(istina==0) fputs(novo.ime, izlaz);
				if(c==EOF) break;
				fputc(c, izlaz);
			}
		}
		else{
			if(c==EOF) break;
			fputc(c, izlaz);
			continue;
		}
	}while(c != EOF);
	printf("Datoteka kompresovana.\n");
	fclose(ulaz);
	fclose(izlaz);
}

void dekompresuj(char* ime_izlazna, char* ime_normalna){
	FILE* izlazna;
	FILE* normalna;
	char c;
	struct Rijec rijeci[15];
	int i=0, j=0;
	izlazna=fopen(ime_izlazna, "r");
	if(izlazna==NULL){
		printf("Datoteka ne postoji!");
		exit(1);
	}
	normalna=fopen(ime_normalna, "w");
	if(normalna==NULL){
		printf("Datoteka ne postoji!");
		exit(2);
	}
	do{
		if(i>=11) break;
		if(j>=10) break;
		c=fgetc(izlazna);
		if(c==EOF) break;
		if(c=='\n'){
			if(j==0) break;
			rijeci[i].ime[j]='\0';
			if(i==9) break;
			j=0;
			i++;
			continue;
		}
		rijeci[i].ime[j++]=c;
	}while(c != EOF);
	
	do{
		c=fgetc(izlazna);
		if(c==EOF) break;
		if(c>=20 && c<=29){
			fputs(rijeci[c-20].ime, normalna);
		}
		else{
			fputc(c,normalna);
		}
	}while(c!=EOF);
	printf("Datoteka dekompresovana.\n");
	fclose(izlazna);
	fclose(normalna);
}

int main() {
	char ime_ulaz[50], ime_izlaz[50];
	int a;
	printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
	scanf("%d", &a);
	while(a != 0){
		if(a==1){
		printf("Unesite ime ulazne datoteke: ");
		unesi(ime_ulaz, 50);
		printf("Unesite ime izlazne datoteke: ");
		unesi(ime_izlaz, 50);
		kompresuj(ime_ulaz, ime_izlaz);
	}
	
		if(a==2){
			printf("Unesite ime ulazne datoteke: ");
			unesi(ime_ulaz, 50);
			printf("Unesite ime izlazne datoteke: ");
			unesi(ime_izlaz, 50);;
			dekompresuj(ime_ulaz, ime_izlaz);
		}
	printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
	scanf("%d", &a);
	}
	
	return 0;
}

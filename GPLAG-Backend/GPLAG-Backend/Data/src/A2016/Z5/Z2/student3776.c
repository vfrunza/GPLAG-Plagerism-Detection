#include <stdio.h>

void unesi(char niz[],int velicina){
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

int uporedi(char* s1,char* s2){
	while(*s1 != '\0' && *s2 != '\0' ){
		if(*s1<*s2) return -1;
		if(*s1>*s2) return 1;
		s1++;
		s2++;
	}
	if(*s1 != '\0') return 1;
	if(*s2 != '\0') return -1;
	return 0;
}
void kompresuj(char* dat1, char *dat2){
	FILE *ulaz=fopen(dat1,"r");
	FILE *pomocna=fopen(dat1,"r");
	FILE *izlaz=fopen(dat2,"w");
	if(!ulaz){
		printf("Greska pri otvaranju ulazne datoteke");
		return;
	}
	if(!izlaz){
		printf("Greska pri otvaranju izlazne datoteke");
		return;
	}
	char kompresne[1000][1000]={0},rijec[1000],karakter=fgetc(ulaz);
	int brojac[1000]={0},i,broj_rijeci=0,k=0,ima,j,kraj=10;
	while(karakter!=EOF){
		k=0;
		while(karakter>='A' && karakter<='Z' || karakter>='a' && karakter<='z'){
			rijec[k]=karakter;
			karakter=fgetc(ulaz);
			k++;
		}
		rijec[k]='\0';
		if(k<10 && k>0){
			ima=0;
			for(j=0;j<broj_rijeci;j++){
				if(uporedi(kompresne[j],rijec)==0){
					ima=1;
					brojac[j]++;
					break;
				}
			}
			if(ima!=1){
				char *q=kompresne[broj_rijeci],*p=rijec;
				while(*q++=*p++);
				brojac[broj_rijeci]=1;
				broj_rijeci++;
			}
		}
		karakter=fgetc(ulaz);
	}
	for(i=0;i<broj_rijeci;i++){
		for(j=i+1;j<broj_rijeci;j++){
			if(uporedi(kompresne[i],kompresne[j])==1 && brojac[j]==brojac[i] || brojac[j]>brojac[i]){
				int zamjena=brojac[j];
				brojac[j]=brojac[i];
				brojac[i]=zamjena;
				char temp[100],*q,*p,*pom;
				q=kompresne[i];
				p=kompresne[j];
				pom=temp;
				while(*pom++=*q++);
				q=kompresne[i];
				while(*q++=*p++);
				p=kompresne[j];
				pom=temp;
				while(*p++=*pom++);
			}
		}
	};
	if(broj_rijeci<10) kraj=broj_rijeci;
	for(i=0;i<kraj;i++){
		fputs(kompresne[i],izlaz);
		fputc('\n',izlaz);
	}
	fputc('\n',izlaz);
	char c=fgetc(pomocna);
	while(c!=EOF){
		k=0;
		while(c>='A' && c<='Z' || c>='a' && c<='z'){
			rijec[k]=c;
			c=fgetc(pomocna);
			k++;
		}
		rijec[k]='\0';
		int jest=0;
		if(k>0 && k<10)
		for(j=0;j<kraj;j++)
		if(uporedi(kompresne[j],rijec)==0){
			fputc(j+20,izlaz);
			fputc(c,izlaz);
			jest=1;
			break;
		}
		if(!jest){
			fputs(rijec,izlaz);
			fputc(c,izlaz);
		}
		c=fgetc(pomocna);
	}
	printf("Datoteka kompresovana. \n");
	fclose(ulaz); fclose(pomocna); fclose(izlaz);
}
void dekompresuj(char*dat1, char*dat2 ){
	FILE *ulaz=fopen(dat1, "r");
	FILE *pomocna=fopen(dat1,"r");
	FILE *izlaz=fopen(dat2, "w");
	if(!ulaz){
		printf("Greska pri otvaranju ulazne datoteke");
		return;
	}
	if(!izlaz){
		printf("Greska pri otvaranju izlazne datoteke");
		return;
	}
	char kompresne[1000][1000]={0},rijec[1000],karakter=fgetc(ulaz),kar;
	int broj_rijeci=0,k,pom_brojac=0,iste=0,j;
	while(karakter!=EOF){
		k=0;
		iste=0;
		while(karakter>'A' && karakter<='Z' || karakter>='a' && karakter<='z'){
			rijec[k]=karakter;
			karakter=fgetc(ulaz);
			k++;
		}
		rijec[k]='\0';
		if(k>0 && k<10){
			char *q=kompresne[broj_rijeci],*p=rijec;
			while(*q++=*p++);
			for(j=0;j<broj_rijeci;j++)
			if(!uporedi(kompresne[j],rijec)){
				iste=1;
				break;
			}
			if(iste)
			break;
			broj_rijeci++;
		}
		karakter=fgetc(ulaz);
}
kar=fgetc(pomocna);
while(kar!=EOF){
	if(kar=='\n') pom_brojac++;
	if(pom_brojac==broj_rijeci) break;
	kar=fgetc(pomocna);
}
kar=fgetc(pomocna);
while(kar!=EOF){
	if(kar>=20 && kar<=30){
		fputs(kompresne[kar-20],izlaz);
		kar=fgetc(pomocna);
		continue;
	}
	fputc(kar,izlaz);
	kar=fgetc(pomocna);
}
printf("Datoteka dekompresovana. \n");
fclose(ulaz); fclose(izlaz); fclose(pomocna);
}
int main() {
	int n;
	char ulazna[1000], izlazna[1000];
	do{
		printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
		scanf("%d", &n);
		if(n==1) {
			printf("Unesite ime ulazne datoteke: ");
			unesi(ulazna,40);
			printf("Unesite ime izlazne datoteke: ");
			unesi(izlazna,40);
			kompresuj(ulazna,izlazna);
		}
		if(n==2){
			printf("Unesite ime ulazne datoteke: ");
			unesi(ulazna,40);
			printf("Unesite ime izlazne datoteke: ");
			unesi(izlazna,40);
			dekompresuj(ulazna,izlazna);
		}
	}while(n!=0);
	
	return 0;
}

#include <stdio.h>
#include <ctype.h>
#include <string.h>
//Unos stringa
void unesi (char niz[], int velicina){
	char znak=getchar();
	if (znak=='\n') znak=getchar();
	int i=0;
	while (i<velicina-1 && znak!='\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}
//Funkcija vraca 1 ako je znak koji je primila slovo
	int slovo(int ch){
		if ((ch>='a' && ch<='z')||(ch>='A' && ch<='Z'))
			return 1;
		return 0;	
	}
//funkcija primi dva stringa i zamijeni ih	
	void kompresuj(char * naziv,char* naziv1){
		FILE *ulaz=fopen(naziv,"r");
		FILE *ulazpom=fopen(naziv,"r");
		FILE *izlaz=fopen(naziv1,"w");
		char rijeci[1000][1000]={{0}},novired,c,pomoc[100];
		int brojac[1000]={0},kontrola;
		int i,broj_rijeci=0,j,kraj,ima,temp;
		char rijec[100000],znak,znk;
		int duzina=0;
		znak=fgetc(ulaz);
		while(znak!=EOF){
			duzina=0;
			while (slovo(znak)){
				rijec[duzina++]=znak;
				znak=fgetc(ulaz);
			}
		rijec[duzina]='\0';
		if (duzina<10 && duzina!=0){
			ima=0;
			for (j=0;j<broj_rijeci;j++){
				if (strcmp(rijeci[j],rijec)==0){
					ima=1;
					brojac[j]++;
					break;
				}
			}
			if (ima!=1){
				strcpy(rijeci[broj_rijeci],rijec);
				brojac[broj_rijeci++]=1;
			}
		}
		znak=fgetc(ulaz);
		}
		//Sortiranje rijeci po broju ponavljanja i leksikografski
		for (i=0;i<broj_rijeci;i++){
			for (j=i+1;j<broj_rijeci;j++){
				if (brojac[j]>brojac[i] || (brojac[j]==brojac[i] && strcmp(rijeci[i],rijeci[j])==1)){
					temp=brojac[j];
					brojac[j]=brojac[i];
					brojac[i]=temp;
					strcpy(pomoc,rijeci[i]);
					strcpy(rijeci[i],rijeci[j]);
					strcpy(rijeci[j],pomoc);
				}
			}
		}
		kraj=10;
		novired='\n';
		if (broj_rijeci<10) kraj=broj_rijeci;
		for (i=0;i<kraj;i++){
			fputs(rijeci[i],izlaz);
			fputc(novired,izlaz);
		}
		
		c=fgetc(ulazpom);
		while(c!=EOF){
			duzina=0;
			while (slovo(c)){
				rijec[duzina++]=c;
				c=fgetc(ulazpom);
			}
			rijec[duzina]='\0';
			
			kontrola=0;
			if (duzina<10 && duzina!=0){
				for (j=0;j<kraj;j++){
					if (strcmp(rijeci[j],rijec)==0){
						znk=j+20;
						kontrola=1;
						fputc(znk,izlaz);
						fputc(c,izlaz);
						break;
					}
				}
			}
			if (kontrola==0){
				char *r=rijec;
				while(*r!='\0'){
					fputc(*r,izlaz);
					r++;
				}
				fputc(c,izlaz);
			}
			c=fgetc(ulazpom);
		}
		printf("Datoteka kompresovana.\n");
		fclose(ulaz);
		fclose(ulazpom);
		fclose(izlaz);
	}
	
	
	void dekompresuj(char*naziv,char*naziv1){
		FILE *ulaz=fopen(naziv,"r");
		FILE *ulazpom=fopen(naziv,"r");
		FILE *izlaz=fopen(naziv1,"w");
		char rijeci[1000][1000]={{0}}, rijec[1000];
		int broj_rijeci=0,duzina=0,broj_mjesta=0,j;
		char znak=fgetc(ulaz);
		int kontrola=0;
		while (znak!=EOF){
			duzina=0;
			kontrola=0;
		while (slovo(znak)){
			rijec[duzina++]=znak;
			znak=fgetc(ulaz);
		}
		rijec[duzina]='\0';
		if (duzina<10 && duzina!=0)
		strcpy(rijeci[broj_rijeci],rijec);
		int j;
		for (j=0;j<broj_rijeci;j++){
			if (strcmp(rijeci[j],rijec)==0){
				kontrola=1;
				break;
			}
			if(kontrola)
			break;
			broj_rijeci++;
		}
		znak=fgetc(ulaz);
	}
	broj_mjesta=0;
	char c=fgetc(ulazpom);
	
	while(c!=EOF){
		if (c=='\n') broj_mjesta++; //Brojimo nova mjesta
		if (broj_mjesta==broj_rijeci) break;
		c=fgetc(ulazpom);
	}
	c=fgetc(ulazpom);
	while(c!=EOF){
		int n=0;
		if (c>=20 && c<=30){
			char *p=rijeci[c-20];
			n=1;
			while (*p!='\0'){
				fputc (*p,izlaz);
				p++;
			}
		}
		if (n==0)
		fputc(c,izlaz);
		c=fgetc(ulazpom);
	}
	printf("Datoteka dekompresovana.\n");
	fclose(ulaz);
	fclose(ulazpom);
	fclose(izlaz);
	}
	
	
int main(){
	char str[100],paket[100];
	int menu;
	do{
		printf("Odaberite:1-kompresuj,2-dekompresuj,0-izlaz: ");
		scanf("%d",&menu);
		switch(menu){
			case 1: //Unosi se ulazna i izlazna datoteka i kompresuje se
			{
				printf("Unesite ime ulazne datoteke: ");
				unesi(str,40);
				kompresuj(str,paket);
				break;
			}
			case 2: //Unosi se ulazna i izlazna datoteka i dekompresuje se
			{
				printf("Unesite ime ulazne datoteke: ");
				unesi(str,40);
				printf("Unesite ime izlazne datoteke: ");
				unesi(paket,40);
				dekompresuj(str,paket);
				break;
			}
		}
	} while(menu!=0);
	return 0;
}
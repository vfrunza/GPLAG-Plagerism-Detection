#include <stdio.h>
#include <stdlib.h>

	struct Oblik {
		char naziv[20];
		int br_stranica;
		double stranice[300];
	};

	while(i<kap) { //kapacitet je maksimum prodavnica koje mozemo ucitati
		
		int vel = 0;
		do {
		
			char x = fgetc(dat); //ucitavamo znak po znak jer naziv prodavnice moze sadrzavati i razmake
			if(x != ',')
				niz[i].naziv[vel++]=x;
			else break;

		} while(!(feof(dat)));
		niz[i].naziv[vel]='\0';
		niz[i].naziv[99] = '\0';	//treba ucitati samo prvih 99 znakova u nazivu prodavnice, ostale ignorisemo
		if(fscanf(dat, "%d\n", &niz[i].ID) == 0) break; //ucitavamo numericki podatak, ako fscanf vrati 0 doslo je do greske
		i++;
		if(feof(dat)) break;
	}

	void dodaj_oblik(struct Oblik o){
		
		FILE *dat=fopen("oblici.dat", "ab");
			if(dat==NULL){
				printf("greska");
				exit(1);
			}
			
			fwrite(&o, sizeof(struct Oblik), 1, dat);
			if(ferror(dat)){
				printf("greska");
			}
			
			fclose(dat);
	}
	
	void izbaci_duple(){
		FILE *dat=fopen("oblici.dat", "rb");
		if(dat==NULL){
			printf("greska");
			exit(1);
		}
		struct Oblik oblici[1000];
		int i=0;
		while(i<1000 && fread(&oblici[i], sizeof(struct Oblik), 1, dat))
		i++;
		int vel=i;
		for(i=0;i<vel;i++){
			for(j=0;j<vel;j++){
				if(strcmp(oblici[j].naziv, oblici[i].naziv)==0){
					for(k=0;k<)
				}
			}
		}
		
}
	

int main() {
	printf("Zadaća 5, Zadatak 3");
	return 0;
}

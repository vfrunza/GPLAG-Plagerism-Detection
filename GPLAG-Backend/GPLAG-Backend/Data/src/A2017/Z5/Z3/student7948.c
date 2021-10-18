#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Oblik{
	char naziv[20];
	int br_stranica;
	double stranice[300];
};

struct Oblik niz[] = {
   {"Trougao", 3, {1.1, 1.1, 1.1}},
   {"Trougao", 3, {1.1, 1.1, 1.1}},
   {"Trougao", 3, {100.1, 100.1, 100.1}},
   {"Kvadrat", 4, {1.1, 1.1, 1.1, 1.1}},
   {"Trougao", 3, {1.1, 1.1, 1.1}}
};

int i,j,k,prekidac;

void dodaj_oblik(struct Oblik o){
	int *p=o.br_stranica;
	FILE *dat=fopen("oblici.dat","ab");
	fwrite(o.naziv,1,strlen(o.naziv)+1,dat);
	fwrite(p,4,1,dat);
	fwrite(o.stranice,8,o.br_stranica,dat);
	fclose(dat);
}

void izbaci_duple(){
	for(i=0;i<duzina;i++){
		prekidac=0;
		for(j=i+1;j<duzina;j++)
			if(!strcmp(niz[i].naziv,niz[j].naziv)){prekidac=1;break;}
		if(prekidac){
			k=j+1;
			while(k<duzina){
				niz[j]=niz[k];
				k++;
				j++;
			}
			duzina--;
			i--;
		}
	}
	
}


int main() {
	int vel;
	struct Oblik shape[50];
	int *t=vel;
	FILE *dat=fopen("oblici.dat","rb");
	if(dat==NULL)return 0;
	fread(t,2,1,dat);
	fread(shape,sizeof(struct Oblik),50,dat);
	
	return 0;
}
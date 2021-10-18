#include <stdio.h>
#include <stdlib.h>

struct Oblik{
	char naziv[20];
	int br_stranica;
	double stranice[300];
};

void dodaj_oblik(struct Oblik a){
	FILE *ulaz=fopen("oblici.dat", "ab");

	int zapisano=fwrite(&a, sizeof(struct Oblik), 1, ulaz);
	fclose(ulaz);
	FILE *dat=fopen("oblici.dat", "rb");
	int n=0;
	fread(&n,sizeof(char),2,dat);
	fclose(dat);
	n++;
	dat=fopen("oblici.dat", "wb");
	fwrite(&n, sizeof(char),2, dat);
	fclose(dat);
}
double obim(struct Oblik a){
	int i=0;
	double o=0;
	for(i=0;i<a.br_stranica;i++)
		o=o+a.stranice[i];
	
	return o;
}
struct Oblik daj_najveci(){
	struct Oblik povratni={"Trougao",3, {1.1, 2.1, 1.1}};
	struct Oblik porediti={"Trougao",3, {1.1, 2.1, 1.1}};
	FILE *dat=fopen("oblici.dat", "rb");
	int n=0, i=0;
	fread(&n, sizeof(char), 2, dat);
	
	if (n==0)return povratni;
	
	//int dummy=0;
	//fread(&dummy, sizeof(char), 2, dat);
	fread(&povratni, sizeof(struct Oblik), 1, dat);
	printf("n = %d\n", n);
	
	for(i=1;i<n;i++){
		fread(&porediti, sizeof(struct Oblik), 1, dat);
		printf("poredim %f i %f\n", obim(porediti), obim(povratni));
		if(obim(porediti)>obim(povratni)) povratni=porediti;
		
	}
	
	fclose(dat);
	return povratni;
}




int main() {
struct Oblik niz[] = {
   {"Trougao", 3, {1.1, 1.1, 1.1}},
   {"Trougao", 3, {1.1, 1.1, 1.1}},
   {"Trougao", 3, {100.1, 100.1, 100.1}},
   {"Kvadrat", 4, {1.1, 1.1, 1.1, 1.1}},
   {"Trougao", 3, {1.1, 1.1, 1.1}}
};

int n = 0;
FILE * dat = fopen("oblici.dat", "rb");
fread(&n,sizeof(char),2,dat);
printf("%d", n); fclose(dat);
dodaj_oblik(niz[0]);
dat = fopen("oblici.dat", "rb");
fread(&n,sizeof(char),2,dat);
printf("%d", n);
	return 0;
}

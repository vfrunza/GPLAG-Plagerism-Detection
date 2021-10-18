#include<stdio.h>
#include<stdlib.h>
struct Oblik {
	char naziv[20];
	int br_stranica;
	double stranice[300];
};
void dodaj_oblik(struct Oblik oblik) {
	FILE *dat=fopen("oblici.dat", "a+");
	int da=fwrite(&oblik,sizeof(struct Oblik),1,dat);
	fclose(dat);
}
struct Oblik daj_najveci() {
	struct Oblik oblici[100];
	struct Oblik najveci;
	double obim,o;
	int vel,i;
	FILE* dat=fopen("oblici.dat","r");
	if(dat==NULL) {
		printf("Greska!");
		exit(1);
	}
	vel=fread(oblici,sizeof(struct Oblik),100,dat);
	fclose(dat);
	obim=oblici[0].br_stranica*oblici[0].stranice[0];
	najveci=oblici[0];
	for(i=0;i<vel;i++) {
		o=oblici[i].br_stranica*oblici[i].stranice[0];
		if(o>obim) {
			obim=o;
			najveci=oblici[i];
		}
	}
	return najveci;
}
int main() {
	printf("Zadaća 5, Zadatak 3");
	return 0;
}

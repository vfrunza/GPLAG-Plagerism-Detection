#include <stdio.h>
#include <stdlib.h>
struct Oblik{
	char naziv[20];
	int br_stranica;
	double stranice[300];
};
struct Oblik dodaj_oblik(struct Oblik rez[]){
	int i;
	FILE* dat=fopen("oblici.dat", "ab");
	if(dat==NULL){
		printf("Greska pri otvaranju datoteke oblici.dat!\n");
		exit(1);
	}
	int 
	fwrite(&rez,sizeof(struct Oblik),1,dat);
	/*fwrite(naziv,sizeof(naziv), 1, dat);
	fwrite(&br_stranica, sizeof(int),1,dat);
	fwrite(stranice,sizeof(double),1,dat);*/
	if(ferror(dat)){
		printf("Greska prilikom pisanja datoteke!\n");
	}
	fclose(dat);
}
int main() {
	
	printf("Zadaća 5, Zadatak 3");
	return 0;
}

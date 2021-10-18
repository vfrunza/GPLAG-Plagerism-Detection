#include <stdio.h>
#include <stdlib.h>

struct Oblik {
	char naziv[20];
	int br_stranica;
	double stranice[300];
};

void ucitaj()
{

}

/*void dodaj_oblik(struct Oblik* s){
	FILE* dat=fopen("oblici.dat","ab");
	if(dat==NULL){
		printf("Greska pri otvaranju datoteke oblici.dat.");
		exit(1);
	}
	fwrite(s,sizeof(struct Oblik),1,dat);
	ftell(dat);
	fclose(dat);
}*/


int main()
{
	struct Oblik oblici[1000];
	int N,i,j;
	float stranice[300] = { 0 };
	FILE* dat=fopen("oblici.dat","rb");
	if(dat==NULL) {
		printf("Greska pri otvaranju datoteke oblici.dat.");
		exit(1);
	}
	fread(&N,2,1,dat);
	
	

	for(i=0; i<N; i++) {
		fread(oblici[i].naziv,1,20,dat);
		fread(&oblici[i].br_stranica,1,1,dat);
		printf("*%s * %d*",oblici[i].naziv,oblici[i].br_stranica);
		fread(stranice,4,oblici[i].br_stranica,dat);
		for(j=0; j<oblici[i].br_stranica; j++) {
			oblici[i].stranice[j]=stranice[j];
		}
		printf("\n");
	}
	fclose(dat);
	printf("Zadaća 5, Zadatak 3");
	return 0;
}

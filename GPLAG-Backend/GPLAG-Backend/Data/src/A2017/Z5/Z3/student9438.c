#include <stdio.h>
#include <stdlib.h>

struct Oblik{
	char naziv[20];
	int br_stranica;
	double stranice[300];
};

void dodaj_oblik(struct Oblik oblici){
	
	struct Oblik* b;
	*b=oblici;
	
	int a=1;
	FILE* ulaz;
	ulaz=fopen("oblici.dat","ab");
	if(ulaz==NULL){
		printf("Pogreska pri otvaranju datoteke.");
		exit(1);
	}
	
	
	fwrite(b,sizeof(struct Oblik),a,ulaz);
	
	
		if(ferror(ulaz)){
		printf("Greska prilikom pisanja datoteke.\n");
		//printf("Zapisano je samo %d oblika\n",zapisano);
	}
	fclose(ulaz);
	
	
}


struct Oblik daj_najveci(){
	struct Oblik o[20];
	FILE* ulaz;
	ulaz=fopen("oblici.dat","rb");
	if(ulaz==NULL){
		printf("Pogreska pri otvaranju datoteke.");
		exit(1);
	}
	

	
}

int main() {

	/*FILE *ulaz;
	ulaz=fopen("oblici.dat","rb");
	if(ulaz==NULL){
		printf("Pogreska pri otvaranju datoteke oblici.dat");
		exit(1);
	}*/
	
	struct Oblik niz[]={{"Trougao", 3, {1.1, 1.1, 1.1}}};
	dodaj_oblik(niz[0]);

	return 0;
}

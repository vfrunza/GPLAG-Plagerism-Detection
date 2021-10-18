#include <stdio.h>

struct Oblik{  
	char naziv[20];
	int br_stranica;
	int stranice[300];
};

void dodaj_oblik (struct Oblik o){
	FILE *ulaz=fopen("oblici.dat", "ab");
	if(ulaz== NULL){
		printf("Greska pri otvaranju datoteke oblici.dat.\n");
		return;
	}
	fwrite(&o, sizeof(struct Oblik), 1, ulaz);
	fclose(ulaz);
}

/*struct Oblik daj_najveci (){
	
	FILE *ulaz=fopen("oblici.dat", "r");
	if(ulaz==NULL){
		printf("Greska pri otvaranju datoteke oblici.dat\n");
	}
	
	
}*/

int main() {
	printf("Zadaća 5, Zadatak 3");
	return 0;
}

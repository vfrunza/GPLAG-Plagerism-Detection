#include <stdio.h>
#include <stdlib.h>

struct Oblik {
		char naziv[20];
		int br_stranica;
		double stranice[300];
	};
int dodaj_oblik(struct Oblik *oblici){
	FILE *dat= fopen("oblik.dat","wb");
	if(dat==NULL) { 
		printf("Greska pri otvaranju datoteke.\n");
		exit(1);
	}
    
    if(ferror(dat)){
    	printf("Greska prilikom pisanja datoteke. \n");
  
    }
    fclose(dat);
}
int main() {
	printf("Zadaća 5, Zadatak 3");
	return 0;
}

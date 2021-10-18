#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Oblik {
	char naziv[20];
	int br_stranica;
	double stranice[300];
};

void dodaj_oblik(struct Oblik o)
{
	FILE *dat = fopen("oblici.dat", "rb");
	if(dat == NULL) {
		printf("Greska pri otvaranju datoteke oblici.dat!\n");
		exit(1);
	}
	struct Oblik oblici[300];
	int ucitano = fread(oblici, sizeof(struct Oblik), 300, dat);
	fclose(dat);
	oblici[ucitano + 1] = o;
	ucitano++;

	dat = fopen("oblici.dat", "wb");
	if(dat == NULL) {
		printf("Greska!");
		exit(1);
	}
	int zapisano = fwrite(oblici, sizeof(struct Oblik), ucitano, dat);
	if(ferror(dat) || zapisano != ucitano) {
		printf("Greska pri pisanju u datoteku!");
		exit(1);
	}
}
void izbaci_duple()
{
	FILE *dat = fopen("oblici.dat", "rb");
	if(dat == NULL) {
		printf("Greska pri otvaranju datoteke oblici.dat za citanje!");
		exit(1);
	}
	struct Oblik oblici[200];
	int ucitano = fread(oblici, sizeof(struct Oblik), 200, dat);
	fclose(dat);

	int i, j, k;

	for(i = 0; i < ucitano; i++) {
		for(j = i + 1; j < ucitano; j++) {
			if((strcmp(oblici[i].naziv, oblici[j].naziv)) == 0) {
				for(k = j; k < ucitano - 1; k++) {
					oblici[k] = oblici[k + 1];
				}
				ucitano--;
				j--;
			}
		}
	}
	dat = fopen("oblici.dat", "wb");
	if(dat == NULL) {
		printf("Greska");
		exit(1);
	}
	int zapisano = fwrite(oblici, sizeof(struct Oblik), ucitano, dat);
	fclose(dat);

}
int main()
{

	return 0;
}

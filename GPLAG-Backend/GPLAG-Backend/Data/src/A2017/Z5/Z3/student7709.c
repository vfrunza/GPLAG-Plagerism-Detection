#include <stdio.h>

struct Oblik {
	char naziv[20];
	int br_stranica;
	double stranice[300];
};

struct Oblik daj_najveci()
{
	struct Oblik k;
	FILE *dat;
	dat=fopen("oblici.dat","rb");
	if(dat==NULL) {
		printf("Greskaaa");
		return k;
	}
	int br[1];
	fread(br,2,1,dat);
	//br je broj oblika!!


	int vel=br[0];
	printf("   %d  ",vel);

	struct Oblik oblici[vel];
//	fread(oblici,sizeof(struct Oblik),br,dat);

	fclose(dat);
	return k;

}
int main()
{
	printf("Zadaća 5, Zadatak 3");
	struct Oblik rez = daj_najveci();
	printf("%s %g %g %g\n", rez.naziv, rez.stranice[0], rez.stranice[1], rez.stranice[2]);
	return 0;
}

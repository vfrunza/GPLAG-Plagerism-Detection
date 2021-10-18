#include <stdio.h>
struct Oblik {
	char naziv[20];
	int br_stranica;
	double stranice[300];
};

void dodaj_oblik(struct Oblik o){
	FILE* dat=fopen("oblici.dat", "ab");
	if(dat==NULL)
	exit(1);
	fwrite(o,sizeof(struct Oblik),1,dat)
	fclose(dat);
}

izbaci_najvece
struct Oblik daj_najveci(){
	
	return max;
}

int main()
{
	printf("Zadaća 5, Zadatak 3");
	return 0;
}

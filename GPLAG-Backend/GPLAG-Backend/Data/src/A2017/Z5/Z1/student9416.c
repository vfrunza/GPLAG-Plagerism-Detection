#include <stdio.h>

int main() {
	int sirina, duzina,i=0,vel;
	char ime[20];
	FILE *dat;
	char s[10];
	int niz[100];

	dat=fopen("treci.txt", "r");
	if(dat==NULL){
		printf("Greska!");
		return 3;
	}
	
	while(fscanf(dat, "%d", &niz[i])==1 && i<100){
	
		i++;
	}
	vel=i;

	i=0;
	while (i<vel){
	fprintf(dat, "%d", niz[i]);
		i++;
	}
	
	
	fclose (dat);
	return 0;
}

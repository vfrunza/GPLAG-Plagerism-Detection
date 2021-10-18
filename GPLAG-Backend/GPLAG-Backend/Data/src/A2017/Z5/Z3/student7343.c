#include <stdio.h>

struct Grad {
 char naziv[20]; 
 int br_stan;
};

struct Grad unos_grada () {
	struct Grad g;
	printf("Unesi naziv grada: ");
	scanf("%s ",&g.naziv);
	printf("Unesi br stanovnika ");
	scanf("%d ",&g.br_stan);
	return g;
}

void ispis_grada (struct Grad g, char znak, int vel) {
	for(i=0; i<vel; i++){
		if(g.naziv[0] == znak){
    	printf("%s %d",g.naziv,g.br_stan);
		}
	}
}

void upisi_u_datoteku(struct Grad *g, int n, int vel){
	FILE *izlaz=fopen("neka.txt","r+");
	if(izlaz==NULL) {
		printf("Dat se nije otvorila");
	    return 1;
	}
	int i=0;
	for(i=0; i<vel; i++)
	if(g[i].br_stan > n){
		fprintf(izlaz, "%-20s%2d", g[i].naziv, g[i].br_stan);
	}
	
	fclose (izlaz);
}



int main() {
	
	int i=0, vel;
	struct Grad g[100];
	FILE *ulaz=fopen("gradovi.txt","r+");
	if(ulaz==NULL) {
	    printf("Dat se nije otvorila.....");
	    return 1;
	}

	//provjera 
	i=0; 
	while((fscanf(ulaz, "%20s%2d\n", g[i].naziv, &g[i].br_stan)) == 2 && i<100) 
		i++;
	vel=i;
	
	
	fclose(ulaz);

	return 0;
}

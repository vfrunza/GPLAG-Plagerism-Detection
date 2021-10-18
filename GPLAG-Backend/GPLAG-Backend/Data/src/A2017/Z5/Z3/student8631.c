#include <stdio.h>
//include<string.h>
#include<stdlib.h>

struct Oblik{
 char naziv[20]; 
 int br_stranica; 
 double stranice[300]; 
};
void dodaj_oblik(struct Oblik o){
    FILE * Ulaz=fopen("oblici.dat", "ab"); 
    //char naziv[20];
    int i=0;
    int br_stranica=o.br_stranica; 
    if(Ulaz==NULL) {
        printf("Greska pri otvaranju datoteke.\n"); 
        exit(1); 
    }
 //  i=fwrite(Ulaz, sizeof(struct Oblik),1, o);
    i=fwrite(&o, sizeof(struct Oblik), 1, Ulaz);
    if(ferror(Ulaz))
    {
        printf("Greska prilikom pisanja datoteke.\n"); 
    }
    fclose(Ulaz); 
}
/*struct Oblik daj_najveci(){
    int i, indeks;
    FILE *Ulaz=fopen("oblici.dat", "rb");
    if(Ulaz==NULL){ printf("Greska pri otvaranju datoteke.\n"); exit(1);}
    int vel = 0; 
    fread(&vel,2 * sizeof(char), 1, Ulaz);
    struct Oblik najveci;
    fread(&najveci, sizeof(struct Oblik), 1, Ulaz);
    for(i=1; i<vel; i++)  
    {
        struct Oblik trenutni;
        fread(&trenutni, sizeof(struct Oblik), 1, Ulaz);
        double obim1 = 0, obim2 = 0;
        int j = 0, k;
        for(j = 0; j<najveci.br_stranica; j++) obim1+=najveci.stranice[j];
        for(k = 0; k<trenutni.br_stranica;k++) obim2+=trenutni.stranice[k];
        if((obim2 > obim1)) najveci = trenutni;
    }
    return najveci; 
}
int izbaci_duple()
{
    int i, j, k=0; 
    int pret=0; 
    char *p, *s; 
    FILE *Ulaz=fopen("oblici.dat", "r"); 
    if(Ulaz==NULL ){printf("Greska pri otvaranju datoteke.\n"); exit(1);}
    int vel=0;
    fread(&vel, 2*sizeof(char), 1, Ulaz); 
    struct Oblik najveci; 
    fread(&najveci, sizeof(struct Oblik), 1, Ulaz); 
    for(i=1; i<vel-1;i++){
        k=0;
       k= strcmp(najveci.naziv[i], najveci.naziv[i+1]);
    if(k){
        for(j=i; j<vel-1; j++)
         najveci.naziv[j]=najveci.naziv[j+1]; 
         i--; 
         vel--; 
    }
}
    fclose(Ulaz);
    return vel; 
}*/
int main() {
    
	printf("Zadaća 5, Zadatak 3");
	return 0;
}



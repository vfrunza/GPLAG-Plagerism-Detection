#include <stdio.h>
#include <stdlib.h>

void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}

struct Datum{
	int dan,mjesec,godina;
};

struct Uposlenik{
	char ime_prezime[50];
	struct Datum datum_rodenja;
};

/*struct Datum unesi_datum(){
	struct Datum d;
	scanf("%d%d%d",&d.dan,&d.mjesec,&d.godina);
    return d;
};

struct Uposlenik unesi_uposlenik(){
	char ime_prezime[50];
	unesi(ime_prezime,50);
	
};
*/

int suzi_listu( struct Uposlenik *kandidati,int vel,struct Uposlenik direktor,int broj_dana){
    
    int danrodenja_direktora,danrodenja_uposlenika,razlika=0;
    int i,j;
    
    danrodenja_direktora=direktor.datum_rodenja.dan;
    
    for(i=0;i<vel;i++){
        
        danrodenja_uposlenika=kandidati[i].datum_rodenja.dan;
        razlika=danrodenja_uposlenika-danrodenja_direktora;
        
        if(razlika==broj_dana){
            for(j=i;j<vej-1;j++){
                
                kandidati[j]=kandidati[j+1];
            }
            vel--;
            j--;
        }
        
    }
    
    return j;
}

int main() {
    
   /* struct Uposlenik kandidati[100];
    int x;
    struct Uposlenik direktor;
    
    scanf("%d\n", &x);
    
    */
    
	return 0;
}

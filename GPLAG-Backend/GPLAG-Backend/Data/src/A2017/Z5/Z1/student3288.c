#include <stdio.h>
#include <math.h>
#include <string.h>

struct Datum{
	int dan,mjesec,godina};
	
	struct Uposlenik{
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

int prestupna(struct Uposlenik kandidat){
	if(kandidat.godina%4)
    {
        if(kandidat.godina%100 == 0)
        {
            // year is divisible by 400, hence the year is a leap year
            if ( kandidat%400 == 0)
               return 1;
        }
    }
    
	return 0;
}
int suzi_listu(struct Uposlenik* kandidati,int vel,struct Uposlenik direktor, int broj_dana){
	int broj=0,i,j,k,mjeseci,suma1=0,suma2=0;
	if(prestupna(direktor)){
		suma1*=366;
	}
	for(i=0;i<vel;++i){
	if(prestupna(kandidati[i])){
		suma2*=365;
		
	}

	}	
	return broj;
}


int main() {
	printf("Zadaća 5, Zadatak 1");
	return 0;
}



#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926
#define MAX_BROJ_CLANOVA 500


int main() {
	double niz_uglova[MAX_BROJ_CLANOVA],ugao,stepeni,minute,sekunde;
	int broj_uglova,i,j;
	printf("Unesite broj uglova: ");
	scanf("%d",&broj_uglova);
	for(i=0;i<broj_uglova; i++){
		scanf("%lf",&ugao);
		niz_uglova[i]=ugao;
	}	
	
	for(i=0; i<broj_uglova; i++) {
		//Pretvorimo odmah ugao u stepene minute i sekunde i provjerimo za sekunde da li su vece od 30 a zaokruzeno manje od 60
		stepeni = niz_uglova[i] *(180/PI);
		minute = fabs(stepeni - (int)stepeni) * 60;
		sekunde= fabs(minute - (int)minute) * 60;
	// Provjerimo da li je apsolutna vrijednost zaokruzenih sekundi veca od 30
		if((int)(sekunde+0.5)>30) {
			//Razmotrimo specijalni slucaj kada je aps vrijednost zaokruzenih sekundi 60
			//Onda se dodaju minutama za +1 ili -1 a one postaju 0 i TAJ CLAN TAD NE TREBA IZBACIT
			//Zato koristimo continue za ovaj specijalni slucaj, a u protivnom izbacujemo
			if((int)(sekunde+0.5)==60)
				continue;
			//Izbacujemo clan ali sa ocuvanjem rasporeda
			for(j=i; j<broj_uglova-1; j++) {
				niz_uglova[j] = niz_uglova[j+1];
				
			}
			broj_uglova--;
			i--;
		}
	}
	printf("Uglovi su:\n");
	for(i=0; i<broj_uglova; i++) {
		stepeni = niz_uglova[i] *(180/PI);
		minute = fabs(stepeni - (int)stepeni) * 60;
		sekunde = fabs(minute - (int)minute) * 60;
	//Kao sto je vec spomenuto, za ovaj specijalni slucaj, imamo promjenu u minutama i eventualno stepenima 
	// za +1 ili -1 ovisno o predznaku, pa zato i razmatramo slucajeve
		if((int)(sekunde+0.5)==60){
			minute++;
			if((int)(minute)==60){
				minute=0;
				if(stepeni<0)
					stepeni--;
				else if(stepeni>0)
					stepeni++;
			}
			sekunde=0;
		}
		printf("%d stepeni %d minuta %d sekundi\n",(int)stepeni,(int)minute,(int)(sekunde+0.5));
		
	}
	return 0;
}

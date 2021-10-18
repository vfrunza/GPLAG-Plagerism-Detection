#include <stdio.h>
#include <math.h>
struct Datum{
	int dan,mjesec,godina;
};
struct Uposlenik{
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};
int isto_prezime(char* ime_kandidata,char* ime_direktora){
	char*pok=ime_kandidata;
	char*pok1=ime_direktora;
	int nije_isto=0,br=0;
	while(*pok!='\0'){
		if(*pok==' '){
		 pok++;
		 break;
		}
		pok++;
		
	}
	//pomjeri pokazivaz do prvog razmaka
	while(*pok1!='\0'){
		if(*pok1==' '){
			pok1++;
			break;
		}
		pok1++;
    }
	while(*pok!='\0' || *pok1!='\0'){
		if(*pok==*pok1){
			pok1++;
			pok++;
		}else{
			nije_isto=1;
			break;
		}
		br++;
	}if(*pok!=*pok1){
		nije_isto=1;
	}
	if(*pok=='-' && *pok1=='\0'){
		nije_isto=0;
		pok1=pok1-br;
		pok+=1;
		while(*pok!='\0'){
			if(*pok==*pok1){
				pok1++;
				pok++;
			}else{
				nije_isto=1;
				break;
			}
		}
	}else if(*pok=='\0' && *pok1=='-'){
		nije_isto=0;
		pok=pok-br;
		pok1+=1;
		while(*pok1!='\0'){
			if(*pok==*pok1){
				pok1++;
				pok++;
			}else{
				nije_isto=1;
				break;
			}
		}
	}
	if(nije_isto){
		return 0;
	}else{
		return 1;
	}
}
int suzi_listu(struct Uposlenik* kandidati,int vel,struct Uposlenik direktor,int broj_dana){
	int i,j,k;
	int mjeseci[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int razlika;;
	for(i=0;i<vel;i++){
		razlika=0;
		mjeseci[2]=28;
		//povecaj drugi element niza mjeseci za jedan u slucaju prestupne godine
		if((kandidati[i].datum_rodjenja.godina%4==0 && kandidati[i].datum_rodjenja.godina%100!=0) || kandidati[i].datum_rodjenja.godina%400==0){
			mjeseci[2]+=1;
		}
		if(kandidati[i].datum_rodjenja.mjesec <= direktor.datum_rodjenja.mjesec && kandidati[i].datum_rodjenja.godina == direktor.datum_rodjenja.godina){
			for(k=kandidati[i].datum_rodjenja.mjesec;k<=direktor.datum_rodjenja.mjesec;k++){
				if(k==direktor.datum_rodjenja.mjesec){
					razlika+=direktor.datum_rodjenja.dan;
				}else if(k==kandidati[i].datum_rodjenja.mjesec){
					razlika+=(mjeseci[k]-kandidati[i].datum_rodjenja.dan);
				}else{
					razlika+=mjeseci[k];
				}
			}
		}else if(kandidati[i].datum_rodjenja.godina < direktor.datum_rodjenja.godina && !(isto_prezime(kandidati[i].ime_prezime,direktor.ime_prezime))){
			for(j=i;j<vel-1;j++){
				kandidati[j]=kandidati[j+1];
			}
			i--;
			vel--;
		}
			if(razlika>fabs(broj_dana) && !(isto_prezime(kandidati[i].ime_prezime,direktor.ime_prezime))){
				for(j=i;j<vel-1;j++){
					kandidati[j]=kandidati[j+1];
				}
				i--;
				vel--;
			}
		}
		return vel;
	}
	

int main() {
	printf("Zadaća 5, Zadatak 1");
	return 0;
}

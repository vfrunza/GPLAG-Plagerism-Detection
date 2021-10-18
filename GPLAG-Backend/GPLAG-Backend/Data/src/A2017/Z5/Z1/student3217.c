#include <stdio.h>
struct Datum{
	int dan, mjesec, godina;
};

struct Uposlenik{
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

int Pripadam_porodici(char *direktor, char *kandidat){
	int broj_slova_d=0, j=0, ima=0;
	char *cuvar_direktor, *drzim_crticu;
	
	
	while(*direktor!='\0') direktor++;                     /*Pomjeram pokazivac na kraj*/
	while(*direktor!=' ') {direktor--; broj_slova_d++;    /*Pomjeram pokazivac do prvog razmaka, iza kojeg je pocetno slovo prezimena*/
		
	}   /*Pomjeram do pocetka prezimena*/
	
	while(*kandidat!='\0') kandidat++;
	while(*kandidat!=' '){
		kandidat--; 
		if(*kandidat=='-'){ ima=1; drzim_crticu=kandidat;}  /*Analogno kao kod direktora, samo ako naidje na crticu, novim pokazivacem drzi to mjesto*/
		
	}
	
	direktor++; kandidat++;
	cuvar_direktor=direktor;
	
	do{
		if(ima==1){  /*Ako kandidat ima dva prezimena. Ovo sam uvela zbog pokazivaca, sluzi mi kao potvrda da zaista ima crtica*/
			
			while(*direktor==*kandidat && *direktor!='\0'){
				direktor++;
				kandidat++;
				j++;
			}
			
			if(j==broj_slova_d-1) return 1;
			
			direktor=cuvar_direktor;
			
			j=0;
			
			kandidat=++drzim_crticu;

			while (*direktor==*kandidat && *direktor!='\0') {
				direktor++;
				kandidat++;
				j++;
			}
			
			if(j==broj_slova_d-1) return 1;
			
		}
		
		while (*direktor==*kandidat && *direktor!='\0' && *kandidat!='\0') {
			direktor++;
			kandidat++;
			j++;
			
		}
		
		if(j==broj_slova_d-1) return 1;
		
		break;
		
	}while(1);
	
	return 0;  /*Fja vraca 1 ako su prezimena jednaka, ili bar jedno prezime kandidata odgovara prezimenu direktora. Vraca 0 ako to ne vrijedi*/


}

int suzi_listu(struct Uposlenik *kandidati, int vel, struct Uposlenik direktor, int broj_dana){
	struct Uposlenik *pomocni, *cuvar, *pocetak, *kraj;
	int j=0, razlika=0,  u_porodici,broj_dana_direktor=0, broj_dana_kandidat=0,  i=0,mjeseci[12]={31,28,31,30,31,30,31,31,30,31,30,31}, *pok, *cuvar_mjeseci, *pocetak_mjeseci;
	
	pocetak=kandidati;
	kraj=kandidati;
	
	pok=mjeseci;
	
	pocetak_mjeseci=mjeseci;
	
	/*Za razliku dana*/
	
	if(((direktor.datum_rodjenja.godina%4==0 && direktor.datum_rodjenja.godina%400==0) || direktor.datum_rodjenja.godina%100==1)&& direktor.datum_rodjenja.mjesec>2){broj_dana_direktor=direktor.datum_rodjenja.dan+1;} /*Ako je godina prestupna, dodaje dan*/
	else broj_dana_direktor=direktor.datum_rodjenja.dan;
	
	while(j<vel){ kraj++; j++;} /*Pokazivac pokazuje iza kraja*/
	
	while(i+1<direktor.datum_rodjenja.mjesec){
				broj_dana_direktor+=*pok;
				pok++;
				i++;
				
			}
			
	pok=pocetak_mjeseci;
			
	while(kandidati!=kraj){ 
		
		u_porodici=Pripadam_porodici((*kandidati).ime_prezime, direktor.ime_prezime); /*Fja koja provjerava da li su prezimena ista*/
		
		if(((((*kandidati).datum_rodjenja.godina%4==0&&(*kandidati).datum_rodjenja.godina%400==0) || (*kandidati).datum_rodjenja.godina%100==1))&& (*kandidati).datum_rodjenja.mjesec>2){ broj_dana_direktor=(*kandidati).datum_rodjenja.dan+1;} /*Ako je godina prestupna, dodaje dan*/
		else broj_dana_kandidat=(*kandidati).datum_rodjenja.dan;
		
		if((*kandidati).datum_rodjenja.godina==direktor.datum_rodjenja.godina){ /*Kada su isto godiste i kandidat i direktor, onda posmatramo dane samo u toj godini*/
	

			pok=pocetak_mjeseci;
			cuvar_mjeseci=pok;
			
			
			i=0;
			pok=pocetak_mjeseci;
			
			while(i+1<(*kandidati).datum_rodjenja.mjesec){
				broj_dana_kandidat+=*pok;
				pok++;
				i++;
			}
			
			pok=cuvar_mjeseci;
			
			razlika=broj_dana_direktor-broj_dana_kandidat;
			
		}
		
		if(direktor.datum_rodjenja.mjesec==1 && (direktor.datum_rodjenja.godina-(*kandidati).datum_rodjenja.godina)==1){ /*Specijalan slucaj, ako je kandidat rodjen godinu ranije u decembru, dok je direktor rodjen*/
			broj_dana_kandidat=31-broj_dana_kandidat;      /*Naredne godine u januaru*/
			
			razlika=broj_dana_direktor+broj_dana_kandidat;
			
		}
		
		if(direktor.datum_rodjenja.godina>(*kandidati).datum_rodjenja.godina) razlika=broj_dana+1;
		
		if(direktor.datum_rodjenja.godina<(*kandidati).datum_rodjenja.godina) razlika=0;
		
		//printf("%s --%d ----\n", (*kandidati).ime_prezime, razlika);
		
		if(broj_dana<0){
			
			if(razlika>broj_dana && u_porodici==0){ 
			
			pomocni=kandidati; 
			cuvar=kandidati; 
			
			pomocni++;
			while(pomocni<kraj){
				                    /*Petlja koja izbacuje kandidate koji su stariji od direktora*/
				*kandidati=*pomocni;
				kandidati++;
				pomocni++;
			}
			
			kandidati=cuvar; 
			if(kandidati>=pocetak)kandidati--;
			kraj--;
			
			
			vel--; 
		}
			
		}
		
		if(broj_dana>0){
		if(razlika>broj_dana && u_porodici==0){ 
			
			pomocni=kandidati; 
			cuvar=kandidati; 
			
			pomocni++;
			while(pomocni<kraj){
				                    /*Petlja koja izbacuje kandidate koji su stariji od direktora*/
				*kandidati=*pomocni;
				kandidati++;
				pomocni++;
			}
			
			kandidati=cuvar; 
			if(kandidati>=pocetak)kandidati--;
			kraj--;
			
			
			vel--; 
		}
		}
		
		//rintf("%d--\n", vel);
		
		kandidati++;
	}
	
	kandidati=pocetak;
	
	return vel;
}

int main() {
	int broj_dana=28,i=0;
	struct Uposlenik direktor={"Mujo Mujic", {1, 3, 1900} };
	struct Uposlenik kandidati[7]={
	{ "Meho Mehic", { 31, 1, 1900 } },
    { "Pero Peric", { 1, 2, 1900 } },
    { "Sara Sarac", { 2, 2, 1900 } },
    { "Fata Mujic", { 1, 2, 1896 } },
    { "Jozo Jozic", { 1, 10, 1900 } },
    { "Mijo Mijic", { 4, 3, 1899 } },
    { "Suljo Suljic", { 15, 1, 1902 } },
};
	int novi_br=suzi_listu(kandidati, 7, direktor, broj_dana);
	
	printf("Novi Broj: %d\n", novi_br);
	
	for(i=0;i<novi_br; i++) printf("%s--\n", kandidati[i].ime_prezime);
	return 0;
}

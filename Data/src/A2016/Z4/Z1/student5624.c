#include <stdio.h>
#include <ctype.h>
void unesi(char niz[], int velicina){  //funkcija za unos//
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	int i=0;
	while(i<velicina-1 && znak!='\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}
void izbaci(char *string, char* pocetak_rijeci){ //funckija za izbacivanje najcesce rijeci //
	char*reset=string,  *pocetak_uporedbene, *reset_pocetka_rijeci, *kraj_uporedbene, *prepisivanje, *ucitavanje;
	while((*reset)!='\0'){
		if(((toupper(*reset)>='A')&& (toupper(*reset)<='Z'))&&((reset==string) || (!((toupper(*(reset-1))>='A')&&(toupper(*(reset-1))<='Z'))))){
			pocetak_uporedbene=reset;
			prepisivanje=reset;
			reset_pocetka_rijeci=pocetak_rijeci;
			while(((toupper(*reset)>='A')&&(toupper(*reset)<='Z')))
				reset++;
			if((!((toupper(*reset)>='A')&& (toupper(*reset)<='Z')))||((*reset)=='\0'))
			{
				kraj_uporedbene=reset;
				ucitavanje=reset;
				if(toupper(*pocetak_uporedbene)==toupper(*reset_pocetka_rijeci)){
				while((toupper(*pocetak_uporedbene)==toupper(*reset_pocetka_rijeci)) && (*reset_pocetka_rijeci!='\0') && (pocetak_uporedbene!=kraj_uporedbene)){
						pocetak_uporedbene++;
						reset_pocetka_rijeci++;
					}
				
				if(*reset_pocetka_rijeci=='\0'&& pocetak_uporedbene==kraj_uporedbene){
					while(*ucitavanje!='\0'){
						*prepisivanje++=*ucitavanje++;
						
					}
					*prepisivanje='\0';
					reset=reset-(ucitavanje-prepisivanje);
				  
			}
			}
				
			}
		
		}
		if(*reset=='\0') break;
		else reset++;
	}
}
char* izbaci_najcescu(char *string){ // funckija pronalazi najcescu rijec //
	char *pocetak_trenutne_rijeci,*reset2=string, *reset=string, *kraj_trenutne_rijeci, *pomocni_string, *pomocni_pocetak_trenutne, *pomocni_pocetak_uporedbene, *pocetak_najcesce, *kraj_najcesce, *pocetak_uporedbene_rijeci, *kraj_uporedbene_rijeci;
	int najcesca=0, brojac=0, log_pretpostavka;
	char rijec[60]={0};
	char* prijec=rijec;
	while((*reset)!='\0'){
		if(((toupper(*reset)>='A')&& (toupper(*reset)<='Z'))&&((reset==string) || (!((toupper(*(reset-1))>='A')&&(toupper(*(reset-1))<='Z'))))){
			pocetak_trenutne_rijeci=reset;
			brojac=1;
			while(((toupper(*reset)>='A')&&(toupper(*reset)<='Z'))){
				reset++;
			}
			if((!((toupper(*reset)>='A')&& (toupper(*reset)<='Z')))||((*reset)=='\0')){
				kraj_trenutne_rijeci=reset;
				pomocni_string=reset;
				while((*pomocni_string)!='\0'){ //poredimo pronadjenu rijec sa ostatkom stringa//
					if(((toupper(*pomocni_string)>='A')&& (toupper(*pomocni_string)<='Z'))&&((pomocni_string==string) || (!((toupper(*(pomocni_string-1))>='A')&&(toupper(*(pomocni_string-1))<='Z'))))){
						pocetak_uporedbene_rijeci=pomocni_string;
						while(((toupper(*pomocni_string)>='A')&&(toupper(*pomocni_string)<='Z'))){
							pomocni_string++;
						}
						if((!((toupper(*pomocni_string)>='A')&& (toupper(*pomocni_string)<='Z')))||((*pomocni_string)=='\0')){
							kraj_uporedbene_rijeci=pomocni_string;
							pomocni_pocetak_trenutne=pocetak_trenutne_rijeci;
							pomocni_pocetak_uporedbene=pocetak_uporedbene_rijeci;
							log_pretpostavka=1;
							if(toupper(*pomocni_pocetak_uporedbene)==toupper(*pomocni_pocetak_trenutne)){
							while((pomocni_pocetak_uporedbene!=kraj_uporedbene_rijeci)){
								if(toupper(*pomocni_pocetak_trenutne)!=toupper(*pomocni_pocetak_uporedbene))
									log_pretpostavka=0;
								pomocni_pocetak_uporedbene++;
								pomocni_pocetak_trenutne++;
							}
							if(log_pretpostavka==1)
								brojac++;
							}
						}
					}
				if(*pomocni_string=='\0') break;
				else pomocni_string++;
				}
				if(brojac>najcesca){ 
				prijec=rijec;
				najcesca=brojac;
				pocetak_najcesce=pocetak_trenutne_rijeci;
				kraj_najcesce=kraj_trenutne_rijeci;
				while(pocetak_najcesce!=kraj_najcesce){ // pravimo novi string u kojem ce se najcesca rijec nalaziti//
					*prijec=*pocetak_najcesce;
					prijec++;
					pocetak_najcesce++;
				}
				*prijec='\0';

				}

			}
		}
		if(*reset=='\0') break;
		else reset++;
	}

	izbaci(string, rijec); //funkciji izbaci saljemo string i drugi string u kojem se nalazi najcesca rijec
	return reset2;
}

int main() {
	char niz[1000];
	printf("Unesite tekst: ");
	unesi(niz, 1000);
	printf("%s", izbaci_najcescu(niz));
	return 0;
}

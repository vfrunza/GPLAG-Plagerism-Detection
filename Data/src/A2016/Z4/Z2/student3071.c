#include <stdio.h>
#include<string.h>

void unesi( char *s, int vel){
	char znak=getchar();
	if (znak=='\n') znak=getchar;
	int i=0;
	while(i<vel && znak!='\n'){
		s[i]=znak;
		i++;
		znak=getchar();
	}
	s[i]='\0';
}



char *kodiraj ( char *string, char *kod_tablica){
	int histogram_slova[97]={0};
	//klizeci_po_tablici cuva vrijednosti kao i po histogramu
	int i,klizeci_po_tablici,j,brojac=0,duzina_stringa=strlen(string);
	for(i=0; i<97; i++){
		brojac=0;
		for(j=0; j<duzina_stringa; j++){
			if(string[j]==i+32){
				brojac++;
			}
		}
		histogram_slova[i]=brojac;
	}
	//Pauza u dodavanju kako petlja za formiranje kod tablice
	//ima kontrolne prve elemente
	int pauza_u_dodavanju=0,duzina=97;
	int max_histogram=histogram_slova[0];
	int brojac_ubacenih_u_tablicu=0;
	int stvarni_index,k,index_max,ubacivac_znakova=0,tragac_stvarnog_max=0,m;
	for(stvarni_index=0, klizeci_po_tablici=0, i=0; i<96; stvarni_index++, klizeci_po_tablici++, i++){
		index_max=0;
		max_histogram=0;

		//Petlja koja nalazi maximum histograma slova
		for(k=0; k<96; k++){

                tragac_stvarnog_max=0;
			if(histogram_slova[k]>max_histogram){
				max_histogram=histogram_slova[k];
				index_max=k;
				//Ovdje pazimo da ne anuliramo nemaksimalni clan histograma
				for(m=k; m<97; m++){
				if(histogram_slova[m]>tragac_stvarnog_max){
                    tragac_stvarnog_max=histogram_slova[m];
				}
				}
				//Postavljamo sve prebrojene na neku specificnu vrijednost
				//koju kasnije koristimo
				if(tragac_stvarnog_max==max_histogram)
                histogram_slova[k]=-1;



			}


		}

		if(index_max>0 || max_histogram>0){
		kod_tablica[i]=index_max+32;
		//Pauza u dodavanju iznosi onoliko elemenata koliko je
		//Ubaceno na pocetak u kod_tablici
		pauza_u_dodavanju++;
		duzina--;
		}else if(index_max==0){

			//Ovdje popunjavamo prvotne clanove, tj(redom)
			//one koji su brojevno nadmocni u histogramu
			kod_tablica[i]=ubacivac_znakova+32;
			ubacivac_znakova++;
			//Ovdje se "izbacuju" oni koji su vec u tablici
			if(histogram_slova[klizeci_po_tablici-pauza_u_dodavanju]==-1)
            i--;
		}

    if(stvarni_index-pauza_u_dodavanju==96){
        kod_tablica[stvarni_index]='\0';
        break;
    }
	}
	kod_tablica[95]='\0';

	//Samo kodiranje stringa
	for(i=0; i<duzina_stringa; i++){
		for(j=0; j<97; j++){
			if(string[i]==kod_tablica[j]){
				break;
			}
		}
		string[i]=126-j;
	}
	string[i]='\0';


	return string;
}

char *dekodiraj ( char *string, char *kod_tablica){
	int i,j,duzina_stringa;
	duzina_stringa=strlen(string);
	for(i=0; i<duzina_stringa; i++){
		for(j=0; j<97; j++){
			if(string[i]==kod_tablica[j]){
				break;
			}
		}
		string[i]=kod_tablica[126-string[i]];
	}
	string[i]='\0';
	return string;
}

int main() {
	//printf("Zadaća 4, Zadatak 2");
	char tekst[] = "Jeste li dobro kreirali sifrarnik?";
    char sifrarnik[100] = "";
    int i;
    kodiraj(tekst, sifrarnik);
    printf("%s", tekst);
    printf("%s", sifrarnik);

	return 0;
}

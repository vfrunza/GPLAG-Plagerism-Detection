#include <stdio.h>

void unesi(char niz[], int velicina){
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

void izmjeni(char *string, char *sifrarnik){ //funkcija koja sifrira string
	char *pomocni_string=string, *pomocni_sifrarnik=sifrarnik;
	int brojac;
	while(*pomocni_string!='\0'){
		brojac=0;
		pomocni_sifrarnik=sifrarnik;
		while(*pomocni_sifrarnik!='\0'){
			if(*pomocni_string==*pomocni_sifrarnik++){
				*pomocni_string=126-brojac;
				break;
			}
			brojac++;
			}
		pomocni_string++;
			
		}
	
}
void sortiraj(int *niz, int *niz_sort, int* indeks, char *pokazivac, char *string){ //funkcija sortira po ucestalosti
	int i, j;
	int temp;
	char*sifrarnik=pokazivac;
	for(i=0; i<127; i++){
		for(j=i; j<127; j++){
			if(niz[i]<niz[j]){
				temp=niz[i];
				niz[i]=niz[j];
				niz[j]=temp;
				temp=indeks[i];
				indeks[i]=indeks[j];
				indeks[j]=temp;
			}
			else if(niz[i]==niz[j] && indeks[i]>indeks[j]){
				temp=indeks[i];
				indeks[i]=indeks[j];
				indeks[j]=temp;
			}
		}
	}
	for(i=0; i<127; i++){
		if(indeks[i]!=-1){
			*pokazivac=indeks[i];
			pokazivac++;
		}
	}
	izmjeni(string, sifrarnik);
}
char *kodiraj(char*string, char *sifrarnik){ // funkcija kodira
	char *pomocni_string=string, *pokazivac=sifrarnik;
	int i;
	int niz[127];
	int niz_sort[127];
	int indeks[127];
	for(i=0;i<127;i++){
		if(i<32){
			niz[i]=-1;
			indeks[i]=-1;
		}
		else{
			niz[i]=0;
			indeks[i]=i;
		}
		
	}
	while(*pomocni_string!='\0'){
		niz[*pomocni_string+0]++;
		pomocni_string++;
	}
	for(i=0;i<127;i++){
		niz_sort[i]=niz[i];
	}
	sortiraj(niz, niz_sort, indeks, pokazivac, string);

	return string;
}
char *dekodiraj(char *string, char *sifrarnik){ // funkcija dekodira
	char *pomocni_string=string;
	while(*pomocni_string!='\0'){
		*pomocni_string=sifrarnik[126-*pomocni_string];
		pomocni_string++;
	}
	return string;
}

int main() {
	printf("zadaca 4, zadatak 2");
	return 0;
}












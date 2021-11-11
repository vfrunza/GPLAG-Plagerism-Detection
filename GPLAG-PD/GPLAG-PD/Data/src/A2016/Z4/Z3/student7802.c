#include <stdio.h>
#include <stdlib.h>
int broj_slova (char* rijec){
	int brojac=0;
		
		while((*rijec>='A' && *rijec<='Z')||(*rijec>='a'&&*rijec<='z')){brojac++;rijec++;}
	
	return brojac;
}

int provjera_rijeci (char* rijec,char* rijec_izbacujemo){
	
	while(*rijec==*rijec_izbacujemo){
		
		rijec++;
		rijec_izbacujemo++;
		if((!((*rijec>='A' && *rijec<='Z') || (*rijec>='a' && *rijec<='z'))))
			break;
	}
	
	if(!((*rijec_izbacujemo>='A' && *rijec_izbacujemo<='Z') || (*rijec_izbacujemo>='a' && *rijec_izbacujemo<='z')) && (!((*rijec>='A' && *rijec<='Z') || (*rijec>='a' && *rijec<='z'))))
		return 1;
	
	
	
	return 0;
}

char* ubacujemo_rijec (char* pocetak_rijeci, int brojslova,char* ubacujemo){
		char* pocetak=pocetak_rijeci;
		char* kraj;
		kraj=pocetak_rijeci;
			
			
			if(brojslova<0){
				
				while((*ubacujemo>='A' && *ubacujemo<='Z')||(*ubacujemo>='a' && *ubacujemo<='z')){
					*pocetak_rijeci=*ubacujemo;
					pocetak_rijeci++;
					ubacujemo++;
				}
				
				*(pocetak+1)='\0';
					
				
				
			}
			else{
				while(*kraj!='\0'){
					kraj++;
				
			}
				while(kraj>pocetak_rijeci){
					*(kraj + brojslova ) = *kraj;
					kraj--;
				
				}	
			
				while((*ubacujemo>='A' && *ubacujemo<='Z')||(*ubacujemo>='a' && *ubacujemo<='z')){
					*pocetak_rijeci=*ubacujemo;
					pocetak_rijeci++;
					ubacujemo++;
				}
			}
	return pocetak;
			
}	
				
	
	
	



char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
	char* p=tekst;
	char* q=tekst;
	char* izbacujemo;
	char* ubacujemo;
	char* kizbacujemo;
	char* kraj;
	int i=0,k=0,s=0,kizbac=0;
	int brojslova;
	

		for(i=0;i<broj_rijeci;i++){
			izbacujemo = rijeci[i];
			ubacujemo = zamjene[i];
			q=p;
			kizbac=0;
			kizbacujemo=izbacujemo;
			
			while((*kizbacujemo>='A' && *kizbacujemo<='Z') || (*kizbacujemo>='a' && *kizbacujemo<='z')) {
				
				kizbac++;
				kizbacujemo++;
			}
			
			while(*q!='\0'){
				
				while(*q!=*izbacujemo) {
					q++;
					if(*q=='\0')
						break;
				}
				if(*q=='\0') break;
				
				k=0;
				if(s==0){k = provjera_rijeci(q,izbacujemo);}
				else{
				if((*(q-1)>='A' && *(q-1)<='Z')||(*(q-1)>='a' && *(q-1)<='z'));
			
				else
				k = provjera_rijeci(q,izbacujemo);
				}
				s++;
					if(k==1){
						brojslova =  (broj_slova(ubacujemo)-kizbac);
						kraj=q;			
						q=ubacujemo_rijec(kraj,brojslova,ubacujemo);
						
						
					}
			
			q++;		
			}
		}	

	return p;
}
void unesi(char niz[], int velicina) {
    char znak = getchar();
    int i=0;
    if (znak == '\n') znak=getchar();
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}

int main() {
char* rijeci[2] = { "Prijestolonasljednikovica" };
	char* zamjene[2] = { "c" };
	char tekst[100];
	
	printf("Unesite neki tekst: ");
	unesi(tekst,100);
	zamjena_rijeci(tekst, rijeci, zamjene, 1);
	printf("%s",zamjena_rijeci(tekst, rijeci, zamjene, 1));
	return 0;
}
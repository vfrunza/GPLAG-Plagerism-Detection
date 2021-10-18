#include <stdio.h>

void najduzi_bp(char *s1, char *s2){
	char *pomocni_pocetak, *pomocni_kraj, *krajnji_pocetak=s1, *krajnji_kraj=s1, *poc;
	int ascii_tabela[63]={0};
	int duzina=0, i=0;
	
	while(*s1!='\0'){
		poc=s1;
		pomocni_pocetak=poc;
		while(*poc!='\0' && *poc!=' ' && ((*poc>='A' && *poc<='Z') || (*poc>='a' && *poc<='z'))){
			if(ascii_tabela[*poc-65]>0) break;
			else{
				if(*poc>='a' && *poc<='z'){
					ascii_tabela[*poc-65]++;
				}
				else{
					int vrijednost = *poc + 32 - 65;
					ascii_tabela[vrijednost]++;
				}
				poc++;
			}
		}
		pomocni_kraj = poc;
		if(pomocni_kraj - pomocni_pocetak > duzina){
			duzina = pomocni_kraj - pomocni_pocetak;
			krajnji_pocetak = pomocni_pocetak;
			krajnji_kraj = pomocni_kraj;
		}
		i=0;
		while(i<63){
			ascii_tabela[i]=0;
			i++;
		}
		s1++;
	}
	while(krajnji_pocetak!= krajnji_kraj){
		*s2 = *krajnji_pocetak;
		krajnji_pocetak++;
		s2++;
	}
	*s2='\0';
}

int main() {
	return 0;
}

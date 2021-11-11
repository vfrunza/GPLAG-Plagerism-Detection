#include <stdio.h>


int duzina_rijeci(char* a){
	int duzina=0;
	if(*a=="") return 0;
	while(*a!='\0'){
		duzina++;
		a++;
	}
	return duzina;
}

int da_li_je_prazan(char* string){
	int br=0;
	if(*string=='\0') return 1;
	else return 0;
}

int je_slovo(char c){
	if((c>='A' && c<='Z') || (c>='a' && c<='z')) return 1;
	else return 0;
}

int uporedi_rijeci(char* a, char* b){
	if(duzina_rijeci(a)!=duzina_rijeci(b)) return 0;
	else{
			while(*a!='\0'){
				if(*a==*b) {a++;b++;}
				else return 0;
			}
	}
	return 1;
}

int broj_razmaka(char* a){
	int br=0;
	while(*a!='\0'){
		if(*a==' ') br++;
		a++;
	}
	return br;
}

char* zamjena_rijeci(char* tekst1, char** rijeci, char** zamjene, int broj_rijeci){
	
	int z,k=0, i=0, j=0, pozicija,poklapanje_rijeci=1,zadovoljava,prazne_rijeci=1;
	char* tekst=tekst1;
	k=0;
	pozicija=0;
	
	if(broj_rijeci==0) return tekst;
	
	for(i=0;i<broj_rijeci;i++){
		if(duzina_rijeci(*(zamjene+i))!=0){
			prazne_rijeci=0;
			break;
		}
	}
	if(prazne_rijeci==1){
		int razmaci=broj_razmaka(tekst);
		for(i=0; i<razmaci;i++){
			*(tekst+i)=' ';
		}
		*(tekst+i)='\0';
		return tekst;
	}
	
	while(tekst[k]!='\0'){
		if(k==0) zadovoljava=1;
		else if(k>duzina_rijeci(tekst)) break;
		else if(je_slovo(tekst[k]) && !je_slovo(tekst[k-1])) zadovoljava=1;
		else zadovoljava=0;
		
		if(zadovoljava){
			int duzina=0;
			while(1){
				if(tekst[k]!=' ' && tekst[k]!='\0'){
					duzina++;
					k++;
				}
				else break;
			}
			char vrati[100]="";
			for(i=0;i<duzina;i++){
				vrati[i]=*(tekst+i+pozicija);
			}
			vrati[i]='\0';
			pozicija+=i+1;
			for(i=0;i<broj_rijeci;i++){
				poklapanje_rijeci=uporedi_rijeci(vrati, *(rijeci+i));
				if (poklapanje_rijeci==1) break;
			}	
			if (poklapanje_rijeci==1){
			
			if(duzina_rijeci(vrati)<=duzina_rijeci(*(zamjene+i))){
				int x=duzina_rijeci(*(zamjene+i))-duzina_rijeci(vrati);
				for(j=duzina_rijeci(tekst)-1;j>=pozicija-duzina_rijeci(vrati);j--){
					tekst[j+x]=tekst[j];
				}
				
				z=0;
				for(j=pozicija-duzina_rijeci(vrati)-1; j<duzina_rijeci(*(zamjene+i))+pozicija-duzina_rijeci(vrati)-1;j++){
					tekst[j]=*(*(zamjene+i)+z);
					z++;
				}
				pozicija+=x;
				k=pozicija;
			}
			else{
				int x=duzina_rijeci(vrati)-duzina_rijeci(*(zamjene+i));
				for(j=pozicija-duzina_rijeci(vrati);j<=duzina_rijeci(tekst)-1;j++){
					tekst[j]=tekst[j+x];
				}
				
				if(*(zamjene+i)!=""){
					z=0;
					for(j=pozicija-duzina_rijeci(vrati)-1;j<duzina_rijeci(*(zamjene+i))+pozicija-duzina_rijeci(vrati)-1;j++){
						tekst[j]=*(*(zamjene+i)+z);
						z++;
					}
					pozicija-=x;
					k=pozicija;
				}
			}
			
			}
			else k++;
		}
		
	else k++;
	if(k>duzina_rijeci(tekst)) break;
	}
return tekst;
}

int main() {
	char* rijeci[2]={"beli","sneg"};
	char* zamjene[2]={"bijeli","snijeg"};
	char tekst[100]="beli sneg je pokrio beli breg";
	
	printf("%s",zamjena_rijeci(tekst,rijeci,zamjene,2));
	return 0;
}

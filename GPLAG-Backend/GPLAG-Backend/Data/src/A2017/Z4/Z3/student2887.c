#include <stdio.h>
void najduzi_bp(char* s1,char* s2){
	int brojac=0,indikator=0,br=0,brojac1,brojac2=0,broj=0;
	char* pok1=s1;
	char* pok2=s1;
	//pomjeri pokazivace na prvo slovo
	while(!((*pok1>='A' && *pok1<='Z') || (*pok1>='a' && *pok1<='z'))){
		pok1++;
		pok2++;
	}
	pok2++;
	
	while(*pok1!='\0' || *pok2!='\0'){
		if(((!((*pok2>='A' && *pok2<='Z') || (*pok2>='a' && *pok2<='z')) && pok1!=pok2) || (pok1!=pok2 && *pok1==*pok2))){
			//pomjeri pokazivac pok2 na slovo i pok1 na pocetak rijeci
			pok2--;
			broj=br;
			if(br!=0){
			do{
				pok1--;
				br--;
			}while(br!=0);
			}
			
			if(broj>brojac2){
			brojac2=broj;
			//ubaci podstring u string s2
			do{
				*s2++=*pok1++;
				brojac++;
			}while(pok1<pok2);
			brojac1=brojac;
			*s2='\0';
			pok2++;
			do{
				s2--;
				brojac1--;
			}while(brojac1!=0);
			br=0;
			brojac=0;
			}else{
				pok2++;
				do{
				pok1++;
				}while(pok1!=pok2);
				brojac=0;
			}
		//ukoliko se pok1 razlikuje od pok2 pomjeraj pokazivace pok1 i pok2 do prvog neslova 
		}else if(*pok2!=*pok1 && ((*pok1>='A' && *pok1<='Z') || (*pok1>='a' && *pok1<='z'))){
			pok1++;
			pok2++;
			br++;
		}else if((!((*pok2>='A' && *pok2<='Z') || (*pok2>='a' && *pok2<='z' )) &&  !((*pok1>='A' && *pok1<='Z') ||(*pok1>='a' && *pok1<='z')))){
			pok1++;
			pok2++;
		    indikator=1;	
		}else if(indikator==1 && *pok2==*pok1 && ((*pok2>='A' && *pok2<='Z') || (*pok2>='a' && *pok2<='z'))){
			pok2++;
			indikator=0;
		}
		
			
		}
		
		
	}
	
int main() {
	char tekst[100]="Ovo je neki primjer teksta";
	char tekst1[100];
	najduzi_bp(tekst,tekst1);
	printf("%s",tekst1);
	return 0;
}

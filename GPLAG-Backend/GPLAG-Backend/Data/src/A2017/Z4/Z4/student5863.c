#include <stdio.h>

int ukrstanje(char *poc, char *kraj){
	int br1 = 0, br2 = 0;
	while(poc <= kraj){
		if(*poc == '<'){
			if(*(poc+1) == '/') br2++;
			else br1++;
		}
		poc++;
	}
	if(br1 == br2) return br1;
	else return 0;
}

int provjeri(char *s)
{
	char naziv[100];
      char *poc_tag,*kraj_tag;
      char *pom = s;
      char *p1,*p2;
      int broj_tag, nasao_tag = 0, duzina, nasli = 1, ukrsta, poceo = 0;
      p2 = pom;
      while(*p2 != '\0') p2++;
      broj_tag = ukrstanje(pom,p2);
      while (*pom != '\0'){
      	if(*pom == '<' && *(pom+1) != '/' && nasli == 1){
      		poceo = 1;
      		poc_tag = pom;
      		nasli = 0;
      		duzina = 0;
      		p1 = pom + 1;
      		p2 = naziv;
      		while(*p1 != ' ' && *p1 != '>'){
      			duzina++;
      			*p2 = *p1;
      			p1++;
      			p2++;
      		}
      		*p2 = '\0';
      	}
      	if(*pom == '<' && *(pom+1) == '/' && poceo == 1){
      		nasli = 1;
      		p2 = naziv;
      		pom+=2;
      		while(*p2 != '\0'){
      			if(*p2 != *pom){
      				nasli = 0;
      			}
      			p2++;
      			pom++;
      		}
      	}
      	if(nasli == 1 && poceo == 1){
      		if(*pom != '>') return 0;
      		kraj_tag = pom - 2 - duzina;
      		ukrsta = ukrstanje(poc_tag,kraj_tag);
      		if(ukrsta == 0) return 0;
      		pom = poc_tag + duzina;
      		poceo = 0;
      		nasao_tag++;
      		if(nasao_tag == broj_tag) return 1;
      	}
      	pom++;
      }
      return 0;
}

int main() {
	
	char tekst1[] = "<div id=\"tekst\"><h2>Naslov</h2><p>Ovo je <b>cetvrti</b> i <i>posljednji</i> zadatak iz <a href=\"zadaca4\">zadace 4</a></p></div>";
	char tekst2[] = "<div><h4>Naslov</h4><p>Danasnja vijest</p></div>";
	//printf("%d ", provjeri(tekst1));
	printf("\n%d ", provjeri(tekst2));
	return 0;
}

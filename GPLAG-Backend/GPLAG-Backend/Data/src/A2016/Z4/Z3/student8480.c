#include <stdio.h>

int duzina(char *rijec){ //vraca duzinu poslane rijeci
	int duzina=0;
	char*pom=rijec;
	while(*pom++!='\0'){
		duzina++;
	}
	return duzina;
}


void ubaci(char *p, char* r){
	char* kraj=p;
	int duz=duzina(r);
	
	while(*kraj!='\0') 
		kraj++; //odemo s kraja na kraj
		
	while(kraj>=p){   //pravimo mjesto iza p, jer cemo tu dodati novu rijec
		*(kraj+duz)=*kraj--;
	}	
	
	while(*r!='\0'){ //p ostalo na mjestu gdje trebamo ubaciti rijec, ubacimo
		*p=*r;
		p++; r++;
	}
	
}


char *trazi_rijeci(char* s1,char* s2){ //isto kao u predavanju samo sto vraca pokazivac, a ne 1, ako nadje rijec u stringu
	char*poc=s1, *p,*q;

	while(*s1!='\0'){
		p=s1; q=s2;	
			while(*p++==*q++){
				if((s1==poc || *(s1-1)==' ') && (*q=='\0') && (*p==' '|| *p=='\0')) return s1;
			}	
		s1++;	
	}
	
return NULL;
}



char* zamjena_rijeci(char *tekst, char **rijeci, char **zamjene, int broj_rijeci) {
	char *pocetak=tekst;
	char *s=tekst, *p, *n, *r, *hod, *prvi=rijeci[0], *drugi=zamjene[0];
	int i, vel;

if(*prvi==*drugi && *(prvi+1)==*(drugi+1) && *(prvi+2)==*(drugi+2) && *(prvi+3)==*(drugi+3)) return pocetak;
	
	for(i=0;i<broj_rijeci;i++){
		p=trazi_rijeci(tekst, rijeci[i]); //u p spasimo gdje je nasa rijec u stringu
		
		if(p==NULL) continue; //ako rijeci nema u stringu, nastavljamo dalje
		
		else { //izbacivanje rijeci
			int izbacivanje=1;
			vel=duzina(rijeci[i]);
			n=p;
			hod=n+vel;
		
		while(*hod!='\0'){
			*n=*hod;
			n++;
			hod++;
		}
			
		*n='\0';
		
if(izbacivanje==1 && p!=NULL){
	ubaci(p,zamjene[i]);
	i--; //sve dok ima nasih rijeci u tekstu moramo izbacivati, pa se i vraca na rijec koja je prethodno izbacena
			}
		}
	
	}
	
return pocetak;
}


int main() {
	
	char *rijeci[2]={"beli","sneg"};
	char *zamjene[2]={"bijeli","snijeg"};
	char tekst[100]="beli sneg je pokrio beli breg";
	printf("%s", zamjena_rijeci(tekst,rijeci,zamjene,2));
	
	return 0;
}

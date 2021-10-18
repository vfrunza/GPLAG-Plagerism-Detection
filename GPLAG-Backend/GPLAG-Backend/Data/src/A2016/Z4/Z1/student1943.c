#include <stdio.h>
#include <ctype.h>
void unesi(char niz[], int velicina) {
          char znak = getchar();
          int i = 0;
           if (znak == '\n') znak = getchar();
          
         while (i < velicina && znak != '\n') {
                  niz[i] = znak;
                    i++;
                 znak = getchar();
         }
            niz[i] = '\0';
}

int isSlovo(char s) {
	if((s>='A' && s<='Z') || (s>='a' && s<='z')) return 1;
	else return 0;
}

char* izbaci_najcescu(char* s) {
	char *p=s;
	char *pt,*kt,*pm,*km,*pocporedjenja,*tporedjenje,*cuvar,*kt2,*poredjenje,*m;
	char mm[100];
	int brojac=0,max=0,jednaki=1;
	
	pm=s;
	while(!isSlovo(*pm) && *pm!='\0')
		pm++;
	km=pm;
	while(km!='\0' && isSlovo(*km))
		km++;
		
	while (*p!='\0')  {
		if(isSlovo(*p)) {
			pt=p;
			while (isSlovo(*p))p++;
			kt=p;
			pocporedjenja=p;
			brojac=0;
			while(*pocporedjenja!='\0') { 
				if(isSlovo(*pocporedjenja)) {
					cuvar=pocporedjenja;
					while(isSlovo(*pocporedjenja))pocporedjenja++;
					kt2=pocporedjenja; 
					poredjenje=pt; 
					tporedjenje=cuvar;
					jednaki=1;
					while(tporedjenje!=kt2) { 
						if(toupper(*tporedjenje)!=toupper(*poredjenje)){ jednaki=0;}
						tporedjenje++;
						poredjenje++;
					}
					if(jednaki==1) brojac++;
				}
				else pocporedjenja++;
			}
			if(brojac>max) {
				pm=pt;
				km=kt;
				max=brojac;
			}
		}
		else p++;
	}
	m=mm;
	while(pm!=km){
		*m=*pm;
		m++;pm++;
	}
	*m='\0';
	m=mm;
	
	p=s;
	while(*p!='\0') {
		if(isSlovo(*p)) {
			pt=p;
			while(isSlovo(*p)) p++;
			kt=p;
			jednaki=1;
			tporedjenje=pt;
			poredjenje=m; 
			while(tporedjenje!=kt && *poredjenje!='\0') {
				if(toupper(*tporedjenje)!=toupper(*poredjenje)) jednaki=0;
				tporedjenje++;
				poredjenje++;
			}
			if(tporedjenje!=kt)
				jednaki=0;
			if(jednaki==1) {
				while (*kt!='\0') {
					*pt++=*kt++;
				}
				*pt='\0';
				p=s;
			}
			else
				if(*p!='\0')
					p++;
		}
		else
			p++;
	}
	p=s;
	return p;
}



int main() {
	char t[]="1PsT1 psT2 3Pst pstpst pst";
	printf("'%s'", izbaci_najcescu(t));
	return 0;
}

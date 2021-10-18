#include <stdio.h>

int provjeri(char* s){
	char *pocetak,*kraj = s,znak1,znak2,*p,*q,*novi;
	char *poc = s;
	int cs,duz,br,provjera,prvi_put = 1,brojac_zagrada = 0,pravilno_zatvorena = 0;
while(*s != '\0'){
		 if(*s == '<'){
		 	if(prvi_put){if(! (*(s+1) >= 'a' && *(s+1) <= 'z' || *(s+1) >= 'A' && *(s+1) <= 'Z' || *(s+1) >= '0' && *(s+1) <= '9') )return 0; prvi_put = 0;}
		 	if(*(s+1) == '/')break;
			pravilno_zatvorena = 1;
			duz = 0;
			s++;
			if( ! (*s >= 'a' && *s <= 'z' || *s >= 'A' && *s <= 'Z' || *s >= '0' && *s <= '9') ) return 0;
			pocetak = s;
			duz = 0;
			while(*s >= 'a' && *s <= 'z' || *s >= 'A' && *s <= 'Z' || *s >= '0' && *s <= '9') {s++; duz++; } 
			if(*s == ' ')while (*s != '\0' && *s != '>')s++;
			if(*s != '>')return 0;
			kraj = s;
			
			while(*kraj != '\0'){
					if(*kraj == '<' && *(kraj + 1) != '/')brojac_zagrada++;
					if(*kraj == '/'){
						novi = kraj;
						novi--;
						kraj++;
						if(*novi != '<' || ! (*kraj >= 'a' && *kraj <= 'z' || *kraj >= 'A' && *kraj <= 'Z' || *kraj >= '0' && *kraj <= '9'))return 0;
						p = kraj;
						br = duz;
						p = kraj;
						q = pocetak;
						cs = 1;
							while(p != '\0' && br != 0){
										znak1 = *q;
										znak2 = *p; 
										if(znak1 >= 'a' && znak1 <= 'z') znak1 = znak1 - 32;
										if(znak2 >= 'a' && znak2 <= 'z') znak2 = znak2 - 32;
										if(znak1 != znak2){
											cs=0;
											brojac_zagrada--;
									
											break;
										}
										p++;
										q++;
										br--;
										
							}
							if(cs){
								//otvorena zagrada je pravilno zatvorena
								pravilno_zatvorena--;
								if(brojac_zagrada != 0)return 0;
							}
					}
					if(!pravilno_zatvorena)break;
					kraj++;
				}
			}
			if(*s == '\0')s--;
			s++;
			if(pravilno_zatvorena != 0)return 0;
	}
	
	return 1;
}


int main() {
{//AT3: pogresno zatvoreni tagovi i bez tagova
printf ("Provjera  0: %d\n", provjeri("</p><p>pocelo je zatvorenim tagom</p>"));
 printf ("Provjera 4: %d\n", provjeri("<span><span><span><a href='https://etf.unsa.ba'>etf.unsa.ba stranica</a></span></span></span>"));
}	return 0;
}
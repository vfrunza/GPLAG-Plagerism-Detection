#include <stdio.h>

void najduzi_bp(char *s1,char *s2){
	char *pocetak, *kraj, *p,*q,znak1,znak2,*kraj_rijeci,*a,*poc;
	int cs,prvi_put = 1,cijela_rijec;						

	while(*s1 != '\0'){
			while(*s1 == ' ' && *s1 != '\0' || !(*s1 >= 'a' && *s1 <= 'z' || *s1 >= 'A' && *s1 <= 'Z'))s1++;
			p = s1; //prvo slovo rijeci
			while(*s1 >= 'a' && *s1 <= 'z' || *s1 >= 'A' && *s1 <= 'Z')s1++;
			q = s1; // iza kraja rijeci
		//izdvojili smo rijeci
				if(prvi_put) {pocetak = p; kraj_rijeci = p; prvi_put = 0; }
				poc = p;
				cijela_rijec = 1; //ako se u rijeci ne javljaju ponavljanja , npr. "divan"
				//prolazimo kroz omedjenu rijec i trazimo podstring   
		+			while(p < q){
						a = p;
						a++;
							while(a < q){
								cs = 0;//pretpostavimo da nema ponavljanja
								kraj = p;
								//svaki put kada dodamo neko slovo ispitamo da li se ponavlja
								while(kraj <a){
									if(*kraj >= 'a' && *kraj <= 'z') znak1 = *kraj - 32; else znak1 = *kraj; 
									if(*a >= 'a' && *a <= 'z') znak2 = *a - 32; else znak2 = *a;
									if(znak1 == znak2){ cs = 1;cijela_rijec = 0;} // ako je bar jednom ispunjeno ,znaci da nije cijela rijec 
									if(cs)break;
							kraj++;
								}
						
								if(cs){
								
									 if((a - p) > (kraj_rijeci - pocetak)){ pocetak = p; kraj_rijeci = a;}
									 }
									 
								a++;
							if(cs)break;
							}
							p++;
					}
					
						if(cijela_rijec){
									 if((q - poc) > (kraj_rijeci - pocetak)){ pocetak = poc; kraj_rijeci = q;}
						}
			if(*s1 == '\0')break;
			s1++;
	}
					
	
	while(pocetak  < kraj_rijeci)
	*s2++ = *pocetak++;
	*s2 = '\0';
	
}



int main() { 
  {
        char niz[100];
        najduzi_bp ("Danas", niz);
        printf ("\nNiz: '%s'", niz);
    }
	return 0;
}3

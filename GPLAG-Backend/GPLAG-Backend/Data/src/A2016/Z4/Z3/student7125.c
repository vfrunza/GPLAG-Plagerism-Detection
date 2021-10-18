#include <stdio.h>
char *zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci);
int br_el_rijeci(char *s);

int main() {
char* rijeci[2] = { "c" };
char* zamjene[2] = {  "Prijestolonasljednikovica" };
   char tekst[100]; /* = "c c"; */
tekst[0] = 'c';
tekst[1] = ' ';
tekst[2] = 'c';
tekst[3] = '\0';

    
    printf("'%s'", zamjena_rijeci(tekst, rijeci, zamjene, 1));
	return 0;
}

int br_el_rijeci(char *s){
    int broj = 0;
    while (*s != ' ' && *s != 0) {
            broj++;
        s++;
    }
    return broj;
}

char *zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
	char *p = tekst,  *q = tekst, *kraj = tekst, *t = tekst, *poc = tekst;
	char *r = rijeci, *z = zamjene;
	int i = 0, ostatak = 0, nije_izvrs_zamjena = 1, veca_zamjena = 1;
	char slovo[1];
	
	if (broj_rijeci == 0)
		return tekst;

	
	while(*p != 0){
		
	  	nije_izvrs_zamjena = 1;
	  
		if (i == broj_rijeci) i = 0;
		
		r = rijeci[i];
		z = zamjene[i];
			
		while(!((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z')) && *p != 0) p++; //Preskace ono što nije slovo
		poc = p;
		q = p;
		
		if(p != tekst && !((*(p-1) >= 'A' && *(p-1) <= 'Z') || (*(p-1) >= 'a' && *(p-1) <= 'z')) && *(p-1)!= ' ') //obezbjeđuje da kao rijeci racuna samo ono omeđeno razmakom
			p--;
		
		while(*p == *r && *p != 0){
			p++;
			r++;
			if (*r == '\0' && ((*p == ' ' || *p == 0)) ){
				if(br_el_rijeci(z) > br_el_rijeci(q)){
					while(*z != 0){
						if(!((*q >= 'A' && *q <= 'Z') || (*q >= 'a' && *q <= 'z'))){ 	// ako smo došli do kraja rijeci koju trebamo zamjeniti
							while(*kraj != 0) kraj++;
							
							slovo[0] = *z; // pamtimo slovo na koje se kasnije zamjenska rijec mora vratit
							ostatak = 0;
														
							while(((*z >= 'A' && *z <= 'Z') || (*z >= 'a' && *z <= 'z')) && *z != 0){
								ostatak++; //broj karaktera što su ostali u rijeci koju treba ubacit
								z++;
							}
								
							while(*z != slovo[0])
								z--;
								
							while(kraj > q){
								*(kraj+ostatak) = *kraj; //dodajemo potrebnu količinu novih mjesta
								kraj--;
							}
								
							t = q;
							
							while(t < q + ostatak)
								*t++ = 'a';
							}
							
						*q++ = *z++; // mjenjamo rijec jednu drugom
						nije_izvrs_zamjena = 0;

						if(*z == 0)
							*q =' ';  // kad je izmjena gotova potrebno je dodati razmak
							
						veca_zamjena = 1; //zamjenska rijec je bila veća od od one koju treba mjenjat
						}
				}
						
					else{  						// ako je zamjenska rijec manja od one koju treba mjenjat
						while(*z != 0)
							*q++ = *z++;
							
						ostatak = 0;
							
						t = q;
							
						while(((*t >= 'A' && *t <= 'Z') || (*t >= 'a' && *t <= 'z')) && *t != 0){ // trazimo koliko je ostalo karaktera od prvobitne rijeci
							ostatak++;
							t++;
						}
							
						while(*kraj != 0) kraj++;
							
						while(q < kraj - ostatak + 1)
							*q++ = *(q+ostatak -1); //izbacujemo viska karaktere
						
							nije_izvrs_zamjena = 0;
							veca_zamjena = 0; //zamjenska rijec je bila manja od one koju treba mjenjat
			
						}
			}	
		}

		if (p != poc && nije_izvrs_zamjena == 1 || veca_zamjena == 0) p = poc;	// ako nije izvrsena zamjena ili ako je zamjenska rijec bila manja pokazivac se vraća na početak riječi 

		
		if (nije_izvrs_zamjena == 0 || i == broj_rijeci - 1)	
			while(((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z')) && *p != 0) p++; // ako nemamo više riječi koje treba porediti sa trenutnom, onda nju preskačemo
			
		i++;

	}

		
	return tekst;
}
	

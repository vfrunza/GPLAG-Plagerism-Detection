#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

short istoSlovo (char a, char b) {
	if(a>='A' && a<='Z')
		a-='A';
	else if(a>='a' && a<='z')
		a-='a';
	if(b>='A' && b<='Z')
		b-='A';
	else if(b>='a' && b<='z')
		b-='a';
	return a==b;
}
void izbaciRijec(char *s) {
	char *temp1, *temp2;
	while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
		temp1=s;
		temp2=s+1;
		do {
		    if(*temp2 == '\0') break;
			*temp1=*temp2;
			temp1++;
			temp2++;
		} while(*temp2!='\0');
		*temp1='\0';
	}
}
char* izbaci_najcescu(char* s) {
	char *pocetak,*najcesca,*temp1,*temp2;
	int max=0, brPonavljanja;
	pocetak=s;
	short iste;
	  /* trazimo najcescu */
    while(*s != '\0') {
        /* trazenje prve sljedece rijeci */
        while(*s < 'A' || (*s > 'Z' && *s < 'a') || *s > 'z') {
            if(*s == '\0') break;
            s++;
        }
        temp1 = s;
        brPonavljanja = 0;
        /* koliko se puta trenutna rijec ponavlja u ostatku teksta ? */
        while(*temp1 != '\0') {
            /* pronadji prvu sljedecu rijec */
            while(*temp1 < 'A' || (*temp1 > 'Z' && *temp1 < 'a') || *temp1 > 'z') {
                if(*temp1 == '\0') break;
                temp1++;
            }
          
            temp2 = s;
            iste = TRUE;
            while((*temp1 >= 'A' && *temp1 <= 'Z') || (*temp1 >= 'a' && *temp1 <= 'z')) {
              
                if(!istoSlovo(*temp1, *temp2))
                    iste = FALSE;
                temp1++;
                temp2++;
            }
            /* je li rijec koju brojimo duza od trenutne ? */
            if((*temp2 >= 'A' && *temp2 <= 'Z') || (*temp2 >= 'a' && *temp2 <= 'z'))
                iste = FALSE;
            if(iste)
                brPonavljanja++;
        }
        if(brPonavljanja > max) {
            max = brPonavljanja;
            /*najcesca = pocetakRijeci;*/
            najcesca = s;
        }
        /* prelazak na kraj rijeci */
        while((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))
            s++;
    }

    /* ako nije bilo rijeci u stringu */
    if(max == 0) return pocetak;

    /* izbacivanje najcesce rijeci iz stringa */
    while(s > najcesca) {
        /* trazenje prve sljedece rijeci s kraja */
        while(*s < 'A' || (*s > 'Z' && *s < 'a') || *s > 'z')
            s--;
        /* prelazak na pocetak rijeci */
        while(((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')) && s > pocetak)
            s--;
        if(!((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')))
            s++;
        if(s == najcesca) break;
        temp1 = najcesca;
        temp2 = s;
        iste = TRUE;
        while((*temp1 >= 'A' && *temp1 <= 'Z') || (*temp1 >= 'a' && *temp1 <= 'z')) {
            
            if(!istoSlovo(*temp1, *temp2)) {
                iste = FALSE;
                break;
            }
            temp1++;
            temp2++;
        }
        
        if((*temp2 >= 'A' && *temp2 <= 'Z') || (*temp2 >= 'a' && *temp2 <= 'z'))
            iste = FALSE;
        if(iste)
            izbaciRijec(s);
        s--;
    }
    izbaciRijec(s);

    return pocetak;
}
int main() {
	 char test[] = "Primjer. Ovo je primjer u kojem se rijec PRIMJER ponavlja najcesce, tako da treba izbaciti i:PriMjeR";
    char ocekivano[] =  ". Ovo je  u kojem se rijec  ponavlja najcesce, tako da treba izbaciti i:";
    char bezRijeci[] = "=-=-989  +_=)(";
    char samoRijec[] = "asdfg";
    char vodeciSimboli[] = "!@#$% @$abcd";
    char prateciSimboli[] = "absd#@$ 2$@2429)";
    char najcescaSadrzana[] = "Car je carevao u svom carstvu";
    char najcescaSadrzi[] = "rijec automat sadrzi auto:AUTOmat";
    char veznici[] = "PROBA+PROBA-proba=Proba";
    char anone[] = "_-_AnOnE_-_";
    char prazan[] = "";
    char viseRijeci[] = "u ovom stringu se rijec \"stringu\" ponavlja kao i rijec 'rijec', ali je 'stringu' blize pocetku!";
    printf("%s\n", test);
    printf("%s\n", izbaci_najcescu(test));
    printf("%s\n", test);
    printf("\nOcekivano: \n");
    printf("%s\n\n", ocekivano);
    printf("%s\n", bezRijeci);
    printf("%s\n", izbaci_najcescu(bezRijeci));
    printf("%s\n", samoRijec);
    printf("%s\n", izbaci_najcescu(samoRijec));
    printf("%s\n", vodeciSimboli);
    printf("%s\n", izbaci_najcescu(vodeciSimboli));
    printf("%s\n", prateciSimboli);
    printf("%s\n", izbaci_najcescu(prateciSimboli));
    printf("%s\n", najcescaSadrzana);
    printf("%s\n", izbaci_najcescu(najcescaSadrzana));
    printf("%s\n", najcescaSadrzi);
    printf("%s\n", izbaci_najcescu(najcescaSadrzi));
    printf("%s\n", veznici);
    printf("%s\n", izbaci_najcescu(veznici));
    printf("%s\n", anone);
    printf("%s\n", izbaci_najcescu(anone));
    printf("%s\n", prazan);
    printf("%s\n", izbaci_najcescu(prazan));
    printf("%s\n", viseRijeci);
    printf("%s\n", izbaci_najcescu(viseRijeci));

	return 0;
}

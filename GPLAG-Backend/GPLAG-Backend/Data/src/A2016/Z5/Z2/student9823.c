#include <stdio.h>
#include <ctype.h>
#include <string.h>

void unesi(char niz[], int velicina)
{
    // obicna funkcija za unos, standard
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	int i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

int isSlovo(int c){
    if((c>='A' && c<='Z') || (c>='a' && c<='z')) return 1;
    return 0;
}

void zamjena(char *s1, char *s2){
    char temp[1000];
    strcpy(temp, s1);
    strcpy(s1, s2);
    strcpy(s2, temp);
}


void kompresuj(char *ulazna, char *izlazna){
    // funkcija iz datotke u matricu upisuje rijeci po broju ponavljanja
    // onda opet prolazimo kroz datoteku i zamjenjujemo rijeci sa znacima ascii-a

    char rijeci[1000][1000] = {0}; // niz od 1k rijeci po 1k karaktera
    int brojac[1000] = {0}; // brojac za svaku rijec
    int i, broj_rijeci = 0;
    char rijec[1000]; // trenutna rijec koju cemo ucitati
    int velicina;
    
    FILE *ulaz = fopen(ulazna, "r");  // otvaramo datoteku 2 puta
    FILE *ulazP = fopen(ulazna, "r");
    FILE *izlaz = fopen(izlazna, "w");
    
    char znak = fgetc(ulaz);
    while(znak !=EOF){
        velicina=0;
        while(isSlovo(znak)){ // ukoliko naletimo na rijec kupimo je
            rijec[velicina] = znak;
            znak = fgetc(ulaz);
            
            if(velicina>10){ 
                while(znak!=' ') znak=fgetc(ulaz);
                velicina=0; 
                break; 
                
            }
            
            velicina++;
        }
        rijec[velicina]='\0'; // terminiramo
        
        if(velicina<10 && velicina!=0){ 
            int postoji =0;
            int k;
            for(k=0;k<broj_rijeci; k++){
                if(strcmp(rijeci[k], rijec) == 0){ // prolazimo kroz matricu
                    postoji = 1;                   // ako ima tu rijec samo povecamo broj
                    brojac[k]++; 
                    break;
                }
            }
            
            if(postoji!=1){ // ako nema rijeci dodajemo i brojac stavljamo na 1
                strcpy(rijeci[broj_rijeci], rijec);
                brojac[broj_rijeci++] = 1;
            }
        }
        znak = fgetc(ulaz);
    }
    
    // sad imamo niz rijeci i niz brojaca
    int j;
    for(i=0;i<broj_rijeci;i++){ // sotriramo nase rijeci po broju ponavljanja i leksikografski
        for(j=i+1;j<broj_rijeci;j++){
            if(brojac[j]>brojac[i] || (brojac[j]== brojac[i] && strcmp(rijeci[i], rijeci[j])>0)){
                int temp=brojac[j];    
                brojac[j]=brojac[i];
                brojac[i]=temp;
                zamjena(rijeci[i],rijeci[j]);
            }
        }
    }
    
    int kraj=10;
    char pomoc='\n';
    if(broj_rijeci<10) kraj=broj_rijeci; // treba nam tacan broj rijeci
    for(i=0;i<kraj;i++){ // unosimo nase rijeci u datoteku
        fputs(rijeci[i], izlaz);
        fputc(pomoc, izlaz);
    }
    
    
    char c = fgetc(ulazP); // drugi put sto smo je otvorili
    while(c!=EOF){
        velicina=0;
        while(isSlovo(c)){ // rijec po rijec
            rijec[velicina] = c;
            c = fgetc(ulazP);
            velicina++;
        }
        rijec[velicina]='\0';
        
        
        int pomocna=0;
        if(velicina<10 && velicina!=0){
            for(j=0;j<kraj;j++){ // ako se nalazi u nizu rijec, mjenjamo je sa znakom u zadatku zadanim
            if(strcmp(rijeci[j],rijec) == 0){
                char znakic = j+20;
                pomocna=1;
                fputc(znakic, izlaz);
                fputc(c, izlaz);
                break;
            }
                
            }
        }   
            if(pomocna==0){
                // ako je nema u nizu samo prekopiramo
                char *a = rijec;
                while(*a!='\0'){
                    fputc(*a, izlaz);
                    a++;
                }
                fputc(c, izlaz);
            }
            
            
            c = getc(ulazP);
        
    }
    printf("Datoteka kompresovana.\n");
    fclose(ulaz);
    fclose(ulazP);
    fclose(izlaz);
}


void dekompresuj(char *ulazna, char *izlazna){
    // funkcija prvo uzme rijeci koje su na pocetku datoteke 
    // stavi ih u niz, i onda tek prolazi kroz datoteku i znakove mjenja sa rijecima

    char rijeci[1000][1000] = {0}; // niz od 1k rijeci po 1k karaktera
    int  broj_rijeci = 0, brojacZSK = 0;
    char pomocna[1000]; // pomocna rijec koju cemo iskoristiti 
    int velicina=0;
    
    int pomocnaZapamtit=0;
    
    FILE *ulaz = fopen(ulazna, "r");  // otvaramo datoteku 2 puta
    FILE *ulazP = fopen(ulazna, "r");
    FILE *izlaz = fopen(izlazna, "w");
    
    char c = fgetc(ulaz);
    while(c != EOF){
        velicina=0;
        pomocnaZapamtit=0;
        
        while(isSlovo(c)){
            pomocna[velicina]=c;
            c=fgetc(ulaz);
            
            if(velicina>10){ 
                while(c!=' ') c=fgetc(ulaz);
                velicina=0; 
                break; 
                
            }
            
            velicina++;
        }
        pomocna[velicina]='\0';
        
        if(velicina<10 && velicina!=0){
            strcpy(rijeci[broj_rijeci], pomocna);
            int i;
            for(i=0;i<broj_rijeci;i++){ // gledamo ima li nase rijeci
                if(strcmp(rijeci[i], pomocna)==0)
                {
                    pomocnaZapamtit=1;
                    break;
                }
            }
                if(pomocnaZapamtit==1) break;
                broj_rijeci++;
            
            
        }
        c = fgetc(ulaz);
    }
    
    brojacZSK=0; // brojimo koliko ima rijeci prije dekompresije
    char znak= fgetc(ulazP);
    while(znak!=EOF){
        if(znak=='\n') brojacZSK++;
        if(brojacZSK == broj_rijeci) break; // kad dodje do zadnje rijeci prekidamo brojanje
        znak = fgetc(ulazP);
    }
    znak = fgetc(ulazP);
    while(znak!=EOF){ // kupimo rijeci i dalje
        int pomozi=0;
        if(znak>=20 && znak<=30){ // ascii od 20 do 30 mjenjamo
            char *pointer = rijeci[znak-20];
            pomozi=1;
        
        while(*pointer!='\0'){ // ubacujemo rijec u datoteku
            fputc(*pointer, izlaz);
            pointer++;
        }
        }
        if(pomozi==0) fputc(znak, izlaz); // ako nije znak isto kao gore prepisujemo samo
        znak = fgetc(ulazP);
        
    }
    printf("Datoteka dekompresovana.\n");
    
    fclose(ulaz);
    
    
    fclose(ulazP);
    
    
    fclose(izlaz);

}




int main(){

    int opcija;
    char string1[100], string2[100];
    do{
        printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
        scanf("%d", &opcija);
        switch(opcija){
            case 1: // unosimo ime ulazne i izlazne i ide kompresija
            printf("Unesite ime ulazne datoteke: ");
            unesi(string1, 40);
            printf("Unesite ime izlazne datoteke: ");
            unesi(string2, 40);
            
            kompresuj(string1, string2);
            break;
            
            case 2: // unosimo ime ulazne i izlazne i ide dekompresija
            printf("Unesite ime ulazne datoteke: ");
            unesi(string1, 40);
            printf("Unesite ime izlazne datoteke: ");
            unesi(string2, 40);
            dekompresuj(string1, string2);
            break;
        }
    }while(opcija!=0); 
    return 0;
}
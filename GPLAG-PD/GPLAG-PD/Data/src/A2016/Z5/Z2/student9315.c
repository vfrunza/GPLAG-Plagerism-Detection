#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//A
struct rijec{
    char sadrzaj[10];
    int brojPon;
};

int jeSlovo(char c){
    if((c >= 'A' && c <= 'Z') ||(c >= 'a' && c <= 'z'))
    return 1;
    return 0;
}
int vecSeNalazi(char *x, struct rijec *niz, int size){
    //vraca indeks x u nizu niz ako se nalazi, -1 ako se ne nalazi
    int i;
    for(i = 0; i < size; i++){
        if(strcmp(x, niz[i].sadrzaj) == 0){
         return i;   
        }
    }
    return -1;
}
int popuniRijeci(struct rijec *niz, FILE *ulaz){
    //samo cemo popunjavati rijeci manje od 10 znakova po uslovu zadatka, time stedimo i memoriju bla bla, vraca broj popunjenih rijeci
    char c;
    struct rijec temp;
    char rijec[10];
    int i,j,max,pozNiz = 0, validna = 0, indeks;//validna ako ima manje od 10 slova, vise od 1
    do{
        c = fgetc(ulaz);
        if(jeSlovo(c)){
            i = 0;
            validna = 0;
            do{
                rijec[i++] = c;
                c = fgetc(ulaz);
                if(i == 10){///////////////////////////11
                    while(jeSlovo(c = fgetc(ulaz)));
                }
            }while(!feof(ulaz) && jeSlovo(c));
            if(i > 1 && i < 10){
                validna = 1;
                rijec[i] = '\0';
            }
            if(validna){
                indeks = vecSeNalazi(rijec, niz, pozNiz);
                if(indeks == -1){
                    strcpy(niz[pozNiz].sadrzaj, rijec);
                    niz[pozNiz].brojPon = 1;
                    pozNiz++;
                }else{
                    niz[indeks].brojPon++;
                }
            }
        }
        
    }while(!feof(ulaz));
    //sad cemo sortirati niz bla bla
    for(i = 0; i < pozNiz; i++){
        max = i;
        for(j = i; j < pozNiz; j++){
            if(niz[j].brojPon > niz[max].brojPon || (niz[j].brojPon == niz[max].brojPon && strcmp(niz[j].sadrzaj,niz[max].sadrzaj) < 0)){
                max = j;
            }
        }
        temp = niz[i];
        niz[i] = niz[max];
        niz[max] = temp;
    }
    
    return pozNiz;
}
void dekompresuj(char *imeUlaz, char *imeIzlaz){
    FILE *ulaz;
	FILE *izlaz;
	struct rijec rijeci[1000];
	struct rijec lista[10];
	char rijec[11];
	int numListe = 0;//max 10 rijeci
	int num, i, validna,indeks,bioNewLine = 0, brRijeci = 0;
	char c, temp, nLine;
	
	if ((ulaz = fopen(imeUlaz,"r")) == NULL) {
        printf("Greska pri otvaranju datoteke %s", imeUlaz);
        exit(1);
    }
    if ((izlaz = fopen(imeIzlaz,"w")) == NULL) {
        printf("Greska pri otvaranju datoteke %s", imeIzlaz);
        exit(1);
    }
    fseek(ulaz, 0, SEEK_SET);
    
    do{
        nLine = fgetc(ulaz);
        if(bioNewLine && nLine == '\n'){
            break;
        }
        bioNewLine = 0;
        if(nLine == '\n'){
            brRijeci++;
            bioNewLine = 1;
            if(brRijeci == 10)
                break;
        }
    }while(nLine != EOF);
     fseek(ulaz, 0, SEEK_SET);
     
	while( numListe < brRijeci){
	    if(fscanf(ulaz, "%s\n", lista[numListe].sadrzaj) != 1 ){
	        break;
	    }
	    numListe++;
	}
	
    fseek(ulaz, 0, SEEK_SET);
    //pomjeramo se do dijela gdje je tekst
    i = 0;
    while( i < brRijeci){
        c = fgetc(ulaz);
        if( c == '\n')
        i++;
    }
    if(brRijeci != 10)
    fgetc(ulaz);
    do{
        c = fgetc(ulaz);
        if(c >= 20 && c <= 29 ){
            fprintf(izlaz, "%s", lista[c - 20].sadrzaj);
        }else{
            if(c!= EOF)
            fprintf(izlaz, "%c", c);
        }
    }while(c != EOF);
    printf("Datoteka dekompresovana.\n");
    fclose(ulaz);
    fclose(izlaz);
}

void kompresuj(char *imeUlaz, char *imeIzlaz){
	FILE *ulaz;
	FILE *izlaz;
	struct rijec rijeci[1000];
	char rijec[10];
	int num, i, validna,indeks;
	char c, temp;
	
	if ((ulaz = fopen(imeUlaz,"r")) == NULL) {
        printf("Greska pri otvaranju datoteke %s", imeUlaz);
        exit(1);
    }
    if ((izlaz = fopen(imeIzlaz,"w")) == NULL) {
        printf("Greska pri otvaranju datoteke %s", imeIzlaz);
        exit(1);
    }
    
    num = popuniRijeci(rijeci, ulaz);
    //printf("%d", num);
    for(i = 0; i < num; i++){
        if(i == 10)
            break;
        fprintf(izlaz, "%s\n", rijeci[i].sadrzaj);
    }
    if(num < 10)
    fprintf(izlaz, "\n");
    fseek(ulaz, 0, SEEK_SET);
    do{
        c = fgetc(ulaz);
        if(jeSlovo(c)){
            i = 0;
            validna = 0;
            do{
                if(i > 8){
                    rijec[i] = '\0';
                    fprintf(izlaz, "%s%c",rijec, c);
                    while(jeSlovo(c = fgetc(ulaz))){
                        fprintf(izlaz, "%c", c);
                    }
                    if(c != EOF);
                    //fprintf(izlaz, "%c", c);
                }
                else{
                    rijec[i++] = c;
                    c = fgetc(ulaz);
                }
                
            }while(!feof(ulaz) && jeSlovo(c));
            if(!jeSlovo(c)){
                temp = c;
            }
            if(i > 1 && i < 10){//9
                validna = 1;
                rijec[i] = '\0';
            }
            if(validna){
                indeks = vecSeNalazi(rijec, rijeci, num);
                if(indeks < 10 && indeks != -1){
                    fprintf(izlaz, "%c", (char) (20 + indeks));    
                }
                else if(i < 9){
                    fprintf(izlaz, "%s", rijec);
                }
                
                if(temp != EOF)
                fprintf(izlaz, "%c", temp);
            }
            else if(i == 1){
                fprintf(izlaz, "%c", rijec[0]);
                if(temp != EOF)
                    fprintf(izlaz, "%c", temp);
            }
        }
        else{
            fprintf(izlaz, "%c", c);
        }
        
    }while(!feof(ulaz));
    printf("Datoteka kompresovana.\n");
    fclose(ulaz);
    fclose(izlaz);
}

int main() {
	int val;
	char ulaz[100], izlaz[100];
	do{
	    printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
	    scanf("%d", &val);
	    
	    if(val == 1){
	        printf("Unesite ime ulazne datoteke: ");
	        scanf("%s", ulaz);
	        printf("Unesite ime izlazne datoteke: ");
	        scanf("%s", izlaz);
	        kompresuj(ulaz, izlaz);
	    }
	    else if(val == 2){
	        printf("Unesite ime ulazne datoteke: ");
	        scanf("%s", ulaz);
	        printf("Unesite ime izlazne datoteke: ");
	        scanf("%s", izlaz);
	        dekompresuj(ulaz, izlaz);
	    }
	}while(val != 0);
	return 0;
}
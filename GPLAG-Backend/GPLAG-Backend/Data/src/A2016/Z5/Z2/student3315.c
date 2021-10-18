#include <stdio.h>
#include <ctype.h>
#include <string.h>

void unesi(char niz[], int velicina) {      //funkcija iz predavanja, unos stringa
    char znak=getchar();
    if(znak=='\n') znak=getchar();
    int i = 0;
    while (i<velicina-1 && znak!='\n') {
        niz[i]=znak;
        i++;
        znak=getchar();
        }
    niz[i]='\0';
 }

int slovo(int c){   //funkcija vrati 1 ako je znak koji je primila slovo
	if (c>='A' && c<='Z' || c>='a' && c<='z')
		return 1;
	return 0;
}

void swap(char*p, char *q){ //funkcija primi 2 stringa, i zamijeni ih
	char temp[100];
	strcpy(temp,p);
	strcpy(p,q);
	strcpy(q,temp);
}
/* FUNKCIJA IZ DATOTEKE U NIZ RIJECI UPISE RIJECI PO BROJU POANVLAJNJA, ZATIM PRODJEMO OPET KROZ DATOTEKU I ZAMJENJUJEMO RIJECI SA ZNACIMA IZ ASCCI VRIJEDNOSTI*/
void kompresuj(char* naziv, char*naziv1){
    FILE *ulaz=fopen(naziv,"r");    //otvorimo datoteku za ulaz 2 puta, i jednu za izlaz
    FILE *ulaz1=fopen(naziv,"r");
    FILE *izlaz=fopen(naziv1,"w");
    char rijeci[1000][1000] = {0}; //niz od 1000 rijeci od po 1000 znakova
    int brojac[1000] = {0};     //brojac za svaku rijec koliko se puta ponalvnja
    int i, broj_rijeci = 0;
    char rijec[1000];       //trenuta rijec koju ucitamo
    int duzina; 
    char znak=fgetc(ulaz); 
    while(znak!=EOF) {  //dok ne dodjemo do kraja datoteke uzimamo znak po znak
        duzina = 0; 
        while (slovo(znak)) {   //dok je znak nas slovo, znaci da smo na rijeci i uzmemo sva slova, ubacimo u nasu trenutnu rijec
            rijec[duzina++] = znak;
            znak=fgetc(ulaz);
        }
        rijec[duzina] = '\0';   //na kraju nase trenutne rijeci stavimo \0
        if (duzina <10 && duzina!=0) {      //ako je duzina rijeci onakva kakva treba bit u zadatku  treba nesto raditi s njom....
            int ima = 0; 
            int j;
            for ( j = 0; j < broj_rijeci; j++) {    //prodjemo kroz rijeci koje smo do sada upisali u nasu matricu rijeci
                if (strcmp(rijeci[j], rijec) == 0) {    //ako ima vec rijec tu, samo joj broj ponavljanja povecamo
                    ima = 1;
                    brojac[j]++;
                    break;
                }
            }
            if (ima!=1) {                   //ako je nema , moramo je dodat i brojac joj stavit na 1
                strcpy(rijeci[broj_rijeci], rijec); 
                brojac[broj_rijeci++] = 1;
            }
        }
    znak=fgetc(ulaz);
    }
    //do sad smo u nas niz rijeci unijeli svaku rijec i u niz brojac koliko se puta ponavlja
    int j;
    for(i=0;i<broj_rijeci;i++){  //sotriramo nase rijeci po brjou ponavljanja i leksiikografski
        for(j=i+1;j<broj_rijeci;j++){
            if(brojac[j]>brojac[i] || (brojac[j]==brojac[i] && strcmp(rijeci[i],rijeci[j])==1)){
                int temp=brojac[j];    
                brojac[j]=brojac[i];
                brojac[i]=temp;
                swap(rijeci[i],rijeci[j]);
            }
        }
    }
    int kraj=10;
    char novired='\n';
    if(broj_rijeci<10) kraj=broj_rijeci; //treba nam 10 rijeci, a ako ih ima manje onda to koristimo
    for(i=0;i<kraj;i++){      //prvo unosimo u izlaz nase rijeci koje imamo u nizu
        fputs(rijeci[i],izlaz);
        fputc(novired,izlaz);
    }
    
    char c=fgetc(ulaz1);        //opet otvaramo nasu ulaznu datoteku
    while(c!=EOF) {
        duzina = 0; 
        while (slovo(c)) {    //uzimamo rijec po rijec
            rijec[duzina++]=c;
            c=fgetc(ulaz1);
        }
        rijec[duzina] = '\0'; 
       
       int kontrola=0;
         if (duzina<10 && duzina!=0) { 
            for ( j = 0; j < kraj; j++) { //ako se ona nalazi u nasem nizu mijenjamoje sa odg znakom receno u datatku
                if (strcmp(rijeci[j], rijec) == 0) { 
                char znk=j+20;
                kontrola=1;
                    fputc(znk,izlaz);
                    fputc(c,izlaz);
                    break;
            } }
        }
           if(kontrola==0){      //ako je nema u nizu onda je samo prekopiramo, tj ne treba je mijenjat
               char*r=rijec;
               while(*r!='\0'){
                    fputc(*r,izlaz);
                    r++;
               }
               fputc(c,izlaz); 
           }
     c=fgetc(ulaz1); 
 	}
    printf("Datoteka kompresovana.\n"); //zatvorimo sve datoteke
    fclose(ulaz);
    fclose(ulaz1);
    fclose(izlaz);
}   
/*FUNKCIJA PRVO UZME RIJECI KOJE SU NA POCETKU DATOTEKE, I STAVI IH U NIZ, I ONDA PRODJE KROZ DAOTEKU I ZNAKOVE ZAMJENJUJE RA RIJECIMA */
void dekompresuj(char*naziv, char*naziv1){
    FILE *ulaz=fopen(naziv,"r"); // isto kao i gore otvorimo 2 za ulaz i 1 za izlaz
    FILE *ulaz1=fopen(naziv,"r");
    FILE *izlaz=fopen(naziv1,"w");
    char rijeci[1000][1000]={0}, rijec[1000];  //isto imamo matrice rijeci, i pomocnu rijec kao i gore
    int  broj_rijeci=0, duzina=0, brojackrajeva=0;
    char znak=fgetc(ulaz);
    int kontrola=0;
    while(znak!=EOF){  
         duzina=0;
         kontrola=0;
         while (slovo(znak)) { //opet uzimamo rijec po rijec,smjestamo u niz
            rijec[duzina++] = znak;
            znak=fgetc(ulaz);
        }
         rijec[duzina] = '\0';
      
        if (duzina <10 && duzina!=0) { //ako moze biti rijec zadana
            strcpy(rijeci[broj_rijeci], rijec);  //prekoiramo u niz rijeci 
            int j;
            for ( j = 0; j < broj_rijeci; j++) { //u nasem nizu vidimo da li ima nasa rijec   
                if (strcmp(rijeci[j], rijec) == 0) { 
                    kontrola=1; 
                	break;
				}
            }
            if(kontrola)
            	break;
            broj_rijeci++; 
            }
    znak=fgetc(ulaz);
    }
brojackrajeva=0;//izbrojimo koliko ima rijeci

char c=fgetc(ulaz1);
    
    while(c!=EOF){ 
        if(c=='\n')  brojackrajeva++; //brojimo nova mjesta
         if(brojackrajeva==broj_rijeci) break;  //kad dodjemo do zadnje rijeci, prekidamo petlju, al pok ostane na tekstu poslije
     c=fgetc(ulaz1);
    }
    c=fgetc(ulaz1);
        while(c!=EOF){//nasstavimo dalje uzimat rijeci 
            int n=0;
            if(c>=20 && c<=30){ //sve znakove od 20 do 30 mijenjamo rijecima
                 char*p=rijeci[c-20]; 
                 n=1;
             while(*p!='\0'){ //ubacimo rijec
                 fputc(*p,izlaz);
                 p++;
             }
         }
         if(n==0) //ako nije znak , onda samo prepisujemo rijeci
             fputc(c,izlaz);
        c=fgetc(ulaz1);
        }
printf("Datoteka dekompresovana.\n");
fclose(ulaz);
fclose(izlaz);
fclose(ulaz1);
}
int main(){
    int opcija;
    char s[100], p[100];
  	do{
    printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
    scanf("%d",&opcija);
    switch(opcija){
        case 1: // unesemo ulaznu i izlaznu dat i vrsimo kompresiju
             printf("Unesite ime ulazne datoteke: ");
             unesi(s,40);
	         printf("Unesite ime izlazne datoteke: ");
             unesi(p,40);
             kompresuj(s,p);
             break;
        case 2: //isto samo dekompresujemo
             printf("Unesite ime ulazne datoteke: ");
             unesi(s,40);
             printf("Unesite ime izlazne datoteke: ");
             unesi(p,40);
             dekompresuj(s,p);
    }
  }while(opcija!=0);
return 0;
}
#include <stdio.h>
#include <ctype.h>

void unesi(char niz[], int velicina){ //funkcija iz predavanja, unos stringa
   char znak=getchar();
   if(znak=='\n') znak=getchar();
   int i=0;
    
   while(i<velicina-1 && znak!='\n'){
        niz[i]=znak;
        i++;
        znak=getchar();
    }
   niz[i]='\0';
}

int uporedi(char* s1, char* s2){ //funkcija iz predavanja koja leksikografski poredi 2 stringa
    while(*s1!='\0' && *s2!='\0'){
        if(*s1<*s2) return -1; //ako prvi string treba biti ispred drugog vraca -1
        if(*s1>*s2) return 1; //ako drugi string treba biti ispred prvog vrati 1
        s1++; s2++;
    }
        if(*s1!='\0') return 1; //ako prvi string nije dosao na kraj, tj. jos ima slova, drugi je ispred njega i vrati 1
        if(*s2!='\0') return -1; //ako drugi string nije dosao na kraj, tj. ima jos slova, prvi je ispred njega i vrati -1
        return 0; //ako su 2 ista stringa, vrati 0, zbog ovog nam treba funkcija
}

int Strlen(char* s){ //funkcija vraca duzinu primljenog stringa
    int duzina=0;
    while(*s!='\0'){
        duzina++;
        s++;
    }
return duzina;
}

void my_strcpy(char* s1, char* s2){ //funkcija prekopira drugi string u prvi
    while(*s2!='\0')
    *s1++=*s2++;
    *s1='\0';
}

void kompresuj(char* ime, char* imed){ 
    FILE* ulaz=fopen(ime,"r"); //otvorimo sve potrebne datoteke, samo ce nam trebati dva pokazivaca na prvu iz koje citamo
    FILE* ulaz1=fopen(ime,"r");
    FILE* izlaz=fopen(imed,"w");
    
char rijeci[1000][1000]={{0}}; //imamo niz od max 1000 rijeci kojima je duzina max 1000 i tu cemo  sve rijeci iz ulazne datoteke upisati
    
int brojac[1000]={0};//brojac ponavljanja za svaku rijec na pocetku su 0
int i, rijec_cnt=0; //broj rijeci u nasem nizu
int clen; //duzina trenutne rijeci
char rijec[1000]; //trenutna rijec kao pomocna
char znak=fgetc(ulaz); //da bi usli u while petlju moramo znak postaviti na nesto

while(znak!=EOF){//idemo do kraja ulazne datoteke i uzimamo sve rijeci i ubacimo ih u nas niz rijeci
    clen=0;
    while(isalpha(znak)){//dok je znak, to spasavamo u nasu pomocnu rijec
        rijec[clen]=znak;
        clen++;
        znak=fgetc(ulaz);
    }
   
if(clen>0 && clen<10){//ako je duzina pomocne u zadanom opsegu, upisujemo je u niz rijeci
    rijec[clen]='\0';

int nasao_rijec=0, j;
      
    for(j=0;j<rijec_cnt;j++){ //posto svaka rijec treba biti jednom u nizu, a na istoj poziciji, provjerimo da li je rijec vec u nizu, ako jeste samo brojac povecamo za 1 te rijeci 
        if(uporedi(rijeci[j], rijec)==0){ //rijec jeste u nizu
            nasao_rijec=1;
            brojac[j]++;
            break;
        }
    }
    
    if(nasao_rijec==0){//ako nije nasao rijec do tada, moramo je upisati i staviti joj brojac na 1 i broj rijeci povecao se za 1
        my_strcpy(rijeci[rijec_cnt],rijec);
        brojac[rijec_cnt]=1;
        rijec_cnt++;
        }    
    }
    znak=fgetc(ulaz); //posto smo u while petlji dok ne dodjemo do kraja, idemo u krug
}
    
int j;
   for(i=0;i<rijec_cnt;i++){ //sortiramo niz rijeci po broju ponavljanja, a ako je br ponavljanja isti onda leksikografski
        for(j=i+1;j<rijec_cnt;j++){
            if(brojac[j]>brojac[i] || (brojac[j]==brojac[i] && uporedi(rijeci[i],rijeci[j])==1)){
                int temp=brojac[j]; //zamijenimo brojace, a ujedno zamijenimo i rijeci
                brojac[j]=brojac[i];
                brojac[i]=temp;
                
                char temp1[100];
                my_strcpy(temp1,rijeci[i]);
                my_strcpy(rijeci[i], rijeci[j]);
                my_strcpy(rijeci[j], temp1);
            }  
        }
    }
int dokle=10; //po defaultu treba biti 10 rijeci, ali ako ima manje od deset, onda idemo do broja koliko ih ima
    
if(rijec_cnt<10) dokle=rijec_cnt;
   
for(i=0;i<dokle;i++){ //te rijeci upisujemo u izlaznu datoteku, svaka u novom redu
    fputs(rijeci[i],izlaz);
    fputc('\n', izlaz);
}
    
char z=fgetc(ulaz1); //sa novim pokazivacem prodjemo opet kroz datoteku i upisujemo u izlaznu, ali mijenjamo rijec sa znakovima
    
    while(z!=EOF){
        clen=0;
        
        while(isalpha(z)){ //uzimamo znakove dok su slova i spasavamo u pomocnu rijec
            rijec[clen]=z;
            clen++;
            z=fgetc(ulaz1);
            }
            rijec[clen]='\0';
            
            int des=0;
            
            if(clen>0 && clen<10){
                for(j=0;j<dokle;j++){
                    if(uporedi(rijeci[j],rijec)==0){ /*ako je nasa pomocna rijec neka rijec iz niza rijeci, trebamo zamijeniti sa ascii
                    vrijednoscu od 20 do 29 i to ubacimo u izlaznu*/
                        char znk=j+20;
                        des=1;
                        fputc(znk,izlaz);
                        fputc(z,izlaz);
                        break;
                    }
                }
            }
            if(des==0){ //ako nasa pomocna rijec nije u nizu, onda je ne treba mijenjati, pa samo nju upisemo u izlaznu
                char* r=rijec;
                while(*r!='\0'){
                    fputc(*r,izlaz);
                    r++;
                }
                
                fputc(z,izlaz);//znak nam je nesto iza nase trenutne rijeci, vjerovatno space, pa to ubacimo poslije nase rijeci
                
            }
            z=fgetc(ulaz1); //uzimamo novi znak i idemo while petljom u krug
    }
    
printf("Datoteka kompresovana.\n");
fclose(ulaz);
fclose(ulaz1);
fclose(izlaz);
    
}

void dekompresuj(char* ime, char* imed){
    FILE* ulaz=fopen(ime,"r"); //kao i gore otvorimo datoteke
    FILE* ulaz1=fopen(ime,"r");
    FILE* izlaz=fopen(imed,"w");
    
char rijeci[1000][1000]={0}, rijec[1000]; //promjenjive analogne onim u prethodnoj funkciji
int brojac[1000]={0}, rijec_cnt=0, i, clen, brojrijeci,brojackrajeva; //posto su u nasoj datoteci sada rijeci, pa tekst, moramo znati koliko ima rijeci
    
char znak=fgetc(ulaz);
    
while(znak!=EOF){ //prodjemo kroz datoteku, pokupimo samo one rijeci
    clen=0;
    while(isalpha(znak) && znak!='\n'){ //u nasu trenutnu rijec zapamtimo svaki znak do \n posto su nam rijeci odvojene novim redom
        rijec[clen]=znak;
        clen++;
        znak=fgetc(ulaz);
    }
    rijec[clen]='\0';
        
    if(clen>0 && clen<10){ //u nas niz upisemo rijeci koje smo nasli
        my_strcpy(rijeci[rijec_cnt],rijec);
        
        int j;
        
        for(j=0;j<rijec_cnt;j++){
            if(uporedi(rijeci[j],rijec)==0){//kad nadjemo rijec neku i u nasem nizu, a da se opet pojavila, onda smo pokupili sve rijeci i trebamo upisivati tekst
                goto gotov; //odmah izadjemo ako smo pokupili sve rijeci
            }
        }
        rijec_cnt++; //ako smo ubacivali rijec, onda se velicina mora povecati za 1
        }
    znak=fgetc(ulaz); //while petlja
        
    }
    gotov:
    //velicina naseg niza rijeci je broj koliko smo pokupili rijeci koje treba zamijeniti
    brojrijeci=rijec_cnt; brojackrajeva=0;

    char z=fgetc(ulaz1);
    
    while(z!=EOF){ //sa novim pokazivacem opet prodjemo kroz nasu datoteku, sad brojimo rijeci, kad prodjemo broj rijeci iz niza, onda ide tekst
        if(z=='\n') brojackrajeva++;
        if(brojackrajeva==brojrijeci) goto kraj;//dosli do teksta i izadjemo
        z=fgetc(ulaz1);
    }
    
    kraj: //ovdje nastavljamo i idemo po tekstu i svaki znak zamjenimo sa odgovarajucom rijeci iz naseg niza
    
    z=fgetc(ulaz1);
    while(z!=EOF){
        int n=0;
        
        if(z>=20 && z<=30){//ako nadjemo ascii vrijednost od 20 do 29 koje smo ubacili u kompresuj funkciji
            char* p=rijeci[z-20]; //pokazivac na rijec koju treba ubaciti
            n=1;
            while(*p!='\0'){//na to mjesto ubacimo odgovarajucu rijec
                fputc(*p,izlaz);
                p++;
            }
        }
    if(n==0) fputc(z,izlaz);//ako nismo ubacivali, znaci da je neki obican znak i njega ubacujemo u izlaz
    z=fgetc(ulaz1);
        
    }
    
printf("Datoteka dekompresovana.\n");
fclose(ulaz);
fclose(izlaz);
fclose(ulaz1);
}

int main(){
    
   int broj;
   char s[100], p[100];
   
   do{
       
       printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
       scanf("%d", &broj);
       
    switch(broj){
        
        case 1:
        
        printf("Unesite ime ulazne datoteke: ");
        unesi(s,40);
        printf("Unesite ime izlazne datoteke: ");
        unesi(p,40);
        kompresuj(s,p);
        break;
        
        
        case 2:
        printf("Unesite ime ulazne datoteke: ");
        unesi(s,40);
        printf("Unesite ime izlazne datoteke: ");
        unesi(p,40);
       dekompresuj(s,p);
    }
   }
   while(broj!=0);
  
    
    return 0;
}
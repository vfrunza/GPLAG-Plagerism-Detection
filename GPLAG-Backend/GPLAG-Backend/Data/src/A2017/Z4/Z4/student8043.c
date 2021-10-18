#include <stdio.h>

int provjeri(char * s){
    char * cita = s; 
    char *pocetak_rijeci = s;
    int brojac = 0;
    int brojac_2 = 0;
    int otvorene = 0;
    int zatvorene = 0;
    char *pom;
    char *pomocni_pocetak;
    int help = 0;
    while(*cita != '\0'){
        
        if(*cita == '<'){
            
            cita++;
            //ako poslije < procita nesto drugo sto nije slovo ili cifra ili / ne valja jer onda nije tag kako treba
            if(!((*cita >= 'A' && *cita <= 'Z') ||  (*cita >= 'a' && *cita <= 'z') || (*cita >= '0' && *cita <= '9') || *cita== '/')) {return 0;}
            //ako je naisao na </ zatvoren tag da preskoci ovo dole sve
            if(*cita == '/') {
                cita++;
                continue;
            }
            
            pocetak_rijeci = cita;
        
            brojac = 0;
            
            //sve dok unutar taga cita slova ili brojeve da ih izbroji radi kasnijeg poredjenja sa zatvorenim tagom 
            while((*cita >= 'A' && *cita <= 'Z') ||  (*cita >= 'a' && *cita <= 'z') || (*cita >= '0' && *cita <= '9')){
                brojac++;
                cita++;
            }
            //treba da preskoci sve sto se nalazi unutar tog taga tipa atribute i sl href = "hjdhjsj"
            while(*cita != '>' && *cita != '\0') {
                cita++;
            }
            
            //ako je dosao do kraja a nije nasao > znaci da ne valja
            if(*cita == '\0') {return 0;}
            
            //sve dok ne nadje prvo slovo koje odgovara prvom slovu ovog taga kojeg posmatramo da se pomjera
            while(*cita != *pocetak_rijeci && *cita != '\0'){
                
                //ako nadjemo < znaci da zapocinje novi tag 
                if(*cita == '<'){
                    if(*(cita++) == '\0') {return 0;}
                     
                    if(*(cita) == '/'){
                        if(*(cita+1) == *pocetak_rijeci) {cita++;break;}
                        
                        while(*cita != '>' && *cita != '\0') cita++;
                        if(*cita == '\0') {
                           
                            return 0;
                        }
                        zatvorene++;
                    }
                    else if((*cita >= 'A' && *cita <= 'Z') ||  (*cita >= 'a' && *cita <= 'z') || (*cita >= '0' && *cita <= '9')){
                        
                        while(*cita != '>' && *cita != '\0') cita++;
                        if(*cita == '\0') {
                        return 0;}
                        otvorene++;
                    }
                }
                
                cita++;
            }
          
            pomocni_pocetak = pocetak_rijeci;
            pom = cita;
            if(*cita == *pomocni_pocetak){
                
                brojac_2=0;
                while(*cita == *pomocni_pocetak && *pomocni_pocetak != '\0' && *cita != '\0' && *cita != '>'){
                    brojac_2++;
                   
                    cita++;
                    pomocni_pocetak++;
                }
            
                if(brojac_2 != brojac) { help = 1; continue;}
                
                else{
                 
                    
                    if(*(pom-1)!= '/' || zatvorene != otvorene){
                      
                           return 0; 
                    } 
                       
                }
                
                    
            }
            
            if(help == 1) cita = pocetak_rijeci-1;
        }
        cita++;
    }
    //if(nasao == 0)return 0;
    return 1;
    
   /* char *cita = s;
    char *niz_otvorenih[25];
    char *niz_zatvorenih[25];
    int i=0;
    int j =0;
    int k, l;
    int nasao = 0;
    while(*cita != '\0'){
        if(*cita == '<'){
            cita++;
            if(*cita == '/') niz_zatvorenih[j] = ++cita;
            else if (((*cita >= 'A' && *cita <= 'Z') ||  (*cita >= 'a' && *cita <= 'z') || (*cita >= '0' && *cita <= '9') || *cita== '/')) niz_otvorenih[i]=cita;
            else return 0;
        }
        cita++;
    }
    if(i!=j) return 0;
    
    for(k = 0; k <= i; k++){
        nasao = 0;
        for(l = 0; l <= j; l++){
           if(*niz_otvorenih[k] == *niz_zatvorenih[l]){
               char *otvoreni = niz_otvorenih[k];
               char *zatvoreni = niz_zatvorenih[l];
           while(*otvoreni == *zatvoreni && *otvoreni != '\0' && *zatvoreni !='\0' && *otvoreni != ' ' && *otvoreni != '>'){
                   otvoreni++;
                   zatvoreni++;
                   
               }
               if((*otvoreni == ' ' || *otvoreni == '>') && *zatvoreni=='>') {
                   nasao = 1;
                   break;
               }
           }
        }
        if(nasao == 0) return 0;
    }
    return 1;*/
}
int main(){
char tekst1[] = "<div id=\"tekst\"><h2>Naslov</h2><p>Ovo je <b>cetvrti</b> i <i>posljednji</i> zadatak iz <a href=\"zadaca4\">zadace 4</a></p></div>";
char tekst2[] = "<b><a>proba</b></a>";
printf("%d ", provjeri(tekst1));
printf("%d ", provjeri(tekst2));
    return 0;
}
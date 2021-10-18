#include <stdio.h>

int slovaJednaka(char a, char b){
    if(a >= 'A' && a <= 'Z') a += 32;
    if(b >= 'A' && b <= 'Z') b +=32;
    
    return a == b;
}

//Funkcija unesi, kopirana iz tut9 2. zad radi testiranja
void unesi(char niz[], int velicina) {
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

int provjeri(char *str){
    //s za string, p pomocni, pi pocetak intervala, a ki kraj intervala
    //po i ko su pocetak i kraj otvorenog taga, a pz i kz su pocetak i kraj zatvorenog taga
    //ppi i kpi su pocetak i kraj podintervala
    char *s, *p, *r, *pi, *ki, *pz, *kz, *po, *ko, *ppi, *kpi, *e;
    s = p = r = pi = ki = po = ko = pz = kz = ppi = kpi = e = str;
    
    int postaviPocetniInterval = 1;
    int nemaTagova = 1;
    
    //Postavi pocetak intervala na kraj, pretpostavi ga takvog
    while(*pi != '\0') pi++;
    ppi = pi;
    e = pi-1;
    //Zanemari razmake na pocetku i kraju stringa
    while(*e == ' ') e--;
    while(*str == ' ') str++;
    
    //Kreni od drugog karaktera i trazi "</"
    s++;
    
    while(*s != '\0'){
        
        //Nadji pocetak zatvorenog taga
        if(*s == '/' && *(s-1) == '<'){
            //Ima tagova xaxa
            nemaTagova = 0;
            //Pocetak zatvorenog taga
            pz = s-1;
            
            //Ako karakter nakon </ nije slovo
            s++;
            if(*s < 'A' || (*s > 'Z' && *s < 'a') || *s > 'z') return 0;
            
            //Pocetak naziva taga
            p = s;
            
            //Nadji '>', ne prolazi interval
            while(*s != '>' && *s != '\0')
                s++;
            // ako '</' postoji, a nema '>' => ne valja xaxa
            if(*s == '\0') return 0;
            
            //Kraj zatvorenog taga
            kz = s;
            
            s = pz-1;
            
            if(s < str) return 0;
            
            //Vracaj se unazad i trazi prvi otvoreni tag, trazi '<'
            while(s >= str && *s != '<'){
                //Preskoci interval i podinterval
                if(s == kpi) s = ppi;
                if(s == ki) s = pi;
                
                s--;
            }
            
            //s je prosao string, a nije nasao '<' => ne valja
            if(s < str) return 0;
            
            //Pocetak otvorenog taga
            po = s;
            
            //Ako karakter nakon '<' nije slovo => ne valja
            s++;
            if(*s < 'A' || (*s > 'Z' && *s < 'a') || *s > 'z') return 0;
            
            //Pocetak naziva taga
            r = s;
            
            //Naci '>' otvorenog taga, trazi do pocetka intervala
            while(*s != '>' && s != pi && s != '\0'){
                s++;
            }
            //Nije nadjen '>' za otvoreni tag
            if(s == pi || *s == '\0') return 0;
            
            //Kraj otvorenog taga
            ko = s;
            
            //Prolazi kroz karaktere naziva otvorenog i zatvorenog taga dok su jednaki i (slovo ili broj)
            while((*p != '\0' && p != kz && r != ko && *r != ' ' && *p != ' ') && slovaJednaka(*p, *r)){
                //Funkcija slovaJednaka provjerava jednakost karaktera bez obzira bilo veliko ili malo slovo

                //Karakter nije ni slovo ni broj 
                //(prvi karakter naziva sigurno jeste slovo, provjereno ranije vec)
                if(*p < '0' || (*p > '9' && *p < 'A') || (*p > 'Z' && *p < 'a') || *p > 'z') return 0;
                if(*r < '0' || (*r > '9' && *r < 'A') || (*r > 'Z' && *r < 'a') || *r > 'z') return 0;
                
                p++;
                r++;
            }
            
            s = p;
            //Provjeriti razmake nakon naziva u zatvorenom tagu
            while(s < kz && *s == ' '){
                s++;
            }
            //Nisu sve razmaci u zatvorenom tagu nakon naziva
            if(s != kz) return 0;
            
            //Moraju nakon niza jednakih karaktera biti ili razmak ili '>' (posto smiju biti razmaci, ali samo razmaci
            //nakon naziva u zatvorenom tagu, dok u otvorenom moze biti atributa raznih, oni me ne zanimaju
            //tako da moze biti tehnicki bilo sta nakon naziva i razmaka u otvorenom tagu),
            //u suprotnom to znaci da nazivi ne odgovaraju
            if(!( (*r == ' ' || *r == '>') && (*p == '>' || *p == ' ') ) ) return 0;
            

            //Pocetni slucaj, potrebno postaviti osnovni interval na pocetku
            if(postaviPocetniInterval){
                pi = po;
                ki = kz;
                
                postaviPocetniInterval = 0;
            }else{
                
                if(po > ki){
                    if(po < ppi)
                        ppi = po;
                    kpi = kz;
                }else if(po < pi){
                    pi = po;
                    ki = kz;
                }
                
                
            }
            
            //s nastavlja nakon intervalaa
            if(ki >= kpi) s = ki;
            else s = kpi;
        }
        
        s++;
    }
    
    //Ostalo gluposti nakon zatvorenog intervala
    if(!nemaTagova && ( (pi != str && ppi != str) || (ki != e && kpi != e) )) return 0;
    
    //Nema zatvorenih, vidi jel' ima otvorenih
    s = str;
    if(nemaTagova){
        while(*s != '\0'){
            if(*s == '<' || *s == '>'){
                return 0;
            }
            
            s++;
        }
    }
    
    //Sve oke
    return 1;
}

int main() {
	char html[1000];
	unesi(html, 1000);
	
	printf("Oke: %d", provjeri(html));
	
	return 0;
}


/*int provjeri(char *str){
    //s za string, p pomocni, pi pocetak intervala, a ki kraj intervala
    //po i ko su pocetak i kraj otvorenog taga, a pz i kz su pocetak i kraj zatvorenog taga
    char *s, *p, *r, *pi, *ki, *pz, *kz, *po, *ko;
    s = p = r = pi = ki = po = ko = pz = kz = str;
    
    while(*pi != '\0') pi++;

    //Kreni od drugog karaktera i trazi </
    s++;
    
    while(*s != '\0'){
        
        //Nadji pocetak zatvorenog taga
        if(*s == '/' && *(s-1) == '<'){
            //Pocetak zatvorenog taga
            pz = s-1;
            
            //Ako karakter nakon </ nije slovo
            s++;
            if(*s < 'A' || (*s > 'Z' && *s < 'a') || *s > 'z') return 0;
            
            //Pocetak naziva taga
            p = s;
            
            //Nadji '>', ne prolazi interval
            while(*s != '>' && *s != '\0')
                s++;
            // ako '</' postoji, a nema '>' => ne valja xaxa
            if(*s == '\0') return 0;
            
            //Kraj zatvorenog taga
            kz = s;
            
            s = pz-1;
            
            if(s < str) return 0;
            
            //Vracaj se unazad i trazi prvi otvoreni tag, trazi '<'
            while(s >= str && *s != '<'){
                //Preskoci interval
                if(s == ki) s = pi;
                
                s--;
            }
            
            //s je prosao string, a nije nasao '<' => ne valja
            if(s < str) return 0;
            
            //Pocetak otvorenog taga
            po = s;
            
            //Ako karakter nakon '<' nije slovo => ne valja
            s++;
            if(*s < 'A' || (*s > 'Z' && *s < 'a') || *s > 'z') return 0;
            
            //Pocetak naziva taga
            r = s;
            
            //Naci '>' otvorenog taga, trazi do pocetka intervala
            while(*s != '>' && s != pi && s != '\0'){
                s++;
            }
            //Nije nadjen '>' za otvoreni tag
            if(s == pi || *s == '\0') return 0;
            
            //Kraj otvorenog taga
            ko = s;
            
            //Prolazi kroz karaktere naziva otvorenog i zatvorenog taga dok su jednaki i (slovo ili broj)
            while((*p != '\0' && p != kz && r != ko && *r != ' ' && *p != ' ') && slovaJednaka(*p, *r)){
                //Funkcija slovaJednaka provjerava jednakost karaktera bez obzira bilo veliko ili malo slovo

                //Karakter nije ni slovo ni broj 
                //(prvi karakter naziva sigurno jeste slovo, provjereno ranije vec)
                if(*p < '0' || (*p > '9' && *p < 'A') || (*p > 'Z' && *p < 'a') || *p > 'z') return 0;
                if(*r < '0' || (*r > '9' && *r < 'A') || (*r > 'Z' && *r < 'a') || *r > 'z') return 0;
                
                p++;
                r++;
            }
            
            s = p;
            //Provjeriti razmake nakon naziva u zatvorenom tagu
            while(s < kz && *s == ' '){
                s++;
            }
            //Nisu sve razmaci u zatvorenom tagu nakon naziva
            if(s != kz) return 0;
            
            //Moraju nakon niza jednakih karaktera biti ili razmak ili '>' (posto smiju biti razmaci, ali samo razmaci
            //nakon naziva u zatvorenom tagu, dok u otvorenom moze biti atributa raznih, oni me ne zanimaju
            //tako da moze biti tehnicki bilo sta nakon naziva i razmaka u otvorenom tagu),
            //u suprotnom to znaci da nazivi ne odgovaraju
            if(!( (*r == ' ' || *r == '>') && (*p == '>' || *p == ' ') ) ) return 0;
            
            //Prosle su sve provjere za validnost taga, otvoren je i zatvoren
            //Sada je kljucna stvar postaviti interval koji se vise ne pregleda, jer je validan
            //Kraj intervala je jednak kraju zatvorenog taga
            ki = kz;
            //Pocetak intervala je jednak pocetku otvorenog taga
            if(po < pi)
                pi = po;
            
            //s je bitno postaviti na kraj intervala, jer sljedeci zatvoreni tag je sigurno nekad nakon
            //prethodnog
            s = ki;
        }
        
        s++;
    }
    
    //Ostalo gluposti nakon zatvorenog intervala
    if(ki < s) return 0;
    
    //Sve oke
    return 1;
}
*/
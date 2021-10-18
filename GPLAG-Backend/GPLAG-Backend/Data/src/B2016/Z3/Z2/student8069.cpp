/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdexcept>
#include <vector>

//Provjerava da li ima razmak ili nesto sto je u zadatku definirano kao 'odvajac' rijeci

bool JeLiOdvojeno(char &a ){
    if(a<'0' || (a>'9' && a<'A') || (a>'Z' && a<'a') || a>'z' ) return true;
    
    return false;
}

//Pretvara velika slova u mala

void Smanji(std :: string &s){
    for(int i(0); i< s.length(); i++){
        s[i]=std :: tolower(s[i]);
    }
}


std :: string IzdvojiRijec(std :: string recenica, int n){
    int razmak(1), broj_rijeci(0), i(0), p(0), k(0);
    
    while(i<recenica.length()-1){
        if(JeLiOdvojeno(recenica[i])) razmak=1;
        else if(razmak==1){
            razmak=0;
            broj_rijeci++;
        }
        if(broj_rijeci==n){
            p=i;
            break;
            }
        i++;
        
    }  
    
    int b=p;
    while(JeLiOdvojeno(recenica[b])==false && b<recenica.length()){
        k++;
        b++;
    }
    
    return recenica.substr(p,k);
    
}

//Ova fja vraca skup pozicija rijeci i u ovom zadatku je pomocna fja

std :: set<int> PozicijaRijeci(std :: string tekst, std :: string rijec){
    int pozicija, i(0), brojslova(0), znak(0), razmak(0), broj_rijeci(0);
    std :: set<int> skup;
    Smanji(tekst);                                   //smanjujem tekst kako se moze trazena rijec naci
    while(i<tekst.length()){
        if(JeLiOdvojeno(tekst[i])==false){             //provjerava razmak
            znak++;
            razmak=1;
        } else if(razmak==1){
            razmak=0;
            broj_rijeci++;
        }
        
        int cuvar=i;
        
        while(JeLiOdvojeno(tekst[i])==false && tekst[i]==rijec[brojslova] && cuvar<tekst.length()){
            cuvar++;                  //cuvar cuva poziciji od i kako bi kasnije bilo lakse ustanoviti na kojoj se poziciji nalazi trazena rijec
            brojslova++;
            
        }
        
        int duzina=rijec.length();
        if(znak==brojslova && znak==duzina && rijec==IzdvojiRijec(tekst,broj_rijeci+1)){  //ako je if-uslov zadovoljen ubacuje se pozicija rijeci u skup
            pozicija=cuvar-duzina;
            if(JeLiOdvojeno(tekst[pozicija])) pozicija ++ ;
            skup.insert(pozicija);
        }
        
        
        if(JeLiOdvojeno(tekst[i])){            ///ako naidje na nesto sto je definirano kao odvajac rijeci, onda se clanovi unutar if-uslova resetiraju, tj postavljaju na nulu 
            znak=0;
            cuvar=0;
            brojslova=0;
            pozicija=0;
            cuvar=0;
        }
        
        i++;
    }
    
    return skup;
    
}

int brojRijeci(std :: string tekst){
    int razmak(1), broj_rijeci(0), i(0);
    while(i<tekst.length()-1){
        if(JeLiOdvojeno(tekst[i])) razmak=1;
        else if(razmak==1){
            razmak=0;
            broj_rijeci++;
        }
        i++;
    }
    
    return broj_rijeci;
}

std :: map<std :: string, std :: set<int>> KreirajIndeksPojmova(std :: string tekst){
    std :: map<std :: string, std :: set<int>> mapa;
    std :: string pomocni;
    std :: set<std :: string> skuprijeci;
    
    
    for(int i(0); i<brojRijeci(tekst) ; i++){
        pomocni=IzdvojiRijec(tekst, i+1);
        skuprijeci.insert(pomocni);
    }
    
    
    for(std :: string x: skuprijeci){
        Smanji(x);
        mapa.insert(std :: make_pair(x, PozicijaRijeci(tekst, x)));
    
    }
    return mapa;
    
}

std :: set<int> PretraziIndeksPojmova(std :: string rijec, std :: map<std :: string, std :: set<int>> mapa){
    Smanji(rijec);
    auto it(mapa.find(rijec));
    if(it == mapa.end()) throw std :: logic_error("Unesena rijec nije nadjena!");
    return it->second;
}


void IspisiSkupJedan(std :: set<int> skup){  //trebaju mi dvije fje za ispis skupa jer je u zadatku naznacen drugaciji ispis za prvi dio zadatka i za drugi dio zadatka
    std :: vector<int> pomocni;
    for(int x: skup) pomocni.push_back(x);
    int n=pomocni.size();
    for(int i(0); i<n-1; i++){
        std :: cout << pomocni[i] << ",";
    }
    std :: cout << pomocni[n-1];
}

void IspisiSkupDva(std :: set<int> skup){ 
    for(int x: skup) std :: cout << x << " ";
    std :: cout << std :: endl;
}

void IspisiIndeksPojmova(std :: map <std :: string, std :: set<int>> mapa){
    for(auto &par: mapa){
        std :: cout << par.first << ": ";
        IspisiSkupJedan(par.second);
        std :: cout << std :: endl;
        
    }
    
}

int main ()
{
    std :: string tekst;
    std :: cout << "Unesite tekst: ";
    std :: getline(std :: cin, tekst);
    std :: string rijec;
    
    std :: map<std :: string, std :: set<int>> mapa=KreirajIndeksPojmova(tekst);
    
    IspisiIndeksPojmova(mapa);
    
    do{
        std :: cout << "Unesite rijec: ";
        try{
        std :: getline(std :: cin, rijec);
        if(rijec[rijec.length()-1]=='.') break;
        std :: set <int > skup=PretraziIndeksPojmova(rijec, mapa);
        IspisiSkupDva(skup);
        } catch(std :: logic_error IZUZETAK){
            std :: cout << IZUZETAK.what() << std :: endl;
        }
        }while(1);
        
    
	return 0;
}
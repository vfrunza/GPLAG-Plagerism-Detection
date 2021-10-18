/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>


std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> djeca, int broj_timova) {
    
    if(broj_timova<=0 || broj_timova>djeca.size()) throw std::logic_error("Razvrstavanje nemoguce");
   
    std::vector<std::set<std::string>> timovi;
    std::vector<int> broj_ljudi_po_timu(broj_timova);
    int ost=djeca.size()%broj_timova;
    
    for(int i=0; i<broj_timova; i++) {
        if(ost>0) {
            broj_ljudi_po_timu[i]=djeca.size()/broj_timova+1; ost--;
        }
        else broj_ljudi_po_timu[i]=djeca.size()/broj_timova;
    }
    
    struct Dijete {
        std::string ime;
        Dijete *sljedeci=nullptr;
    };

    Dijete *prvi(nullptr), *it;
    
    for(int i=0; i<djeca.size(); i++) {
        Dijete *pom = new Dijete;                           //JAVLJALO,NE VISE-javlja curenje memorije ovdje zato sto se ovdje alocira, vjerovatno se nesto ne izbrise dole u kodu sto je alocirano ovdjre 
        pom->ime = djeca[i];
        
        if(!prvi) prvi=pom;
        else if(pom->ime==djeca[djeca.size()-1] && i==djeca.size()-1) {
            it->sljedeci = pom;
            it=pom;
            it->sljedeci=prvi;
            //std::cout << it -> sljedeci << " <<<< ";
            break;
        }
        else it->sljedeci = pom;
        it = pom;
    }
    
    
    int broj=djeca.size();
    std::set<std::string> skup, a;
    int i(0), k(0);
    
    for(Dijete *p = prvi; p!=nullptr; p = it->sljedeci) {
        
        if(broj==0) break;
        if(p==it) {
            skup.insert(p->ime);
            timovi.push_back(skup);
            delete p;
            p=nullptr;
            return timovi;
        }
        
        
        skup.insert(p->ime);
        std::string rijec = p->ime;
        it->sljedeci=p->sljedeci;
        delete p;
        p=it->sljedeci;
        
        int broj_rijeci(rijec.length());
        for(int i=0; i<rijec.length(); i++) {
            if(!((rijec[i]>='a' && rijec[i]<='z') || (rijec[i]>='A' && rijec[i]<='Z') || (rijec[i]>='0' && rijec[i]<='9'))) broj_rijeci--;
        }
        
        //cout<<rijec<<" "<<broj_rijeci<<endl;
        while(broj_rijeci-1) {
            //std::cout<<broj_rijeci-2<<std::endl;
            it=(*it).sljedeci; 
            p = (*p).sljedeci;
            broj_rijeci--;
            //p = it;
        }
        broj--;
        
        i++;
        
        
        if(i==broj_ljudi_po_timu[k]) {
            timovi.push_back(skup);
            i=0; k++;
            skup=a;
        }
        
    }
    //delete it;
    //delete prvi;
    return timovi;
    
} 
int main ()
{
    
     
    std::vector<std::string> lista;
    int broj_timova, broj_djece;
    std::cout << "Unesite broj djece: ";
    std::cin >> broj_djece;
    std::cin.clear();std::cin.ignore(1000000, '\n');
    std::cout << "Unesite imena djece: " << std::endl;
    while(broj_djece) {
        //std::cin.clear(); std::cin.ignore(100000, '\n');
        std::string s;
        getline(std::cin, s);
        lista.push_back(s);
        broj_djece--;
    }
    
    std::cout << "Unesite broj timova: ";
    std::cin >> broj_timova;
    try{
        std::vector<std::set<std::string>> timovi = Razvrstavanje(lista, broj_timova);
        for(int i=0; i<timovi.size(); i++) {
            std::cout << "Tim " << i+1 <<": ";
            int brojac(0);
            for(auto it : timovi[i]) {
                std::cout <<  it; brojac++;
                if(brojac!=timovi[i].size()) std::cout << ", ";
                
            }
            std::cout << std::endl; 
        }
    }   catch(std::logic_error izuzetak) { std::cout << "Izuzetak: " <<izuzetak.what(); }
    catch(...) { std::cout << "ne valja"; }
	
	return 0;
}
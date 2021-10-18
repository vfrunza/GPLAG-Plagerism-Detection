/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <string>
#include <stdexcept>

std::list<std::string> PretvoriUListu(std::vector<std::string> v){
    std::list<std::string> imena;
    for(int i=0; i<v.size(); i++){
        imena.push_back(v[i]);
    }
    return imena;
}

int VelicinaListe(std::list<std::string> &imena){
    int brojac(0);
    auto it=imena.begin();
    while(it!=imena.end()){
        it++;
        brojac++;
    } 
    return brojac;
}

int DuzinaStringa(std::string s){
    int suma(0);
    for(int i=0; i<s.size(); i++){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) suma++;
    }
    return suma;
}

int razlika(typename std::list<std::string>::iterator it, typename std::list<std::string>::iterator it2){
    int brojac(0);
    while(it!=it2){
        it2++;
        brojac++;
    }
    return brojac;
}

std::string IzaberiIIzbrisi (std::list<std::string> &imena, int duzina, std::string &vratiti, bool prvi, typename std::list<std::string>::iterator &it){
    std::string pomocni;
    int brojac(0);
  //  auto it=imena.begin();
    int velicina=VelicinaListe(imena);
    if(prvi){
        it=imena.begin();
        pomocni=*it;
        it=imena.erase(it);
        vratiti=pomocni;
        return pomocni;
    }
    auto it2=imena.begin();
//    brojac+=(razlika(it, it2));
//    std::cout<<razlika(it, it2)<<" "<<duzina<<std::endl;
    int pomocni_brojac=razlika(it, it2);
    while(it!=imena.end() && brojac<=duzina){
        brojac++;
        pomocni_brojac++;
        if(brojac<duzina && (brojac%velicina==0 || pomocni_brojac%velicina==0)){
            it=imena.begin();
        }
        else if(brojac==duzina && (brojac%velicina==0 || pomocni_brojac%velicina==0)){
            pomocni=*it;
            it=imena.erase(it);
            vratiti=pomocni;
            return pomocni;
        }
        else if(brojac==duzina){
            pomocni=*it;
            it=imena.erase(it);
            vratiti=pomocni;
            return pomocni;
        }
        else it++;
    }
    
}

std::vector<std::multiset<std::string>> Razvrstavanje (std::vector<std::string> v, int broj_timova){
    if(broj_timova<1 || broj_timova>v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> imena=PretvoriUListu(v);
    std::vector<std::multiset<std::string>> skupovi(broj_timova);
    int ostatak=VelicinaListe(imena)%broj_timova;
    int brojac(0), osnovni_broj=VelicinaListe(imena)/broj_timova;
    auto it1=imena.begin();
    std::string ime=*it1;
    std::string vraceni;
    bool prvi=true;
    typename std::list<std::string>::iterator it=imena.begin();
    for(int i=0; i<broj_timova; i++){
        if(i<ostatak){
            brojac=0;
            while(brojac<osnovni_broj+1){
                skupovi[i].insert(IzaberiIIzbrisi(imena, DuzinaStringa(ime), vraceni, prvi, it));
                prvi=false;
                ime=vraceni;
                std::cout<<"evo "<<vraceni<<" ";
                brojac++;
            }
        }
        else{
            brojac=0;
            while(brojac<osnovni_broj){
                skupovi[i].insert(IzaberiIIzbrisi(imena, DuzinaStringa(ime), vraceni, prvi, it));
                prvi=false;
                ime=vraceni;
                std::cout<<"evo "<<vraceni<<" ";
                brojac++;
            }
        }
    }
    return skupovi;
    
}


int main ()
{
    try{
/*
    std::list<std::string> lista={ "Safet", "Damir", "Vedad", "Haris", "Nikolina", "Maja", "Adis"};
    std::cout<<VelicinaListe(lista)<<std::endl;
    std::string s2;
    std::string s=IzaberiIIzbrisi(lista, 3, s2, false);
    std::cout<<s<<std::endl;
    std::cout<<VelicinaListe(lista)<<std::endl;
    auto it=lista.begin();
    while(it!=lista.end()){
        std::cout<<*it<<" ";
        it++;
    } 
    std::cout<<std::endl<<IzaberiIIzbrisi(lista, 4, s2, true)<<std::endl;
 */
    int broj;
    std::cout<<"Unesite broj djece: ";
    std::cin>>broj;
    std::cin.ignore(1000, '\n');
    std::vector<std::string> v(broj);
    std::cout<<"Unesite imena djece: ";
    for(int i=0; i<broj; i++) {
        std::getline(std::cin, v[i]);
    }
  //  std::cin.ignore(1000, '\n');
    std::cout<<"Unesite broj timova: ";
    int n;
    std::cin>>n;
    std::string s;
    std::list<std::string> imena=PretvoriUListu(v);
    auto it=imena.begin();
    while(it!=imena.end()){
        std::cout<<*it<<" ";
        it++;
    } 
    std::cout<<std::endl;
 //   std::cout<<IzaberiIIzbrisi(imena, 1, s, false);
    std::vector<std::multiset<std::string>> skupovi=Razvrstavanje(v, n);
    for(int i=0; i<skupovi.size(); i++){
        std::cout<<"Tim "<<i+1<<": ";
        auto it=skupovi[i].begin();
        while(it!=skupovi[i].end()){
            std::cout<<*it<<" ";
            it++;
        }
        std::cout<<std::endl;
    }
    }
    catch(std::logic_error e){
        std::cout<<e.what()<<std::endl;
    }
	return 0;
}
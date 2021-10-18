/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <stdexcept>
#include <list>
#include <cctype>

typedef std::string string;
typedef std::vector<std::string> VektorStringova;
typedef std::vector<std::set<std::string>> VektorSkupova;
typedef std::list<std::string> Lista;
typedef std::vector<int> Vektor;

bool IsAlpha(char slovo){
    if((slovo>='a' && slovo<='z')||(slovo>='A' && slovo<='Z'))
    return true;
    return false;
}

int BrojSlova(string ime){
    int i(0),broj_slova(0);
    while(i!=int(ime.length())){
        if(IsAlpha(ime[i])) broj_slova++;
        i++;
    }
    return broj_slova;
}

Lista IskopirajUListu(VektorStringova imena){
    Lista djeca;
    int i(0);
    while(i!=int(imena.size())){
        djeca.push_back(imena[i]);
        i++;
    }
    return djeca;
}

Lista Izbrisi(Lista krug, string dijete){
    if (krug.empty()) return krug;
    auto it(krug.begin());
    if(it==krug.end()) return krug;
    while(it!=krug.end()){
        if(*it==dijete){
        it=krug.erase(it);
        break;
        }
        it++;
    }
    return krug;
}

void IspisiListu(Lista krug){
    for(auto x:krug) std::cout<<x<<" ";
}

VektorSkupova Razvrstavanje(VektorStringova imena, int broj_timova){
    if(broj_timova<1 || broj_timova>int(imena.size()))
    throw std::logic_error("Razvrstavanje nemoguce");
    
    VektorSkupova timovi(broj_timova);
    int broj_djece(int(imena.size()));
    Lista krug(IskopirajUListu(imena));
    //prvih mod(n,k) timova ima n/k+1 clanova
    int prvi_timovi((broj_djece/broj_timova)+1),ostali_timovi(broj_djece/broj_timova);
    
    auto pocetak(krug.begin()),brisanje(krug.begin());
    int korak(BrojSlova(*pocetak));
    timovi[0].insert(*pocetak);
    pocetak=krug.erase(brisanje);
    
    int i(0);
    do{
        if(i<(broj_djece%broj_timova)){
            if(timovi[i].size()<prvi_timovi){
                int brojac(0);
                string dijete;
                for(;;){
                    pocetak++;
                    brojac++;
                    if(brojac==korak){
                        if(pocetak==krug.end()) pocetak=krug.begin();
                        //std::cout<<"Brojac i korak: "<<brojac<<" "<<korak<<std::endl;
                        brisanje=pocetak;
                        dijete=*--pocetak;
                        break;
                    }
                    if(pocetak==krug.end()) pocetak=krug.begin();
                }
                brisanje=pocetak;
                timovi[0].insert(dijete); 
                korak=BrojSlova(dijete); 
                pocetak++; 
                brisanje=krug.erase(--brisanje);
                if(krug.empty()) return timovi;
            }
            else i++;
        }
        else{
            if(timovi[i].size()<ostali_timovi){
                int brojac(0);
                string dijete;
                for(;;){
                    pocetak++;
                    brojac++;
                    if(brojac==korak){
                        if(pocetak==krug.end()) pocetak=krug.begin();
                        brisanje=pocetak;
                        dijete=*--pocetak;
                        break;
                    }
                    if(pocetak==krug.end()) pocetak=krug.begin();
                }
                brisanje=pocetak;
                timovi[0].insert(dijete); 
                korak=BrojSlova(dijete);
                pocetak++;
                brisanje=krug.erase(--brisanje);
                if(krug.empty()) return timovi;
            }
            else i++;
        }
        
    }while(1);
    
    return timovi;
}

void IspisiTimove(VektorSkupova timovi){
    for(int i=0;i<int(timovi.size());i++){
        std::cout<<"Tim "<<i+1<<": ";
        for(auto x:timovi[i]) std::cout<<x<<" ";
        std::cout<<std::endl;
    }
}

int main (){
    try{
    int broj_djece;
    std::cout<<"Unesite broj djece: ";
    std::cin>>broj_djece;
    std::cin.ignore(1000,'\n');
    VektorStringova imena_djece(0);
    string ime;
    std::cout<<"Unesite imena djece: "<<std::endl;
    for(int i=0;i<broj_djece;i++){
        std::getline(std::cin,ime);
        imena_djece.push_back(ime);
    }
    int broj_timova;
    std::cout<<"Unesite broj timova: ";
    std::cin>>broj_timova;
    VektorSkupova timovi(Razvrstavanje(imena_djece,broj_timova));
    IspisiTimove(timovi);
    } catch(std::logic_error izuzetak){
        std::cout<<izuzetak.what();
    }
	return 0;
}
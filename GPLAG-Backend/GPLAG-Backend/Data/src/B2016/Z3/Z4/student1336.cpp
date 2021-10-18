/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <stdexcept>

std::list<std::string> KopirajUListu(std::vector<std::string> &imena){
    std::list<std::string> kopirano;
    for(int i(0); i<int(imena.size()); i++){
        kopirano.push_back(imena.at(i));
    }
    return kopirano;
}

int PomjeriZa(std::string &ime){
    int b(0);
    for(int i(0); i<int(ime.size()); i++){
        if((ime.at(i)>='a' && ime.at(i)<='z') || ( ime.at(i)>='A' && ime.at(i)<='Z' ) || (ime.at(i)>='0' && ime.at(i)<='9') ) b++;
    }
    return b;
}

std::set<std::string> JedanTim(std::list<std::string> &imena, int br_igraca, int &trenutni_igrac){
    std::set<std::string> tim;
    auto it=imena.begin();
    int b=trenutni_igrac;
    while(b>0){ it++; b--;}
    
    while(br_igraca!=0 && int(imena.size())!=0){
        tim.insert(*it);
        std::string ime=*it;
        int br_koraka(PomjeriZa(ime));
        it=imena.erase(it);
        if(it==imena.end()) it=imena.begin();
        if(int(imena.size())==0) break;
        if(int(imena.size())==trenutni_igrac) trenutni_igrac=0;
        
        for(int i(0); i<br_koraka-1; i++){
            it++;
            if(it==imena.end()) {it=imena.begin(); trenutni_igrac=0;}
            else trenutni_igrac++;
        }
        
        br_igraca--;
    }
    return tim;
}

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> imena, int br_timova){
    if(br_timova<1 || br_timova>int(imena.size())) throw std::logic_error("Razvrstavanje nemoguce");
    
    std::list<std::string> lista(KopirajUListu(imena));
    std::vector<std::set<std::string>> timovi;
    
    int trenutni_igrac(0);
    
    int mod(int(imena.size())%br_timova);
    
    for(int i(1); i<=br_timova; i++){
        if(i<=mod) timovi.push_back(JedanTim(lista, (int(imena.size())/br_timova)+1, trenutni_igrac ));
        else timovi.push_back(JedanTim(lista, int(imena.size())/br_timova, trenutni_igrac ));
    }
    
    return timovi;
}

void IspisiTimove(std::vector<std::set<std::string>> timovi, int br_timova){
     for(int i(0); i<br_timova; i++){
            std::cout<<"Tim "<<i+1<<": ";
            std::set<std::string> pomocni(timovi.at(i));
            for(auto it=pomocni.begin(); it!=pomocni.end(); it++){
                auto p=pomocni.end(); p--;
                if(it==p) std::cout<<*it;
                else std::cout<<*it<<", ";
            }
            std::cout<<std::endl;
     }
}

int main ()
{
    int n;
    std::cout<<"Unesite broj djece: ";
    std::cin>>n;
    
    std::cin.ignore(1000,'\n');
    
    std::vector<std::string> imena;
    std::cout<<"Unesite imena djece: "<<std::endl;
    for(int i(0); i<n; i++){
        std::string s;
        std::getline(std::cin, s);
        imena.push_back(s);
    }
    
    std::cout<<"Unesite broj timova: ";
    int br_timova;
    try{
        std::cin>>br_timova;
        std::vector<std::set<std::string>> timovi(Razvrstavanje (imena, br_timova));
        IspisiTimove(timovi, br_timova);
    }
    catch(std::logic_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
    
	return 0;
}
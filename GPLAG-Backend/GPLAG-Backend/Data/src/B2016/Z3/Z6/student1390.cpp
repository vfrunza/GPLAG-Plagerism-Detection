/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <iterator>
#include <stdexcept>
#include <memory>

struct Dijete{
  std::string ime;
  std::shared_ptr<Dijete> sljedeci;
};
int IzbrojiSlova(std::string s){
    int broj(0);
    for(int j=0;j<s.length();j++){
        if((s[j]>='a' && s[j]<='z') || (s[j]>='A' && s[j]<='Z') || (s[j]>='0' && s[j]<='9'))broj++;
    }
    return broj-1;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int br_timova){
    if(br_timova<1 || br_timova>v.size())throw std::logic_error("Izuzetak: Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> vektor;
    std::vector<int> broj_timova_konacni;
    if((v.size()%br_timova)==0){for(int i=0;i<br_timova;i++)broj_timova_konacni.push_back(v.size()/br_timova);}
    else {
        int broj_tim=v.size()%br_timova;
        int razlika=v.size()/br_timova;
    for(int i=0;i<br_timova;i++){
        if(broj_tim>i)broj_timova_konacni.push_back(razlika+1);
        else broj_timova_konacni.push_back(razlika);
    }
    }
    std::shared_ptr<Dijete> trenutni=nullptr;
    std::shared_ptr<Dijete> pocetak=nullptr;
    int clanovi(0);
    for(int i=0;i<v.size();i++){
        std::shared_ptr<Dijete> novo_dijete=std::make_shared<Dijete>();
        novo_dijete->ime=v[i];
        if(pocetak==nullptr){
            pocetak=trenutni=novo_dijete;
            novo_dijete->sljedeci=pocetak;
            clanovi++;
        }else {
            trenutni->sljedeci=novo_dijete;
            novo_dijete->sljedeci=pocetak;
            trenutni=novo_dijete;
            clanovi++;
        }
    }
    
    trenutni=pocetak;
    int slova_onog_kog_posmatramo(0);
    for(int i=0;i<broj_timova_konacni.size();i++){
        std::set<std::string> skup;
        int broj_djece_u_timu=broj_timova_konacni[i];
      while(broj_djece_u_timu>0){
          while(slova_onog_kog_posmatramo-->0)trenutni=trenutni->sljedeci;
                skup.insert(trenutni->ime);
                broj_djece_u_timu--;
                clanovi--;
                slova_onog_kog_posmatramo=IzbrojiSlova(trenutni->ime);
               std::shared_ptr<Dijete> pom=pocetak;
                while(pom->sljedeci!=trenutni)pom=pom->sljedeci;
                pom->sljedeci=trenutni->sljedeci;
                if(trenutni==pocetak)pocetak=pocetak->sljedeci;
                    trenutni->sljedeci=nullptr;
                if(clanovi!=0)trenutni=pom->sljedeci;
      }
      vektor.push_back(skup);
               
    }
    trenutni->sljedeci=nullptr;
    pocetak->sljedeci=nullptr;
    return vektor;
}
int main ()
{
    std::cout << "Unesite broj djece: " ;
    int n;
    std::cin >> n;
    std::cin.ignore(10000,'\n');
    std::cout << "Unesite imena djece: " << std::endl;
    std::vector<std::string> v;
    std::string a;
    for(int i=0;i<n;i++){
        std::getline(std::cin,a);
        v.push_back(a);
    }
    std::cout << "Unesite broj timova: ";
    int timovi;
    std::cin >> timovi;
    std::vector<std::set<std::string>> vek;
    try{
    vek=Razvrstavanje(v,timovi);
    for(int i=0;i<vek.size();i++){
        std::cout << "Tim "<<i+1<<": " ;
        auto it1(vek[i].begin());
        auto it2(vek[i].end());
        it2--;
        while(it1!=it2)std::cout << *it1++ <<", ";
        std::cout << *it1<<std::endl;
    }
    }catch(std::logic_error e){
        std::cout << e.what() << std::endl;
    }
	return 0;
}
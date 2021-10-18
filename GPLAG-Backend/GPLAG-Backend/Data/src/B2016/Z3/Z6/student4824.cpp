/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
#include <memory>

struct Dijete{
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};

std::shared_ptr<Dijete> KreirajListu(std::vector<std::string> djeca){
    std::shared_ptr<Dijete> pocetak=nullptr, prethodni=nullptr;
    for(int i=0; i<djeca.size(); i++){
        std::shared_ptr<Dijete> novi(new Dijete);
        novi->ime=djeca[i];
        novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
    }
    prethodni->sljedeci=pocetak;
    return pocetak;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> djeca, int broj){
    if(broj<1||broj>djeca.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::shared_ptr<Dijete> lista=KreirajListu(djeca);
    std::vector<std::set<std::string>> grupe(broj);
    int velicina_prvog;
    if(djeca.size()%broj==0) velicina_prvog=djeca.size()/broj;
    else velicina_prvog=djeca.size()/broj+1;
    int pocetna=velicina_prvog;
    int promijeni_index(0);
    int i(0);
    int brojac=djeca.size();
    std::shared_ptr<Dijete> kraj=lista;
    std::shared_ptr<Dijete> pocetak=lista;
    while(kraj->sljedeci!=pocetak) kraj=kraj->sljedeci;
    while(brojac!=0){
        grupe[promijeni_index].insert(pocetak->ime);
        std::string rijec(pocetak->ime);
        if(kraj==pocetak){
            kraj->sljedeci=nullptr;
            pocetak->sljedeci=nullptr;
            kraj=nullptr;
            pocetak=nullptr;
            return grupe;
        }
        kraj->sljedeci=pocetak->sljedeci;
        pocetak=pocetak->sljedeci;
        brojac--;
        i++;
        if(i==velicina_prvog){
            promijeni_index++;
            i=0;
        }
        if(velicina_prvog==pocetna&&promijeni_index==djeca.size()%broj&&djeca.size()%broj!=0)
        velicina_prvog--;
        std::string::iterator it1(rijec.begin());
        it1++;
        while(1){
            if(*it1!=' '&&*it1!='-'){
                pocetak=pocetak->sljedeci;
                kraj=kraj->sljedeci;
            }
            it1++;
            if(it1==rijec.end()) break;
        }
    }
    return grupe;
}

int main ()
{
    std::cout<<"Unesite broj djece: ";
    int n;
    std::cin>>n;
    std::vector<std::string> djeca(n);
    std::cout<<"Unesite imena djece: ";
    std::cin.ignore(100, '\n');
    for(int i=0; i<n; i++) std::getline(std::cin, djeca[i]);
    std::cout<<std::endl<<"Unesite broj timova: ";
    int broj;
    std::cin>>broj;
    try{
        std::vector<std::set<std::string>> grupe=Razvrstavanje(djeca, broj);
        for(int i=0; i<broj; i++){
            std::cout<<"Tim "<<i+1<<":";
            int j(0);
            for(std::string x: grupe[i]){
                std::cout<<" "<<x;
                if(j<grupe[i].size()-1) std::cout<<",";
                j++;
            }
            std::cout<<std::endl;
        }
    }
    catch(std::logic_error izuzetak){
        std::cout<<"Izuzetak: "<<izuzetak.what();
        return 0;
    }
	return 0;
}
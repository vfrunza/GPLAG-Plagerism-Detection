
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <stdexcept>
#include <memory>

struct Dijete{
    std::string ime;
    std::shared_ptr<Dijete> slijedeci;
};


int Funkcija(std::string s){
    
    for(int i=0;i<s.length();i++){
        if(s[i]>='A' && s[i]<='Z'){
            s[i]-='A'-'a';
        }
    }
    
    
    int brojac(0);
    for(int i=0;i<s.length();i++){
        while((s[i]<'a'&& s[i]>'z')||(s[i]<'0'&&s[i]>'9')){
            i++;
        }
        if(i==s.length())
            break;
            if((s[i]>='a'||s[i]<='z')||(s[i]>='0'&&s[i]<='9')){
                while((s[i]>='a'&& s[i]<='z')||(s[i]>='0'&&s[i]<='9')){
                    brojac++;
                    i++;
                }
            }
    }
    return brojac;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string>v,int broj_timo){
    if(broj_timo>v.size() || broj_timo<1) throw std::logic_error("Izuzetak: Razvrstavanje nemoguce");
    
    std::shared_ptr<Dijete> pocetak(nullptr),prethodni,preusmeri;
    
    for(int i=0;i<v.size();i++){
        std::shared_ptr<Dijete> novi=std::make_shared<Dijete>();
        novi->ime=v[i];
        novi->slijedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->slijedeci=novi;
        prethodni=novi;
    }
    
    prethodni->slijedeci=pocetak;
    
    std::vector<std::set<std::string>>vekorskupova;
    std::vector<std::string>vekorstringova;
    std::vector<int>v1;
    int broj_dece,broj_slova,broj_timova;
    broj_dece=v.size();
    broj_timova=broj_timo;
    int pomocni1;
    pomocni1=broj_dece%broj_timova;
    int pomocni2;
    pomocni2=broj_dece/broj_timova;
    
    vekorstringova.push_back(pocetak->ime);
    
    broj_slova=Funkcija(pocetak->ime);
    
    preusmeri=pocetak;
    prethodni->slijedeci=pocetak->slijedeci;
    pocetak=pocetak->slijedeci;
    preusmeri=nullptr;
    for(int i=0;i<broj_timova;i++){
        v1.push_back(pomocni2);
    }
for(int i=0;i<pomocni1;i++){
    v1[i]+=1;
}
int zadnji(broj_dece);
for(int i=0;i<broj_dece;i++){
    if(zadnji==1){
        pocetak->slijedeci=nullptr;
        
        break;
        
    }
    for(int i=0;i<broj_slova-1;i++){
    pocetak=pocetak->slijedeci;
    prethodni=prethodni->slijedeci;
    }
    preusmeri=pocetak;
    vekorstringova.push_back(pocetak->ime);
    broj_slova=Funkcija(pocetak->ime);
    prethodni->slijedeci=pocetak->slijedeci;
    pocetak=pocetak->slijedeci;
    zadnji--;
    preusmeri=nullptr;
    }
  
int k=0;
std::set<std::string>skup;
std::set<std::string>skup1;
    for(int i=0;i<broj_timova;i++){
        for(int j=0;j<v1[i];j++){
            skup.insert(vekorstringova[k]);
            k++;
        }
        vekorskupova.push_back(skup);
        skup=skup1;
    }
return vekorskupova;
}

int main ()
{
    std::vector<std::set<std::string>>vektorskupova;
    int broj_dece;
    int broj_timova;
    std::string djeca;
    std::vector<std::string>v;
    std::cout<<"Unesite broj djece: ";
    std::cin>>broj_dece;
    std::cin.ignore(10000,'\n');
    std::cout<<"Unesite imena djece: ";
    for(int i=0;i<broj_dece;i++){
        std::getline(std::cin,djeca);
        v.push_back(djeca);
        
    }
    std::cout<<std::endl;
    std::cout<<"Unesite broj timova: ";
    std::cin>>broj_timova;
    std::set<std::string>::iterator it2;
try{    std::set<std::string>::iterator it;
    vektorskupova=Razvrstavanje(v,broj_timova);
    
    for(int i=0;i<vektorskupova.size();i++){
        std::cout<<"Tim "<<i+1<<": ";
        it=vektorskupova[i].begin();
        it2=vektorskupova[i].end();
        it2--;
        while(it!=vektorskupova[i].end()){
            if(it==it2){
                std::cout<<*it;
            }
            else {
            std::cout<<*it<<", ";
        }
        it++;
        }
        std::cout<<std::endl;
    }
}
catch(std::logic_error poruka){
    std::cout<<poruka.what();
}
    
	return 0;
}   
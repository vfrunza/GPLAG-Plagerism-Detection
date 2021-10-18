/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <stdexcept>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
enum class Boje{Pik,Tref,Herc,Karo};
std::vector<Boje> nizBoja{Boje::Pik,Boje::Tref,Boje::Herc,Boje::Karo};
std::vector<std::string> Vrijednosti{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
std::list<std::pair<Boje,std::string>> KreirajSpil(){
    std::list<std::pair<Boje,std::string>> Spil;
    
    for(int i=0; i<nizBoja.size();i++){
        for(int j=0; j<Vrijednosti.size();j++)
            Spil.push_back(std::make_pair(nizBoja[i],Vrijednosti[j]));
    }
    return Spil;
}
void DodajUVektor(std::vector<int> &a,int c){
    bool ima(false);
    for(int i=0; i<a.size();i++){
        if(a[i]==c)ima=true;
        break;}
    if(!ima)a.push_back(c);
}
bool DodajUVektor1(std::vector<int> &vek,std::string s){
    if(s[0]>='0' && s[0]<='9'){
        DodajUVektor(vek,s[0]-'0');
        return true;
    }else{
        if(s=="10"){
            DodajUVektor(vek,10);
            return true;
        }else if(s=="J"){
            DodajUVektor(vek,12);
            return true;
        }else if(s=="Q"){
            DodajUVektor(vek,13);
            return true;
        }else if(s=="K"){
            DodajUVektor(vek,14);
            return true;
        }else if(s== "A"){
            DodajUVektor(vek,15);
            return true;
        }
    }
    return false;
    
}
void PomocnaFjaZaProvjeruListe(std::list<std::pair<Boje,std::string>> &spil){
        if(spil.size()>52)throw std::logic_error("Neispravna lista!");
    std::vector<int> niz;
    std::vector<int> nizVr;
    for(auto it=spil.begin(); it!=spil.end();it++){
        switch((*it).first){
            case Boje::Pik:
                DodajUVektor(niz,0);
                break;
            case Boje::Tref:
                DodajUVektor(niz,1);
                break;
            case Boje::Herc:
                DodajUVektor(niz,2);
                break;
            case Boje::Karo:
                DodajUVektor(niz,3);
                break;
        }
        auto t=DodajUVektor1(nizVr,(*it).second);
        if(!t)throw std::logic_error("Neispravna lista!");
        for(int i=0; i<niz.size()-1;i++)
            if(niz[i]>niz[i+1])throw std::logic_error("Neispravna lista!");
    
    }
    
}
void IzbaciKarte(std::list<std::pair<Boje,std::string>> &spil,std::multimap<Boje,std::string> &multimapa){
    PomocnaFjaZaProvjeruListe(spil);
    for(auto it=multimapa.begin();it!=multimapa.end();it++){
        
        auto par=*it;
        
        auto pok=spil.begin();
        
        for(auto it1=spil.begin(); it1!=spil.end();it1++)
            if((*it1).first==par.first && (*it1).second==par.second){pok=it1;break;}
        if(pok!=spil.end()){
            spil.erase(pok);
            multimapa.erase(it);
            it--;
        }
        
    }
}
std::string DajBoju(Boje b){
    std::string rez;
    if(b==Boje::Pik)rez="Pik";
    else if(b==Boje::Tref)rez="Tref";
    else if(b==Boje::Herc)rez="Herc";
    else rez="Karo";
    return rez;
}
Boje StringUBoju(std::string s){
    Boje b;
    if(s=="Pik")b=Boje::Pik;
    else if(s=="Herc")b=Boje::Herc;
    else if(s=="Karo")b=Boje::Karo;
    else b=Boje::Tref;
    return b;
}
std::queue<std::pair<std::string,std::string>>IzbaciKarteRazbrajanjem(std::list<std::pair<Boje,std::string>> &spil,const short int &r, const int &b){
    if(r<1 || r>52 || b<1)throw std::logic_error("Neispravni elementi za izbacivanje!");
    std::queue<std::pair<std::string,std::string>> rez;
    auto it=spil.begin();
    int brputa=0;
    for(int i=0; i<b;i++){
        if(spil.size()==0)break;
        
        for(int j=0; j<r-1;j++){
            if(it!=spil.end())it++;
            
            if(it==spil.end())it=spil.begin();
        }
        rez.emplace(std::make_pair(DajBoju((*it).first),(*it).second));
        brputa=0;
        auto pok=spil.begin();
        while(pok!=it){pok++;brputa++;}
        spil.erase(it);
        it=spil.begin();
        int x=0;
        while(x<brputa){x++;it++;}
       // if(it!=spil.end())it++;
        if(it==spil.end())it=spil.begin();
    }
    return rez;
    
}
void SortirajSpil(std::list<std::pair<Boje,std::string>> &spil){
     spil.sort([](std::pair<Boje,std::string> karta1,std::pair<Boje,std::string> karta2){
        int boja1,boja2;
        int vr1,vr2;
        if(karta1.first==Boje::Pik)boja1=0;
        else if(karta1.first==Boje::Tref)boja1=1;
        else if(karta1.first==Boje::Herc)boja1=2;
        else boja1=3;
        if(karta2.first==Boje::Pik)boja2=0;
        else if(karta2.first==Boje::Tref)boja2=1;
        else if(karta2.first==Boje::Herc)boja2=2;
        else boja2=3;
        if(boja2>boja1)return true;
        else if(boja2<boja1)return false;
        else{
            if(karta1.second[0]>='0' && karta1.second[0]<='9' && karta1.second.size()==1)vr1=karta1.second[0]-'0';
            else if(karta1.second=="10")vr1=10;
            else if(karta1.second=="J")vr1=12;
            else if(karta1.second=="Q")vr1=13;
            else if(karta1.second=="K")vr1=14;
            else if(karta1.second=="A")vr1=15;
            if(karta2.second[0]>='0' && karta2.second[0]<='9'&& karta2.second.size()==1)vr2=karta2.second[0]-'0';
            else if(karta2.second=="10")vr2=10;
            else if(karta2.second=="J")vr2=12;
            else if(karta2.second=="Q")vr2=13;
            else if(karta2.second=="K")vr2=14;
            else if(karta2.second=="A")vr2=15;
            return vr2>vr1;
           
        }
        
        
    });
    
}
void VratiPrvihNKarata(std::list<std::pair<Boje,std::string>> &spil,std::queue<std::pair<std::string,std::string>> &red,int n){
    if(n<0)throw std::domain_error("Broj n je besmislen!");
    else if (n>red.size())throw std::range_error("Nedovoljno karata u redu!");
    PomocnaFjaZaProvjeruListe(spil);
    bool sort=false;
    for(int i=0; i<n;i++){
        auto pa=red.front();
        std::pair<Boje,std::string> par=std::make_pair(StringUBoju(pa.first),pa.second);
         auto pok=spil.end();
        
        for(auto it1=spil.begin(); it1!=spil.end();it1++)
            if((*it1).first==par.first && (*it1).second==par.second){pok=it1;break;}
        if(pok==spil.end()){
            spil.push_back(par);
            red.pop();
            sort=true;
        }
    
    }
    
    if(sort)SortirajSpil(spil);
    
}

void IspisiSpil(std::list<std::pair<Boje,std::string>> &spil){
    std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to: ";
     std::string ispisanaBoja="-1";
      for (auto it=spil.begin();it!=spil.end();it++){
        
        if(ispisanaBoja!=DajBoju(it->first)){ispisanaBoja=DajBoju(it->first); std::cout<<std::endl<<ispisanaBoja<<": ";}
        
        std::cout<<it->second<< " ";
        
    }
    std::cout<<std::endl;
}
int main ()
{
    std::cout<<"Unesite korak razbrajanja: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    int brkar;
    std::cin>>brkar;
    
    auto spil=KreirajSpil();
    try{
        auto red=IzbaciKarteRazbrajanjem(spil,n,brkar);
        
        
        IspisiSpil(spil);
    
        std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        int vrati;
        std::cin>>vrati;
        try{
            VratiPrvihNKarata(spil,red,vrati);
            IspisiSpil(spil);
        }catch(std::domain_error a){std::cout<<"Izuzetak: "<<a.what();}
        catch(std::range_error a){std::cout<<"Izuzetak: "<<a.what();
        }
    }catch(std::logic_error a){std::cout<<"Izuzetak: "<<a.what();}

	return 0;
}

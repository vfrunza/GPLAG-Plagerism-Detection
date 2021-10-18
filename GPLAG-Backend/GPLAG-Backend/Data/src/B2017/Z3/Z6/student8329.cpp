/B2017/2018: Zadaća 3, Zadatak 6
#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <map>
#include <stack>
#include <memory>


enum class Boje {Pik, Tref, Herc, Karo};

struct Karta{
    Boje boja;
    std::string vrijednost;
};

struct Cvor{
    Karta karta;
    std::shared_ptr<Cvor>sljedeci=nullptr;
};

template <typename T> std::string U_string(T x)
{
	std::ostringstream s;
	s<<x;
	return s.str();
}

std::string Pretvori(Boje boja)
{
    std::string s;
    if(boja==Boje(0))s="Pik";
    else if(boja==Boje(1))s="Tref";
    else if(boja==Boje(2))s="Herc";
    else if(boja==Boje(3))s="Karo";
    return s;
}

int PretvoriBoje(Boje boja){
    if(boja==Boje::Pik)return 0;
    else if(boja==Boje::Herc)return 2;
    else if(boja==Boje::Karo)return 3;
    return 1;
}

Boje pretvoriStringUBoju(std::string s){
    if(s=="Pik")return Boje::Pik;
    else if(s=="Herc")return Boje::Herc;
    else if(s=="Karo")return Boje::Karo;
    return Boje::Tref;
}

Boje Pretvori2(std::string s)
{
    Boje boja;
    if(s=="Pik")boja=Boje(0);
    else if(s=="Tref")boja=Boje(1);
    else if(s=="Herc")boja=Boje(2);
    else if(s=="Karo")boja=Boje(3);
    return boja;
}

int Pretvori1(std::string s)
{
    int broj;
    if(s=="J"){broj=11;return broj;}
    if(s=="Q"){broj=12;return broj;}
    if(s=="K"){broj=13;return broj;}
    if(s=="A"){broj=14;return broj;}
    else broj=std::stoi(s);
    return broj;
    
}

std::shared_ptr<Cvor> KreirajSpil()
{
    std::shared_ptr<Cvor> pocetak(nullptr);
    std::shared_ptr<Cvor> prethodni; 
    std::shared_ptr<Cvor> temp;
    
    Boje trenutna_boja;
    for(int i(0);i<4;i++)
    {
        trenutna_boja=Boje(i);
        for(int j(2);j<=10;j++)
        {
            Karta tmp;
            tmp.boja= trenutna_boja;
            tmp.vrijednost=U_string(j);
            temp = std::shared_ptr<Cvor>(new Cvor);
            //temp=std::make_shared<Cvor>;
            temp->karta=tmp;
            if(!pocetak)
            {
                pocetak=temp;
                prethodni=temp;
            }
            else{
                prethodni->sljedeci=temp;
                prethodni=temp;
                
            }
            temp=temp->sljedeci;
        }
        Karta tmp;
        tmp.boja=trenutna_boja;
        tmp.vrijednost="J";
        //temp=std::make_shared<Cvor>;
        temp = std::shared_ptr<Cvor>(new Cvor);
        temp->karta=tmp;
        prethodni->sljedeci=temp;
        prethodni=temp;
        temp=temp->sljedeci;
        tmp.vrijednost="Q";
        //temp=std::make_shared<Cvor>;
        temp = std::shared_ptr<Cvor>(new Cvor);
        temp->karta=tmp;
        prethodni->sljedeci=temp;
        prethodni=temp;
        temp=temp->sljedeci;
        tmp.vrijednost="K";
        //temp=std::make_shared<Cvor>;
        temp = std::shared_ptr<Cvor>(new Cvor);    
        temp->karta=tmp;
        prethodni->sljedeci=temp;
        prethodni=temp;
        temp=temp->sljedeci;
        tmp.vrijednost="A";
        //temp=std::make_shared<Cvor>;
        temp = std::shared_ptr<Cvor>(new Cvor);
        temp->karta=tmp;
        prethodni->sljedeci=temp;
        prethodni=temp;
        temp=temp->sljedeci;
    }
    prethodni->sljedeci=pocetak;
    
    return pocetak;
}

void IzbaciKarte( std::shared_ptr<Cvor> &pocetak, std::multimap<Boje, std::string>& Mapa)
{
    
    std::shared_ptr<Cvor> privremeni(pocetak);
    if(pocetak==nullptr)return;
    int brojac(0);
    while(privremeni->sljedeci!=pocetak)
    {
        if(brojac>52)throw std::logic_error("Neispravna lista");
        
        if(!((privremeni->karta).boja==Boje::Pik || (privremeni->karta).boja==Boje::Herc || (privremeni->karta).boja==Boje::Tref || (privremeni->karta).boja==Boje::Karo))throw std::logic_error("Neispravna lista");
        if(!((privremeni->karta).vrijednost[0]>='0' && (privremeni->karta).vrijednost[0]<='9' || (privremeni->karta).vrijednost[0]=='K' || (privremeni->karta).vrijednost[0]=='Q' || (privremeni->karta).vrijednost[0]=='A' || (privremeni->karta).vrijednost[0]=='J'))throw std::logic_error("Neispravna lista");
        brojac++;
        privremeni=privremeni->sljedeci;
    }
    std::shared_ptr<Cvor> kraj(privremeni);
    privremeni=pocetak;
    std::shared_ptr<Cvor> prethodni(pocetak);
    while(privremeni!=nullptr && privremeni->sljedeci!=pocetak)
    {
        auto it2=Mapa.find((privremeni->karta).boja);
        if(it2!=Mapa.end() && it2->second==(privremeni->karta).vrijednost)
        {
            Mapa.erase(it2);
            prethodni->sljedeci=privremeni->sljedeci;
            auto tmp=privremeni;
            privremeni=privremeni->sljedeci;
            if(tmp==pocetak){pocetak=privremeni;
            kraj->sljedeci=pocetak;}
            tmp=nullptr;
        }
        brojac--;
    }
    if(brojac==0)pocetak->sljedeci=nullptr;
    pocetak=nullptr;
}

std::stack<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(std::shared_ptr<Cvor> &pocetak, const short int &r, const int &b)
{
    if(r<1 || r>52 || b<1)throw std::logic_error("Neispravni elementi za izbacivanje!");
    std::stack<std::pair<std::string, std::string>> Stek;
    std::shared_ptr<Cvor> privremeni=pocetak;
    if(pocetak!=nullptr){
    int brojac(0);
  while(privremeni->sljedeci!=pocetak)
    {
        if(brojac>52)throw std::logic_error("Neispravna lista");
        
        if(!((privremeni->karta).boja==Boje::Pik || (privremeni->karta).boja==Boje::Herc || (privremeni->karta).boja==Boje::Tref || (privremeni->karta).boja==Boje::Karo))throw std::logic_error("Neispravna lista");
        if(!((privremeni->karta).vrijednost[0]>='0' && (privremeni->karta).vrijednost[0]<='9' || (privremeni->karta).vrijednost[0]=='K' || (privremeni->karta).vrijednost[0]=='Q' || (privremeni->karta).vrijednost[0]=='A' || (privremeni->karta).vrijednost[0]=='J'))throw std::logic_error("Neispravna lista");
        brojac++;
        privremeni=privremeni->sljedeci;
    }
    
    int a(0);
    std::shared_ptr<Cvor> kraj(privremeni);
    privremeni=pocetak;
    std::shared_ptr<Cvor> prethodni=pocetak;
    while(!(privremeni==nullptr || a==b))
    {
        int br(0);
        while(br!=r)
        {
            br++;
            if(br==r)break;
            prethodni=privremeni;
            privremeni=privremeni->sljedeci;
        
        }
        std::string pomocni;
        if((privremeni->karta).boja==Boje(0))pomocni="Pik";
        else if((privremeni->karta).boja==Boje(1))pomocni="Tref";
        else if((privremeni->karta).boja==Boje(2))pomocni="Herc";
        else if((privremeni->karta).boja==Boje(3))pomocni="Karo";
        std::pair<std::string, std::string> temp;
        temp.first=pomocni;
        temp.second=(privremeni->karta).vrijednost;
        Stek.push(temp);
        a++;
        prethodni->sljedeci=privremeni->sljedeci;
        auto tmp=privremeni;
        privremeni=privremeni->sljedeci;
        if(tmp==kraj)kraj=prethodni;
        if(tmp==pocetak){pocetak=privremeni;
        kraj->sljedeci=pocetak;}
        tmp=nullptr;
        
    }}
    return Stek;
}


void VratiPosljednjihNKarata(std::shared_ptr<Cvor> pocetak, std::stack<std::pair<std::string, std::string>> &Red, int n)
{
     std::shared_ptr<Cvor> privremeni=pocetak;
    int brojac(0);
   while(privremeni->sljedeci!=pocetak)
    {
        if(brojac>52)throw std::logic_error("Neispravna lista");
        
        if(!((privremeni->karta).boja==Boje::Pik || (privremeni->karta).boja==Boje::Herc || (privremeni->karta).boja==Boje::Tref || (privremeni->karta).boja==Boje::Karo))throw std::logic_error("Neispravna lista");
        if(!((privremeni->karta).vrijednost[0]>='0' && (privremeni->karta).vrijednost[0]<='9' || (privremeni->karta).vrijednost[0]=='K' || (privremeni->karta).vrijednost[0]=='Q' || (privremeni->karta).vrijednost[0]=='A' || (privremeni->karta).vrijednost[0]=='J'))throw std::logic_error("Neispravna lista");
        brojac++;
        privremeni=privremeni->sljedeci;
    }
    if(n<0)throw std::domain_error("Broj n je besmislen!");
    if(n>Red.size())throw std::range_error("Nedovoljno karata u redu!");
    int a(0);
    std::shared_ptr<Cvor> kraj(privremeni);
    while(a!=n)
    {
        privremeni=pocetak;
        if(a==n)break;
        auto par=Red.top();
        Red.pop();
        std::shared_ptr<Cvor> prethodni=privremeni;
        while(privremeni!=nullptr && privremeni->sljedeci!=pocetak)
        {
            if(Pretvori((privremeni->karta).boja)==par.first)break;
            prethodni=privremeni;
            privremeni=privremeni->sljedeci;
        }
        
        while(privremeni!=nullptr && privremeni->sljedeci!=pocetak)
        {
            if(Pretvori1((privremeni->karta).vrijednost)<Pretvori1(par.second))
            {
                prethodni=privremeni;
                privremeni=privremeni->sljedeci;
            }
            else break;
        }
        std::shared_ptr<Cvor> zlj(new Cvor);
        zlj->karta.boja=Pretvori2(par.first);
        zlj->karta.vrijednost=par.second;
        if(prethodni==pocetak && Pretvori1((prethodni->karta).vrijednost)>Pretvori1(par.second))
        {
            zlj->sljedeci=prethodni;
            pocetak=zlj;
            kraj->sljedeci=pocetak;
        }
        else if(privremeni==kraj&&Pretvori1((privremeni->karta).vrijednost)<Pretvori1(par.second)){
            privremeni->sljedeci=zlj;
            zlj->sljedeci=pocetak;
            kraj=zlj;
        }
        else{
        prethodni->sljedeci=zlj;
        zlj->sljedeci=privremeni;
        }
        
        a++;
        brojac--;
        
    }
    if(brojac==0)pocetak->sljedeci=nullptr;
    pocetak=nullptr;
}


int main ()
{
    try{
     std::shared_ptr<Cvor> Spil=nullptr;
     Spil=KreirajSpil();
    try
    {
    std::cout<<"Unesite korak razbrajanja: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    int broj;
    std::cin>>broj;
   
    std::stack<std::pair<std::string, std::string>> Red(IzbaciKarteRazbrajanjem(Spil,n,broj));
    
    std::cout<<"U spilu trenutno ima "<<((broj>=52)?0:(52-broj))<<" karata, i to:"<<std::endl;
    std::cout<<"Pik: ";
    auto tmp(Spil);
    while(Spil!=nullptr)
    {
        if((tmp->karta).boja==Boje(0))std::cout<<(tmp->karta).vrijednost<<" ";
        else break;
        if(tmp->sljedeci==Spil)break;
        tmp=tmp->sljedeci;
    }
    std::cout<<std::endl<<"Tref: ";
    while(Spil!=nullptr)
    {
        if((tmp->karta).boja==Boje(1))std::cout<<(tmp->karta).vrijednost<<" ";
        else break;
        if(tmp->sljedeci==Spil)break;
         tmp=tmp->sljedeci;
    }
    std::cout<<std::endl<<"Herc: ";
    while(Spil!=nullptr)
    {
        if((tmp->karta).boja==Boje(2))std::cout<<(tmp->karta).vrijednost<<" ";

        else break;
        if(tmp->sljedeci==Spil)break;
        tmp=tmp->sljedeci;
    }
    std::cout<<std::endl<<"Karo: ";
    while(Spil!=nullptr)
    {
        if((tmp->karta).boja==Boje(3))std::cout<<(tmp->karta).vrijednost<<" ";
        else break;
        if(tmp->sljedeci==Spil)break;
         tmp=tmp->sljedeci;
    }
    
    std::cout<<std::endl<<"Unesite broj karata koje zelite vratiti u spil: ";
    int br1;
    std::cin>>br1;
   VratiPosljednjihNKarata(Spil,Red,br1);
    
    std::cout<<"U spilu trenutno ima "<<((broj>=52)?(0+br1):(52-broj+br1))<<" karata, i to:"<<std::endl;
    std::cout<<"Pik: ";
    tmp=Spil;
    while(Spil!=nullptr)
    {
        if((tmp->karta).boja==Boje(0))std::cout<<(tmp->karta).vrijednost<<" ";
        else break;
        if(tmp->sljedeci==Spil)break;
        tmp=tmp->sljedeci;
    }
    std::cout<<std::endl<<"Tref: ";
    while(Spil!=nullptr)
    {
        if((tmp->karta).boja==Boje(1))std::cout<<(tmp->karta).vrijednost<<" ";
        else break; 
        if(tmp->sljedeci==Spil)break;
        tmp=tmp->sljedeci;
    }
    std::cout<<std::endl<<"Herc: ";
    while(Spil!=nullptr)
    {
        if((tmp->karta).boja==Boje(2))std::cout<<(tmp->karta).vrijednost<<" ";
        else break; 
        if(tmp->sljedeci==Spil)break;
        tmp=tmp->sljedeci;
    }
    std::cout<<std::endl<<"Karo: ";
    while(Spil!=nullptr)
    {
        if((tmp->karta).boja==Boje(3))std::cout<<(tmp->karta).vrijednost<<" ";
        else break; 
        if(tmp->sljedeci==Spil)break;
        tmp=tmp->sljedeci;
    }
    Spil->sljedeci=nullptr;
    Spil=nullptr;
    }
    catch(std::domain_error Izuzetak){
        Spil->sljedeci=nullptr;
        Spil=nullptr;
        std::cout<<"Izuzetak: "<<Izuzetak.what()<<std::endl;
  
    }
    catch(std::logic_error Izuzetak){
        Spil->sljedeci=nullptr;
        Spil=nullptr;
        std::cout<<"Izuzetak: "<<Izuzetak.what()<<std::endl;
      
    }
    catch(std::range_error Izuzetak){
        Spil->sljedeci=nullptr;
        Spil=nullptr;
        std::cout<<"Izuzetak: "<<Izuzetak.what()<<std::endl;
     
    }
    }
    catch(...){}
	return 0;
}
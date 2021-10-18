/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include<vector>
#include<set>
#include <stdexcept>
struct Dijete{
    std::string ime;
    Dijete* sljedeci;
};

bool slovo(char c)
{
    if(c>='a' && c<='z')
    return true;
    if(c>='A' && c<='Z')
    return true;
    if(c>='0' && c<='9')
    return true;
    return false;
    
}

int broj_slova_igraca(std::string s)
{
    int vrati=0;
    for(int i=0;i<s.size();i++)
    {
        if(slovo(s[i])==true)
        vrati++;
    }
    return vrati;
}



Dijete *KreirajListuCvoroca(std::vector<std::string> v)
{
    
    Dijete *pocetak=nullptr;
    Dijete *predhodni;
    
    for(int i=0;i<v.size();i++)
    {
        Dijete *novi(new Dijete);
        novi->ime=v[i];
        novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else
        predhodni->sljedeci=novi;
        predhodni=novi;
    }
    predhodni->sljedeci=pocetak;
    return pocetak;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string>v,int broj_timova)
{
    
    if(broj_timova<1 || broj_timova>v.size())
    throw std::logic_error("Razvrstavanje nemoguce");
     
    
    int broj_igraca=v.size();
    std::vector<std::set<std::string>> vrati;
  
    std::vector<int> broj_igraca_u_timu;
    broj_igraca_u_timu.resize(broj_timova);
    
    int index=broj_igraca%broj_timova;
    
    int tempigrac=broj_igraca/broj_timova;
    
    for(int i=0;i<index;i++)
    {
        broj_igraca_u_timu[i]=tempigrac+1;
    }
    for(int i=index;i<broj_igraca_u_timu.size();i++)
    broj_igraca_u_timu[i]=tempigrac;
   
    std::string prazni;
    std::string ime_zadnjeg_igraca;
    vrati.resize(broj_timova);
    
    int broj_slova_zadnjeg_igraca=0;
    auto pocetak=KreirajListuCvoroca(v);
    ime_zadnjeg_igraca=pocetak->ime;
    auto iza_Pocetka=pocetak;
    int brojac=0;
    while(brojac<v.size()-1)
    {
    iza_Pocetka=iza_Pocetka->sljedeci;
    
        brojac++;
    }
    broj_slova_zadnjeg_igraca=broj_slova_igraca(ime_zadnjeg_igraca);
    vrati[0].insert(pocetak->ime);
    iza_Pocetka->sljedeci=pocetak->sljedeci;
delete pocetak;  
pocetak=iza_Pocetka->sljedeci;
   
    
        for(int i=0;i<broj_timova;i++)
        {
            for(int brojac=0;brojac<broj_igraca_u_timu[i];brojac++) {
                    if(i==0 && brojac==0)
                    brojac++;
                    if(brojac==broj_igraca_u_timu[i])
                    break;
                for(int j=0;j<broj_slova_zadnjeg_igraca-1;j++)
                {
                  pocetak=pocetak->sljedeci;
                  iza_Pocetka=iza_Pocetka->sljedeci;
                }
               
                ime_zadnjeg_igraca=pocetak->ime;
                    vrati[i].insert(ime_zadnjeg_igraca);
            
      iza_Pocetka->sljedeci=pocetak->sljedeci;              
    delete pocetak;
    if(broj_igraca_u_timu[i]!=vrati[broj_timova-1].size())
      pocetak=iza_Pocetka->sljedeci;
     broj_slova_zadnjeg_igraca=broj_slova_igraca(ime_zadnjeg_igraca);
            }
            
        }
    
    
    return vrati;
    
}




int main ()
{
     try{
    int broj_dijece;
    std::cout<<"Unesite broj djece: ";
    
    std::cin>>broj_dijece;
    std::cin.ignore(100,'\n');
    std::cout<<"Unesite imena djece: ";
    std::vector<std::string> v;
    std::string s;
    for(int i=0;i<broj_dijece;i++)
    {
        s.resize(0);
        std::getline(std::cin,s);
        v.push_back(s);
    }
    std::cout<<"\nUnesite broj timova: ";
    int broj_timova;
    std::cin>>broj_timova;
    int prosao=0;
    auto ispis=Razvrstavanje(v,broj_timova);
    for(int i=0;i<ispis.size();i++)
    {
        prosao=0;
        std::cout<<"Tim "<<i+1<<": ";
        for(auto x:ispis[i])
        {
            if(prosao<ispis[i].size()-1)
            std::cout<<x<<", ";
            else
            std::cout<<x;
            prosao++;
        }
        std::cout<<"\n";
        
        
        
    }
    }
    catch(std::logic_error izutetak)
    {
        std::cout<<"Izuzetak: "<<izutetak.what();
    }
	return 0;
}
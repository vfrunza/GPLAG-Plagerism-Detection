/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <map>
#include <queue>
#include <stdexcept>
enum class Boje
{
    Pik,Tref,Herc,Karo
};
typedef std::list<std::pair<Boje,std::string>>Spil;
Spil KreirajSpil()
{
    Boje b;
    Spil s;
    std::pair<Boje,std::string>Par;
    for(int j(0);j<4;j++)
    {
        if(j==0) b=Boje::Pik;
        if(j==1) b=Boje::Tref;
        if(j==2) b=Boje::Herc;
        if(j==3) b=Boje::Karo;
        for(int i(2); i<=14; i++) {
            if(i<10) {
                Par=std::make_pair(b,'0'+i);
                s.push_back(Par);
            }
            if(i==10) Par=std::make_pair(b,"10"), s.push_back(Par);
            if(i==11) Par=std::make_pair(b,"J"), s.push_back(Par);
            if(i==12) Par=std::make_pair(b,"Q"), s.push_back(Par);
            if(i==13) Par=std::make_pair(b,"K"), s.push_back(Par);
            if(i==14) Par=std::make_pair(b,"A"), s.push_back(Par);
        }
    }
    return s;
}
void IzbaciKarte(Spil &spil,std::multimap<Boje,std::string>&mapa)
{
    Spil spil1=spil;
    std::multimap<Boje,std::string>mapa1=mapa;
    if(spil.size()>52) throw std::logic_error("Neispravna lista!");
    auto p(mapa.begin());
   for(auto it=spil.begin();it!=spil.end();it++)
   {

       for(auto it1=mapa.begin();it1!=mapa.end();it1++)
       {
           p=it1;
           std::pair<Boje,std::string>Par=*it;
          if(it1->first==Par.first&&it1->second==Par.second) 
          {

              it=spil.erase(it);
              it--;
          }
       }

   }

}
std::queue<std::pair<std::string,std::string>>IzbaciKarteRazbrajanjem(Spil &spil,short int &r,int &b)
{
    if(r<1||r>52||b<1) throw std::logic_error("Izuzetak: Neispravni elementi za izbacivanje!");
    int brojac(0),br(0);
    std::pair<Boje,std::string>Par;
    std::pair<std::string,std::string>Umetac;
    std::queue<std::pair<std::string,std::string>>Red;
    std::string s1("Pik"),s2("Tref"),s3("Herc"),s4("Karo"),s;
    auto it=spil.begin();
    while (it!=spil.end()) {
        brojac++;
        if(brojac==r)
        {
            br++;
            if((*it).first==Boje::Pik) s=s1;
            if((*it).first==Boje::Tref) s=s2;
            if((*it).first==Boje::Herc) s=s3;
            if((*it).first==Boje::Karo) s=s4;
            Umetac.first=s;
            Umetac.second=(*it).second;
            Red.push(Umetac);
            it=spil.erase(it);
            it--;
            brojac=0;
        }
        it++;
        if(it==spil.end()) it=spil.begin();
        if(br==b) break;
    }
    return Red;
}
void VratiPrvihNKarata(Spil &spil,std::queue<std::pair<std::string,std::string>>&red ,int n)
{
    spil=KreirajSpil( );
    if(n>red.size()&&n>0) throw std::range_error("Izuzetak: Nedovoljno karata u redu!");
    if(n<0) throw std::domain_error("Izuzetak: Broj n je besmislen!");
    if(spil.size()>52) throw std::logic_error("Izuzetak: Neispravna lista!");
    std::multimap<Boje,std::string>mp;
    std::pair<std::string,std::string> par;
    std::string s1("Pik"),s2("Tref"),s3("Herc"),s4("Karo"),str;
    Boje boja;
    for(int i(0);i<n;i++)
        red.pop();
    //for (int i(0);i<n;i++)
    while(!red.empty())
    {
        par=red.front();
        if(par.first==s1) boja=Boje::Pik;
        if(par.first==s2) boja=Boje::Tref;
        if(par.first==s3) boja=Boje::Herc;
        if(par.first==s4) boja=Boje::Karo;
        mp.insert({boja,par.second});
        red.pop();
    }  
   /* for(auto it=mp.begin();it!=mp.end();it++)
    {
        std::cout << it->first<<" - "<<it->second << std::endl;
    }  */
    IzbaciKarte(spil,mp);
}    

int main ()
{
    std::cout << "Unesite korak razbrajanja: ";
    short int korak;
    std::cin >> korak;
    int br_karata;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    std::cin >> br_karata; 
    Spil s(KreirajSpil());
    std::string s1("Pik"),s2("Tref"),s3("Herc"),s4("Karo"),str,s5("A");
    std::multimap<Boje,std::string>m;
    std::queue<std::pair<std::string,std::string>>red;
    Boje b;
    b=Boje::Pik;
    try
    {
    red = IzbaciKarteRazbrajanjem(s,korak,br_karata);
    std::cout << "U spilu trenutno ima "<<s.size()<<" karata, i to:";
    int t(1);
    std::string ref{};
    for(auto x : s)
    {
        b=x.first;
        if(b==Boje::Pik) { str=s1 ; if(ref!=str) t=1; }  
        if(b==Boje::Tref) { str=s2; if(ref!=str) t=1; }
        if(b==Boje::Herc) {str=s3; if(ref!=str) t=1;}
        if(b==Boje::Karo) {str=s4; if(ref!=str) t=1;}
        ref=str;
        if(str==ref&&t==1)
        {
            std::cout <<"\n" <<str<<": ";
            t++;
        }    
            std::cout <<x.second<<" ";
    }  
    }
    catch(std::logic_error &i)
    {
        std::cout << i.what() << std::endl;
        return 0;
    }
    std::cout << "\nUnesite broj karata koje zelite vratiti u spil: ";
    int vrati;
    std::cin >> vrati;

    int t=1;
    std::string ref1{};
    try
    {
    VratiPrvihNKarata(s,red,vrati);
    std::cout << "U spilu trenutno ima "<<s.size()<<" karata, i to:";
    for(auto x : s)
    {
        b=x.first;
        if(b==Boje::Pik) { str=s1; if(ref1!=str) t=1;}
        if(b==Boje::Tref) {str=s2; if(ref1!=str) t=1; }
        if(b==Boje::Herc) { str=s3; if(ref1!=str) t=1; }
        if(b==Boje::Karo) {str=s4; if(ref1!=str) t=1; }
        ref1=str;
        if(str==ref1&&t==1)
        {
            std::cout << "\n"<<str <<": ";
            t++;
        }
        std::cout << x.second<<" ";
    }
    }
    catch(std::range_error &i)
    {
        std::cout << i.what() << std::endl;
    }
    catch(std::domain_error &i)
    {
        std::cout << i.what() << std::endl;
    }
    catch(std::logic_error &i)
    {
        std::cout << i.what() << std::endl;
    }
    return 0;
}

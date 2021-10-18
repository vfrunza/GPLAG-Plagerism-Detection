#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include <stdexcept>
#include <map>

enum class Boje{Pik, Tref, Herc, Karo};

const char *niz[13]{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

struct Karta {
  Boje boja;
  std::string vrijednost;
};

struct Cvor {
  Karta karta;
  Cvor *sljedeci;
};

Cvor *KreirajSpil ()
{
  Cvor *pocetak(nullptr),*prethodni;
  Boje b(Boje::Pik);
  for (int i=0;i<4;i++)
  {
      if (i==1) b=Boje::Tref;
      if (i==2) b=Boje::Herc;
      if (i==3) b=Boje::Karo;
    for (int j=0;j<13;j++)
    {
      Cvor *novi(new Cvor {{b,niz[j]},nullptr});
      if (!pocetak) pocetak=novi;
      else prethodni->sljedeci=novi;
      prethodni=novi;
    }
  }
  prethodni->sljedeci=pocetak;
  return pocetak;
}
void UnistiSpil (Cvor *pocetak)
{
    if(!pocetak) return;
    Cvor *temp(pocetak->sljedeci),*prethodni(pocetak->sljedeci);
    while (temp!=pocetak)
    {
        prethodni=prethodni->sljedeci;
        delete temp;
        temp=prethodni;
    }
    delete pocetak;
}

int BrojEl (Cvor *pok)
{
    if (!pok) return 0;
    auto poc(pok);
    int brojac(0);
    do
    { 
        brojac++;
        poc=poc->sljedeci;
    }
    while (poc!=pok);
    return brojac;
}

std::string Fun (std::string s)
{
    if (s=="J") return "11";
    if (s=="Q") return "12";
    if (s=="K") return "13";
    if (s=="A") return "14";
    return s;
}

bool Kriterij (std::string s1, std::string s2)
{
    s1=Fun(s1); s2=Fun(s2);
    if (s1.size()==s2.size())
    return s1<s2;
    return s1.size()<s2.size();
}

bool Kriterij2(std::string s1, std::string s2)
{
    s1=Fun(s1); s2=Fun(s2);
    if (s1.size()==s2.size())
    return s1>s2;
    return s1.size()>s2.size();
}

bool DaLiJeIspravnaLista (Cvor *poc)
{
    if (BrojEl(poc)>52)
      return false;
    auto pok(poc);
    do
    {
        if (pok->karta.boja!=Boje::Pik && pok->karta.boja!=Boje::Tref && pok->karta.boja!=Boje::Karo && pok->karta.boja!=Boje::Herc)
        return false;
        bool ispravno(false);
        for (int i=0;i<13;i++)
        {
            if (pok->karta.vrijednost==niz[i])
            {
                ispravno=true;
                break;
            }
        }
        if (!ispravno)
        return false;
        pok=pok->sljedeci;
    }
    while (pok!=poc);
    pok=poc; auto pp(poc->sljedeci);
    while (pp!=poc)
    {
        if (pok->karta.boja>pp->karta.boja)
        return false;
        else if (pok->karta.boja==pp->karta.boja && Kriterij2(pok->karta.vrijednost,pp->karta.vrijednost))
        return false;
        pok=pp;
        pp=pp->sljedeci;
    }
    return true;
}

Boje PretvoriUBoju (std::string s)
{
    if (s=="Tref") return Boje::Tref;
    else if (s=="Pik") return Boje::Pik;
    else if (s=="Herc") return Boje::Herc;
    return Boje::Karo;
}

std::string PretvoriUString (Boje b)
{
    if (b==Boje::Tref) return "Tref";
    else if (b==Boje::Karo) return "Karo";
    else if (b==Boje::Pik) return "Pik";
    return "Herc";
}

bool DaLiJeUListi (Cvor *poc, std::pair<std::string,std::string> temp)
{
    auto pom(poc);
    do
    {
        if (PretvoriUString(pom->karta.boja)==temp.first && pom->karta.vrijednost==temp.second)
        return true;
        pom=pom->sljedeci;
    }
    while (pom!=poc);
    return false;
}

void IzbaciKarte (Cvor *&poc, std::multimap<Boje,std::string> &mapa)
{
    if (!poc) return;
    if (!DaLiJeIspravnaLista(poc))
        throw std::logic_error ("Neispravna lista!");
    auto it(mapa.begin()),kraj(mapa.end());
    while (it!=kraj)
    {
        if (!poc) break;
        Cvor *temp(poc),*prethodni(poc);
        while (prethodni->sljedeci!=poc)
        prethodni=prethodni->sljedeci;
        bool brisi(false);
        do
        {
            if (temp->karta.boja==it->first && temp->karta.vrijednost==it->second)
            {
                if (prethodni==temp)
                {
                    delete prethodni;
                    poc=nullptr;
                    brisi=true;
                    break;
                }
                prethodni->sljedeci=temp->sljedeci;
                if (temp==poc)
                poc=prethodni->sljedeci;
                delete temp;
                temp=prethodni->sljedeci;
                brisi=true;
                break;
            }
            prethodni=temp;
            temp=temp->sljedeci;
        }
        while (temp!=poc);
        if (brisi) it=mapa.erase(it);
        else it++;
    }
}

std::stack<std::pair<std::string,std::string>> IzbaciKarteRazbrajanjem (Cvor *&poc, const short int &r, const int &b)
{
    if (poc && !DaLiJeIspravnaLista(poc))
        throw std::logic_error ("Neispravna lista!");
    if (r<1 || r>52 || b<1)
        throw std::logic_error ("Neispravni elementi za izbacivanje!");
    std::stack<std::pair<std::string,std::string>> vrati;
    if (poc) {
    Cvor *temp(poc),*prethodni(poc);
    while (prethodni->sljedeci!=poc)
    prethodni=prethodni->sljedeci;
    for (int i=0;i<b;i++)
    {
        if (!poc) continue;
        for (int j=0;j<r-1;j++)
        {
            prethodni=temp;
            temp=temp->sljedeci;
        }
        vrati.push({PretvoriUString(temp->karta.boja),temp->karta.vrijednost});
        if (temp!=prethodni)
        {
            prethodni->sljedeci=temp->sljedeci;
            if (temp==poc)
            poc=prethodni->sljedeci;
            delete temp;
            temp=prethodni->sljedeci;
        }
        else
        {
            delete poc;
            poc=nullptr;
        }
    }}
    return vrati;
}

bool DaLiJeIspravanStek(std::stack<std::pair<std::string,std::string>> s)
{
    while (!s.empty())
    {
        auto temp(s.top());
        s.pop();
        if (temp.first!="Pik" && temp.first!="Tref" && temp.first!="Karo" && temp.first!="Herc")
            return false;
        bool ispravno(false);
        for (int i=0;i<13;i++)
        {
            if (temp.second==niz[i])
            {
                ispravno=true;
                break;
            }
        }
        if (!ispravno)
        return false;
    }
    return true;
}

void VratiPosljednjihNKarata (Cvor *&poc, std::stack<std::pair<std::string,std::string>> &stek, int n)
{
    if (n<0)
        throw std::domain_error ("Broj n je besmislen!");
    if (n>stek.size())
        throw std::range_error ("Nedovoljno karata u steku!");
    if (!DaLiJeIspravanStek(stek))
        throw std::logic_error("Neispravne karte!");
    if (poc && !DaLiJeIspravnaLista(poc))
        throw std::logic_error ("Neispravna lista!");
    if (!poc)
    {
        auto pom(stek.top());
        stek.pop();
        Cvor *novi(new Cvor {{PretvoriUBoju(pom.first),pom.second},nullptr});
        poc=novi;
        novi->sljedeci=poc;
        if (n==1)
        return;
        n--;
    }
    for (int i=0;i<n;i++)
    {
        auto pom(stek.top());
        stek.pop();
        if (!DaLiJeUListi(poc,{pom.first,pom.second}))
        {
            Cvor *temp(poc),*prethodni(poc);
            while (prethodni->sljedeci!=poc)
            prethodni=prethodni->sljedeci;
            while ((temp->karta.boja<PretvoriUBoju(pom.first) || (temp->karta.boja==PretvoriUBoju(pom.first) && Kriterij(temp->karta.vrijednost,pom.second))))
            {
                prethodni=temp;
                temp=temp->sljedeci;
                if (temp==poc)
                break;
            }
            Cvor *novi(new Cvor{{PretvoriUBoju(pom.first),pom.second},temp});
            prethodni->sljedeci=novi;
            if (novi->karta.boja<poc->karta.boja || (novi->karta.boja==poc->karta.boja && Kriterij(novi->karta.vrijednost,poc->karta.vrijednost)))
                poc=novi;
        }
    }
}

void IspisiSpil (Cvor *poc)
{
    if (!poc)
    {
        std::cout<<"Pik: \nTref: \nHerc: \nKaro: \n";
        return;
    }
    auto pom(poc);
    std::cout<<"Pik: ";
    while (pom->karta.boja==Boje::Pik)
    {
        std::cout<<pom->karta.vrijednost<<" ";
        pom=pom->sljedeci;
        if (pom==poc)
        break;
    }
    std::cout<<std::endl<<"Tref: ";
    while (pom->karta.boja==Boje::Tref)
    {
        std::cout<<pom->karta.vrijednost<<" ";
        pom=pom->sljedeci;
        if (pom==poc)
        break;
    }
    std::cout<<std::endl<<"Herc: ";
    while (pom->karta.boja==Boje::Herc)
    {
        std::cout<<pom->karta.vrijednost<<" ";
        pom=pom->sljedeci;
        if (pom==poc)
        break;
    }
    std::cout<<std::endl<<"Karo: ";
    while (pom->karta.boja==Boje::Karo)
    {
        std::cout<<pom->karta.vrijednost<<" ";
        pom=pom->sljedeci;
        if (pom==poc)
        break;
    }
    std::cout<<std::endl;
}

int main()
{
    auto poc(KreirajSpil()); 
    try
    {
        short int korak;
        int izbaci;
        std::cout<<"Unesite korak razbrajanja: ";
        std::cin>>korak;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        std::cin>>izbaci;
        auto stek(IzbaciKarteRazbrajanjem(poc,korak,izbaci));
        std::cout<<"U spilu trenutno ima "<<BrojEl(poc)<<" karata, i to:\n";
        IspisiSpil(poc);
        int x;
        std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        std::cin>>x;
        VratiPosljednjihNKarata(poc,stek,x);
        std::cout<<"U spilu trenutno ima "<<BrojEl(poc)<<" karata, i to:\n";
        IspisiSpil(poc);
    }
    catch (std::domain_error izuz)
    {
        std::cout<<"Izuzetak: "<<izuz.what()<<std::endl;
    }
    catch (std::range_error izuz2)
    {
        std::cout<<"Izuzetak: "<<izuz2.what()<<std::endl;
    }
    catch (std::logic_error izuz3)
    {
        std::cout<<"Izuzetak: "<<izuz3.what()<<std::endl;
    }
    UnistiSpil(poc);
    return 0;
}




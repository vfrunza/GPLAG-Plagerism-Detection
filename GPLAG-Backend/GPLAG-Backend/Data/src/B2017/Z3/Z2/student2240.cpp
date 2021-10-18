/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <stdexcept>
#include <tuple>
#include <set>

typedef std::map<std::string, std::vector<std::string>> Knjiga;


std::map<std::string,std::set<std::tuple<std::string,int,int>>> KreirajIndeksPojmova (Knjiga k)
{
    std::map<std::string,std::set<std::tuple<std::string,int,int>>> rezultat;
    
    std::vector<std::string> vektor_rijeci;                                     ///Pomocni vektor koji sadrzi sve rijeci - stringove.
    for (auto it = k.begin(); it != k.end(); it++)                              ///Prolazak kroz knjigu i pronalazenje svih rijeci.
    {
        for (auto stranica = it->second.begin(); stranica != it->second.end(); stranica++)    ///Prolazak kroz svaki vektor i otkrivanje rijeci.
        {
            std::string s = *stranica;
            
            for (int i{};i<s.length();i++)
            {
                if (s[i] != ' ')
                {
                    std::string rijec;
                    for (int j{i}; j<s.length(); j++)
                    {
                        if (s[j] == ' ')
                            break;
                            
                        bool u1 = false, u2 = false, u3 = false;
                        
                        if (s[j]>='0' && s[j]<='9')
                            u1 = true;
                            
                        if (s[j]>='A' && s[j]<='Z')
                            u2 = true;
                            
                        if (s[j]>='a' && s[j]<='z')
                            u3 = true;
                            
                        if (u1 == false && u2 == false && u3 == false)
                            break;
                        
                        
                        if (s[j]>='A' && s[j]<='Z')
                            s[j] = s[j] + 'a' - 'A';
                            
                        rijec.push_back(s[j]);
                        
                        i = j;
                    }
                    
                    bool upisan = false;
                    for (int j{};j<vektor_rijeci.size();j++)                    ///Provjera postojanja rijeci i upis u slucaju da nije otkrivena vec rijec.
                    {
                        if (vektor_rijeci[j] == rijec)
                            upisan = true;
                    }
                    
                    for (int brojac{}; brojac < rijec.length(); brojac++)       ///Provjera da li je rijec ili neki znak.
                    {
                        bool u1 = false, u2 = false;
                        
                        if (rijec[brojac]>='0' && rijec[brojac]<='9')
                            u1 = true;
                            
                        if (rijec[brojac]>='A' && rijec[brojac]<='Z')
                            upisan = true;
                            
                        if (rijec[brojac]>='a' && rijec[brojac]<='z')
                            u2 = true;
                            
                        if (u1 == false && u2 == false)
                            upisan = true;
                    }
                    
                    if (upisan == false)
                        vektor_rijeci.push_back(rijec);
                    
                }
            }
            
        }
    }
    
    for (int l{};l<vektor_rijeci.size();l++)                                    ///Trazenje svih indeksa pojmova, preko pronadjenih rijeci.
    {
        if (vektor_rijeci[l].length() == 0)                                     ///U slucaju upisanih znakova, koji su prekidali rijeci.
            continue;
            
         std::set<std::tuple<std::string,int,int>>  skup_indeksa;  
         for (auto it = k.begin(); it != k.end(); it++)                         ///Ponovni prolazak kroz knjigu, kljucna rijec je ime poglavlja.
         {
             for (auto stranica = it->second.begin(); stranica != it->second.end(); stranica++)   ///Prolazak kroz svaki vektor unutrar poglavlja (stranica == indeks vektora + 1).
             {
                 std::string s = *stranica;
                 int broj_stranice = stranica-it->second.begin()+1;
                 
                 for (int i{};i<s.length();i++)
            {
                if (s[i] != ' ')
                {
                    int pocetak_rijeci = i;
                    std::string rijec;
                    for (int j{i}; j<s.length(); j++)
                    {
                        if (s[j] == ' ')
                            break;
                            
                        bool u1 = false, u2 = false, u3 = false;
                        
                        if (s[j]>='0' && s[j]<='9')
                            u1 = true;
                            
                        if (s[j]>='A' && s[j]<='Z')
                            u2 = true;
                            
                        if (s[j]>='a' && s[j]<='z')
                            u3 = true;
                            
                        if (u1 == false && u2 == false && u3 == false)
                            break;
                        
                        
                        if (s[j]>='A' && s[j]<='Z')
                            s[j] = s[j] + 'a' - 'A';
                            
                        rijec.push_back(s[j]);
                        
                        i = j;
                    }
                    
                    
                    if (rijec == vektor_rijeci[l])                              ///Pronadjena rijec, formiranje tuple-a.
                        skup_indeksa.insert(std::make_tuple(it->first, broj_stranice, pocetak_rijeci));
                }
            }
             }
         }
         
         
        rezultat.insert(std::pair<std::string,std::set<std::tuple<std::string,int,int>>> (vektor_rijeci[l], skup_indeksa)); 
    }
    
    
    
    return rezultat;
}

std::set<std::tuple<std::string,int,int>> PretraziIndeksPojmova (std::string s, std::map<std::string,std::set<std::tuple<std::string,int,int>>> indeksi)
{
    std::string rijec;
    for (int i{};i<s.length();i++)                                              ///Modifikacija rijeci za prilagodbu pretrazi.
    {
        if (s[i]>='0' && s[i]<='9')
            rijec.push_back(s[i]);
            
        else if (s[i]>='A' && s[i]<='Z')
            rijec.push_back(s[i]+'a'-'A');
            
        else if (s[i]>='a' && s[i]<='z')
            rijec.push_back(s[i]);
    }
    
    auto it = indeksi.find(rijec);
    
    if (it == indeksi.end())
        throw std::logic_error ("Pojam nije nadjen");
        
    return it->second;
}


void IspisiIndeksPojmova (std::map<std::string,std::set<std::tuple<std::string,int,int>>> ispis)
{
    for (auto it = ispis.begin(); it != ispis.end(); it++)
    {
        std::cout<<it->first<<": ";
        
        auto posljednji_element = it->second.end();
        posljednji_element--;
        for (auto skup = it->second.begin(); skup != it->second.end(); skup++)
        {
            if (skup == posljednji_element)
                std::cout<<std::get<0>(*skup)<<"/"<<std::get<1>(*skup)<<"/"<<std::get<2>(*skup)<<std::endl;
            else
                std::cout<<std::get<0>(*skup)<<"/"<<std::get<1>(*skup)<<"/"<<std::get<2>(*skup)<<", ";
        }
    }
}



int main ()
{
    Knjiga k;
    
    while (true)
    {
        std::cout<<"Unesite naziv poglavlja: ";
        std::string poglavlje;
        std::getline(std::cin, poglavlje);
        
        if (poglavlje == ".")
            break;
            
        std::vector<std::string> stranice;
        int brojac = 1;
        while (true)
        {
            std::cout<<"Unesite sadrzaj stranice "<<brojac++<<": ";
            std::string pomocni;
            std::getline(std::cin, pomocni);
            
            if (pomocni == ".")
                break;
                
            stranice.push_back(pomocni);
        }
        
        k.insert (std::pair<std::string,std::vector<std::string>> (poglavlje, stranice));
    }
    
    auto indeksi = KreirajIndeksPojmova(k);
    
    std::cout<<std::endl;
    
    std::cout<<"Kreirani indeks pojmova:"<<std::endl;
    IspisiIndeksPojmova(indeksi);
    
    std::cout<<std::endl;
    
    while (true)
    {
        try
        {
            std::cout<<"Unesite rijec: ";
            std::string rijec;
            std::getline(std::cin, rijec);
            
            if (rijec == ".")
                break;
                
            auto skup = PretraziIndeksPojmova(rijec, indeksi);
            for (auto it = skup.begin(); it != skup.end(); it++)
                std::cout<<std::get<0>(*it)<<"/"<<std::get<1>(*it)<<"/"<<std::get<2>(*it)<<" ";
                
            std::cout<<std::endl;
        }
        catch (std::logic_error e)
        {
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        }
    }
    
    
    
    
	return 0;
}

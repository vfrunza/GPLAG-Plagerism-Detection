/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stdexcept>
#include <tuple>

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::set<std::tuple<std::string, int, int>> IndeksPojmova;
typedef std::map<std::string, IndeksPojmova> TrazeniIndeksPojmova;


TrazeniIndeksPojmova KreirajIndeksPojmova(Knjiga knjiga)
{
    std::vector<std::string> sverijeci;
    for(auto it=knjiga.begin(); it!=knjiga.end(); it++)
    {
        for(auto stranica=(*it).second.begin(); stranica!=(*it).second.end(); stranica++)
        {
            std::string tekst(*stranica);
            for(int i(0); i<tekst.size(); i++)
            {
                if(tekst[i]!=' ')
                {
                    std::string rijec;
                    for(int j(i); j<tekst.size(); j++)
                    {
                        if(tekst[j]==' ') break;
                        bool provjeri(false);
                        if((tekst[j]>='A' && tekst[j]<='Z') || (tekst[j]>='0' && tekst[j]<='9') || (tekst[j]>='a' && tekst[j]<='z')) provjeri=true;
                        if(provjeri==false) break;
                        if(tekst[j]>='A' && tekst[j]<='Z') tekst[j]+=32;
                        rijec.push_back(tekst[j]);
                        i=j;
                    }
                    bool upisi(false);
                    for(int j(0); j<sverijeci.size(); j++)
                        if(sverijeci[j]==rijec) upisi=true;
                    for(int k(0); k<rijec.size(); k++)
                    {
                        bool provjeri(false);
                        if((rijec[k]>='a' && rijec[k]<='z') || (rijec[k]>='0' && rijec[k]<='9')) provjeri=true;
                        if(rijec[k]>='A' && rijec[k]<='Z') upisi=true;
                        if(provjeri==false) upisi=true;
                    }
                    if(upisi==false) sverijeci.push_back(rijec);
                }
            }
        }
    }
    std::map<std::string,IndeksPojmova> pojmovi;
    for(int i(0); i<sverijeci.size(); i++)
    {
       if(sverijeci[i].size()==0) continue;
        IndeksPojmova indeksi;
        for(auto it=knjiga.begin(); it!=knjiga.end(); it++)
        {
            for(auto strana=(*it).second.begin(); strana!=(*it).second.end(); strana++)
            {
                std::string pomocni(*strana);
                int brojstranice(strana-(*it).second.begin()+1);
                for(int j(0); j<pomocni.size(); j++)
                {
                    if(pomocni[j]!=' ')
                    {
                        int pocetak=j;
                        std::string rijec;
                        for(int k(j); k<pomocni.size(); k++)
                        {
                            if(pomocni[k]==' ') break;
                            bool provjeri(false);
                            if((pomocni[k]>='0' && pomocni[k]<='9') || (pomocni[k]>='A' && pomocni[k]<='Z') || (pomocni[k]>='a' && pomocni[k]<='z')) provjeri=true;
                            if(provjeri==false) break;
                            if(pomocni[k]>='A' && pomocni[k]<='Z') pomocni[k]+=32;
                            rijec.push_back(pomocni[k]);
                            j=k;
                        }
                        if(sverijeci[i]==rijec) indeksi.insert(std::make_tuple((*it).first,brojstranice,pocetak));
                    }
                }
            }
        }
        pojmovi.insert(std::pair<std::string, IndeksPojmova> (sverijeci[i], indeksi));
    }
    return pojmovi;
}

 void PretvoriUMalaSlova(std::string &rijec)
{
    for(int i(0); i<rijec.size(); i++)
        if(rijec[i]>='A' && rijec[i]<='Z') rijec[i]+=32;
}

IndeksPojmova PretraziIndeksPojmova(std::string rijec, std::map<std::string, IndeksPojmova> indeks)
{
    std::string modifikovanrijec(rijec);
    PretvoriUMalaSlova(modifikovanrijec);
    auto it(indeks.find(modifikovanrijec));
    if(it==indeks.end()) throw std::logic_error("Pojam nije nadjen");
    
    return (*it).second;
}

void IspisiIndeksPojmova(std::map<std::string, IndeksPojmova> ispispojmova)
{
    for(auto it=ispispojmova.begin(); it!=ispispojmova.end(); it++)
    {
        std::cout<<(*it).first<<": ";
        auto iduci=(*it).second.end();
        iduci--;
        for(auto ispis=(*it).second.begin(); ispis!=(*it).second.end(); ispis++)
        {
            if(ispis!=iduci) std::cout<<std::get<0>(*ispis)<<"/"<<std::get<1>(*ispis)<<"/"<<std::get<2>(*ispis)<<", ";
            else if (ispis==iduci) std::cout<<std::get<0>(*ispis)<<"/"<<std::get<1>(*ispis)<<"/"<<std::get<2>(*ispis)<<std::endl;
        }
    }
}

int main ()
{
    Knjiga knjiga;
    for(;;)
    {
        int br(1);
        std::cout<<"Unesite naziv poglavlja: ";
        std::string a;
        std::getline(std::cin,a);
        if(a==".") break;
        
        std::vector<std::string> strana;
        for(;;)
        {
            std::cout<<"Unesite sadrzaj stranice "<<br<<": ";
            br++;
            std::string tekst;
            std::getline(std::cin, tekst);
            if(tekst==".") break;
            strana.push_back(tekst);
        }
        knjiga.insert(std::pair<std::string, std::vector<std::string>>(a,strana));
    }
    TrazeniIndeksPojmova temp(KreirajIndeksPojmova(knjiga));
    std::cout<<std::endl<<"Kreirani indeks pojmova: "<<std::endl;
    IspisiIndeksPojmova(temp);
    //std::cout<<"\n";
    
    for(;;)
    {
        try
        {
            std::cout<<"Unesite rijec: ";
            std::string rijec;
            std::getline(std::cin,rijec);
            if(rijec==".") break;
            IndeksPojmova pojmovi(PretraziIndeksPojmova(rijec,temp));
            for(auto iter=pojmovi.begin(); iter!=pojmovi.end(); iter++) std::cout<<std::get<0>(*iter)<<"/"<<std::get<1>(*iter)<<"/"<<std::get<2>(*iter)<<" ";
            std::cout<<"\n";
        }
        catch(std::logic_error a)
        {
            std::cout<<"Unesena rijec nije nadjena!\n";
        }
    }
    
	return 0;
}
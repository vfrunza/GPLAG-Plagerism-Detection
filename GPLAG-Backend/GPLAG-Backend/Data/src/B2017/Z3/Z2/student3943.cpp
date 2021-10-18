#include <iostream>
#include <map>
#include <string>
#include <set>
#include <tuple>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>

typedef std::map<std::string,std::vector<std::string>> Knjiga;
typedef std::map<std::string,std::set<std::tuple<std::string,int,int>>> Mapa;



std::map<std::string,std::set<std::tuple<std::string,int,int>>> KreirajIndeksPojmova(const Knjiga &tekst)
{
    Mapa pojmovi;

    auto it(tekst.begin());

    while(it!=tekst.end()) {


        for(int i=0; i<(it->second).size(); i++) {

            for(int j=0; j<(it->second)[i].length() ;) {


                
                while(j<(it->second)[i].length() && !(((it->second)[i][j]>='A' && (it->second)[i][j]<='Z') || ((it->second)[i][j]>='a' && (it->second)[i][j]<='z') || ((it->second)[i][j]>='0' && (it->second)[i][j]<='9'))) j++;

                
                std::string pomocni;
                int pocetak(j);
                while(j<(it->second)[i].length() && (((it->second)[i][j]>='A' && (it->second)[i][j]<='Z') || ((it->second)[i][j]>='a' && (it->second)[i][j]<='z') || ((it->second)[i][j]>='0' && (it->second)[i][j]<='9'))) {

                    if((it->second)[i][j]>='A' && (it->second)[i][j]<='Z') {
                        pomocni.push_back((it->second)[i][j]+('a'-'A'));
                    } else {
                        
                        pomocni.push_back((it->second)[i][j]);

                    }
                    j++;

                }
                if(pomocni.length()!=0)
                pojmovi[pomocni].insert(std::make_tuple(it->first,i+1,pocetak));

            }


        }



        it++;
    }


    return pojmovi;
}

std::set<std::tuple<std::string,int,int>> PretraziIndeksPojmova(std::string s,const Mapa &pojmovi)
{

    auto it(pojmovi.find(s));
    if(it==pojmovi.end()) {
        throw std::logic_error("Unesena rijec nije nadjena!");
    }


    return it->second;
}



void IspisiIndeksPojmova(const Mapa &pojmovi)
{

    for(auto it=pojmovi.begin(); it!=pojmovi.end(); it++) {
        std::cout<<it->first<<": ";


        for(auto it1=(it->second).begin(); it1!=(it->second).end(); it1++) {

            std::cout<<std::get<0>(*it1)<<"/"<<std::get<1>(*it1)<<"/"<<std::get<2>(*it1);
            if(std::distance(it1,(it->second).end())==1)
                continue;
            else {
                std::cout<<", ";
            }
        }

        std::cout<<std::endl;



    }

}

int main()
{
    Knjiga tekst;
    for(;;) {
        std::cout<<"Unesite naziv poglavlja: ";
        std::string poglavlje;
        std::getline(std::cin,poglavlje);
        if(poglavlje==".") break;
        std::vector<std::string> v;
        for(int j=0;; j++) {
            std::string pomocni;
            std::cout<<"Unesite sadrzaj stranice "<<j+1<<": ";
            std::getline(std::cin,pomocni);

            if(pomocni==".") break;
            v.push_back(pomocni);


        }

        tekst[poglavlje]=v;


    }
std::cout<<std::endl;
    std::cout<<"Kreirani indeks pojmova:"<<std::endl;
    IspisiIndeksPojmova(KreirajIndeksPojmova(tekst));

    for(;;) {

        std::cout<<"Unesite rijec: ";
        std::string pomocna;
        std::getline(std::cin,pomocna);
        if(pomocna==".") break;
        try {
            std::set<std::tuple<std::string,int,int>> pomocni(PretraziIndeksPojmova(pomocna,KreirajIndeksPojmova(tekst)));

            for(auto it1=pomocni.begin(); it1!=pomocni.end(); it1++) {

                std::cout<<std::get<0>(*it1)<<"/"<<std::get<1>(*it1)<<"/"<<std::get<2>(*it1)<<" ";

            }
            std::cout<<std::endl;
        } catch(std::logic_error izuzetak) {
            std::cout<<izuzetak.what()<<std::endl;
        }

    }

    return 0;
}

